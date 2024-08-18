class Solution {
public:
    
//     Runtime: 101 ms, faster than 9.82% of C++ online submissions for Ugly Number II.
// Memory Usage: 35.6 MB, less than 7.76% of C++ online submissions for Ugly Number II.
    
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        vector<int> v = {2, 3, 5};
        set<int> st;
        while(1)
        {
            n--;
            if(n == 0)
                return pq.top();
            for(auto i : v)
            {
                if(st.find(i * pq.top()) == st.end())
                {
                    pq.push(i * pq.top());
                    st.insert(i * pq.top());
                }
            }
            pq.pop();
        }
        return pq.top();
    }
};