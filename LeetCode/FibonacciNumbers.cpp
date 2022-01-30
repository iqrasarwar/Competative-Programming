//DP Technique

int dp[50];

class Solution {
public:
    
    Solution()
    {
        memset(dp,-1,sizeof(dp));
    }
int fib(int n)
{
	if (dp[n] != -1) return dp[n];
	if (n == 0)return 0;
	if (n == 1)return 1;
	return dp[n] = fib(n - 1) + fib(n - 2);
}

};


//Runtime, Memory	= 2 ms,	5.9 MB


//BurteForce

class Solution {
public:
    
    int fib(int n)
    {
        if (n == 0)return 0;
        if (n == 1)return 1;
        return fib(n - 1) + fib(n - 2);
    }
};
