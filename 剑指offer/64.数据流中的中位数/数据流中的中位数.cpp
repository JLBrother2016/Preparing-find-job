#include "../uitl.h"

using namespace std;

class Solution {
protected :
    multiset<int>   left;       /*  左半部分  */
    multiset<int>   right;      /*  右半部分  */
public:
    void Insert(int n) {
        int tmp = n;
        if(((left.size() + right.size()) & 1) == 0) {
            if (right.empty() != true && n > *right.begin()) {
                right.insert(n);
                tmp = *right.begin();
                right.erase(right.find(tmp));
            }
            left.insert(tmp);
        }
        else {
            if (left.empty() != true && n < *left.rbegin()) {
                left.insert(n);
                tmp = *left.rbegin();
                left.erase(left.find(tmp));
            }
            right.insert(tmp);
        }
    }
    double GetMedian() {
        if(((left.size() + right.size()) & 1) == 0) {
            return (double)(*left.rbegin() + *right.begin()) / 2.0;
        }
        else {
            return (double)*left.rbegin();
        }
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

