class Solution
{
    public:
        int threeSumMulti(vector<int> &arr, int target)
        {
            sort(arr.begin(), arr.end());
            int n = arr.size();
            long long ans = 0, mod = 1e9 + 7;
            for (int i = 0; i < n; i++)
            {
                int j = i + 1, k = n - 1;
                int sum = target - arr[i];
                long long cnt1, cnt2;
                while (j < k)
                {
                    if (arr[j] + arr[k] < sum)
                        j++;
                    else if (arr[j] + arr[k] > sum)
                        k--;
                    else
                    {
                        cnt1 = cnt2 = 1;
                        if (arr[j] == arr[k])
                        {

                            while (j < k && arr[j] == arr[k])
                            {
                                cnt1++;
                                j++;
                            }
                            ans += (cnt1 *(cnt1 - 1)) / 2;
                        }
                        else
                        {
                            while (j < k && arr[j] == arr[j + 1])
                            {
                                j++;
                                cnt1++;
                            }
                            while (j < k && arr[k] == arr[k - 1])
                            {
                                cnt2++;
                                k--;
                            }
                            ans += (cnt1 *cnt2);
                        }
                        j++;
                        k--;
                    }
                }
            }
            return ans % mod;
        }
};