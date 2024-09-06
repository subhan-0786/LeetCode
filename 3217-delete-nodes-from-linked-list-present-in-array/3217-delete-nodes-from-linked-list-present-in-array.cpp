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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Store the values to remove in an unordered_set for quick lookup
        unordered_set<int> removalSet(nums.begin(), nums.end());

        // Remove any leading nodes that are in the removalSet
        while (head != nullptr && removalSet.find(head->val) != removalSet.end()) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // If all nodes were removed, return nullptr
        if (head == nullptr) {
            return nullptr;
        }

        // Traverse the list, removing nodes as needed
        ListNode* current = head;
        while (current->next != nullptr) {
            if (removalSet.find(current->next->val) != removalSet.end()) {
                // Node to be removed
                ListNode* temp = current->next;
                // Bypass the node to be removed
                current->next = current->next->next;
                // Free the memory of the removed node
                delete temp;
            } else {
                // Move to the next node if no removal is needed
                current = current->next;
            }
        }

        return head;
    }
};
