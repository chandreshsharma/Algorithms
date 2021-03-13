/***
  https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/213/

  Given a character array s, reverse the order of the words.
  A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.

  Example 1:

  Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
  Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
  Example 2:

  Input: s = ["a"]
  Output: ["a"]
***/

void reverseWords(vector<char>& s) 
{
    std::string word;
    std::stack<std::string> strStk;

    for (const auto & c: s) 
    {
        if(!std::isspace(c))
            word += c;
        else if(word.length())  /// A valid word exists, push it to the stack
        {
            strStk.push(word);
            word.clear();
        }
    }

    /// Push in the last word
    if(word.length())
        strStk.push(word);

    s.clear();

    while(!strStk.empty())
    {
        std::string word = strStk.top();
        strStk.pop();
        for(auto c:word)
            s.push_back(c);

        if(!strStk.empty())
            s.push_back(' ');
    }
}
