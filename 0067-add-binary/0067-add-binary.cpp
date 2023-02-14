class Solution {
public:

//     Runtime: 2 ms, faster than 73.96% of C++ online submissions for Add Binary.
// Memory Usage: 6.4 MB, less than 61.65% of C++ online submissions for Add Binary.
    
    
//      string addBinary(string a, string b) {
//          int i = a.size() - 1;
//     int j = b.length() - 1;
//     string ans = "";
//     int carry = 0;

//     while (i >= 0 || j >= 0 || carry)
//     {
//         if (i >= 0)
//         {
//             carry += a[i] - '0';
//             i--;
//         }
//         if (j >= 0)
//         {
//             carry += b[j] - '0';
//             j--;
//         }

//         ans += (carry % 2) + '0';
//         carry = carry / 2;
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
//     }
// };
    

    string addBinary(string a, string b) {
        int n = a.size();
    int m = b.size();
    int c = max(n, m) + 1;
    int i = n - 1;
    int j = m - 1;

    // char x = 'a';
    string ans(c, 'a');
    c--;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = (a[i] - '0') + (b[j] - '0') + carry;
        // cout << "sum = " << sum << endl;
        // cout << c << endl;
        // return "";

        if (sum == 3)
        {
            ans[c] = '1';
            carry = 1;
        }
        else if (sum == 2)
        {
            ans[c] = '0';
            carry = 1;
        }
        else if (sum == 1)
        {
            ans[c] = '1';
            carry = 0;
        }
        else if (sum == 0)
        {
            ans[c] = '0';
            carry = 0;
        }
        // cout << ans[c-1] << endl;
        c--;
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = a[i] - '0' + carry;
        if (sum == 2)
        {
            ans[c] = '0';
            carry = 1;
        }
        else if (sum == 1)
        {
            ans[c] = '1';
            carry = 0;
        }
        else if (sum == 0)
        {
            ans[c] = '0';
            carry = 0;
        }
        // cout << ans[c] << endl;
        i--;
        c--;
    }
    while (j >= 0)
    {
        int sum = b[j] - '0' + carry;
        if (sum == 2)
        {
            ans[c] = '0';
            carry = 1;
        }
        else if (sum == 1)
        {
            ans[c] = '1';
            carry = 0;
        }
        else if (sum == 0)
        {
            ans[c] = '0';
            carry = 0;
        }
        j--;
        c--;
    }
    // cout << "c = " << c << endl;
    // cout << ans[0] << endl;
    if (carry == 1)
    {
        ans[c] = '1';
        return ans;
    }
    return ans.substr(1);
    }
};