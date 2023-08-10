class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > nums[high])
            {
                if(target < nums[mid] && target >= nums[low]) // Take mid = 8 and target = 7 to write the condition
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[mid] < nums[high])
            {
               if(target > nums[mid] && target <= nums[high]) // Take mid = 0 && target = 3 to write this condition
                   low = mid + 1;
                else
                     high = mid - 1;
            }
            else  // when nums[mid] == nums[high] cannot decide so high--;
            {
                high--;
            }
        }
        return false;
    }
};
    
// 6 7 8 9 0 1 2 3 4 5 // Test Case used to write the code and the conditions in binary search

    
//         bool search(vector<int>& nums, int target) {
//             int n = nums.size();
//             if(nums[0] == target || nums[n-1] == target)
//                 return true;
//             if(n <= 2)
//                 return false;
            
//             int left = 1, right = n-2, pivot = 0;
            
//             // while(left <= right)
//             // {
//             //     int mid = (left + right) / 2;
//             //     if(nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid])
//             //     {
//             //         pivot = mid;
//             //         break;
//             //     }
//             //     if(nums[mid] > nums[0])
//             //         left = mid + 1;
//             //     else
//             //         right = mid - 1;
//             // }
            
//             while(left <= right)
//             {
//                 while(left < right && nums[left] == nums[right])
//                 {
//                     left++;
//                     right--;
//                 }
//                 int mid = (left + right) / 2;
//                 if(nums[mid] > nums[mid + 1])
//                 {
//                     pivot = mid + 1;
//                     break;
//                 }
//                 if(nums[mid] < nums[mid - 1])
//                 {
//                     pivot = mid;
//                     break;
//                 }

//                 if(nums[mid] > nums[0])
//                     left = mid + 1;
//                 else
//                      right = mid - 1;
//             }
            
//             cout << pivot << endl;
            
//             if(target >= nums[0] && target > nums[n-1])
//             {
//                 left = 0;
//                 right = pivot;
//             }
//             else
//             {
//                 left = pivot;
//                 right = n-1;
//             }
            
            
//         while(left <= right)
//         {
//             int mid = (left + right) / 2;
//             if(nums[mid] < target)
//                 left = mid + 1;
//             else if(nums[mid] > target)
//                 right = mid - 1;
//             else
//                 return true;
//         }
//         return false;   
//     }
// };
    
    
    
//     bool find(vector<int> &nums, int i, int n, int target)
//     {
//         // int n = nums.size();
//         int low = 0, high = n;
//         while(low <= high)
//         {
//             int mid = (low + high) / 2;
//             if(nums[mid] == target)
//                 return true;
//             if(nums[0] == nums[mid] && nums[0] == nums[n-1])
//             {
//                 cout << low << " " << mid << " " << high << endl;
//                 if(find(nums, mid+1, high, target))
//                     return true;
//                 if(find(nums, low, mid-1, target))
//                     return true;
//                 return false;
//             }
//             else
//             {
//                 if(nums[mid] < target && target <= nums[n-1])
//                     low = mid + 1;
//                 else
//                     high = mid - 1;
//             }
//         }
//         return false;
//     }
    
//     bool search(vector<int>& nums, int target) {
//         // cout << endl;
//         int n = nums.size();
//         // return find(nums, 0, n-1, target);
//         int low = 0, high = n-1;
//         while(low <= high)
//         {
//             int mid = (low + high) / 2;
//             if(nums[mid] == target || nums[low] == target || nums[high] == target)
//                 return true;
//             // if(nums[0] == nums[mid] && nums[0] == nums[n-1])
//             // {
//             //     while(low <= high && nums[low] == nums[mid])
//             //         low++;
//             //     while(high >= low && nums[high] == nums[mid])
//             //         high--;
//             //     // low++;
//             //     // high--;
//             // }
            
//             while(low <= high && nums[low] == nums[high])
//             {
//                 low++;
//                 high--;
//             }
            
//             if(low > high)
//                 break;
//             mid = (low + high) / 2;
//             // cout << low << " " << mid << " " << high << endl;
//             if(nums[mid] == target || nums[low] == target || nums[high] == target)
//                 return true;
//             // if(nums[mid] < target && target <= nums[n-1])
//             //     low = mid + 1;
//             // if(nums[mid] > target)
//             //     low = mid + 1;
//             // else
//             //     high = mid - 1;
            
//             if(nums[mid] >= target && nums[0] >= target)
//                 low = mid + 1;
//             else
//                 high = mid - 1;
            
//         }
//         return false;
//     }
// };

// [2,5,6,0,0,1,2]
// 0
// [2,5,6,0,0,1,2]
// 3
// [1,0,1,1,1]
// 0
// [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
// 2
// [1]
// 0
// [3,1]
// 1
// [4,5,6,7,0,1,2]
// 0

