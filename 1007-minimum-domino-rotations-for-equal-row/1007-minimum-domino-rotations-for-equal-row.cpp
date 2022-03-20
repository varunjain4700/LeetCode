class Solution
{
    public:
        int minDominoRotations(vector<int> &top, vector<int> &bottom)
        {
            int n = top.size(), ans = INT_MAX;
            for (int i = 1; i <= 6; i++)
            {
                int cnt = 0, moves = 0;
                for (int j = 0; j < n; j++)	//making all top sides equal
                {
                    if (top[j] == i)
                        cnt++;
                    else if (bottom[j] == i)
                    {
                        moves++;
                        cnt++;
                    }
                    else
                        break;
                }
                if (cnt == n)
                    ans = min(ans, moves);
                cnt = 0, moves = 0;
                for (int j = 0; j < n; j++)	//making all bottom sides equal
                {
                    if (bottom[j] == i)
                        cnt++;
                    else if (top[j] == i)
                    {
                        moves++;
                        cnt++;
                    }
                    else
                        break;
                }
                if (cnt == n)
                    ans = min(ans, moves);
            }
            if (ans == INT_MAX)
                return -1;
            return ans;
        }
};