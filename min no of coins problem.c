#include <stdio.h>
#include <limits.h>

int minCoinsUtil(int coins[], int m, int V, int* dp)
{
    if (V == 0)
        return 0;
    if (dp[V] != -1)
        return dp[V];
    int res = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (coins[i] <= V) {
            int sub_res = minCoinsUtil(coins, m, V - coins[i], dp);
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    dp[V] = res;
    return res;
}
int minCoins(int coins[], int m, int V)
{
    int dp[V + 1];
    for (int i = 0; i <= V; i++)
        dp[i] = -1;
    return minCoinsUtil(coins, m, V, dp);
}
int main()
{
  int m;
  printf("Enter the no. of kinds of coins:");
  scanf("%d",&m);
  int coins[m];
  printf("\nEnter the values of coins (in non-increasing  order):");
  for(int i=0;i<m;i++){
    scanf("%d",&coins[i]);
  }
  
    //int m = sizeof(coins) / sizeof(coins[0]);
    int V;
    printf("\nEnter the Amount:");
    scanf("%d",&V);
    int res = minCoins(coins, m, V);
    if (res == INT_MAX)
        res = -1;
    printf("Minimum coins required is %d", res);
    return 0;
}
