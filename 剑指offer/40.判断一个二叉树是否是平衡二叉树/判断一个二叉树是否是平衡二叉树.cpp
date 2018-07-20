#include "../util.h"

using namespace std;

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced_Solution(pRoot, depth);
    }
private:
    bool IsBalanced_Solution(TreeNode* pRoot, int& depth) {
        if(pRoot == nullptr) {
            depth = 0;
            return true;
        }
        int left, right;    //边递归边判断二叉树是否是平衡二叉树
        if(IsBalanced_Solution(pRoot->left, left) &&
           IsBalanced_Solution(pRoot->right, right)) {
            int diff = abs(left - right);
            if(diff <= 1) {
                depth = 1 + max(left, right);
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

