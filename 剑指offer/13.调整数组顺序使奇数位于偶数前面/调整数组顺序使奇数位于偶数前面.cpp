#include "../util.h"
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {     //如果只是保证把奇数和偶数分开，可以用快排的思想
                                                //但要求保证原来的奇偶数的顺序，就用插入排序的思想
        if(array.size() == 0)               //特殊处理
            return;
        int i = 0, j;
        while(i < array.size()) {           //小于矩阵的大小
            while(i < array.size() && !isEven(array[i])) //找到第一个偶数的位置
                ++i;
            j = i + 1;
            while(j < array.size() && isEven(array[j]))  //找到第一个奇数的位置
                ++j;
            if(j < array.size()) {//第一个偶数还没有到数组末尾                     
                int tmp = array[j];         //tmp是一个奇数,即要插入的是一个奇数
                for(int j2 = j - 1; j2 >= i; --j2) {
                    array[j2 + 1] = array[j2];      //这里有一个数据移动的过程
                }
                array[i++] = tmp;   //先执行后加, 即先执行array[i] = tmp;再执行i = i + 1
            } else {      //查找失败
                break;
            }
        }
    }
private:
    bool isEven(int n) {
        return n % 2 == 0 ? true : false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> iv{1,2,3,4,5,6,7,8,9};
    Solution().reOrderArray(iv); 
    cout << iv << endl;

    return 0;
}
