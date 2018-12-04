#include <string.h>
#include <iostream>
namespace std;


class emprestimo{
		
	public:
		int numero;
		Date dataEmprestimo;
		Usuario usuario;//como criar esse objeto?
		int proximoNumero;//como torná-lo estático?
		emprestimo(int numero, Date dataEmprestimo, Date dataPrevDevolucao, Usuario usuario);
		void adicionarLivro(livro nomeLivro);
		void excluirLivro(livro nomeLivro);
		void devolverLivro(livro nomeLivro);
		void devolverTodosOsLivros();


};

class Usuario{
	private:
	public:
		string nome;
		string cpf;
		string endereco;
		string fone;
		Usuario();
		~Usuario();
};

class Publicacao{
	private:
	public:
		int codPublicacao;
		string titulo;
		string editora;
		int ano;
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

class Livro{
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
