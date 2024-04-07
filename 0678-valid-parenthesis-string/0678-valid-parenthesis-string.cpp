class Solution {
public:
    
    bool checkValidString(string s) {
        int count1 = 0, count2 = 0;
        for(auto &i : s)
        {
            if(i == '(')
            {
                count1++;
                count2++;
            }
            else if(i == ')')
            {
                count1--;
                count2--;
            }
            else
            {
                count1--;
                count2++;
            }
            if(count2 < 0)
                return false;
            count1 = max(count1, 0);
        }
        return count1 == 0;
    }
};
    
    
//     bool checkValidString(string s) {
//         int count1 = 0, count2 = 0;
//         for(auto &i : s)
//         {
//             if(i == '(')
//             {
//                 count1++;
//             }
//             else if(i == ')')
//             {
//                 count1--;
//             }
//             else
//             {
//                 count2++;
//             }
//             if(count1 < 0)
//             {
//                 if(count2 >= 1)
//                 {
//                     count1 = 0;
//                     count2--;
//                 }
//                 else
//                     return false;
//             }
//         }
//         return count1 - count2 <= 0;
//     }
// };