#ifndef VEC4_H
#define VEC4_H
#include <iostream>
#include <vector>
#include <string>

/**
 * This class represents a vector in R^4.
 */
class Classified {
private:
    std::vector<double> m_data;
    std::string m_handle;

public:
    /**
     * empty constructor.
     */
    Classified();

    /**
     * constructor.
     * @param handle the handle
     * @param data the data
     */
    Classified(std::string handle, std::vector<double> data);

    /**
    * copy constructor.
    * @param classified another classified instance
    */
    Classified(const Classified& classified);

    /**
     * handle getter
     */
    std::string handle();

    /**
     * handle setter
     */
     void handle(std::string handle);

    /**
     * the '-' operator.
     * @return the vector reversed
     */
    Classified operator-() const;

    /**
     * the '[]' get operator.
     * @param i an integer
     * @return the i-th component of the vector
     */
    double operator[](double i) const;

    /**
     * the '+=' operator
     * @param v another vector
     * @return the sum of the LHS and RHS vectors
     */
    Classified& operator+=(const Classified& v);

    /**
     * the '*=' operator
     * @param t a scalar
     * @return the vector, multiplied by the scalar t
     */
    Classified& operator*=(const double t);

    /**
     * the '/=' operator
     * @param t a scalar
     * @return the vector, multiplied by the inverse of the scalar t
     */
    Classified& operator/=(const double t);

    /**
     * the '+' operator.
     * @param u another vector
     * @return the sum of the two vectors
     */
    const Classified operator+(const Classified& u) const;

    /**
     * the '-' operator.
     * @param u another vector
     * @return the sum of the two vectors
     */
    const Classified operator-(const Classified& u) const;

    /**
     * the '*' operator.
     * @param u another vector
     * @return the sum of the two vectors
     */
    const Classified operator*(double t) const;

    /**
     * the '/' operator.
     * @param t a scalar
     * @return the vector, multiplied by the scalar t
     */
    const Classified operator/(double t) const;

    /**
     * @return the length of the vector
     */
    double len() const;
};

// Other Classified-related functions

/**
 * the '*' operator.
 * @param t a scalar
 * @param u a vector
 * @return the product of the scalar t and u
 */
const Classified operator*(double t, const Classified& u);

// Type aliases for Classified
using Iris = Classified;

#endif
