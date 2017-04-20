#include <iostream>
#include <string>

using namespace std;

int main() {
    int step = 0;
    int P = 0;
    string strin;
    string  strout;
    string strAlf;

    cin >> step;
    cin >> P;
    getline(cin, strout);
    getline(cin, strAlf);
    getline(cin, strin);
    strout.clear();

    if (P == 1) {
        for (size_t i = 0; i < strin.size(); i++) {
            for (size_t j = 0; j < strAlf.size(); j++) {
                if (strin[i] == strAlf[j]) {
                    size_t smes = j + step;
                    if (smes >= strAlf.size()) {
                        smes = smes % strAlf.size();
                    }
                    strout = strout+ strAlf[smes];
                }
            }
        }
        cout << strout;
    }
    if (P == 0) {
        strout = strin;
        strin = "";
        for (size_t i = 0; i < strout.size(); i++) {
            for (size_t j = 0; j < strAlf.size(); j++) {
                if (strout[i] == strAlf[j]) {
                    int smes = j - step;
                    if (smes < 0) {
                        if ((step-j) < strAlf.size()) {
                            smes = strAlf.size() - (step - j);
                        } else {
                            smes = strAlf.size() - (step - j) % strAlf.size();
                        }
                    }
                    strin = strin + strAlf[smes];
                }
            }
        }
        cout << strin;
    }
    return 0;
}
