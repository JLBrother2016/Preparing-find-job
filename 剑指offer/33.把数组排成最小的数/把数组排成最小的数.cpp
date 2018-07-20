#include "../util.h"

using namespace std;

// 一个非常直观的解决大数计算的方法是将数字转换为字符串
// 对vector容器内的数据进行排序, 按照将a和b转为string后
// 若a + b < b + a，a排在前的规则排序
// 比如2 21, 因为212 < 221, 所以排序后为212
// to_string 可以将int型转换为stirng
class Solution {
public:
    static bool cmp(int a, int b) {
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);

        B += to_string(b);
        B += to_string(a);

        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string ans = "";
        sort(numbers.begin(), numbers.end(), cmp);

        for(int i = 0; i < numbers.size(); ++i) {
            ans += to_string(numbers[i]);
        } 

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().PrintMinNumber({3, 32, 321}) << endl;

    return 0;
}

