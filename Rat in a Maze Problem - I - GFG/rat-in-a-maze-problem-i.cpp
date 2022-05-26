// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4]={1,0,0,-1};
    int dy[4]={0,-1,1,0};
    void solve(int x,int y,vector<vector<int>>&mat,
    vector<vector<bool>>&vis,int n,string temp,vector<string>&res)
    {
        if(x==n-1&&y==n-1)
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<n&&!vis[xx][yy]&&mat[xx][yy]==1)
            {
                vis[xx][yy]=1;
                if(i==0)
                    temp+="D";
                else if(i==1)
                    temp+="L";
                else if(i==2)
                    temp+="R";
                else 
                    temp+="U";
                solve(xx,yy,mat,vis,n,temp,res);
                temp.pop_back();
                vis[xx][yy]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        if(mat[0][0]==0||mat[n-1][n-1]==0)
            return {};
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vector<string>res;
        string temp;
        vis[0][0]=1;
        solve(0,0,mat,vis,n,temp,res);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends