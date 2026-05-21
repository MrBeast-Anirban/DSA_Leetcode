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
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split the list and reverse the second half
        ListNode *curr = slow->next;
        slow->next = nullptr; // Sever the first half
        ListNode *prev = nullptr;
        
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Step 3: Merge the two halves alternately
        ListNode *first = head;
        ListNode *second = prev; // Head of the reversed second half
        
        while (second) {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;
            
            first->next = second;
            second->next = tmp1;
            
            first = tmp1;
            second = tmp2;
        }
    }
};