class Solution {
public:
    
//     Runtime: 7 ms, faster than 90.57% of C++ online submissions for Remove K Digits.
// Memory Usage: 10.2 MB, less than 26.88% of C++ online submissions for Remove K Digits.
    
     string removeKdigits(string num, int k) {
    if (num.length() == k)
      return "0";

    string ans;
    vector<char> stack;

    for (int i = 0; i < num.length(); ++i) {
      while (k > 0 && !stack.empty() && stack.back() > num[i]) {
        stack.pop_back();
        --k;
      }
      stack.push_back(num[i]);
    }

    while (k-- > 0)
      stack.pop_back();

    for (const char c : stack) {
      if (c == '0' && ans.empty())
        continue;
      ans += c;
    }

    return ans.empty() ? "0" : ans;
  }
};