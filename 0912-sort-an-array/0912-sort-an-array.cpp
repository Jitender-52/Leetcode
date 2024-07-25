class Solution {
public:
    
    void merge(vector<int> &nums, int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        
        vector<int> a(n1);
        vector<int> b(n2);
        for (int i = 0; i < n1; i++)
            a[i] = nums[l + i];
        for (int i = 0; i < n2; i++)
            b[i] = nums[m + i + 1];

        int i = 0;
        int j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (a[i] < b[j])
            {
                nums[k] = a[i];
                k++;
                i++;
            }
            else
            {
                nums[k] = b[j];
                k++;
                j++;
            }
        }
        while (i < n1)
        {
            nums[k] = a[i];
            k++;
            i++;
        }
        while (j < n2)
        {
            nums[k] = b[j];
            k++;
            j++;
        }
    }
    
    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int m = ((l + r) / 2);
            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);
            merge(nums, l, m, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};


//     vector<int> sortArray(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[nums[i]]++;
//         }
//         int j = 0;
//         for(auto i : mp)
//         {
//             for(auto k = 0; k < i.second; k++)
//             {
//                 nums[j] = i.first;
//                 j++;
//             }
//         }
//         return nums;
//     }
// };