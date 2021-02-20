/*
 * Create Phone Number
 *
 * Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string
 * of those numbers in the form of a phone number.
 *
 * Example:
 * createPhoneNumber(int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}) // => returns "(123) 456-7890"
 */


#include <string>

std::string createPhoneNumber(const int arr[10]) {
	
	std::string phoneNumber = "";
	
	//converting from int[10] to string
	for (int i = 0; i <= 9; i++) {
		phoneNumber += std::to_string(arr[i]);
	}

	return ("(" + phoneNumber.substr(0, 3) + ") " + phoneNumber.substr(3, 3) + "-"
		+ phoneNumber.substr(6, 4));
}
