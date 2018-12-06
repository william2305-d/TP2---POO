#include <iostream>
#include <string.h>
#include <time.h>
#include "Biblioteca.h"
using namespace std;

void Publicacao::setCodPublicacao(int codPublicacao){
	
}

Livro::Livro(string aut, int codP, string tit, string ed, int a,int qtdeE){
	autores = aut;
	qtdeExemplares = qtdeE;
	setCodPublicacao(codP);
	setTitulo(tit);
	setEditora(ed);
	setAno(a);
}
