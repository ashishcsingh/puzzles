#include "strings.h"
#include <map>
#include <iostream>
#include <vector>
#include <cassert>

namespace strings {
using namespace std;

/*
 * What: Reverse the string
 * How:  Find length
 *       Then Till half way swap i with length-1-i elements
 */
void Reverse(char* str) {
   int length = Length(str);
   //Swap till half the length
   int j = 0;
   int k = length - 1;
   char temp;
   while (j < k) {
      temp = str[j];
      str[j] = str[k];
      str[k] = temp;
      j++;
      k--;
   }
}

/*
 * What: UniqueCharacters(const string& str)
 *       Returns unique chars string
 * How:  Use set<char>
 */
string UniqueCharacters(const string& str) {
   set<char> s;
   for(auto c:str) {
      s.insert(c);
   }
   string ret;
   for(auto c:s) {
      ret.push_back(c);
   }
   return ret;
}

/*
 * What: UniqueCharactersCheck(const string& str)
 *       Returns unique chars string as bool
 * How:  Use set<char>
 */
bool UniqueCharactersCheck(const string& str) {
   set<char> s;
   for(auto c:str) {
      auto ret = s.insert(c);
      if(!ret.second) {
         return false;
      }
   }
   return true;
}

/*
 * What: ReverseString(char* str)
 * How:  length = Find length of end.
 *       Two iterators one from start and other from end
 *       Till they over pass swap
 */
void ReverseString(char* str) {
   int length = 0;
   while(str[length]!='\0') {
      ++length;
   }
   int i = 0, j = length-1;
   char temp;
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      ++i;
      --j;
   }
}

/*
 * What: Checks if all the chars in str1 exists in str2
 * How:  Using map<char, int> store count of chars in str1
 *
 */
bool Anagram(const string& str1, const string& str2) {
   // Insert counts in map of str1
   map<char, int> m;
   for(auto c: str1) {
      ++m[c];
   }
   // Decrease counts in map for str2
   // If new chars then return false
   for(auto c: str2) {
      if(m.count(c) < 1) {
         return false;
      }
      --m[c];
   }
   // If any count is not 0 then return false
   for(auto i: m) {
      if(i.second!=0) {
         return false;
      }
   }
   return true;
}

/*
 * What: Replaces spaces by "%20"
 * How:
 */
void ReplaceSpaces(char* str, int length) {
   int spaceCount = 0, i = 0;
   // Count spaces
   while (i <= length) {
      if (str[i++] == ' ') {
         ++spaceCount;
      }
   }
   // Compute new length
   int newLen = length + 2 * spaceCount;
   // Update Index
   --length;
   --newLen;
   // Replace space by "%20"
   while (length >= 0) {
      if (str[length] == ' ') {
         str[newLen--] = '0';
         str[newLen--] = '2';
         str[newLen--] = '%';
      } else {
         str[newLen] = str[length];
         --newLen;
      }
      --length;
   }
}

/*
 * What: UniqueCharactersNoSpace(const string& str);
 *       Returns unique chars in a string
 * How:  No space, therefore N2 complexity of comparisions
 */
bool UniqueCharactersNoSpace(const string& str) {
   for(int i=0; i<str.length(); ++i) {
      for(int j=i+1; j<str.length(); ++j) {
         if(str[i] == str[j]) {
            return false;
         }
      }
   }
   return true;
}

/*
 * Calculate Length
 */
unsigned int Length(char* str) {
   unsigned int length = 0;
   while (str[length]!='\0') {
      length++;
   }
   return length;
}

/*
 * What: Calculate Length
 */
unsigned int Length(wchar_t* str) {
   unsigned int length = 0;
   while (str[length]!='\0') {
      length++;
   }
   return length;
}

/*
 * Iterate through from 0 to length-1 in i and j
 * while str[i] == ' ' do i++
 * Copy str[j] = str[i]
 */
void StripWhitespace(char* str) {
   int length = Length(str);
   int i = 0, j = 0;
   for(; i<length && j<length; i++, j++) {
      while(str[i]==' ') {
         i++;
      }
      str[j] = str[i];
   }
   str[j] = '\0';
}

/*
 * Iterate through from 0 to length-1 in i and j
 * While str[i] == str[i - 1] do i++
 * Copy str[j] = str[i]
 * Copy str[j] = '\0';
 */
void RemoveDuplicate(char* str) {
   int length = Length(str);
   int i = 0, j = 0;
   for(; i<length && j<length; i++, j++) {
      while(i > 0 && i< length && str[i]==str[i-1]) {
         i++;
      }
      str[j] = str[i];
   }
   str[j] = '\0';
}


/*
 * Push all the chars from 0 to length-1 to map (char, int)
 * where value is meant for count
 * Iterate through each element from start when count is 1 return
 */
char FindFirstUnique(char* str) {
   int length = Length(str);
   std::map<char,int> strMap;
   for(unsigned int i=0; i<length; i++) {
      if (strMap.count(str[i]) > 0) {
         strMap[str[i]]++;
      } else {
         strMap[str[i]] = 1;
      }
   }
   for(auto i=strMap.begin(); i!=strMap.end(); ++i) {
      if(i->second == 1) {
         return i->first;
      }
   }
   return 0;
}


/*
 * Push all the chars from 0 to length-1 to map (char, int)
 * where value is meant for count
 * Iterate through each element from start when count is 1 return
 */
wchar_t FindFirstUniqueUnicode(wchar_t* str) {
   unsigned int length = Length(str);
   std::map<wchar_t,int> strMap;
   for(unsigned int i=0; i<length; i++) {
      if (strMap.count(str[i]) > 0) {
         strMap[str[i]]++;
      } else {
         strMap[str[i]] = 1;
      }
   }
   for(auto i=strMap.begin(); i!=strMap.end(); ++i) {
      if(i->second == 1) {
         return i->first;
      }
   }
   return 0;
}

int Atoi(const char* str) {
   bool negative = false;
   int i = 0;
   if(str == nullptr) {
      return 0;
   }
   if(str[0] == '-') {
      negative = true;
      i++;
   }
   int number = str[i] - '0';
   i++;
   while(str[i]!='\0') {
      number = number*10;
      number+= (str[i] - '0');
      i++;
   }
   return negative?-number:number;
}

/*
 * What: Converts int to chars
 * How:  %10 and /10 then reverse
 */
const static int LENGTH_INT = 8;
char* Itoa(int number) {
   char* str = new char[LENGTH_INT];
   bool negative = false;
   if(number < 0) {
      negative = true;
      number = -number;
   }
   int i = 0;
   // number = number mod 10 and keep on dividing number by 10
   while(number > 0) {
      str[i] = (number % 10) + '0';
      number /= 10;
      i++;
   }
   if(negative) {
      str[i] = '-';
      i++;
   }
   int j=0, length = i;
   i--;
   // Reverse the fetched number string
   while(i>j) {
      char temp = str[j];
      str[j] = str[i];
      str[i] = temp;
      i--;
      j++;
   }
   str[length] = '\0';
   return str;
}

/*
 * What: Is this word in dictionary
 */
bool IsRecognizedWord(string& str, set<string>& dict) {
   return dict.end()!=dict.find(string(str));
}

/*
 * What: "peanutbutterisgood" => "peanut butter is good"
 * How:  From end, using two iterators check if word exists
 *       in the dictionary if yes then store in the vector
 *       In the ret string add words seperated by space
 */
void WordSeperator(string& str, set<string>& dict)  {
   vector<string> words;
   string::iterator itr = str.end();
   for(string::iterator rit = str.end(); rit>=str.begin(); --rit) {
      string test(rit, itr);
      if(IsRecognizedWord(test, dict)) {
         words.push_back(test);
         itr = rit;
      }
   }
   words.push_back(string(str.begin(), itr));
   string ret;
   for(vector<string>::iterator rit=words.end(); rit>=words.begin(); --rit) {
      ret += *rit;
      ret += " ";
   }
   str = ret;
}

/*
 * What: Removes space from string
 */
void RemoveSpaces(string& str) {
   for(size_t i = 0; i<=str.length(); ++i) {
      if(str[i]==' ') {
         str.erase(i);
      }
   }
}


/*
 * What: Trie
 * How: Push() and Exists()
 * if head_ is empty
 * Initialize it.
 * str will end with '\0'
 * reach each chars and keep inserting into Trie
 *   - if at that node this is nullptr
 *   return false
 */
void Trie::Push(const char* str) {
   TNode* node = nullptr;
   if(head_ == nullptr) {
      head_ = new TNode();
   }
   node = head_;
   while(true) {
      char c = *(str++);
      if(c == '\0') {
         node->word_ = true;
         return;
      }
      c = tolower(c);
      //Data check
      if(c<'a' || c>'z') {
         return;
      }
      int trieItr = c -'a';
      if(node->child_[trieItr] == nullptr) {
         node->child_[trieItr] = new TNode();
      }
      node = node->child_[trieItr];
   }
}

bool Trie::Exists(const char* str) const {
   TNode* node = head_;
   while(true) {
      char c = *(str++);
      //Positive returns
      if(c == '\0') {
         return node->word_;
      }
      c = tolower(c);
      //Data check
      if(c<'a' || c>'z') {
         return false;
      }
      int trieItr = c -'a';
      if(node->child_[trieItr] == nullptr) {
         return false;
      }
      node = node->child_[trieItr];
   }
   return false;
}

/*
 * What: aaabbbcccdd =>a3b2c3d2
 * How: if(str[i] == str[i-1]) count++
 */
string CompressString(const string& str) {
   if(str.length() <1) {
      return str;
   }
   int count = 1;
   string ret;
   for(int i=1; i<str.length(); ++i) {
      if(str[i-1] == str[i]) {
         ++count;
      } else {
         ret += str[i-1];
         ret += (count + '0');
         count = 1;
      }
   }
   ret += str[str.length()-1];
   ret += (count + '0');
   if(ret.length() < str.length()) {
      return ret;
   } else {
      return ret;
   }
}

/*
 * What: checks if str1 is rotated str2
 * How:  if str2 is a substring of str1 + str1
 */
bool IsRotatedSubstring(const string& str1, const string& str2) {
   string str = str1 + str1;
   return str.find(str2)!=string::npos;
}

/*
 * What: Print words in string[]:matrix that exists in Trie:t
 *       Horizonally and vertically
 * How:  For i:length
 *          For j:string.length()
 *             if t.Exists(matrix[i].substring(j, matrix[i].length())
 *                Print
 *
 */
void PrintMatrixWords(const string* matrix, const Trie& t, int length) {
   // Horizonally
   for(int i=0; i<length; ++i) {
      for(int j=0; j<matrix[i].length()-1; ++j) {
         const char* candidate = matrix[i].substr(j).c_str();
         if(t.Exists(candidate)) {
            cout<<candidate<<endl;
         }
      }
   }
}

void Swap(char* a, char* b) {
   char temp = *a;
   *a = *b;
   *b = temp;
}

/*
 * What: a = "ABC", i=0 and n=2
 *       print: ABC and 6 combinations
 *       O(n*n!)
 * How:  swap first element with next and then revert back
 *       Then print when all arrangements have been tried till n
 */
void PrintPermutations(char* a, int i, int n) {
   if(i == n) {
      cout<<a<<endl;
      return;
   }
   for(int j=i; j<=n; ++j) {
      Swap(a+i, a+j);
      PrintPermutations(a, i+1, n);
      Swap(a+i, a+j);
   }
}

/*
 * What: pat: a+b: ab, aaa...b (+ => one and more)
 *            a*b: b, aaaaa..b (* => one or more)
 * How:
 *
 */
bool CheckPattern(const string& pat, const string& match) {
   if(pat[0] == '+' || pat[0] == '*') {
      return false;
   }
   int patI = 0, matI = 0;
   while(patI < pat.length() && matI < match.length()) {
      switch(pat[patI]) {
      case '+':
         if(pat[patI-1] != match[matI]) {
            return false;
         }
         matI++;
      case '*':
         while(pat[patI-1] == match[matI]) {
            ++matI;
         }
         patI++;
         break;
      default:
         if(pat[patI] == match[matI]) {
            ++matI;
            ++patI;
         } else {
            return false;
         }
      }
   }
   if(patI == pat.length() && matI == match.length()) {
      return true;
   }
   return false;
}

/*
 * What: Writes back with the sorted vector of strings by anagram
 * How:  map<string, vector<string>>
 *       key = sorted string
 *       value = keep adding new elements
 */
void KeepAnagramsTogether(vector<string>& strV) {
   map<string, vector<string>> mapStr;
   for(auto str:strV) {
      string temp = str;
      sort(temp.begin(), temp.end());
      mapStr[temp].push_back(str);
   }
   strV.clear();
   for(auto itr: mapStr) {
      for(auto str: itr.second) {
         strV.push_back(str);
      }
   }
}

/*
 * What: Find if the string exists in the sortedStringVector with space
 */
int FindInSortedStringsWithSpace(const vector<string>& strV, int start, int end, const string& find) {
   if(start > end) {
      return -1;
   }
   int mid = (start + end)/2;
   int left = mid, right = mid;
   if(strV[mid].empty()) {
      left--;
      right++;
      while(true) {
         if(left < start || right > end) {
            return -1;
         } else if (!strV[left].empty()) {
            mid = left;
            break;
         } else if (!strV[right].empty()) {
            mid = right;
            break;
         }
         --left;
         ++right;
      }
   }

   int val = strV[mid].compare(find);
   if(val == 0) {
      return mid;
   } else if (val > 0) {
      return FindInSortedStringsWithSpace(strV, start, mid - 1, find);
   } else {
      return FindInSortedStringsWithSpace(strV, mid + 1, end, find);
   }
}
}
