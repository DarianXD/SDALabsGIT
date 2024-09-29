#include <iostream>
#include <chrono>
#include "VecOperations/OperatiiVector.h"

/*
 * Sortarea vectorului, inainte de anumite operatii precum cautare, modificare, verificare unicitate element din vector reduce timpul acestor operatii.
 * Operatia de sortare e eficienta in general, daca se aplica pe vectori si nu pe alte structuri de date(liste, arbori, hash tables)
 * Eficienta algoritmilor de sortare e intre O(n^2) si O(n*log(n))
 *
 */


//Algorithm complexity, arrays
//Complexitatea spatiul. Tablouri


int main() {
    int *vec = nullptr, n = 0;
    const char *filename = "/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/input.txt";
    const char* filename1 = "/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/output.txt";
    readArrayFromFile(filename, vec, n);

    auto start = std::chrono::high_resolution_clock::now();

    insertion_sort(vec, n);

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Timpul de exec al sortarii : " << duration.count() << "microsecunds" << std::endl;

    writeArrayToFile(filename1, vec, n);
    return 0;
}
