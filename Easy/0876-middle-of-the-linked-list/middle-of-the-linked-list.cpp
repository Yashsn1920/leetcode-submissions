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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head; 
        int cnt = 1; 
        while(temp -> next != nullptr){ 
            temp = temp -> next; 
            cnt++; 
        }
        int m = cnt / 2;
        temp = head; 
        int i = 0; 
        while(i < m){ 
            temp = temp -> next; 
            i++; 
        }
        return temp;
        
    }
};