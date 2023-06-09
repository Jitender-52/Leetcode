class Solution {
public:
    
//     Runtime: 11 ms, faster than 94.29% of C++ online submissions for Find Smallest Letter Greater Than Target.
// Memory Usage: 15.9 MB, less than 32.10% of C++ online submissions for Find Smallest Letter Greater Than Target.
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size(), l = 0, r = n-1;
        while(l <= r)
        {
            int mid = ((l + r) / 2);
            if(letters[mid] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l >= n ? letters[0] : letters[l];
    }
};