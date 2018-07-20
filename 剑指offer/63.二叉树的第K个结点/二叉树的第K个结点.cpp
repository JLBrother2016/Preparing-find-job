#include "../uitl.h"

using namespace std;

class Solution {
public:     //二叉搜索树的中序是有序的
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(pRoot == nullptr || k == 0)
            return nullptr;

        vector<TreeNode*> ans;
        inorderTraverseTree(pRoot, ans);

        //return ans[0] >= k ? ans[k] : nullptr;
        return k <= ans.size() ? ans[k-1] : nullptr;
    }
private:
    void inorderTraverseTree(TreeNode *root, vector<TreeNode*>& ans) {
        if (root == NULL) return;
        inorderTraverseTree(root->left, ans);
        ans.push_back(root);
        inorderTraverseTree(root->right, ans);
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

