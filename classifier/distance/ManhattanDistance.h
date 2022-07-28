#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H

#include "Distance.h"
#include "../Classified.h"

class ManhattanDistance : public Distance {
public:
    /**
     * @param v1 a vector in R^4
     * @param v2 another vector in R^4
     * @return the manhattan distance between the two
     */
    virtual double distance(const std::vector<double>& v1, const std::vector<double>& v2) const override;
};

#endif
