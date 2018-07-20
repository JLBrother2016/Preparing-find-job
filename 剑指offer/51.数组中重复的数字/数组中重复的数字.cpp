#include "../util.h"

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 0 || numbers == nullptr) {
            return false;
        }
        unordered_map<int, int> cnt_map;
        for(int i = 0; i < length; ++i) {
            if(cnt_map.count(numbers[i]) == 0)
                cnt_map[numbers[i]] = 1;
            else ++cnt_map[numbers[i]];
        }
        /*for(auto it = cnt_map.begin(); it != cnt_map.end(); ++it) {
            if(it->second > 1) {
                *duplication = it->first;
                return true;
            }
        }*/
        for(int i = 0; i < length; ++i) {
            if(cnt_map[numbers[i]] > 1) {
                *duplication = numbers[i];
                return true;
            }
        }
        
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}

