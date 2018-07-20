#include "../util.h"

using namespace std;

class Solution {
    int n, m;                               //n是数组的行，m是数组的列
    vector<vector<bool> > v;                //表示当前位置是否被访问过
    bool judge(int i, int j) {              //判断(i,j)这一点是不是合法的
        return 0 <= i && i < n && 0 <= j && j < m && !v[i][j];  //i在(0,n)范围内, j在(0,m)范围内, 并且v[i][j]为false, 即未被访问
    }

public:
    vector<int> printMatrix(vector<vector<int> > a) {
        vector<int> r;                      //保存结果的数组
        if((n = a.size()) == 0 || (m = a[0].size()) == 0)   //容错处理
            return r;

        v = vector<vector<bool> >(n, vector<bool>(m, false));   //声明一个二维数组并初始化为false
        const int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  //用数组来标识转向，右->下->左->上
                         //  向右加， 向下加， 向左走， 向上走
        int i = 0, j = 0, d = 0, count = m * n;
        while(count--) {
            // cout << i << " " << j << endl;
            r.push_back(a[i][j]);
            v[i][j] = true;             //push_back后的点，标记为已访问的点
            if(!judge(i + D[d][0], j + D[d][1])) {          //d的取值为(0,4), 如果该点已经被访问了或者是超出了边界,d就加1, 即进入下一个方向
                (++d) %= 4;     //转弯, 余数范围在0-3中
            }
            i += D[d][0];       //i和j为数组的索引
            j += D[d][1];       //前进
        }

        return r;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().printMatrix({{1, 2, 3, 4,},
                                    {5, 6, 7, 8,},
                                    {9, 10, 11, 12,},
                                    {13, 14, 15, 16}}) 
         << endl;

    return 0;
}
