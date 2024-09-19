#include <iostream>
using namespace std;

 struct Student {
    char* nume;
    int nota;
};

void SwapV(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void SwapR(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

void Schimba(Student** unu, Student** doi) //schimbare de pointeri
{
    Student* trei;
    trei = *unu;
    *unu = *doi;
    *doi = trei;
}

void Schimba(Student*& unu, Student*& doi)
{
    Student* trei;
    trei = unu;
    unu = doi;
    doi = trei;
}

int main() {
    Student s1, s2;
    Student grupa[5];
    Student *ps;
    Student *idx[5];
    int *pi;
    pi = new int(5);
    std::cout << pi << std::endl;
    std::cout << *pi;
    std::cout << "Hello, World!" << std::endl;
    free(pi);
    pi = nullptr;
    int x = 2, y = 3;
    SwapV(&x, &y);
    std:: cout << x << " " << y << " " << std::endl;
    SwapR(x, y);
    std:: cout << x << " " << y << " " << std::endl;
    int i = 0;
    if(i == NULL)
        std::cout << "Miau";
    else
        std::cout <<"Ham";

    int iVal;
    char sVal[30];
    cout << "Introduceti un numar: ";
    cin >> iVal;
    cout << "Si un sir de caractere: ";
    cin >> sVal;
    cout << "Numarul este: " << iVal << "\n"
         << "Sirul este: " << sVal << endl;

    return 0;
}
