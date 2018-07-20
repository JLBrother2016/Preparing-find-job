#include "../util.h"

using namespace std;

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == NULL) {
            return NULL;
        }

        TreeLinkNode *pNext = NULL;
        //  如果当前结点有右子树, 那么其中序遍历的下一个结点就是其右子树的最左结点
        if(pNode->right != NULL) {
            //  找到右子树的最左孩子
            pNext = pNode->right;
            while(pNext->left != NULL) {
                pNext = pNext->left;
            }
        }
        else if(pNode->right == NULL && pNode->next != NULL) {
            TreeLinkNode *pCurrent = pNode;
            TreeLinkNode *pParent = pNode->next;
            //如果当前结点是其父结点的左子结点那么其中序遍历的下一个结点就是他的父亲结点
            //  如果当前结点是其父结点的右子结点，
            //  这种情况下其下一个结点应该是当前结点所在的左子树的根
            //  因此我们可以顺着其父节点一直向上遍历,
            //  直到找到一个是它父结点的左子结点的结点
            while(pParent != NULL && pCurrent == pParent->right) {
                pCurrent = pParent;
                pParent = pParent->next;
            }
            pNext = pParent;
        }

        return pNext;
    }
};

// class Solution {
// public:
//     TreeLinkNode* GetNext(TreeLinkNode* pNode)
//     {
//         if(pNode==NULL)
//             return NULL;
//         if(pNode->right!=NULL)
//         {
//             pNode=pNode->right;
//             while(pNode->left!=NULL)
//                 pNode=pNode->left;
//             return pNode;
//         }  
//         while(pNode->next!=NULL)
//         {
//             TreeLinkNode *proot=pNode->next;
//             if(proot->left==pNode)
//                 return proot;
//             pNode=pNode->next;
//         }
//         return NULL;
//     }
// };

int main(int argc, char const *argv[])
{
    

    return 0;
}

