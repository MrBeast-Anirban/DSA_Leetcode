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
    bool isPalindrome(ListNode* head) {
        //floyd's fast and slow pointer with linked list reversal technique
        ListNode *slow = head, *fast = head, *prev, *temp;
        while(fast && fast->next){
            slow = slow->next, fast = fast->next->next;
        }
        //make the prev node i.e. slow node point to null
        prev = slow;
        slow = slow->next;
        prev->next = NULL;
        //Now slow pointer is at the half way of the linkedlist. Start reversing the right half of the linked list.
        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        //point fast at the start and slow at the end of the original linkedlist
        fast = head;
        slow = prev;
        //compare values at fast and slow pointer iterating.
        while(slow){
            if(fast->val != slow->val) return false;
            else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }
};