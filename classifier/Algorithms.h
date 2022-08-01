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
 * @return the sum of the two vectors (u+v)
 */
const std::vector<double> operator+(const std::vector<double>& v, const std::vector<double>& u);

/**
 * the '-' operator.
 * @param v a vector
 * @param u another vector
 * @return the difference of the two vectors (u - v)
 */
const std::vector<double> operator-(const std::vector<double>& u, const std::vector<double>& v);

/**
 * the '*' operator.
 * @param t a scalar
 * @param v a vector
 * @return the vector, multiplied by the scalar t (t*v)
 */
const std::vector<double> operator*(double t, const std::vector<double>& v);

/**
 * the '*' operator.
 * @param v a vector
 * @param t a scalar
 * @return the product of the scalar t and v (v*t)
 */
const std::vector<double> operator*(const std::vector<double>& v, double t);

/**
 * the '/' operator.
 * @param t a scalar
 * @param v a vector
 * @return the vector, multiplied by the inverse of the scalar t (t^-1*v)
 */
const std::vector<double> operator/(const std::vector<double>& v, double t);

/**
 * @return the length of the vector
 */
double len(const std::vector<double>& v);


// Other utility functions


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
 * swap two pairs of double and integer.
 * @param p1 a reference to a pair
 * @param p2 a reference to another pair
 */
void swap(std::pair<double,int>& p1, std::pair<double,int>& p2);


// Algorithms


/**
 * group v[left...right] into two parts: those smaller than v[pivot] and those bigger than v[pivot].
 * @param v a vector of real numbers, paired with their original indices
 * @param left a lower bound on the indices
 * @param right an upper bound on the indices
 * @param pivot a pivot
 * @return the new index of v[pivot]
 */
static int partition(std::vector<double>& v, std::vector<int>& indices, int left, int right, int pivot);

/**
 * @param v a vector of real numbers, paired with their original indices
 * @param left a lower bound on the indices
 * @param right an upper bound on the indices
 * @param k an integer s.t left <= k <= right
 * @return the k-th smallest element of v[left...right]
 */
static double quickSelect(std::vector<double>& v, std::vector<int>& indices, int left, int right, int k);

/**
 * @param k an integer
 * @return a vector of the k-th smallest elements of the array
 */
std::vector<int> kSmallestElements(const std::vector<double>& v, int k);

#endif
