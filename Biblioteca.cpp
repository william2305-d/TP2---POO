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

//USUARIO

int Usuario::operator==(const Usuario &u)const{
	if( nome == u.nome && cpf == u.cpf && endereco == u.endereco && fone == u.fone){
		return true;
	}
	return false;
}

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



//EMPRESTIMO 

//Contador 
int Emprestimo::proximoNumero = 0;

Emprestimo::Emprestimo(Usuario usu, Date dataPrevDev):usuario(usu),dataPrevDevolucao(dataPrevDev){
	Date a;
	a.DataCorrente();
// Tirar De Comentario apos implementar getDataPen();
//	if(usu.getDataPen() <= a ){
//		throw Erro("Usuario esta Penalizado");
//	}
	numero = proximoNumero;
	dataEmprestimo.DataCorrente();
	
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

//BIBLIOTECA

//Construtor para inicializar as listas
Biblioteca::Biblioteca(){
	//Mesmo ao inicializar, ja começa como vazio, decidi remendicionar para 0;
	emprestimos.resize(0);
	usuarios.resize(0);
	livros.resize(0);
}

//Metodos para inserir

void Biblioteca::novoUsuario(const Usuario &u){
	usuarios.push_back(u);
}

void Biblioteca::novoEmprestimo(const Emprestimo &e){
	emprestimos.push_back(e);
}

void Biblioteca::novaPublicacao(const Publicacao &p){ //Precisa de função virtual ? Para livro ser reconcedo como publicação?
	livros.push_back(p);
}

void Biblioteca::novoItemEmprestimo(Emprestimo &e, ItemEmprestimo &i){
	e.adcItemEmprestimo(i);
}

//Metodos para exlusão 
//Todos tem seu tratamento de excessões!!! Lembrar de usar try and catch no main

void Biblioteca::excluiUsuario(const Usuario &u){
 //Primeiro ,tem que saber se o usuario existe
 //Fazer uma busca no vetor usuarios  
 	int j;
	for(j= 0; j < usuarios.size(); j++){
		if(usuarios[j] == u){
			break; //usuario existe
		}
	}
	
	//Verifica se fez uma busca em todo e não encontrou o usuario
	if(j == usuarios.size()){
		throw Erro("Usuario não existe");
	}

//Se acha=lo, verificar se ele tem algum emprestimo
//Para isso, é preciso acessar o usuario nas lista de emprestimos OK
//Tem que ter uma sobrecarga no operador na classe de usuario == OK
	int i;
	for( i = 0; i < emprestimos.size() ; i++){ // no vetor vai até size-1 pq começa em 0
		if(emprestimos[i].getUsuario() == u){ //Achou o usuario na lista de emprestimo
			Date hoje;
			hoje.DataCorrente();
		//Tirar depois que implementar operador <=
		//	if(emprestimos[i].getDataPrevDev() <= hoje){ // Verifica se ele tem emprestimo 
		//		throw Erro("Usuario não pode ser excluido, ele possui emprestimo");
		//	}
			usuarios.erase(usuarios.begin() + j); //Deleto o Usuario
			break;	
		}
	}
	
	//Usuario não foi achado na lista de emprestimos
	if(i == emprestimos.size()){
		usuarios.erase(usuarios.begin() + j);
	}


}








