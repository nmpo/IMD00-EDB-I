#include <iostream>
#include <cstdlib>
//g++ --std=c++11 main.cpp ou g++ -o programa -std=c++11 main.cpp

int main(int argc, char* argv[]) {
                                    //contando
                                    //instrucoes
    size_t num = std::atoi(argv[1]);//1


    // 1. usar a free store (new e delete)
    // 2. receber o N pelo argv (atoi)
    
    int* numeros = new int[num];//1

    for (size_t i = 0; i < num; ++i) {//3
        numeros[i] = rand() % num;//2
    }

    //ornedar

    for (size_t i = 0; i < num - 1; ++i) {//3
        for (size_t j = i + 1; j < num; ++j) {//3
            if (numeros[j] < numeros[i]) {//1
                int tmp    = numeros[j];//1
                numeros[j] = numeros[i];//1
                numeros[i] = tmp;//1
            }

        }
    }


    for (size_t i = 0; i < num; ++i) {//3
        std::cout << numeros[i] << "\n";
    }

    delete[] numeros;
}

