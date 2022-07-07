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
        void dfs(int id, vector<Employee*> employees, int &cnt, unordered_map<int, int> &mp)
        {
            int src = mp[id];
            cnt += employees[src]->importance;
            for (auto it: employees[src]->subordinates)
            {
                dfs(it, employees, cnt, mp);
            }
        }
    int getImportance(vector<Employee*> employees, int id)
    {
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < employees.size(); i++)
            mp[employees[i]->id] = i;
        dfs(id, employees, cnt, mp);
        return cnt;
    }
};