#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <string>

// Vector utility functions

/**
 * the '-' operator.
 * @param v a vector
 * @return the vector reversed
 */
const std::vector<double> operator-(const std::vector<double>& v);

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
const std::vector<double> operator*(double t, const std::vector<double>& v);

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
 * @return the vector, multiplied by the inverse of the scalar t
 */
const std::vector<double> operator/(const std::vector<double>& v, double t);

/**
 * @return the length of the vector
 */
double len(const std::vector<double>& v);

// Algorithms and other utility functions

/**
 * @param str a string
 * @return whether the input string represents a floating point number
 */
bool isFloat(const std::string& str);

/**
 * @param a a lower bound
 * @param b an upper bound
 * @return a random real number in [a,b]
 */
int random(int a, int b);

/**
 * swap two double variables.
 * @param x a reference to a variable
 * @param y a reference to another variable
 */
void swap(double& x, double& y);

/**
 * group v[left...right] into two parts: those smaller than v[pivot] and those bigger than v[pivot].
 * @param v a vector of real numbers
 * @param left a lower bound on the indices
 * @param right an upper bound on the indices
 * @param pivot a pivot
 * @return the new index of v[pivot]
 */
int partition(std::vector<double>& v, int left, int right, int pivot);

/**
 * @param left a lower bound on the indices
 * @param right an upper bound on the indices
 * @param k an integer s.t left <= k <= right
 * @return the k-th smallest element of v[left...right]
 */
double quickSelect(std::vector<double> v, int left, int right, int k);

/**
 * @param k an integer s.t left <= k <= right
 * @return the k-th smallest element of v
 */
double quickSelect(const std::vector<double>& v, int k);

#endif
