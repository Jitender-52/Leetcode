class Solution {
public:
    
//     Runtime: 11 ms, faster than 43.49% of C++ online submissions for Make Two Arrays Equal by Reversing Subarrays.
// Memory Usage: 21.1 MB, less than 6.79% of C++ online submissions for Make Two Arrays Equal by Reversing Subarrays.
    
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp1, mp2;
        for(auto i : target)
            mp1[i]++;
        for(auto i : arr)
            mp2[i]++;
        for(auto i : mp1)
        {
            if(mp2[i.first] != i.second)
                return false;
        }
        return true;
    }
};