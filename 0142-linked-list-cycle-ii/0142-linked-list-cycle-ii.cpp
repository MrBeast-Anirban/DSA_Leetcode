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
    ListNode *detectCycle(ListNode *head) {
        ListNode *rabbit = head, *turtle = head;
        while(rabbit && rabbit->next){
            rabbit = rabbit->next->next;
            turtle = turtle->next;
            if(rabbit == turtle) break;
        }
        if(!rabbit || !rabbit->next) return NULL;
        rabbit = head;
        while(rabbit != turtle){
            rabbit = rabbit->next;
            turtle = turtle->next;
        }
        return turtle;
    }
};