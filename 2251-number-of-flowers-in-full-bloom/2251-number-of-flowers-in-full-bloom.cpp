class Solution
{
    public:
        vector<int> fullBloomFlowers(vector<vector < int>> &flowers, vector< int > &persons)
        {
            int n = flowers.size();
            map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                mp[flowers[i][0]]++;
                mp[flowers[i][1] + 1]--;
            }
            int pre = 0;
            set<int> indexes;
            indexes.insert(0);
            for (auto it: mp)	//prefix sum on map
            {
                mp[it.first] += pre;
                pre = mp[it.first];
                indexes.insert(it.first);
               	// cout << it.first << " " << mp[it.first] << endl;
            }
            vector<int> ans;
            for (int i = 0; i < persons.size(); i++)
            {
                auto it = indexes.upper_bound(persons[i]);
                it--;
                ans.push_back(mp[*it]);
            }
            return ans;
        }
};