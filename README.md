# KNN Classifier

This repository implements the  [k-nearest neighbors algorithm](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm), 
using different metrics to classify types new data, based on given data. 

## Description
The classifier receives an integer *k* as an argument, and assumes the existence of
files *Classified.csv*, *Unclassified.csv* where:

* *Classified.csv* - stores the dataset known, classified objects.
* *Unclassified.csv* - stores the dataset of unidentified objects.

Using the KNN algorithm (with the given *k*), the classifier determines
the type of the unclassified objects, and returns it in three different files: 

* *euclidean_output.csv* 
* *chebyshev_output.csv* 
* *manhattan_output.csv*

Each file correspondence to a different metric that the KNN algorithm used.

## Getting Started

### Dependencies

This project uses CMake to generate and build. In a Debian-based system you can install it via:
```bash
sudo apt install cmake
```
bear in mind, CMake uses g++ in it's implementation, and so you need
to have the compiler installed. In a Debian-based system you can install 
it via:
```bash
sudo apt install g++
```

### Installation

Clone the repository:
```bash
git clone 'https://github.com/JonathanKelsi/KNN-Classifier'
```

### Executing program

To run the program, the standard CMake workflow can be used:
```bash
mkdir -p build && cd build
cmake ..
make -j && make KNN-Classifier <k>
```

## Authors
[Jonathan Kelsi](https://github.com/JonathanKelsi)  
[Ido Katzav](https://github.com/idokatzav)

## Acknowledgments

We've relied on [Wikipedia](https://www.wikipedia.org/) in order to better 
understand and implement some of the algorithms we used.