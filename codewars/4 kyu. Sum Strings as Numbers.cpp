/*
 * Sum Strings as Numbers
 *
 * Given the string representations of two integers, return the string representation of the sum of those integers.
 *
 * For example:
 * sumStrings('1','2') // => '3'
 *
 * A string representation of an integer will contain no characters besides the ten numerals "0" to "9".
 */


#include <string>

std::string sum_strings(const std::string& a, const std::string& b) {
  std::string newA = a, newB = b;
  if (newA.size() < newB.size()) {
    do {
      newA.insert(0, "0");
    } while (newA.size() < newB.size());
  }
  else if (newA.size() > newB.size()) {
    do {
      newB.insert(0, std::string("0"));
    } while (newA.size() > newB.size());
  }
  std::string sum = "";
  int advSum = 0;
  for (int i = newA.size() - 1; i >= 0; i--) {
    int subSum = advSum + newA[i] + newB[i] - 96;
    if (subSum > 9) {
      subSum %= 10;
      advSum = 1;
    }
    else {
      advSum = 0;
    }
    sum.insert(0, std::to_string(subSum));
  }
  if (advSum == 1) {
    sum.insert(0, "1");
  }
  return sum;
}
