class Solution {
public:
    bool isValid(string s) {
        stack<char> pilha;

        unordered_map<char, char> opts = { {'(', ')'}, {'{', '}'}, {'[', ']'} };
        unordered_map<char, char> bcks = { {')', '('}, {'}', '{'}, {']', '['} };


        for(auto c: s){
            if (opts.find(c) != opts.end()){
                pilha.push(c);
            } else {
                if (pilha.size() && pilha.top() == bcks[c]){
                    pilha.pop();
                } else {
                    return false;
                }
            }
        }

        return (pilha.size() == 0);
    }
};
