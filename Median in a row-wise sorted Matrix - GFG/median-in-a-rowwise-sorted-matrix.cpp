// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
//1,1,2,2,3,4,6
int solve(int r,int c,int target,vector<vector<int>>&mat)
{
    if(mat[r][0]>target)
        return 0;
    int low=0,high=c-1;
    while(low<high)
    {
        int mid=(low+high+1)/2;
        if(mat[r][mid]>target)
            high=mid-1;
        else 
            low=mid;
    }
    return low+1;
}
    int median(vector<vector<int>> &mat, int r, int c){
          int low=1,high=2000;
          while(low<high)
          {
              int mid=(low+high)/2;
              int cnt=0;
              for(int i=0;i<r;i++)
                cnt+=solve(i,c,mid,mat);
                 //cout<<mid<<" "<<cnt<<endl;
            if(cnt>(r*c)/2)
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
          }
          return low;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends