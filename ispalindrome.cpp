/***

  From https://leetcode.com/problems/valid-palindrome/

  Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  Example 1:

  Input: s = "A man, a plan, a canal: Panama"
  Output: true
  Explanation: "amanaplanacanalpanama" is a palindrome.

***/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        
        std::string str;
       
        // create the new string, ignoring the case and the spaces
        for(int i=0; i < s.length(); ++i)   {
            if( isalnum(s.at(i)) )
                str += ::tolower(s.at(i));
        }

        // compare each letter from beginning of the string to from end of the string.
        for(int j=0; j < (str.length()/2) ; ++j) {
            if( str.at(j) != str.at(str.length() - j - 1) )
                return false;
        }

        return true;
    }
};
