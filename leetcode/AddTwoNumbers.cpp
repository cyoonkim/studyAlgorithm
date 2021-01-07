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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answerHead = new ListNode(0);
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* c = answerHead;
        int carry = 0;
        int x, y;
        
        while (a || b) {
            int sum = 0;
            if(a) {
                sum += a->val;
                a = a->next;
            }
            if(b){
                sum += b->val;
                b = b->next;
            }
            sum += carry;
            carry = ((sum)>=10) ? 1 : 0;
            sum = ((sum)>=10) ? sum - 10 : sum;
            c->next = new ListNode(sum);
            c = c->next;
        }
        if(carry == 1){
            c->next = new ListNode(carry);
        }
        return answerHead->next;
    }
};