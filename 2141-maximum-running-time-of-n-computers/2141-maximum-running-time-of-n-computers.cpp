class Solution {
public:
    
        long long maxRunTime(int n, vector<int>& batteries) {
            long long sum = 0;
            for(auto i : batteries)
                sum += i;
            long long left = 0, right = sum / n;
            while(left <= right)
            {
                long long mid = (left + right) / 2;
                sum = 0;
                for(auto i : batteries)
                    sum += min(1LL * i, mid);
                if(sum >= mid * n)
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
            return left - 1;
        }
};
    
    
    
    
    // clean code
    
//     Runtime: 2880 ms, faster than 5.40% of C++ online submissions for Maximum Running Time of N Computers.
// Memory Usage: 351.4 MB, less than 6.83% of C++ online submissions for Maximum Running Time of N Computers.
    
//     bool isFeasible(long long mid, int n, vector<int> v)
//     {
//         int m = v.size();
//         vector<long long> batteries(m);
        
//         for(int i = 0; i < m; i++)
//         {
//             batteries[i] = v[i];
//         }
        
//         sort(batteries.begin(), batteries.end());
//         for(int j = n; j < m; j++)
//         {
//             batteries[j] = min(batteries[j], mid);
//         }

//         long long i = 0, j = m-1;
//         while(i < n && j >= n)
//         {
//             if(batteries[i] >= mid)
//                 break;
//             while(i < n && j >= n && batteries[i] < mid)
//             {
//                 long long a = mid - batteries[i];
//                 if(a <= batteries[j])
//                 {
//                     batteries[i] = mid;
//                     batteries[j] -= a;
//                     i++;
//                 }
//                 else
//                 {
//                     batteries[i] += batteries[j];
//                     j--;
//                 }
//             }
//         }

//         bool check = true;
//         for(int i = 0; i < n; i++)
//         {
//             if(batteries[i] < mid)
//                 check = false;
//         }
//         return check;
//     }
    
//     long long maxRunTime(int n, vector<int>& batteries) {
//         long long l = 0, r = 1e15;
        
//         while(l <= r)
//         {
//             long long mid = (l + r) / 2;
//             if(isFeasible(mid, n, batteries))
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }
//         return l - 1;
//     }
// };
    
    
    
    
//     Runtime: 2902 ms, faster than 5.40% of C++ online submissions for Maximum Running Time of N Computers.
// Memory Usage: 351.3 MB, less than 6.83% of C++ online submissions for Maximum Running Time of N
    
//     bool isFeasible(long long mid, int n, vector<int> v)
//     {
//         int m = v.size();
//         vector<long long> batteries(m);
        
//         for(int i = 0; i < m; i++)
//         {
//             batteries[i] = v[i];
//             // cout << batteries[i] << " ";
//         }
        
//         sort(batteries.begin(), batteries.end());
//         for(int j = n; j < m; j++)
//         {
//             batteries[j] = min(batteries[j], mid);
//             // cout << batteries[j] << " ";
//         }
//         // cout << "HII" << endl;
//         // for(int i = 0; i < m; i++)
//         // {
//         //     cout << batteries[i] << " ";
//         // }
//         // cout << endl;
        
//         long long i = 0, j = m-1;
//         while(i < n && j >= n)
//         {
//             // if(batteries[i] >= mid)
//             //     break;
//             bool check = true;
//             while(i < n && j >= n && batteries[i] < mid)
//             {
//                 check = false;
//                 // cout << i << " " << j << endl;
//                 long long a = mid - batteries[i];
//                 if(a <= batteries[j])
//                 {
//                     batteries[i] = mid;
//                     batteries[j] -= a;
//                     i++;
//                 }
//                 else
//                 {
//                     batteries[i] += batteries[j];
//                     j--;
//                 }
//             }
//             if(check)
//                 i++;
//         }
//         // cout << "BYE" << endl;
//         // cout << batteries[n-1] << " " << mid << endl;
//         // for(int i = 0; i < m; i++)
//         // {
//         //     cout << batteries[i] << " ";
//         // }
//         // cout << endl;
//         bool check = true;
//         for(int i = 0; i < n; i++)
//         {
//             if(batteries[i] < mid)
//                 check = false;
//         }
//         return check;
//     }
    
//     long long maxRunTime(int n, vector<int>& batteries) {
//         long long l = 0, r = 1e15;
        
//         while(l <= r)
//         {
//             long long mid = (l + r) / 2;
//             // cout << mid << endl;
//             if(isFeasible(mid, n, batteries))
//             {
//                 l = mid + 1;
//             }
//             else
//             {
//                 r = mid - 1;
//             }
//         }
//         return l - 1;
//     }
// };