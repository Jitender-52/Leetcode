class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int a = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                swap(v[i], v[a]);
                a++;
            }
        }

        for (int i = a; i < n; i++)
        {
            if (v[i] == 1)
            {
                swap(v[i], v[a]);
                a++;
            }
        }
    }
};