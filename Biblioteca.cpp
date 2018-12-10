//biblioteca.cpp
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Biblioteca.h"

using namespace std;

// --------------------------------------------------------------------    DATE   --------------------------------------------------------------------// 
int Date::operator==(Date &d){ 
	if( mes == d.mes && ano == d.ano && mes == d.mes){
		return true;
	}
	return false;
};

int Date::operator<(Date &d){
	if(ano < d.ano){
		return true;
	}	
	else if (ano == d.ano){
		if(mes < d.mes){
			return true;
		}
		else if(mes == d.mes){
			if(dia < d.dia){
				return true;
			}
		}
	}
	return false;
}

void Date::DataCorrente(){
  time_t rawtime;
  struct tm * timeinfo;
  string data;
  string d;
  string m;
  string a;
  
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  data = asctime (timeinfo);
  
  m = data.substr(4,3);
  d = data.substr(8,2);
  a = data.substr(20,4);
  
  if(m == "Jan"){
	mes = 1;
	}
	else{
		if(m == "Fen"){
			mes = 2;
		}
		else{
			if(m == "Mar"){
				mes = 3;
			}
			else{
				if(m == "Apr"){
					mes = 4;
				}
				else{
					if(m == "May"){
						mes = 5;
					}
					else{
						if(m == "Jun"){
							mes = 6;
						}
						else{
							if(m == "Jul"){
								mes = 7;
							}
							else{
								if(m == "Aug"){
									mes = 8;
								}
								else{
									if(m == "Sep"){
										mes = 9;
									}
									else{
										if(m == "Oct"){
											mes = 10;
										}
										else{
											if(m == "Nov"){
												mes = 11;
											}
											else{
												if(m == "Dec"){
													mes = 12;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} 
  
  dia = atoi( d.c_str() );
  ano = atoi( a.c_str() );
}

Date::Date(){
	DataCorrente();
}


// --------------------------------------------------------------------    USUARIO   --------------------------------------------------------------------//

int Usuario::operator==(const Usuario &u)const{
	if( nome == u.nome && cpf == u.cpf && endereco == u.endereco && fone == u.fone){
		return true;
	}
	return false;
}

Usuario::Usuario(string nomeParametro, string cpfParametro, string enderecoParametro, string foneParametro){
	nome = nomeParametro;
	cpf = cpfParametro;
	endereco = enderecoParametro;
	fone = foneParametro;
}

// --------------------------------------------------------------------    PUBLICACAO   --------------------------------------------------------------------//

int Publicacao::operator==(Publicacao &p){
	if(p.ano == ano && p.codPublicacao == codPublicacao && (editora.compare(p.editora) == 0 ) && (titulo.compare(p.titulo) == 0)){
		return true;
	}
	else{
		return false;
	}
}

// --------------------------------------------------------------------    LIVRO   --------------------------------------------------------------------//

//Esta errado so fiz pr testar, falta testar se as outras variaveis sao iguais
//Observação importante para o Will (necessario fazer um get para todos os atributos) 
int Livro::operator==(const Livro &l)const{
	if (autores == l.autores && getCodPublicacao() == l.getCodPublicacao() && this->getTitulo() == l.getTitulo() && getEditora() == l.getEditora() && getAno() == l.getAno() && qtdeExemplares == l.qtdeExemplares ){
		return true;
	} 
	else{
		return false;	
	}
}

void Livro::incrementar(){
	qtdeExemplares++;
}

void Livro::decrementar(){
	if(qtdeExemplares <= 0){
		throw Erro("Quantidade de exemplares igual a 0, impossivel decrementar");
	}
	else{
		qtdeExemplares--;
	}
}

// ---------------------------------------------------------------------    PERIODICO   ---------------------------------------------------------------------//

int Periodico::operator==(const Periodico &p)const{
	// comparar só as variáveis de periodico ou da classe base tbm?
	if(numEdicao == p.numEdicao && mes == p.mes && this->getCodPublicacao() == p.getCodPublicacao() && getTitulo() == p.getTitulo() && getEditora() == p. getEditora() && getAno() == p.getAno()){
		return true;
	}
	else{
		return false;
	}
}

// ------------------------------------------------------------------    ITEM EMPRESTIMO   ------------------------------------------------------------------//

ItemEmprestimo::ItemEmprestimo(Livro l):livro(l){
	dataDevolucao.DataNula();
}

Livro& ItemEmprestimo::getLivro(){
	return livro;
}

bool ItemEmprestimo::operator==(ItemEmprestimo &e){
	return(dataDevolucao == e.dataDevolucao && livro == e.livro);
}

// --------------------------------------------------------------------    EMPRESTIMO   --------------------------------------------------------------------//

//Contador 
int Emprestimo::proximoNumero = 0;

Emprestimo::Emprestimo(Usuario usu, Date dataPrevDev):usuario(usu),dataPrevDevolucao(dataPrevDev){
	Date a;
	a.DataCorrente();
	if(usu.getDataPen() < a ){
		throw Erro("Usuario esta Penalizado");
	}
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

bool Emprestimo::operator==(Emprestimo &e){
	return ( numero == e.numero );
}

// --------------------------------------------------------------------    BIBLIOTECA   --------------------------------------------------------------------//

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

void Biblioteca::novaPublicacao(Publicacao *p){ //Precisa de função virtual ? Para livro ser reconcedo como publicação?
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
			if(emprestimos[i].getDataPrevDev() < hoje){ // Verifica se ele tem emprestimo 
				throw Erro("Usuario não pode ser excluido, ele possui emprestimo");
			}
			usuarios.erase(usuarios.begin() + j); //Deleto o Usuario
			break;	
		}
	}
	
	//Usuario não foi achado na lista de emprestimos
	if(i == emprestimos.size()){
		usuarios.erase(usuarios.begin() + j);
	}



}

void Biblioteca::excluiPublicacao(Publicacao *p){
	//Verificar se é Periodioco
	Livro* l = dynamic_cast<Livro*>(p);
	if (l == NULL){
		throw Erro("É um periodico, não pode ser excluido");
	}

	//Verificar se existe ele na lista de publicacao
	int i,j;
	for(i = 0; i< livros.size(); i++){
		if( p == livros[i]){
			break; //encontrou o livro
		}
	}
	
	if(i == livros.size()){
		throw Erro("Não existe esse Livro");
	}
	
	int indiceLivro = i;
	// Verificar se algum usuario possui emprestimo para ele
	//Esta errado: Não funciona!
	cout << emprestimos.size();
	
	for(i = 0 ; i < emprestimos.size(); i++){
		vector <ItemEmprestimo> itens;
		itens = emprestimos[i].getItens();
		
		//Verifico se tem algum emprestimo pr ele
		
		for(j = 0; j < itens.size(); j++ ){
				Livro * l = dynamic_cast <Livro*> (p);
				if ( *l == itens[j].getLivro()){
					Date hoje;
					if(hoje < itens[j].getDataDev()){ //Ele não foi devolvido
						throw Erro("O livro está em um Emprestimo");
					}
				}
			
		}
	}
	
	// Se saiu é pq pode ser excluido
	
	livros.erase(livros.begin() + indiceLivro);
			
}

void Biblioteca::exluiEmprestimo(Emprestimo &e){
	int i,size;
	size = emprestimos.size();
	
	for(i = 0 ; i < emprestimos.size(); i++){
		if( e == emprestimos[i]){
			emprestimos.erase(emprestimos.begin() + i);
			break;
		}
	}
	if(i == size){				
		throw Erro("Não existe esse Emprestimo");	
	}
}


void Biblioteca::exluiItemEmprestimo(Emprestimo &e, ItemEmprestimo &it){
	vector<ItemEmprestimo> itens = e.getItens();
	int i,size;
	size = itens.size(); //Guarda o tamanho inicial
	for(i = 0; i < itens.size(); i++){
		if( it == itens[i]){
			itens.erase(itens.begin() + i);
			break;
		}
	}
	
	if( i == size){ // Se o tamanho se manter...
		throw Erro("Nao existe esse Item nesse Emprestimo");
	}
}

void Biblioteca::devolverLivro(Emprestimo &e, Livro &l){
	vector<ItemEmprestimo> itens = e.getItens();
	int i,size;
	size = itens.size(); //Guarda o tamanho inicial
	for(i = 0; i < itens.size(); i++){
		if( l == itens[i].getLivro()){
 				itens[i].setDataDev(); //Atualiza a data de Devolução
				break;
		}
	}
	
	if( i == size){ // Se o tamanho se manter...
		throw Erro("Nao existe esse Livro nesse Emprestimo");
	}
}

void Biblioteca::devolverTodosLivros(Emprestimo &e){
	vector<ItemEmprestimo> itens = e.getItens();
	if(itens.size() == 0){ 
		throw Erro("Sem itens para Devolver");
	}
	int i;
	for(i = 0; i < itens.size(); i++){
 		itens[i].setDataDev(); //Atualiza a data de Devolução	
	}
}

void Biblioteca::pesquisaPub(string &a, vector<Publicacao*>& livrosAchados){
//	vector <Publicacao>* livrosAchados; Não consegui como retorno!
	int size = livrosAchados.size();  //Guarda tamanho inicial
	for(int i =0 ; i < livros.size(); i++){
		string titulo = livros[i]->getTitulo();
		if(titulo.find(a) != -1){
			livrosAchados.push_back(livros[i]);
		}
	}
	if(livrosAchados.size() == size){ //Se o tamanho inicial for o msm que o final
		throw Erro("Livro nao encontrado na Biblioteca");
	}

}

void Biblioteca::pesquisaAutores(string &a, vector<Livro*>& livrosAchados){
	int size = livrosAchados.size();  //Guarda tamanho inicial
	for(int i =0 ; i < livros.size(); i++){
		Livro* l = dynamic_cast<Livro*>(livros[i]);
		if(l != NULL){ //Apenas se for um livro
			string titulo = l->getAutores();
			if(titulo.find(a) != -1){
				livrosAchados.push_back(l);
			}
		}
	}
	if(livrosAchados.size() == size){ //Se o tamanho inicial for o msm que o final
		throw Erro("Livro nao encontrado na Biblioteca");
	}

}








