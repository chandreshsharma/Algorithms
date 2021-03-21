/***

https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/211/

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

***/

int trap(vector<int>& height) {
    int result = 0;

    const int size = height.size();

    // For every element of the array, starting from the second element, i.e index 1
    for (int i=1; i<size-1; i++) {
        /// Traverse from the index 0 element to the left of the current element

        /// height of current element
        int left = height[i];
        int right = height[i];

        /// Find the maximum element on its left
        for (int j=0; j<i; j++)
            left = max(left, height[j]);

        /// Find the maximum element on its right   
        for (int j=i+1; j<size; j++)
            right = max(right, height[j]); 

        /// Update the maximum water, minimum height on each side, less height of current
        result = result + (min(left, right) - height[i]);   
    }

    return result;
  }
