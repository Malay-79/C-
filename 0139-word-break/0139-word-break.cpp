class Solution {
public:
    unordered_set<string> st;
    int n;
    vector<int> dp;

    bool solve(int idx, string &s) {
        if (idx == n)
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (int l = 1; idx + l <= n; l++) {
            string temp = s.substr(idx, l);

            if (st.count(temp) && solve(idx + l, s))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for (string &word : wordDict)
            st.insert(word);

        dp.assign(n, -1);

        return solve(0, s);
    }
};