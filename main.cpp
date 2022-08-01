#include "classifier/Classifier.h"
#include <iostream>
#include <vector>
#include "classifier/Algorithms.h"
#include <map>

int main(int argc, char** argv) {
//    // Create a classifier
//    Classifier classifier(std::stoi(argv[0]));
//
//    // Initialize the classifier with the given data, ad classify the unclassified data
//    classifier.init(""); //TODO: add correct path
//    classifier.write("", ""); //TODO: add correct paths

    std::map<std::string, int> map;
//    std::cout << (map.find("Hi") == map.end()) << std::endl;
    map["Hi"] = 5;
    map["hi"]++;
    std
    std::cout << map["Hi"];
    return 0;
}

