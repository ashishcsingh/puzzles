/*
 * arrays.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: acs
 */

#include "arrays.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

namespace arrays {
using namespace std;

/*
 * What:  1,2,3,5,6 returns 4
 * How:  Sum n*n+1/2 - all elems
 */
   int FindMissingNumber(int array[], int arrayLength, int length) {
      int sum = length * (length + 1)/2;
      for(int i=0; i<arrayLength; ++i) {
         sum-=array[i];
      }
      return sum;
   }

   void PopulateRandomNumbers(int array[], int length) {
      for(int i=0; i<length; ++i) {
         array[i] = i + 1;
      }
      srand(time(NULL));
      for(int i=0; i<length; ++i) {
         std::swap(array[i], array[rand()%length]);
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
      for(int i=0; i<length; ++i) {
         ret = arraySet.insert(array[i]);
         //couldn't insert in set that means it is a duplicate
         if(ret.second==false) {
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
      std::vector<int> data(array, array+length);
      do {
         changing = CombineSameSigns(data);
         CombinePositiveNegativePairs(data);
      } while(changing);
      int max = 0;
      for(auto val:data) {
         if(val > max) {
            max = val;
         }
      }
      return max;
   }


   bool CombineSameSigns(std::vector<int>& data) {
      if(data.size() <= 1) {
         return false;
      }
      bool changed = false;
      int j = 0;
      std::vector<int> newData;
      newData.push_back(data[0]);
      for(int i=1; i<data.size(); i++) {
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
      std::cout<<"After CombineSameSigns";
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
      while(i > 0) {
         std::swap(numbers[(rand() % i)], numbers[i]);
         --i;
      }
   }

   /*
    * What: 5 -2 6 -7 => (5-2),(6-7) = 3,-1
    * How: Do consider n[i] + n[i+1] + n[i+2] > n[i]
    */
   void CombinePositiveNegativePairs(std::vector<int>& data) {
      if(data.size() < 2) {
         return;
      }
      std::vector<int> newData;
      int i = 0;
      while(i < data.size()) {
         if((data[i] > 0) && (i+2 < data.size()) &&
               (data[i] + data[i+1] + data[i+2] > data[i])) {
            newData.push_back(data[i] + data[i+1] + data[i+2]);
            i+=3;
         } else {
            newData.push_back(data[i]);
            i+=1;
         }
      }
      data = newData;
      std::cout<<"After CombinePositiveNegativePairs";
      PrintArray(&data[0], data.size());
   }

   bool comparatorFirst(std::pair<int, int> a, std::pair<int,int> b) {
      return a.first < b.first;
   }

   bool comparatorSecond(std::pair<int, int> a, std::pair<int,int> b) {
      return a.first < b.first;
   }

   // Not the solution
   void LongestStrictlyOrderedSubSequence(std::vector<int>& data) {
      std::vector<std::pair<int, int>> container;
      int i = 1;
      for(auto val:data) {
         std::pair<int, int> valPair {val, i++};
         container.push_back(valPair);
      }
      std::sort(container.begin(), container.end(), comparatorFirst);
      for(auto i:container) {
         std::cout<<" first "<<i.first<<" second "<<i.second<<std::endl;
      }
      std::vector<int> output;
      int current = container[0].second;
      output.push_back(current);
      for(int i=1; i<container.size(); ++i) {
         if(current < container[i].second) {
            current = container[i].second;
            output.push_back(container[i].first);
         }
      }
      data = output;
   }

   void PrintArray(int array[], int length) {
      using namespace std;
      cout<<"Length "<<length<<endl;
      cout<<"Printing array: "<<endl;
      for(int i = 0; i<length; ++i) {
         cout<<array[i]<<" ";
      }
      cout<<endl;
   }

   /*
    * What: SumTwoLargest
    * How:  oldMax takes Max when max swaps the bigger #
    *
    */
   int SumTwoLargest(int* data, int size) {
      if(size <= 0 || data == nullptr) {
         return -1;
      }
      int oldMax = data[0], max = data[0];
      for(int i=1; i<size; ++i) {
         if(max < data[i]) {
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

      while(j<=k) {
         // First category
         if(data[j] == -1) {
            std::swap(data[i], data[j]);
            i++;
            j++;
         //Second category
         } else if(data[j] == 0) {
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
    * What: Count n*# from 9 to 0
    *
    */
   long SumNLargest(int* data, int size, int n) {
      int digits[10];
      memset(digits, 0, 10*sizeof(int));
      for(int i=0; i<size; ++i) {
         if(i < 0 && i > 9) {
            return -1;
         }
         digits[data[i]]++;
      }
      long sum = 0;
      for(int i=9; i>=0; --i) {
         if(digits[i] > n) {
            sum += n*i;
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
      for(int i=0; i<length; ++i) {
         for(int j=0; j<8; ++j) {
            if(data[i] & 1<<j) {
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
      if(number < 2 || number > 9) {
         return '0' + number;
      }
      return (number - 2) * 3 + 'A' + index - 1;
   }

   void GeneratePhoneNumbersRecurse(int* numbers, char* results, int order, int length) {
      if(order == length) {
         for(int i=0; i<length; ++i) {
            std::cout<<results[i];
         }
         std::cout<<std::endl;
         return;
      }
      for(int i=1; i<=3; ++i) {
         results[order] = GetCharForNumber(numbers[order], i);
         GeneratePhoneNumbersRecurse(numbers, results, order + 1, length);
         if(numbers[order] == 0 || numbers[order] == 1) {
            return;
         }
      }
   }

   void GeneratePhoneNumbers(int* numbers, int length) {
      char results[length+1];
      GeneratePhoneNumbersRecurse(numbers, results, 0, length);
   }

   /*
    * What: Given NxN, with elements sorted for each row
    * How:  Keep a column of mins in each row.
    *       Increment that the lowestRow.
    *       Do this for K times
    */
   int GetMinElemNxN(const std::vector<std::vector<int>>& matrix, vector<int>& colCtr) {
      int min = INT_MAX;
      int lowestRow = 0;
      for(int i=0; i<matrix.size(); ++i) {
         if(min > matrix[i][colCtr[i]]) {
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
      for(int i=1; i<k; ++i) {
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
      if(start > end || start < 0 || end >= length) {
         return -1;
      }
      int mid = (start + end)/2;
      if(data[mid] == mid) {
         return mid;
      } else if(data[mid] > mid) {
         return MagicNumber(data, start, mid - 1, length);
      } else {
         return MagicNumber(data, mid + 1, end, length);
      }
   }
   int MagicNumber(const int data[], int length) {
      return MagicNumber(data, 0, length-1, length);
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
      if(start > end || start < 0 || end >= length) {
         return -1;
      }
      int mid = (start + end)/2;
      if(data[mid] == mid) {
         return mid;
      } else if(data[mid] > mid) {
         int left = min(mid - 1, data[mid]);
         return MagicNumber(data, start, left, length);
      } else {
         int right = max(mid + 1, data[mid]);
         return MagicNumber(data, right, end, length);
      }
   }
   int MagicNumberWithDup(const int data[], int length) {
      return MagicNumberWithDup(data, 0, length-1, length);
   }

   /*
    * What: k = 101 of set {1,2,3} is {1,3}
    * How: Read bits in K from right to left
    *       and replace that by element
    */
   vector<int> IntToSet(int k, vector<int> set) {
      vector<int> out;
      int index = 0;
      for(int i=k; i>0; i = i>>1) {
         if(i & 1) {
            out.push_back(set[index]);
         }
         index++;
      }
      return out;
   }
   /*
    * What: Returns combinations of set.
    * How:  2 power set.size() combinations
    *       For 3 ints : 000 to 111 iterate whenever '1' then replace with element[i]
    */
   vector<vector<int>> Subsets(const std::vector<int> set) {
      int max = 1 << set.size();
      vector<vector<int>> powerSet;
      for(int i=0; i<max; ++i) {
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
      if(s.size() <=1) {
         vector<string> ret;
         ret.push_back(s);
         return ret;
      }
      // Get previous permutations for 1 to npos
      vector<string> prevPerms = Permutations(s.substr(1));
      vector<string> perms;
      for(int j=0; j<prevPerms.size(); ++j) {
         // when s = abc, for bc place a all 0,1,2 positions
         for(int i=0; i<=prevPerms[j].length(); ++i) {
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
   void BuildParenthesis(vector<string>& set, char* str, int loc,
         int leftPar, int rightPar) {
      if(leftPar == 0 && rightPar == 0) {
         string s(str, loc);
         set.push_back(s);
         return;
      }
      // At loc place (
      if(leftPar > 0) {
         str[loc] = '(';
         BuildParenthesis(set, str, loc + 1, leftPar - 1, rightPar);
      }
      if(rightPar > leftPar) {
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
      char str[count*2];
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
      if(x < 0 || y < 0 || y>=screen.size() || x >= screen[0].size()) {
         return;
      }
      if(screen[y][x]!=color) {
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
      for(int row2 = row; row2>=0; row2--) {
         if(cols[row2] == col) {
            return false;
         }
         int distanceRow = row - row2;
         int distanceCol = abs(cols[row2] - col);
         if(distanceRow==distanceCol) {
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
      if(row == MAX_QUEENS) {
         results.push_back(cols);
      } else {
         for(int col = 0; col<MAX_QUEENS; ++col) {
            if(CheckQueens(row, col, cols)) {
               cols[row] = col;
               EightQueens(row+1, cols, results);
            }
         }
      }
   }

   /*
    * What: Merge sorted array A and B and store into A
    * How:  Use merge sort and keep on storing into A
    */
   void MergeSortLargeAToB(int a[], int lenA, int b[], int lenB) {
      int c[lenA];
      int i = 0, j = 0, k = 0;
      if(lenA < lenB) {
         return;
      }
      while(i < lenA && j < lenB) {
         if(a[i] < b[j]) {
            c[k] = a[i];
            ++i;
            ++k;
         } else {
            c[k] = b[j];
            ++j;
            ++k;
         }
      }
      while(i < lenA) {
         c[k] = a[i];
         ++i;
         ++k;
      }
      while(j < lenB) {
         c[k] = b[j];
         ++j;
         ++k;
      }
      for(int i=0; i<lenA; ++i) {
         a[i] = c[i];
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
      if(start > end) {
         return -1;
      }
      int mid = (start + end)/2;
      if(data[mid] == find) {
         return mid;
      }
      // when start to mid is sorted
      if(data[start] < data[mid]) {
         if(data[start] <= find && data[mid] >= find) {
            return FindInRotatedSortedArray(data, start, mid - 1, find);
         } else {
            return FindInRotatedSortedArray(data, mid, end, find);
         }
      } else {
         // when mid to end is sorted
         if(data[mid] <= find && data[end] >= find) {
            return FindInRotatedSortedArray(data, mid, end, find);
         } else {
            return FindInRotatedSortedArray(data, start, mid - 1, find);
         }
      }
   }
}



