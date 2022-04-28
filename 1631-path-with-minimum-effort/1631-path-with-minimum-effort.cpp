class Solution
{
    public:
        int minimumEffortPath(vector<vector < int>> &mat)
        {
            int n = mat.size(), m = mat[0].size();
            vector<pair<pair<int,int>,int>> adj[n][m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if(i+1<n)
                        adj[i][j].push_back({{i+1,j},abs(mat[i+1][j]-mat[i][j])});
                    if(i-1>=0)
                        adj[i][j].push_back({{i-1,j},abs(mat[i-1][j]-mat[i][j])});
                     if(j-1>=0)
                        adj[i][j].push_back({{i,j-1},abs(mat[i][j-1]-mat[i][j])});
                     if(j+1<m)
                        adj[i][j].push_back({{i,j+1},abs(mat[i][j+1]-mat[i][j])});
                }
            }
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
            pq.push({0,{0,0}});
            vector<vector<int>>wt(n,vector<int>(m,INT_MAX));
            wt[0][0]=0;
            while(!pq.empty())
            {
                pair<int,pair<int,int>>p=pq.top();
                pq.pop();
                int x=p.second.first,y=p.second.second,d=p.first;
                for(auto child:adj[x][y])
                {
                    int u=child.first.first,v=child.first.second;
                    if(max(child.second,wt[x][y])<wt[u][v])
                    {
                        wt[u][v]=max(child.second,wt[x][y]);
                        pq.push({wt[u][v],{u,v}});
                    }
                }
            }
            return wt[n-1][m-1];
            
        }
};