class Solution {
public:
    unordered_map<int, int> dp;
    int numDecodings(string &s, int i=0) {
        if (i >= s.size()) return 1;
        if (dp.count(i)) return dp[i];
        if (s[i] == '0') return dp[i] = 0;

        auto count1 = numDecodings(s, i+1);
        auto count2 = 0;
        if (i + 1 < s.size()){
            if ((s[i] - '0')*10 + s[i+1]-'0' <= 26)
                count2 = numDecodings(s, i+2);
        }

        return dp[i] = count1 + count2; 
        
    }
};
