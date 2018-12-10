#include <string.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <Biblioteca.h>;

class Interface {
	public:
		static void CadastroUsuario (Biblioteca &biblio);
		static void CadastroLivro (Biblioteca &biblio);
		static void CadastroPeriodico (Biblioteca &biblio);
		static void CadastroEmprestimo (Biblioteca &biblio);
		static void CadastroItemEmprestimo (Biblioteca &biblio);
		
		static void ExcluirUsuario (Biblioteca &biblio);
		static void ExcluirLivro (Biblioteca &biblio);
		static void ExcluirPeriodico (Biblioteca &biblio);
		static void ExcluirEmprestimo (Biblioteca &biblio);
		static void ExcluirItemEmprestimo (Biblioteca &biblio);
		
		static void DevolverEmprestimo (Biblioteca &biblio);
		static void DevolverLivroEmprestimo (Biblioteca &biblio);
		
		static void PesquisarPublicacao (Biblioteca &biblio);
		static void PesquisarLivro (Biblioteca &biblio);
		
		static void ListarUsuario (Biblioteca &biblio);
		static void ListarPublicacao (Biblioteca &biblio);
		static void ListarEmprestimos (Biblioteca &biblio);
};
