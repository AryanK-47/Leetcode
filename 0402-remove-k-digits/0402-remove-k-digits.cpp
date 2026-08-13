class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        st.push(num[0]);
        int cnt=0;
        for(int i=1;i<n;i++){
            while(!st.empty() && cnt<k && num[i]<st.top()){
                st.pop();
                cnt++;
                
            }
            st.push(num[i]);
        }
        while(cnt<k){
            st.pop();
            cnt++;
        }

        string res="";
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());

        int i = 0;

        while(i < res.size() && res[i] == '0') {
            i++;
        }
        res = res.substr(i);

        if(res=="")return"0";


        
        return res;
    }
};