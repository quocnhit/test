#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string s) {
    stack<char> S; // tao stack

    bool valid = true; //ktra xem co hop le ko	

    for (int i = 0; i < s.length(); i++) {
        char c = s[i]; //lay ki tu thu i trong bieu thuc

        if (c == '(') {
            S.push(c); // day ( vao stack
        } else if (c == ')') {
            if (S.empty()) {
                valid = false; //neu stack rong khi gap ) thi bieu thuc ko hop le
                break;
            } else {
                S.pop(); //loai bo ki tu '(' tuong uong voi ')'
            }
        }
    }

    // N?u sau khi duy?t h?t bi?u th?c mà stack v?n còn ph?n t?, bi?u th?c không h?p l?
    if (!S.empty()) {
        valid = false;
    }

    return valid;
}

int main() {
    string expression;
    cout << "Nhap bieu thuc: ";
    getline(cin, expression);

    if (check(expression)) {
        cout << "Bieu thuc hop le." << endl;
    } else {
        cout << "Bieu thuc khong hop le." << endl;
    }

    return 0;
}

