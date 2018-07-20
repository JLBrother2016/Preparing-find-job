#include "../util.h"

using namespace std;

// class temp {
// public:
//     temp() {++N, sum += N;}
//     static void reset(void) {
//         N = 0, sum = 0;
//     }
//     static unsigned int getsum (void) {
//         return sum;
//     }
// private:
//     static unsigned int N;
//     static unsigned int sum;
// };

// unsigned int temp::N = 0;
// unsigned int temp::sum = 0;

// class Solution {     //利用构造函数求解
// public:
//     int Sum_Solution(int n) {
//         temp::reset();

//         temp* a = new temp[n];  //创建n个对象，然后马上释放掉
//         delete []a;

//         a = nullptr;

//         return temp::getsum();  //返回的是类共有的数据
//     }
// };
// class A;
// A* array_[2];

// class A {
// public:
//     virtual unsigned int sum(unsigned int n) {
//         return 0;
//     }
// };
// class B : public A {
// public:
//     virtual unsigned int sum(unsigned int n) {
//         return array_[!!n]->sum(n - 1) + n;
//     }    
// };

// class Solution {     //利用虚函数求解
// public:
//     int Sum_Solution(int n) {
//         A a;
//         B b;
//         array_[0] = &a;
//         array_[1] = &b;
//         int ans = array_[1]->sum(n);

//         return ans;
//     }
// };
typedef unsigned int (*fun)(unsigned int);
unsigned int Solution3_teminator(unsigned int n) {
    return 0;
}
unsigned int Sum_Solution3(unsigned int n) {
    static fun f[2] = {Solution3_teminator, Sum_Solution3};
    return n + f[!!n](n - 1);
}
// 利用模板函数求解
template <unsigned int n> 
struct sum_solution4 {
    enum value {
        N = sum_solution4<n - 1>::N + n
    };
};
template <>
struct sum_solution4<1>
{
    enum value {
        N = 1
    };
};


class Solution {     //利用函数指针来模拟虚函数
public:
    int Sum_Solution(unsigned int n) {
        // const unsigned int n_ = n;
        // return Sum_Solution3(n);
        return sum_solution4<100>::N;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().Sum_Solution(10) << endl;

    return 0;
}

