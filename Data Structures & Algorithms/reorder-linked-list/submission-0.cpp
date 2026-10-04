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
    void reorderList(ListNode* head) {
        stack<ListNode*> pilha1, pilha2;

        ListNode* ant = nullptr;

        while(head){
            pilha1.push(head);
            head = head->next;
        }


        while(pilha1.size() != pilha2.size()){
            auto top = pilha1.top();
            pilha1.pop();   

            if (pilha1.size() == pilha2.size()){
                top->next = ant;
                ant = top;
                break;
            }

            pilha2.push(top);
        }

        while(!pilha1.empty()){
            auto tp1 = pilha1.top();
            auto tp2 = pilha2.top();
            tp1->next = tp2;
            tp2->next = ant;
            ant = tp1;

            pilha1.pop();
            pilha2.pop();
        }

        head = ant;
    }
};
