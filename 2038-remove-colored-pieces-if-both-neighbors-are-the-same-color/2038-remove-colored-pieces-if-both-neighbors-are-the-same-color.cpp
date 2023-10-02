class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0, b = 0;
        for(int i = 1; i < n-1; i++)
        {
            if(colors[i] == 'A' && colors[i-1] == colors[i] && colors[i+1] == colors[i])
                a++;
            else if(colors[i] == 'B' && colors[i-1] == colors[i] && colors[i+1] == colors[i])
                b++;
        }
        return a > b;
    }
};