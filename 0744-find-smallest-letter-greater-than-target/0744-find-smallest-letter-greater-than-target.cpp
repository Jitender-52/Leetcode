class Solution {
public:
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