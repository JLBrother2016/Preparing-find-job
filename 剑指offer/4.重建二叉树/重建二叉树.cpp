#include "../util.h"

using namespace std;

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = vin.size();
        if(len == 0) return nullptr;
        vector<int> preLeft, preRight, inLeft, inRight;
        TreeNode *head = new TreeNode(pre[0]);
        int pos = 0;            //找到中序遍历中的根节点，放到pos中
        for(int i = 0; i < len; ++i) {
            if(vin[i] == pre[0]){
                pos = i;
                break;
            }
        }
        //中序中根节点的左边一定是左子树，右边为右子树, 前序: 根左右，中序: 左根右, 后序: 左右根
        //找出前序和中序中的左子树
        for(int i = 0; i < pos; ++i) {
            preLeft.push_back(pre[i+1]);    //左子树节点的个数相同
            inLeft.push_back(vin[i]);
        }
        for(int i = pos+1; i < len; ++i) {  //提取右子树
            preRight.push_back(pre[i]);
            inRight.push_back(vin[i]);
        }

        head->left = reConstructBinaryTree(preLeft, inLeft);
        head->right = reConstructBinaryTree(preRight, inRight);

        return head;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
