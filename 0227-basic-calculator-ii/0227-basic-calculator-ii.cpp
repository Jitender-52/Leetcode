class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st1;
        stack<char> st2;
        
        int i = 0;
        string x = "";
        while(i < n && ((s[i] >= '0' && s[i] <= '9') || s[i] == ' '))
        {
            if(s[i] != ' ')
            x += s[i];
            i++;
        }
        st1.push(stoi(x));
        
        while(i < n)
        {
            char c;
            // cout << s[i] << " " << "HII" << endl;
            while(i < n)
            {
                if(s[i] != ' ')
                {
                    c = s[i];
                    i++;
                    break;
                }
                i++;
            }
            if(i == n)
                break;
            x = "";
            while(i < n && ((s[i] >= '0' && s[i] <= '9') || s[i] == ' '))
            {
                if(s[i] != ' ')
                    x += s[i];
                i++;
            }
            // cout << s[i] << " " << "BYE" << endl;
            int a = stoi(x);
            // cout << st1.top() << c << a << endl;
            if(c == '*')
            {
                int b = st1.top();
                st1.pop();
                a = b * a;
                // cout << b << endl;
            }
            else if(c == '/')
            {
                int b = st1.top();
                st1.pop();
                a = b / a;
                // cout << b << endl;
            }
            else
            {
                // cout << "HII" << endl;
                st2.push(c);
            }
            // cout << a << endl;
            st1.push(a);
        }
        // return 0;
        // cout << st1.size() << " " << st2.size() << endl;
        
        stack<int> st3;
        stack<char> st4;
        while(!st1.empty())
        {
            st3.push(st1.top());
            st1.pop();
        }
        while(!st2.empty())
        {
            st4.push(st2.top());
            st2.pop();
        }
        st1 = st3;
        st2 = st4;
        
        int a = st1.top();
        st1.pop();
        while(!st1.empty() && !st2.empty())
        {
            char c = st2.top();
            st2.pop();
            int b = st1.top();
            st1.pop();
            // cout << a << " " << b << endl;
            if(c == '+')
            {
                a = b + a;   
            }
            else
            {
                a = a - b;
            }
        }
        return a;
    }
};