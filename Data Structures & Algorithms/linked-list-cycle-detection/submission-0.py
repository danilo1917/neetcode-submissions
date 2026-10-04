# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        low = head
        fast = head
        while(True):
            if (low is None or fast is None): return False
            low = low.next
            if (low is None or fast is None): return False
            fast = fast.next
            if (low is None or fast is None): return False
            fast = fast.next
            
            if (low is fast): return True