class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> st;
        int a = 1;
        for(int i = 0; i <= 20; i++)
        {
            int b = 1;
            if(a > bound)
                break;
            for(int j = 0; j <= 20; j++) // mybad using i++ here instead of j++;
            {
                if(a + b <= bound)
                    st.insert(a + b);
                else
                    break;
                b *= y;
            }
            a *= x;
        }
        vector<int> ans;
        for(auto i : st)
            ans.push_back(i);
        return ans;
    }
};