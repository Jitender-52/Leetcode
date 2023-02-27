class Solution {
public:
    
    string add(string ans, string s)
    {
        reverse(ans.begin(), ans.end());
        int n = ans.length();
        int m = s.length();
        
        string x = "";
        int i = 0;
        int j = 0;
        int carry = 0;
        while(i < n && j < m)
        {
            int a = (ans[i] - '0') + (s[j] - '0') + carry; 
            x += to_string(a % 10);
            carry = a / 10;
            i++;
            j++;
        }
        while(i < n)
        {
            int a = (ans[i] - '0') + carry;
            x += to_string(a % 10);
            carry = a / 10;
            i++;
        }
        while(j < m)
        {
            int a = (s[j] - '0') + carry;
            x += to_string(a % 10);
            carry = a / 10;
            j++;
        }
        if(carry > 0)
        {
            x += to_string(carry);
        }
        reverse(x.begin(), x.end());
        return x;
    }
    
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        
        int k = 0;
        string ans = "";
        for(int i = 0; i < m; i++)
        {
            string s = "";
            for(int j = 0; j < k; j++)
            {
                s += "0";
            }
            int carry = 0;
            int x = (num2[m-k-1] - '0');
            for(int j = n-1; j >= 0; j--)
            {
                int y = (num1[j] - '0');
                int a = x * y + carry;
                s += to_string(a % 10);
                carry = a / 10;
            }
            while(carry > 0)
            {
                s += to_string(carry % 10);
                carry /= 10;
            }
            ans = add(ans, s);
            k++;
        }
        // cout << ans << endl;
        
        // for(int i = 0; i < ans.length()-1; i++)
        // {
        //     while(ans[0] == '0')
        //     {
        //         ans = ans.substr(1, ans.length() - 1);
        //     }
        // }
        
        string s = "";
        int i = 0;
        while(i < ans.length() && ans[i] == '0')
        {
            i++;
        }
        
        while(i < ans.length())
        {
            s += ans[i];
            i++;
        }
        if(s.length() == 0)
        {
            s += '0';
        }
        
        return s;
    }
};