#include "../util.h"

using namespace std;

class Solution {
public:
    // 构造函数
    Solution() {
        str = "";
        memset(count, '\0', sizeof(count));
    }
  //Insert one char from stringstream
    void Insert(char ch) {
         str += ch;
         ++count[(int)ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        int len = str.length();
        for(int i = 0; i < len; ++i) {
            if(count[(int)str[i]] == 1) 
                return str[i];
        }

        return '#';
    }
private:
    string str;
    int  count[256];
};

int main(int argc, char const *argv[])
{
    

    return 0;
}


