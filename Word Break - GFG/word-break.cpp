// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
//helloworld
    int wordBreak(string str, vector<string> &dict) {
        int m=dict.size(),n=str.size();
        vector<bool>dp(n+1,0);
        unordered_set<string>words;
        for(int i=0;i<m;i++)
        {
            words.insert(dict[i]);
        }
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]==1&&words.find(str.substr(j,i-j))!=words.end())
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends