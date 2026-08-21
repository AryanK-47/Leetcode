class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1)
            return head;

        ListNode*check = head;
        ListNode*left = head;
        ListNode*prev = nullptr;
        ListNode*prevGroup = nullptr;

        while(check != nullptr) {

            for(int i = 0; i < k; i++) {
                if(check == nullptr)
                    return head;
                check = check->next;
            }

            ListNode*prevleft = left;

            while(left != check) {
                ListNode*next = left->next;
                left->next = prev;
                prev = left;
                left = next;
            }

            if(prevGroup != nullptr)
                prevGroup->next = prev;
            else
                head = prev;

            prevleft->next = check;
            prevGroup = prevleft;
        }

        return head;
    }
};