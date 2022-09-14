#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz():
	linhas(0), colunas(0)
{}

Matriz::Matriz(int l, int c):
	linhas(l), colunas(c)
{
	
}

int Matriz::getLinhas(){
	return linhas;
}
void Matriz::setLinhas(int l){
	linhas = l;
}
int Matriz::getColunas(){
	return colunas;
}
void Matriz::setColunas(int c){
	colunas = c;
}