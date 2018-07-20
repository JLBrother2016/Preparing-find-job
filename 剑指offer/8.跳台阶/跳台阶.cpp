#include "../util.h"

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2)
            return number;
        int ans = 0;
        int f1 = 1;
        int f2 = 2;
        for(int i = 3; i <= number; ++i) {
            ans = f1 + f2;
            f1 = f2;
            f2 = ans;
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().jumpFloor(10) << endl;

    return 0;
}
