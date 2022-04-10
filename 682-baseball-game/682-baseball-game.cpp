class Solution
{
    public:
        int calPoints(vector<string> &ops)
        {
            int n = ops.size();
            vector<int> scores;
            for (int i = 0; i < n; i++)
            {
                if (ops[i] == "+")
                {
                    int score1 = scores.back();
                    scores.pop_back();
                    int score2 = scores.back();
                    scores.push_back(score1);
                    scores.push_back(score1 + score2);
                }
                else if (ops[i] == "D")
                {
                    scores.push_back(scores.back() *2);
                }
                else if (ops[i] == "C")
                {
                    scores.pop_back();
                }
                else
                {
                    scores.push_back(stoi(ops[i]));
                }
            }
            int ans = 0;
            for (int i = 0; i < scores.size(); i++)
            {
                ans += scores[i];
            }
            return ans;
        }
};