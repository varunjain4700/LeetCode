// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    // static bool cmp(pair<int,int>&a,pair<int,int>&b)
    // {
    //     return a.first>b.first;
    // }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<double,int>>items;
        for(int i=0;i<n;i++)
        {
            items.push_back({(double)arr[i].value/arr[i].weight,i});
        }
        sort(items.begin(),items.end(),greater<pair<double,int>>());
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[items[i].second].weight<=w)
            {
                ans+=arr[items[i].second].value;
                w-=arr[items[i].second].weight;
            }
            else
            {
                ans+=items[i].first*w;
                w=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends