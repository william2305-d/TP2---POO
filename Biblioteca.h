#include <string.h>
#include <iostream>
#include <time.h>
namespace std;

class Date{
	public:
		int dia;
		int mes;
		int ano;
		Date();
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
		Usuario(string nome, string cpf, string endereco,string fone);
		~Usuario(){};
};

class Publicacao{
	private:
		int codPublicacao;
		string titulo;
		string editora;
		int ano;
	pubic:
		Publicacao();
		Publicacao(int codP, string tit, string ed, int a);
		~Publicacao(){}; 
};

class Livro:public Publicacao{
	private:
		string autores;
		int qtdeExemplares;
	public:
		Livro(string aut, int codP, string tit, string ed, int a,int qtdeE = 0):autores(aut),codPublicacao(codP),titulo(tit),editora(ed),ano(a),qtdeExemplares(qtdeE){};
		~Livro(){};
		void incrementar();
		void decrementar();
		
};

class Periodico:public Publicacao{
	private:
		int numEdicao;
		string mes;
	public:
		Periodico(int numE, string m, int codP, string tit, string ed, int a):numeEdicao(numE), mes(m), codPublicacao(codP),titulo(tit),editora(ed),ano(a){};
		~Periodico(){};
};


class emprestimo{
		
	private:
		int numero;
		Date dataEmprestimo;
		Usuario usuario;
		int proximoNumero;
		Date dataPrevDevolucao;
		vector <ItemEmprestimo> itens;
	public:
		void adicionarLivro(Livro nomeLivro);
		void excluirLivro(Livro nomeLivro);
		void devolverLivro(Livro nomeLivro);
		void devolverTodosOsLivros();
		emprestimo(int num, Date dataE, Usuario usu, Date dataPrevDev);



};

class Biblioteca{
	Emprestimo emprestimo;
	Usuario usuario;
	Publicacao publicacao;
	
	public:
		
};

class itemEmprestimo{
	private:
				
	public:
		Date dataDevolucao;
		Livro livro;
		itemEmprestimo(Livro Livro, Date dataDevolucao = NULL);
};

int main(){

	return 0;
}
