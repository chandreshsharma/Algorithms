/***
  https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/179/

  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.

  Example 1:
    Input: s = "()"
    Output: true
    
  Example 2:
    Input: s = "()[]{}"
    Output: true
***/

bool isOpenParen(const char & c) const 
{
    return (c == '{' || c == '(' || c == '[');
}

bool isMatchParen(const char & c, const std::stack<char> & stk) const
{
    if(stk.empty())
        return false;
    else if( c == '}' && stk.top() == '{' )
        return true;
    else if ( c == ')' && stk.top() == '(' )
        return true;
    else if ( c == ']' && stk.top() == '[' )
        return true;
    else
        return false;
}

bool isValid(string s) {
    std::stack<char> parenStk;

    for(const auto & c: s)
    {
        if(isOpenParen(c))  /// Push to the stack
            parenStk.push(c);
        else
        {
            if( isMatchParen(c, parenStk) )
                parenStk.pop();
            else
                return false;
        }
    }
  
    if(!parenStk.empty())
        return false;

    return true;
}
