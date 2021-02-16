/* 
 * Find The Parity Outlier
 *
 * You are given an array (which will have a length of at least 3, but could be very large)
 * containing integers. The array is either entirely comprised of odd integers or entirely
 * comprised of even integers except for a single integer N. Write a method that takes the array
 * as an argument and returns this "outlier" N.
 *
 * Examples:
 * [2, 4, 0, 100, 4, 11, 2602, 36]
 * Should return: 11 (the only odd number)
 *
 * [160, 3, 1719, 19, 11, 13, -21]
 * Should return: 160 (the only even number)
 */


#include <vector>

// function to check if number is odd
bool ifOdd(int number) {
	if (number >= 0) {
		return number % 2;
	}
	else {
		return (-number) % 2;
	}
}

// function to solve task
int FindOutlier(std::vector<int> arr) {

	bool odd;	// TRUE if mostly numbers are odd and it's needed to find an even number in array
			// FALSE if mostly numbers are even and it's needed to find an odd number in array

	// check if mostly numbers in array are odd or even by first 3 numbers
	if (ifOdd(arr[0]) == ifOdd(arr[1])) {
		odd = ifOdd(arr[0]);
	}
	else {
		odd = ifOdd(arr[2]);
	}

	// looking for outlier
	for (int i = 0; i <= arr.size() - 1; i++) {
		if (ifOdd(arr[i]) != odd) {
			return arr[i];
		}
	}
}
