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
    ListNode* swapPairs(ListNode* head) {
        ListNode*left=head;
        ListNode*right=nullptr;
        ListNode*prevleft=nullptr;
        while(left!=nullptr && left->next!=nullptr){
            right=left->next;
            ListNode*next=right->next;

            if(prevleft==nullptr)head=right;
            else prevleft->next=right;

            right->next=left;
            left->next=next;
            
            prevleft=left;
            left=next;
            
        }
return head;
    }
};