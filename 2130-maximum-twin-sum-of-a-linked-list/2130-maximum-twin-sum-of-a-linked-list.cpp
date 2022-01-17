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
    ListNode* reverseList(ListNode* head) {
        ListNode * prevNode = NULL;
        ListNode * currNode = head;
        ListNode * nextNode = NULL;
        
        while(currNode != NULL){
            
            if(currNode ->next == NULL){
                head = currNode;
            }
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return head;
    }
    ListNode * getMiddle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        if(head == NULL){
            return 0;
        }
        int pairSum = 0;
        ListNode * first = head;
        ListNode * second = reverseList(getMiddle(head));
       
        while(second != NULL){
            pairSum = max(pairSum,first->val + second->val);
            first = first->next;
            second = second->next;
        }
        
        return pairSum;
    }
};