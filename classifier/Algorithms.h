#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

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
double quickSelect(std::vector<double>& v, int left, int right, int k);

/**
 * @param k an integer s.t left <= k <= right
 * @return the k-th smallest element of v
 */
double quickSelect(std::vector<double>& v, int k);

#endif
