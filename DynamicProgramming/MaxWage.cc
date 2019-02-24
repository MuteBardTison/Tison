#include <iostream>
#include <vector>

int MaxWage(int wage[], int job[], int n) {
  std::vector<int> dp(n + 1);
  dp[0] = 0;
  for(int i = 1; i <= n; ++i) {
    dp[i] = std::max(wage[i - 1] + dp[job[i - 1]], dp[i - 1]);
  }
  return dp[n];
}
int main() {
  int wage[] = {5, 1, 8, 4, 6, 3, 2, 4};
  int job[] = {0, 0, 0, 1, 0, 2, 3, 5};
  for(int i = 1; i <= 8; ++i)
  std::cout << MaxWage(wage, job, i) << std::endl;
  return 0;
}