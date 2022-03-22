class Solution
{
    public:
       	//R----L,,,,,S----L,,,,,R----S
        int countCollisions(string dir)
        {
            int n = dir.size();
            int ans = 0, prev = dir[0], cnt = 0;
            if (dir[0] == 'R')
                cnt++;
            //cout<<ans<<" ";
            for (int i = 1; i < n; i++)
            {
                if (dir[i] == 'S')
                {
                    if (prev == 'R')
                    {
                        ans += cnt;
                        cnt = 0;
                    }
                     prev='S';
                }
                else if (dir[i] == 'L')
                {
                    if (prev == 'S')
                        ans++;
                    else if (prev == 'R')
                    {
                        ans += 2;
                        ans += (cnt - 1);
                        cnt = 0;
                        prev = 'S';
                    }
                    else 
                        prev='L';
                }
                else
                {
                    cnt++;
                    prev = 'R';
                }
               	// cout<<ans<<" ";
            }
           //	cout<<endl;
            return ans;
        }
};