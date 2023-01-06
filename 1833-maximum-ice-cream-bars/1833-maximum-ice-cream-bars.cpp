class Solution
{
    public:

        int maxIceCream(vector<int> &costs, int coins)
        {
            int n = costs.size();
            map<int, int> mp;
            for (int i = 0; i < n; i++)
            {
                mp[costs[i]]++;
            }
            int ans = 0;
            for (auto i: mp)
            {
                if (i.first > coins)
                    break;
                while (i.second--)
                {
                    if (i.first > coins)
                        break;
                    ans++;
                    coins -= i.first;
                }
                if(i.first > coins)
                    break;
            }
            return ans;
        }
};

//     Runtime: 351 ms, faster than 41.97% of C++ online submissions for Maximum Ice Cream Bars.
// Memory Usage: 76.5 MB, less than 32.82% of C++ online submissions for Maximum Ice Cream Bars.

// int maxIceCream(vector<int> &costs, int coins)
// {
//     int n = costs.size();
//     sort(costs.begin(), costs.end());
//     int ans = 0;
//     int i = 0;
//     while (i < n)
//     {
//         if (costs[i] > coins)
//             break;
//         ans++;
//         coins -= costs[i];
//         i++;
//     }
//     return ans;
// }
// };