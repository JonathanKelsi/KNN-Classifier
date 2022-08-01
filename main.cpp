#include "classifier/Classifier.h"
#include <iostream>
#include <vector>
#include "classifier/Algorithms.h"
#include <map>

int main(int argc, char** argv) {
    // Create a classifier
    Classifier classifier(3);

    // Initialize the classifier with the given data, ad classify the unclassified data
    classifier.init("../input/classified.csv"); //TODO: add correct path
    classifier.write("../input/Unclassified.csv", "../output"); //TODO: add correct paths
    return 0;
}

