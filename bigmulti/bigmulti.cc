#include <string>
#include <iostream>
using namespace std;

inline int toInt(char c) {
    return c - '0';
}

bool BigMul(const string& a, const string& b, string* c) {
    cout<<a.length()<<endl;
    cout<<b.length()<<endl;
    c->resize(a.size() + b.size() + 1, '0');
    cout<<c->size()<<endl;

    int csize = c->size() - 1;
    int mul = 0;

    for (int i = a.size() -1; i >=0; i--) {
        int jinwei = 0;
        int k = csize--;

        for (int j = b.size() - 1; j >=0; j--) {
            mul = toInt(a[i]) * toInt(b[j]) + jinwei;
            mul += toInt((*c)[k]);
            jinwei = mul / 10;
            (*c)[k--] = (mul % 10) + '0';
        }
        if (jinwei) {
            (*c)[k] = jinwei + '0';
        }
    }
    return true;
}

int main() {
    string a = "789";
    string b = "789";
    string c;
    BigMul(a, b, &c);
    cout<<c<<endl;
}
