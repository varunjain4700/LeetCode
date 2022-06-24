class Solution
{
    public:
        bool isPossible(vector<int> &target)
        {
            int n = target.size();
            if (n == 1 && target[0] != 1)
                return false;
            long long sum = 0;
            priority_queue<int> pq;
            for (int i = 0; i < n; i++)
            {
                sum += target[i];
                pq.push(target[i]);
            }
            while (pq.top() != 1)
            {
                int num = pq.top();
                int temp = num;
                if (sum - num == 1)	//when sum of rest of the numbers is 1(it will always be possible to convert all elements to one)
                    return true;
                pq.pop();
                sum -= num;
                num %= sum;
                if (num ==0 || num == temp)	//if there is no effect of modulus on num then need to return false as this element can't be converted to one
                    return false;
                pq.push(num);
                sum += num;
            }
            return true;
        }
};