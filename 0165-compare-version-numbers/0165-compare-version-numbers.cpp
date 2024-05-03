class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Compare Version Numbers.
// Memory Usage: 7.7 MB, less than 27.22% of C++ online submissions for Compare Version Numbers.
    
    bool isRight(string &s, int index)
    {
        int n = s.length();
        for (int i = index; i < n; i++)
        {
            if (s[i] == '.')
                continue;

            if (s[i] != '0')
                return true;
        }
        return false;
    }

    int compareVersion(string version1, string version2)
    {

        int i = 0;
        int j = 0;
        int n = version1.length();
        int m = version2.length();
        string a1 = "";
        string a2 = "";
        while (i < n && j < m)
        {
            while (version1[i] != '.' && i < n)
            {
                a1 += version1[i];
                i++;
            }

            while (version2[j] != '.' && j < m)
            {
                a2 += version2[j];
                j++;
            }
            i++;
            j++;
            int b1 = stoi(a1);
            int b2 = stoi(a2);
            a1.clear();
            a2.clear();
            if (b1 < b2)
                return -1;
            else if (b1 > b2)
                return 1;
        }
        if (i < n)
        {
            if (isRight(version1, i))
            {
                return 1;
            }
        }
        if (j < m)
        {
            if (isRight(version2, j))
            {
                return -1;
            }
        }

        return 0;
    }
};