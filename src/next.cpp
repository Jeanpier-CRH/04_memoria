#include <iostream>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
            j++;
        }
        if (j == m)
            j = 0;
    }

    cout << "No. Proceso\tTamano de proceso\tNo. Bloque Asignado" << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t\t" << processSize[i] << "\t\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "No asignado";
        cout << endl;
    }
}

int main() {
    int blockSize[] = {14, 11, 54, 13};
    int processSize[] = {10, 25, 33, 50};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    nextFit(blockSize, m, processSize, n);
    return 0;
}
