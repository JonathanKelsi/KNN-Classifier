#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "Classified.h"
#include "distance/Distance.h"
#include <string>
#include <memory>

class Classifier {
private:
    std::vector<std::unique_ptr<Classified>> m_classifiedData;
    int m_k;
    bool m_isInit;

    /**
     * Given unclassified data, and a distance metric, this method uses
     * the KNN algorithm to classify the object.
     * @param unclassified an unclassified object.
     * @param distance a distance metric
     */
    void classify(Classified& unclassified, Distance distance);

public:
    /**
     * Constructor.
     * @param k the parameter used in the KNN algorithm
     */
    Classifier(int k);

    /**
     * Initialize the classified data the KNN algorithm will utilise.
     * @param dataPath the path to the classified data
     */
    void init(std::string dataPath);

    /**
     * Use the KNN algorithm to classify the data stored in the dataPath,
     * and output the result to outputPath.
     * @param dataPath the path to the unclassified data
     * @param outputPath the desired output path
     */
    void write(std::string dataPath, std::string outputPath);
};

#endif