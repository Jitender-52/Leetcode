class Solution {
public:
    
    
      int searchInsert(vector<int>& v, int t) {
          int s = 0;
    int e = v.size();

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] > t)
        {
            if (mid == 0)
            {
                return 0;
            }
            else if (v[mid - 1] < t)
            {
                return mid;
            }
            e = mid - 1;
        }
        else if (v[mid] < t)
        {
            if (mid == v.size() - 1)
            {
                return v.size();
            }
            else if (v[mid + 1] > t)
            {
                return mid + 1;
            }
            s = mid + 1;
        }
        else
        {
            return mid;
        }
    }
     return 0;   
    }
};