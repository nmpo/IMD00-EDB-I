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
    for (size_t i = 0; i < n; ++i) {
        A[i] = rand() % 100;
    }
}

void sort(int* A, size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (A[j] < A[i]) {
                int tmp    = A[j];
                A[j] = A[i];
                A[i] = tmp;
            }

        }
    }
}

int findSum(int* A, size_t n, int t) {
    if (A[0] > t)  {
        return 0;
    }
    for (size_t left = 0, right = n - 1; left < right;) {
        int sum = A[left] + A[right];

        if (sum == t) {
            return 1;

        }

        if (sum > t) {
            right--;
        } else {
            left++;
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {

    // primeiro time
    auto tempo_inicio_c = std::chrono::high_resolution_clock::now();

    if (argc <= 2) {
        std::cout << "Usage: " << argv[0] << " <number of elements> <target sum>\n";
        return -1;
    }

    size_t n = std::atoi(argv[1]);
    size_t t = std::atoi(argv[2]);

    int* A = new int[n];

    fillRandom(A, n);
    sort(A, n);


    std::cout << findSum(A, n, t) << "\n";
    


    delete[] A;

    // encerra time 1
    auto tempo_termino_c = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double>(tempo_termino_c - tempo_inicio_c).count();
    std::cout << "/n";
}

