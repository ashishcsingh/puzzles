/*
 * arrays.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: acs
 */

#include "arrays.h"
#include "log.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <map>
#include <list>
#include <climits>
#include <utility>

namespace arrays {
using namespace std;

/*
 * What:  1,2,3,5,6 returns 4
 * How:  Sum n*n+1/2 - all elems
 */
int FindMissingNumber(int array[], int arrayLength, int length) {
   int sum = length * (length + 1) / 2;
   for (int i = 0; i < arrayLength; ++i) {
      sum -= array[i];
   }
   return sum;
}

void PopulateRandomNumbers(int array[], int length) {
   for (int i = 0; i < length; ++i) {
      array[i] = i + 1;
   }
   srand(time(NULL));
   for (int i = 0; i < length; ++i) {
      std::swap(array[i], array[rand() % length]);
   }
}

/*
 * What: 1,2,3,4,5,4 => 4
 * How:  Inserts content into a new set
 *       when there is any failure inserting then return that #.
 */
int FindDuplicateNumber(int array[], int length) {
   std::set<int> arraySet;
   std::pair<std::set<int>::iterator, bool> ret;
   for (int i = 0; i < length; ++i) {
      ret = arraySet.insert(array[i]);
      //couldn't insert in set that means it is a duplicate
      if (ret.second == false) {
         return *ret.first;
      }
   }
   return 0;
}

/*
 * What: 4 5 -1 3 -8 2 => 11
 *       Contiguous max sum is computed and returned
 * How: 1. combine all same signs
 *      2. combine +- pairs
 *      3. repeat 1 and 2 till no change can be done
 *      4. find the max
 */
int GetLargestContiguousSum(int array[], int length) {
   bool changing = false;
   std::vector<int> data(array, array + length);
   do {
      changing = CombineSameSigns(data);
      CombinePositiveNegativePairs(data);
   } while (changing);
   int max = 0;
   for (auto val : data) {
      if (val > max) {
         max = val;
      }
   }
   return max;
}

bool CombineSameSigns(std::vector<int>& data) {
   if (data.size() <= 1) {
      return false;
   }
   bool changed = false;
   int j = 0;
   std::vector<int> newData;
   newData.push_back(data[0]);
   for (int i = 1; i < data.size(); i++) {
      //data[i] is negative
      if (data[i] < 0) {
         //Both negative, sum it
         if (newData[j] < 0) {
            changed = true;
            newData[j] += data[i];
         } else {
            //Old value is positive
            j++;
            newData.push_back(data[i]);
         }
      } else {
         //Both positive, sum it
         if (newData[j] > 0) {
            changed = true;
            newData[j] += data[i];
         } else {
            j++;
            newData.push_back(data[i]);
         }
      }
   }
   data = newData;
   std::cout << "After CombineSameSigns";
   PrintArray(&data[0], data.size());
   return changed;
}

/*
 * What:    shuffle[]
 * How:     swap the last-- with rand % last
 */
void Shuffle(int numbers[], int length) {
   int i = length - 1;
   srand(time(NULL));
   //Swap the last element with a random number
   while (i > 0) {
      std::swap(numbers[(rand() % i)], numbers[i]);
      --i;
   }
}

/*
 * What: 5 -2 6 -7 => (5-2),(6-7) = 3,-1
 * How: Do consider n[i] + n[i+1] + n[i+2] > n[i]
 */
void CombinePositiveNegativePairs(std::vector<int>& data) {
   if (data.size() < 2) {
      return;
   }
   std::vector<int> newData;
   int i = 0;
   while (i < data.size()) {
      if ((data[i] > 0) && (i + 2 < data.size())
            && (data[i] + data[i + 1] + data[i + 2] > data[i])) {
         newData.push_back(data[i] + data[i + 1] + data[i + 2]);
         i += 3;
      } else {
         newData.push_back(data[i]);
         i += 1;
      }
   }
   data = newData;
   std::cout << "After CombinePositiveNegativePairs";
   PrintArray(&data[0], data.size());
}

bool comparatorFirst(std::pair<int, int> a, std::pair<int, int> b) {
   return a.first < b.first;
}

bool comparatorSecond(std::pair<int, int> a, std::pair<int, int> b) {
   return a.first < b.first;
}

// Not the solution
void LongestStrictlyOrderedSubSequence(std::vector<int>& data) {
   std::vector<std::pair<int, int>> container;
   int i = 1;
   for (auto val : data) {
      std::pair<int, int> valPair { val, i++ };
      container.push_back(valPair);
   }
   std::sort(container.begin(), container.end(), comparatorFirst);
   for (auto i : container) {
      std::cout << " first " << i.first << " second " << i.second << std::endl;
   }
   std::vector<int> output;
   int current = container[0].second;
   output.push_back(current);
   for (int i = 1; i < container.size(); ++i) {
      if (current < container[i].second) {
         current = container[i].second;
         output.push_back(container[i].first);
      }
   }
   data = output;
}

void PrintArray(int array[], int length) {
   using namespace std;
   cout << "Length " << length << endl;
   cout << "Printing array: " << endl;
   for (int i = 0; i < length; ++i) {
      cout << array[i] << " ";
   }
   cout << endl;
}

/*
 * What: SumTwoLargest
 * How:  oldMax takes Max when max swaps the bigger #
 *
 */
int SumTwoLargest(int* data, int size) {
   if (size <= 0 || data == nullptr) {
      return -1;
   }
   int oldMax = data[0], max = data[0];
   for (int i = 1; i < size; ++i) {
      if (max < data[i]) {
         oldMax = max;
         max = data[i];
      }
   }
   return max + oldMax;
}

/*
 * Sort arrays of 3 ints (-1,0,1)
 */
void DutchSort(int* data, int size) {
   int i = 0, j = 0, k = size - 1;

   while (j <= k) {
      // First category
      if (data[j] == -1) {
         std::swap(data[i], data[j]);
         i++;
         j++;
         //Second category
      } else if (data[j] == 0) {
         j++;
         //Third category
      } else {
         std::swap(data[j], data[k]);
         k--;
      }
   }
}

/*
 * What: N Input of # ranging from 0 - 9
 *    Find sum of max N digits
 * How: Count n*# from 9 to 0
 *
 */
long SumNLargest(int* data, int size, int n) {
   int digits[10];
   memset(digits, 0, 10 * sizeof(int));
   for (int i = 0; i < size; ++i) {
      if (i < 0 && i > 9) {
         return -1;
      }
      digits[data[i]]++;
   }
   long sum = 0;
   for (int i = 9; i >= 0; --i) {
      if (digits[i] > n) {
         sum += n * i;
         return sum;
      } else {
         sum += i * digits[i];
         n -= digits[i];
      }
   }
   return sum;
}

/*
 * What: Count # of set bits
 * How:  Read each bit and keep going left
 */
int CountBits(char* data, int length) {
   int count = 0;
   for (int i = 0; i < length; ++i) {
      for (int j = 0; j < 8; ++j) {
         if (data[i] & 1 << j) {
            ++count;
         }
      }
   }
   return count;
}

/*
 * What: Diadpad #, print all combinations
 * number = 2 and index = 1 then char = A
 */
char GetCharForNumber(int number, int index) {
   if (number < 2 || number > 9) {
      return '0' + number;
   }
   return (number - 2) * 3 + 'A' + index - 1;
}

void GeneratePhoneNumbersRecurse(int* numbers, char* results, int order,
      int length) {
   if (order == length) {
      for (int i = 0; i < length; ++i) {
         std::cout << results[i];
      }
      std::cout << std::endl;
      return;
   }
   for (int i = 1; i <= 3; ++i) {
      results[order] = GetCharForNumber(numbers[order], i);
      GeneratePhoneNumbersRecurse(numbers, results, order + 1, length);
      if (numbers[order] == 0 || numbers[order] == 1) {
         return;
      }
   }
}

void GeneratePhoneNumbers(int* numbers, int length) {
   char results[length + 1];
   GeneratePhoneNumbersRecurse(numbers, results, 0, length);
}

/*
 * What: Given NxN, with elements sorted for each row
 * How:  Keep a column of mins in each row.
 *       Increment that the lowestRow.
 *       Do this for K times
 */
int GetMinElemNxN(const std::vector<std::vector<int>>& matrix,
      vector<int>& colCtr) {
   int min = INT_MAX;
   int lowestRow = 0;
   for (int i = 0; i < matrix.size(); ++i) {
      if (min > matrix[i][colCtr[i]]) {
         min = matrix[i][colCtr[i]];
         lowestRow = i;
      }
   }
   ++colCtr[lowestRow];
   return min;
}
int KLargestElementNxN(const std::vector<std::vector<int>>& matrix, int k) {
   vector<int> colCtr(matrix.size(), 0);
   //k-1 times
   for (int i = 1; i < k; ++i) {
      GetMinElemNxN(matrix, colCtr);
   }
   return GetMinElemNxN(matrix, colCtr);;
}

/*
 * What: Finds data[i] == i where data is array of sort data with no rep
 * How:  Using binary search, if data[i] > i then traverse left from start, mid-1
 *       Else traverse on right from mid+1, end
 *
 */
int MagicNumber(const int data[], int start, int end, int length) {
   if (start > end || start < 0 || end >= length) {
      return -1;
   }
   int mid = (start + end) / 2;
   if (data[mid] == mid) {
      return mid;
   } else if (data[mid] > mid) {
      return MagicNumber(data, start, mid - 1, length);
   } else {
      return MagicNumber(data, mid + 1, end, length);
   }
}
int MagicNumber(const int data[], int length) {
   return MagicNumber(data, 0, length - 1, length);
}

/*
 * What: Finds data[i] == i where data is array of sort data with no rep
 * How:  Using binary search, if data[i] > i then traverse left from start, mid-1
 *       Else traverse on right from mid+1, end
 *       left = min(mid - 1 or midVal)
 *       right = max(mid + 1 or midVal)
 *
 */
int MagicNumberWithDup(const int data[], int start, int end, int length) {
   if (start > end || start < 0 || end >= length) {
      return -1;
   }
   int mid = (start + end) / 2;
   if (data[mid] == mid) {
      return mid;
   } else if (data[mid] > mid) {
      int left = min(mid - 1, data[mid]);
      return MagicNumber(data, start, left, length);
   } else {
      int right = max(mid + 1, data[mid]);
      return MagicNumber(data, right, end, length);
   }
}
int MagicNumberWithDup(const int data[], int length) {
   return MagicNumberWithDup(data, 0, length - 1, length);
}

/*
 * What: k = 101 of set {1,2,3} is {1,3}
 * How: Read bits in K from right to left
 *       and replace that by element
 */
vector<int> IntToSet(int k, vector<int> set) {
   vector<int> out;
   int index = 0;
   for (int i = k; i > 0; i = i >> 1) {
      if (i & 1) {
         out.push_back(set[index]);
      }
      index++;
   }
   return out;
}
/*
 * What: Returns combinations of set
 *       AKA combinations
 * How:  2 power set.size() combinations
 *       For 3 ints : 000 to 111 iterate whenever '1' then replace with element[i]
 */
vector<vector<int>> Subsets(const std::vector<int> set) {
   int max = 1 << set.size();
   vector<vector<int>> powerSet;
   for (int i = 0; i < max; ++i) {
      powerSet.push_back(IntToSet(i, set));
   }
   return powerSet;
}

/*
 * What: Places c at loc of the passed string s
 */
string PlaceCharAtLoc(const string& s, char c, int loc) {
   string start = s.substr(0, loc);
   string end = s.substr(loc);
   return start + c + end;
}

/*
 * What: Computes Permutations
 * How:  Runtime n!
 *       "ab" => "ab" "ba"
 *       "abc" => "cab" bca" abc"
 *       Put c in every previous combination of abc
 */
vector<string> Permutations(const string& s) {
   if (s.size() <= 1) {
      vector<string> ret;
      ret.push_back(s);
      return ret;
   }
   // Get previous permutations for 1 to npos
   vector<string> prevPerms = Permutations(s.substr(1));
   vector<string> perms;
   for (int j = 0; j < prevPerms.size(); ++j) {
      // when s = abc, for bc place a all 0,1,2 positions
      for (int i = 0; i <= prevPerms[j].length(); ++i) {
         perms.push_back(PlaceCharAtLoc(prevPerms[j], s[0], i));
      }
   }
   return perms;
}

/*
 * What: leftPar is count of ( and right is count of )
 *       Build and return that many parenthesis
 * How:  Keep decrementing leftPar and rightParm
 */
void BuildParenthesis(vector<string>& set, char* str, int loc, int leftPar,
      int rightPar) {
   if (leftPar == 0 && rightPar == 0) {
      string s(str, loc);
      set.push_back(s);
      return;
   }
   // At loc place (
   if (leftPar > 0) {
      str[loc] = '(';
      BuildParenthesis(set, str, loc + 1, leftPar - 1, rightPar);
   }
   if (rightPar > leftPar) {
      str[loc] = ')';
      BuildParenthesis(set, str, loc + 1, leftPar, rightPar - 1);
   }

}
/*
 * What: (()) ()() for count = 2
 * How:  Build on top of previous array
 *       Add keep count of leftPar and rightPar
 */
vector<string> BuildParenthesis(int count) {
   vector<string> sets;
   char str[count * 2];
   BuildParenthesis(sets, str, 0, count, count);
   return sets;
}

/*
 * What: void PrintScreen
 *
 * How: Go up, left, right, down and call the same method
 *      int [][]
 */
void PrintScreen(vector<vector<int>>& screen, int x, int y, int color) {
   if (x < 0 || y < 0 || y >= screen.size() || x >= screen[0].size()) {
      return;
   }
   if (screen[y][x] != color) {
      screen[y][x] = color;
      PrintScreen(screen, x - 1, y, color);
      PrintScreen(screen, x + 1, y, color);
      PrintScreen(screen, x, y - 1, color);
      PrintScreen(screen, x, y + 1, color);
   }
}

/*
 * What: CheckQueens(row, col, cols)
 *       All the previous queens are safe
 * How:  No colomn clash and diagnol clash
 */
bool CheckQueens(int row, int col, vector<int>& cols) {
   for (int row2 = row; row2 >= 0; row2--) {
      if (cols[row2] == col) {
         return false;
      }
      int distanceRow = row - row2;
      int distanceCol = abs(cols[row2] - col);
      if (distanceRow == distanceCol) {
         return false;
      }
   }
   return true;
}

/*
 * What: Store results in results of placement of 8 queens in a way don't attack
 *       each other (diagonal and same row).
 * How:  Build a call stack of incrementing possiblities
 *       In a loop of current queen checkOther queens
 */
void EightQueens(int row, vector<int>& cols, vector<vector<int>>& results) {
   if (row == MAX_QUEENS) {
      results.push_back(cols);
   } else {
      for (int col = 0; col < MAX_QUEENS; ++col) {
         if (CheckQueens(row, col, cols)) {
            cols[row] = col;
            EightQueens(row + 1, cols, results);
         }
      }
   }
}


/*
 * What: Merges two parts of the same array
 * How: Move on smaller values and copy the left overs
 */
void MergeSortedArrays(int data[], int start1, int end1, int start2, int end2) {
   int length = end1 - start1 + 1 + end2 - start2 + 1;
   int place[length];
   int i = start1, j = start2, k = 0;
   // Move whatever is less between both the parts
   while (i <= end1 && j <= end2) {
      if(data[i] < data[j]) {
         place[k] = data[i];
         ++i;
      } else {
         place[k] = data[j];
         ++j;
      }
      ++k;
   }
   // Move left overs in the first part
   for(; i <= end1; ++i) {
      place[k] = data[i];
      ++k;
   }
   // Move left overs in the second part
   for(; j <= end2; ++j) {
      place[k] = data[j];
      ++k;
   }
   // Copy place[] to data[]
   for(k=0; k<=(end1 - start1); ++k) {
      data[start1 + k] = place[k];
   }
   int startOfSecondArray = end1 - start1 + 1;
   for(k=0; k<=(end2 - start2); ++k) {
      data[start2 + k] = place[k + startOfSecondArray];
   }

}

/*
 * What: Quick Sort implementation
 * How:  Find a pivot element at center and swap all bigger elems
 *       on left with smaller elem on right then appropriately place
 *       pivot at its right location. This elem is placed at the right
 *       location respective to all elems. Apply the same quick sort around
 *       this new bound that is new pivot for both on left and right.
 */
int Partition(int data[], int start, int end) {
   int pivot = (start + end) / 2;
   int pivotElem = data[pivot];
   int i = start, j = end;
   while(i <= j) {
      // Find ith location that is bigger on left
      while(data[i] <= pivotElem) {
         ++i;
      }
      // Find jth location that is smaller on right
      while(data[j] >= pivotElem) {
         --j;
      }
      // Swap them
      if(i <= j) {
         swap(data[i], data[j]);
         ++i;
         --j;
      }
   }
   return i;
}

/*
 * What: Quick Sort the data
 * How:  Calculate a pivot at center then
 *       quick sort around this new pivot.
 */
void QuickSort(int data[], int start, int end) {
   if(start < end) {
      int pivot = Partition(data, start, end);
      QuickSort(data, start, pivot - 1);
      QuickSort(data, pivot, end);
   }
}

/*
 * What: Merge Sort implementation
 * How: First sort the current data recursively into two arrays
 *      then merge the two sorted arrays back.
 */
void MergeSort(int data[], int start, int end) {
   if(end > start) {
      int center = (end - start) / 2 + start;
      MergeSort(data, start, center);
      MergeSort(data, center + 1, end);
      MergeSortedArrays(data, start, center, center + 1, end);
   }
}

/*
 * What: Merge sorted array A and B and store into A
 * How:  Use merge sort and keep on storing into A
 *    Better means exist below in another method
 *    that is by placing large elements first and also with O(1) memory
 */
void MergeSortLargeAToB(int a[], int lenA, int b[], int lenB) {
   int c[lenA];
   int i = 0, j = 0, k = 0;
   if (lenA < lenB) {
      return;
   }
   while (i < lenA && j < lenB) {
      if (a[i] < b[j]) {
         c[k] = a[i];
         ++i;
         ++k;
      } else {
         c[k] = b[j];
         ++j;
         ++k;
      }
   }
   while (i < lenA) {
      c[k] = a[i];
      ++i;
      ++k;
   }
   while (j < lenB) {
      c[k] = b[j];
      ++j;
      ++k;
   }
   for (int i = 0; i < lenA; ++i) {
      a[i] = c[i];
   }
}

/*
 * What: Merges two sorted arrays into the first array
 * How: Start from back and place the largest number.
 */
void Merge(int A[], int m, int B[], int n) {
   int loc = m + n - 1;
   --m;
   --n;
   for (; m >= 0 && n >= 0;) {
      if (A[m] > B[n]) {
         A[loc] = A[m];
         --m;
      } else {
         A[loc] = B[n];
         --n;
      }
      --loc;
   }
   for (; n >= 0; --n) {
      A[loc] = B[n];
      --loc;
   }
}

/*
 * What: Finds loc of find in rotated sorted array
 * How:  Two options: s < m > e or s > m < e
 *       if s < m
 *          if s < f < m
 *             search(s, m - 1, f)
 *          else
 *             search(m, e, f)
 *       else //m < e
 *          if m < f < e
 *             search(m, e, f)
 *          else
 *             search(s, m - 1, f)
 */
int FindInRotatedSortedArray(int data[], int start, int end, int find) {
   if (start > end) {
      return -1;
   }
   int mid = (start + end) / 2;
   if (data[mid] == find) {
      return mid;
   }
   // when start to mid is sorted
   if (data[start] < data[mid]) {
      if (data[start] <= find && data[mid] >= find) {
         return FindInRotatedSortedArray(data, start, mid - 1, find);
      } else {
         return FindInRotatedSortedArray(data, mid, end, find);
      }
   } else {
      // when mid to end is sorted
      if (data[mid] <= find && data[end] >= find) {
         return FindInRotatedSortedArray(data, mid, end, find);
      } else {
         return FindInRotatedSortedArray(data, start, mid - 1, find);
      }
   }
}

/*
 * What: Reverses the passed num
 * How:  mod and divide by 10 and handle negative
 */
int ReverseNum(int x) {
   int ret = 0;
   bool negative = false;
   if (x < 0) {
      negative = true;
      x *= -1;
   }
   while (x > 0) {
      ret *= 10;
      ret += x % 10;
      x /= 10;
   }
   return negative ? -ret : ret;
}

/*
 * What: Print K Max repeated elements in input
 * How: map<digit,count>
 *      set -1 to count when looking for the highest elemt
 */
void KMaxRepeatedElements(const std::vector<int>& input, int k,
      std::vector<int>& out) {
   map<int, int> digitCountMap;
   for (auto elem : input) {
      digitCountMap[elem]++;
   }
   int max = 0, maxElem;
   for (int i = 0; i < k; ++i) {
      max = 0;
      for (auto p : digitCountMap) {
         if (max < p.second) {
            max = p.second;
            maxElem = p.first;
         }
      }
      out.push_back(maxElem);
      digitCountMap[maxElem] = -1;
   }
}

/*
 * What: KShortestDistance(Points, k)
 * How: compute x*x + y*y + z*z
 *      store distance in another vector
 *      Find min K then set to INT_MAX at that index
 */
void KShortestDistance(const vector<Point>& points, int k, vector<Point>& out) {
   vector<long> distance(points.size());
   for (int i = 0; i < points.size(); ++i) {
      distance[i] = points[i].x * points[i].x + points[i].y * points[i].y
            + points[i].z * points[i].z;
   }
   for (int j = 0; j < k; ++j) {
      long min = INT_MAX, minIndex = 0;
      for (int i = 0; i < distance.size(); ++i) {
         if (min > distance[i]) {
            min = distance[i];
            minIndex = i;
         }
      }
      distance[minIndex] = INT_MAX;
      out.push_back(points[minIndex]);
   }
}

/*
 * What: comparator()
 * How:
 */
bool comparator(int i, int j) {
   return abs(i) < abs(j);
}
/*
 * What: Closest pair sum to zero
 * How: Sort by abs()
 *       When add consecutive #s and find the smallest sum
 */
void PairSumClosestToZero(std::vector<int>& input,
      std::pair<int, int>& output) {
   sort(input.begin(), input.end(), comparator);
   int min = INT_MAX;
   for (int i = 0; i < input.size(); i += 2) {
      int sum = input[i] + input[i + 1];
      if (min > sum) {
         min = sum;
         output.first = input[i];
         output.second = input[i + 1];
      }
   }
}

/*
 * What: Gets all leaf employees reporting to this manager
 * How: Using DFS keep populating employees
 */
void ExtractEmployees(map<int, vector<int> >& employeeManagerMap, int reportee,
      set<int>& employees) {
   if (employeeManagerMap.count(reportee) > 0) {
      for (auto m : employeeManagerMap[reportee]) {
         ExtractEmployees(employeeManagerMap, m, employees);
      }
      employees.insert(reportee);
   }
}

/*
 * What: vector<pair<e,m> >, get all e for m reporting directly
 * How:  map<int,vector<int> >, push_back(e) in map[m]
 *       For reporteeDirect = map[m]
 *       For  reporteeIndirect push_back all map[e] and discard 0
 *
 */
void GetEmployeesForManager(std::vector<std::pair<int, int> >& employeeManagers,
      int manager, std::vector<int>& reporteeDirect,
      std::vector<int>& reporteeIndirect) {
   // map[m] = e(s)
   map<int, vector<int> > employeeManagerMap;
   for (auto em : employeeManagers) {
      if (em.second <= 0) {
         Log(INFO,
               "Skipping bad managers Ids: " + to_string(em.second) + " for "
                     + to_string(em.first));
         continue;
      }
      employeeManagerMap[em.second].push_back(em.first);
   }
   // Direct
   reporteeDirect = employeeManagerMap[manager];
   // Indirect
   set<int> reporteeIndirectSet;
   for (auto em : reporteeDirect) {
      ExtractEmployees(employeeManagerMap, em, reporteeIndirectSet);
   }
   reporteeIndirect.assign(reporteeIndirectSet.begin(),
         reporteeIndirectSet.end());
}

/*
 * What: Given an array Of integers build a new array of integers
 *       such that every 2nd element of the array is
 *       greater than its left and right element.
 *  How: Take 3 elements and check 1,2,3 that 2nd is bigger
 *       Do it till the end with +2 increments
 */
void EvenIndicesAsMax(std::vector<int>& input) {
   for (int i = 1; i < input.size() - 1; i += 2) {
      if (input[i - 1] > input[i]) {
         swap(input[i - 1], input[i]);
      }
      if (input[i] < input[i + 1]) {
         swap(input[i], input[i + 1]);
      }
   }
}

/*
 * What: Even indices set to negatives
 *       Odd indices set to positives
 * How:  From left to right
 *       For even indices incrementing +2
 *       Place negative values with i incrementor incremeting with +1
 *       Similarly do positive numbers with odd indices
 */
void NegativePositiveOrganizer(std::vector<int>& input) {
   int even = 0, odd = 1;
   while (1) {
      while (even < input.size() && input[even] < 0) {
         even += 2;
      }
      while (odd < input.size() && input[odd] > 0) {
         odd += 2;
      }
      if (even < input.size() && odd < input.size()) {
         swap(input[even], input[odd]);
      } else {
         break;
      }
   }
}

/*
 * What: Prints digonal values in a NxN matrix
 *       1,2,3
 *       4,5,6
 *       7,8,9
 *     print:
 *       1
 *       2,4
 *       3,5,7
 *       6,8
 *       9
 *  How: for(k:0 to 2*(n-1)) {
 *          for(i:0 to k) {
 *           if(valid bounds)
 *            print a[i][k-1]
 */
void PrintDigonalMatrix(std::vector<std::vector<int> >& data) {
   int sizeI = data.size() - 1;
   for (int k = 0; k <= 2 * sizeI; ++k) {
      for (int i = 0; i <= k; ++i) {
         if (i <= sizeI && (k - i) <= sizeI) {
            cout << data[i][k - i] << ", ";
         }
      }
      cout << endl;
   }
}

/*
 * What: Median(a,b,c)
 * How:
 */
int Median(int a, int b, int c) {
   if ((a <= b && b <= c) || (a >= b && b >= c)) {
      return b;
   } else if ((a <= c && c <= b) || (c <= a && b <= c)) {
      return c;
   }
   return a;
}

int Median(int a, int b, int c, int min, int max) {
   return a ^ b ^ c ^ min ^ max;
}

/*
 * What: Helper of MatrixFillDistaceFromG
 *       update value @x,y and floodfill around
 */
void UpdateMatrixDistanceFromG(vector<vector<char>>& data, int x, int y,
      char value) {
   int length = data.size() - 1;
   Log(VERBOSE,
         "[UpdateMatrixDistanceFromG] Setting @" + to_string(x) + " "
               + to_string(y) + " data: " + to_string(value));
   if (length < x || length < y || x < 0 || y < 0) {
      return;
   }
   if (data[x][y] == 'G') {
      Log(VERBOSE, "[UpdateMatrixDistanceFromG] Found G");
      if (y - 1 >= 0 && data[x][y - 1] != 'G') {
         UpdateMatrixDistanceFromG(data, x, y - 1, 1);
      }
      if (y + 1 <= length && data[x][y + 1] != 'G') {
         UpdateMatrixDistanceFromG(data, x, y + 1, 1);
      }
      if (x - 1 >= 0 && data[x - 1][y] != 'G') {
         UpdateMatrixDistanceFromG(data, x - 1, y, 1);
      }
      if (x + 1 <= length && data[x + 1][y] != 'G') {
         UpdateMatrixDistanceFromG(data, x + 1, y, 1);
      }
   } else if (data[x][y] == 'B') {
      Log(VERBOSE, "[UpdateMatrixDistanceFromG] Found B");
      return;
   } else if (data[x][y] > value) {
      Log(VERBOSE,
            "[UpdateMatrixDistanceFromG] Setting value: " + to_string(value));
      data[x][y] = value;
      UpdateMatrixDistanceFromG(data, x, y - 1, value + 1);
      UpdateMatrixDistanceFromG(data, x, y + 1, value + 1);
      UpdateMatrixDistanceFromG(data, x - 1, y, value + 1);
      UpdateMatrixDistanceFromG(data, x + 1, y, value + 1);
   }
}

/*
 * What: MatrixFillDistanceFromG
 *       In Matrix fill distance from G
 *       Matrix contains B=block, G=guard, 0=rooms
 *       http://www.careercup.com/question?id=4716965625069568
 * How:  Initialize all 0 to CHAR_MAX
 *
 */
void MatrixFillDistanceFromG(std::vector<std::vector<char>>& data) {
   /*
    * If size is greater than B (66) then it will fail
    * Therefore returning
    */
   if (data.size() > 'B') {
      return;
   }
   // initialize and find all the Gs
   vector<pair<int, int>> allGs;
   int length = data.size();
   Log(VERBOSE,
         "[MatrixFillDistanceFromG] Data received of length "
               + to_string(length));
   for (int i = 0; i < length; ++i) {
      for (int j = 0; j < length; ++j) {
         switch (data[i][j]) {
         case '0':
            data[i][j] = CHAR_MAX;
            break;
         case 'G':
            allGs.push_back(make_pair(i, j));
            break;
         case 'B':
            break;
         default:
            Log(ERROR, "Invalid data " + to_string(data[i][j]));
            return;
         }
      }
   }
   Log(VERBOSE, "[MatrixFillDistanceFromG] done initilization");
   for (auto p : allGs) {
      UpdateMatrixDistanceFromG(data, p.first, p.second, 0);
   }
}
/*
 * What: Finds max repeat val in sorted array
 * http://www.careercup.com/question?id=5104572540387328
 * How:  when data[i] == data[i-1]
 *          set repeatCount++;
 *       if(repeatCount > maxRepeatCount) maxRepeatVal...
 */
int MaxRepeatVal(const std::vector<int>& data) {
   if (data.size() < 1) {
      Log(ERROR, "[MaxRepeatVal] Array size is 0");
      return -1;
   }
   if (data.size() == 1) {
      return data[0];
   }
   int maxRepeatCount = 0, maxRepeatVal, repeatCount = 1, repeatVal;
   for (int i = 1; i < data.size(); ++i) {
      if (data[i] == data[i - 1]) {
         ++repeatCount;
         repeatVal = data[i];
      } else {
         repeatVal = 1;
         repeatVal = data[i];
      }
      if (repeatCount > maxRepeatCount) {
         maxRepeatCount = repeatCount;
         maxRepeatVal = repeatVal;
      }
   }
   return maxRepeatVal;
}

/*
 * What: QueueUsingArray
 *       Thread safe
 *       http://www.careercup.com/question?id=5154240347504640
 */
bool QueueUsingArray::Enqueue(int data) {
   if (((front_ + 1) % length_) == back_) {
      Log(ERROR, "[Enqueue] Queue full");
      return false;
   }
   lock_guard<mutex> lock(mutex_);
   data_[front_ % length_] = data;
   front_ = (front_ + 1) % length_;
   return true;
}
int QueueUsingArray::Dequeue() {
   if (back_ == front_) {
      Log(ERROR, "[Dequeue] Queue empty");
      return -1;
   }
   lock_guard<mutex> lock(mutex_);
   int ret = data_[back_];
   back_ = (back_ + 1) % length_;
   return ret;
}
QueueUsingArray::~QueueUsingArray() {
   delete[] data_;
}
QueueUsingArray::QueueUsingArray(int length) {
   data_ = new int[length + 1];
   length_ = length + 1;
}

int DiffNumbers(const vector<vector<int>>&in, const vector<int>& minIndex) {
   int len = in.size();
   int min = INT_MAX, max = INT_MIN;
   // Among all the arrays, find min and max @minIndex[i]
   for (int i = 0; i < len; ++i) {
      if (min > in[i][minIndex[i]]) {
         min = in[i][minIndex[i]];
      }
      if (max < in[i][minIndex[i]]) {
         max = in[i][minIndex[i]];
      }
   }
   // the range that covers all the elements @minIndex
   return abs(max - min);
}

int minimumArray(const vector<vector<int>>&in, const vector<int>& minIndex) {
   int length = in.size();
   int minArray = 0;
   int min = INT_MAX;
   // Among all the arrays find the lowest minIndex
   for (int i = 0; i < length; ++i) {
      if (min > in[i][minIndex[i]]) {
         min = in[i][minIndex[i]];
         minArray = i;
      }
   }
   return minArray;
}

void ClosestNumbers(const std::vector<std::vector<int>>& in,
      std::vector<int>& out) {
   if (in.size() < 1) {
      return;
   }
   int countInArray = in[0].size();
   int countArrays = in.size();
   out.resize(countArrays);
   vector<int> minIndex(countArrays, 0);
   vector<int> bestMinIndex;
   int bestMinDiff = INT_MAX;
   int diffNumbers, minArray;
   // While tracking best closest range explore through all the elements
   for (int i = 0; i < countInArray; ++i) {
      diffNumbers = DiffNumbers(in, minIndex);
      if (diffNumbers < bestMinDiff) {
         bestMinIndex = minIndex;
         bestMinDiff = diffNumbers;
      }
      // Find the lowest minIndex and increment it
      minArray = minimumArray(in, minIndex);
      minIndex[minArray]++;
   }
   // Copy values to output
   for (int i = 0; i < countArrays; ++i) {
      out[i] = in[i][bestMinIndex[i]];
   }
}

/*
 * What: Sort this way: s1<=s2>=s3<=s4>=s5
 * How:  Read 3 digits and move by 2 digit
 */
void SortIncDecPairs(std::vector<int>& data) {
   for (int i = 0; i < data.size(); i += 2) {
      if (i < data.size() - 2) {
         if (data[i] > data[i + 1]) {
            swap(data[i], data[i + 1]);
         }
         if (data[i + 1] < data[i + 2]) {
            swap(data[i + 1], data[i + 2]);
         }
      } else if (i < data.size() - 1) {
         if (data[i] > data[i + 1]) {
            swap(data[i], data[i + 1]);
         }
      }
   }
}

}

