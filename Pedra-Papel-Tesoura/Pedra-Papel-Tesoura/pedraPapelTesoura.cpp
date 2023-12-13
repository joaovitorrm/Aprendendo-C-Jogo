#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Player {
public:
	int vitorias = 0;
	int derrotas = 0;
	int movimentoId = 0;
	string movimento;
};

class Bot {
public:
	int vitorias = 0;
	int derrotas = 0;
	int movimentoId = 0;
	string movimento;
};

class Game {
public:
	Player p;
	Bot b;
	bool jogando = true;
	string jogadas[3] = { "Pedra", "Papel", "Tesoura" };

	Game(Player& player, Bot& bot) {
		p = player;
		b = bot;
	}
		
	void runGame() {
		system("cls");
		cout << "#################################\n";
		cout << "#      Pedra Papel Tesoura      #\n";
		cout << "#################################\n";
		cout << "Digite um valor para o movimento \n[1. Pedra; 2. Papel; 3. Tesoura]: ";
		cin >> p.movimentoId;
		b.movimentoId = 1 + (rand() % 3);
	}

	void checarVitoria() const {		
		for (int i = 0; i < 33; i++) cout << "#";		
		cout << "\nJogador: " + jogadas[p.movimentoId - 1] + "\n";
		cout << "Bot: " + jogadas[b.movimentoId - 1] + "\n\n";		
		cout << "Gerando Resultado";

		string final = ".";
		for (int i = 0; i < 5; i++) {			
			cout << final;
			Sleep(500);
		};
		cout << "\n";
		
		if (p.movimentoId == b.movimentoId) {
			final = "Empate!";
		}
		else if (p.movimentoId == 3 && b.movimentoId == 1) {
			final = "Perdeu!";
		}
		else if (p.movimentoId == 1 && b.movimentoId == 3) {
			final = "Venceu!";
		}
		else if (p.movimentoId > b.movimentoId) {
			final = "Venceu!";
		}
		else {
			final = "Perdeu!";
		}		
		cout << "\n" + final + "\n\n";		
		for (int i = 0; i < 33; i++) cout << "#";
		cout << "\n";
	}
};

int main() {

	Player player;
	Bot bot;
	Game game(player, bot);

	while (game.jogando) {
		game.runGame();
		while (game.p.movimentoId < 0 || game.p.movimentoId > 4) {
			game.runGame();
		}
		if (game.p.movimentoId == 4) {
			game.jogando = false;
		}
		else {
			game.checarVitoria();
			system("pause");
		}
		
	}

	return 0;
}