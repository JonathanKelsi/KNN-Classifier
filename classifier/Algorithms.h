#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

/**
 * @return a random real number in [0,1)
 */
double randomDouble();

/**
 * swap two real numbers.
 * @param x a reference to a number
 * @param y another reference to a number
 */
void swap(double& x, double&y);

/**
 * group v[left...right] into two parts: those smaller than v[pivot] and those bigger than v[pivot].
 * @param v a vector of real numbers
 * @param left a lower bound on the indices
 * @param right an upper bound on the indices
 * @param pivot a pivot
 * @return the
 */
int partition(std::vector<double> &v, int left, int right, int pivot);

/**
 * @param left a lower bound on the indices
 * @param right an upper bound on the indices
 * @param k an integer s.t left <= k <= right
 * @return the k-th smallest element of v[left...right]
 */
double select(std::vector<double> v, int left, int right, int k);



#endif
