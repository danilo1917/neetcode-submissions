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
    ListNode* mergeKLists2(vector<ListNode*>& lists, int beg, int end) {
        if (beg == end) return lists[beg];
        if (end < beg) return nullptr;

        auto p1 = mergeKLists2(lists, beg, (beg + end) / 2);
        auto p2 = mergeKLists2(lists, (beg + end ) / 2+1 , end);

        if (!p1) return p2;
        if (!p2) return p1;

        ListNode* head;
        if(p1-> val <= p2-> val){
            head = p1;
            p1 = p1->next;
        } else {
            head = p2;
            p2 = p2->next;
        }
        auto lista = head;
        while (p1 && p2){
            if (p1-> val <= p2-> val){
                lista->next = p1;
                p1 = p1-> next;
            } else {
                lista->next = p2;
                p2 = p2->next;
            }

            lista = lista->next;
        }

        if(!p1){
            lista->next = p2;
        }
        if(!p2){
            lista->next = p1;
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

      return mergeKLists2(lists, 0, lists.size()-1);
    }
};
