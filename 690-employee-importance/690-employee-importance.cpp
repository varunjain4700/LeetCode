/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
    public:
        void dfs(int id, vector<Employee*> employees, vector<int> &cnt, unordered_map< int, int> &mp)
        {
            int src = mp[id];
            cnt[id] += employees[src]->importance;
            for (auto it: employees[src]->subordinates)
            {
                dfs(it, employees, cnt, mp);
                cnt[id] += cnt[it];
            }
        }
    int getImportance(vector<Employee*> employees, int id)
    {
        vector<int> cnt(2001, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < employees.size(); i++)
            mp[employees[i]->id] = i;
        dfs(id, employees, cnt, mp);
        return cnt[id];
    }
};