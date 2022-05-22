class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int cnt=1,ans=0;
        long double slope=0,m;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(cnt<=1)
            {
                if(cnt==1){
                    slope=(long double)(nums[i][1]-nums[i-1][1])/(nums[i][0]-nums[i-1][0]);
                    // ss.insert(slope);
                    cnt++;
                }
                else
                    cnt++;
            }
            else
            {
                 m=(long double)(nums[i][1]-nums[i-1][1])/(nums[i][0]-nums[i-1][0]);
                //cout<<m<<" "<<slope<<endl;
                if(m==slope)
                {
                    cnt++;
                }
                else
                {
                    slope=m;
                    cnt=2;
                    ans++;
                }
            }
           // cout<<ans<<" "<<slope<<endl;
        }
        //cout<<endl;
        ans++;
        return ans;
    }
};