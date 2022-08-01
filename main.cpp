#include "classifier/Classifier.h"
#include <iostream>
#include <vector>
#include "classifier/Algorithms.h"

int main(int argc, char** argv) {
//    // Create a classifier
//    Classifier classifier(std::stoi(argv[0]));
//
//    // Initialize the classifier with the given data, ad classify the unclassified data
//    classifier.init(""); //TODO: add correct path
//    classifier.write("", ""); //TODO: add correct paths

    std::vector<double> v;
    v.push_back(1);
    v.push_back(-10);
    v.push_back(11);
    v.push_back(-90);
    v.push_back(17);
    // 1 -10 11 -90 17
    // -90 -10 1 11 17

    std::vector<int> indices = kSmallestElements(v, 3);
    std::cout << v[indices[0]] << std::endl;
    std::cout << v[indices[1]] << std::endl;
    std::cout << v[indices[2]] << std::endl;
//    std::cout << v[indices[3]] << std::endl;
//    std::cout << v[indices[4]] << std::endl;

    return 0;
}

