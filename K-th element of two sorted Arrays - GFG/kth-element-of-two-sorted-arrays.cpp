// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if (n > m)
                return kthElement(nums2, nums1,m,n,k);
            int low=max(0,k-m),high=min(k,n);
            while (low <= high)
            {
                int cut1 = (low + high) / 2;
                int cut2 = k - cut1;
               	// cout << cut1 << " " << cut2 << endl;
                int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
                if (cut1 != 0)
                    l1 = nums1[cut1 - 1];
                if (cut2 != 0)
                    l2 = nums2[cut2 - 1];
                if (cut1 != n)
                    r1 = nums1[cut1];
                if (cut2 != m)
                    r2 = nums2[cut2];
                if (l1 <= r2 && l2 <= r1)
                {
                   return max(l1,l2);
                }
                else if (l1 > r2)
                    high = cut1 - 1;
                else
                    low = cut1 + 1;
            }
            return 0;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends