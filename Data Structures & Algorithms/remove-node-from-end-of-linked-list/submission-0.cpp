/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p1 = head;
        auto p2 = head;
        while (n){
            if (!p2) break;
            p2 = p2-> next;
            n--;
        }

        while(p2 && p2->next){
            p2 = p2->next;
            p1 = p1->next;
        }

        if(!p2){
            return head-> next;
        }

        auto toRemove = p1->next;
        p1->next = toRemove->next;
        delete toRemove;

        return head;

    }
};
