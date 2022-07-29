#ifndef CHEBYSHEVDISTANCE_H
#define CHEBYSHEVDISTANCE_H

#include "Distance.h"
#include "../Classified.h"

class ChebyshevDistance : public Distance {
public:
    /**
     * @param v1 a vector
     * @param v2 another vector
     * @return the chebyshev distance between the two
     */
    virtual double distance(const std::vector<double>& v1, const std::vector<double>& v2 ) const override;
};

#endif
