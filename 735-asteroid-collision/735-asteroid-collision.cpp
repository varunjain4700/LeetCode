class Solution
{
    public:
       	//collision will only take place when asteroid moving in negative/left direction is present to the right of asteroid moving in positive/right direction
        vector<int> asteroidCollision(vector<int> &asteroids)
        {
            int n = asteroids.size();
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                if (asteroids[i] < 0)
                {
                    while (!st.empty() && st.top() > 0 && st.top() < -asteroids[i])	//remove all asteroids from the left that are smaller than the current one
                        st.pop();
                    if (!st.empty() && st.top() > 0)
                    {
                        if (st.top() == -asteroids[i])	//both asteroids are of same size-->remove both(current and previous one)
                        {
                            st.pop();
                            continue;
                        }
                        if (st.top() > -asteroids[i])	//current asteroid is smaller in size,so just don't include this in stack
                            continue;
                    }
                }
                st.push(asteroids[i]);
            }
            vector<int> ans;
            while (!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};