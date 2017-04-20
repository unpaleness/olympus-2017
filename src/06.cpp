#include <iostream>
#include <vector>

using namespace std;

int main () {
    int input, y, output = 0;
    cin >> input;
    vector<int> number;
    for (int x = 2; x < input; x++) {
        for (y = 2; y <= (x / y); y++)
            if (!(x % y)) break;
        if (y > (x / y)) number.push_back(x);
    }

    int ggg = number.size(), k=0;

    if (input % 2 == 0) {
        ggg++;
        k = 1;
    }

    for (int i = 0; i <= ggg / 2; i++) {
        for (int j = ggg / 2; j < ggg - k; j++) {
            if (number[i] + number[j] == input) {
                output++;
            }
        }
    }

    cout << output << endl;

    return 0;
}