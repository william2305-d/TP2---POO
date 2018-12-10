#include <string.h>
#include <iostream>
#include <time.h>
#include<vector>
using namespace std;


// --------------------------------------------------------------------    DATE   --------------------------------------------------------------------//

//Dia nao pode ser digitado com 0 antes ex:(06 -> errado, 6 -> certo)
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
		void DataNula(){ dia = 0; mes = 0; ano = 0;};  
		void DataCorrente(); // inicializa com a data do "dia" que voce usar essa função, para gente será o msm dia.
		Date(); //  inicializa com a data do dia da criação
		Date(int d, int m, int a):dia(d), mes(m), ano(a){};
		~Date(){};
		int getDia(){return dia;};
		int getMes(){return mes;};
		int getAno(){return ano;};
		int operator==(Date &d); 
		int operator<(Date &d);  

};

// --------------------------------------------------------------------    USUARIO   --------------------------------------------------------------------//

class Usuario{
	private:
		string nome;
		string cpf;
		string endereco;
		string fone;
		Date dataPenalizacao;
	public:
	//	Usuario(Usuario &u);
		Date& getDataPen(){ return dataPenalizacao;};
		Usuario(){nome = ""; cpf = ""; endereco = ""; fone= "";}; //Mudei aqui
		Usuario(string nomeParametro, string cpfParametro, string enderecoParametro, string foneParametro);
		~Usuario(){};
		int operator==(const Usuario &u)const;
};

// --------------------------------------------------------------------    PUBLICACAO   --------------------------------------------------------------------//

class Publicacao{
	private:
		int codPublicacao;
		string titulo;
		string editora;
		int ano;
	public:
	//	Publicacao(Publicacao &p);
		int operator==(Publicacao &p);
		string getTitulo()const{return titulo;};
		string getEditora()const{return editora;};
		int getCodPublicacao()const{return codPublicacao;};
		int getAno()const{return ano;};
		Publicacao(){codPublicacao = 0; titulo = ""; editora = ""; ano = 0;};
		Publicacao(int codP, string tit, string ed, int a): codPublicacao(codP), titulo(tit), editora(ed), ano(a){};
		virtual ~Publicacao(){};

};

// --------------------------------------------------------------------    LIVRO   --------------------------------------------------------------------//

class Livro: public Publicacao{
	private:
		string autores;
		int qtdeExemplares;
	public:
	//	Livro(Livro& l);
		Livro():Publicacao(){ autores = ""; qtdeExemplares = 0;}; 
		Livro(string aut, int codP, string tit, string ed, int a,int qtdeE = 0):Publicacao( codP, tit, ed, a),autores(aut),qtdeExemplares(qtdeE){};
		virtual ~Livro(){};
		void incrementar();
		void decrementar();
		virtual int getQtdeExemplares(){return qtdeExemplares;};
		virtual string getAutores(){ return autores;};
		int operator==(const Livro &l)const;
		
};

// ---------------------------------------------------------------------    PERIODICO   ---------------------------------------------------------------------//

class Periodico:public Publicacao{
	private:
		int numEdicao;
		string mes;
	public:
		Periodico(int numE, string m, int codP, string tit, string ed, int a):Publicacao( codP, tit, ed, a),numEdicao(numE),mes(m){};
		virtual ~Periodico(){};
		int operator==(const Periodico &p)const;
};


// ------------------------------------------------------------------    ITEM EMPRESTIMO   ------------------------------------------------------------------//

class ItemEmprestimo{
	private:
		Date dataDevolucao;
		Livro livro;	
	public:
		Date& getDataDev(){return dataDevolucao;	};
		ItemEmprestimo(){};
		ItemEmprestimo(Livro l);
		Livro& getLivro();
		void setDataDev(){ dataDevolucao.DataCorrente();};
		bool operator==(ItemEmprestimo &e);
};

// --------------------------------------------------------------------    EMPRESTIMO   --------------------------------------------------------------------//
class Emprestimo{		
	private:
		int numero;
		Date dataEmprestimo;
		Usuario usuario;
		static int proximoNumero;
		Date dataPrevDevolucao;
		vector <ItemEmprestimo> itens;
	public:
		~Emprestimo(){};
		Emprestimo(){};
		Emprestimo(Usuario usu, Date dataPrevDev);
		vector <ItemEmprestimo>& getItens(){ return itens;};
		void adicionarLivro(Livro &nomeLivro);
		void excluirLivro(Livro &nomeLivro);
		void devolverLivro(Livro &nomeLivro);
		void devolverTodosOsLivros();
		Usuario& getUsuario(){return usuario;};
		Date& getDataPrevDev(){ return dataPrevDevolucao;}
		void adcItemEmprestimo(ItemEmprestimo &i){ itens.push_back(i);};
		bool operator==(Emprestimo &e);
		
};

class Erro{
	private:
		string tipo_erro;
	public:
		Erro(const string &a):tipo_erro(a){};
		void out(){ cout << tipo_erro << endl; };	
			
};

// --------------------------------------------------------------------    BIBLIOTECA   --------------------------------------------------------------------//

class Biblioteca{		
	private:
		//Ao iniciar aqui já é dado como vazio (tamanho zero do vetor)
		vector <Emprestimo> emprestimos;
		vector <Usuario> usuarios;
		vector <Publicacao*> livros;
	public:
		Biblioteca(); 
		vector <Usuario>& getListaUsuario(){return usuarios;};
		vector <Publicacao*>& getPublicacoes(){return livros;};
		vector <Emprestimo>& getEmprestimos(){return emprestimos;};
		void novoUsuario(const Usuario &u);
		void novaPublicacao(Publicacao *p);
		void novoEmprestimo(const Emprestimo &e);
		void novoItemEmprestimo(Emprestimo &e, ItemEmprestimo &i); //tambem recebe item de emprestimo
		void excluiUsuario(const Usuario &u);
		void excluiPublicacao(Publicacao *p);
		void exluiEmprestimo(Emprestimo &e);
		void exluiItemEmprestimo(Emprestimo &e, ItemEmprestimo &it);
		void devolverLivro(Emprestimo &e, Livro &l);
		void devolverTodosLivros(Emprestimo &e);
		void pesquisaPub(string &a, vector<Publicacao*>& livrosAchados);
		void pesquisaAutores(string &a, vector<Livro*>& livrosAchados);
};

