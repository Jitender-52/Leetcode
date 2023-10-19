class Solution {
public:

    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> st;
        int a = 1;
        while(a < bound)
        {
            int b = 1;
            while(a + b <= bound)
            {
                st.insert(a + b);
                if(y == 1)
                    break;
                b *= y;
            }
            if(x == 1)
                break;
            a *= x;
        }
        vector<int> ans;
        for(auto i : st)
            ans.push_back(i);
        return ans;
    }
};
    
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Powerful Integers.
// Memory Usage: 6.9 MB, less than 63.76% of C++ online submissions for Powerful Integers.
    
//     vector<int> powerfulIntegers(int x, int y, int bound) {
//         set<int> st;
//         int a = 1;
//         for(int i = 0; i <= 20; i++)
//         {
//             int b = 1;
//             if(a > bound)
//                 break;
//             for(int j = 0; j <= 20; j++) // mybad using i++ here instead of j++;
//             {
//                 if(a + b <= bound)
//                     st.insert(a + b);
//                 else
//                     break;
//                 b *= y;
//             }
//             a *= x;
//         }
//         vector<int> ans;
//         for(auto i : st)
//             ans.push_back(i);
//         return ans;
//     }
// };