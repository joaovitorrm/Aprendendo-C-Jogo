#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool rodando = true;

class Livraria {
public:
	vector<vector<string>> livros;

	void cadastrarLivro() {
		string nome, autor, lancamento;
		drawCadastroMenu();

		cin.ignore();

		cout << "\nNome do livro: ";
		getline(cin, nome);
		cout << "Nome do(a) autor(a): ";
		getline(cin, autor);
		cout << "Ano de lancamento: ";
		getline(cin, lancamento);

		vector<string> livro;

		livro.push_back(nome);
		livro.push_back(autor);
		livro.push_back(lancamento);

		livros.push_back(livro);

		int op;

		cout << "\nLivro inserido com sucesso!";
		cout << "\nInserir novo livro? [ 1. Sim | 2. Nao ]: ";
		cin >> op;

		if (op == 1) {
			cadastrarLivro();
		}
	}

	void editarLivro(int livroId) {		
		int op;
		bool editando = true;

		while (editando) {
			drawEditarMenu();
			cout << "\n1. Nome: " << livros[livroId][0];
			cout << "\n2. Autor: " << livros[livroId][1];
			cout << "\n3. Ano de lancamento: " << livros[livroId][2];
			cout << "\n4. Sair";
			cout << "\n\nDigite o valor que deseja editar: ";
			cin >> op;
			cout << "\n\nDigite o novo valor: ";
			switch (op) {
			case 1:
				cin >> livros[livroId][0];
				break;
			case 2:
				cin >> livros[livroId][1];
				break;
			case 3:
				cin >> livros[livroId][2];
				break;
			case 4:
				editando = false;
				break;
			}
			cin.ignore();
		}
	}

	void listarLivros() {
		int op;

		string valores[3] = { "Nome do livro", "Autor", "Ano de Lancamento" };

		drawListaMenu();

		cout << "\n";
		int id = 0;
		for (vector<string> listaLivros : livros) {						
			cout << "\nID - " << id << "\n";
			int c = 0;
			for (string livro : listaLivros) {
				cout << " " << valores[c] << ": " << livro << "\n";
				c++;
			}
			id++;
			cout << "\n";
			for (int l = 0; l < 40; l++) cout << "=";
			cout << "\n";
		}

		cout << "\nDigite a opcao: ";
		cin >> op;
		if (op == -1) {
			rodando = false;
		}
		else if (op >= 0 && op < livros.size()) {
			editarLivro(op);
		}
		else {
			cout << "Digite um valor valido!";
			system("pause");
		}
	}
	void drawMainMenu() {
		system("cls");
		for (int l = 0; l < 40; l++) cout << "=";		
		cout << "\n Livraria\n";
		cout << "\n  1. Cadastrar Livro\n";
		cout << "  2. Listar Livros\n";
		cout << "  3. Sair\n\n";
		for (int l = 0; l < 40; l++) cout << "=";
	}
	void drawListaMenu() {
		system("cls");
		for (int l = 0; l < 40; l++) cout << "=";
		cout << "\n Lista\n";
		cout << "\n  ?. Editar";
		cout << "\n  -1. Voltar \n\n";
		for (int l = 0; l < 40; l++) cout << "=";
	}
	void drawCadastroMenu() {
		system("cls");
		for (int l = 0; l < 40; l++) cout << "=";
		cout << "\n Cadastrar \n";
		for (int l = 0; l < 40; l++) cout << "=";
	}
	void drawEditarMenu() {
		system("cls");
		for (int l = 0; l < 40; l++) cout << "=";
		cout << "\n Editando \n";
		for (int l = 0; l < 40; l++) cout << "=";
	}
};

int main() {
	
	Livraria livraria;

	int op;

	while (rodando) {
		livraria.drawMainMenu();

		cout << "\nDigite a opcao: ";
		cin >> op;

		switch (op) {
		case 1:
			livraria.cadastrarLivro();
			break;

		case 2:
			livraria.listarLivros();
			break;

		case 3:
			rodando = false;
			break;
		}
		
	}

	
	



	return 0;
}
