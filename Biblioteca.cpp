#include <iostream>
#include <string.h>
#include "Biblioteca.h"

using namespace std;
//DATE

int Date::operator==(Date &d){ 
	if( mes == d.mes && ano == d.ano && mes == d.mes){
		return true;
	}
	return false;
};

//LIVRO

//Esta errado so fiz pr testar, falta testar se as outras variaveis sao iguais
//Observação importante para o Will (necessario fazer um get para todos os atributos) 
int Livro::operator==(const Livro &l)const{
	if (this->getTitulo() == l.getTitulo()){
		return true;
	} 
	return false;

}

//ITEM EMPRESTIMO

ItemEmprestimo::ItemEmprestimo(Livro l):livro(l){
	dataDevolucao.DataNula();
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

void Emprestimo::adicionarLivro(Livro &nomeLivro){
	ItemEmprestimo A(nomeLivro);
	itens.push_back(A); //Acrescenta A ao final da fila!
	nomeLivro.decrementar(); //Testar se pode decrementar na classe Livro
}

void Emprestimo::excluirLivro(Livro &nomeLivro){

	//Tem que fazer o operador de == de livros
	int i;
	Date a;
	a.DataNula();
	
	for( i = 0; i < itens.size(); i++){
		 
		if ( nomeLivro == itens[i].getLivro()){
		
			itens.erase(itens.begin() + i); //Exlui o item 
	
			//Se for diferente é pq ja foi devolvido
			if(itens[i].getDataDev() == a ){
				nomeLivro.incrementar();
			}
			break; //sai do loop
		}
	}
	
	//Se pecorreu todo o vetor  significa que não encontrou
	if(i == itens.size()){
		throw Erro("Livro não encontrado");
	}
	
}

void Emprestimo::devolverLivro(Livro &nomeLivro){
	
	//Tem que fazer o operador de == de livros
	int i;
	
	for( i = 0; i < itens.size(); i++){
		 
		if ( nomeLivro == itens[i].getLivro()){
			// Como devolver um item ??? Devo exlui -lo da lista???
			nomeLivro.incrementar();
			itens[i].setDataDev();
			break; //sai do loop
		}
	}
	
	//Se pecorreu todo o vetor  significa que não encontrou
	if(i == itens.size()){
		throw Erro("Livro não encontrado");
	}
	
}

void Emprestimo::devolverTodosOsLivros(){
	
	for( int i = 0; i < itens.size(); i++){
		 
			Livro a = itens[i].getLivro(); //Sobrecarregar o operador = ou fazer construção por coia
			// Como devolver um item ??? Devo exclui -lo da lista??? Acho que não.
			a.incrementar();
			itens[i].setDataDev();
	
	}
	
}

