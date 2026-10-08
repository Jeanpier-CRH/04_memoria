#include <iostream>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    int j = 0; // Puntero que recuerda la última posición

    for (int i = 0; i < n; i++) {
        int count = 0;
        while (count < m) {
            int idx = j % m; 
            if (blockSize[idx] >= processSize[i]) {
                allocation[i] = idx;
                blockSize[idx] -= processSize[i];
                j = idx + 1; // Avanza al siguiente bloque para el próximo proceso
                break;
            }
            j++;
            count++;
        }
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
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 301};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    nextFit(blockSize, m, processSize, n);
    return 0;
}