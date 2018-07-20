#include "../util.h"

using namespace std;

class Solution {
public:     //排序数组中出现的次数, 应该用二分查找法
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0) 
            return 0;
        int left = GetNumberOfK(data, 0, data.size() - 1, k, 1);
        int right = GetNumberOfK(data, 0, data.size() - 1, k, 2);
        int ans = right - left;

        return ans > 0 ? ans : 0;
    }
private:  //
    int GetNumberOfK(vector<int>& data, int start, int end, int k, int flag) {
        if(start > end) 
            return -1;
        int mid = start + (end - start)/2;
        if(data[mid] == k) {
            if(flag == 1) {
                if((mid > 0 && data[mid-1] != k) || mid == 0)
                    return mid;
                else end = mid - 1;
            } else {
                if((mid < data.size() && data[mid+1] != k) || 
                    mid == data.size() - 1)
                    return mid;
                else start = mid + 1;
            }
            
        }
        else if(data[mid] > k)
            end = mid - 1;
        else start = mid + 1;

        return GetNumberOfK(data, start, end, k, flag);
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
