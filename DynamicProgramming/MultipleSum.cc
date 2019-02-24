#include <iostream>
#include <vector>


bool MultipleSum(int arr[], int n, int target) {
  std::vector<std::vector<bool>> dp(n, std::vector<bool>(target + 1, false));
  for(int i = 0; i <= target; ++i)
  {
    if(arr[0] == i)
      dp[0][i] = true;
    else
      dp[0][i] = false;
  }
  for(int i = 0; i < n; ++i)
    dp[i][0] = true;
  for(int i  = 1; i < n; ++i) {
    for(int j = 1; j <= target; ++j) {
      if(arr[i] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
    }
  }
  return dp[n - 1][target];
}

int main() {
  int arr[] = {3, 34, 4, 12, 5, 2};
  std::cout << MultipleSum(arr, 6, 9) << std::endl;
  std::cout << MultipleSum(arr, 6, 10) << std::endl;
  std::cout << MultipleSum(arr, 6, 11) << std::endl;
  std::cout << MultipleSum(arr, 6, 12) << std::endl;
  std::cout << MultipleSum(arr, 6, 13) << std::endl;
  std::cout << MultipleSum(arr, 6, 14) << std::endl;
  std::cout << MultipleSum(arr, 6, 15) << std::endl;
}