class Solution {
public:
    int cal(vector<int> v) {
        int c = 0;

        for(auto& a:v) {
            c += a;
        }

        return c;
    }

    bool isDigit(char c) {
        if(c != '+' && c != '-' && c != '(' && c != ')' && c != ' ') return true;
        else return false;
    }

    int calculate(string s) {
        stack<bool> brackets_sign;
        stack<int> brackets_val;
        int ans = 0;
        bool num_minus = false;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '-') { // find minus
                num_minus = true;
            }
            else if(s[i] == '+') {
                num_minus = false;  // find plus
            }
            else if(s[i] == '(') {
                brackets_val.push(ans);
                brackets_sign.push(num_minus);
                ans = 0;
                num_minus = false;
            }
            else if(s[i] == ')') {
                int tmp = brackets_val.top();
                brackets_val.pop();

                if(brackets_sign.top()) ans = (ans * -1);
                brackets_sign.pop();

                ans += tmp;
            }
            else if(isDigit(s[i])){ // current char is a number
                int t = (s[i] - '0');
                int j = (i+1);
                while(j < s.size()) {   // 找到整串數字
                    if(isDigit(s[j])) {
                        t = t*10 + (s[j]-'0');
                        i = j;
                        j++;
                    } else break;
                }
                if(num_minus) t = t*(-1); // 此數字存為負值
                ans += t;
            }
        }
        return ans;
    }
};