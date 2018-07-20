#include "../util.h"

using namespace std;

class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return 0;
        
        int left = TreeDepth(pRoot->right);
        int right = TreeDepth(pRoot->left);

        return left > right ? left + 1 : right + 1;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
