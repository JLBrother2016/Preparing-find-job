#include "../util.h"

using namespace std;

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {  //从上往下层遍历
        if(root == nullptr) 
            return {};
        queue<TreeNode*> q;         //按层遍历, 利用一个队列实现
        vector<int> ans;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tmpRoot = q.front();      //每次取出队列的头部
            ans.push_back(tmpRoot->val);
            if(tmpRoot->left) q.push(tmpRoot->left);    //左结点先入队
            if(tmpRoot->right) q.push(tmpRoot->right);  //右结点再入队
            q.pop();
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

