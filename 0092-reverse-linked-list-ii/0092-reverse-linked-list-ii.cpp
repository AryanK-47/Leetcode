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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode*temp=head;
        int t=right-left+1;
        ListNode*before=nullptr;

        while(left>1){
            before=temp;
            temp=temp->next;
            left--;
        }
        ListNode*curr=temp;
        ListNode*prev=nullptr;

        while(t > 0){
        ListNode* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;

        t--;
    }
        if(before!=nullptr)before->next=prev;
        else head=prev;

        temp->next=curr;
        return head;

        
    }
};