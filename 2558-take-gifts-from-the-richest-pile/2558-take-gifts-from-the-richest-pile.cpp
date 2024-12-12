class Solution {
public:
    
//     Runtime: 3 ms, faster than 54.53% of C++ online submissions for Take Gifts From the Richest Pile.
// Memory Usage: 13 MB, less than 78.35% of C++ online submissions for Take Gifts From the Richest Pile.
    
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        
        // sort(gifts.begin(), gifts.end());
        
        // long long ans = 0;
        // for(int i = 0; i < n && k > 0; i++)
        // {
        //     ans += log(gifts[i]);
        //     k--;
        // }
        // return ans;
        
        priority_queue<int,vector<int>> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push(gifts[i]);
        }
        
        while(k-- && pq.size())
        {
            int a = pq.top();
                        // cout << a << " ";

            pq.pop();
            // int b = log(a);
            int  b= sqrt(a);
            pq.push(b);
        }
        // cout << endl;
        long long sum = 0;
        while(!pq.empty())
        {
            // cout << pq.top() << " ";
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};