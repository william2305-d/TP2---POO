#include <string.h>
#include <iostream>
#include <time.h>
#include<vector>
using namespace std;

//Arrumar para inicializar com a data corrente do sistema
class Date{
		int dia;
		int mes;
		int ano;
	public:
		//Obs: O certo é tirar daqui as {} depois de implementar em todas as funções
		//De menos das contrutores que n recebem nada
		//Exemplo =>  Date DataNula();
		//Acho que terá q fazer um contrutor por copia em todos!!!
		
		Date DataNula(){};        //William tem q implemetar
		Date DataCorrente(){};
		Date(){};
		~Date(){};

};

class Usuario{
	private:
		string nome;
		string cpf;
		string endereco;
		string fone;
		Date dataPenalizacao;
	public:
		Usuario(){};
		Usuario(string nome, string cpf, string endereco,string fone);
		~Usuario(){};
};

class Publicacao{
	private:
		int codPublicacao;
		string titulo;
		string editora;
		int ano;
	public:
		Publicacao(){};
		Publicacao(int codP, string tit, string ed, int a);
		~Publicacao(){}; 
		
};

class Livro: public Publicacao{
	private:
		string autores;
		int qtdeExemplares;
	public:
		Livro(){};
		Livro(string aut, int codP, string tit, string ed, int a,int qtdeE = 0):Publicacao( codP, tit, ed, a),autores(aut),qtdeExemplares(qtdeE){};
		~Livro(){};
		void incrementar(){};
		void decrementar(){}; //Fazer o teste se pode decrementar
		int operator==(const Livro &l)const;
		
};

class Periodico:public Publicacao{
	private:
		int numEdicao;
		string mes;
	public:
		
		Periodico(int numE, string m, int codP, string tit, string ed, int a):Publicacao( codP, tit, ed, a),numEdicao(numE),mes(m){};
		~Periodico(){};
};

class ItemEmprestimo{
	private:
		Date dataDevolucao;
		Livro livro;	
	public:
		ItemEmprestimo(){};
		ItemEmprestimo(Livro l);
		Livro getLivro();
};

class Emprestimo{
		
	private:
		int numero;
		Date dataEmprestimo;
		Usuario usuario;
		static int proximoNumero;
		Date dataPrevDevolucao;
		vector <ItemEmprestimo> itens;
	public:
		Emprestimo(){};
		Emprestimo(Usuario usu, Date dataPrevDev);
		void adicionarLivro(Livro nomeLivro);
		void excluirLivro(Livro nomeLivro);
		void devolverLivro(Livro nomeLivro);
		void devolverTodosOsLivros();
		



};

class Biblioteca{
		
};


