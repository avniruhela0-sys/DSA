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
        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify result list handling
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Loop as long as there are nodes in l1, l2, or a remaining carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            // Add value from l1 if available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Add value from l2 if available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate the new carry (0 or 1)
            carry = sum / 10;
            
            // Create a new node with the single-digit remainder and attach it
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        // Return the actual head, skipping the initial dummy node
        ListNode* result = dummyHead->next;
        delete dummyHead; // Clean up memory
        return result;
    }
};