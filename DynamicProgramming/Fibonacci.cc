#include <iostream>
#include <vector>

int fib(int n) {
  if(n == 1 || n == 2) return 1;
  return fib(n - 1) + fib(n - 2); 
}

int fibDP(int n) {
  std::vector<int> dp(n);
  dp[0] = dp[1] = 1;
  for(int i = 2; i < n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n - 1];
}

int main() {
  std::cout << fib(20) << std::endl;
  std::cout << fibDP(20) << std::endl;
}
