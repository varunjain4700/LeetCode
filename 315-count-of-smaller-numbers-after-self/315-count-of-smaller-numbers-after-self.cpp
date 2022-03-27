class Solution
{
    public:
       	//Good problem to test the concept of merge sort and its application

       	//This problem is basically asking us to calculating all the inversion counts
       	//But what is an inversion?
       	//A pair (i,j) is an inversion if a[i]>a[j] && i < j;

       	//One thing that is worth remembering is we are appplying merge sort on array of indexes (instead of original array, we can do that also but this will be easier to implement) as we need to know the original indexes(as elements will be merged and their indexes will not remain same while doing sorting) to keep in account the elements that are smaller to its right.

        void sortArray(vector<int> &nums, vector<int> &index, int low, int high, vector< int > &cnt)
        {
            if (low < high)
            {
                int mid = (low + high) / 2;
                sortArray(nums, index, low, mid, cnt);
                sortArray(nums, index, mid + 1, high, cnt);
                merge(nums, index, low, high, cnt);
            }
        }
    void merge(vector<int> &nums, vector<int> &index, int low, int high, vector< int > &cnt)
    {
        vector<int> res(high-low+1);
        int smallerToRight = 0;
        int mid=(low+high)/2;
        int i = low, j = mid + 1,k=0;
        while (i <= mid && j <= high)
        {
            if (nums[index[j]] < nums[index[i]])
            {
                smallerToRight++;
                res[k]=index[j];
                ++k;
                ++j;
            }
            else
            {
                cnt[index[i]] += smallerToRight;
                res[k]=index[i];
                ++k;
                ++i;
            }
        }
        while (j <= high)
        {
            smallerToRight++;
            res[k]=index[j];
            ++k;
            ++j;
        }
        while (i <= mid)
        {
            cnt[index[i]] += smallerToRight;
            res[k]=index[i];
            ++k;
            ++i;
        }
         k = 0;
        for (int i = low; i <= high; i++)
        {
            index[i] = res[k++];
        }
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> index, cnt(n);
        for (int i = 0; i < n; i++)
            index.push_back(i);
        sortArray(nums, index, 0, n - 1, cnt);
        return cnt;
    }
};