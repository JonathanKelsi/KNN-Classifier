#include "classifier/Classifier.h"
#include <vector>

int main(int argc, char** argv) {
    // Create a classifier
    auto classifier = new Classifier(3);

    // Initialize the classifier with the given data, ad classify the unclassified data
    classifier->init("../input/Classified.csv");
    classifier->write("../input/Unclassified.csv", "../output");

    delete classifier;
    return 0;
}

