/***
  https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/180/

  Given a string s, return the longest palindromic substring in s.

  Example 1:

  Input: s = "babad"
  Output: "bab"
  Note: "aba" is also a valid answer.
  Example 2:

  Input: s = "cbbd"
  Output: "bb"
  Example 3:

  Input: s = "a"
  Output: "a"
***/

string longestPalindrome(string s) 
{        
    if (s.length() == 1)
        return s;
  
    std::string longest = s.substr(0,1);

    for (int i=0; i<s.length(); ++i)
    {
        for (int j=i+1; j < s.length(); ++j)
        {
            /// Each substring starts from the previous i+1 to j
            const std::string sstr = s.substr(i,(j-i+1));        // substr(pos, len)

            int k=0;
            /// Traverse from both ends of the string and match the characters
            for(;k < sstr.size()/2; k++)    {
                if( sstr.at(k) != sstr.at(sstr.length()-k-1) )
                    break;
            }

            if( k == sstr.size()/2 && 
                sstr.length() > longest.length()
              )
            {
                longest = sstr;
            } 
          }
      }
    return longest;
}
