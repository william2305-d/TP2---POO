#include <string.h>
#include <time.h>
#include <vector>
using namespace std;

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
		Usuario(Usuario &u):nome(u.nome),cpf(u.cpf),endereco(u.endereco),fone(u.fone),dataPenalizacao(u.dataPenalizacao){};
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
		Publicacao(Publicacao &p):codPublicacao(p.codPublicacao),titulo(p.titulo),editora(p.editora),ano(p.ano){};
		Publicacao();
		Publicacao(int codP, string tit, string ed, int a);
		~Publicacao(){}; 
};

class Livro:public Publicacao{
	private:
		string autores;
		int qtdeExemplares;
	public:
		//construtor de cópia(inicializando somente as variáveis da classe Livro)
		Livro(Livro &l):autores(l.autores),qtdeExemplares(l.qtdeExemplares){};
	
		//construtor inicializando todas as variáveis
		Livro(string aut, int codP, string tit, string ed, int a,int qtdeE = 0):autores(aut),qtdeExemplares(qtdeE){};
		~Livro(){};
		void incrementar();
		void decrementar();
		
};

class Periodico:public Publicacao{
	private:
		int numEdicao;
		string mes;
	public:
		//construtor de cópia(inicializando somente as variáveis da classe Periodico)
		Periodico(Periodico &p):numEdicao(p.numEdicao),mes(p.mes){};
		Periodico(int numE, string m, int codP, string tit, string ed, int a):numEdicao(numE), mes(m){};
		~Periodico(){};
};

class ItemEmprestimo{
	private:
				
	public:
		Date dataDevolucao;
		Livro livro;
		ItemEmprestimo(Livro Livro, Date dataDevolucao);
};

class Emprestimo{
		
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
		Emprestimo(int num, Date dataE, Usuario usu, Date dataPrevDev);



};

class Biblioteca{
	Emprestimo emprestimo;
	Usuario usuario;
	Publicacao publicacao;
	
	public:
		
};

