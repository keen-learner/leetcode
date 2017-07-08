'''

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. 
Could you implement both?

'''

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution1(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next: return head
        prev = None
        curr = head
        while(curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
            
        return prev

class Solution2(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        curr = head
        while (curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
            
        return prev  
   
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next: return head
        temp = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return temp

        
