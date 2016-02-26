/*
 * strings_test.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: acs
 */

#include "strings.h"

#include <iostream>
#include <cassert>
#include <cstring>

namespace strings {

using namespace std;

void Test_Reverse() {
   cout << "Started testing Test_Reverse()" << endl;
   char str[10] = "Hello";
   str[6] = '\0';
   Reverse(str);
   cout << "Reverse of Hello : " << str << endl;
   cout << "Done testing Test_Reverse()" << endl;
}

void Test_StripWhitespace() {
   cout << "Started testing Test_StripWhitespace()" << endl;
   char str[] = "Hello World";
   StripWhitespace(str);
   cout << "StripWhitespace of \"Hello World\" : " << str << endl;
   cout << "Done testing Test_StripWhitespace()" << endl;
}

void Test_RemoveDuplicate() {
   cout << "Started testing Test_RemoveDuplicate()" << endl;
   char str[] = "Hello World";
   RemoveDuplicate(str);
   cout << "RemoveDuplicate of \"Hello World\" : " << str << endl;
   cout << "Done testing Test_RemoveDuplicate()" << endl;
}

void Test_FindFirstUnique() {
   cout << "Started testing Test_FindFirstUnique()" << endl;
   // Positive testing
   char str[] { "hehewoo" };
   cout << "Setting str = " << str << endl;
   char ret = FindFirstUnique(str);
   assert(ret == 'w');
   cout << "FindFirstUnique(str) returns " << ret << endl;
   // Negative testing
   char str2[] { };
   assert(FindFirstUnique(str2) == '\0');
   cout << "Done testing Test_FindFirstUnique()" << endl;
}

void Test_FindFirstUniqueUnicode() {
   cout << "Started testing Test_FindFirstUniqueUnicode()" << endl;
   // Positive testing
   wchar_t str[] { 0x0061, 0x8161, 0x0061, 0 };
   wcout << "Setting str = " << str << endl;
   wchar_t ret = FindFirstUniqueUnicode(str);
   assert(ret == 0x8161);
   cout << "FindFirstUnique(str) returns " << ret << endl;
   cout << "Done testing Test_FindFirstUnique()" << endl;
}

void Test_Atoi() {
   cout << "Started testing Test_Atoi()" << endl;
   cout << "Integer string 1234 should be " << Atoi("1234") << endl;
   cout << "Integer string -1234 should be " << Atoi("-1234") << endl;
   assert(Atoi("1234") == 1234);
   assert(Atoi("-1234") == -1234);
   cout << "Done testing Test_Atoi()" << endl;
}

void Test_Itoa() {
   cout << "Started testing Test_Itoa()" << endl;
   cout << "Integer string 1234 should be " << Itoa(1234) << endl;
   cout << "Integer string -1234 should be " << Itoa(-1234) << endl;
   //assert(Itoa(1234) == "1234");
   //assert(Itoa(-1234) == "-1234");
   cout << "Done testing Test_Itoa()" << endl;
}

void Test_WordSeperator() {
   cout << "Started testing Test_WordSeperator()" << endl;
   set<string> dict;
   dict.insert("peanut");
   dict.insert("pea");
   dict.insert("butter");
   dict.insert("is");
   dict.insert("great");
   string test = "xpeanutbutterisgreat";
   cout << "Input string : " << test << endl;
   WordSeperator(test, dict);
   cout << "Output string : " << test << endl;
   cout << "Done testing Test_WordSeperator()" << endl;
}

void Test_RemoveSpaces() {
   cout << "Started testing Test_RemoveSpaces()" << endl;
   string str = "test is fun ";
   RemoveSpaces(str);
   assert(str.find(" ") == string::npos);
   cout << "Done testing Test_RemoveSpaces()" << endl;
}

void Test_Trie() {
   cout << "Started testing Test_Trie()" << endl;
   Trie t;
   t.Push("Airplane");
   t.Push("Aircraft");
   t.Push("Apple");
   t.Push("Zebra");
   t.Push("Air");
   assert(t.Exists("Airplane"));
   assert(t.Exists("Aircraft"));
   assert(t.Exists("Zebra"));
   assert(t.Exists("Human") == false);
   assert(t.Exists("Air"));
   cout << "count match of -Air- : " << t.CountMatches("Air") << endl;
   cout << "count match of -A r- : " << t.CountMatches("A r") << endl;
   cout << "Done testing Test_Trie()" << endl;
}

void Test_PrintMatrixWords() {
   cout << "Started testing Test_PrintMatrixWords()" << endl;
   string matrix[] = { "ate", "sad", "kit", "amo" };
   Trie t;
   t.Push("at");
   t.Push("ate");
   t.Push("sad");
   t.Push("ed");
   t.Push("te");
   t.Push("as");
   t.Push("to");
   t.Push("kit");
   t.Push("ask");
   t.Push("aim");
   PrintMatrixWords(matrix, t, 4);
   cout << "Done testing Test_PrintMatrixWords()" << endl;
}

void Test_UniqueCharacters() {
   cout << "Started testing Test_UniqueCharacters()" << endl;
   string test = "aaabbcde";
   cout << "UniqueCharacters of " << test << " " << UniqueCharacters(test)
         << endl;
   cout << "Done testing Test_UniqueCharacters()" << endl;
}

void Test_UniqueCharactersNoSpace() {
   cout << "Started testing Test_UniqueCharactersNoSpace()" << endl;
   string test = "aaabbcde";
   cout << "UniqueCharacters of " << test << " "
         << UniqueCharactersNoSpace(test) << endl;
   test = "abcde";
   cout << "UniqueCharacters of " << test << " "
         << UniqueCharactersNoSpace(test) << endl;
   cout << "Done testing Test_UniqueCharactersNoSpace()" << endl;
}

void Test_UniqueCharactersCheck() {
   cout << "Started testing Test_UniqueCharactersCheck()" << endl;
   string test = "aaabbcde";
   cout << "UniqueCharacters of " << test << " " << UniqueCharactersCheck(test)
         << endl;
   test = "abcde";
   cout << "UniqueCharacters of " << test << " " << UniqueCharactersCheck(test)
         << endl;
   cout << "Done testing Test_UniqueCharactersCheck()" << endl;
}

void Test_ReverseString() {
   cout << "Started testing Test_ReverseString()" << endl;
   char test[] = "abcdef\0";
   cout << "ReverseString " << test << " : ";
   ReverseString(test);
   cout << test << endl;
   cout << "Done testing Test_ReverseString()" << endl;
}

void Test_Anagram() {
   cout << "Started testing Test_Anagram()" << endl;
   cout << " Is Anagram(\"hahaha\", \"hahaha\") " << Anagram("hahaha", "hahaha")
         << endl;
   cout << " Is Anagram(\"hahahaba\", \"ha\") " << Anagram("hahahaba", "ha")
         << endl;
   cout << "Done testing Test_Anagram()" << endl;
}

void Test_ReplaceSpaces() {
   cout << "Started testing Test_ReplaceSpaces()" << endl;
   cout << "ReplaceSpaces \"a b\" : ";
   char test[] = "a b";
   int length = 3;
   char* newTest = new char[length + 2];
   strncpy(newTest, test, length);
   ReplaceSpaces(newTest, length);
   newTest[length + 3] = '\0';
   cout << newTest << endl;
   cout << "Done testing Test_ReplaceSpaces()" << endl;
}

void Test_CompressString() {
   cout << "Started testing Test_CompressString()" << endl;
   string test = "aaaabbbbccc";
   cout << " Compress of " << test << " " << CompressString(test) << endl;
   test = "abcde";
   cout << " Compress of " << test << " " << CompressString(test) << endl;
   test = "aabbbbcccddda";
   cout << " Compress of " << test << " " << CompressString(test) << endl;
   cout << "Done testing Test_CompressString()" << endl;
}

void Test_IsRotatedSubstring() {
   cout << "Started testing Test_IsRotatedSubstring()" << endl;
   string str1 = "abcd";
   string str2 = "cdab";
   cout << "IsRotatedSubstring(" << str1 << "," << str2 << ") : "
         << IsRotatedSubstring(str1, str2) << endl;
   str2 = "cdabe";
   cout << "IsRotatedSubstring(" << str1 << "," << str2 << ") : "
         << IsRotatedSubstring(str1, str2) << endl;
   cout << "Done testing Test_IsRotatedSubstring()" << endl;
}

void Test_PrintPermutations() {
   cout << "Started testing Test_PrintPermutations()" << endl;
   char a[] = "ABC";
   PrintPermutations(a, 0, 2);
   cout << "Started testing Test_PrintPermutations()" << endl;
}

void Test_CheckPattern() {
   cout << "Started testing Test_CheckPattern()" << endl;
   assert(CheckPattern("a+b", "aaaab") == true);
   assert(CheckPattern("a*b", "aaaab") == true);
   assert(CheckPattern("ab", "ab") == true);
   assert(CheckPattern("ab+c", "abbbbbc") == true);
   assert(CheckPattern("a+b", "b") == false);
   cout << "Done testing Test_CheckPattern()" << endl;
}

void Test_KeepAnagramsTogether() {
   cout << "Start Test_KeepAnagramsTogether()" << endl;
   vector<string> testV;
   testV.push_back("cat");
   testV.push_back("act");
   testV.push_back("tca");
   testV.push_back("tac");
   testV.push_back("chuha");
   testV.push_back("bili");
   testV.push_back("kutta");
   testV.push_back("chat");
   testV.push_back("hat");
   cout << "Before performing : " << endl;
   for (auto str : testV) {
      cout << str << endl;
   }
   KeepAnagramsTogether(testV);
   cout << "After performing : " << endl;
   for (auto str : testV) {
      cout << str << endl;
   }
   cout << "Done Test_KeepAnagramsTogether()" << endl;
}

void Test_FindInSortedStringsWithSpace() {
   cout << "Start Test_FindInSortedStringsWithSpace" << endl;
   vector<string> strV;
   strV.push_back("Aello");
   strV.push_back("");
   strV.push_back("Borld");
   strV.push_back("Corld");
   strV.push_back("");
   strV.push_back("");
   strV.push_back("Zpace");
   cout << "Borld exists : "
         << FindInSortedStringsWithSpace(strV, 0, 6, "Borld") << endl;
   cout << "jojo does not exist : "
         << FindInSortedStringsWithSpace(strV, 0, 6, "jojo") << endl;
   cout << "Done Test_FindInSortedStringsWithSpace" << endl;
}

void Test_LongestPalindrome() {
   cout << "Start Test_LongestPalindrome" << endl;
   string s("baalaabassdfd");
   cout << LongestPalindrome(s) << endl;
   cout << "Done Test_LongestPalindrome" << endl;
}

void Test_FromRoman() {
   cout << "Start Test_FromRoman" << endl;
   cout << "IV " << Roman::FromRoman("IV") << endl;
   cout << "V " << Roman::FromRoman("V") << endl;
   cout << "VI " << Roman::FromRoman("VI") << endl;
   cout << "CV " << Roman::FromRoman("CV") << endl;
   cout << "Done Test_FromRoman" << endl;
}

void Test_ToRoman() {
   cout << "Start Test_ToRoman" << endl;
   cout << "IV " << Roman::ToRoman(4) << endl;
   cout << "V " << Roman::ToRoman(5) << endl;
   cout << "VI " << Roman::ToRoman(6) << endl;
   //cout<<"CV "<<Roman::ToRoman(105)<<endl;
   cout << "Done Test_ToRoman" << endl;
}

void Test_Numeronym() {
   cout << "Start Test_Numeronym" << endl;
   cout << "Numeronym(hello): " << Numeronym("hello") << endl;
   cout << "Numeronym(house): " << Numeronym("house") << endl;
   cout << "Numeronym(de): " << Numeronym("de") << endl;
   cout << "Numeronym(sdfdfdfdf): " << Numeronym("sdfdfdfdf") << endl;
   cout << "Done Test_Numeronym" << endl;
}

void Test_OrganizeAlphaNumStr() {
   cout << "Start Test_OrganizeAlphaNumStr" << endl;
   string str("a1b2c3d4");
   cout << "Before : " << str << endl;
   OrganizeAlphaNumStr(str);
   cout << "After : " << str << endl;
   cout << "Done Test_OrganizeAlphaNumStr" << endl;
}

void Test_Scribble() {
   cout << "Start Test_Scribble" << endl;
   list<string> words;
   words.push_back("stop");
   words.push_back("act");
   words.push_back("cac");
   vector<char> alphas { 'a', 'c', 't' };
   Scribble(words, alphas);
   cout << "Left words" << endl;
   for (auto word : words) {
      cout << word << endl;
   }
   cout << "Done Test_Scribble" << endl;
}

void Test_OneEditApart() {
   cout << "Start Test_OneEditApart" << endl;
   string a1("cat");
   string b1("cat1");
   cout << endl << a1 << " " << b1 << " Result " << OneEditApart(&a1, &b1);
   a1 = "cbp";
   b1 = "aaa";
   cout << endl << a1 << " " << b1 << " Result " << OneEditApart(&a1, &b1);

   cout << endl << "Done Test_OneEditApart" << endl;
}

void Test_Print123To100() {
   cout << endl << "Start Test_Print123To100" << endl;
   Print123To100();
   cout << endl << "Done Test_Print123To100" << endl;
}

void Test_BalanceParenthesis() {
   cout << endl << "Start Test_BalanceParenthesis" << endl;
   string str { "((((((((((((a()b(()c(" };
   cout << "Before balance : " << str << endl;
   BalanceParenthesis(str);
   cout << "After balance : " << str << endl;
   cout << endl << "Done Test_BalanceParenthesis" << endl;
}

void Test_CountTwos() {
   cout << "Start Test_CountTwos" << endl;
   for (int i = 0; i <= 10; ++i) {
      cout << " For " << i << " " << CountTwos(i) << endl;
   }
   cout << "Done Test_CountTwos" << endl;
}

void Test_ReverseStringByWords() {
   cout << "Start Test_ReverseStringByWords" << endl;
   cout << ReverseStringByWords("Hello World.") << endl;
   cout << ReverseStringByWords("Hello World") << endl;
   cout << ReverseStringByWords("Hello") << endl;
   cout << "Done Test_ReverseStringByWords" << endl;
}

void Test_MaxLenSubStrNoDup() {
   cout << "Start Test_MaxLenSubStrNoDup" << endl;
   string str{"abcdefga"};
   cout<<MaxSubStringNoDupSize(str)<<endl;
   cout << "Done Test_MaxLenSubStrNoDup" << endl;
}

void Test_LongestUniqueString() {
   cout << "Start Test_LongestUniqueString" << endl;
   string str("abcdaefg");
   cout<<LongestUniqueString(str)<<endl;
   cout << "Start Test_LongestUniqueString" << endl;
}

void Test_Strings() {
#ifdef TEST_DONE
   Test_Reverse();
   Test_StripWhitespace();
   Test_RemoveDuplicate();
   Test_FindFirstUnique();
   Test_FindFirstUniqueUnicode();
   Test_Atoi();
   Test_Itoa();
   Test_WordSeperator();
   Test_RemoveSpaces();
   Test_PrintMatrixWords();
   Test_UniqueCharacters();
   Test_UniqueCharactersNoSpace();
   Test_UniqueCharactersCheck();
   Test_ReverseString();
   Test_Anagram();
   Test_ReplaceSpaces();
   Test_CompressString();
   Test_IsRotatedSubstring();
   Test_PrintPermutations();
   Test_CheckPattern();
   Test_KeepAnagramsTogether();
   Test_FindInSortedStringsWithSpace();
   Test_LongestPalindrome();
   Test_FromRoman();
   Test_ToRoman();
   Test_Numeronym();
   Test_Trie();
   Test_OrganizeAlphaNumStr();
#endif
   Test_Scribble();
   Test_OneEditApart();
   Test_Print123To100();
   Test_BalanceParenthesis();
   Test_CountTwos();
   Test_ReverseStringByWords();
   Test_MaxLenSubStrNoDup();
   Test_LongestUniqueString();
}

}
