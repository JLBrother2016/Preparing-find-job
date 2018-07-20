#include "../util.h"

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* tmp = nullptr;
        Convert(pRootOfTree, &tmp);
        TreeNode* res = tmp;
        while(res != nullptr && tmp->left != nullptr) {
            tmp = tmp->left;
        }

        return res;
    }
private:
    void Convert(TreeNode* proot, TreeNode** node) {
        if(proot == nullptr)
            return;
        TreeNode* current = proot;
        if(proot->left != nullptr) {
            Convert(proot->left, node);
        }
        proot->left = *node;
        if(*node != nullptr) {
            (*node)->right = current;
        }
        *node = current;
        if(proot->right != nullptr) {
            Convert(proot->right, node);
        }
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* node = createTree({10,6,14,4,8,12,16});
    levelorderTraverseTree(Solution().Convert(node));

    return 0;
}
