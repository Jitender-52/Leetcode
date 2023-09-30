class Solution {
public:
    
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 1; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        int mini = nums[0];
        for(int i = 1; i < n-1; i++)
        {            
            auto it = mp.lower_bound(nums[i]);
            if(it != mp.begin())
            {
                it--;
                // if(mini < nums[i] && nums[i] > mp.begin()->first && it->first > mini)
                if(mini < it->first && it->first < nums[i])
                    return true;
            }            
            // if(mini < nums[i] && nums[i] > mp.begin()->first)
            //     return true;
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
            mini = min(mini, nums[i]);
        }
        return false;
    }
};

    
//         bool find132pattern(vector<int>& nums) {
//             int n = nums.size();
//             vector<int> suffix(n), prefix(n);
//             prefix[0] = v[0];
//             suffix[n-1] = v[n-1];
//             for(int i = 1; i < n; i++)
//             {
//                 prefix[i] = min(prefix[i-1], nums[i]);
//             }
            
//             for(int i = n-2; i >= 0; i--)
//             {
//                 suffix[i] = max(suffix[i+1], nums[i]);
//             }
            
//             for(int i = 0; i )
    
//         }
// };
    
    
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int> left, right;
        
//         for(int i = 0; i < n; i++)
//         {
//             right[nums[i]]++;
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             right[nums[i]]--;
//             if(right[nums[i]] == 0)
//                 right.erase(nums[i]);
//             auto it = right.lower_bound(nums[i]);
//             if(it == right.begin())
//             {
//                 left[nums[i]]++;
//                 continue;
//             }
//             it--;
//             if(it == right.begin())
//             {
//                 left[nums[i]]++;
//                 continue;
//             }
            
//             int x = it->first;
//             it = left.lower_bound(x);
//             if(it == left.begin())
//             {
//                 left[nums[i]]++;
//                 continue;
//             }
//             it--;
//             if(it == left.begin())
//             {
//                 left[nums[i]]++;
//                 continue;
//             }
//             return true;
//         }
//         return false;
//     }
// };


    
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int> mp1, mp2;
//         for(int i = 0; i < n; i++)
//         {
//             mp2[nums[i]]++;
//         }
//         mp2[INT_MAX]++;
//         mp2[INT_MIN]++;
//         for(int i = 0; i < n; i++)
//         {
//             mp2[nums[i]]--;
//             if(mp2[nums[i]] == 0)
//                 mp2.erase(nums[i]);
//             auto it = mp2.lower_bound(nums[i]);
//             it--;
            
//             auto it2 = mp1.begin();
//             mp1[nums[i]]++;
            
//             int a = it2->first;
//             int b = nums[i];
//             int c = it->first;
//             if(it2->first != INT_MIN && it->first != INT_MIN && c > a && c < b && a < b)
//             {
//                 return true;    
//             }
//         }
//         return false;
//     }
// };
    
    
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         int a = INT_MAX;
//         int b = INT_MIN;
//         // int c = INT_MIN;
//         // cout << 1 << endl;
//         map<int,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[nums[i]]++;
//         }
//         mp[INT_MAX]++;
//         mp[INT_MIN]++;
        
//         int x = INT_MAX;
//         for(int i = 0; i < n; i++)
//         {
//             mp[nums[i]]--;
//             if(mp[nums[i]] == 0)
//                 mp.erase(nums[i]);
            
//             if(nums[i] > b)
//             {
//                 b = max(b, nums[i]);
//                 a = min(a, x);
//                 x = INT_MAX;
//             }
            
//             auto it = mp.lower_bound(b);
//             it--;
           
//             int c = it->first;
            
//             if(a != INT_MAX && c > a && c < b && a < b)
//             {
//                 // cout << a << " " << b << " " << c << endl;
//                 return true;
//             }
//             x = min(x, nums[i]);
//         }
        
//         return false;
        
//         // for(int i = 0; i < n; i++)
//         // {
//         //     if(nums[i] > b)
//         //     {
//         //         a = c;
//         //         c = b;
//         //         b = nums[i];
//         //     }
//         //     else if(nums[i] > c)
//         //     {
//         //         a = c;
//         //         c = nums[i];
//         //     }
//         //     else if(nums[i] > a) 
//         //     {
//         //         nums[i] = a;
//         //     }
//         // } 
//         // cout << a << " " << b << " " << c << endl;
//         // if(b > a && b > c && c > a)
//         //     return 1;
//         // return 0;
//     }
// };