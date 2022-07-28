#include <iostream>
#include "classifier/Classified.h"
#include <vector>

int main() {
    std::vector<double> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::vector<double> u;
    u.push_back(1);
    u.push_back(2);
    u.push_back(3);
    u.push_back(4);

    std::vector<double> w = u+v;

    std::cout << w[0] << w[1] << w[2] << w[3];

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

