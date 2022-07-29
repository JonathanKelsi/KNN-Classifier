# KNN Classifier

This repository implements the  [k-nearest neighbors algorithm](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm), 
using different metrics to classify types of Irises, based on given data. 

## Description
The classifier receives paths to files *Classified.csv*, *Unclassified.csv* and 
the path to the output directory.

* *Classified.csv* stores the dataset of three different
kind of Irises (Setosa, Virginia, Versicolor).
* *Unclassified.csv* stores the dataset of unidentified Irises.

each Iris in the datasets has four properties: width and length of it's sepals,
and width and length of it's petals.
</br>

Using the KNN algorithm, the classifier determines the type of the unclassified
Irises, and returns it in three different files: 

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
make -j && make KNN-Classifier <arg1> <arg2> <arg3>
```

## Authors
[Jonathan Kelsi](https://github.com/JonathanKelsi)  
[Ido Katzav](https://github.com/idokatzav)

## Acknowledgments

We've relied on [Wikipedia](https://www.wikipedia.org/) in order to better 
understand and implement some of the algorithms we used.