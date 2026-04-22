/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //use turtle rabbit approach
        ListNode *turtle = head, *rabbit = head;
        while(rabbit != NULL && rabbit -> next != NULL){
            turtle = turtle -> next;
            rabbit = rabbit -> next -> next;
            if(turtle == rabbit){
                return true;
            }
        }
        return false;
    }
};