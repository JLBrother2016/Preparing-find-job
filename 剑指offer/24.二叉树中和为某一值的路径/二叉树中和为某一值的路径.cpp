#include "../util.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr) return {};
        int currentSum = 0;
        vector<int> path;           //保存路径
        vector<vector<int>> ans;    //保存结果
        FindPath(root, expectNumber, path, ans, currentSum);

        return ans;
    }
private:
    void FindPath(TreeNode* root, int expectNumber, vector<int>& path, 
                  vector<vector<int>>& ans, int currentSum) {
        currentSum += root->val;        //加上结点的和
        path.push_back(root->val);      //是否到了叶子结点
        bool isLeaf = (root->left == nullptr && root->right == nullptr);
        if(isLeaf && currentSum == expectNumber) {
            ans.push_back(path); //如果到了叶子结点，而且路径的和为所求,就保存该路径
        }
        if(root->left)  //如果左子树存在, 就递归遍历左子树
            FindPath(root->left, expectNumber, path, ans, currentSum);
        if(root->right) //如果右子树存在，就递归遍历右子树
            FindPath(root->right, expectNumber, path, ans, currentSum);
        path.pop_back();
    }

};

int main(int argc, char const *argv[])
{
    


    return 0;
}

