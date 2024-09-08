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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        
        // Count total nodes
        int nodeCount = 0;
        for (ListNode* node = head; node; node = node->next) {
            nodeCount++;
        }
        
        // Calculate part sizes
        int baseSize = nodeCount / k;
        int extraNodes = nodeCount % k;
        
        ListNode* currentNode = head;
        ListNode* previousNode = nullptr;
        
        for (int i = 0; i < k && currentNode; i++) {
            result[i] = currentNode;
            
            // Determine size of current part
            int currentPartSize = baseSize + (i < extraNodes ? 1 : 0);
            
            // Traverse to the end of current part
            for (int j = 0; j < currentPartSize; j++) {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            
            // Disconnect current part from the rest
            if (previousNode) {
                previousNode->next = nullptr;
            }
        }
        
        return result;
    }
};