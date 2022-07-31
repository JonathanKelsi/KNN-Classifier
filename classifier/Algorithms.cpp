#include "Algorithms.h"
#include <random>
#include <stdexcept>

const std::vector<double> operator-(const std::vector<double>& v) {
    std::vector<double> res = v;
    auto size = res.size();

    for (int i = 0; i < size; ++i) {
        res[i] *= -1;
    }

    return res;
}

const std::vector<double> operator+(const std::vector<double>& v, const std::vector<double>& u) {
    auto size = v.size();

    if (size != u.size()) {
        throw std::invalid_argument("The vectors don't have the same size");
    }

    std::vector<double> res = v;

    for (int i = 0; i < size; ++i) {
        res[i] += u[i];
    }

    return res;
}

const std::vector<double> operator-(const std::vector<double>& u, const std::vector<double>& v) {
    return v + (-u);
}

const std::vector<double> operator*(double t, const std::vector<double>& v) {
    std::vector<double> res = v;
    int size = res.size();

    for (int i = 0; i < size; ++i) {
        res[i] *= t;
    }

    return res;
}

const std::vector<double> operator*(const std::vector<double>& v, double t) {
    return t * v;
}

const std::vector<double> operator/(const std::vector<double>& v, double t) {
    return v * (1 / t);
}

double len(const std::vector<double>& v) {
    double lenSqrd = 0;
    double size = v.size();

    for (int i = 0; i < size; ++i) {
        lenSqrd += v[i] * v[i];
    }

    return sqrt(lenSqrd);
}

bool isFloat(const std::string& str) {
    char* ptr;
    strtof(str.c_str(), &ptr);
    return (*ptr) == '\0';
}

int random(int a, int b) {
    // Obtain a random number from hardware
    std::random_device rand;

    // Seed the generator
    std::mt19937 gen(rand());

    // Define the range
    std::uniform_int_distribution<> distr(a, b);

    return distr(gen);
}

void swap(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}

int partition(std::vector<double>& v, int left, int right, int pivot) {
    double pivotVal = v[pivot];

    // Move the pivot to the end
    swap(v[pivot], v[right]);

    int index = left;
    for (int i = left; i < right; ++i) {
        if (v[i] < pivotVal) {
            swap(v[index], v[i]);
            index++;
        }
    }

    // Move pivot to it's final place
    swap(v[right], v[index]);

    return index;
}

double quickSelect(std::vector<double> v, int left, int right, int k) {
    // If the vector contains only one element
    if (left == right) {
        return v[left];
    }

    // Select an index between left and right
    int pivot = random(left, right);
    pivot = partition(v, left, right, pivot);

    // If we've found the desired element
    if (k == pivot) {
        return v[k];
    } else if (k < pivot) {
        return quickSelect(v, left, pivot -1, k);
    }

    // Else
    return quickSelect(v, pivot + 1, right, k);
}

double quickSelect(const std::vector<double>& v, int k) {
    return quickSelect(v, 0, v.size() - 1, k);
}
