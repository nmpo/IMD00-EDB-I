#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;


//g++ -o main2 -std=c++11 main2.cpp



void fillRandom(int* A, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        A[i] = rand() % 100;
        //std::cout << A[i] << "\t";
        //if (i != 0 && i % 10 == 0){
          //  std::cout << "\n";
        //}
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
} */

int find_t(int* A, size_t n, size_t t){
    for (size_t i = 0; i < n; ++i){//3
            if(A[i] == t){//1
                return 1;//1
            }
        }

         return 0;
    }

int searchBinary(int* A,int n, int t) {
    // Na busca binária, espera-se que o vetor esteja ordenado
     
    int start= 0;//1
    int end = n-1;//2
    int half;//1
    while (start<=end) {//1
        half = (start+end)/2;//3
        if (A[half] == t)//1
            return half;//1
        else {
            if (t > A[half])//1
                start = half+1;//2
            else
                end = half-1;//2
        }
    }
    return -1;//1
}

int main(int argc, char* argv[]) { 
  
    if (argc <= 3) {//1
        std::cout << "Usage: " << argv[0] << " <number of elements> <target sum>\n";
        return -1;//1
    }
    std::srand(time(0));

    size_t n = std::atoi(argv[1]);//1
    size_t t = std::atoi(argv[2]);//1
    size_t method = std::atoi(argv[3]);//1
    int posicao, aux;
    int* A = new int[n];//1

    fillRandom(A, n);

    
    if(method == 1){//1
        auto inicio1 = std::chrono::high_resolution_clock::now();
        aux = find_t(A, n, t);
        auto fim1 = std::chrono::high_resolution_clock::now();
        if(aux == 1){//1
            std::cout << "\nO valor procurado foi encontrado." << std::endl;
        }else{
            std::cout << "\nO valor procurado não foi encontrado." << std::endl;
        }
        std::cout << "Time method 1 in microseconds: " << duration_cast<microseconds>(fim1 - inicio1).count() << ";" << std::endl;
    }
    
    
    if(method == 2){//1
        sort(A, n);
        auto inicio2 = std::chrono::high_resolution_clock::now();
        posicao = searchBinary(A, n, t);//1
        auto fim2 = std::chrono::high_resolution_clock::now();
        if (posicao==-1){//1
            std::cout << "\nO valor procurado não foi encontrado." << std::endl;
        }else{
            std::cout << "\nO valor procurado encontra-se na posição " << posicao + 1 << std::endl;
        }
        std::cout << "Time method 2 in microseconds: " << duration_cast<microseconds>(fim2 - inicio2).count() << ";" << std::endl;
    }

    

    delete[] A;

}