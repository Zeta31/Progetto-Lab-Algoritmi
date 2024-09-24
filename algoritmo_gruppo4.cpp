#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

/* OPZIONI */
#define _DEBUG // decommentare per la modalità debug
// #define _TEST       // decommentare per effettuare i test
#define NUM_TEST 15 // numero di test presenti nella cartella "tests"

/* MACRO */
#define top_cell(c, N) (c >= N ? c - N : -1)             // macro per ottenere l'indice valido della cella sopra
#define right_cell(c, N) (c % N < N - 1 ? c + 1 : -1)    // macro per ottenere l'indice valido della cella destra
#define bottom_cell(c, N) (c < N * (N - 1) ? c + N : -1) // macro per ottenere l'indice valido della cella sotto
#define left_cell(c, N) (c % N > 0 ? c - 1 : -1)         // macro per ottenere l'indice valido della cella sinistra

int algoritmo(ifstream *in)
{
    /* LETTURA DEL FILE */
    int N;    // valore N in input
    *in >> N; // lettura del valore N dal file

    if (N < 1 || N > 100) // requisito del problema
    {
        return -1;
    }

    char value_reader;                 // variabile per la lettura del file
    int square[N * N];                 // inizializzo l'array che conterrà i valori del square
    queue<int> Q;                      // inizializzo la coda per la multiple source BFS
    int visited_distance[N * N] = {0}; // inizializzo l'array che conterrà i minimi delle distanze da un 3
    int max_of_min_distances = -1;     // inizializzo la variabile che conterrà il massimo delle distanze minime da un 3.
                                       // Inizializzo a -1 sia per essere garantire che venga sostituito al primo valore e sia perchè in caso di errore ritornerà - 1

#ifdef _DEBUG
    cout << "Q: ";
#endif

    for (int i = 0; i < N * N; i++)
    {
        *in >> value_reader;            // leggo il carattere dal file
        square[i] = value_reader - '0'; // leggo carattere per carattere traducendolo in int
        if (square[i] == 3)             // memorizzo le posizioni dei 3 nella matrice
        {
            Q.push(i); // inserisco i 3 nella coda
#ifdef _DEBUG
            cout << i << " ";
#endif
        }
    }

#ifdef _DEBUG
    cout << endl;
    cout << "square: " << endl;
    for (int i = 0; i < N * N; i++)
    {
        cout << square[i] << " ";
    }
    cout << endl
         << endl;

#endif

    /* multiple souse BFS*/
    while (!Q.empty()) // continua fino a quanto la coda è vuota cioè fino a quando tutte le celle saranno state visitate
    {

        int current_index = Q.front(); // prendo l'indice in prima posizione della coda
        Q.pop();                       // rimuovo l'elemente in prima posizione
#ifdef _DEBUG
        cout << "Pop: " << current_index << endl;
#endif

        if (square[current_index] == 1 && visited_distance[current_index] > max_of_min_distances) // se la cella corrente è un 1 e la sua distanza dal 3 più vicino è maggiore del massimo delle distanze minime da un 3 allora
        {
            max_of_min_distances = visited_distance[current_index]; // assegnane il valore
        }

        int index_of_adjacent_cells[4] = {top_cell(current_index, N),
                                          right_cell(current_index, N),
                                          bottom_cell(current_index, N),
                                          left_cell(current_index, N)}; // array che memorizza gli indici delle celle adiacenti

        for (int i = 0; i < 4; i++) // per tutte le celle adiacenti
        {
            if (index_of_adjacent_cells[i] != -1 && visited_distance[index_of_adjacent_cells[i]] == 0 && square[index_of_adjacent_cells[i]] != 3) // se ha un indice valido (cioè se non siamo sforati dalla matrice) e se la cella non è stata ancora visitata e se la cella non è un 3
            {
                Q.push(index_of_adjacent_cells[i]);                                                 // inserisci l'indice nella coda
                visited_distance[index_of_adjacent_cells[i]] = visited_distance[current_index] + 1; // aggiorna la distanza della cella a quella attuale + 1
#ifdef _DEBUG
                cout << "Aggiunto alla coda: " << index_of_adjacent_cells[i] << endl;
#endif
            }
        }

#ifdef _DEBUG

        cout << "Visited_distance: " << endl;
        for (int i = 0; i < N * N; i++)
        {
            cout << visited_distance[i] << " ";
        }
        cout << endl;
        cout << "max_of_min_distances: " << max_of_min_distances << endl;
        cout << endl;

#endif
    }
    return max_of_min_distances; // ritorno il massimo delle distanze minime
}

/**
 * @brief Esecuzione dei test e verica della corretta implementazione
 *
 */
void executeTests()
{
    ifstream file_soluzioni("tests/soluzioni.txt");
    if (!file_soluzioni)
    {
        cout << "File soluzioni non trovato!" << endl;
        return;
    }

    cout << "/ Esecuzione tests..." << endl;
    int correct_solution_sum = 0;
    for (int i = 0; i < NUM_TEST; i++)
    {
        ifstream in("tests/" + to_string(i) + ".txt");
        if (!in)
        {
            cout << "| [!] Test [" << i << "] File non trovato!" << endl;
        }
        else
        {
            int soluzione;
            int risultato = algoritmo(&in);
            file_soluzioni >> soluzione;

            if (risultato == soluzione)
            {
                correct_solution_sum++;
            }
            else
            {
                cout << "| [!] Test [" << i << "] fallito! Ottenuto " << risultato << " - Aspettato " << soluzione << endl;
            }
        }
    }

    cout << "| Test passati [" << correct_solution_sum << "/" << NUM_TEST << "]" << endl;
}

/**
 * @brief Esecuzione dell'algoritmo con inpu file
 *
 * @param pathfile percorso del file in cui è presente l'input
 */
void executeInput(string pathfile)
{
    ifstream in(pathfile);
    if (in)
    {
        cout << algoritmo(&in) << endl;
    }
    else
    {
        cout << "File non trovato!" << endl;
    }
}

int main(int argc, char const *argv[])
{

#ifdef _TEST
    executeTests();
#else
    executeInput("input.txt");
#endif

    return 0;
}