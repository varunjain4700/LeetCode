class Solution
{
    public:
        vector<vector < int>> reconstructQueue(vector<vector < int>> &people)
        {
            sort(people.begin(), people.end());
            int n = people.size();
            vector<vector < int>> res(n, vector<int> (2, -1));
            for (int i = 0; i < n; i++)
            {
                int cnt = 0, greaterHeight = people[i][1];
                int j = 0;
                while (cnt != greaterHeight)	//first reach at a location which has number of people whose height is larger than desired(that place may be occupied but maybe)
                {
                    if (res[j][0] == -1 || res[j][0] >= people[i][0])
                        cnt++;
                    j++;
                }
                while (res[j][0] != -1)	//then find an empty location to place this person
                    j++;
                res[j][0] = people[i][0];
                res[j][1] = people[i][1];
            }
            return res;
        }
};