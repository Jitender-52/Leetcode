class Solution {
public:
    
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        
        int x = arr[0], count = 0;
        for(int i = 1; i < arr.size(); i++)
        {
            if(x > arr[i])
                count++;
            else
            {
                x =  arr[i];
                count = 1;
            }
            if(x == maxi || count >= k)
                return x;
        }
        return -1;
    }
};
    
//     Runtime: 91 ms, faster than 44.44% of C++ online submissions for Find the Winner of an Array Game.
// Memory Usage: 69 MB, less than 13.89% of C++ online submissions for Find the Winner of an Array Game.
    
//     Runtime: 97 ms, faster than 28.24% of C++ online submissions for Find the Winner of an Array Game.
// Memory Usage: 68.9 MB, less than 14.35% of C++ online submissions for Find the Winner of an Array Game.
    
//     int getWinner(vector<int>& arr, int k) {
//         int n = arr.size();
//         if(k >= n)
//             return *max_element(arr.begin(), arr.end());
//         queue<int> q;
//         for(int i = 0; i < n; i++)
//         {
//             q.push(arr[i]);
//         }
        
//         int maxi = arr[0], count = 0;
//         q.pop();
//         while(1)
//         {
//             int a = q.front();
//             q.pop();
//             if(a > maxi)
//             {
//                 q.push(maxi);
//                 maxi = a;
//                 count = 1;
//             }
//             else
//             {
//                 q.push(a);
//                 count++;
//             }
//             if(count >= k)
//                 return maxi;
//         }
//         return arr[n-1];
//     }
// };