// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
            v.push_back({start[i],end[i]});
        sort(v.begin(),v.end(),cmp);
        int end_time=v[0][1];
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(v[i][0]>end_time)
            {
                end_time=v[i][1];
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends