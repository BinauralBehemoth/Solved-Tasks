/*
 * Product of consecutive Fib numbers
 *
 * The Fibonacci numbers are the numbers in the following integer sequence (Fn):
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
 * such as
 * F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.
 * Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying
 * F(n) * F(n+1) = prod.
 * Your function productFib takes an integer (prod) and returns an array:
 * [F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)
 * depending on the language if F(n) * F(n+1) = prod.
 * If you don't find two consecutive F(m) verifying F(m) * F(m+1) = prodyou will return
 * [F(m), F(m+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)
 * F(m) being the smallest one such as F(m) * F(m+1) > prod.
 *
 * Some Examples of Return:
 * productFib(714) # should return {21, 34, true}, 
 *                 # since F(8) = 21, F(9) = 34 and 714 = 21 * 34
 * productFib(800) # should return {34, 55, false}, 
 *                 # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55
 */


#include <vector>

typedef unsigned long long ull;

class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod){
    
    std::vector<ull> answer, fib = {1, 1};
    ull mult;
    
    do {
      ull newNum = fib[fib.size()-2] + fib[fib.size()-1];
      fib.push_back(newNum);
      mult = fib[fib.size()-2] * fib[fib.size()-1];
    } while (mult < prod);
    
    answer.push_back(fib[fib.size()-2]);
    answer.push_back(fib[fib.size()-1]);
    
    if (mult == prod) {
      answer.push_back(1);
    }
    else {
      answer.push_back(0);
    }
    return answer;
    
  }
};
