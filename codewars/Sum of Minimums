/* 
 * Sum of Minimums
 *
 * Given a 2D vector of size m * n. Your task is to find the sum of minimum value in each row.
 *
 * For Example:
 *
 * {
 * {1,2,3,4,5},       // minimum value of row is 1
 * {5,6,7,8,9},       // minimum value of row is 5
 * {20,21,34,56,100}  // minimum value of row is 20
 * }
 */


#include <vector>

int sum_of_minimums(const std::vector<std::vector<int>> &numbers) {

	int min, sum = 0;

	for (int n = 0; n <= numbers.size() - 1; n++) {
		min = numbers[n][0];
		for (int m = 0; m <= numbers[n].size() - 1; m++) {
			if (numbers[n][m] < min) {
				min = numbers[n][m];
			}
		}
		sum += min;
	}

	return sum;
}
