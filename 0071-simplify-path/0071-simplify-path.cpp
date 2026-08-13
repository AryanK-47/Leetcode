class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {

            if (part == "") {
                continue;
            }
            else if (part == "..") {
                if (!st.empty())
                    st.pop();
            }
            else if (part == ".") {
                continue;
            }
            else {
                st.push(part);
            }
        }
        string res = "";

        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res==""?"/":res;
    }
};