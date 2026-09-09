class Solution {
public:

    void check(string& digits, int n, int idx,
               string& temp, vector<string>& ans,
               unordered_map<char, string>& mp) {

        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        char digit = digits[idx];

        for (char ch : mp[digit]) {

            temp.push_back(ch);

            check(digits, n, idx + 1, temp, ans, mp);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        int n = digits.size();

        vector<string> ans;
        string temp;

        check(digits, n, 0, temp, ans, mp);

        return ans;
    }
};