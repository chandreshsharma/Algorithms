/***

  https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/171/

  Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

  The algorithm for myAtoi(string s) is as follows:

  Read in and ignore any leading whitespace.
  Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
  This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.

  Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
  Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). 

  If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
  If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. 
  Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
  
  Return the integer as the final result.
***/

int myAtoi(std::string str) {
    
        std::string num;
        
        bool ignoreSpace = false;
        
        for(int i=0; i<str.length(); ++i )  {
            if(isalpha(str[i]))
                break;
            
            /// If a digit or a sign is found, ignore spaces
            if (isdigit(str[i]) || str[i] == '-' || str[i] == '+')
                ignoreSpace = true;
            
            /// Spaces are ignored once a digit or a sign is read. All leading spaces are ignored.
            if( !isspace(str[i]) )
                num.append(1, str[i]);    // string& append (size_t n, char c);
            else if(ignoreSpace)
                break;
        }

        std::stringstream ss(num);
        
        long int ret;
        if(num.empty())
            ret = 0;
        else
            ss >> ret;
        
        if(ret >= std::numeric_limits<int>::max())
            return std::numeric_limits<int>::max();
        else if(ret <= std::numeric_limits<int>::min())
            return std::numeric_limits<int>::min();
        else
            return ret;
    }
