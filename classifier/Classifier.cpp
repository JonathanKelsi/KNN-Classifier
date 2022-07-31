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
    std::string st = std::max_element(m.begin(), m.end())->first;

    // Continue next
    unclassified.handle(st);
}

Classifier::Classifier(int k) {
    m_isInit = false;
    m_k = k;
}

void Classifier::init(std::string dataPath) {
    // Update the object has been initialized
    m_isInit = true;

    std::string str;
    std::ifstream inStream(dataPath);
    while (std::getline(inStream, str)) {
        std::istringstream str1(str);
        std::string val;
        std::vector<double> vec1;
        std::string handle;
        while (std::getline(str1, val, ',')) {
            if ((val[0] < (char)'0' || val[0] > (char)'0') && val[0] != '.') {
                vec1.push_back(std::stod(val));
            }
        }
        handle = val;
        std::unique_ptr<Classified> uniquePtr (reinterpret_cast<Classified *>(new Classified(handle, vec1)));
        m_classifiedData.push_back(uniquePtr);
    }

}

void Classifier::write(std::string dataPath, std::string outputPath) {
}

