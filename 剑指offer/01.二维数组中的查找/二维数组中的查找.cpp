#include "../util.h"

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n = array.size();
        int m = array[0].size();
        if(n == 0 || m == 0)
            return false;
        for(int i = 0, j = m - 1; (i < n && n >= 0) && (j >= 0 && j < m);) {
             if(array[i][j] < target) {
                ++i;
             } else if (array[i][j] > target) {
                --j;
             } else {
                return true;
             }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> iv{{1, 2, 8, 9},
                            {2, 4, 9, 12},
                            {4, 7, 10,13},
                            {6, 8, 11,15}};
    cout << Solution().Find(4, iv) << endl;

    return 0;
}
