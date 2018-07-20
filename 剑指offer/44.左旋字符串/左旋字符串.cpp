#include "../util.h"

using namespace std;

// class Solution {
// public:
//     string LeftRotateString(string str, int n) {
//         if(str.size() == 0)
//             return "";

//         string tmp = str + str;
//         string ans;
//         for(int i = 0; i < str.size(); ++i) {
//             ans.push_back(tmp[i+n]);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() == 0)
            return "";

        int len = str.length();
        n = n % len;
        str += str;

        return str.substr(n, len);
    }
};


int main(int argc, char const *argv[])
{
    cout << Solution().LeftRotateString("abcXYZdef", 3) << endl;


    return 0;
}

