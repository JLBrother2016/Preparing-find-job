#include "../util.h"

using namespace std;

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        bool ans = false;       //用于判断子结构是否相同
        //如果当前父树的节点与子树的根节点相同，则直接从父树的当前位置开始判定
        if(pRoot1->val == pRoot2->val) {               
            ans = doesSubTree(pRoot1, pRoot2);
        }
        if(!ans) {
            //先从左子树查找，再从右子树查找
            return HasSubtree(pRoot1->left, pRoot2) ||  
                   HasSubtree(pRoot1->right, pRoot2);
        } else {
            return true;
        }
    }
private:
    bool doesSubTree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if(pRoot2 == nullptr) //子树为空，那么必然是子树
            return true;              
        if(pRoot1 == nullptr)//如果子树不为空，但是父亲树为空，一定是不是子树 
            return false;
        //两个节点的值不相等, 那么这两个树必然不是父子关系
        if(pRoot1->val != pRoot2->val)
            return false;
        //否则当前节点相等, 则递归的判断左子树和右子树对应节点是否相同
        return doesSubTree(pRoot1->left, pRoot2->left) &&   
               doesSubTree(pRoot1->right, pRoot2->right);
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
