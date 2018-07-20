#include "../util.h"

/*class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int len = numbers.size();
    vector<int> result;
    int temp = 0;
    for(int i = 0; i < len; ++i) {
      temp = target - numbers[i];
      for(int j = i + 1; j < len; ++j)
        if (numbers[j] == temp){
          result.push_back(i+1);
          result.push_back(j+1);
        }
        else if(numbers[j] > temp)
          break;
    } 
    return result;
  }
};*/
/*class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        
        int start = 0;
        int end = numbers.size() - 1;
        
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (sum == target) {
                res.push_back(start + 1);
                res.push_back(end + 1);
                break;
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
        return res;
    }
};*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int, int> M;
        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            if (M.find(complement) != M.end()) {
                return {M[complement], i+1};
            } else {
                M[numbers[i]] = i + 1;
            }
        }
        return {-1, -1};
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{2, 7, 11, 15};

  cout << Solution().twoSum(vect, 9) << endl;

  return 0;
}