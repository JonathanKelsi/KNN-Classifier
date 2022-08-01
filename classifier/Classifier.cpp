#include "Classifier.h"
#include <memory>
#include <map>

void Classifier::classify(Classified& unclassified, const Distance& metric) const {
    if (!m_isInit) {
        return;
    }

    // Measure the distances from the unclassified vector to the gathered data
    std::vector<double> distances;
    auto dataSize = m_classifiedData.size();

    for (int i = 0; i < dataSize; ++i) {
        distances.push_back(metric.distance(unclassified.data(), m_classifiedData[i]->data()));
    }

    // Find the K nearest neighbours
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
    std::map<std::string, int>::iterator handleIterator = map.begin();
    std::string maxHandle = "";
    int maxTimes = 0;
    while (handleIterator != map.end()) {
        if (handleIterator->second > maxTimes) {
            maxHandle = handleIterator->first;
            maxTimes = handleIterator->second;
        }
    }
    unclassified.handle(maxHandle);
}

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

void Classifier::write(std::string dataPath, std::string outputPath) {
    //create a vector with the 3 type of distances: euclidean, chebyshev and manhattan for the classifications.
    std::unique_ptr<Distance> eD (reinterpret_cast<Distance *>(new EuclideanDistance()));
    std::unique_ptr<Distance> cD (reinterpret_cast<Distance *>(new ChebyshevDistance()));
    std::unique_ptr<Distance> mD (reinterpret_cast<Distance *>(new ManhattanDistance()));
    std::vector<std::unique_ptr<Distance>> distancesVector;
    distancesVector.push_back(std::move(eD));
    distancesVector.push_back(std::move(cD));
    distancesVector.push_back(std::move(mD));

    //create a vector of vectors which will contain the classification, each for one distance.
    //the first: EuclideanDistance, the second: ChebyshevDistance, the third: ManhattanDistance.
    //when the objects will be classified, they will be pushed into the corresponding vector.
    std::vector<std::vector<Classified>> outputs;
    auto numOfDistances = distancesVector.size();
    for (int i = 0; i < numOfDistances; ++i) {
        std::vector<Classified> vec;
        outputs.push_back(vec);
    }

    //we'll open the file of the input.
    std::string line;
    std::ifstream inFile(dataPath);

    //we'll create the objects from the file object by object, each line contains one object.
    while (std::getline(inFile, line)) {
        //for each line, we'll split it by ',' so we'll get the coordinates of each object.
        std::istringstream inputStringStream(line);
        std::string col;
        //vData will store the coordinates.
        std::vector<double> vData;
        //for each word in the line, we'll convert it to the double that contains in it.
        while (std::getline(inputStringStream, col, ',')) {
            if (isFloat(col)) {
                vData.push_back((double)std::atof(col.c_str()));
            }
        }
        //finally, we'll create form these coordinates a Classified object of this unclassified, and then classify it.
        //we'll do it as for each distance once.
        for (int i = 0; i < numOfDistances; ++i) {
            Classified classified("", vData);
            classify(classified, *distancesVector[i].get());
            //after classifying the object, we'll push it into the vector which is relevant to its distance type.
            outputs[i].push_back(classified);
        }
    }
    //we'll close the input file.
    inFile.close();
    //we'll create vector with the files names to write into.
    std::vector<std::string> files;
    files.push_back("euclidean_output.csv");
    files.push_back("chebyshev_output.csv");
    files.push_back("manhattan_output.csv");

    //know, for each distance, we'll print the classifications by the relevant distance.
    for (int i = 0; i < numOfDistances; ++i) {
        std::fstream ostream;
        ostream.open(outputPath + "/" + files[i]);
        auto numOfClassifieds = outputs[i].size();
        for (int j = 0; j < numOfDistances; ++j) {
            ostream << outputs[i][j].handle() << std::endl;
        }
        ostream.close();
    }
}