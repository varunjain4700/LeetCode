class Solution
{
    public:
        int latestTimeCatchTheBus(vector<int> &buses, vector<int> &pass, int cap)
        {
            sort(buses.begin(), buses.end());
            sort(pass.begin(), pass.end());
            int m = buses.size(), n = pass.size();
            int cnt = 0, i = 0, j = 0;
            map<int, int> vis;
            bool flag=0;
            while (i < n && j < m)
            {
               	//cout<<buses[j]<<" "<<pass[i]<<"   "<<pass[i]<<endl;
                if (pass[i] <= buses[j])
                {
                    vis[pass[i]] = 1;
                    i++;
                    cnt++;
                }
                else
                {
                    cnt = 0;
                    flag=1;
                    j++;
                }
                if (cnt == cap)
                {
                    flag=0;
                    cnt = 0;
                    j++;
                }
            }
            if (j < m||flag==1)
                if(!vis[buses[m-1]])
                    return buses[m - 1];
            for (auto it = vis.rbegin(); it != vis.rend(); it++)
            {
                int val = it->first;
               	//cout << val << endl;
                if (vis[val - 1] == 0)
                    return val - 1;
            }
            return 0;
        }
};