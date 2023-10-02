class Solution {
public:

     bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0, b = 0;
        for(int i = 1; i < n-1; i++)
        {
            if(colors[i] == colors[i-1] && colors[i] == colors[i+1])
            {
                if(colors[i] == 'A')
                    a++;
                else 
                    b++;
            }
        }
        return a > b;
    }
};
    
//     Runtime: 41 ms, faster than 8.04% of C++ online submissions for Remove Colored Pieces if Both Neighbors are the Same Color.
// Memory Usage: 13.6 MB, less than 17.42% of C++ online submissions for Remove Colored Pieces if Both Neighbors are the Same Color.

    
//     bool winnerOfGame(string colors) {
//         int n = colors.size();
//         int a = 0, b = 0;
//         for(int i = 1; i < n-1; i++)
//         {
//             if(colors[i] == 'A' && colors[i-1] == colors[i] && colors[i+1] == colors[i])
//                 a++;
//             else if(colors[i] == 'B' && colors[i-1] == colors[i] && colors[i+1] == colors[i])
//                 b++;
//         }
//         return a > b;
//     }
// };