class Solution {
public:
    
//     Runtime: 62 ms, faster than 61.06% of C++ online submissions for Max Points on a Line.
// Memory Usage: 12.5 MB, less than 66.56% of C++ online submissions for Max Points on a Line.
   
//         int maxPoints(vector<vector<int>> &points){
//             int n = points.size();
//             int ans = 1;
//             for(int i = 0; i < n-1; i++)
//             {
//                 map<double,int> mp;
//                 for(int j = i+1; j < n; j++)
//                 {
//                     if(points[i][0] == points[j][0])
//                     {
//                         mp[1e9]++;
//                     }
//                     else
//                     {
//                         double d = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
//                         mp[d]++;
//                     }
//                     for(auto i : mp)
//                         {
//                             ans = max(ans, i.second + 1);
//                         }
//                 }
//             }
            
//             return ans;
//         }
// };

    
    
//     Whats Wrong with this code with test cases
// [[1,1],[2,2],[3,3]]
// [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// [[0,1],[0,0],[0,4],[0,-2],[0,-1],[0,3],[0,-4]]
// [[0,0],[1,-1],[1,1]]
// [[0,0]]
// [[-6,-1],[3,1],[12,3]] // with this last testcase
    
    
//     Runtime: 242 ms, faster than 19.16% of C++ online submissions for Max Points on a Line.
// Memory Usage: 12.5 MB, less than 70.78% of C++ online submissions for Max Points on a Line.
    
    
    
    // used set precision of 1e-6 in comparing y and mx + c
    
    
   int maxPoints(vector<vector<int>> &points){
        int n = points.size();
        
        set<pair<double,double>> st;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                double m;
                if(x2 - x1 == 0)
                {
                    m = 1e6;
                }
                else
                {
                    m = (double(y2 - y1)) / (x2-x1);
                }
                double c = double(y1) - (m*x1); 
                if(m == 1e6)
                {
                    c = x1;
                }
                st.insert({m, c});
            }
        }
        
        int ans = 1;
        for(auto i : st)
        {
            // cout << i.first << " " << i.second << endl;
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                double x = points[j][0];
                double y = points[j][1];
                double m = i.first;
                double c = i.second;
                if(m == 1e6)
                {
                    if(x == c)
                    {
                        count++;
                    }
                }
                // else if(y == (m*x + c))
                // else if(abs(y - (m*x + c)) <= 1e-6)
                else if(abs(y - (m*x + c)) <= 1e-9)
                {
                    count++;
                }
                ans = max(ans, count);
            }
        }
    return ans;
    }
};


        // Not Working


//  int maxPoints(vector<vector<int>> &points){
//         int n = points.size();
        
//         set<pair<double,double>> st;
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i+1; j < n; j++)
//             {
//                 double x1 = (double)points[i][0];
//                 double y1 = (double)points[i][1];
//                 double x2 = (double)points[j][0];
//                 double y2 = (double)points[j][1];
                
//                 double m;
//                 if(x2 - x1 == 0)
//                 {
//                     m = 1e9;
//                 }
//                 else
//                 {
//                     m = (double(y2 - y1)) / (x2-x1);
//                 }
//                 double c = double(y1) - (m*x1); 
//                 // double c = (x2 * y1 - x1 * y2)/(x2 - y1);
//                 if(m == 1e9)
//                 {
//                     c = x1;
//                 }
//                 st.insert({m, c});
//             }
//         }
        
//         int ans = 1;
//         cout << endl;
//         for(auto i : st)
//         {
//             cout << i.first << " " << i.second << endl;
//             int count = 0;
//             for(int j = 0; j < n; j++)
//             {
//                 double x = (double)points[j][0];
//                 double y = (double)points[j][1];
//                 double m = i.first;
//                 double c = i.second;
//                 if(m == 1e9)
//                 {
//                     if(x == c)
//                     {
//                         count++;
//                     }
//                 }
                
//                 // cout << y << " " << m * x + c << endl;
                
//                 double a = (double)y;
//                 double b = (double)m * (double)x + (double)c;

//                 if(a == b)
//                 // if(abs(a - b) <= 1e-6)
//                 {
//                     cout << a << " and " << b << " are equal" << endl;
//                     count++;
//                 }
//                 else
//                 {
//                     cout << a << " and " << b << " are not equal" << endl; 
//                 }
//             }
//             ans = max(ans, count);
//         }
//     return ans;
//     }
// };


    
    
    
//     double slope(int i, int j, int k, int l)
// {
//     int b = l - j;
//     int c = k - i;
//     double a = double(b) / (c);
//     // if (c == 0)
//     // {
//     //     float d = float(22) / 7;
//     //     return d;
//     //     // if (b > 0)
//     //     // {
//     //     //     // return INT_MAX;
//     //     //     return d;
//     //     // }
//     //     // else
//     //     // {
//     //     //     return -d;
//     //     //     // return INT_MIN;
//     //     // }
//     // }

//     // else if (b < 0 && c < 0)
//     // {
//     //     return a;
//     // }
//     // // else if (b < 0 || c < 0)
//     // // {
//     // //     return -a;
//     // // }
//     // else if (b > 0 && c >> 0)
//     // {
//     //     return a;
//     // }
//     return a;
// }

// int maxPoints(vector<vector<int>> &points)
// {
//     map<double, int> mp;
//     int n = points.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             double a = slope(points[i][0], points[i][1], points[j][0], points[j][1]);
//             // cout << "a = " << a << endl;
//             mp[a]++;
//             // cout << mp[a] << endl;
//         }
//         // int count = 0;
//         // cout << "size = " <<  mp.size() << endl;
//         for (auto i : mp)
//         {
//             // cout << "slope = " << i.first << " " << i.second << endl;
//             ans = max(ans, i.second);
//             // cout << ans << endl;
//         }
//         mp.clear();
//     }
//     return ans + 1;
// }
    
// };