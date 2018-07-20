#include "../util.h"

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) 
            return 0;
        if(rotateArray.size() == 1) 
            return rotateArray[0];

        int low = 0;
        int high = rotateArray.size() - 1;
        int mid = low;      //利用二分查找的思路来解这道题
        while(rotateArray[low] >= rotateArray[high]){      //因为是旋转数组，后面的应该比前面的小
            // 结束条件
            if(high - low == 1){
                mid = high;
                break;
            }

            // mid = (low + high)/2;   //为了防止溢出, 推荐使用low + (high - low) /2
            mid = low + (high - low) / 2;

            //顺序查找
            if(rotateArray[low] == rotateArray[high] && rotateArray[low] == rotateArray[mid])   //三个位置的大小都相同
                return minInOrder(rotateArray, low, high);

            if(rotateArray[mid] >= rotateArray[low])    //利用了部分有序的原理
                low = mid;
            else if(rotateArray[mid] <= rotateArray[high])
                high = mid;
        }

        return rotateArray[mid];
    }

    int minInOrder(vector<int>& numbers, int low, int high){
        int result = numbers[low];
        for(int i = low + 1; i <= high; ++i){
            if(result > numbers[i])
                result = numbers[i];
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
