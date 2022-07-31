#include "Classifier.h"
#include <memory>

void Classifier::classify(Classified& unclassified, Distance distance) {
    std::vector<double> distances;
    for (int i = 0; i < m_classifiedData.size(); i++) {
        distances.push_back(distance.distance(unclassified.data(), m_classifiedData[i]->data()));
    }
    std::vector<Classified> selected;
    for (int i = 1; i <= m_k; i++) {
        selected.push_back(
    }
    //continue next
}
Classifier::Classifier(int k) {
    m_isInit = false;
    m_k = k;
}

void Classifier::init(std::string dataPath) {
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

