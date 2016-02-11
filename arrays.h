/*
 * arrays.h
 *
 *  Created on: Mar 4, 2015
 *      Author: acs
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

#include <vector>
#include <string>
#include <mutex>
#include <new>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <utility>

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
void PrintScreen(std::vector<std::vector<int>>&, unsigned x, unsigned y,
		int color);
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
int FindMaxSumInRange(std::vector<int>& data);
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

/*
 * What: QueueRound implements Queue with rotation
 *       with max size size_.
 * How: 0 ... start_ ... length_ ... size_
 *      length_ can go around.
 *      Max full is when length_ + 1 == start_
 *      Enque will push length_ forward.
 *      Deque will push start_ forward.
 *      Split case is when some data can be copied around.
 */
class QueueRound {
	char* data_;
	unsigned length_;
	unsigned start_;
	unsigned size_;
public:
	QueueRound(unsigned size) :
			length_(0), start_(0), size_(size) {
		try {
			data_ = new char[size_];
		} catch (std::bad_alloc& ba) {
			std::cerr << "Failed to allocate memory " << ba.what();
		}
	}
	unsigned Enque(const char * src, unsigned size) {
		if (size == 0 || size_ == 0 || start_ == length_ + 1) {
			return 0;
		}
		unsigned first = 0;
		if (start_ < length_) {
			// start_ ... length_ ... size_
			first = min(size, size_ - length_);
			std::memcpy(data_ + length_, src, first);
			length_ += first;
			length_ %= size_;
			// Split case
			if (first < size) {
				unsigned second = min(size - first, start_);
				std::memcpy(data_, src + first, second);
				length_ += second;
				length_ %= size_;
				return first + second;
			}
			return first;
		} else {
			// length_ ... start_ ... size_
			first = min(size, length_ - start_ - 1);
			std::memcpy(data_ + length_, src, first);
			length_ += first;
			length_ %= size_;
			return first;
		}
	}
	;

	unsigned Deque(char * dst, unsigned size) {
		if (size == 0 || size_ == 0 || start_ == length_) {
			return 0;
		}
		unsigned first = 0;
		if (start_ < length_) {
			// 0 ... start_ ... length_ .. size_
			first = min(size, length_ - start_);
			std::memcpy(dst, data_ + start_, first);
			start_ += first;
			start_ %= size_;
			return first;
		} else {
			// 0 ... length_ ... start_ ... size_
			first = min(size, size_ - start_);
			std::memcpy(dst, data_ + start_, first);
			start_ += first;
			start_ %= size_;
			// Split case.
			if (first < size) {
				unsigned second = min(size - first, start_ - length_ - 1);
				std::memcpy(dst, data_, second);
				start_ += second;
				start_ %= size_;
				return first + second;
			}
			return first;
		}
	}
	;
protected:
	template<typename T>
	T min(T a, T b) {
		return (a < b) ? a : b;
	}
};

/*
 * What: 2D array
 * How: Using vectors
 */
template<typename T>
class Array2D {
	std::vector<std::vector<T>> data_;
	unsigned size_;
public:
	Array2D(unsigned size) :
			size_(size) {
		for (unsigned i = 0; i < size_; ++i) {
			data_.push_back(std::vector<T>(size_, 0));
		}
	}
	std::vector<T>& operator[](unsigned i) {
		return data_[i];
	}
};

/*
 * What: Two dimensional vector using C style
 * How: Total data will contain size * (T*) and size * T
 *      First size will be header.
 */
template<typename T>
class Array2DC {
	T** header_;
	unsigned size_;
public:
	Array2DC(unsigned size) :
			size_(size) {
		header_ = (T**) malloc(size * sizeof(T*));
		for (unsigned i = 0; i < size; ++i) {
			*(header_ + i) = (T*) malloc(size * sizeof(T));
		}
	}
	T* operator[](unsigned i) {
		return *(header_ + i);
	}
	~Array2DC() {
		for (unsigned i = 0; i < size_; ++i) {
			delete[] *(header_ + i);
		}
		delete[] header_;
	}
};

void ClosestNumbers(const std::vector<std::vector<int>>& in,
		std::vector<int>& out);
void SortIncDecPairs(std::vector<int>& data);
// unorderd number, with one repeating, then find missing.
int FindMissingNum(std::vector<int>& data);

// A non-empty zero-indexed array A of M integers is given. This array represents consecutive operations:
// if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
// if A[K] = N + 1 then operation K is max counter.
std::vector<int> CounterWithMax(int N, std::vector<int>& data);
//Unique elements
int CountUniques(std::vector<int>& data);
// Find min parameter for a rectangle with given area
int MinPerimeterForArea(int area);
int CountFactors(int N);
std::vector<int> FindAllPrimesUsingSieve(int N);
void FindAllSubPrimesInSieve(std::vector<int>& sieve);
int NextPrimeInSieve(std::vector<int>& sieve, int N);
void AddSubPrimesInSieve(std::vector<int>& sieve);
std::vector<int> FindAllSubPrimes(int N, std::vector<int>& P,
		std::vector<int>& Q);
// Maximize values in arr by replacing from rep.
void Maximize(std::vector<int>& arr, std::vector<int>& rep);
// Make all row,col zero for elem is zero in matrix[][].
void MakeAllRowAndColZero(std::vector<std::vector<int>>& m);
//Find minimum range to cover an element from each N rows.
void MinRange(std::vector<std::vector<int>> arrays, int& min, int& max);

// Abstract Heap related classes made from priority_queue.
template<typename T>
class Heap {
public:
	virtual void Push(const T& data)=0;
	virtual const T& Top()=0;
	virtual void Pop()=0;
	virtual ~Heap() {
	}
	;
};

template<typename T>
class MinHeap: public Heap<T> {
	struct Comp {
		bool operator()(const T& l, const T& r) {
			return l > r;
		}
	};
	std::priority_queue<T, std::vector<T>, Comp> pq_;
public:
	virtual void Push(const T& data) {
		pq_.push(data);
	}
	virtual const T& Top() {
		return pq_.top();
	}
	virtual void Pop() {
		pq_.pop();
	}
	virtual ~MinHeap() {
	}
};

template<typename T>
class MaxHeap: public Heap<T> {
	std::priority_queue<T> pq_;
public:
	virtual void Push(const T& data) {
		pq_.push(data);
	}
	virtual const T& Top() {
		return pq_.top();
	}
	virtual void Pop() {
		pq_.pop();
	}
	virtual ~MaxHeap() {
	}
};

std::vector<std::pair<int, int>> RepeatCounts(std::vector<int>& repeats);
int MaxProfit(std::vector<int>& stocks);
int FindMaxDiffSum(const std::vector<int>& list);
// Finds max N elements and returns in decreasing order.
std::vector<int> MaxNElems(const std::vector<int>& nums, int n);
// Finds min N elements and returns in increasing order.
std::vector<int> MinNElems(const std::vector<int>& nums, int n);
// Finds max product of 3 ints.
int MaxThreeProduct(std::vector<int>& nums);
// Finds max sum in a range.
int FindMaxRangeSum(const std::vector<int>& data);
// Finds all path from src to dst point in 2D.
void FindAllPath(int startX, int startY, int destX, int destY,
		std::vector<std::pair<int, int>>& path);
int BinarySearch(const std::vector<int>& data, int value);
}
#endif /* ARRAYS_H_ */
