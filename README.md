

# Dynamic Programming in C++ 
A collection of leetcode problems solved using dynamic programming
These are not my solutions, but solutions built by github copilot

$$ \LARGE  f_n=f_{n-1} + f_{n-2} $$


```cpp
#include <bits/stdc++.h>
using namespace std;
int* dp = new int[INT_MAX];
int fib(int n)
{//memoization
    if (n <= 1) return n;//base case
    if (dp[n] != 0) return dp[n];//if already calculated
    dp[n] = fib(n - 1) + fib(n - 2);//calculate and store
    return dp[n];//return the answer
}
int main() 
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}
```





