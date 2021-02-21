/***

  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.

  Example 1:

  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Output: Because nums[0] + nums[1] == 9, we return [0, 1].

  Example 2:
  Input: nums = [3,2,4], target = 6
  Output: [1,2]
  
***/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef std::vector<int>::iterator IntVecIter;
        std::vector<int> result;
        
        for( IntVecIter iter = nums.begin(); iter != nums.end(); ++iter) {
            // Check if the difference exists in the array
            // Making the iterator as a const reference reduced the run times from 564 ms to 10 ms
            const IntVecIter & pos = std::find(iter+1, nums.end(), target - (*iter) );
        
            if (pos != nums.end() ) {
                // store the index of the current iterator from the beginning and the 
                // index of the difference number
                result.push_back(iter - nums.begin() );
                result.push_back( pos - nums.begin() );
                break;
            }
        }
        
        return result;
    }
};
