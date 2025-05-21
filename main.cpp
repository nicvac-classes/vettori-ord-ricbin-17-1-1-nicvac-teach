#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));
    
    int n, i, j;

    cout << "Quanti numeri casuali generare?" << endl;
    cin >> n;
    vector<int> v(n);

    // Carico il vettore con valori casuali
    i = 0;
    while (i < n) {
        v[i] = rand() % 100;
        i = i + 1;
    }

    // Ordinamento del vettore
    int t;
    bool scambio;

    scambio = true;
    i = 0;
    while (i <= n - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= n - 2 - i) {
            if (v[j] > v[j + 1]) {
                scambio = true;
                t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    // Visualizzo il vettore ordinato
    i = 0;
    while (i < n) {
        cout << "V[" << i << "]=" << v[i] << endl;
        i = i + 1;
    }

    // Chiedo il numero da cercare, visualizzo la sua posizione nel vettore.
    int valore;

    cout << "Inserire il valore da cercare: " << endl;
    cin >> valore;

    // Ricerco il valore con il metodo sequenziale
    cout << "Ricerca sequenziale 🐌🐌🐌" << endl;
    int indice, numControlli;

    numControlli = 0;
    indice = -1;
    i = 0;
    while (i <= n - 1 && indice == -1) {
        numControlli = numControlli + 1;
        if (valore == v[i]) {
            indice = i;
        }
        i = i + 1;
    }
    cout << "Controlli eseguiti: " << numControlli << endl;
    cout << "Il valore è stato trovato in nella cella " << indice << endl;

    // Ricerco il valore con il metodo della ricerca binaria
    cout << "Ricerca binaria 🏎️🏎️🏎️" << endl;
    int inizio, fine, medio;

    numControlli = 0;
    indice = -1;
    inizio = 0;
    fine = n - 1;
    while (inizio <= fine && indice == -1) {
        medio = inizio + (double) (fine - inizio) / 2;
        numControlli = numControlli + 1;
        if (valore == v[medio]) {
            indice = medio;
        } else {
            numControlli = numControlli + 1;
            if (valore > v[medio]) {
                inizio = medio + 1;
            } else {
                fine = medio - 1;
            }
        }
    }
    cout << "Controlli eseguiti: " << numControlli << endl;
    cout << "Il valore è stato trovato in nella cella " << indice << endl;
    
}
