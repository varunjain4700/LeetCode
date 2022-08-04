class Solution {
public:
    //[1,2,1,2] k=3
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            sum%=k;
            sum+=k;
            ans+=mp[sum%k];
            mp[sum%k]++;
        }
        return ans;
    }
};