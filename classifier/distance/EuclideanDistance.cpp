#include "EuclideanDistance.h"

double EuclideanDistance::distance(const Classified& v1, const Classified& v2) const {
    return len(v1.data() - v2.data());
}