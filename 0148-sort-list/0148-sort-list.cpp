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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* dummynode= new ListNode(-1);
        ListNode* temp=dummynode;
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1= temp1->next;
            }
            else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1) temp->next=temp1;
        else temp->next=temp2;
        return dummynode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode* middle = findmiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return mergeTwoLists(left , right);
        
    }
};