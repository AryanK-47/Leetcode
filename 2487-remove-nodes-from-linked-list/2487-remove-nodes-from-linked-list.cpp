class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        stack<ListNode*> st;

        ListNode* curr = head;

        while (curr != nullptr) {

           
            while (!st.empty() && st.top()->val < curr->val) {
                st.pop();
            }

           
            st.push(curr);

            curr = curr->next;
        }

        
        ListNode* newHead = nullptr;

        while (!st.empty()) {

            ListNode* node = st.top();
            st.pop();

            node->next = newHead;
            newHead = node;
        }

        return newHead;
    }
};