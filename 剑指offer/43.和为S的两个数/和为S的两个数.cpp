#include "../util.h"

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if(array.size() == 0)
            return {};

        int start = 0;
        int end = array.size() - 1;
        vector<int> ans;

        while(end > start) {
            int cursum = array[start] + array[end];
            if(cursum == sum) {
                ans.push_back(array[start]);
                ans.push_back(array[end]);
                break;
            } else if(cursum > sum) 
                --end;
            else 
                ++start;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().FindNumbersWithSum({1,2,4,7,11,11,15}, 15) << endl;

    return 0;
}

