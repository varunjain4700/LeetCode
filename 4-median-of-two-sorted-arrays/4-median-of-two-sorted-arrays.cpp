class Solution
{
    public:
       	//Main observations: need to partition the arrays into 2 equal halves as need to find the median,try every cut as partition as long as you are not able to find the desired.
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
            if (nums1.size() > nums2.size())
                return findMedianSortedArrays(nums2, nums1);
           	//applying binary search on smaller array(can't apply on larger as there may be a case that elements go out of bound as we are giving rest of the elements to second one)
            int n1 = nums1.size(), n2 = nums2.size();
            int low = 0, high = n1;
            while (low <= high)
            {
                int cut1 = (low + high) / 2;
                int cut2 = ((n1 + n2 + 1) / 2) - cut1;
               	// cout << cut1 << " " << cut2 << endl;
                int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
                if (cut1 != 0)
                    l1 = nums1[cut1 - 1];
                if (cut2 != 0)
                    l2 = nums2[cut2 - 1];
                if (cut1 != n1)
                    r1 = nums1[cut1];
                if (cut2 != n2)
                    r2 = nums2[cut2];
                if (l1 <= r2 && l2 <= r1)
                {
                   	// cout << l1 << " " << r1 << endl;
                   	// cout << l2 << " " << r2 << endl;
                    if ((n1 + n2) % 2 == 0)
                    {
                        return (double)(max(l1, l2) + min(r1, r2)) / 2;
                    }
                    else
                    {
                        return max(l1, l2);
                    }
                }
                else if (l1 > r2)
                    high = cut1 - 1;
                else
                    low = cut1 + 1;
            }
            return 0.0;
        }
};