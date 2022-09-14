#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>

using namespace std;

class Matriz
{
private:
	int linhas;
	int colunas;
public:
	Matriz();
	Matriz(int l, int c);
	//get & set
	int getLinhas();
	void setLinhas(int l);
	int getColunas();
	void setColunas(int c);

	
};

#endif //MATRIZ_H