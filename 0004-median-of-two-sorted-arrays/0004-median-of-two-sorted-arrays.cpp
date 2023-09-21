class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, count = 0, a = 0, b = 0;
        if((n + m) % 2 == 1)
        {
            while(1)
            {
                if(j == m || ((i < n) && nums1[i] <= nums2[j]))
                {
                    a = b;
                    b = nums1[i];
                    i++;
                }
                else
                {
                    a = b;
                    b = nums2[j];
                    j++;
                }
                // cout << count << " " << (n + m + 2) / 2 << endl;
                if((count == (n + m) / 2))
                    return b;
                count++;
            }
        }
        else
        {
            while(1)
            {
                if(j == m || ((i < n) && nums1[i] <= nums2[j]))
                {
                    a = b;
                    b = nums1[i];
                    i++;
                }
                else
                {
                    a = b;
                    b = nums2[j];
                    j++;
                }
                if(count == (n + m) / 2)
                    return (double(a + b)) / 2.0;
                count++;
            }
        }
        return -1;
    }
};