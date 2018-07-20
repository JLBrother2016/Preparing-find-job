#include "../util.h"

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) 
            return 0;
        int ans =  array[0];
        int tem = 0;
        for(int i = 0; i < array.size(); ++i) {
            tem = max(tem + array[i],  array[i]);
            ans = max(tem, ans);
            
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().FindGreatestSumOfSubArray({6,-3,-2,7,-15,1,2,2}) << endl;

    return 0;
}

