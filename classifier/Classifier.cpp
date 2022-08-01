#include "Classifier.h"
#include <memory>
#include <map>

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

void Classifier::classify(Classified& unclassified, const Distance& metric) const {
    if (!m_isInit) {
        throw std::runtime_error("Classifier uninitialized");
    }

    // Measure the distances from the unclassified vector to the gathered data
    std::vector<double> distances;
    auto dataSize = m_classifiedData.size();

    for (int i = 0; i < dataSize; ++i) {
        distances.push_back(metric.distance(unclassified.data(), m_classifiedData[i]->data()));
    }

    // Find the K nearest neighbours, and the most common handle among them
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


    //TODO: Create method in Algorithms.h
    auto handleIterator = map.begin();
    std::string mostCommonHandle;
    int maxTimes = 0;

    while (handleIterator != map.end()) {
        if (handleIterator->second > maxTimes) {
            mostCommonHandle = handleIterator->first;
            maxTimes = handleIterator->second;
        }
    }

    // Classify the object
    unclassified.handle(mostCommonHandle);
}

void Classifier::write(std::string dataPath, std::string outputPath) {
    if (!m_isInit) {
        throw std::runtime_error("Classifier uninitialized");
    }




    // Create unclassified objects from the unclassified data
    std::string line;
    std::ifstream inFile(dataPath);
    std::vector<std::unique_ptr<Classified>> unclassifiedData;

    while (std::getline(inFile, line)) {
        std::istringstream inputStringStream(line);
        std::string col;
        std::vector<double> vData;

        while (std::getline(inputStringStream, col, ',')) {
            if (isFloat(col)) {
                vData.push_back((double)std::atof(col.c_str()));
            }
        }

        std::unique_ptr<Classified> uniquePtr (reinterpret_cast<Classified *>(new Classified("", vData)));
        unclassifiedData.push_back(std::move(uniquePtr));
    }

    inFile.close();

    // Create a vector of the metrics used
    std::vector<Distance*> metrics = {new EuclideanDistance(), new ChebyshevDistance(), new ManhattanDistance()};

    //Create vector with the output path names, corresponding to the metrics
    std::vector<std::string> files = {"euclidean_output.csv", "chebyshev_output.csv", "manhattan_output.csv"};
    auto numOfDistances = metrics.size();
    // Now, for each distance, we'll print the classifications by the relevant distance.
    for (int i = 0; i < numOfDistances; ++i) {
        std::fstream ostream;
        ostream.open(outputPath + "/" + files[i]);
        auto numOfClassifieds = unclassifiedData.size();
        for (int j = 0; j < numOfDistances; ++j) {
            classify(*unclassifiedData[j], *metrics[i]);
            ostream << unclassifiedData[j]->handle() << std::endl;
        }
        ostream.close();
    }
}