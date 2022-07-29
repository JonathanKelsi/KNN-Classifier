#include "ChebyshevDistance.h"

double ChebyshevDistance::distance(const std::vector<double>& v1, const std::vector<double>& v2 ) const {
    std::vector<double> diff = v1 - v2;
    double max = 0;
    int size = diff.size();

    for(int i = 0; i < size; ++i) {
        max = max < abs(diff[i]) ? abs(diff[i]) : max;
    }

    return max;
}