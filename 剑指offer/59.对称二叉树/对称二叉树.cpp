#include "../util.h"

using namespace std;

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
    }
private:
    bool isSymmetrical(TreeNode* right, TreeNode* left) {
        if(right == nullptr && left == nullptr) {
            return true;
        }
        if(right == nullptr || left == nullptr)
            return false;
        if(right->val != left->val) 
            return false;

        return isSymmetrical(right->right, left->left) &&
               isSymmetrical(right->left, left->right);
    }
};


int main(int argc, char const *argv[])
{
    

    return 0;
}

