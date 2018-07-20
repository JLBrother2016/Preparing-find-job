#include "../util.h"

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() == 0)
            return false;
        int len = numbers.size();
        int countZero = 0;
        for(int i = 0; i < len; ++i) {
            if(numbers[i] == 0)
                ++countZero;
        }
        sort(numbers.begin(), numbers.end());
        int small = countZero;
        int big = countZero + 1;
        int numberGap = 0;
        while(big < len) {
            if(numbers[small] == numbers[big])
                return false;
            numberGap += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }

        return numberGap > countZero ? false : true;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

