#include "../util.h"

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() < k || input.size() == 0)
            return {};
        else if(input.size() == k)
            return input;
        int start = 0;
        int end = input.size() - 1;
        int index = partition(input, start, end);
        while(index != (k-1)) {
            if(index > k-1) {
                end = index - 1;
                index = partition(input, start, end);
            } else {
                start = index + 1;
                index = partition(input, start, end);
            }
            if(k <= 0) break;
        }
        vector<int> ans(input.begin(), input.begin() + k);

        return ans;
    }
private:
    int partition(vector<int>& number, int begin, int end) {
        int low = begin;
        int high = end;
        int pivot = number[low];
        while(low < high) {
            while(low < high && pivot <= number[high])
                --high;
            number[low] = number[high];
            while(low < high && pivot >= number[low])
                ++low;
            number[high] = number[low];
        }
        number[low] = pivot;
        return low;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}


