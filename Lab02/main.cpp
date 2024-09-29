#include <iostream>
#include <chrono>
#include "VecOperations/OperatiiVector.h"
#include <vector>
#include <random>


/*
 * Sortarea vectorului, inainte de anumite operatii precum cautare, modificare, verificare unicitate element din vector reduce timpul acestor operatii.
 * Operatia de sortare e eficienta in general, daca se aplica pe vectori si nu pe alte structuri de date(liste, arbori, hash tables)
 * Eficienta algoritmilor de sortare e intre O(n^2) si O(n*log(n))
 *
 */


//Algorithm complexity, arrays
//Complexitatea spatiul. Tablouri


int main() {

    std::vector<int> vec_random(40000);
    std::vector<int> vec_best_case(40000);
    std::vector<int> vec_worst_case(40000);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10000);

    for(int& val : vec_random) {
        val = dis(gen);
    }

    std::ofstream fout("/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/random_case.txt");
    std::ofstream fout1("/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/best_case.txt");
    std::ofstream fout2("/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/worst_case.txt");

    fout << vec_random.size() << std::endl;
    fout1 << vec_best_case.size() << std::endl;
    fout2 << vec_worst_case.size() << std::endl;


    for(const int& val : vec_random){
        fout << val << " ";
    }
    for(int i = 0; i < vec_best_case.size(); ++i)
    {
        fout1 << i << " ";
    }
    for(int i = 0; i < vec_worst_case.size(); ++i)
    {
        fout2 << vec_worst_case.size() - i << " ";
    }
    fout.close();
    fout1.close();
    fout2.close();


    int *vec_random1 = nullptr, *vec_worst_case1 = nullptr, *vec_best_case1 = nullptr, n = 0;
    const char *filename = "/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/random_case.txt";
    const char* filename1 = "/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/best_case.txt";
    const char* filename2 = "/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/worst_case.txt";
    const char* filename3 = "/home/darian/Documents/FAANGPath/SD/LaboratoareGIT/Lab02/Files/output.txt";

    readArrayFromFile(filename, vec_random1, n);
    readArrayFromFile(filename1, vec_best_case1, n);
    readArrayFromFile(filename2, vec_worst_case1, n);


    auto start1 = std::chrono::high_resolution_clock::now();

    insertion_sort(vec_random1, n);

    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    std::cout << "Timpul de exec al sortarii pentru RANDOM_CASE : " << duration1.count() << "microsecunds" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();

    insertion_sort(vec_best_case1, n);

    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    std::cout << "Timpul de exec al sortarii pentru BEST_CASE : " << duration2.count() << "microsecunds" << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    insertion_sort(vec_worst_case1, n);
    auto stop3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);

    std::cout << "Timpul de exec al sortarii pentru WORST_CASE : " << duration3.count() << "microsecunds" << std::endl;


    writeArrayToFile(filename3, vec_random1, n);
    return 0;
}
