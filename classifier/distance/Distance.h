#ifndef DISTANCE_H
#define DISTANCE_H

#include "../Classified.h"

/**
 * This class represents an abstract metric.
 */
class Distance {
public:
    /**
     * @param v1 a vector
     * @param v2 another vector
     * @return the distance between the two
     */
    virtual double distance(const std::vector<double>& v1, const std::vector<double>& v2 ) const = 0;
};

#endif