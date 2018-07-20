#include "../util.h"

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if(number < 2)
            return number;
        int ans = 1;            //f(n) = 2 * f(n-1), 等比数列，公比为2, 首项为1
        for(int i = 1; i < number; ++i) {
            ans *= 2;
        }
            
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
