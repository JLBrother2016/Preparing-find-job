#include "../util.h"

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        if(len == 0) 
            return {};
        vector<int> ans(len, 0);
        ans[0] = 1;
        for(int i = 1; i < len; ++i) {
            ans[i] = ans[i - 1] * A[i - 1];
        }
        int tmp = 1;
        for(int i = len - 1; i >= 0; --i) {
            ans[i] *= tmp;
            tmp *= A[i];
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
