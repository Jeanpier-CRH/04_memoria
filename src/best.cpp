#include <iostream>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int originalBlockSize[m];

    // Cargas el tamano de bloques original antes de la modifcacion
    for (int i = 0; i < m; i++)
        originalBlockSize[i] = blockSize[i];

    // Inicializar el array allocation
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    // Best Fit Allocation
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        // Si allocate ha sido encontrado
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] = -1; // Marcar el bloque como usado
        }
    }

    // Imprimir resultados
    cout << "No. Proceso\tTamano de proceso\tNo. Bloque Asignado" << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t\t" << processSize[i] << "\t\t\t";
        if (allocation[i] != -1) 
		cout << (allocation[i] + 1);
        else
            cout << "No asignado";
        cout << endl;
    }
}

int main() {
    int blockSize[] = {6, 5, 50, 20, 14};
    int processSize[] = {4, 10, 15, 20, 23};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);
    return 0;
}
