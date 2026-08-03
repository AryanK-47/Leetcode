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
        if(head==NULL || head->next==NULL)return head;

    ListNode * newnode=reverseList(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;

    return newnode;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*front=reverseList(slow->next);
        slow->next=NULL;
        ListNode*temp=head;
        while(front!=NULL){
            ListNode* tempNext = temp->next;
            ListNode* frontNext = front->next;
            temp->next=front;
            front->next=tempNext;
            temp=tempNext;
            front=frontNext;

        }

    }
};