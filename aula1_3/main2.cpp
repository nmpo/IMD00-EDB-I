#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;

//g++ -o main2 -std=c++11 main2.cpp

/*
void searchSum(size_t* A, size_t n, size_t t){
    for (size_t i = 0; i < n -1; ++i){
        for (int j = i + 1; j < n; ++j){
            if(A[i] + A[j] == t){
                std::cout << 1 << "\n";
                return;
            }
        }
    }
    std::cout << 0 << "\n";
    return;
} */

void fillRandom(int* A, size_t n) {
    for (size_t i = 0; i < n; ++i) {//3
        A[i] = rand() % 100;//2
    }
}

void sort(int* A, size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {//3
        for (size_t j = i + 1; j < n; ++j) {//3
            if (A[j] < A[i]) {//1
                int tmp    = A[j];//1
                A[j] = A[i];//1
                A[i] = tmp;//1
            }

        }
    }
}

int findSum(int* A, size_t n, int t) {
    if (A[0] > t)  {//1
        return 0;//1
    }
    for (size_t left = 0, right = n - 1; left < right;) {
        int sum = A[left] + A[right];//6

        if (sum == t) {
            return 1;

        }

        if (sum > t) {//1
            right--;//1
        } else {
            left++;//1
        }
    }

    return 0;//1
}

int main(int argc, char* argv[]) {

    if (argc <= 2) {//1
        std::cout << "Usage: " << argv[0] << " <number of elements> <target sum>\n";
        return -1;//1
    }

    size_t n = std::atoi(argv[1]);//1
    size_t t = std::atoi(argv[2]);//1

    int* A = new int[n];//1

    fillRandom(A, n);
    auto inicio = std::chrono::high_resolution_clock::now();
    sort(A, n);

    auto inicio2 = std::chrono::high_resolution_clock::now();
    std::cout << findSum(A, n, t) << "\n";
    auto fim = std::chrono::high_resolution_clock::now();

    std::cout << duration_cast<microseconds>(fim - inicio).count() << " ; " << duration_cast<microseconds>(fim - inicio2).count() << std::endl;



    delete[] A;

    // encerra time 1
    
}

