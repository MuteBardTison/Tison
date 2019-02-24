#include <iostream>
#include <vector>

int MaxSum(int arr[], int n) {
  std::vector<int> dp(n);
  dp[0] = arr[0];
  dp[1] = std::max(arr[0], arr[1]);
  for(int i = 2; i < n; ++i) {
    dp[i] = std::max(arr[i] + dp[i - 2], dp[i - 1]);
  }
  return dp[n - 1];
}

int main() {
  int arr1[] = {4, 1, 1, 9, 1};
  int arr2[] = {1, 2, 4, 1, 7, 8, 3};
  std::cout << MaxSum(arr1, 5) << std::endl;
  std::cout << MaxSum(arr2, 7) << std::endl;
  return 0;
}