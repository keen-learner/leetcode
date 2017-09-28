# Leetcode Algo Problem Solutions (Count = 202)

# Index
  01. [Math (Count = 11)](#01-math) 
  02. [Arrays, General (Count = 35)](#02-arrays-general) 
  03. [Partition, 2 Pointers (Count = 07)](#03-partition-2-pointers) 
  04. [Sort (Count = 06)](#04-sort) 
  05. [LinkedList (Count = 22)](#05-linkedlist) 
  06. [Trees (Count = 36)](#06-trees) 
  07. [Search, Binary Search (Count = 13)](#07-search-binary-search) 
  08. [Queue, Priority Queue (Count = 07)](#08-queue-priority-queue) 
  09. [DFS, Recursion (Count = 20)](#09-dfs-recursion) 
  10. [Strings (Count = 20)](#10-strings) 
  11. [Dynamic Programming (Count = 14)](#11-dynamic-programming) 
  12. [Greedy (Count = 03)](#12-greedy) 
  13. [Stack (Count = 05)](#13-stack) 
  14. [BFS (Count = 03)](#14-bfs-graph) 
  15. [Miscellaneous (Count = 01)](#15-miscellaneous) 

## 01. Math

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [C++](./7-ReverseInteger.cpp) [Java](./java/7-ReverseInteger.java)| good | | 16 July 2017 |
02 | 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | [C++](./12-IntegerToRoman.cpp) [Java](./java/12-IntegerToRoman.java)|  | | 16 July 2017 |
03 | 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | [C++](./13-RomanToInteger.cpp) [Java](./java/13-RomanToInteger.java)|  | | 16 July 2017 |
04 | 190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | [C++](./190-ReverseBits.cpp) [Java](./java/190-ReverseBits.java) |  | | 27 July 2017 |
05 | 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [C++](./9-PalindromeNumber.cpp) | good | | 24 August 2017 |
06 | 29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | [C++](./29-DivideTwoIntegers.cpp) [Java](./java/29-DivideTwoIntegers.java)| :boom::boom::boom::boom::boom:|tricky | 27 September 2017 |
07 | 43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | [C++](./43-MultiplyStrings.cpp) [Java](./java/43-MultiplyStrings.java)| :boom::boom::boom::boom::boom:|tricky | 27 September 2017 |
08 | 66 | [Plus One](https://leetcode.com/problems/plus-one/) | [C++](./66-PlusOne.cpp) [Java](./java/66-PlusOne.java)| :star::star::star::star::star:|tricky | 27 September 2017 |
09 | 191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | [C++](./191-NumberOf1Bits.cpp) [Java](./java/191-NumberOf1Bits.java)| :star::star::star::star::star:| | 27 September 2017 |
10 | 461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance/) | [C++](./461-HammingDistance.cpp) [Java](./java/461-HammingDistance.java)| :star::star::star::star::star:| | 28 September 2017 |
11 | 477 | [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/) | [C++](./477-TotalHammingDistance.cpp) [Java](./java/477-TotalHammingDistance.java)|:boom::boom::boom:|nice approach | 28 September 2017 |
 

## 02. Arrays, General

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 268 | [Missing Number](https://leetcode.com/problems/missing-number/) | [C++](./268-MissingNumber.cpp) |  | | 7 June 2017 |
02 | 287 | [Find The Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | [C++](./287-FindTheDuplicateNumber.cpp) [Java](./java/287-FindTheDuplicateNumber.java)| tricky | | 7 June 2017 |
03 | 41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | [C++](./41-FindTheDuplicateNumber.cpp) | tricky,hard | | 7 June 2017 |
04 | 442 | [Find All Duplicates In An Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | [C++](./442-FindAllDuplicatesInAnArray.cpp) | tricky,hard | | 7 June 2017 |
05 | 448 | [Find All Numbers Disappeared In An Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | [C++](./448-FindAllNumbersDisappearedInAnArray.cpp) | similar to 442 | | 7 June 2017 |
06 | 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | [C++](./217-ContainsDuplicate.cpp) |  | | 8 June 2017 |
07 | 219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) | [C++](./219-ContainsDuplicateII.cpp) |  | | 8 June 2017 |
08 | 220 | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) | [C++](./220-ContainsDuplicateIII.cpp) [Java](./java/220-ContainsDuplicateIII.java)|:boom::boom::boom::boom::boom:| | 8 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
09 | 169 | [Majority Element](https://leetcode.com/problems/majority-element/) | [C++](./169-MajorityElement.cpp) | tricky | | 8 June 2017 |
10 | 229 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | [C++](./229-MajorityElementII.cpp) | tricky, generalise it | | 8 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
11 | 168 | [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) | [C++](./168-ExcelSheetColumnTitle.cpp) | num to excel col; math | | 8 June 2017 |
12 | 171 | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) | [C++](./171-ExcelSheetColumnNumber.cpp) | excel col to num; math | | 8 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
13 | 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | [C++](./189-RotateArray.cpp) [Java](./java/189-RotateArray.java)| | | 6 May 2017 |
14 | 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) | [C++](./61-RotateList.cpp) [Java](./java/61-RotateList.java)| | | 6 May 2017 |
-- | -- | -- | -- | -- | -- | -- |
15 | 48 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | [C++](./48-RotateImage.cpp) [Java](./java/48-RotateImage.java)| extra | | 18 June 2017 |
16 | 54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | [C++](./54-SpiralMatrix.cpp) | | | 18 June 2017 |
17 | 59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | [C++](./59-SpiralMatrixII.cpp) | | | 18 June 2017 |
18 | 73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) | [C++](./73-SetMatrixZeroes.cpp) | | | 18 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
19 | 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [C++](./1-TwoSum.cpp) [Python](./python/1-TwoSum.py) | | | 18 June 2017 |
20 | 15 | [3 Sum](https://leetcode.com/problems/3sum/) | [C++](./15-3Sum.cpp) [Java](./java/15-3Sum.java)| tricky | | 18 June 2017 |
21 | 18 | [4 Sum](https://leetcode.com/problems/4sum/) | [C++](./18-4Sum.cpp) | see multimap solution| | 18 June 2017 |
22 | 16 | [3 Sum Closest](https://leetcode.com/problems/3sum-closest/) | [C++](./16-3SumClosest.cpp) | | | 18 June 2017 |
23 | 259 | [3 Sum Smaller](https://leetcode.com/problems/3sum-smaller/) | [C++](./259-3SumSmaller.cpp) |tricky, paid | | 18 June 2017 |
24 | 454 | [4 Sum II](https://leetcode.com/problems/4sum-ii/) | [C++](./454-4SumII.cpp) | | | 18 June 2017 |
25 | 167 | [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [C++](./167-TwoSumII.cpp) | | | 27 September 2017 |
26 | 170 | [Two Sum III - Data structure design ](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | [C++](./170-TwoSumIII.cpp) | | | 27 September 2017 |
27 | 653 | [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | [C++](./653-TwoSumIV.cpp) | | | 27 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
28 | 532 | [K Diff Pairs In An Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | [C++](./532-K-diffPairsInAnArray.cpp) | | | 22 August 2017 |
-- | -- | -- | -- | -- | -- | -- |
29 | 674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/) | [C++](./674-LongestContinuousIncreasingSubsequence.cpp) [Java](./java/674-LongestContinuousIncreasingSubsequence.java)| :star::star::star::star::star:| | 16 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
30 | 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++](./121-BestTimeToBuyAndSellStock.cpp) [Java](./java/121-BestTimeToBuyAndSellStock.java)|:boom::boom::boom:|only 1 transaction, if delta prices given then equals max contiguous subarray | 16 September 2017 |
31 | 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | [C++](./122-BestTimeToBuyAndSellStockII.cpp) [Java](./java/122-BestTimeToBuyAndSellStockII.java)|:boom::boom::boom:|any no.of txns, we want all positive deltas | 16 September 2017 |
32 | 188 | [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | [C++](./188-BestTimeToBuyAndSellStockIV.cpp) [Java](./java/188-BestTimeToBuyAndSellStockIV.java)|:boom::boom::boom::boom::boom:|atmost k txns | 16 September 2017 |
33 | 123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | [C++](./123-BestTimeToBuyAndSellStockIII.cpp) [Java](./java/123-BestTimeToBuyAndSellStockIII.java)|:boom::boom::boom::boom::boom:|same as 188, k = 2 and atmost k txns | 16 September 2017 |
34 | 309 | [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | [C++](./309-BestTimeToBuyAndSellStockWithCooldown.cpp) [Java](./java/309-BestTimeToBuyAndSellStockWithCooldown.java)|:boom::boom::boom::boom::boom:|with cooldown | 16 September 2017 |
-- | -- | -- | -- | -- | -- | -- |
35 | 384 | [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/) | [C++](./384-ShuffleAnArray.cpp) [Java](./java/384-ShuffleAnArray.java)|:boom::boom::boom::boom::boom:|Concept | 21 September 2017 |
-- | -- | -- | -- | -- | -- | -- |


## 03. Partition, 2 Pointers

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 75 | [Sort Colors](https://leetcode.com/problems/sort-colors/) | [C++](./75-SortColors.cpp) [Java](./java/75-SortColors.java)|Partition, 2 Pointers | | 6 May 2017 |
02 | 283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | [C++](./283-MoveZeroes.cpp) [Java](./java/283-MoveZeroes.java)|Partition | | 6 May 2017 |
03 | 27 | [Remove Element](https://leetcode.com/problems/remove-element/) | [C++](./27-RemoveElement.cpp) [Java](./java/27-RemoveElement.java)|Partition | | 6 May 2017 |
04 | 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | [C++](./88-MergeSortedArray.cpp) [Java](./java/88-MergeSortedArray.java)|Partition | | 6 May 2017 |
-- | -- | -- | -- | -- | -- | -- |
05 | 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [C++](./26-RemoveDuplicatesFromSortedArray.cpp) | [Java](./java/26-RemoveDuplicatesFromSortedArray.java)| | 23 June 2017 |
06 | 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [C++](./80-RemoveDuplicatesFromSortedArrayII.cpp) [Java](./java/80-RemoveDuplicatesFromSortedArrayII.java)| :boom::boom::boom::boom::boom:| | 23 June 2017 |
-- | -- | -- | -- | -- | -- | -- |
07 | 209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | [C++](./209-MinimumSizeSubarraySum.cpp) | sliding window, tricky | | 23 August 2017 |


## 04. Sort

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | [C++](./56-MergeIntervals.cpp) [Java](./java/56-MergeIntervals.java)|Sort |used lambda fn; tricky  | 30 March 2017 |
02 | 57 | [Insert Intervals](https://leetcode.com/problems/insert-interval/) | [C++](./57-InsertInterval.cpp) | | tricky  | 30 March 2017 |
03 | 179 | [Largest Number](https://leetcode.com/problems/largest-number/) | [C++](./179-LargestNumber.cpp) [Java](./java/179-LargestNumber.java)| | tricky  | 16 July 2017 |
04 | 252 | [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) | [C++](./252-MeetingRooms.cpp) | | find presence of overlapping interval, paid  | 16 July 2017 |
05 | 253 | [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | [C++](./253-MeetingRoomsII.cpp) | :boom::boom::boom::boom::boom:|custom sorting | 16 July 2017 |
06 | 165 | [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/) | [C++](./165-CompareVersionNumbers.cpp) [Java](./java/165-CompareVersionNumbers.java)| | good sorting practice  | 1 August 2017 |


## 05. LinkedList

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | [C++](./21-MergeTwoSortedLists.cpp) [Java](./java/21-MergeTwoSortedLists.java)|:star::star::star::star::star:|iterative and recursive solutions | 6 May 2017 |
02 | 23 | [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | [C++](./23-MergeKSortedLists.cpp) [Java](./java/23-MergeKSortedLists.java)|:boom::boom::boom:| | 6 May 2017 |
03 | 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | [C++](./141-LinkedListCycle.cpp) [Java](./java/141-LinkedListCycle.java)|:star::star::star:| | 1 July 2017 |
04 | 142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) | [C++](./142-LinkedListCycleII.cpp) [Java](./java/142-LinkedListCycleII.java) :boom::boom::boom:| | 1 July 2017 |
05 | 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | [C++](./206-ReverseLinkedList.cpp) [Java](./java/206-ReverseLinkedList.java) [Python](./python/206-ReverseLinkedList.py) | :star::star::star::star::star:|recursive and iterative | 1 July 2017 |
06 | 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) | [C++](./92-ReverseLinkedListII.cpp) [Java](./java/92-ReverseLinkedListII.java)|:boom::boom::boom:|tricky, reverse b/w m and n, case m ==1, see Java solution | 1 July 2017 |
07 | 143 | [Reorder List](https://leetcode.com/problems/reorder-list/) | [C++](./143-ReorderList.cpp) |:boom::boom::boom:|handle even/odd length case | 1 July 2017 |
07 | 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) | [C++](./61-RotateList.cpp) [Java](./java/61-RotateList.java)|:boom::boom::boom:| LinkedList, in Group1| 6 May 2017 |
08 | 148 | [Sort List](https://leetcode.com/problems/sort-list/) | [C++](./148-SortList.cpp) [Java](./java/148-SortList.java)|:boom::boom::boom:| handle odd/even length case| 1 July 2017 |
09 | 147 | [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/) | [C++](./147-InsertionSortList.cpp) |LinkedList| | 1 July 2017 |
10 | 160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) | [C++](./160-IntersectionOfTwoLinkedLists.cpp) [Java](./java/160-IntersectionOfTwoLinkedLists.java)|:boom::boom::boom:| | 1 July 2017 |
11 | 109 | [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | [C++](./109-ConvertSortedListToBinarySearchTree.cpp) [Java](./java/109-ConvertSortedListToBinarySearchTree.java)|:boom::boom::boom:| | 1 July 2017 |
12 | 328 | [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) | [C++](./328-OddEvenLinkedList.cpp) [Java](./java/328-OddEvenLinkedList.java)|:boom::boom::boom:| | 1 July 2017 |
13 | 237 | [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/) | [C++](./237-DeleteNodeInALinkedList.cpp) |LinkedList| | 1 July 2017 |
14 | 203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/) | [C++](./203-RemoveLinkedListElements.cpp) |LinkedList| | 1 July 2017 |
15 | 83 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | [C++](./83-RemoveDuplicatesFromSortedList.cpp) [Java](./java/83-RemoveDuplicatesFromSortedList.java)|:star::star::star::star::star:| | 1 July 2017 |
16 | 82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | [C++](./82-RemoveDuplicatesFromSortedListII.cpp) [Java](./java/82-RemoveDuplicatesFromSortedListII.java)|:boom::boom::boom:|tricky| 1 July 2017 |
17 | 234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) | [C++](./234-PalindromeLinkedList.cpp) |LinkedList| | 1 July 2017 |
18 | 86 | [Partition List](https://leetcode.com/problems/partition-list/) | [C++](./86-PartitionList.cpp) [Java](./java/86-PartitionList.java)|:boom::boom::boom:|| 1 July 2017 |
19 | 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [C++](./19-RemoveNthNodeFromEndOfList.cpp) |LinkedList| | 1 July 2017 |
20 | 2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [C++](./2-AddTwoNumbers.cpp) |LinkedList| | 1 July 2017 |
21 | 24 | [Swap Nodes In Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | [C++](./24-SwapNodesInPairs.cpp) |LinkedList|tricky | 1 July 2017 |
22 | 138 | [Copy List With Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) | [C++](./138-CopyListWithRandomPointer.cpp) [Java](./java/138-CopyListWithRandomPointer.java)|:boom::boom::boom::boom::boom:|tricky | 15 September 2017 |


## 06. Trees

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | [C++](./235-LowestCommonAncestorOfABinarySearchTree.cpp) [Java](./java/235-LowestCommonAncestorOfABinarySearchTree.java)| :star::star::star:| Trees, Recursion| 4 April 2017 |
02 | 236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | [C++](./236-LowestCommonAncestorOfABinaryTree.cpp) [Java](./java/236-LowestCommonAncestorOfABinaryTree.java)| :star::star::star::star::star:| Trees, Recursion| 4 April 2017 |
-- | -- | -- | -- | -- | -- | -- |
03 | 100 | [Same Tree](https://leetcode.com/problems/same-tree/) | [C++](./100-SameTree.cpp) [Java](./java/100-SameTree.java) [Python](./python/100-SameTree.py) | :star::star::star:| Trees, Recursion| 4 April 2017 |
04 | 226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | [C++](./226-InvertBinaryTree.cpp) [Java](./java/226-InvertBinaryTree.java) |:star::star::star:| Trees, Recursion| 10 September 2017 |
05 | 101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) | [C++](./101-SymmetricTree.cpp) [Java](./java/101-SymmetricTree.java)|:star::star::star::star::star:| Trees, Recursion| 4 April 2017 |
06 | 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | [C++](./98-ValidateBinarySearchTree.cpp) [Java](./java/98-ValidateBinarySearchTree.java)|:star::star::star::star::star:| Trees, Recursion| 2 July 2017 |
07 | 110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | [C++](./110-BalancedBinaryTree.cpp) [Java](./java/110-BalancedBinaryTree.java)| :star::star::star::star::star:|Trees, Recursion| 2 July 2017 |
-- | -- | -- | -- | -- | -- | -- |
08 | 450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) | [C++](./450-DeleteNodeInABst.cpp) |Trees | | 4 April 2017 |
09 | 173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | [C++](./173-BinarySearchTreeIterator.cpp) [Java](./java/173-BinarySearchTreeIterator.java)| :boom::boom::boom::boom::boom: | | 12 April 2017 |
10 | 94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | [C++](./94-BinaryTreeInorderTraversal.cpp) | | | 12 April 2017 |
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
28 | 530 | [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/) | [C++](./530-MinimumAbsoluteDifferenceInBST.cpp) [Java](./java/530-MinimumAbsoluteDifferenceInBST.java)|:star::star::star::star::star:|good, inorder traversal| 22 August 2017 |
29 | 654 | [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/) | [C++](./654-MaximumBinaryTree.cpp) [Java](./java/654-MaximumBinaryTree.java)|:star::star::star::star::star:|like 108| 16 September 2017 |
30 | 563 | [Binary Tree Tilt](https://leetcode.com/problems/binary-tree-tilt/) | [C++](./563-BinaryTreeTilt.cpp) [Java](./java/563-BinaryTreeTilt.java)|:star::star::star::star::star:| | 16 September 2017 |
31 | 671 | [Second Minimum Node In a Binary Tree](https://leetcode.com/problems/binary-tree-tilt/) | [C++](./671-SecondMinimumNodeInABinaryTree.cpp) [Java](./java/671-SecondMinimumNodeInABinaryTree.java)|:boom::boom::boom::boom::boom:| | 16 September 2017 |
32 | 652 | [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) | [C++](./652-FindDuplicateSubtrees.cpp) [Java](./java/652-FindDuplicateSubtrees.java)|:boom::boom::boom::boom::boom:| | 21 September 2017 |
33 | 669 | [Trim A Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/) | [C++](./669-TrimABinarySearchTree.cpp) [Java](./java/669-TrimABinarySearchTree.java)|:boom::boom::boom::boom::boom:|deleting node in c++ makes it tricky | 21 September 2017 |
34 | 270 | [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/) | [C++](./270-ClosestBinarySearchTreeValue.cpp) |:boom::boom::boom:|paid| 22 September 2017 |
35 | 272 | [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) | [C++](./272-ClosestBinarySearchTreeValueII.cpp) |:boom::boom::boom::boom::boom:|paid| 25 September 2017 |
36 | 617 | [Merge Two Binary Trees](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) | [C++](./617-MergeTwoBinaryTrees.cpp) [Java](./java/617-MergeTwoBinaryTrees.java)|:star::star::star::star::star:|| 27 September 2017 |


## 07. Search, Binary Search

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 35 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [C++](./35-SearchInsertPosition.cpp) [Java](./java/35-SearchInsertPosition.java)|:star::star::star:|Binary Search| 19 July 2017 |
02 | 162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element/) | [C++](./162-FindPeakElement.cpp) [Java](./java/162-FindPeakElement.java)|:boom::boom::boom::boom::boom:|Binary Search| 19 July 2017 |
03 | 278 | [First Bad Version](https://leetcode.com/problems/find-bad-version/) | [C++](./278-FirstBadVersion.cpp) [Java](./java/278-FirstBadVersion.java)| :boom::boom::boom:|Binary Search| 19 July 2017 |
04 | 33 | [Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [C++](./33-SearchInRotatedSortedArray.cpp) | Binary Search| | 6 May 2017 |
05 | 81 | [Search In Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | [C++](./81-SearchInRotatedSortedArrayII.cpp) | Binary Search | | 6 May 2017 |
06 | 153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [C++](./153-FindMinimumInRotatedSortedArray.cpp) [Java](./java/153-FindMinimumInRotatedSortedArray.java)|:boom::boom::boom::boom::boom:| Binary Search| 22 September 2017 |
07 | 154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) | [C++](./154-FindMinimumInRotatedSortedArrayII.cpp) [Java](./java/154-FindMinimumInRotatedSortedArrayII.java)|:boom::boom::boom::boom::boom:| Binary Search| 22 September 2017 |
08 | 74 | [Search A 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | [C++](./74-SearchA2dMatrix.cpp) [Java](./java/74-SearchA2dMatrix.java) | Special Search | | 23 June 2017 |
09 | 240 | [Search A 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) | [C++](./240-SearchA2dMatrixII.cpp) [Java](./java/240-SearchA2dMatrixII.java)| Special Search | | 23 June 2017 |
10 | 04 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [C++](./4-MedianOfTwoSortedArrays.cpp) | Binary Search | | 9 July 2017 |
11 | 34 | [Search for a Range](https://leetcode.com/problems/search-for-a-range/) | [C++](./34-SearchForARange.cpp) |:boom::boom::boom::boom::boom:| Binary Search, own lower bound and upper bound implementation| 11 September 2017 |
12 | 658 | [Find K Closest Points](https://leetcode.com/problems/find-k-closest-elements/) | [C++](./658-FindKClosestPoints.cpp) |:boom::boom::boom::boom::boom:| Binary Search| 17 September 2017 |
13 | 69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | [C++](./69-Sqrtx.cpp) [Java](./java/69-Sqrtx.java)|:boom::boom::boom::boom::boom:| Binary Search, last of N approach| 27 September 2017 |


## 08. Queue, Priority Queue

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | [C++](./215-KthLargestElementInAnArray.cpp) | Quick Select, Priority Q | | 24 June 2017 |
02 | 378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | [C++](./378-KthSmallestElementInASortedMatrix.cpp) | Priority Q, see binary search approach | | 24 June 2017 |
03 | 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | [C++](./347-TopKFrequentElements.cpp) | Priority Q, Quick Select | | 24 June 2017 |
04 | 295 | [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) | [C++](./295-FindMedianFromDataStream.cpp) | Priority Q, Multiset | | 25 June 2017 |
05 | 480 | [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) | [C++](./480-SlidingWindowMedian.cpp) | Priority Q, Multiset | | 25 June 2017 |
06 | 346 | [Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/) | [C++](./346-MovingAverageFromDataStream.cpp) | Queue | | 25 June 2017 |
07 | 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | [C++](./239-SlidingWindowMaximum.cpp) | Priority Q, Multiset | | 25 June 2017 |


## 09. DFS, recursion

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 112 | [Path Sum](https://leetcode.com/problems/path-sum/) | [C++](./112-PathSum.cpp) [Java](./java/112-PathSum.java)|:star::star::star::star::star:| Trees DFS, Recursion| 31 March 2017 |
02 | 113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | [C++](./113-PathSumII.cpp) [Java](./java/113-PathSumII.java)| :boom::boom::boom:| Trees DFS, Recursion| 31 March 2017 |
03 | 437 | [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | [C++](./437-PathSumIII.cpp) [Java](./java/437-PathSumIII.java)|:boom::boom::boom:| Trees DFS, Recursion| 8 June 2017 |
04 | 124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | [C++](./124-BinaryTreeMaximumPathSum.cpp) [Java](./java/124-BinaryTreeMaximumPathSum.java)|:boom::boom::boom::boom::boom: | see: [http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/] Trees DFS, Recursion| 30 July 2017 |
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
19 | 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | [C++](./22-GenerateParentheses.cpp) |:boom::boom::boom: | dfs,recursion,tricky| 27 September 2017 |
20 | 17 | Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | [C++](./17-LetterCombinationsOfAPhoneNumber.cpp) |:boom::boom::boom: | dfs,recursion,tricky| 27 September 2017 |


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
09 | 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [C++](./3-LongestSubstringWithoutRepeatingCharacters.cpp) [Java](./java/3-LongestSubstringWithoutRepeatingCharacters.java)| :boom::boom::boom::boom::boom:| sliding window| 30 July 2017 |
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


## 12. Greedy

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | [C++](./11-ContainerWithMostWater.cpp) | greedy,nice | | 18 July 2017 |
02 | 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | [C++](./42-TrappingRainWater.cpp) | greedy,difficult | | 18 July 2017 |
03 | 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | [C++](./55-JumpGame.cpp) | greedy,tricky | | 25 July 2017 |


## 13. Stack

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 155 | [Min Stack](https://leetcode.com/problems/min-stack/) | [C++](./155-MinStack.cpp) [Java](./java/155-MinStack.java) |  | | 30 July 2017 |
02 | 150 | [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | [C++](./150-EvaluateReversePolishNotation.cpp) [Java](./java/150-EvaluateReversePolishNotation.java) |  | | 30 July 2017 |
03 | 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [C++](./20-ValidParentheses.cpp) [Java](./java/20-ValidParentheses.java) |  | | 11 August 2017 |
04 | 32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) | [C++](./32-LongestValidParentheses.cpp) | :boom::boom::boom::boom::boom: | | 23 August 2017 |
05 | 71 | [Simplify Path](https://leetcode.com/problems/simplify-path/) | [C++](./71-SimplifyPath.cpp) [Java](./java/71-SimplifyPath.java)|:boom::boom::boom::boom::boom:| | 16 September 2017 |


## 14. BFS, graph 

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 207 | [Course Schedule](https://leetcode.com/problems/course-schedule/) | [C++](./207-CourseSchedule.cpp) |  | | 14 August 2017 |
02 | 210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) | [C++](./210-CourseScheduleII.cpp) [Java](./java/210-CourseScheduleII.java) | :boom::boom::boom::boom::boom: | | 14 August 2017 |
03 | 133 | [Clone Graph](https://leetcode.com/problems/clone-graph/) | [C++](./133-CloneGraph.cpp) [Java](./java/133-CloneGraph.java) | :boom::boom::boom::boom::boom: | | 17 September 2017 |



## 15. Miscellaneous 

|  S.No  |  Prob #  | Title                         |  Solution       | Tag          | Note                                  | Added on | 
|-----|-----|------------------------------ | --------------- |--------------|-------------------------------------- |----------|
01 | 146 | [LRU Cache](https://leetcode.com/problems/lru-cache/) | [C++](./146-LRUCache.cpp) |:boom::boom::boom::boom::boom: || 30 August 2017 |


