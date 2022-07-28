#ifndef Classified_H
#define Classified_H
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
    const std::string& handle() const;

    /**
     * data getter
     */
    const std::vector<double>& data() const;

    /**
     * handle setter
     */
     void handle(std::string handle);
};

// Vector utility functions

/**
 * the '-' operator.
 * @param v a vector
 * @return the vector reversed
 */
std::vector<double> operator-(std::vector<double>& v);

/**
 * the '+' operator.
 * @param v a vector
 * @param u another vector
 * @return the sum of the two vectors
 */
const std::vector<double> operator+(const std::vector<double>& v, const std::vector<double>& u);

/**
 * the '-' operator.
 * @param v a vector
 * @param u another vector
 * @return u - v
 */
const std::vector<double> operator-(const std::vector<double>& u, const std::vector<double>& v);

/**
 * the '*' operator.
 * @param t a scalar
 * @param v a vector
 * @return the vector, multiplied by the scalar t
 */
const std::vector<double> operator*(double t, std::vector<double> v);

/**
 * the '*' operator.
 * @param v a vector
 * @param t a scalar
 * @return the product of the scalar t and v
 */
const std::vector<double> operator*(const std::vector<double>& v, double t);

/**
 * the '/' operator.
 * @param t a scalar
 * @param v a vector
 * @return the vector, multiplied by the inverse the scalar t
 */
const std::vector<double> operator/(std::vector<double> v, double t);

/**
 * @return the length of the vector
 */
double len(const std::vector<double>& v);


// Type aliases for Classified
using Iris = Classified;

#endif
