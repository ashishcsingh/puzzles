/*
 * arrays.h
 *
 *  Created on: Mar 4, 2015
 *      Author: acs
 */

#ifndef MAXNOY_ARRAYS_H_
#define MAXNOY_ARRAYS_H_

#include <vector>
#include <string>
#include <mutex>

namespace arrays {
int FindMissingNumber(int array[], int arrayLength, int length);
void PopulateRandomNumbers(int array[], int length);
int FindDuplicateNumber(int array[], int length);
int GetLargestContiguousSum(int array[], int length);
void CombinePositiveNegativePairs(std::vector<int>&);
bool CombineSameSigns(std::vector<int>&);
void LongestStrictlyOrderedSubSequence(std::vector<int>&);
void PrintArray(int data[], int length);
void Shuffle(int numbers[], int length);
int SumTwoLargest(int* anData, int size);
long SumNLargest(int* data, int size, int n);
void DutchSort(int* data, int size);
int CountBits(char* data, int length);
char GetCharForNumber(int, int);
void GeneratePhoneNumbers(int* numbers, int length);
int KLargestElementNxN(const std::vector<std::vector<int>>& matrix, int k);
int GetMinElemNxN(const std::vector<std::vector<int>>& matrix,
      std::vector<int>& colCtr);
int MagicNumber(const int data[], int length);
int MagicNumberWithDup(const int data[], int length);
std::vector<std::vector<int>> Subsets(const std::vector<int> set);
std::vector<std::string> Permutations(const std::string& s);
std::vector<std::string> BuildParenthesis(int count);
void PrintScreen(std::vector<std::vector<int>>&, int x, int y, int color);
const static int MAX_QUEENS = 8;
void EightQueens(int row, std::vector<int>& col,
      std::vector<std::vector<int>>& results);
void MergeSortLargeAToB(int A[], int lenA, int B[], int lenB);
void MergeSortedArrays(int data[], int start1, int end1, int start2, int end2);
int Partition(int data[], int start, int end);
void QuickSort(int data[], int start, int end);
void quickSort(int arr[], int left, int right);
void MergeSort(int data[], int start, int end);
int FindInRotatedSortedArray(int[], int start, int end, int find);
int ReverseNum(int x);
void Merge(int A[], int m, int B[], int n);
void KMaxRepeatedElements(const std::vector<int>& input, int k,
      std::vector<int>& out);
struct Point {
   int x, y, z;
};
void KShortestDistance(const std::vector<Point>& points, int k,
      std::vector<Point>& out);
void PairSumClosestToZero(std::vector<int>& input, std::pair<int, int>& output);
void GetEmployeesForManager(std::vector<std::pair<int, int> >& employeeManagers,
      int manager, std::vector<int>& reporteeDirect,
      std::vector<int>& reporteeIndirect);
void EvenIndicesAsMax(std::vector<int>& input);
void NegativePositiveOrganizer(std::vector<int>& input);
std::vector<int> ShortestPathDjkstras(std::vector<std::vector<int>>& weights,
      int src, int dest);
void PrintDigonalMatrix(std::vector<std::vector<int> >& data);
int Median(int a, int b, int c);
int Median(int a, int b, int c, int min, int max);
void MatrixFillDistanceFromG(std::vector<std::vector<char> >& data);
int MaxRepeatVal(const std::vector<int>& data);

class QueueUsingArray {
public:
   bool Enqueue(int data);
   int Dequeue();
   ~QueueUsingArray();
   QueueUsingArray(int length);
private:
   std::mutex mutex_;
   int* data_ { nullptr };
   int front_ { 0 }, back_ { 0 };
   int length_ { 0 };
};

void ClosestNumbers(const std::vector<std::vector<int>>& in,
      std::vector<int>& out);
void SortIncDecPairs(std::vector<int>& data);

}
#endif /* MAXNOY_ARRAYS_H_ */
