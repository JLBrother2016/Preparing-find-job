#include "../util.h"

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        bitset<32> bit(n);      //利用STL库函数来实现
        return bit.count();
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().NumberOf1(6) << endl;

    return 0;
}

