/* Split Strings
 * 
 * Complete the solution so that it splits the string into pairs of two characters. If the string
 * contains an odd number of characters then it should replace the missing second character of the
 * final pair with an underscore ('_').
 *
 * Examples:
 * solution("abc") // should return {"ab", "c_"}
 * solution("abcdef") // should return {"ab", "cd", "ef"}
 */


#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
	std::vector<std::string> arr;
	std::string tempStr;	// temporary string for pushing into array
	
	// make every 2 characters of the source string into element of array
	if (s.size() > 1) {
		for (int i = 0; i <= s.size() - 2; i += 2) {
			tempStr = s[i];
			tempStr += s[i + 1];
			arr.push_back(tempStr);
		}
	}

	//if the string contains an odd number of characters
	if (s.size() % 2 == 1) {
		tempStr = s[s.size() - 1];
		tempStr += '_';
		arr.push_back(tempStr);
	}

	return arr;
}