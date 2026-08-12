class Solution {
public:
    string removeDuplicates(string s) {
        stack<int>st;
        int n=s.size();
        string res;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }

            if(st.top()!=s[i])st.push(s[i]);
            else{
                st.pop();
                continue;
            } 
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};