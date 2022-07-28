#ifndef DISTANCE_H
#define DISTANCE_H

#include "../Classified.h"

/**
 * This class represents an abstract metric.
 */
class Distance {
public:
    /**
     * @param v1 a vector in R^4
     * @param v2 another vector in R^4
     * @return the distance between the two
     */
    virtual double distance(const Classified& v1, const Classified& v2 ) const = 0;
};

#endif
