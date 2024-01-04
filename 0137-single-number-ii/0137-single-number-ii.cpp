class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            int setBit = 0;
            for(int j = 0; j < n; j++)
            {
                if((nums[j] & (1 << i)) != 0)
                    setBit++;
            }
            // this means all the setbits at that position get three and +1 more time because of that single nums which(this setbit of that nums is 1 so adding it).
            if(setBit % 3 == 1) 
                ans = ans | (1 << i);
        }
        return ans;
    }
};