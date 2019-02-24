#include <iostream>
#include <vector>
int CutRod(std::vector<int> & p, int n) {
  if(n == 0) return 0;
  int q = -1;
  for(int i = 1; i <= n; ++i) {
    q = std::max(q, p[i - 1] + CutRod(p, n - i));
  }
  return q;
} 

int CutRodDP(std::vector<int> & p, int n) {
  int dp[n] = {};
  dp[0] = 0;
  for(int i = 1; i <= n; ++i) {
    dp[i] = std::max(p[i] + dp[n - i], dp[i + 1])
  }
}
int main()
{
  std::vector<int> p{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  std::cout << CutRod(p, 5) << std::endl;
  return 0;
}
