/* 
 * Missing Number
 *
 * You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.
 *
 * Input
 *
 * The first input line contains an integer n.
 * The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).
 *
 * Output
 *
 * Print the missing number.
 *
 * Constraints
 * 2≤n≤2⋅105
 *
 * Example
 *
 * Input:
 * 5
 * 2 3 1 5
 *
 * Output:
 * 4
 */


#include <iostream>
#include <vector>

int main() {

	int n, inputNumber;
	std::cin >> n;
	std::vector<bool> arr(n); //for registration every inputed number

	//register every inputed number in arr
	for (int i = 1; i <= n - 1; i++) {
		std::cin >> inputNumber;
		arr[inputNumber - 1] = true;
	}

	//find an unregistered number
	for (int i = 1; i <= n; i++) {
		if (arr[i - 1] == false) {
			std::cout << i;
		}
	}

	return 0;
}
