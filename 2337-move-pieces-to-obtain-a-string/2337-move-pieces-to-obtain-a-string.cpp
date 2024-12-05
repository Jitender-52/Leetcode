class Solution {
public:
    
//     Runtime: 35 ms, faster than 22.41% of C++ online submissions for Move Pieces to Obtain a String.
// Memory Usage: 37.8 MB, less than 8.11% of C++ online submissions for Move Pieces to Obtain a String.
    
    bool canChange(string start, string target) {
        queue<pair<char, int>> startQueue, targetQueue;

        for (int i = 0; i < start.size(); i++) 
        {
            if (start[i] != '_') 
                startQueue.push({start[i], i});
            if (target[i] != '_') 
                targetQueue.push({target[i], i});
        }

        if (startQueue.size() != targetQueue.size()) 
            return false;

        while (!startQueue.empty()) 
        {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            if (startChar != targetChar || (startChar == 'L' && startIndex < targetIndex) || (startChar == 'R' && startIndex > targetIndex))
                return false;
        }
        return true;
    }
};