#include "ManhattanDistance.h"

double ManhattanDistance::distance(const Classified& v1, const Classified& v2) const {
    std::vector<double> diff = v1.data() - v2.data();
    double res = 0;

    for(int i = 0; i < diff.size(); i++) {
        res += abs(diff[i]);
    }

    return res;
}