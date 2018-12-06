#include <iostream>
#include <string.h>
#include "Biblioteca.h"
using namespace std;

//LIVRO

int Livro::operator==(const Livro &l)const{


}

//ITEM EMPRESTIMO

ItemEmprestimo::ItemEmprestimo(Livro l):livro(l){
	//dataDevolucao.DataNula();
}

Livro ItemEmprestimo::getLivro(){
	return livro;
}

//Contador 
int Emprestimo::proximoNumero = 0;

//EMPRESTIMO 

Emprestimo::Emprestimo(Usuario usu, Date dataPrevDev):usuario(usu),dataPrevDevolucao(dataPrevDev){
	numero = proximoNumero;
	//Inicializar DataEmprestimo com a Data Corrente (Will)
}

void Emprestimo::adicionarLivro(Livro nomeLivro){
	ItemEmprestimo A(nomeLivro);
	itens.push_back(A); //Acrescenta A ao final da fila!
	nomeLivro.decrementar(); //Testar se pode decrementar na classe Livro
}

void Emprestimo::excluirLivro(Livro nomeLivro){
	for(int i = 0; i < itens.size(); i++){
	//	if ( itens[i].getLivro == nomeLivro){
			
	//	}
	}
}
