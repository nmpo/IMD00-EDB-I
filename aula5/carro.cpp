#include <iostream>
#include<string>

using namespace std;

struct Carro{
	std::string nome;
	unsigned short ano;
};
	//RAII C++
struct CarrosDB{
	Carros(size_t qtdCarros)
		qtdMax(qtdMax),
		qtdCarros(0)
	{
		carros = new Carro[qtdMax];
	}

	~CarrosDB(){
		delete[] carros;
	}

	size_t qtdMax;
	size_t qtdCarros;
	Carro* carros;
	//finalizado o cabeçalho, inicio das funcoes da struct

	//a qtd máxima de carros
	void qtdMax(size_t qtdMax_){
		qtdMax = qtdMax_;
		carros = new Carro[qtdMax_];
		qtdCarros = 0;
	}
	//adicionar carro até a quantidade máxima
	void addCarro (Carro umCarro){
		if (qtdCarros < qtdMax){ //se a qtd for menor que a máx, add
			carro[qtdCarros++] = umCarro; //add na posicao e atribui +1 em qtd de carros
		}
	}
	//final da funcao de adicionar carro

	//verificar se tem um carro com um ano específico X
	void sort(int* CarrosDB, size_t qtdCarros) {
	    for (size_t i = 0; i < qtdCarros - 1; ++i) {
	        for (size_t j = i + 1; j < qtdCarros; ++j) {
	            if (CarrosDB.ano[j] < CarrosDB.ano[i]) {
	                int tmp = CarrosDB.ano[j];
	                CarrosDB.ano[j] = CarrosDB.ano[i];
	                CarrosDB.ano[i] = tmp;
	            }

	        }
	    }
	}
	int searchBinary(int* CarrosDB,size_t qtdCarros, int anoX) {
	     
	    int start= 0;
	    int end = qtdCarros-1;
	    int half;
	    while (start<=end) {
	        half = (start+end)/2;
	        if (CarrosDB.ano[half] == anoX)
	            return half;
	        else {
	            if (anoX > CarrosDB.ano[half])
	                start = half+1;
	            else
	                end = half-1;
	        }
	    }
	    return -1;
	}
	//finalizada a busca binária
};

int main(int argc, char* argv[]) {

	size_t anox = std::atoi(argv[1]);
	int vaga;
	CarrosDB db(10);

	CarrosDB carrosdb;
	Carro carros;
	//informa a qtd de carros e máxima
	cout << "Quantidade de carros: " << carrosdb.qtdCarros << " de uma capacidade máxima de " << carrosdb.qtdMax << " carros." << endl;
	
	//verifica de imprime se tem carro de um ano X
	vaga = searchBinary(carrosdb, qtdCarros, anoX);
	if (vaga==-1){
            std::cout << "\nO carro deste ano não foi encontrado." << std::endl;
        }else{
            std::cout << "\nO carro deste ano encontra-se na vaga " << vaga+ 1 << std::endl;
        }
	return 0;
}
