// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool solve(int a[],int n,int m,long long mid)
    {
        long long total=0,cnt=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>mid)
                return false;
            if(total+a[i]<=mid)
            {
                total+=a[i];
            }
            else 
            {
                total=a[i];
                cnt++;
            }
        }
        if(cnt<=m)
            return true;
        return false;
            
    }
    int findPages(int a[], int n, int m) 
    {
        long long low=1;
        long long high=1e12;
        while(low<high)
        {
            long long mid=(low+high)/2;
            if(solve(a,n,m,mid))
                high=mid;
            else 
                low=mid+1;
        }
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends