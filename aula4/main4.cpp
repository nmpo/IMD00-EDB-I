#include <iostream>
#include <cstdlib>
#include <chrono>

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

int searchId(size_t* A, size_t n, size_t t){
    for (size_t i = 0; i < n; ++i){
            if(A[i] == t){
                return 1;
            }
        }

         return 0;
    }

int main(int argc, char* argv[]) {

	size_t n = std::atoi(argv[1]);
    size_t t = std::atoi(argv[2]);

    int* A = new int[n];



    fillRandom(A, n);
    //sort(A, n);

    std::cout << searchId(A, n, t) << "\n";









    delete[] A;

}