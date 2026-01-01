#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int open = 0;
int close = 0;
vector<string> result;


void paren(int n, string res) {
    if (open == close && open== n) {
        result.push_back(res);
        return;
    }

    if (open < n) {
        res.append("(");
        open++;
        paren(n, res);
        res.erase(res.size(), 1);
    }

    if (close < open) {
        res.append(")");
        close++;
        paren(n, res);
        res.erase(res.size(), 1);
    }
}

vector<string> generateParenthesis(int n) {
    if (n == 1) return {"()"};
    string res = "";
    paren(n, res);
    return result;
}



int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for (const auto& s : result) {
        printf("%s\n", s.c_str());
    }
}