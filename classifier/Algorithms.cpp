#include "Algorithms.h"
#include <random>

double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0, 1);
    static std::mt19937 generator;
    return distribution(generator);
}

void swap(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}

int partition(std::vector<double> &v, int left, int right, int pivot) {
    double pivotVal = v[pivot];

    // Move the pivot to the end
    swap(v[pivotVal], v[right]);

    int index = left;
    for (int i = left; i < right - 1; ++i) {
        if (v[i] < pivotVal) {
            swap(v[index], v[i]);
            index++;
        }
    }


    // Move pivot to it's final place
    swap(v[right], v[index]);

    return index;
}

double select(std::vector<double> v, int left, int right, int k) {
    // If the vector contains only one element
    if (left == right) {
        return v[left];
    }

    // Select an index between left and right
    int pivot = left + floor(randomDouble() * (right - left + 1));
    pivot = partition(v, left, right, pivot);

    // If we've found the desired element
    if (pivot == k) {
        return v[k];
    } else if (k < pivot) {
        return select(v, left, pivot -1, k);
    }

    // Else
    return select(v, pivot + 1, right, k);
}