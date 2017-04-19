#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Sentence {
    string body;
    char ending;
};

size_t split(const string &inpit, vector<Sentence> &sentences, string delimers) {
    size_t i1 { 0 };
    size_t i2 { 0 };
    do {
        i1 = i2 + 2;
    } while (i2 != string::npos);
}

int main() {
    string input;
    vector<Sentence> sentences;
    getline(cin, input);
    //cout << input;
}
