#include <iostream>

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::nanoseconds;

using namespace std;

const int SIZE = 5;
int graph1[SIZE][SIZE];
int graph2[SIZE][SIZE];
int graph3[SIZE * 2][SIZE * 2];

void createAdjacencyMatrix(int matrix[][SIZE]);
void displayMatrix(int matrix[][SIZE]);
void combineGraphs(int g1[][SIZE], int g2[][SIZE]);
void displayCombined(int matrix[][SIZE * 2]);

int main()
{
    // generate first graph 
    createAdjacencyMatrix(graph1);
    displayMatrix(graph1);

    // generate second graph 
    createAdjacencyMatrix(graph2);
    displayMatrix(graph2);

    combineGraphs(graph1, graph2);
    displayCombined(graph3);
}

// creates matrix to represent a circle graph
void createAdjacencyMatrix(int matrix[][SIZE]) {
    int weight;
    for (int i = 0; i < SIZE; i++) {
        weight = rand() % 9 + 1;
        matrix[i][i + 1] = weight;
        matrix[i + 1][i] = weight;
    }

    // adds connection between first and last node to complete circle
    if (SIZE > 2) {             
        weight = rand() % 9 + 1;
        matrix[0][SIZE - 1] = weight;
        matrix[SIZE - 1][0] = weight;
    }
}

void displayMatrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void combineGraphs(int g1[][SIZE], int g2[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph3[i][j] = g1[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph3[i + 5][j + 5] = g2[i][j];
        }
    }
    
    // add two edges between two nodes in first and second graph
    int randomNode1 = rand() % (SIZE - 1);
    int randomNode2 = rand() % (SIZE - 1);
    int weight = rand() % 9 + 1;
    graph3[randomNode1][randomNode2 + 5] = weight;
    graph3[randomNode2 + 5][randomNode1] = weight;
    cout << "Added edge between G[" << randomNode1 << "] and H[" << randomNode2 << "]" << endl;
    randomNode1 = rand() % (SIZE - 1);
    randomNode2 = rand() % (SIZE - 1);
    weight = rand() % 9 + 1;
    graph3[randomNode1][randomNode2 + 5] = weight;
    graph3[randomNode2 + 5][randomNode1] = weight;
    cout << endl << "Added edge between G[" << randomNode1 << "] and H[" << randomNode2 << "]" << endl;
}

void displayCombined(int matrix[][SIZE * 2]) {
    cout << endl;
    for (int i = 0; i < SIZE * 2; i++) {
        for (int j = 0; j < SIZE * 2; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}
