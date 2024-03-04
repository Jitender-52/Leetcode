class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n-1, score = 0;
        while(i <= j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i];
                score++;
                i++;
            }
            else if(score > 0)
            {
                power += tokens[j] - tokens[i];
                i++;
                j--;
            }
            else
            {
                break;
            }
        }
        return score;
    }
};