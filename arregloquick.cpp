#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostrar(int b[], int arreglo) {
    for (int i = 0; i < arreglo; i++)
        cout << b[i] << " ";

    cout << endl;
}

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int particion(int a[], int inicio, int fin) {
    int pivote = a[fin];
    int i = (inicio - 1);

    for (int j = inicio; j <= fin - 1; j++) {
        if (a[j] < pivote) {
            i++;
            intercambiar(a[i], a[j]);
        }
    }
    intercambiar(a[i + 1], a[fin]);
    return (i + 1);
}

void quicksort(int a[], int inicio, int fin) {
    if (inicio < fin) {
        int indiceParticion = particion(a, inicio, fin);

        quicksort(a, inicio, indiceParticion - 1);
        quicksort(a, indiceParticion + 1, fin);
    }
}

int main() {
    const int arreglo = 20;
    int a[arreglo];

    srand(time(0));
    for (int i = 0; i < arreglo; i++)
        a[i] = 1 + rand() % 100;

    cout << "Arreglo original:" << endl;
    mostrar(a, arreglo);

    quicksort(a, 0, arreglo - 1);

    cout << "Arreglo ordenado usando QuickSort:" << endl;
    mostrar(a, arreglo);

    system("pause");
    return 0;
}

