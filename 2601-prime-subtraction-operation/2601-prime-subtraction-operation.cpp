class Solution {
public:
    
//     Runtime: 36 ms, faster than 10.88% of C++ online submissions for Prime Subtraction Operation.
// Memory Usage: 36.7 MB, less than 6.71% of C++ online submissions for Prime Subtraction Operation.
    
    bool isPrime(int n)
    {
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i== 0)
            {
                return false;
            }
        }
        return true;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
//         int j = 0;
        
//         vector<map<int,int>> v;
        
//         for(int i = 0; i < n; i++)
//         {
            
//         }
        
        map<int,int> mp;
        // vector<int> v;
        for(int i = 2; i <= 1000; i++)
        {
            if(isPrime(i))
            {
                // v.push_back(i);
                mp[i]++;
            }
        }
        
        mp[0]++;
        int prev = 0;
        for(int i = 0; i < n; i++)
        {
            auto it = mp.lower_bound(nums[i]);
            it--;
            if(i == 0 && nums[i] == 1)
            {
                continue;
            }
            // if(it != 0)
            // {
            //     nums[i] -= it->first;
            // }
            // cout << it->first << endl;
            
            while(it!= mp.begin() && (nums[i] - it->first <= prev))
            {
                it--;
            }
            // cout << nums[i]  << " " <<  it->first << endl;
            // if(it == mp.begin())
            // {
            //     // cout << endl;
            //     return false;
            // }
            if(i > 0 && nums[i] <= nums[i-1])
                return false;
            nums[i] -= it->first;
            prev = nums[i];
        }
        
        // for(int i = 0; i < n; i++)
        // {
        //     cout << nums[i] <<" ";
        // }
        // cout << endl;
        return true;
        
        // for(int i = 0; i < n; i++)
        // {
        //     int j = 0;
        //     while(!isPrime(nums[i] - j))
        //     {
        //         if(nums[i]-j == 1)
        //         {
        //             cout << i << endl;
        //             return false;
        //         }
        //         j++;
        //     }
        //     nums[i] -= j;
        //     cout << nums[i] <<  " ";
        //     if(i > 0 && nums[i] <= nums[i-1])
        //     {
        //         cout << endl;
        //         cout << i << endl;
        //         return false;
        //     }
        // }
        return true;
    }
};