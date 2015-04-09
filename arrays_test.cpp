/*
 * arrays_test.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: acs
 */

#include "arrays.h"

#include <cassert>
#include <iostream>
#include <cstdlib>
#include <vector>

namespace arrays {
using namespace std;

void Test_FindMissingNumber() {
   cout<<"Started testing Test_FindMissingNumber()"<<endl;
   int length = 10;
   int array[length];
   PopulateRandomNumbers(array, length);
   PrintArray(array, length);
   int result = FindMissingNumber(array, length - 1, length);
   cout<<"FindMissingNumber() : "<<result<<endl;
   assert(result == array[length-1]);
   cout<<"Done testing Test_FindMissingNumber()"<<endl;
}

void Test_FindDuplicateNumber() {
   cout<<"Started testing Test_FindDuplicateNumber()"<<endl;
   int length = 10;
   int array[length];
   PopulateRandomNumbers(array, length-1);
   array[length - 1] = array[rand() % (length - 1)];
   PrintArray(array, length);
   int ret = FindDuplicateNumber(array, length);
   cout<< "FindDuplicateNumber() "<<ret<<endl;
   cout<<"Done testing Test_FindDuplicateNumber()"<<endl;
}

void Test_GetLargestContiguousSum() {
   cout<<"Started testing Test_GetLargestContiguousSum()"<<endl;
   //populate random values from -range to range in array[]
   int length = 10;
   int range = 100;
   int array[length];
   for(int i=0; i<length; ++i) {
      array[i] = (rand()%range) * ((rand()%2==0)?1:-1);
   }
   PrintArray(array, length);
   cout<<"GetLargestContiguousSum() : "<<GetLargestContiguousSum(array, length) << endl;
   cout<<"Done testing Test_GetLargestContiguousSum()"<<endl;
}

void Test_CombinePositiveNegativePairs() {
   int data[10] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
   std::vector<int> vectorData(data, data+10);
   CombinePositiveNegativePairs(vectorData);
   for(auto i:vectorData) {
      cout<<" "<<i;
   }
   cout<<endl;
}

void Test_LongestStrictlyOrderedSubSequence() {
   cout<<"Started testing Test_LongestStrictlyOrderedSubSequence()"<<endl;
   vector<int> data = {100, 2, 15, 3, 6, 17, 8, 10, 20};
   cout<<"Before running:"<<endl;
   PrintArray(&data[0], data.size());
   LongestStrictlyOrderedSubSequence(data);
   cout<<"After running:"<<endl;
   PrintArray(&data[0], data.size());
   data = {100, 2, 102, 103, 15, 106, 109, 3, 6, 17, 8, 110, 10, 111, 20};
   cout<<"Before running:"<<endl;
   PrintArray(&data[0], data.size());
   LongestStrictlyOrderedSubSequence(data);
   cout<<"After running:"<<endl;
   PrintArray(&data[0], data.size());
   cout<<"Done testing Test_LongestStrictlyOrderedSubSequence()"<<endl;
}

void Test_Shuffle() {
   cout<<"Started testing Shuffle()"<<endl;
   int cards[52];
   for(int i=0; i<52; i++) {
      cards[i] = i+1;
   }
   cout<<"Before : "<<endl;
   PrintArray(cards, 52);
   Shuffle(cards, 52);
   cout<<"After : "<<endl;
   PrintArray(cards, 52);
   cout<<"Done testing Shuffle()"<<endl;
}

void Test_SumTwoLargest() {
   cout<<"Started Test_SumTwoLargest()"<<endl;
   int data[10];
   PopulateRandomNumbers(data, 10);
   PrintArray(data, 10);
   cout<<"Test_SumTwoLargest : "<<SumTwoLargest(data, 10)<<endl;
   cout<<"Done Test_SumTwoLargest()"<<endl;
}

void Test_SumNLargest() {
   cout<<"Started Test_SumNLargest()"<<endl;
   int data[10];
   for(int i=0; i<10; ++i) {
      data[i] = i;
   }
   PrintArray(data, 10);
   cout<<"SumNLargest(data, 10, 3) : "<<SumNLargest(data, 10, 3)<<endl;
   cout<<"Started Test_SumNLargest()"<<endl;
}

void Test_DutchSort() {
   cout<<"Started Test_DutchSort()"<<endl;
   int data[] = {1, 1, -1, 0, -1 , 0 };
   int size = sizeof(data)/sizeof(int);
   cout<<"Before: "<<endl;
   PrintArray(data, size);
   DutchSort(data, size);
   cout<<"After: "<<endl;
   PrintArray(data, size);
   cout<<"Done Test_DutchSort()"<<endl;
}

void Test_CountBits() {
   cout<<"Started Test_CountBits()"<<endl;
   char data[] = {'A', 'B', 'C'};
   cout<<"CountBits("<<data<<") : "<<CountBits(data, sizeof(data))<<endl;
   cout<<"Done Test_CountBits()"<<endl;
}

void Test_GeneratePhoneNumbers() {
   cout<<"Started Test_GeneratePhoneNumbers()"<<endl;
   int numbers[] = {1,4,5,6};
   assert(GetCharForNumber(0, 1) == '0');
   assert(GetCharForNumber(1, 1) == '1');
   assert(GetCharForNumber(2, 1) == 'A');
   assert(GetCharForNumber(6, 2) == 'N');
   GeneratePhoneNumbers(numbers, sizeof(numbers)/sizeof(int));
   cout<<"Done Test_GeneratePhoneNumbers()"<<endl;
}

void Test_KLargestElementNxN() {
   cout<<"Started Test_KLargestElementNxN()"<<endl;
   vector<vector<int>> data;
   int counter = 0;
   for(int i=0; i<10; ++i) {
      data.push_back(vector<int>());
      for(int j=0; j<10; ++j) {
         data[i].push_back(++counter);
      }
   }
   cout<<"KLargestElementNxN is : "<<KLargestElementNxN(data, 5)<<endl;
   cout<<"Done Test_KLargestElementNxN()"<<endl;
}

void Test_MagicNumber() {
   cout<<"Started Test_MagicNumber()"<<endl;
   int data[] = {-5, -3, -2, -1, 4, 6, 8};
   int length = sizeof(data)/sizeof(int);
   cout<<"MagicNumber should be 4 :"<<MagicNumber(data, length)<<endl;
   cout<<"Done Test_MagicNumber()"<<endl;
}

void Test_MagicNumberWithDup() {
   cout<<"Started Test_MagicNumber()"<<endl;
   int data[] = {-5, -3, -3, -2, -1, 5, 6, 8};
   int length = sizeof(data)/sizeof(int);
   cout<<"MagicNumber should be 5 :"<<MagicNumberWithDup(data, length)<<endl;
   cout<<"Done Test_MagicNumberWithDup()"<<endl;
}

void Test_Subsets() {
   cout<<"Started Test_Subsets()"<<endl;
   vector<int> set;
   for(int i=0; i<5; ++i) {
      set.push_back(i+1);
   }
   vector<vector<int> > powerSet = Subsets(set);
   for(auto i:powerSet) {
      for(auto j:i) {
         cout<<" "<<j;
      }
      cout<<endl;
   }
   cout<<"Done Test_Subsets()"<<endl;
}

void Test_Permutations() {
   cout<<"Start Test_Permutations()"<<endl;
   string s = "abcd";
   vector<string> permutations = Permutations(s);
   for(auto unit : permutations) {
      cout<<unit<<endl;
   }
   cout<<"Done Test_Permutations()"<<endl;
}

void Test_BuildParenthesis() {
   cout<<"Start Test_Permutations()"<<endl;
   vector<string> ret = BuildParenthesis(2);
   for(auto s: ret) {
      cout<<s<<endl;
   }
   cout<<"Done Test_Permutations()"<<endl;
}

void Test_PrintScreen() {
   cout<<"Start Test_PrintScreen()"<<endl;
   vector<vector<int>> screen;
   for(int y=0; y<20; ++y) {
      screen.push_back(vector<int>(20, 0));
   }
   for(auto y: screen) {
      for(auto x: y) {
         cout<<x<<" ";
      }
      cout<<endl;
   }
   PrintScreen(screen, 0, 0, 5);
   cout<<"After printing "<<endl;
   for(auto y: screen) {
      for(auto x: y) {
         cout<<x<<" ";
      }
      cout<<endl;
   }
   cout<<"Done Test_PrintScreen()"<<endl;
}

void Test_EightQueens() {
   cout<<"Start Test_EightQueens()"<<endl;
   vector<int> cols (8);
   vector<vector<int>> results;
   EightQueens(0, cols, results);
   for(auto v: results) {
      cout<<"Set : "<<endl;
      for(auto i:v) {
         cout<<" "<<i;
      }
      cout<<endl;
   }
   cout<<"Done Test_EightQueens()"<<endl;
}

void Test_MergeSortLargeAToB() {
   cout<<"Start Test_MergeSortLargeAToB()"<<endl;
   int A[10] = {3,6,7,8,9};
   int B[5] = {0,1,2,3,4};
   MergeSortLargeAToB(A, 10, B, 5);
   for(int i=0; i<10; ++i) {
      cout<<A[i]<<" ";
   }
   cout<<endl;
   cout<<"Done Test_MergeSortLargeAToB()"<<endl;
}

void Test_FindInRotatedSortedArray() {
   cout<<"Start Test_FindInRotatedSortedArray()"<<endl;
   int data[] = {5,6,7,8,9,10,1,2,3};
   int len = sizeof(data)/sizeof(int);
   cout<<"Found at location : "<<FindInRotatedSortedArray(data, 0, len - 1, 6)<<endl;
   cout<<"Done Test_FindInRotatedSortedArray()"<<endl;
}

void Test_Arrays() {
#ifdef TEST_DONE
   Test_FindMissingNumber();
   Test_FindDuplicateNumber();
   Test_LongestStrictlyOrderedSubSequence();
   Test_GetLargestContiguousSum();
   Test_Shuffle();
   Test_SumTwoLargest();
   Test_SumNLargest();
   Test_DutchSort();
   Test_CountBits();
   Test_GeneratePhoneNumbers();
   Test_KLargestElementNxN();
   Test_MagicNumber();
   Test_MagicNumberWithDup();
   Test_Subsets();
   Test_Permutations();
   Test_PrintScreen();
   Test_BuildParenthesis();
   Test_EightQueens();
   Test_MergeSortLargeAToB();
#endif
   Test_FindInRotatedSortedArray();
}
}



