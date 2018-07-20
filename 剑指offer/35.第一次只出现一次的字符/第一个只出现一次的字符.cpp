#include "../util.h"

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() <= 0)
            return -1;
        unordered_map<char, int> tmap;
        for(char x : str) {
            if(tmap.count(x) == 0) 
                tmap[x] = 1;
            else ++tmap[x];
        }
        int ans = -1;
        for(int i = 0; i < str.length(); ++i) {
            if(tmap[str[i]] == 1) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().FirstNotRepeatingChar("AABCD") << endl;

    return 0;
}

