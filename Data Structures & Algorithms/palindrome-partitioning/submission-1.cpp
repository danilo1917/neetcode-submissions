class Solution {
public:
    vector<vector<string>> final;
    vector<string> going;

    bool isPal(string &s, int beg, int end){
        auto mid = (beg + end) / 2;
        for (int i =beg; i<= mid; i++){
            
            if (s[i] != s[end + beg - i]) {
                return false;
            }
        }

        return true;
    }

    void partition(string &s, int beg){
        if (beg >= s.size()){
            final.push_back(going);
            return;
        }

        for (int i=beg; i< s.size(); i++){
            if(isPal(s, beg, i)){
                going.push_back(s.substr(beg, i -beg +1));
                partition(s, i+1);
                going.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        partition(s, 0);

        return final;
    }
};
