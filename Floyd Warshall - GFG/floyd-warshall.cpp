// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
	    int n=mat.size();
	     // vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(mat[i][k]==-1||mat[k][j]==-1)
	                    continue;
	                if(mat[i][j]==-1)
	                    mat[i][j]=mat[i][k]+mat[k][j];
	               else
	                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	            }
	        }
	    }
	   // for(int i=0;i<n;i++)
	   // {
	   //     for(int j=0;j<n;j++)
	   //         mat[i][j]=dis[i][j];
	   // }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends