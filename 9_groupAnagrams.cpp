/***

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

***/

vector<vector<string>> groupAnagrams(vector<string>& strs) {

  /// For each word read, insert the lexicographic order in as a key in a map
  /// with the lexicographic order as the key
  /// Keep comparing the elements and pushing the elements.

  /// @@@CS: Using an std::sort(std::string) was seen faster than using a std::multiset<char>
  /// std::map<std::multiset<char>, std::vector<std::string>> lexStrToStrMap;

  std::map<std::string, std::vector<std::string>> lexStrToStrMap;

  for(const auto & str: strs)
  {
    std::string lexStr = str;
    std::sort(lexStr.begin(), lexStr.end());

///            for(const auto & c: str)
///                lexStr.insert(c);

///            if(lexStrToStrMap[lexStr].empty()) 
///            {
///                std::vector<std::string> vecStrs = {str};
///                lexStrToStrMap[lexStr] = {str};
///            }
///            else

      ///@@@CS: Using the lexStrToStrMap both initializes and inserts the string in the vector
              lexStrToStrMap[lexStr].push_back(str);
  }

  std::vector<std::vector<std::string>> resultStrs;

  for(auto m:lexStrToStrMap){
      std::vector<std::string> strVec(m.second.begin(), m.second.end());

      ///@@@CS: Using begin() and end() method to initialize a vector is faster than std::copy

//            std::copy(m.second.begin(), m.second.end(), std::back_inserter(strVec));
      resultStrs.push_back(strVec);
  }

  return resultStrs;
}
