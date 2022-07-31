#include "Classifier.h"
#include <memory>

void Classifier::classify(Classified& unclassified, Distance distance) {

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
        auto ptr = std::make_unique<Classified>(handle, vec1);
        m_classifiedData.push_back(cls);
    }

}

void Classifier::write(std::string dataPath, std::string outputPath) {

}

