// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int idx,int coins[],int n,int v,vector<vector<int>>&dp)
	{
	    if(v==0)
	        return 0;
	    if(idx==n)
	        return 1e9;
	   if(dp[idx][v]!=-1)
	    return dp[idx][v];
	   int ans=0;
	   if(coins[idx]<=v)
	   {
	       ans=min(solve(idx+1,coins,n,v,dp),1+solve(idx,coins,n,v-coins[idx],dp));
	   }
	   else
	        ans=solve(idx+1,coins,n,v,dp);
	   return dp[idx][v]=ans;
	}
	int minCoins(int coins[], int m, int v) 
	{ 
	    vector<vector<int>>dp(m+1,vector<int>(v+1,-1));
	    int ans= solve(0,coins,m,v,dp);
	    if(ans==1e9)
	        return -1;
	       return ans;
	   // for(int i=0;i<=m;i++)
	   //     dp[i][0]=0;
	   //for(int i=1;i<=v;i++)
	   // dp[0][i]=INT_MAX-1;
	   // for(int i=1;i<=m;i++)
	   // {
	   //     for(int j=1;j<=v;j++)
	   //     {
	   //         if(coins[i-1]<=j)
	   //         {
	   //             dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	   //         }
	   //         else
	   //             dp[i][j]=dp[i-1][j];
	   //     }
	   // }
	   // if(dp[m][v]==INT_MAX-1)
	   //     return -1;
	   // return dp[m][v];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends