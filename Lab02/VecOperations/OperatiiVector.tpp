//
// Created by darian on 25/09/24.
//

template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void readArrayFromFile(const char* filename, T*& vec, int &n)
{
    std::ifstream file(filename);
    if( !file.is_open()){
        std::cerr << "\nNu se poate deschide fisierul - " << filename <<" \n";
        vec = nullptr;
        n = 0;
        return;
    }

    file >> n;
    if(n <= 0)
    {
        std::cerr << "Numar de elemente invalid.\n";
        vec = nullptr;
        n = 0;
        file.close();
        return;
    }

    vec = new T[n];

    for(int i = 0; i < n; ++i)
    {
        file >> vec[i];
    }

    file.close();
}

template<typename T>
void writeArrayToFile(const char* filename, const T* vec, int n)
{
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cerr << "Fisierul nu a putut fi deschis - " << filename << std::endl;
        vec = nullptr;
        n = 0;
        file.close();
        return;
    }

    for(int i = 0; i < n; ++i)
    {
        file << vec[i] << " ";
    }

    file.close();
}

//Algoritmi de sortare

//Bubble Sort O(N^2)
template<typename T>
void bubble_sort(T v[], int n)
{
    int swapped = 1;
    int j = 0;
    while(swapped)
    {
        swapped = 0;
        j = j + 1;
        for(int i = 0; i < n - j; ++i)
        {
            if(v[i] > v[i+1])
            {
                T tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                swapped = 1;
            }
        }
    }
}

//Selection Sort O(N^2) < O(N^2) bubble sort
template<typename T>
void sel_sort(T v[], int n)
{
    int m;
    for(int i = 0; i < n - 1; i++)
    {
        m = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(v[j] < v[m])
            {
                m = j;
            }
            swap(v[i], v[m]);
        }
    }
}

//O(n) cel mai bun O(n^2) cel mai rau
template<typename T>
void insertion_sort(T v[], int n)
{
    int i;
    for(int k = 1; k < n; ++k)
    {
        T temp = v[k];
        i = k - 1;
        while((i >= 0) && (v[i] > temp))
        {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = temp;
    }
}

template<typename T>
int partition(T vec[], int low, int high)
{
    T pivot = vec[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; ++j)
    {
        if(vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

template<typename T>
void quick_sort(T vec[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(vec, low, high);
        quick_sort(vec, low, pi - 1);
        quick_sort(vec, pi + 1, high);
    }
}

template<typename T>
void heapify(T vec[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && vec[left] > vec[largest])
    {
        largest = left;
    }

    if(right < n && vec[right] > vec[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(vec[i], vec[largest]);
        heapify(vec, n, largest);
    }
}

template <typename T>
void heapSort(T vec[], int n)
{
    for(int i = n / 2 -1; i >= 0; --i)
    {
        heapify(vec, n, i);
    }

    for(int i = n - 1; i > 0; --i)
    {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

//Algoritmi de cautare


template<typename T>
bool bruteforce_search(T vec[], int n, T b)
{
    int i = 0;
    while (i < n)
    {
        if(vec[i] == b)
        {
            return true;
        }
    }
    return false;
}


template<typename T>
bool binary_search(T vec[], int n, T b)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = ((low + high) / 2);
        if(vec[mid] == b)
        {
            return true;
        }
        else if(vec[mid] > b)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}


template<typename T>
int interpolation_search(const T vec[], int n, const T& target)
{
    int low = 0, high = n - 1;
    while(low <= high && target >= vec[low] && target <= vec[high])
    {
        if(low == high)
        {
            if (vec[low] == target) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (vec[high] - vec[low])) * (target - vec[low]));
        if(vec[pos] == target)
        {
            return pos;
        }
        if (vec[pos] < target)
        {
            low = pos + 1;
        } else
        {
            high = pos - 1;
        }
    }
    return -1;
}