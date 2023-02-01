class Solution {
public:
//     string gcdOfStrings(string str1, string str2) {
//         int n = str1.length();
//         int m = str2.length();
//         string s1;
//         string s2;
//         if(n < m)
//         {
//             s1 = str1;
//             s2 = str2;
//         }
//         else
//         {
//             s1 = str2;
//             s2 = str1;
//         }
        
//         while(s1 != "")
//         {
//             // cout << s1 << " " << s2 << endl;
//             int x = s1.length();
//             int i = 0;
//             for(i = 0; i < x; i++)
//             {
//                 if(s1[i] != s2[i])
//                 {
//                     // cout << "HII" << endl;
//                     return "";
//                 }
//             }
//             if(i == s2.length())
//                 return s1;
//             string temp = s1;
//             s1 =  s2.substr(i, s2.length() - i);
//             s2 = temp;
//         }
//         // cout << "HII" << endl;
//         return "";
//     }
    
    
    // Just copy and paste
    
         string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};