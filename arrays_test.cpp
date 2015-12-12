/*
 * arrays_test.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: acs
 */

#include "arrays.h"

#include <cassert>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <utility>
#include <memory>

namespace arrays {
using namespace std;

void Test_FindMissingNumber() {
   cout << "Started testing Test_FindMissingNumber()" << endl;
   int length = 10;
   int array[length];
   PopulateRandomNumbers(array, length);
   PrintArray(array, length);
   int result = FindMissingNumber(array, length - 1, length);
   cout << "FindMissingNumber() : " << result << endl;
   assert(result == array[length - 1]);
   cout << "Done testing Test_FindMissingNumber()" << endl;
}

void Test_FindDuplicateNumber() {
   cout << "Started testing Test_FindDuplicateNumber()" << endl;
   int length = 10;
   int array[length];
   PopulateRandomNumbers(array, length - 1);
   array[length - 1] = array[rand() % (length - 1)];
   PrintArray(array, length);
   int ret = FindDuplicateNumber(array, length);
   cout << "FindDuplicateNumber() " << ret << endl;
   cout << "Done testing Test_FindDuplicateNumber()" << endl;
}

void Test_GetLargestContiguousSum() {
   cout << "Started testing Test_GetLargestContiguousSum()" << endl;
   //populate random values from -range to range in array[]
   int length = 10;
   int range = 100;
   int array[length];
   for (int i = 0; i < length; ++i) {
      array[i] = (rand() % range) * ((rand() % 2 == 0) ? 1 : -1);
   }
   PrintArray(array, length);
   cout << "GetLargestContiguousSum() : "
         << GetLargestContiguousSum(array, length) << endl;
   cout << "Done testing Test_GetLargestContiguousSum()" << endl;
}

void Test_CombinePositiveNegativePairs() {
   int data[10] = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10 };
   std::vector<int> vectorData(data, data + 10);
   CombinePositiveNegativePairs(vectorData);
   for (auto i : vectorData) {
      cout << " " << i;
   }
   cout << endl;
}

void Test_LongestStrictlyOrderedSubSequence() {
   cout << "Started testing Test_LongestStrictlyOrderedSubSequence()" << endl;
   vector<int> data = { 100, 2, 15, 3, 6, 17, 8, 10, 20 };
   cout << "Before running:" << endl;
   PrintArray(&data[0], data.size());
   LongestStrictlyOrderedSubSequence(data);
   cout << "After running:" << endl;
   PrintArray(&data[0], data.size());
   data = {100, 2, 102, 103, 15, 106, 109, 3, 6, 17, 8, 110, 10, 111, 20};
   cout << "Before running:" << endl;
   PrintArray(&data[0], data.size());
   LongestStrictlyOrderedSubSequence(data);
   cout << "After running:" << endl;
   PrintArray(&data[0], data.size());
   cout << "Done testing Test_LongestStrictlyOrderedSubSequence()" << endl;
}

void Test_Shuffle() {
   cout << "Started testing Shuffle()" << endl;
   int cards[52];
   for (int i = 0; i < 52; i++) {
      cards[i] = i + 1;
   }
   cout << "Before : " << endl;
   PrintArray(cards, 52);
   Shuffle(cards, 52);
   cout << "After : " << endl;
   PrintArray(cards, 52);
   cout << "Done testing Shuffle()" << endl;
}

void Test_SumTwoLargest() {
   cout << "Started Test_SumTwoLargest()" << endl;
   int data[10];
   PopulateRandomNumbers(data, 10);
   PrintArray(data, 10);
   cout << "Test_SumTwoLargest : " << SumTwoLargest(data, 10) << endl;
   cout << "Done Test_SumTwoLargest()" << endl;
}

void Test_SumNLargest() {
   cout << "Started Test_SumNLargest()" << endl;
   int data[10];
   for (int i = 0; i < 10; ++i) {
      data[i] = i;
   }
   PrintArray(data, 10);
   cout << "SumNLargest(data, 10, 3) : " << SumNLargest(data, 10, 3) << endl;
   cout << "Started Test_SumNLargest()" << endl;
}

void Test_DutchSort() {
   cout << "Started Test_DutchSort()" << endl;
   int data[] = { 1, 1, -1, 0, -1, 0 };
   int size = sizeof(data) / sizeof(int);
   cout << "Before: " << endl;
   PrintArray(data, size);
   DutchSort(data, size);
   cout << "After: " << endl;
   PrintArray(data, size);
   cout << "Done Test_DutchSort()" << endl;
}

void Test_CountBits() {
   cout << "Started Test_CountBits()" << endl;
   char data[] = { 'A', 'B', 'C' };
   cout << "CountBits(" << data << ") : " << CountBits(data, sizeof(data))
         << endl;
   cout << "Done Test_CountBits()" << endl;
}

void Test_GeneratePhoneNumbers() {
   cout << "Started Test_GeneratePhoneNumbers()" << endl;
   int numbers[] = { 1, 4, 5, 6 };
   assert(GetCharForNumber(0, 1) == '0');
   assert(GetCharForNumber(1, 1) == '1');
   assert(GetCharForNumber(2, 1) == 'A');
   assert(GetCharForNumber(6, 2) == 'N');
   GeneratePhoneNumbers(numbers, sizeof(numbers) / sizeof(int));
   cout << "Done Test_GeneratePhoneNumbers()" << endl;
}

void Test_KLargestElementNxN() {
   cout << "Started Test_KLargestElementNxN()" << endl;
   vector<vector<int>> data;
   int counter = 0;
   for (int i = 0; i < 10; ++i) {
      data.push_back(vector<int>());
      for (int j = 0; j < 10; ++j) {
         data[i].push_back(++counter);
      }
   }
   cout << "KLargestElementNxN is : " << KLargestElementNxN(data, 5) << endl;
   cout << "Done Test_KLargestElementNxN()" << endl;
}

void Test_MagicNumber() {
   cout << "Started Test_MagicNumber()" << endl;
   int data[] = { -5, -3, -2, -1, 4, 6, 8 };
   int length = sizeof(data) / sizeof(int);
   cout << "MagicNumber should be 4 :" << MagicNumber(data, length) << endl;
   cout << "Done Test_MagicNumber()" << endl;
}

void Test_MagicNumberWithDup() {
   cout << "Started Test_MagicNumber()" << endl;
   int data[] = { -5, -3, -3, -2, -1, 5, 6, 8 };
   int length = sizeof(data) / sizeof(int);
   cout << "MagicNumber should be 5 :" << MagicNumberWithDup(data, length)
         << endl;
   cout << "Done Test_MagicNumberWithDup()" << endl;
}

void Test_Subsets() {
   cout << "Started Test_Subsets()" << endl;
   vector<int> set;
   for (int i = 0; i < 5; ++i) {
      set.push_back(i + 1);
   }
   vector<vector<int> > powerSet = Subsets(set);
   for (auto i : powerSet) {
      for (auto j : i) {
         cout << " " << j;
      }
      cout << endl;
   }
   cout << "Done Test_Subsets()" << endl;
}

void Test_Permutations() {
   cout << "Start Test_Permutations()" << endl;
   string s = "abcd";
   vector<string> permutations = Permutations(s);
   for (auto unit : permutations) {
      cout << unit << endl;
   }
   cout << "Done Test_Permutations()" << endl;
}

void Test_BuildParenthesis() {
   cout << "Start Test_Permutations()" << endl;
   vector<string> ret = BuildParenthesis(2);
   for (auto s : ret) {
      cout << s << endl;
   }
   cout << "Done Test_Permutations()" << endl;
}

void Test_PrintScreen() {
   cout << "Start Test_PrintScreen()" << endl;
   vector<vector<int>> screen;
   for (int y = 0; y < 20; ++y) {
      screen.push_back(vector<int>(20, 0));
   }
   for (auto y : screen) {
      for (auto x : y) {
         cout << x << " ";
      }
      cout << endl;
   }
   PrintScreen(screen, 0, 0, 5);
   cout << "After printing " << endl;
   for (auto y : screen) {
      for (auto x : y) {
         cout << x << " ";
      }
      cout << endl;
   }
   cout << "Done Test_PrintScreen()" << endl;
}

void Test_EightQueens() {
   cout << "Start Test_EightQueens()" << endl;
   vector<int> cols(8);
   vector<vector<int>> results;
   EightQueens(0, cols, results);
   for (auto v : results) {
      cout << "Set : " << endl;
      for (auto i : v) {
         cout << " " << i;
      }
      cout << endl;
   }
   cout << "Done Test_EightQueens()" << endl;
}

void Test_MergeSortLargeAToB() {
   cout << "Start Test_MergeSortLargeAToB()" << endl;
   int A[10] = { 3, 6, 7, 8, 9 };
   int B[5] = { 0, 1, 2, 3, 4 };
   MergeSortLargeAToB(A, 10, B, 5);
   for (int i = 0; i < 10; ++i) {
      cout << A[i] << " ";
   }
   cout << endl;
   cout << "Done Test_MergeSortLargeAToB()" << endl;
}

void Test_FindInRotatedSortedArray() {
   cout << "Start Test_FindInRotatedSortedArray()" << endl;
   int data[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
   int len = sizeof(data) / sizeof(int);
   cout << "Found at location : "
         << FindInRotatedSortedArray(data, 0, len - 1, 6) << endl;
   cout << "Done Test_FindInRotatedSortedArray()" << endl;
}

void Test_Merge() {
   cout << "Start Test_Merge()" << endl;
   int A[] = { -1, 0, 0, 3, 3, 3 };
   int B[] = { 3, 4, 7 };
   Merge(A, 3, B, 3);
   for (int i = 0; i < 6; ++i) {
      cout << A[i] << " ";
   }
   cout << endl << "Done Test_Merge()" << endl;
}

void Test_ReverseNum() {
   cout << "Start Test_ReverseNum()" << endl;
   cout << "ReverseNum(-23) : " << ReverseNum(-23) << endl;
   cout << "ReverseNum(23) : " << ReverseNum(23) << endl;
   cout << "ReverseNum(-2334) : " << ReverseNum(-2334) << endl;
   cout << "Done Test_ReverseNum()" << endl;
}

void Test_KMaxRepeatedElements() {
   cout << "Start Test_KMaxRepeatedElements()" << endl;
   vector<int> input;
   vector<int> output;
   input.push_back(1);
   input.push_back(1);

   input.push_back(2);
   input.push_back(2);
   input.push_back(2);

   input.push_back(3);
   input.push_back(3);
   KMaxRepeatedElements(input, 2, output);
   cout << " Max K=2 elements : " << endl;
   for (auto i : output) {
      cout << i << endl;
   }
   cout << "Done Test_KMaxRepeatedElements()" << endl;
}

void Test_KShortestDistance() {
   cout << "Start Test_KShortestDistance()" << endl;
   vector<Point> input, output;
   for (int i = 1; i < 6; ++i) {
      Point p = { i, i, i };
      input.push_back(p);
   }
   KShortestDistance(input, 2, output);
   for (Point p : output) {
      cout << "Output " << p.x << " " << p.y << " " << p.z << endl;
   }
   cout << "Done Test_KShortestDistance()" << endl;
}

void Test_PairSumClosestToZero() {
   cout << "Start Test_PairSumClosestToZero()" << endl;
   int in[] = { -1, -2, -5, -6, 9, 8 };
   vector<int> input(in, in + 6);
   pair<int, int> output;
   PairSumClosestToZero(input, output);
   cout << "Output " << output.first << " " << output.second << endl;
   cout << "Done Test_PairSumClosestToZero()" << endl;
}

void Test_GetEmployeesForManager() {
   cout << "Start Test_GetEmployeesForManager()" << endl;
   vector<pair<int, int> > emPairs;
   for (int i = 0; i < 10; ++i) {
      pair<int, int> em { i, i + 2 };
      emPairs.push_back(em);
      em = {i, i+1};
      emPairs.push_back(em);
   }
   vector<int> direct;
   vector<int> indirect;
   GetEmployeesForManager(emPairs, 5, direct, indirect);
   cout << "Direct reportees : ";
   for (auto em : direct) {
      cout << em << " ";
   }
   cout << endl;
   cout << "Indirect reportees : ";
   for (auto em : indirect) {
      cout << em << " ";
   }
   cout << endl;
   cout << "Done Test_GetEmployeesForManager()" << endl;
}

void Test_EvenIndicesAsMax() {
   cout << "Start Test_EvenIndicesAsMax()" << endl;
   int data[] = { 1, 4, 5, 2, 3 };
   vector<int> input(data, data + sizeof(data) / sizeof(int));
   EvenIndicesAsMax(input);
   for (auto i : input) {
      cout << i << "";
   }
   cout << endl;
   cout << "Done Test_EvenIndicesAsMax()" << endl;
}

void Test_NegativePositiveOrganizer() {
   cout << "Start Test_NegativePositiveOrganizer()" << endl;
   int data[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
   vector<int> input(data, data + sizeof(data) / sizeof(int));
   NegativePositiveOrganizer(input);
   for (auto i : input) {
      cout << i << " ";
   }
   cout << endl;
   cout << "Done Test_NegativePositiveOrganizer()" << endl;
}

void Test_PrintDigonalMatrix() {
   cout << "Start Test_PrintDigonalMatrix()" << endl;
   vector<vector<int>> data;
   int k = 1;
   for (int i = 0; i < 3; ++i) {
      data.push_back(vector<int>());
      for (int j = 0; j < 3; ++j) {
         data[i].push_back(k);
         ++k;
      }
   }
   PrintDigonalMatrix(data);
   cout << "Done Test_PrintDigonalMatrix()" << endl;
}

void Test_Median() {
   cout << "Start Test_Median()" << endl;
   int a = 1, b = 2, c = 3;
   cout << Median(a, b, c) << endl;
   cout << Median(a, b, c, 1, 3) << endl;
   cout << "Done Test_Median()" << endl;
}

void Test_MatrixFillDistanceFromG() {
   cout << "Start Test_MatrixFillDistanceFromG()" << endl;
   vector<vector<char>> data = { { '0', '0', '0' }, { 'B', 'G', 'G' }, { 'B',
         '0', '0' } };
   cout << "Before" << endl;
   for (unsigned i = 0; i < data.size(); ++i) {
      for (unsigned j = 0; j < data.size(); ++j) {
         cout << data[i][j] << ", ";
      }
      cout << endl;
   }
   MatrixFillDistanceFromG(data);
   cout << "After" << endl;
   for (unsigned i = 0; i < data.size(); ++i) {
      for (unsigned j = 0; j < data.size(); ++j) {
         if (data[i][j] == 'B' || data[i][j] == 'G') {
            cout << data[i][j] << ", ";
         } else {
            cout << to_string(data[i][j]) << ", ";
         }
      }
      cout << endl;
   }
   cout << "Done Test_MatrixFillDistanceFromG()" << endl;
}

void Test_MaxRepeatVal() {
   cout << "Start Test_MaxRepeatVal()" << endl;
   vector<int> data { 1, 2, 3, 4, 4, 5, 6 };
   cout << "MaxRepeatVal: " << MaxRepeatVal(data) << endl;
   cout << "Done Test_MaxRepeatVal()" << endl;
}

void Test_QueueUsingArray() {
   cout << "Start Test_QueueUsingArray()" << endl;
   QueueUsingArray q(5);
   for (int i = 1; i < 5; ++i) {
      cout << "Enqueing " << i << " : " << q.Enqueue(i) << endl;
   }
   //q.Dequeue();
   //q.Enqueue(6);
   //q.Dequeue();
   //q.Enqueue(7);
   cout << endl;
   for (int i = 1; i < 5; ++i) {
      cout << "Dequeing : " << q.Dequeue() << endl;
   }
   cout << "Done Test_QueueUsingArray()" << endl;
}

void Test_SortIncDecPairs() {
   cout << "Start Test_SortIncDecPairs()" << endl;
   vector<int> data { 1, 2, 3, 4, 5, 6 };
   SortIncDecPairs(data);
   for (auto val : data) {
      cout << val << " ";
   }
   cout << endl;
   cout << "Done Test_SortIncDecPairs()" << endl;
}

void Test_MergeSort() {
   cout << "Start Test_MergeSort()" << endl;
   int data[] {5, 4, 3 , 2, 1};
   cout<<"before: "<<endl;
   for(int i=0; i<5; ++i ) {
      cout << data[i]<< " ";
   }
   MergeSort(data, 0, 4);
   cout<<endl<<"after: "<<endl;
   for(int i=0; i<5; ++i ) {
      cout << data[i]<< " ";
   }
   cout<<endl;
   cout << "Done Test_MergeSort()" << endl;
}

void Test_QuickSort() {
   cout << "Start Test_QuickSort()" << endl;
   int data[] {5, 4, 3 , 2, 1};
   cout<<"before: "<<endl;
   for(int i=0; i<5; ++i ) {
      cout << data[i]<< " ";
   }
   QuickSort(data, 0, 4);
   cout<<endl<<"after: "<<endl;
   for(int i=0; i<5; ++i ) {
      cout << data[i]<< " ";
   }
   cout<<endl;
   cout << "Done Test_QuickSort()" << endl;
}

void Test_FindMissingNum() {
   cout << "Start Test_FindMissingNum()" << endl;
   vector<int> data {1,3,6,4,1,2};
   cout <<"The missing one is : "<<FindMissingNum(data)<<endl;
   cout << "Done Test_FindMissingNum()" << endl;
}


void Test_Queue_Round() {
   cout << "Start Test_Queue_Round()" << endl;
   QueueRound q(100);
   const char *c = {"Data to copy"};
   q.Enque(c, 12);
   char* d = new char[13];
   q.Deque(d, 12);
   d[12] = '\0';
   cout<<d<<endl;
   cout << "Done Test_Queue_Round()" << endl;
}

void Test_CounterWithMax() {
   cout << "Start Test_CounterWithMax()" << endl;
   vector<int> data {1,3,6,4,1,2};
   cout <<"The missing one is : "<<endl;
   auto output = CounterWithMax(5, data);
   for(auto o: output) {
      cout<<o<<" ";
   }
   cout <<endl<< "Done Test_CounterWithMax()" << endl;
}

void Test_CountUniques() {
   cout << "Start Test_CountUniques()" << endl;
   vector<int> data {1,3,6,4,1,2};
   cout<<"Unique elements : "<<CountUniques(data);
   cout <<endl<< "Done Test_CountUniques()" << endl;
}

void Test_FindMaxSumInRange() {
   cout << "Start Test_FindMaxSumInRange()" << endl;
   vector<int> data {1,-3,6,-4,1,2};
   cout<<"MaxRange is : "<<FindMaxSumInRange(data);
   cout <<endl<< "Done Test_FindMaxSumInRange()" << endl;
}

void Test_MinPerimeterForArea() {
   cout << "Start Test_MinPerimeterForArea()" << endl;
   int area = 36;
   cout<<"MinPerimeter for "<<area<<" is : "<<MinPerimeterForArea(area);
   cout <<endl<< "Done Test_MinPerimeterForArea()" << endl;
}


void Test_CountFactors() {
   cout << "Start Test_CountFactors()" << endl;
   int N = 8;
   cout<<"MinPerimeter for "<<N<<" is : "<<CountFactors(N);
   cout <<endl<< "Done Test_CountFactors()" << endl;
}



void Test_FindAllSubPrimes() {
   cout << "Start Test_FindAllSubPrimes()" << endl;
   vector<int> P{3,4,8};
   vector<int> Q{10, 20, 20};
   cout<<"Results: ";
   auto&& results = FindAllSubPrimes(25, P, Q);
   for(auto r: results) {
      cout<<r<<" ";
   }
   cout << endl<<"Done Test_FindAllSubPrimes()" << endl;
}

void Test_Array2D() {
   cout << "Start Test_Array2D()" << endl;
   Array2D<int> a(10);
   a[4][8] = 10;
   cout<<a[4][8]<<endl;
   cout << "Done Test_Array2D()" << endl;
}

void Test_Array2DC() {
   cout << "Start Test_Array2DC()" << endl;
   Array2DC<int> a(10);
   a[4][8] = 10;
   cout<<a[4][8]<<endl;
   cout << "Done Test_Array2DC()" << endl;
}

void Test_Maximize() {
   cout << "Start Test_Maximize()" << endl;
   vector<int> arr{3,1,4,5,6};
   vector<int> rep{1,9,5,2,3};
   Maximize(arr, rep);
   for(auto a: arr) {
      cout<<a<<" ";
   }
   cout<<endl;
   cout << "Done Test_Maximize()" << endl;
}

void Test_MakeAllRowAndColZero() {
   cout << "Start Test_MakeAllRowAndColZero()" << endl;
   vector<vector<int>> m;
   for(int i= 0; i<5; ++i) {
      m.push_back(vector<int>(5));
      for(int j= 0; j<5; ++j) {
         m[i][j] = rand() % 100 + 1;
      }
   }
   m[3][2] = 0;
   cout<<endl<<"Before: "<<endl;
   for(auto& r: m) {
      for(auto& e: r) {
         cout<<e<<" ";
      }
      cout<<endl;
   }
   MakeAllRowAndColZero(m);
   cout<<endl<<"After:"<<endl;
   for(auto& r: m) {
      for(auto& e: r) {
         cout<<e<<" ";
      }
      cout<<endl;
   }
   cout<<"Done Test_MakeAllRowAndColZero()"<<endl;
}


void Test_MinRange() {
   cout<<"Start Test_MinRange()"<<endl;
   vector<vector<int>> arrays;
   for(int i=0; i<5; ++i) {
      arrays.push_back(vector<int>(5));
   }
   cout<<endl<<"Input array : "<<endl;
   for(int i=0; i<5; ++i) {
      for(int j=0; j<5; ++j) {
         arrays[i][j] = (i + 1) * (j + 2) + 1;
         cout<<arrays[i][j]<<" ";
      }
      cout<<endl;
   }
   int min, max;
   MinRange(arrays, min, max);
   cout<<endl<<"Range "<<min<<","<<max<<endl;
   cout<<"Done Test_MinRange()"<<endl;
}


void Test_Heaps() {
   cout<<"Start Test_Heaps()"<<endl;
   // Min Heap testing.
   unique_ptr<Heap<int>> hmin(new MinHeap<int>);
   for(int i=0; i<10; ++i) {
      hmin->Push(i);
   }
   cout<<"0 to 9 for minheap is "<<endl;
   for(int i=0; i<10; ++i) {
      cout<<hmin->Top()<<" ";
      hmin->Pop();
   }
   // Max Heap testing.
   unique_ptr<Heap<int>> hmax(new MaxHeap<int>);
   for(int i=0; i<10; ++i) {
      hmax->Push(i);
   }
   cout<<endl<<"0 to 9 for maxheap is "<<endl;
   for(int i=0; i<10; ++i) {
      cout<<hmax->Top()<<" ";
      hmax->Pop();
   }
   cout<<endl;
   cout<<"Done testing Test_Heaps()"<<endl;
}


void Test_RepeatCounts() {
   cout<<"Start Test_RepeatCounts()"<<endl;
   vector<int> repeation {4, 5, 6, 9};
   auto rc = RepeatCounts(repeation);
   for(auto& p : rc) {
      cout<<"Number "<<p.first<<" repeated "<<p.second<<endl;
   }
   cout<<"Done Test_RepeatCounts()"<<endl;
}

void Test_MaxProfit() {
   cout<<"Start Test_MaxProfit()"<<endl;
   vector<int> stocks {4, 6, 1, 9, 3};
   cout<<MaxProfit(stocks)<<endl;
   cout<<"Done Test_MaxProfit()"<<endl;
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
   Test_FindInRotatedSortedArray();
   Test_Merge();
   Test_ReverseNum();
   Test_KMaxRepeatedElements();
   Test_KShortestDistance();
   Test_PairSumClosestToZero();
   Test_GetEmployeesForManager();
   Test_EvenIndicesAsMax();
   Test_NegativePositiveOrganizer();
   Test_PrintDigonalMatrix();
   Test_Median();
   Test_MatrixFillDistanceFromG();
   Test_MaxRepeatVal();
   Test_QueueUsingArray();
   Test_SortIncDecPairs();
   Test_MergeSort();
   Test_QuickSort();
   Test_FindMissingNum();
   Test_CounterWithMax();
   Test_CountUniques();
   Test_FindMaxSumInRange();
   Test_MinPerimeterForArea();
   Test_CountFactors();
   Test_FindAllSubPrimes();
   Test_Queue_Round();
   Test_Array2D();
   Test_Array2DC();
#endif
   Test_Maximize();
   Test_MakeAllRowAndColZero();
   Test_MinRange();
   Test_Heaps();
   Test_RepeatCounts();
   Test_MaxProfit();
}
}

