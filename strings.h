/*
 * strings.h
 *
 *  Created on: Feb 25, 2015
 *      Author: acs
 */

#ifndef MAXNOY_STRINGS_H_
#define MAXNOY_STRINGS_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

namespace strings {
using namespace std;

void Reverse(char* str);
unsigned int Length(char* str);
void StripWhitespace(char* szStr);
void RemoveDuplicate(char* str);
char FindFirstUnique(char* str);
wchar_t FindFirstUniqueUnicode(wchar_t* str);
int Atoi(const char* str);
char* Itoa(int number);

/*
 * Problem:
 *         "peanutbutterisgood" should be made
 *         "peanut butter is good"
 *         dict_ can have "pea" "peanut" "butter" etc.
 */
void WordSeperator(string& str, set<string>& dict);
bool IsRecognizedWord(string& str, set<string>& dict);
void RemoveSpaces(string& str);
string UniqueCharacters(const string& str);
bool UniqueCharactersCheck(const string& str);
bool UniqueCharactersNoSpace(const string& str);
void ReverseString(char* str);
bool Anagram(const string& str1, const string& str2);
void ReplaceSpaces(char* str, int length);
string CompressString(const string& str);
bool OneEditApart(string* str1, string* str2);
void Print123To100();
void BalanceParenthesis(string& str);
/*
 * Trie
 */
class Trie {
public:
   const static int MaxChars = 26;
   struct TNode {
      bool word_ { false };
      TNode* child_[MaxChars];
      TNode() {
         word_ = false;
         for (int i = 0; i < MaxChars; ++i) {
            child_[i] = nullptr;
         }
      }
      ~TNode() {
         for (int i = 0; i < MaxChars; ++i) {
            delete child_[i];
         }
      }
   };
   void Push(const char* str);
   bool Exists(const char* str) const;
   // Pass "t o" to match two etc.
   int CountMatches(const char* str) const;
private:
   int countMatches_(const char* str, int loc, TNode* node) const;
   TNode* head_ { nullptr };
};

void PrintMatrixWords(const string*, const Trie&, int length);
string CompressString(const string& str);
bool IsRotatedSubstring(const string& str1, const string& str2);
void PrintPermutations(char* c, int i, int n);
bool CheckPattern(const string& pat, const string& match);
void KeepAnagramsTogether(vector<string>& strV);
int FindInSortedStringsWithSpace(const vector<string>& strV, int start, int end,
      const string& find);
string LongestPalindrome(string s);
bool IsPalindrome(string s);

class Roman {
public:
   static int FromRoman(string roman);
   static string ToRoman(int roman);
   static void init();
private:
   static map<char, int> romanMap_;
   static map<int, char> romanRMap_;
};
string Numeronym(const string& str);
void OrganizeAlphaNumStr(string& str);
void Scribble(std::list<string>& words, const std::vector<char>& alphas);
int CountTwos(int k);

}
#endif /* MAXNOY_STRINGS_H_ */
