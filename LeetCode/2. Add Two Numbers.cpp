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
        ListNode *sum = new ListNode(0);
        ListNode *s = sum;
        int carry =0;
        while(l1 || l2 || carry != 0)
        {
            int ss = (l1?l1->val:0)  + (l2?l2->val:0) + carry;
            carry = ss /10;
            s->next = new ListNode(ss%10);
            s = s->next;
            l1  = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        return sum->next;
    }
};
