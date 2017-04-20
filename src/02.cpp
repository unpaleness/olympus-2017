#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string find_target(const string &text, const string &unique) {
    string target = text;
    for (size_t len = unique.size(); len <= text.size(); ++len) {
        bool is_target { false };
        for (size_t i = 0; i < text.size() + 1 - len; ++i) {
            target = text.substr(i, len);
            bool is_unique { true };
            for (size_t j = 0; j < unique.size(); ++j) {
                if (target.find(unique[j]) == string::npos) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                is_target = true;
                break;
            }
        }
        if (is_target) {
            break;
        }
    }
    return target;
}

int main() {
    string text;
    string unique;
    cin >> text;
    for (size_t i = 0; i < text.size(); ++i) {
        if (unique.find(text[i]) == string::npos) {
            unique += text[i];
        }
    }
    sort(unique.begin(), unique.end());
    string target;
    target = find_target(text, unique);
    cout << target << endl;
}
