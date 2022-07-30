#include "classifier/Classifier.h"
#include <iostream>

int main(int argc, char** argv) {

    // Create a classifier
    Classifier classifier(std::stoi(argv[0]));

    // Initialize the classifier with the given data, ad classify the unclassified data
    classifier.init(""); //TODO: add correct path
    classifier.write("", ""); //TODO: add correct paths

    std::cout << "Done";
    return 0;
}

