#include <iostream>
#include <stdlib.h>

static void Interface::CadastroUsuario (Biblioteca &biblio){
	cout << "Novo usuário sendo cadastrado:" << endl;
	
	string nome, cpf, endereco, fone;
	
	cout << "Insira o nome: ";
	cin >> nome;
	cout << "Insira o cpf: ";
	cin >> cpf;
	cout << "Insira o endereco: ";
	cin >> endereco;
	cout << "Insira o fone: ";
	cin >> fone;	
	try{
		Usuario cadastro = new Usuario(nome, cpf, endereco, fone);
		biblio.novoUsuario(cadastro);
		cout << "Usuário cadastrado com sucesso!" << endl << "Aperte enter para voltar ao menu principal...";
		cin;
	}
	catch (Erro e){
		e.out();
		cout << "Aperte enter para voltar ao menu principal...";
		cin;
	}
}

static void Interface::CadastroLivro (Biblioteca &biblio){
	cout << "Novo livro sendo cadastrado:" << endl;
	
	string titulo, editora, autores;
	int codPublicacao, ano;
	
	while (true){
		cout << "Insira o código de publicação (inteiro): ";
		cin >> codPublicacao;
		if(!cin.fail()) break;
		cout << "Inserção inválida, tente novamente" << endl;
	}
	cout << "Insira o título: ";
	cin >> titulo;
	cout << "Insira a editora: ";
	cin >> editora;
	while (true){
		cout << "Insira o ano (inteiro): ";
		cin >> ano;
		if(!cin.fail()) break;
		cout << "Inserção inválida, tente novamente" << endl;
	}
	cout << "Insira os autores: ";
	cin >> autores;
	
	try{
		Livro * cadastro = new Livro(codPublicacao, titulo, editora, ano, autores);
		biblio.novoLivro(cadastro);
		cout << "Livro cadastrado com sucesso!" << endl << "Aperte enter para voltar ao menu principal...";
		cin;
	}
	
	catch (Erro e){
		e.out();
		cout << "Aperte enter para voltar ao menu principal...";
		cin;
	}
}

static void Interface::CadastroPeriodico (Biblioteca &biblio){
	cout << "Novo periódico sendo cadastrado:" << endl;
	string titulo, editora, mes;
	int codPublicacao, ano, numEdicao;
	
	while (true){
		cout << "Insira o código de publicação (inteiro): ";
		cin >> codPublicacao;
		if(!cin.fail()) break;
		cout << "Inserção inválida, tente novamente" << endl;
	}
	cout << "Insira o título: ";
	cin >> titulo;
	cout << "Insira a editora: ";
	cin >> editora;
	while (true){
		cout << "Insira o ano (inteiro): ";
		cin >> ano;
		if(!cin.fail()) break;
		cout << "Inserção inválida, tente novamente" << endl;
	}
	while (true){
		cout << "Insira o número da edição (inteiro): ";
		cin >> numEdicao;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	cout << "Insira o mês: ";
	cin >> mes;
	
	try{
		Periodico * cadastro = new Periodico(codPublicacao, titulo, editora, ano, numEdicao, mes);
		biblio.novoPeriodico(cadastro);
		cout << "Periódico cadastrado com sucesso!" << endl << "Aperte enter para voltar ao menu principal...";
		cin;
	}
	
	catch (Erro e){
		e.out();
		cout << "Aperte enter para voltar ao menu principal...";
		cin;
	}
}

static void Interface::CadastroEmprestimo (Biblioteca &biblio){
	cout << "Novo Empréstimo sendo cadastrado:" << endl;
	int indexUser, dia, mes, ano, numItens;
	vector <Usuario> usuarios = biblio.getListaUsuario();
	Usuario user;
	Date dataPrevDevolucao;
	vector <ItemEmprestimo> itens;
	vector <Publicacao> pubs = getPublicacoes();
	Livro livro;
	int indexLivro;
	
	while (true){
		cout << "Insira o índice do usuário (inteiro): ";
		cin >> indexUser;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		user = usuarios[indexUser];
		cout << "O seguinte usuário foi selecionado" << endl << user << endl << "Confirme o usuário (Y/N): ";
		string text;
		while (true){
			cin >> text;
			if(text == "Y" || text == "y") break;
			else if (text == "N" || text == "n"){
				cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
				cin;
				return;
			}
			cout << "O seguinte usuário foi selecionado" << endl << user << endl << "Confirme o usuário (Y/N): ";
		}
	}
	catch (...){
		cout << "Índice do usuário inválido." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}
	
	while (true){
		cout << "Insira o dia da data prevista para a devolução (inteiro): ";
		cin >> dia;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	while (true){
		cout << "Insira o mes da data prevista para a devolução (inteiro): ";
		cin >> mes;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	while (true){
		cout << "Insira o ano da data prevista para a devolução (inteiro): ";
		cin >> ano;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		dataPrevDevolucao = new Date(dia, mes, ano);
	}
	catch (...){
		cout << "Data prevista para a devolução inválida." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}
	
	while (true){
		cout << "Insira a quantidade de itens a serem emprestados (inteiro): ";
		cin >> numItens;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	
	for (int i = 0; i < numItens; i++){
		cout << "Cadastrando o " << i << " Item." << endl;
		Livro livro;
		int indexLivro;
		while (true){
			cout << "Insira o índice do Livro (inteiro): ";
			cin >> indexLivro;
			if(!cin.fail()) break;
			cout << "Inserção inválida, Tente novamente" << endl;
		}
		try{
			livro = pubs[indexLivros];
			cout << "O seguinte livro foi selecionado" << endl << livro << endl << "Confirme o livro (Y/N): ";
			string text;
			while (true){
				cin >> text;
				if(text == "Y" || text == "y") break;
				else if (text == "N" || text == "n"){
					cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
					cin;
					return;
				}
				cout << "O seguinte livro foi selecionado" << endl << livro << endl << "Confirme o livro (Y/N): ";
			}
		}
		catch (...){
			cout << "Índice de livro inválido." << endl;
			cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
			cin;
			return;
		}
		ItemEmprestimo item = new ItemEmprestimo(livro);
		itens.push_back(livro);
	}
	
	Emprestimo emp = new Emprestimo(user, dataPrevDevolucao);
	for (int i = 0; i < numItens; i++) emp.adcItemEmprestimo(itens[i]);
	
	biblio.novoEmprestimo(emp);
	
	cout << "Empréstimo cadastrado com sucesso!" << endl << "Aperte enter para voltar ao menu principal...";
	cin;
}

static void Interface::CadastroItemEmprestimo (Biblioteca &biblio){
	cout << "Novo Item de Empréstimo sendo cadastrado:" << endl;
	vector <Emprestimo> emps = getEmprestimos();
	Emprestimo emp;
	int indexEmp;
	vector <Publicacao> pubs = getPublicacoes();
	
	while (true){
		cout << "Insira o índice do empréstimo (inteiro): ";
		cin >> indexEmp;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		emp = emps[indexEmp];
		cout << "O seguinte empréstimo foi selecionado" << endl << emp << endl << "Confirme o empréstimo (Y/N): ";
		string text;
		while (true){
			cin >> text;
			if(text == "Y" || text == "y") break;
			else if (text == "N" || text == "n"){
				cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
				cin;
				return;
			}
			cout << "O seguinte empréstimo foi selecionado" << endl << emp << endl << "Confirme o empréstimo (Y/N): ";
		}
	}
	catch (...){
		cout << "Índice do empréstimo inválido." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}
	
	cout << "Cadastrando o item." << endl;
	while (true){
		cout << "Insira o índice do Livro (inteiro): ";
		cin >> indexLivro;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		livro = pubs[indexLivros];
		cout << "O seguinte livro foi selecionado" << endl << livro << endl << "Confirme o livro (Y/N): ";
		string text;
		while (true){
			cin >> text;
			if(text == "Y" || text == "y") break;
			else if (text == "N" || text == "n"){
				cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
				cin;
				return;
			}
			cout << "O seguinte livro foi selecionado" << endl << livro << endl << "Confirme o livro (Y/N): ";
		}
	}
	catch (...){
		cout << "Índice de livro inválido." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}

	emp.adicionarLivro(livro);
	
	cout << "Item de Empréstimo cadastrado com sucesso!" << endl << "Aperte enter para voltar ao menu principal...";
	cin;
}

static void Interface::ExcluirUsuario (Biblioteca &biblio){
	cout << "Usuário sendo excluído:" << endl;
	int indexUser;
	vector <Usuario> usuarios = biblio.getListaUsuario();
	Usuario user;
	
	while (true){
		cout << "Insira o índice do usuário (inteiro): ";
		cin >> indexUser;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		user = usuarios[indexUser];
		cout << "O seguinte usuário foi selecionado" << endl << user << endl << "Confirme o usuário (Y/N): ";
		string text;
		while (true){
			cin >> text;
			if(text == "Y" || text == "y") break;
			else if (text == "N" || text == "n"){
				cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
				cin;
				return;
			}
			cout << "O seguinte usuário foi selecionado" << endl << user << endl << "Confirme o usuário (Y/N): ";
		}
	}
	catch (...){
		cout << "Índice do usuário inválido." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}
	
	try{
		biblio.excluiUsuario(user);
	}
	catch (Erro e){
		e.out();
		cout << "Aperte enter para voltar ao menu principal...";
		cin;
	}
}

static void Interface::ExcluirEmprestimo (Biblioteca &biblio){
	cout << "Empréstimo sendo excluído:" << endl;
	vector <Emprestimo> emps = getEmprestimos();
	Emprestimo emp;
	int indexEmp;
	
	while (true){
		cout << "Insira o índice do empréstimo (inteiro): ";
		cin >> indexEmp;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		emp = emps[indexEmp];
		cout << "O seguinte empréstimo foi selecionado" << endl << emp << endl << "Confirme o empréstimo (Y/N): ";
		string text;
		while (true){
			cin >> text;
			if(text == "Y" || text == "y") break;
			else if (text == "N" || text == "n"){
				cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
				cin;
				return;
			}
			cout << "O seguinte empréstimo foi selecionado" << endl << user << endl << "Confirme o empréstimo (Y/N): ";
		}
	}
	catch (...){
		cout << "Índice do empréstimo inválido." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}
	
	try{
		biblio.excluiEmprestimo(emp);
	}
	catch (Erro e){
		e.out();
		cout << "Aperte enter para voltar ao menu principal...";
		cin;
	}
}

static void Interface::ExcluirItemEmprestimo (Biblioteca &biblio){
	cout << "Item de Empréstimo sendo excluído:" << endl;
	vector <Emprestimo> emps = getEmprestimos();
	Emprestimo emp;
	int indexEmp;
	vector <Publicacao*> pubs = getPublicacoes();
	Livro* livro;
	
	while (true){
		cout << "Insira o índice do empréstimo (inteiro): ";
		cin >> indexEmp;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		emp = emps[indexEmp];
		cout << "O seguinte empréstimo foi selecionado" << endl << emp << endl << "Confirme o empréstimo (Y/N): ";
		string text;
		while (true){
			cin >> text;
			if(text == "Y" || text == "y") break;
			else if (text == "N" || text == "n"){
				cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
				cin;
				return;
			}
			cout << "O seguinte empréstimo foi selecionado" << endl << emp << endl << "Confirme o empréstimo (Y/N): ";
		}
	}
	catch (...){
		cout << "Índice do empréstimo inválido." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}
	
	
	cout << "Excluindo o item." << endl;
	while (true){
		cout << "Insira o índice do Livro (inteiro): ";
		cin >> indexLivro;
		if(!cin.fail()) break;
		cout << "Inserção inválida, Tente novamente" << endl;
	}
	try{
		livro = pubs[indexLivros];
		cout << "O seguinte livro foi selecionado" << endl << livro << endl << "Confirme o livro (Y/N): ";
		string text;
		while (true){
			cin >> text;
			if(text == "Y" || text == "y") break;
			else if (text == "N" || text == "n"){
				cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
				cin;
				return;
			}
			cout << "O seguinte livro foi selecionado" << endl << livro << endl << "Confirme o livro (Y/N): ";
		}
	}
	catch (...){
		cout << "Índice de livro inválido." << endl;
		cout << "Operação cancelada." << endl << "Aperte enter para voltar ao menu principal...";
		cin;
		return;
	}

	try{
		emp.excluirLivro(livro);
	}
	catch (Erro e){
		e.out();
		cout << "Aperte enter para voltar ao menu principal...";
		cin;
	}
}

