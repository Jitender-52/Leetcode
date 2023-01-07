class Solution {
public:
    
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = cost.size();
            vector<int> v(n);
            for(int i = 0; i < n; i++)
            {
                v[i] = gas[i] - cost[i];
            }
            
            int idx = -1;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                // sum--;
                if(idx == -1 && v[i] >= 0)
                {
                    idx = i;
                    sum = 0;
                }
                sum += v[i];
                if(sum < 0)
                {
                    idx = -1;
                }
            }
            
            // cout << idx << endl;
            for(int i = 0; i <= idx; i++)
            {
                // sum--;
                if(sum < 0)
                {
                    // cout << i << endl;
                    return -1;
                }
                sum += v[i];
            }
            return idx;
        }
};
    
    
//         int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//             int n = gas.size();
//             int idx = -1;
            
//             int sum = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 sum--;
//                 if(sum < 0)
//                 {
//                     idx = -1;
//                     sum = 0;
//                 }
//                 if(gas[i] > cost[i] && idx == -1)
//                 {
//                     idx = i;
//                     sum = 0;
//                 }
//                 sum += gas[i];
//                 if(i != idx)
//                     sum -= cost[i];
//                 cout << idx << " " << sum << endl;
//             }
//             if(idx == -1)
//                 return idx;
            
//             for(int i = 0; i < n; i++)
//             {
//                 sum--;
//                 if(sum <= 0)
//                     return -1;
//                 sum += gas[i] - cost[i];
//                 cout << i << " " <<  sum << endl;
//                 if(sum <= 0)
//                     return -1;
//                 if(i == idx)
//                     return idx;
//             }
//             return -1;
//         }
// };
    
    
    
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//        if(n == 1 )
//     {
//         if(gas[0] >= cost[0])
//         {
//         return 0;
//         }
//         else
//         {
//             return -1;
//         }
//     }
        
//     int gas_sum = 0;
//     int cost_sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         gas_sum += gas[i];
//         cost_sum += cost[i];
//     }

//     if (cost_sum > gas_sum)
//     {
//         return -1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (gas[i] > cost[i])
//         {
//             // int start = gas[i] - cost[i];
//             int start = 0;
//             int j = i;
//             int k = 0;
//             int check = 0;
//             while (k <= n)
//             {
//                 start += gas[j] - cost[j];
//                 if (start < 0)
//                 {
//                     // cout << "Break = " << j << endl;
//                     break;
//                 }
//                 if (j == i && check == 1)
//                 {
//                     // cout << n << endl;
//                     return i;
//                 }
//                 if(j == 1)
//                 {
//                     check++;
//                 }
//                 j++;
//                 k++;
//                 if (j == n)
//                 {
//                     // cout << "HII = " << i << endl;
//                     j = 0;
//                 }
//             }
//         }
//     }
//     return -1;
//     }
// };