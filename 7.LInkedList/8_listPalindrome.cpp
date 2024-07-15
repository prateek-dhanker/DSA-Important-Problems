class Solution {
private:
   ListNode * middleNode(ListNode *head){
        ListNode *slow = head , * fast = head->next;
        while(fast){
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                return slow;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode * head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *current = head , *prev = NULL , *next = NULL;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } 
        return prev;
    } 
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode * mid = middleNode(head);
        ListNode * mnext = mid->next;
        ListNode * head2 = reverseList(mnext);
        mid->next = head2;
        while(head2){
            if(head2->val != head->val)
                return false;
            head2 = head2->next ; 
            head= head->next;
        }
        return true;
    }
};