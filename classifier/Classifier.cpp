#include "Classifier.h"
#include <memory>
#include <map>

void Classifier::classify(Classified& unclassified, const Distance& metric) {
    if (!m_isInit) {
        return;
    }

    // Measure the distances from the unclassified vector to the gathered data
    std::vector<double> distances;
    auto dataSize = m_classifiedData.size();

    for (int i = 0; i < dataSize; i++) {
        distances.push_back(metric.distance(unclassified.data(), m_classifiedData[i]->data()));
    }

    // Find the K nearest neighbours
    std::map<std::string, int> m;

    for (int i = 0; i < m_k; i++) {
        // TODO: get the number vector sorted

        std::string strType;
        if (m.find(strType) == m.end()) {
            m.insert(std::pair<std::string, int>(strType, 1));
        } else {
            m[strType] += 1;
        }
    }

    // Can't use algorithms
//    std::string st = std::max_element(m.begin(), m.end())->first;

    // Continue next
    unclassified.handle(st);
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

