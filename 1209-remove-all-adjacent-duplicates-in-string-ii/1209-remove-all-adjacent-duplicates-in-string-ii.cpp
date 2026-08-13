class Solution {
public:
    string removeDuplicates(string s, int k) {
       int n=s.size();
       stack<pair<char,int>>st;
       string res;
    for(int i=0;i<n;i++){
        if(!st.empty() && st.top().first==s[i]){
            st.top().second++;
        }
        else{
            st.push({s[i],1});
        }
       if(st.top().second==k)st.pop();

    } 
    while(!st.empty()){
        char ch=st.top().first;
        int i=st.top().second;

        while(i>0){
            res+=ch;
            i--;
        }
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;

    }
};