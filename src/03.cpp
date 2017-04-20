#include <iostream>

using namespace std;

void step(int, int, int**, int*, int*);

int main() {
    int n, k, temp1, temp2;
    cin >> n >> k;
    int mas[n + 1][n + 1], used[n + 1], vin_lose[n + 1];;
    int* mass[n + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            mas[i][j] = 0;
        }
    used[i] = 0;
    vin_lose[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> temp1 >> temp2;
        mas[temp1][temp2]++;
        mas[temp2][temp1]++;
    }
    for (int i = 1; i < n+1; i++) {
            mass[i] = mas[i];
    }
    step(k, n, mass, used, vin_lose);
    for (int i = 1; i <= n; i++) {
        if (!vin_lose[i] && mas[k][i]) {
            cout << "First player visiting hall " << i << " wins"<< endl;
            return 0;
        }
    }
    cout << "First player loses" << endl;
    return 0;
}

void step(int k, int n, int** mass, int* used, int* vin_lose){
    used[k] = 1;
    vin_lose[k] = 0;
    for (int i = 1; i < n + 1; i++) {
        if (mass[k][i] && !used[i]) {
            step(i, n, mass, used, vin_lose);
            if (vin_lose[i] == 0)
                vin_lose[k] = 1;
        }
    }
}
