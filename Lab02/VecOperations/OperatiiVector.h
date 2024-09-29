//
// Created by darian on 25/09/24.
//

#ifndef LAB02_OPERATIIVECTOR_H
#define LAB02_OPERATIIVECTOR_H

#include <iostream>
#include <fstream>

template<typename T>
void swap(T& a, T& b);

template<typename T>
void readArrayFromFile(const char* filename, T*& vec, int &n);

template<typename T>
void writeArrayToFile(const char*filename, const T *vec, int n);

//algoritmi de ordonare

template<typename T>
void bubble_sort(T* v, int n);

template<typename T>
void sel_sort(T v[], int n);

template<typename T>
void insertion_sort(T v[], int n);

template<typename T>
int partition(T vec[], int low, int high);

template<typename T>
void quick_sort(T vec[], int low, int high);

template<typename T>
void heapify(T vec[], int n, int i);

template<typename T>
void heap_sort(T vec[], int n);

//algoritmi de cautare

template<typename T>
bool bruteforce_search(T vec[], int n, T b);

template<typename T>
bool binary_search(T vec[], int n, T b);

template<typename T>
int interpolation_search(const T vec[], int n, const T& target);


#endif //LAB02_OPERATIIVECTOR_H
