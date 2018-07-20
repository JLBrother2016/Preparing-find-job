#include "../util.h"

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == nullptr) return nullptr;
        
        TreeNode* res = con(pRootOfTree);  //得到一个双链表, 但返回的是根节点

        while(res->left)                   //找到最小的元素
            res = res->left;

        return res;
    }
private:
    TreeNode* con(TreeNode* root) {
        if(root == nullptr) 
            return nullptr;
        if(root->left) {    //中序遍历
            TreeNode* pleft = con(root->left);
            while(pleft->right) {    //指向右子树的最小值
                pleft = pleft->right;
            }
            pleft->right = root;
            root->left = pleft; 
        }
        if(root->right) {
            TreeNode* pright = con(root->right);
            while(pright->left) {    //找到左子树的最大值
                pright = pright->left;
            }
            pright->left = root;
            root->right = pright;
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
