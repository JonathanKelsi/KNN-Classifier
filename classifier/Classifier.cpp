#include "Classifier.h"
#include <memory>
#include <map>

void Classifier::classify(Classified& unclassified, const Distance& metric) const {
    if (!m_isInit) {
        return;
    }

    // Measure the distances from the unclassified vector to the gathered data
    std::vector<double> distances;
    auto dataSize = m_classifiedData.size();

    for (int i = 0; i < dataSize; ++i) {
        distances.push_back(metric.distance(unclassified.data(), m_classifiedData[i]->data()));
    }

    // Find the K nearest neighbours
    std::map<std::string, int> map;
    std::vector<int> indices = kSmallestElements(distances, m_k);

    for (int i = 0; i < m_k; ++i) {
        std::string handle = m_classifiedData[indices[i]]->handle();

        if (map.find(handle) == map.end()) {
           map[handle] = 1;
        } else {
            map[handle]++;
        }
    }
    std::map<std::string, int>::iterator handleIterator = map.begin();
    std::string maxHandle = "";
    int maxTimes = 0;
    while (handleIterator != map.end()) {
        if (handleIterator->second > maxTimes) {
            maxHandle = handleIterator->first;
            maxTimes = handleIterator->second;
        }
    }
    unclassified.handle(maxHandle);
}

Classifier::Classifier(int k) {
    m_isInit = false;
    m_k = k;
}

void Classifier::init(std::string dataPath) {
    // Read from given csv files and create classified objects
    std::string line;
    std::ifstream inFile(dataPath);

    // Iterate through the csv file
    while (std::getline(inFile, line)) {
        // Read the line
        std::istringstream stringStream(line);
        std::string column;

        std::string handle;
        std::vector<double> vData;

        while(std::getline(stringStream, column, ',')) {
            //Check if the column is a valid floating point number
            if (isFloat(column)) {
                vData.push_back((double)std::atof(column.c_str()));
            } else {
                handle = column;
            }
        }

        std::unique_ptr<Classified> uniquePtr (reinterpret_cast<Classified *>(new Classified(handle, vData)));
        m_classifiedData.push_back(std::move(uniquePtr));
    }

    // Update the object has been initialized
    m_isInit = true;
}

void Classifier::write(std::string dataPath, std::string outputPath) {
}

