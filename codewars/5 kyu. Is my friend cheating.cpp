/*
 * Is my friend cheating?
 *
 * A friend of mine takes the sequence of all numbers from 1 to n (where n > 0). Within
 * that sequence, he chooses two numbers, a and b. He says that the product of a and b
 * should be equal to the sum of all numbers in the sequence, excluding a and b. Given
 * a number n, could you tell me the numbers he excluded from the sequence?
 * The function takes the parameter: n (n is always strictly greater than 0) and returns
 * an array or a string (depending on the language) of the form:
 * [(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or [{a, b}, ...]
 * with all (a, b) which are the possible removed numbers in the sequence 1 to n.
 * [(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or ... will be sorted in increasing order
 * of the "a".
 * It happens that there are several possible (a, b). The function returns an empty array (or an empty string) if no possible numbers are found which will prove that my friend has not told the truth! (Go: in this case return nil).
 *
 * Examples:
 * removNb(26) should return { {15, 21}, {21, 15} }
 */


#include <vector>

class RemovedNumbers
{
public:
  static std::vector<std::vector<long long>> removNb(long long n) {
    
    std::vector<std::vector<long long>> answer;
    long long sum = 0;
    
    for (long long i = 1; i <= n; i++) {
      sum += i;
    }
    
    for (long long a = 1; a <= n; a++) {
      if ((sum - a) % (a + 1) == 0) {
        
        int b = (sum - a) / (a + 1);
        if (b >= 1 && b <= n) {
          std::vector<long long> pair = { a, b };
          answer.push_back(pair);
        }
        
      }
    }
    
    return answer;
  }
};
