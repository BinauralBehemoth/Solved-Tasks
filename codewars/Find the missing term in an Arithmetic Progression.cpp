/*
 * Find the missing term in an Arithmetic Progression
 *
 * An Arithmetic Progression is defined as one in which there is a constant difference between
 * the consecutive terms of a given series of numbers. You are provided with consecutive elements
 * of an Arithmetic Progression. There is however one hitch: exactly one term from the original
 * series is missing from the set of numbers which have been given to you. The rest of the given
 * series is the same as the original AP. Find the missing term.
 *
 * You have to write a function that receives a list, list size will always be at least 3 numbers.
 * The missing term will never be the first or last one.
 * 
 * Example
 *
 * findMissing([1, 3, 5, 9, 11]) == 7
 */


#include <vector>

static long findMissing(std::vector<long> list) {
	
	long inc;	// for arithmetic progression difference


	// find progression difference by first 3 numbers
	if (list[1] - list[0] == list[2] - list[1]) {
		inc = list[1] - list[0];
	}

	// if their difference is not the same, then task is solved
	else if (list[1] - list[0] < list[2] - list[1]) {
		return list[1] + (list[1] - list[0]);
	}
	else {
		return list[0] + (list[2] - list[1]);
	}

	// find the missing number
	for (int i = 0; i <= list.size() - 2; i++) {
		if (list[i + 1] != list[i] + inc) {
			return list[i] + inc;
		}
	}
}