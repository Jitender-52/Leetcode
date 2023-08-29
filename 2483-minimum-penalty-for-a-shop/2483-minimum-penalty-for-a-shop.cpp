class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        int ans = 0, mini = 0;
        int count = 0;
        for(int i = 0; i < n;i++)
        {
            if(customers[i] == 'Y')
                count--;
            else
                count++;
            if(count < mini)
            {
                ans = i+1;
                mini = count;
                
            }
        }
        return ans;
    }
};