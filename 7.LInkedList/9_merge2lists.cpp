class Solution {
private:
    void modifyLists(ListNode* &list1, ListNode* &list2){
        if(list1->val > list2->val){
            ListNode * temp = list1;
            list1 = list2;
            list2 = temp;
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        modifyLists(list1 , list2);
        ListNode *current1 = list1 , *next1 = list1->next;
        ListNode *current2 = list2 , *next2 = list2->next;
        while(next1 && current2){
            if(current2->val >= current1->val && current2->val <= next1->val){
                current1->next = current2;
                next2 = current2->next;
                current2->next = next1;
                current1 = current1->next;
                current2 = next2;
            }
            else{
                current1 = next1;
                next1 = next1->next;
            }
        }
        if(next1 == NULL)
            current1->next = current2;
        return list1;
    }
};
// recusive appraoch
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1==NULL)return list2;
            if(list2==NULL)return list1;
            if(list1->val<=list2->val)
            {
               list1->next= mergeTwoLists(list1->next,list2);
               return list1;
            }
            else 
            {
               list2->next= mergeTwoLists(list1,list2->next);
               return list2;
            }
    }