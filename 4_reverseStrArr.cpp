/***

  https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/187/

  Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
  You may assume all the characters consist of printable ascii characters.

  Example 1:

  Input: ["h","e","l","l","o"]
  Output: ["o","l","l","e","h"]
***/

void reverseString(vector<char>& s) {

    /// Traverse only till the mid of the string, else the entire string gets reversed again. 
    for(int i=0;i<s.size()/2;++i) 
    {
        const char tmp = s.at(s.size()-i-1);
        s[s.size()-i-1] = s[i];
        s[i] = tmp;
    }
}
