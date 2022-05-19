// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        int ans=0,curr_sum=0;
        map<int,int>mp;
        mp[0]=-1;
       for(int i=0;i<n;i++)
       {
           curr_sum+=nums[i];
           if(mp.find(curr_sum)!=mp.end())
                ans=max(ans,i-mp[curr_sum]);
            if(mp.find(curr_sum)==mp.end())
                mp[curr_sum]=i;
       }
       return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends