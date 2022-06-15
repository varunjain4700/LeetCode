class Solution
{
    public:
        vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
        {
            sort(potions.begin(), potions.end());
            vector<int> res;
            for (int i = 0; i < spells.size(); i++)
            {
                long long reqd = ceil((double) success / spells[i]);
                auto idx = lower_bound(potions.begin(), potions.end(), reqd) - potions.begin();
                res.push_back(potions.size() - idx);
            }
            return res;
        }
};