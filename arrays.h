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
int GetMinElemNxN(const std::vector<std::vector<int>>& matrix, std::vector<int>& colCtr);
int MagicNumber(const int data[], int length);
int MagicNumberWithDup(const int data[], int length);
std::vector<std::vector<int>> Subsets(const std::vector<int> set);
std::vector<std::string> Permutations(const std::string& s);
std::vector<std::string> BuildParenthesis(int count);
void PrintScreen(std::vector<std::vector<int>>&, int x, int y, int color);
const static int MAX_QUEENS = 8;
void EightQueens(int row, std::vector<int>& col, std::vector<std::vector<int>>& results);
void MergeSortLargeAToB(int A[], int lenA, int B[], int lenB);
int FindInRotatedSortedArray(int [], int start, int end, int find);
}
#endif /* MAXNOY_ARRAYS_H_ */
