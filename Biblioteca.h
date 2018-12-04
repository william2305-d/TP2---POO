#include <string.h>
#include <iostream>
namespace std;

class Biblioteca{
	public:
	private:
};

class emprestimo: public Biblioteca{
	private:
		int numero;
		
	public:


};

class usuario{
	private:
	public:
		string nome;
		string cpf;
		string endereco;
		string fone;
		usuario();
		~usuario();
};

class publicacao{
	private:
	public:
		int codPublicacao;
		string titulo;
		string editora;
		int ano;
};

class itemEmprestimo{
	private:
				
	public:
		itemEmprestimo();
};

class livro{
	private:
	public:
		string autores;
		int qtdeExemplares;
		livro(string autoresPar, int qtdeExemplaresPar);
		livro(int codPublicacao, string titulo, string editora, int ano, string autores, int qtdeExemplares = 0);
		void acrescentar();
		void decrementar();
		
};

class periodico{
	private:
	public:
		int numEdicao;
		string mes;
		periodico(int numEdicaoPar, string mesPar);
};

int main(){

	return 0;
}
