#include "ManhattanDistance.h"

double ManhattanDistance::distance(const Classified& v1, const Classified& v2) const {
    std::vector<double> diff = v1.data() - v2.data();
    double res = 0;
    int size = diff.size();

    for(int i = 0; i < size; ++i) {
        res += abs(diff[i]);
    }

    return res;
}