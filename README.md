# Leetcode Algo Problem Solutions (Count = 266)
# Leetcode SQL Problem Solutions (Count = 3)

# Index
  01. [Math (Count = 15)](#01-math) 
  02. [Arrays, General (Count = 51)](#02-arrays-general) 
  03. [Partition, 2 Pointers (Count = 06)](#03-partition-2-pointers) 
  04. [Sort (Count = 9)](#04-sort) 
  05. [LinkedList (Count = 26)](#05-linkedlist) 
  06. [Trees (Count = 45)](#06-trees) 
  07. [Search, Binary Search (Count = 16)](#07-search-binary-search) 
  08. [Queue, Priority Queue (Count = 09)](#08-queue-priority-queue) 
  09. [DFS, Recursion (Count = 23)](#09-dfs-recursion) 
  10. [Strings (Count = 26)](#10-strings) 
  11. [Dynamic Programming (Count = 21)](#11-dynamic-programming) 
  12. [Greedy (Count = 04)](#12-greedy) 
  13. [Stack (Count = 06)](#13-stack) 
  14. [BFS, Graph, Union Find (Count = 06)](#14-bfs-graph) 
  15. [Miscellaneous (Count = 04)](#15-miscellaneous) 
  16. [SQL (Count = 03)](#16-sql) 

## 01. Math

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [C++](./7-ReverseInteger.cpp) [Java](./java/7-ReverseInteger.java)| good | | 16 July 2017 |
02 | 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | [C++](./12-IntegerToRoman.cpp) [Java](./java/12-IntegerToRoman.java)|  | | 16 July 2017 |
03 | 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [C++](./13-RomanToInteger.cpp) [Java](./java/13-RomanToInteger.java)|  | | 16 July 2017 |
04 | 190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | [C++](./190-ReverseBits.cpp) [Java](./java/190-ReverseBits.java) |  | | 27 July 2017 |
05 | 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [C++](./9-PalindromeNumber.cpp) | good | | 24 August 2017 |
06 | 29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | [C++](./29-DivideTwoIntegers.cpp) [Java](./java/29-DivideTwoIntegers.java)| :boom::boom::boom::boom::boom:|tricky, see 371 | 27 September 2017 |
07 | 43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | [C++](./43-MultiplyStrings.cpp) [Java](./java/43-MultiplyStrings.java)| :boom::boom::boom::boom::boom:|tricky | 27 September 2017 |
08 | 66 | [Plus One](https://leetcode.com/problems/plus-one/) | [C++](./66-PlusOne.cpp) [Java](./java/66-PlusOne.java)| :star::star::star::star::star:|tricky | 27 September 2017 |
09 | 191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | [C++](./191-NumberOf1Bits.cpp) [Java](./java/191-NumberOf1Bits.java)| :star::star::star::star::star:| | 27 September 2017 |
10 | 461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance/) | [C++](./461-HammingDistance.cpp) [Java](./java/461-HammingDistance.java)| :star::star::star::star::star:| | 28 September 2017 |
11 | 477 | [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/) | [C++](./477-TotalHammingDistance.cpp) [Java](./java/477-TotalHammingDistance.java)|:boom::boom::boom:|nice approach | 28 September 2017 |
12 | 633 | [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/) | [C++](./633-SumOfSquareNumbers.cpp) [Java](./java/633-SumOfSquareNumbers.java)|:star::star::star::star::star:|cases less 0/equal 0/1/2 | 28 September 2017 |
13 | 371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) | [C++](./371-SumOfTwoIntegers.cpp) |:boom::boom::boom:|[https://discuss.leetcode.com/topic/50315/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently], see 29 | 30 September 2017 |
14 | 260 | [Single Number III](https://leetcode.com/problems/single-number-iii/) | [C++](./260-SingleNumberIII.cpp) [Java](./java/260-SingleNumberIII.java)|:boom::boom::boom:| | 30 September 2017 |
15 | 204 | [Count Primes](https://leetcode.com/problems/count-primes/) | [C++](./204-CountPrimes.cpp) [Java](./java/204-CountPrimes.java)|:star::star::star::star::star:| | 29 October 2017 |
 

## 02. Arrays, General

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 268 | [Missing Number](https://leetcode.com/problems/missing-number/) | [C++](./268-MissingNumber.cpp) [Java](./java/268-MissingNumber.java)|:star::star::star::star::star:| | 7 June 2017 |
02 | 287 | [Find The Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | [C++](./287-FindTheDuplicateNumber.cpp) [Java](./java/287-FindTheDuplicateNumber.java)| :boom::boom::boom: | | 7 June 2017 |
03 | 136 | [Single Number](https://leetcode.com/problems/single-number/) | [C++](./136-SingleNumber.cpp) [Java](./java/136-SingleNumber.java)|:star::star::star:| | 30 September 2017 |
04 | 389 | [Find the Difference](https://leetcode.com/problems/find-the-difference/) | [C++](./389-FindTheDifference.cpp) [Java](./java/389-FindTheDifference.java)|:star::star::star::star::star:| | 27 September 2017 |
05 | 41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | [C++](./41-FindTheDuplicateNumber.cpp) [Java](./java/41-FindTheDuplicateNumber.java)|:boom::boom::boom:| tricky,hard| 7 June 2017 |
06 | 442 | [Find All Duplicates In An Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | [C++](./442-FindAllDuplicatesInAnArray.cpp) [Java](./java/442-FindAllDuplicatesInAnArray.java)|:boom::boom::boom:| tricky,hard| 7 June 2017 |
07 | 448 | [Find All Numbers Disappeared In An Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | [C++](./448-FindAllNumbersDisappearedInAnArray.cpp) [Java](./java/448-FindAllNumbersDisappearedInAnArray.java)|:boom::boom::boom:| similar to 442| 7 June 2017 |
08 | 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | [C++](./217-ContainsDuplicate.cpp) [Java](./java/217-ContainsDuplicate.java)| :star::star::star::star::star:| | 8 June 2017 |
09 | 219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) | [C++](./219-ContainsDuplicateII.cpp) [Java](./java/219-ContainsDuplicateII.java)| :boom::boom::boom: | | 8 June 2017 |
10 | 220 | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) | [C++](./220-ContainsDuplicateIII.cpp) [Java](./java/220-ContainsDuplicateIII.java)|:boom::boom::boom::boom::boom:| | 8 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
11 | 169 | [Majority Element](https://leetcode.com/problems/majority-element/) | [C++](./169-MajorityElement.cpp) [Java](./java/169-MajorityElement.java)| :boom::boom::boom: | tricky| 8 June 2017 |
12 | 229 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | [C++](./229-MajorityElementII.cpp) [C++](./229-MajorityElementII.java)|:boom::boom::boom::boom::boom:| tricky, generalise it| 8 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
13 | 168 | [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) | [C++](./168-ExcelSheetColumnTitle.cpp) [Java](./java/168-ExcelSheetColumnTitle.java)| :boom::boom::boom: | num to excel col; math; note string concat operation| 8 June 2017 |
14 | 171 | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) | [C++](./171-ExcelSheetColumnNumber.cpp) | [Java](./java/171-ExcelSheetColumnNumber.java) | excel col to num; math| 8 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
15 | 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | [C++](./189-RotateArray.cpp) [Java](./java/189-RotateArray.java)| | | 6 May 2017 |
16 | 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) | [C++](./61-RotateList.cpp) [Java](./java/61-RotateList.java)| | | 6 May 2017 |
-- | -- | -- | -- | -- | -- | -- |
17 | 48 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | [C++](./48-RotateImage.cpp) [Java](./java/48-RotateImage.java)|:star::star::star::star::star:| extra: 90 anticlockwise and 180 rotation| 18 June 2017 |
18 | 54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | [C++](./54-SpiralMatrix.cpp) [Java](./java/54-SpiralMatrix.java)|:boom::boom::boom:|see direction approach,[https://codereview.stackexchange.com/questions/38104/clockwise-and-counterclockwise-spiral-matrix-traversal], [https://stackoverflow.com/questions/21108695/how-do-i-change-the-directions-and-starting-points-of-this-matrix-spiral-travers], [https://gist.github.com/DaemonTails/8470408], [https://stackoverflow.com/questions/726756/print-two-dimensional-array-in-spiral-order/19625520#19625520] | 18 June 2017 |
19 | 59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | [C++](./59-SpiralMatrixII.cpp) [Java](./java/59-SpiralMatrixII.java)| :star::star::star::star::star:| | 18 June 2017 |
20 | 73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) | [C++](./73-SetMatrixZeroes.cpp) [Java](./java/73-SetMatrixZeroes.java)| :boom::boom::boom:| | 18 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
21 | 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [C++](./1-TwoSum.cpp) [Java](./java/1-TwoSum.java) [Python](./python/1-TwoSum.py) | :star::star::star:|map, sort, brute force | 18 June 2017 |
22 | 15 | [3 Sum](https://leetcode.com/problems/3sum/) | [C++](./15-3Sum.cpp) [Java](./java/15-3Sum.java)|:star::star::star::star::star:| | 18 June 2017 |
23 | 18 | [4 Sum](https://leetcode.com/problems/4sum/) | [C++](./18-4Sum.cpp) [Java](./java/18-4Sum.java)|:star::star::star::star::star:| see multimap solution| 18 June 2017 |
24 | 16 | [3 Sum Closest](https://leetcode.com/problems/3sum-closest/) | [C++](./16-3SumClosest.cpp) [Java](./java/16-3SumClosest.java)| :star::star::star::star::star:| | 18 June 2017 |
25 | 259 | [3 Sum Smaller](https://leetcode.com/problems/3sum-smaller/) | [C++](./259-3SumSmaller.cpp) |:boom::boom::boom:|paid | 18 June 2017 |
26 | 454 | [4 Sum II](https://leetcode.com/problems/4sum-ii/) | [C++](./454-4SumII.cpp) [Java](./java/454-4SumII.java)| :boom::boom::boom:| | 18 June 2017 |
27 | 167 | [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [C++](./167-TwoSumII.cpp) [Java](./java/167-TwoSumII.java)| :star::star::star:| | 27 September 2017 |
28 | 170 | [Two Sum III - Data structure design ](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | [C++](./170-TwoSumIII.cpp) |:boom::boom::boom:|paid| 27 September 2017 |
29 | 653 | [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | [C++](./653-TwoSumIV.cpp) [Java](./java/653-TwoSumIV.java)|:boom::boom::boom::boom::boom:| | 27 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
30 | 532 | [K Diff Pairs In An Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | [C++](./532-K-diffPairsInAnArray.cpp) [Java](./java/532-K-diffPairsInAnArray.java)| :boom::boom::boom::boom::boom:| | 22 August 2017 |
-- | -- | -- | -- | -- | -- | -- |
31 | 674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/) | [C++](./674-LongestContinuousIncreasingSubsequence.cpp) [Java](./java/674-LongestContinuousIncreasingSubsequence.java)|:boom::boom::boom:| | 16 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
32 | 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++](./121-BestTimeToBuyAndSellStock.cpp) [Java](./java/121-BestTimeToBuyAndSellStock.java)|:boom::boom::boom:|only 1 transaction, if delta prices given then equals max contiguous subarray | 16 September 2017 |
33 | 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | [C++](./122-BestTimeToBuyAndSellStockII.cpp) [Java](./java/122-BestTimeToBuyAndSellStockII.java)|:boom::boom::boom:|any no.of txns, we want all positive deltas | 16 September 2017 |
34 | 188 | [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | [C++](./188-BestTimeToBuyAndSellStockIV.cpp) [Java](./java/188-BestTimeToBuyAndSellStockIV.java)|:boom::boom::boom::boom::boom:|atmost k txns | 16 September 2017 |
35 | 123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | [C++](./123-BestTimeToBuyAndSellStockIII.cpp) [Java](./java/123-BestTimeToBuyAndSellStockIII.java)|:boom::boom::boom::boom::boom:|same as 188, k = 2 and atmost k txns | 16 September 2017 |
36 | 309 | [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | [C++](./309-BestTimeToBuyAndSellStockWithCooldown.cpp) [Java](./java/309-BestTimeToBuyAndSellStockWithCooldown.java)|:boom::boom::boom::boom::boom:|with cooldown | 16 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
37 | 384 | [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/) | [C++](./384-ShuffleAnArray.cpp) [Java](./java/384-ShuffleAnArray.java)|:boom::boom::boom::boom::boom:|Concept | 21 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
38 | 349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | [C++](./349-IntersectionOfTwoArrays.cpp) [Java](./java/349-IntersectionOfTwoArrays.java)|:star::star::star:|return common elements, hash(remove element afterwards), 2 pointers and sort approach | 30 September 2017 |
39 | 350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | [C++](./350-IntersectionOfTwoArraysII.cpp) [Java](./java/350-IntersectionOfTwoArraysII.java)|:star::star::star:| | 30 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
40 | 293 | [Flip Game](https://leetcode.com/problems/flip-game/) | [C++](./293-FlipGame.cpp) |:boom::boom::boom:| paid | 28 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
41 | 560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | [C++](./560-SubarraySumEqualsK.cpp) [Java](./java/560-SubarraySumEqualsK.java)|:boom::boom::boom:|  | 6 October 2017 |
42 | 523 | [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | [C++](./523-ContinuousSubarraySum.cpp) [Java](./java/523-ContinuousSubarraySum.java)|:boom::boom::boom:| see 416 | 6 October 2017 |
43 | 525 | [Contiguous Array](https://leetcode.com/problems/contiguous-array/) | [C++](./525-ContiguousArray.cpp) [Java](./java/525-ContiguousArray.java)|:boom::boom::boom:| | 26 October 2017 |
44 | 325 | [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | [C++](./325-MaximumSizeSubarraySumEqualsK.cpp) |:boom::boom::boom::boom::boom:|paid| 6 October 2017 |
45 | 209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | [C++](./209-MinimumSizeSubarraySum.cpp) [Java](./java/209-MinimumSizeSubarraySum.java)| :boom::boom::boom: | sliding window, tricky, NOTE:difference between this and 325| 23 August 2017 |
46 | 581 | [Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/) | [C++](./581-ShortestUnsortedContinuousSubarray.cpp) [Java](./java/581-ShortestUnsortedContinuousSubarray.java)|:boom::boom::boom::boom::boom:|tricky with O(1) space | 27 October 2017 |
-- | -- | -- | -- | -- | -- | -- |
47 | 463 | [Island Perimeter](https://leetcode.com/problems/island-perimeter/) | [C++](./463-IslandPerimeter.cpp) [Java](./java/463-IslandPerimeter.java)|:boom::boom::boom:| | 29 October 2017 |
48 | 277 | [Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/) | [C++](./277-FindTheCelebrity.cpp) |:boom::boom::boom:|paid| 2 November 2017 |
-- | -- | -- | -- | -- | -- | -- |
49 | 495 | [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/) | [C++](./495-TeemoAttacking.cpp) [Java](./java/495-TeemoAttacking.java)|:boom::boom::boom:| tricky, similar to interval problems 56, 57 etc.  | 9 November 2017 |
50 | 228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges/) | [C++](./228-SummaryRanges.cpp) [Java](./java/228-SummaryRanges.java)|:boom::boom::boom:| tricky,similar to 495  | 9 November 2017 |
51 | 163 | [Missing Ranges](https://leetcode.com/problems/missing-ranges/) | [C++](./163-MissingRanges.cpp) |:boom::boom::boom:| tricky,similar to 495, paid  | 9 November 2017 |
-- | -- | -- | -- | -- | -- | -- |


## 03. Partition, 2 Pointers

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 75 | [Sort Colors](https://leetcode.com/problems/sort-colors/) | [C++](./75-SortColors.cpp) [Java](./java/75-SortColors.java)| :star::star::star::star::star:| | 6 May 2017 |
02 | 283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | [C++](./283-MoveZeroes.cpp) [Java](./java/283-MoveZeroes.java)| :star::star::star::star::star:| | 6 May 2017 |
03 | 27 | [Remove Element](https://leetcode.com/problems/remove-element/) | [C++](./27-RemoveElement.cpp) [Java](./java/27-RemoveElement.java)| :star::star::star::star::star:| | 6 May 2017 |
04 | 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | [C++](./88-MergeSortedArray.cpp) [Java](./java/88-MergeSortedArray.java)| :star::star::star::star::star:| | 6 May 2017 |
-- | -- | -- | -- | -- | -- | -- |
05 | 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [C++](./26-RemoveDuplicatesFromSortedArray.cpp) [Java](./java/26-RemoveDuplicatesFromSortedArray.java)| :boom::boom::boom:| | 23 June 2017 |
06 | 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [C++](./80-RemoveDuplicatesFromSortedArrayII.cpp) [Java](./java/80-RemoveDuplicatesFromSortedArrayII.java)| :boom::boom::boom::boom::boom:| | 23 June 2017 |
-- | -- | -- | -- | -- | -- | -- |


## 04. Sort

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | [C++](./56-MergeIntervals.cpp) [Java](./java/56-MergeIntervals.java)| :star::star::star::star::star:|used lambda fn; tricky  | 30 March 2017 |
02 | 57 | [Insert Intervals](https://leetcode.com/problems/insert-interval/) | [C++](./57-InsertInterval.cpp) [Java](./java/57-InsertInterval.java)|:boom::boom::boom:| tricky  | 30 March 2017 |
03 | 179 | [Largest Number](https://leetcode.com/problems/largest-number/) | [C++](./179-LargestNumber.cpp) [Java](./java/179-LargestNumber.java)| :boom::boom::boom:| tricky  | 16 July 2017 |
04 | 252 | [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) | [C++](./252-MeetingRooms.cpp) | :star::star::star::star::star:| find presence of overlapping interval, paid  | 16 July 2017 |
05 | 253 | [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | [C++](./253-MeetingRoomsII.cpp) | :boom::boom::boom::boom::boom:|custom sorting, paid | 16 July 2017 |
06 | 165 | [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/) | [C++](./165-CompareVersionNumbers.cpp) [Java](./java/165-CompareVersionNumbers.java)|:boom::boom::boom:| | 1 August 2017 |
07 | 406 | [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/) | [C++](./406-QueueReconstructionByHeight.cpp) [Java](./java/406-QueueReconstructionByHeight.java)| :boom::boom::boom::boom::boom:| very tricky; see effecient algo  | 30 September 2017 |
08 | 280 | [Wiggle Sort](https://leetcode.com/problems/wiggle-sort/) | [C++](./280-WiggleSort.cpp) | :boom::boom::boom:|paid | 26 October 2017 |
09 | 324 | [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) | [C++](./324-WiggleSortII.cpp) [Java](./java/324-WiggleSortII.java)| :boom::boom::boom::boom::boom:|see median and tri partition approach | 26 October 2017 |


## 05. LinkedList

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | [C++](./21-MergeTwoSortedLists.cpp) [Java](./java/21-MergeTwoSortedLists.java)|:star::star::star::star::star:|iterative and recursive solutions | 6 May 2017 |
02 | 23 | [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | [C++](./23-MergeKSortedLists.cpp) [Java](./java/23-MergeKSortedLists.java)|:boom::boom::boom:| | 6 May 2017 |
-- | -- | -- | -- | -- | -- | -- |
03 | 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | [C++](./141-LinkedListCycle.cpp) [Java](./java/141-LinkedListCycle.java)|:star::star::star:| | 1 July 2017 |
04 | 142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) | [C++](./142-LinkedListCycleII.cpp) [Java](./java/142-LinkedListCycleII.java) |:boom::boom::boom:| | 1 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
05 | 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | [C++](./206-ReverseLinkedList.cpp) [Java](./java/206-ReverseLinkedList.java) [Python](./python/206-ReverseLinkedList.py) | :star::star::star::star::star:|recursive and iterative | 1 July 2017 |
06 | 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) | [C++](./92-ReverseLinkedListII.cpp) [Java](./java/92-ReverseLinkedListII.java)|:boom::boom::boom:|tricky, reverse b/w m and n, case m ==1, see Java solution | 1 July 2017 |
06 | 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) | [C++](./61-RotateList.cpp) [Java](./java/61-RotateList.java)|:boom::boom::boom:| LinkedList, in Group1| 6 May 2017 |
-- | -- | -- | -- | -- | -- | -- |
07 | 148 | [Sort List](https://leetcode.com/problems/sort-list/) | [C++](./148-SortList.cpp) [Java](./java/148-SortList.java)|:boom::boom::boom:| handle odd/even length case| 1 July 2017 |
08 | 147 | [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/) | [C++](./147-InsertionSortList.cpp) [Java](./java/147-InsertionSortList.java)|:boom::boom::boom:| | 1 July 2017 |
09 | 160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) | [C++](./160-IntersectionOfTwoLinkedLists.cpp) [Java](./java/160-IntersectionOfTwoLinkedLists.java)|:boom::boom::boom:| | 1 July 2017 |
10 | 109 | [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | [C++](./109-ConvertSortedListToBinarySearchTree.cpp) [Java](./java/109-ConvertSortedListToBinarySearchTree.java)|:boom::boom::boom:| | 1 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
11 | 237 | [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/) | [C++](./237-DeleteNodeInALinkedList.cpp) [Java](./java/237-DeleteNodeInALinkedList.java)| :star::star::star:| | 1 July 2017 |
12 | 203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/) | [C++](./203-RemoveLinkedListElements.cpp) [Java](./java/203-RemoveLinkedListElements.java)|:star::star::star::star::star:| | 1 July 2017 |
13 | 83 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | [C++](./83-RemoveDuplicatesFromSortedList.cpp) [Java](./java/83-RemoveDuplicatesFromSortedList.java)|:star::star::star::star::star:| | 1 July 2017 |
14 | 82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | [C++](./82-RemoveDuplicatesFromSortedListII.cpp) [Java](./java/82-RemoveDuplicatesFromSortedListII.java)|:boom::boom::boom:|tricky| 1 July 2017 |
15 | 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [C++](./19-RemoveNthNodeFromEndOfList.cpp) [Java](./java/19-RemoveNthNodeFromEndOfList.java)|:boom::boom::boom:| | 1 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
16 | 234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) | [C++](./234-PalindromeLinkedList.cpp) [Java](./java/234-PalindromeLinkedList.java)|:boom::boom::boom:| | 1 July 2017 |
17 | 2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [C++](./2-AddTwoNumbers.cpp) [Java](./java/2-AddTwoNumbers.java)|:boom::boom::boom:| | 1 July 2017 |
18 | 445 | [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/) | [C++](./445-AddTwoNumbersII.cpp) [Java](./java/445-AddTwoNumbersII.java)|:boom::boom::boom:| | 9 November 2017 |
19 | 369 | [Plus One Linked List](https://leetcode.com/problems/plus-one-linked-list/) | [C++](./369-PlusOneLinkedList.cpp) |:boom::boom::boom:|paid | 9 November 2017 |
-- | -- | -- | -- | -- | -- | -- |
20 | 143 | [Reorder List](https://leetcode.com/problems/reorder-list/) | [C++](./143-ReorderList.cpp) [Java](./java/143-ReorderList.java)|:boom::boom::boom:|handle even/odd length case | 1 July 2017 |
21 | 86 | [Partition List](https://leetcode.com/problems/partition-list/) | [C++](./86-PartitionList.cpp) [Java](./java/86-PartitionList.java)|:boom::boom::boom:|| 1 July 2017 |
22 | 328 | [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) | [C++](./328-OddEvenLinkedList.cpp) [Java](./java/328-OddEvenLinkedList.java)|:boom::boom::boom:| | 1 July 2017 |
23 | 24 | [Swap Nodes In Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | [C++](./24-SwapNodesInPairs.cpp) [Java](./java/24-SwapNodesInPairs.java)|:boom::boom::boom:| tricky| 1 July 2017 |
24 | 25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) | [C++](./25-ReverseNodesInKGroup.cpp) [Java](./java/25-ReverseNodesInKGroup.java)|:boom::boom::boom::boom::boom:| tricky| 1 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
25 | 138 | [Copy List With Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) | [C++](./138-CopyListWithRandomPointer.cpp) [Java](./java/138-CopyListWithRandomPointer.java)|:boom::boom::boom::boom::boom:|tricky | 15 September 2017 |
26 | 379 | [Design Phone Directory](https://leetcode.com/problems/design-phone-directory/) | [C++](./379-DesignPhoneDirectory.cpp) [Java](./java/379-DesignPhoneDirectory.java)|:boom::boom::boom::boom::boom:|tricky, harsh time constraints, paid, see both | 10 November 2017 |


## 06. Trees

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | [C++](./235-LowestCommonAncestorOfABinarySearchTree.cpp) [Java](./java/235-LowestCommonAncestorOfABinarySearchTree.java)| :star::star::star:| Trees, Recursion| 4 April 2017 |
02 | 236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | [C++](./236-LowestCommonAncestorOfABinaryTree.cpp) [Java](./java/236-LowestCommonAncestorOfABinaryTree.java)| :star::star::star::star::star:| Trees, Recursion| 4 April 2017 |
02 | 0 | [Lowest Common Ancestor of a Binary Tree Using Parent Pointer](http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-tree-set-2-using-parent-pointer/) | [C++](./extras/0-LowestCommonAncestorOfABinaryTreeUsingParentPointer.cpp) |:star::star::star::star::star:| Trees, Recursion| 4 November 2017 |
-- | -- | -- | -- | -- | -- | -- |
03 | 100 | [Same Tree](https://leetcode.com/problems/same-tree/) | [C++](./100-SameTree.cpp) [Java](./java/100-SameTree.java) [Python](./python/100-SameTree.py) | :star::star::star:| Trees, Recursion| 4 April 2017 |
04 | 226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | [C++](./226-InvertBinaryTree.cpp) [Java](./java/226-InvertBinaryTree.java) |:star::star::star:| Trees, Recursion| 10 September 2017 |
05 | 101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) | [C++](./101-SymmetricTree.cpp) [Java](./java/101-SymmetricTree.java)|:star::star::star::star::star:| Trees, Recursion| 4 April 2017 |
06 | 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | [C++](./98-ValidateBinarySearchTree.cpp) [Java](./java/98-ValidateBinarySearchTree.java)|:star::star::star::star::star:| Trees, Recursion| 2 July 2017 |
07 | 110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | [C++](./110-BalancedBinaryTree.cpp) [Java](./java/110-BalancedBinaryTree.java)| :star::star::star::star::star:|Trees, Recursion| 2 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
08 | 450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) | [C++](./450-DeleteNodeInABst.cpp) [Java](./java/450-DeleteNodeInABst.java)| :boom::boom::boom:| | 4 April 2017 |
09 | 173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | [C++](./173-BinarySearchTreeIterator.cpp) [Java](./java/173-BinarySearchTreeIterator.java)| :boom::boom::boom::boom::boom: | | 12 April 2017 |
10 | 94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | [C++](./94-BinaryTreeInorderTraversal.cpp) [Java](./java/94-BinaryTreeInorderTraversal.java)| :boom::boom::boom:|see morris traversal, stack solutions | 12 April 2017 |
11 | 144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | [C++](./144-BinaryTreePreorderTraversal.cpp) | | | 12 April 2017 |
12 | 145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | [C++](./145-BinaryTreePostorderTraversal.cpp) | | | 12 April 2017 |
13 | 285 | [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/) | [C++](./285-InorderSuccessorInBST.cpp) |:star::star::star::star::star:| | 12 April 2017 |
14 | 102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | [C++](./102-BinaryTreeLevelOrderTraversal.cpp) [Java](./java/102-BinaryTreeLevelOrderTraversal.java)| | | 3 July 2017 |
15 | 103 | [Binary Tree ZigZag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | [C++](./103-BinaryTreeZigzagLevelOrderTraversal.cpp) [Java](./java/103-BinaryTreeZigzagLevelOrderTraversal.java)| | | 3 July 2017 |
16 | 107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) | [C++](./107-BinaryTreeLevelOrderTraversalII.cpp) [Java](./java/107-BinaryTreeLevelOrderTraversalII.java)| :star::star::star:| | 3 July 2017 |
17 | 314 | [Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/) | [C++](./314-BinaryTreeVerticalOrderTraversal.cpp) |:boom::boom::boom::boom::boom:| good; uses level order traversal| 3 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
18 | 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | [C++](./104-MaximumDepthOfBinaryTree.cpp) [Java](./java/104-MaximumDepthOfBinaryTree.java)| :star::star::star:| | 3 July 2017 |
19 | 111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) | [C++](./111-MinimumDepthOfBinaryTree.cpp) [Java](./java/111-MinimumDepthOfBinaryTree.java)| :star::star::star::star::star:| | 3 July 2017 |
20 | 230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) | [C++](./230-KthSmallestElementInABST.cpp) [Java](./java/230-KthSmallestElementInABST.java)| :star::star::star::star::star:| | 3 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
21 | 108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) | [C++](./108-ConvertSortedArrayToBinarySearchTree.cpp) [Java](./java/108-ConvertSortedArrayToBinarySearchTree.java)| :star::star::star::star::star:| | 3 July 2017 |
22 | 116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) | [C++](./116-PopulatingNextRightPointersInEachNode.cpp) [Java](./java/116-PopulatingNextRightPointersInEachNode.java)|:boom::boom::boom::boom::boom:|O(1) space very tricky | 4 July 2017 |
23 | 117 | [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) | [C++](./117-PopulatingNextRightPointersInEachNodeII.cpp) [Java](./java/117-PopulatingNextRightPointersInEachNodeII.java)|:boom::boom::boom::boom::boom:| O(1) space very tricky| 4 July 2017 |
24 | 105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [C++](./105-ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp) [Java](./java/105-ConstructBinaryTreeFromPreorderAndInorderTraversal.java)|:boom::boom::boom:|NOTE: Binary tree, not BST | 25 July 2017 |
25 | 106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | [C++](./106-ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp) [Java](./java/106-ConstructBinaryTreeFromInorderAndPostorderTraversal.java)|:boom::boom::boom:| NOTE: Binary tree, not BST | 25 July 2017 |
26 | 297 | [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | [C++](./297-SerializeAndDeserializeBinaryTree.cpp) |good| | 30 August 2017 |
-- | -- | -- | -- | -- | -- | -- |
27 | 114 | [Flatten Binary Tree To Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | [C++](./114-FlattenBinaryTreeToLinkedList.cpp) [Java](./java/114-FlattenBinaryTreeToLinkedList.java)|:boom::boom::boom::boom::boom:| | 29 July 2017 |
27 | 0 | [Binary Tree to Doubly Linked List](http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/) | [C++](./extras/0-BinaryTreeToDoublyLinkedList.cpp) |:boom::boom::boom::boom::boom:|[Link 2](http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/) [Link 3](http://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/) [Link 4](http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/) | 4 November 2017 |
27 | 0 | [Binary Tree to Circular Doubly Linked List](http://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/) | [C++](./extras/0-BinaryTreeToCircularDoublyLinkedList.cpp) [C](./extras/0-BinaryTreeToCircularDoublyLinkedList2.c) |:boom::boom::boom::boom::boom:|[Link 2](http://cslibrary.stanford.edu/109/TreeListRecursion.html) [Link 3](http://articles.leetcode.com/convert-binary-search-tree-bst-to/) | 4 November 2017 |
-- | -- | -- | -- | -- | -- | -- |
28 | 530 | [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/) | [C++](./530-MinimumAbsoluteDifferenceInBST.cpp) [Java](./java/530-MinimumAbsoluteDifferenceInBST.java)|:star::star::star::star::star:|good, inorder traversal| 22 August 2017 |
29 | 654 | [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/) | [C++](./654-MaximumBinaryTree.cpp) [Java](./java/654-MaximumBinaryTree.java)|:star::star::star::star::star:|like 108| 16 September 2017 |
30 | 563 | [Binary Tree Tilt](https://leetcode.com/problems/binary-tree-tilt/) | [C++](./563-BinaryTreeTilt.cpp) [Java](./java/563-BinaryTreeTilt.java)|:star::star::star::star::star:| | 16 September 2017 |
31 | 671 | [Second Minimum Node In a Binary Tree](https://leetcode.com/problems/binary-tree-tilt/) | [C++](./671-SecondMinimumNodeInABinaryTree.cpp) [Java](./java/671-SecondMinimumNodeInABinaryTree.java)|:boom::boom::boom::boom::boom:| | 16 September 2017 |
32 | 652 | [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) | [C++](./652-FindDuplicateSubtrees.cpp) [Java](./java/652-FindDuplicateSubtrees.java)|:boom::boom::boom::boom::boom:| | 21 September 2017 |
33 | 669 | [Trim A Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/) | [C++](./669-TrimABinarySearchTree.cpp) [Java](./java/669-TrimABinarySearchTree.java)|:boom::boom::boom::boom::boom:|deleting node in c++ makes it tricky | 21 September 2017 |
34 | 270 | [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/) | [C++](./270-ClosestBinarySearchTreeValue.cpp) |:boom::boom::boom:|paid| 22 September 2017 |
35 | 272 | [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) | [C++](./272-ClosestBinarySearchTreeValueII.cpp) |:boom::boom::boom::boom::boom:|paid| 25 September 2017 |
36 | 617 | [Merge Two Binary Trees](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) | [C++](./617-MergeTwoBinaryTrees.cpp) [Java](./java/617-MergeTwoBinaryTrees.java)|:star::star::star::star::star:|| 27 September 2017 |
37 | 199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | [C++](./199-BinaryTreeRightSideView.cpp) [Java](./java/199-BinaryTreeRightSideView.java)|:boom::boom::boom:| see dfs approach| 29 September 2017 |
38 | 366 | [Find Leaves of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/) | [C++](./366-FindLeavesOfBinaryTree.cpp) |:boom::boom::boom::boom::boom:|paid| 29 September 2017 |
39 | 543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | [C++](./543-DiameterOfBinaryTree.cpp) [Java](./java/543-DiameterOfBinaryTree.java)|:boom::boom::boom:|see path sum problems| 29 September 2017 |
40 | 501 | [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/) | [C++](./501-FindModeInBinarySearchTree.cpp) [Java](./java/501-FindModeInBinarySearchTree.java)|:boom::boom::boom:|| 29 September 2017 |
41 | 538 | [Convert BST to Greater Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/) | [C++](./538-ConvertBSTToGreaterTree.cpp) [Java](./java/538-ConvertBSTToGreaterTree.java)|:star::star::star::star::star:|| 29 September 2017 |
42 | 404 | [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/) | [C++](./404-SumOfLeftLeaves.cpp) [Java](./java/404-SumOfLeftLeaves.java)|:star::star::star::star::star:|| 29 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
43 | 572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) | [C++](./572-SubtreeOfAnotherTree.cpp) [Java](./java/572-SubtreeOfAnotherTree.java)|:star::star::star::star::star:|| 01 November 2017 |
44 | 508 | [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/) | [C++](./508-MostFrequentSubtreeSum.cpp) [Java](./java/508-MostFrequentSubtreeSum.java)|:star::star::star::star::star:|| 01 November 2017 |
45 | 250 | [Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees/) | [C++](./250-CountUnivalueSubtrees.cpp) |:star::star::star::star::star:|paid| 01 November 2017 |
-- | -- | -- | -- | -- | -- | -- |


## 07. Search, Binary Search

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 35 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [C++](./35-SearchInsertPosition.cpp) [Java](./java/35-SearchInsertPosition.java)|:star::star::star:|Binary Search| 19 July 2017 |
02 | 162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element/) | [C++](./162-FindPeakElement.cpp) [Java](./java/162-FindPeakElement.java)|:boom::boom::boom::boom::boom:|Binary Search| 19 July 2017 |
03 | 278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) | [C++](./278-FirstBadVersion.cpp) [Java](./java/278-FirstBadVersion.java)| :boom::boom::boom:|Binary Search| 19 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
04 | 33 | [Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [C++](./33-SearchInRotatedSortedArray.cpp) [Java](./java/33-SearchInRotatedSortedArray.java)|:boom::boom::boom::boom::boom:| Binary Search| 6 May 2017 |
05 | 81 | [Search In Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | [C++](./81-SearchInRotatedSortedArrayII.cpp) [Java](./java/81-SearchInRotatedSortedArrayII.java)|:boom::boom::boom::boom::boom:|Binary Search| 6 May 2017 |
06 | 153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [C++](./153-FindMinimumInRotatedSortedArray.cpp) [Java](./java/153-FindMinimumInRotatedSortedArray.java)|:boom::boom::boom::boom::boom:| Binary Search| 22 September 2017 |
07 | 154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) | [C++](./154-FindMinimumInRotatedSortedArrayII.cpp) [Java](./java/154-FindMinimumInRotatedSortedArrayII.java)|:boom::boom::boom::boom::boom:| Binary Search| 22 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
08 | 74 | [Search A 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | [C++](./74-SearchA2dMatrix.cpp) [Java](./java/74-SearchA2dMatrix.java) |:boom::boom::boom::boom::boom:|Special Search| 23 June 2017 |
09 | 240 | [Search A 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) | [C++](./240-SearchA2dMatrixII.cpp) [Java](./java/240-SearchA2dMatrixII.java)|:boom::boom::boom::boom::boom:|Special Search| 23 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
10 | 04 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [C++](./4-MedianOfTwoSortedArrays.cpp) |:boom::boom::boom::boom::boom:| Binary Search| 9 July 2017 |
11 | 34 | [Search for a Range](https://leetcode.com/problems/search-for-a-range/) | [C++](./34-SearchForARange.cpp) [Java](./java/34-SearchForARange.java)|:boom::boom::boom::boom::boom:| Binary Search, own lower bound and upper bound implementation| 11 September 2017 |
12 | 658 | [Find K Closest Points](https://leetcode.com/problems/find-k-closest-elements/) | [C++](./658-FindKClosestPoints.cpp) [Java](./java/658-FindKClosestPoints.java)|:boom::boom::boom::boom::boom:| Binary Search| 17 September 2017 |
13 | 69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | [C++](./69-Sqrtx.cpp) [Java](./java/69-Sqrtx.java)|:boom::boom::boom::boom::boom:| Binary Search, last of N approach| 27 September 2017 |
14 | 374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | [C++](./374-GuessNumberHigherOrLower.cpp) [Java](./java/374-GuessNumberHigherOrLower.java)|:star::star::star::star::star:| Binary Search, see 375| 28 September 2017 |
15 | 367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | [C++](./367-ValidPerfectSquare.cpp) [Java](./java/367-ValidPerfectSquare.java)|:star::star::star::star::star:| Binary Search, see cases n is 0 and is 0 and is 1| 28 September 2017 |
16 | 540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/) | [C++](./540-SingleElementInASortedArray.cpp) [Java](./java/540-SingleElementInASortedArray.java)|:boom::boom::boom:| Binary Search, tricky, see single number problems| 30 September 2017 |


## 08. Queue, Priority Queue

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | [C++](./215-KthLargestElementInAnArray.cpp) [Java](./java/215-KthLargestElementInAnArray.java)|:boom::boom::boom:| Quick Select, Priority Q| 24 June 2017 |
02 | 378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | [C++](./378-KthSmallestElementInASortedMatrix.cpp) [Java](./java/378-KthSmallestElementInASortedMatrix.java)| :boom::boom::boom: | Priority Q, see binary search approach| 24 June 2017 |
03 | 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | [C++](./347-TopKFrequentElements.cpp) [Java](./java/347-TopKFrequentElements.java)|:boom::boom::boom:|Note: both can be used, min and max pq | 24 June 2017 |
04 | 295 | [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) | [C++](./295-FindMedianFromDataStream.cpp) [Java](./java/295-FindMedianFromDataStream.java)| :boom::boom::boom::boom::boom: | Priority Q, Multiset| 25 June 2017 |
05 | 480 | [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) | [C++](./480-SlidingWindowMedian.cpp) [Java](./java/480-SlidingWindowMedian.java)| :boom::boom::boom::boom::boom: | Priority Q, Multiset; Java better as PQ has remove| 25 June 2017 |
06 | 373 | [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) | [C++](./373-FindKPairsWithSmallestSums.cpp) [Java](./java/373-FindKPairsWithSmallestSums.java)| :boom::boom::boom::boom::boom: | Priority Q, very tricky, java better| 29 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
07 | 346 | [Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/) | [C++](./346-MovingAverageFromDataStream.cpp) |:boom::boom::boom:|Queue, paid| 25 June 2017 |
08 | 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | [C++](./239-SlidingWindowMaximum.cpp) |:boom::boom::boom::boom::boom:| Deque, Multiset| 25 June 2017 |
09 | 225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/) | [C++](./225-ImplementStackUsingQueues.cpp) |:boom::boom::boom::boom::boom: |Queue | 6 October 2017 |
-- | -- | -- | -- | -- | -- | -- |


## 09. DFS, recursion

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 112 | [Path Sum](https://leetcode.com/problems/path-sum/) | [C++](./112-PathSum.cpp) [Java](./java/112-PathSum.java)|:star::star::star::star::star:| Trees DFS, Recursion| 31 March 2017 |
02 | 113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | [C++](./113-PathSumII.cpp) [Java](./java/113-PathSumII.java)| :boom::boom::boom:| Trees DFS, Recursion| 31 March 2017 |
03 | 437 | [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | [C++](./437-PathSumIII.cpp) [Java](./java/437-PathSumIII.java)|:boom::boom::boom::boom::boom:| Trees DFS, Recursion| 8 June 2017 |
04 | 124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | [C++](./124-BinaryTreeMaximumPathSum.cpp) [Java](./java/124-BinaryTreeMaximumPathSum.java)|:boom::boom::boom::boom::boom: | see: [http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/] and [http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/] Trees DFS, Recursion| 30 July 2017 |
05 | 129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | [C++](./129-SumRootToLeafNumbers.cpp) [Java](./java/129-SumRootToLeafNumbers.java)| :boom::boom::boom::boom::boom:| Trees DFS, Recursion| 30 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
06 | 46 | [Permutations](https://leetcode.com/problems/permutations/) | [C++](./46-Permutations.cpp) [Java](./java/46-Permutations.java)| :star::star::star:| DFS, Recursion| 10 June 2017 |
07 | 47 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | [C++](./47-PermutationsII.cpp) [Java](./java/47-PermutationsII.java)|:star::star::star::star::star: | DFS, Recursion| 10 June 2017 |
08 | 31 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | [C++](./31-NextPermutation.cpp) [Java](./java/31-NextPermutation.java)| :star::star::star::star::star:| DFS, Recursion| 10 June 2017 |
09 | 60 | [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | [C++](./60-PermutationSequence.cpp) |Tricky | | 10 June 2017 |
10 | 266 | [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/) | [C++](./266-PalindromePermutation.cpp) |PAID | | 10 June 2017 |
11 | 267 | [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/) | [C++](./267-PalindromePermutationII.cpp) |PAID | | 10 June 2017 |
12 | 78 | [Subsets](https://leetcode.com/problems/subsets/) | [C++](./78-Subsets.cpp) [Java](./java/78-Subsets.java)| :star::star::star: | dfs,recursion| 10 June 2017 |
13 | 90 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | [C++](./90-SubsetsII.cpp) [Java](./java/90-SubsetsII.java)|:star::star::star::star::star:| dfs,recursion,tricky| 10 June 2017 |
14 | 39 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | [C++](./39-CombinationSum.cpp) [Java](./java/39-CombinationSum.java)|:star::star::star::star::star: | dfs,recursion,tricky| 10 June 2017 |
15 | 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | [C++](./40-CombinationSumII.cpp) [Java](./java/40-CombinationSumII.java)|:star::star::star::star::star: | dfs,recursion,tricky| 10 June 2017 |
16 | 216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | [C++](./216-CombinationSumIII.cpp) [Java](./java/216-CombinationSumIII.java)|:star::star::star::star::star:| dfs,recursion,tricky| 10 June 2017 |
17 | 377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | [C++](./377-CombinationSumIV.cpp) [Java](./java/377-CombinationSumIV.java)|:boom::boom::boom::boom::boom:| DP, dfs,recursion,follow up tricky| 10 June 2017 |
18 | 77 | [Combinations](https://leetcode.com/problems/combinations/) | [C++](./77-Combinations.cpp) | dfs,recursion,tricky | | 10 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
19 | 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | [C++](./22-GenerateParentheses.cpp) |:boom::boom::boom: | dfs,recursion,tricky| 27 September 2017 |
20 | 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | [C++](./17-LetterCombinationsOfAPhoneNumber.cpp) |:boom::boom::boom: | dfs,recursion,tricky| 27 September 2017 |
21 | 494 | [Target Sum](https://leetcode.com/problems/target-sum/) | [C++](./494-TargetSum.cpp) |:boom::boom::boom: | dfs,recursion, DP approach -subset sum also| 11 October 2017 |
-- | -- | -- | -- | -- | -- | -- |
22 | 200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/) | [C++](./200-NumberOfIslands.cpp) | :boom::boom::boom::boom::boom: | | 6 October 2017 |
23 | 695 | [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | [C++](./695-MaxAreaOfIsland.cpp) [Java](./java/695-MaxAreaOfIsland.java)| :star::star::star::star::star:| | 29 October 2017 |
-- | -- | -- | -- | -- | -- | -- |


## 10. Strings

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | [C++](./14-LongestCommonPrefix.cpp) |  | | 19 July 2017 |
02 | 38 | [Count and Say](https://leetcode.com/problems/count-and-say/) | [C++](./38-CountAndSay.cpp) |  | | 19 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
03 | 151 | [Reverse Words In a String ](https://leetcode.com/problems/reverse-words-in-a-string/) | [C++](./151-ReverseWordsInAString.cpp) [Java](./java/151-ReverseWordsInAString.java)|:boom::boom::boom::boom::boom:| | 12 June 2017 |
04 | 557 | [Reverse Words In a String III ](https://leetcode.com/problems/reverse-words-in-a-string-iii/) | [C++](./557-ReverseWordsInAStringIII.cpp) | tricky | | 12 June 2017 |
05 | 161 | [One Edit Distance ](https://leetcode.com/problems/one-edit-distance/) | [C++](./161-OneEditDistance.cpp) | tricky, paid | | 12 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
06 | 409 | [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/) | [C++](./409-LongestPalindrome.cpp) [Java](./java/409-LongestPalindrome.java)| | | 11 August 2017 |
07 | 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [C++](./5-LongestPalindromicSubstring.cpp) [Java](./java/5-LongestPalindromicSubstring.java)| :star::star::star::star::star:|same as 647 | 24 August 2017 |
08 | 647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | [C++](./647-PalindromicSubstrings.cpp) [Java](./java/647-PalindromicSubstrings.java)| :star::star::star::star::star:|same as 5 | 24 August 2017 |
-- | -- | -- | -- | -- | -- | -- |
09 | 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [C++](./3-LongestSubstringWithoutRepeatingCharacters.cpp) [Java](./java/3-LongestSubstringWithoutRepeatingCharacters.java)| :boom::boom::boom::boom::boom:| sliding window, same for arrays| 30 July 2017 |
10 | 438 | [Find All Anagrams In a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | [C++](./438-FindAllAnagramsInAString.cpp) [Java](./java/438-FindAllAnagramsInAString.java)|:boom::boom::boom::boom::boom:| sliding window| 20 August 2017 |
11 | 76 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | [C++](./76-MinimumWindowSubstring.cpp) [Java](./java/76-MinimumWindowSubstring.java)|:boom::boom::boom::boom::boom:|sliding window| 23 August 2017 |
12 | 567 | [Permutation In String](https://leetcode.com/problems/permutation-in-string/) | [C++](./567-PermutationInString.cpp) [Java](./java/567-PermutationInString.java)|:boom::boom::boom::boom::boom:| sliding window| 23 August 2017 |
13 | 340 | [Longest Substring with At Most K Distinct Characters ](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | [C++](./340-LongestSubstringWithAtMostKDistinctCharacters.cpp) [Java](./java/340-LongestSubstringWithAtMostKDistinctCharacters.java)| :boom::boom::boom::boom::boom:| sliding window, paid| 23 August 2017 |
-- | -- | -- | -- | -- | -- | -- |
14 | 139 | [Word Break](https://leetcode.com/problems/word-break/) | [C++](./139-WordBreak.cpp) [Java](./java/139-WordBreak.java)|:boom::boom::boom::boom::boom: || 30 August 2017 |
15 | 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | [C++](./49-GroupAnagrams.cpp) [Java](./java/49-GroupAnagrams.java)| :star::star::star:|| 1 September 2017 |
16 | 8 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | [C++](./8-StringToIntegerAtoi.cpp) [Java](./java/8-StringToIntegerAtoi.java)| :boom::boom::boom:|see test cases:leading space, sign, overflow| 27 September 2017 |
17 | 28 | [Implement strStr()](https://leetcode.com/problems/implement-strstr/) | [C++](./28-ImplementStrStr.cpp) [Java](./java/28-ImplementStrStr.java)|:boom::boom::boom::boom::boom:|see KMP Algo and the test cases | 27 September 2017 |
18 | 205 | [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/) | [C++](./205-IsomorphicStrings.cpp) [Java](./java/205-IsomorphicStrings.java)|:boom::boom::boom::boom::boom:| | 27 September 2017 |
19 | 290 | [Word Pattern](https://leetcode.com/problems/word-pattern/) | [C++](./290-WordPattern.cpp) [Java](./java/290-WordPattern.java)|:boom::boom::boom::boom::boom:| | 27 September 2017 |
20 | 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | [C++](./125-ValidPalindrome.cpp) [Java](./java/125-ValidPalindrome.java)|:boom::boom::boom:| | 27 September 2017 |
21 | 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | [C++](./242-ValidAnagram.cpp) |:star::star::star::star::star:|hash and sort approach | 27 September 2017 |
22 | 387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/) | [C++](./387-FirstUniqueCharacterInAString.cpp) |:star::star::star::star::star:| | 27 September 2017 |
23 | 344 | [Reverse String](https://leetcode.com/problems/reverse-string/) | [C++](./344-ReverseString.cpp) |:star::star::star:| | 27 September 2017 |
24 | 345 | [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/) | [C++](./345-ReverseVowelsOfAString.cpp) |:star::star::star:| | 27 September 2017 |
25 | 392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | [C++](./392-IsSubsequence.cpp) ||:boom::boom::boom: | 30 September 2017 |
26 | 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) | [C++](./58-LengthOfLastWord.cpp) [Java](./java/58-LengthOfLastWord.java)|| :star::star::star:| 26 October 2017 |


## 11. Dynamic Programming

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 72 | [Edit Distance ](https://leetcode.com/problems/edit-distance/) | [C++](./72-EditDistance.cpp) [Java](./java/72-EditDistance.java)|:boom::boom::boom::boom::boom:| | 22 June 2017 |
02 | 583 | [ Delete Operation for Two Strings ](https://leetcode.com/problems/delete-operation-for-two-strings/) | [C++](./583-DeleteOperationForTwoStrings.cpp) [Java](./java/583-DeleteOperationForTwoStrings.java)|:boom::boom::boom::boom::boom:| tricky, similar to 72| 22 June 2017 |
03 | 10 | [ Regular Expression Matching ](https://leetcode.com/problems/regular-expression-matching/) | [C++](./10-RegularExpressionMatching.cpp) [Java](./java/10-RegularExpressionMatching.java)|:boom::boom::boom::boom::boom:| | 28 June 2017 |
04 | 44 | [ Wildcard Matching ](https://leetcode.com/problems/wildcard-matching/) | [C++](./44-WildcardMatching.cpp) [Java](./java/44-WildcardMatching.java)|:boom::boom::boom::boom::boom:| | 14 September 2017 |
05 | 53 | [ Maximum Subarray ](https://leetcode.com/problems/maximum-subarray/) | [C++](./53-MaximumSubarray.cpp) [Java](./java/53-MaximumSubarray.java)| :star::star::star::star::star:| | 18 July 2017 |
06 | 70 | [ Climbing Stairs ](https://leetcode.com/problems/climbing-stairs/) | [C++](./70-ClimbingStairs.cpp) [Java](./java/70-ClimbingStairs.java)|:star::star::star::star::star:|note case n = 0 | 18 July 2017 |
07 | 91 | [ Decode Ways ](https://leetcode.com/problems/decode-ways/) | [C++](./91-DecodeWays.cpp) [Java](./java/91-DecodeWays.java)|:boom::boom::boom::boom::boom:| | 18 July 2017 |
08 | 322 | [ Coin Change ](https://leetcode.com/problems/coin-change/) | [C++](./322-CoinChange.cpp) [Java](./java/322-CoinChange.java)| | | 29 July 2017 |
09 | 198 | [House Robber](https://leetcode.com/problems/house-robber/) | [C++](./198-HouseRobber.cpp) [Java](./java/198-HouseRobber.java)| | | 30 July 2017 |
10 | 152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | [C++](./152-MaximumProductSubarray.cpp) [Java](./java/152-MaximumProductSubarray.java)| | | 1 August 2017 |
11 | 416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | [C++](./416-PartitionEqualSubsetSum.cpp) [Java](./java/416-PartitionEqualSubsetSum.java)|:boom::boom::boom::boom::boom:|see subset sum problem, like 0-1 knapsack, see O(n) space soln | 13 September 2017 |
12 | 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | [C++](./64-MinimumPathSum.cpp) [Java](./java/64-MinimumPathSum.java)|:boom::boom::boom:|| 13 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
13 | 300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | [C++](./300-LongestIncreasingSubsequence.cpp) [Java](./java/300-LongestIncreasingSubsequence.java)|:boom::boom::boom:|| 16 September 2017 |
14 | 673 | [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) | [C++](./673-NumberOfLongestIncreasingSubsequence.cpp) [Java](./java/673-NumberOfLongestIncreasingSubsequence.java)|:boom::boom::boom:|| 16 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
15 | 62 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | [C++](./62-UniquePaths.cpp) |:boom::boom::boom:|| 3 October 2017 |
16 | 63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | [C++](./63-UniquePathsII.cpp) |:boom::boom::boom:|| 3 October 2017 |
-- | -- | -- | -- | -- | -- | -- |
17 | 221 | [Maximal Square](https://leetcode.com/problems/maximal-square/) | [C++](./221-MaximalSquare.cpp) |:boom::boom::boom::boom::boom:|| 5 October 2017 |
18 | 84 | [Largest Rectangle In Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) | [C++](./84-LargestRectangleInHistogram.cpp) |:boom::boom::boom::boom::boom:|| 5 October 2017 |
19 | 85 | [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) | [C++](./85-MaximalRectangle.cpp) |:boom::boom::boom::boom::boom:|| 5 October 2017 |
19 | 0 | [Maximum sum rectangle in a 2D matrix](http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/) | [C++](./extras/0-MaximumSumRectangleIn2DMatrix.cpp) |:boom::boom::boom::boom::boom:|Dynamic Programming, Kadane Algo| 5 October 2017 |
19 | 0 | [Largest rectangular sub-matrix whose sum is 0](http://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/) | [C++](./extras/0-LargestRectangularSubMatrixWhoseSumIs0.cpp) |:boom::boom::boom::boom::boom:|| 5 October 2017 |
19 | 0 | [Largest area rectangular sub-matrix with equal number of 1’s and 0’s](http://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/) | [C++](./extras/0-LargestRectangularSubMatrixWithEqual1And0.cpp) |:boom::boom::boom::boom::boom:|| 5 October 2017 |
-- | -- | -- | -- | -- | -- | -- |
20 | 329 | [Longest Increasing Path in a Matrix](http://www.leetcode.com/problems/longest-increasing-path-in-a-matrix/) | [C++](./329-LongestIncreasingPathInAMatrix.cpp) [Java](./java/329-LongestIncreasingPathInAMatrix.java)|:boom::boom::boom::boom::boom:|see 79| 26 October 2017 |
-- | -- | -- | -- | -- | -- | -- |
21 | 279 | [Perfect Squares](http://www.leetcode.com/problems/perfect-squares/) | [C++](./279-PerfectSquares.cpp) [Java](./java/279-PerfectSquares.java)|:boom::boom::boom::boom::boom:|see BFS, other DP, Math solutions| 29 October 2017 |
-- | -- | -- | -- | -- | -- | -- |


## 12. Greedy

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | [C++](./11-ContainerWithMostWater.cpp) | greedy,nice | | 18 July 2017 |
02 | 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [C++](./42-TrappingRainWater.cpp) | greedy,difficult | | 18 July 2017 |
03 | 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | [C++](./55-JumpGame.cpp) |:boom::boom::boom:| | 25 July 2017 |
04 | 134 | [Gas Station](https://leetcode.com/problems/gas-station/) | [C++](./134-GasStation.cpp) [Java](./java/134-GasStation.java)|:boom::boom::boom::boom::boom:| | 01 November 2017 |


## 13. Stack

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 155 | [Min Stack](https://leetcode.com/problems/min-stack/) | [C++](./155-MinStack.cpp) [Java](./java/155-MinStack.java) |  | | 30 July 2017 |
02 | 150 | [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | [C++](./150-EvaluateReversePolishNotation.cpp) [Java](./java/150-EvaluateReversePolishNotation.java) |  | | 30 July 2017 |
03 | 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [C++](./20-ValidParentheses.cpp) [Java](./java/20-ValidParentheses.java) |  | | 11 August 2017 |
04 | 32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) | [C++](./32-LongestValidParentheses.cpp) | :boom::boom::boom::boom::boom: | | 23 August 2017 |
05 | 71 | [Simplify Path](https://leetcode.com/problems/simplify-path/) | [C++](./71-SimplifyPath.cpp) [Java](./java/71-SimplifyPath.java)|:boom::boom::boom::boom::boom:| | 16 September 2017 |
06 | 232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) | [C++](./232-ImplementQueueUsingStacks.cpp) |:boom::boom::boom:| | 6 October 2017 |


## 14. BFS, graph, Union Find 

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 207 | [Course Schedule](https://leetcode.com/problems/course-schedule/) | [C++](./207-CourseSchedule.cpp) |  | | 14 August 2017 |
02 | 210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) | [C++](./210-CourseScheduleII.cpp) [Java](./java/210-CourseScheduleII.java) | :boom::boom::boom::boom::boom: | | 14 August 2017 |
03 | 133 | [Clone Graph](https://leetcode.com/problems/clone-graph/) | [C++](./133-CloneGraph.cpp) [Java](./java/133-CloneGraph.java) | :boom::boom::boom::boom::boom: | | 17 September 2017 |
04 | 261 | [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/) | [C++](./261-GraphValidTree.cpp) | :boom::boom::boom::boom::boom: | | 6 October 2017 |
04 | 0 | [Detect Cycle in a Graph](http://www.geeksforgeeks.org/detect-cycle-in-a-graph/) | [C++](./extras/0-DetectCycleInGraph.cpp) | :boom::boom::boom::boom::boom: | | 15 October 2017 |
05 | 547 | [Friend Circles](https://leetcode.com/problems/friend-circles/) | [C++](./547-FriendCircles.cpp) [Java](./java/547-FriendCircles.java)| :boom::boom::boom::boom::boom: | | 6 October 2017 |
06 | 79 | [Word Search](https://leetcode.com/problems/word-search/) | [C++](./79-WordSearch.cpp) | :boom::boom::boom::boom::boom: | | 7 October 2017 |



## 15. Miscellaneous 

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 146 | [LRU Cache](https://leetcode.com/problems/lru-cache/) | [C++](./146-LRUCache.cpp) |:boom::boom::boom::boom::boom: || 30 August 2017 |
02 | 315 | [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) | [C++](./315-CountOfSmallerNumbersAfterSelf.cpp) [Java](./java/315-CountOfSmallerNumbersAfterSelf.java)|:boom::boom::boom::boom::boom: |see BST, BIT approach too, count inversions| 30 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
03 | 208 | [ Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | [C++](./208-ImplementTrie.cpp) [Java](./java/208-ImplementTrie.java)|:boom::boom::boom::boom::boom: |Trie| 3 October 2017 |
04 | 211 | [ Add and Search Word - Data structure design ](https://leetcode.com/problems/add-and-search-word-data-structure-design/) | [C++](./211-AddAndSearchWord.cpp) [Java](./java/211-AddAndSearchWord.java)|:boom::boom::boom::boom::boom: |Trie| 5 October 2017 |



## 16. SQL 

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 175 | [Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) | [MySQL](./mysql/175-CombineTwoTables.sql) | :star::star::star:|| 23 October 2017 |
02 | 176 | [Second Highest Salary](https://leetcode.com/problems/second-highest-salary/) | [MySQL](./mysql/176-SecondHighestSalary.sql) | :star::star::star:|| 23 October 2017 |
03 | 177 | [Nth Highest Salary](https://leetcode.com/problems/nth-highest-salary/) | [MySQL](./mysql/177-NthHighestSalary.sql) |:boom::boom::boom:|| 25 October 2017 |




