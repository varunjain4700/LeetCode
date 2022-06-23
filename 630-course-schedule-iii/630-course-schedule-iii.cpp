class Solution
{
    public:
        static bool cmp(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }
    int scheduleCourse(vector<vector < int>> &courses)
    {
        int n = courses.size();
        sort(courses.begin(), courses.end(), cmp);	//sort by deadline 
        priority_queue<int> pq;
        int total_time = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            total_time += courses[i][0];
            pq.push(courses[i][0]);
            ans++;
            if (total_time > courses[i][1])	//total_time exceeds the deadline so one of the course needs to be removed
            {
                total_time -= pq.top();	//remove the course which takes the highest amount of time 
                pq.pop();
                ans--;
            }
        }
        return ans;
    }
};