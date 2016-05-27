#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int i = 0;
    int j = 0;
    int star = -1;
    int mark = -1;
    while(i < s.size()) {
        if (j < p.size()) {
            if (s[i] == p[j] || (p[j] == '?')) {
                i++;
                j++;
            }
            else if (p[j] == '*') {
                star = j;
                mark = i;
                j++;
            }
            else if (star == -1) return false;
            else {
                j = star + 1;
                i = ++mark;
            }
        } else if (star == -1) return false;
        else {
            j = star + 1;
            i = ++mark;
        }
    }
    for(; j < p.size() && p[j] == '*'; ++j);
    return j == p.size();
}

int main() { 
    cout << isMatch("mississippi", "m*issip*");
}