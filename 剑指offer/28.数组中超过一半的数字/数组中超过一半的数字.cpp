#include "../util.h"

using namespace std;

class Solution {
public: 
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0)
            return 0;
        else if(numbers.size() == 1)
            return numbers[0];
        int count = 1, ans = numbers[0];
        for(int i = 1; i < numbers.size(); ++i) {
            if(numbers[i] == ans) 
                ++count;
            else --count;
            if(count == 0) {
                ans = numbers[i];
                ++count; 
            }
        }  

        count = 0;
        for(auto &x : numbers)
            if(x == ans)
                ++count;

        return count > numbers.size()/2 ? ans : 0;  
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

