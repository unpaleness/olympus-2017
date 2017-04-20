#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

size_t find_target(const string &text, const string &unique, string &target, size_t d) {
    for (size_t i = 0; i < d; ++i) {
        // cout << ' ';
    }
    // cout << text << endl;
    if (text.size() == 0 || text.size() < unique.size()) {
        return 0;
    }
    if (text.size() == unique.size()) {
        target = text;
        return text.size();
    }
    bool is_target = true;
    for (size_t i = 0; i < unique.size(); ++i) {
        if (text.find(unique[i]) == string::npos) {
            is_target = false;
            break;
        }
    }
    if (!is_target) {
        return 0;
    }
    string daughter1;
    size_t length_daughter1 = find_target(text.substr(0, text.size() - 1), unique, daughter1, d + 1);
    string daughter2;
    size_t length_daughter2 = find_target(text.substr(1, text.size() - 1), unique, daughter2, d + 1);
    if (length_daughter1 > 0 && length_daughter1 <= length_daughter2) {
        target = daughter1;
        return target.size();
    }
    if (length_daughter2 > 0) {
        target = daughter2;
        return target.size();
    }
    target = text;
    return text.size();
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
    //cout << unique << endl;
    string target;
    find_target(text, unique, target, 0);
    cout << target << endl;
}
