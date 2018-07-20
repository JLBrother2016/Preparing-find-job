#include "../util.h"

using namespace std;

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr) return;

        stack<TreeNode*>  Stack;    //相当于二叉树的按层遍历的变种
        Stack.push(pRoot);
        while(!Stack.empty()) {
            TreeNode *tmpRoot = Stack.top();
            Stack.pop();
            TreeNode *tmp = tmpRoot->left;    //将左右子树的结点交换
            tmpRoot->left = tmpRoot->right;
            tmpRoot->right = tmp;
            if(tmpRoot->left != nullptr)
                Stack.push(tmpRoot->left);
            if(tmpRoot->right != nullptr)
                Stack.push(tmpRoot->right); 
        }
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

