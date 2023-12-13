#include <iostream>
#include <cstdlib>

using namespace std;

int gridArray[3][3] = {
		{
			{0},{0},{0}
		},
		{
			{0},{0},{0}
		},
		{
			{0},{0},{0}
		},
};

bool jogando = true;
bool reset = false;

static void drawGame() {
	system("cls");
	cout << "==================\n";
	cout << "= Jogo Da Velha! =\n";
	cout << "==================\n\n";

	for (int y = 0, yLine = 0 ; y < 4 && yLine < 4; y++, yLine++) {
		for (int x = 0, xLine = 0; x < 4 && xLine < 4; x++, xLine++) {
			if (x == 0 && y == 0) {
				cout << "y/x";
			}
			else if (x == 0) {
				cout << " ";
				cout << yLine;
				cout << " ";
			}
			else if (y == 0) {
				cout << " ";
				cout << xLine;
				cout << " ";
			}
			else {
				switch (gridArray[y - 1][x - 1]) {
				case 0:
					cout << "   ";
					break;
				case 1:
					cout << " X ";
					break;
				case 2:
					cout << " O ";
					break;
				}
			}			
			if (x != 3) {
				cout << "|";
			}
		}
		cout << "\n";
		if (y != 3) {
			for (int line = 0; line < 5; line++) {
				cout << "---";
			}
			cout << "\n";
		}
	}
	cout << "\n";
}

static void playerTurn() {
	int posY, posX;
	cout << "Digite o valor Y: ";
	cin >> posY;
	cout << "\nDigite o valor X: ";
	cin >> posX;

	if (posY < 1 || posY > 3 || posX < 1 || posX > 3 || gridArray[posY - 1][posX - 1] != 0) {
		cout << "Tente outra posicao!\n";
		system("pause");
		drawGame();
		playerTurn();
	}
	else {
		gridArray[posY - 1][posX - 1] = 1;
	}
	
}

static void botTurn() {	
	int randomPosY = (rand() % 3);
	int randomPosX = (rand() % 3);

	int limit = 0;
	while (gridArray[randomPosY][randomPosX] != 0 && limit < 30) {
		randomPosY = (rand() % 3);
		randomPosX = (rand() % 3);
		limit++;
	}

	if (limit == 30) {
		int decisao;
		cout << "Sem jogadas disponivel! EMPATE!\n";
		cout << "Jogar Novamente? [1.Sim | 2.Nao]: ";
		cin >> decisao;
		if (decisao == 1) {
			reset = true;
		}
		else {
			jogando = false;
		}		
	}
	else {
		gridArray[randomPosY][randomPosX] = 2;
	}
}

static void resetGrid() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			gridArray[y][x] = 0;
		}
	}
	reset = false;
}

static void checkVitoria() {
	int jogadorVencedor = 0;
	int decisao;
	int empate = 0;
	for (int x = 0, y = 0; x < 3 && y < 3; x++, y++) {
		// CHECA AS LINHAS HORIZONTAIS
		if (gridArray[y][0] == gridArray[y][1] && gridArray[y][0] == gridArray[y][2]) {
			jogadorVencedor = gridArray[y][0];
			break;
		}
		// CHECA AS LINHAS VERTICAIS
		if (gridArray[0][x] == gridArray[1][x] && gridArray[0][x] == gridArray[2][x]) {
			jogadorVencedor = gridArray[0][x];
			break;
		}
	}

	if (jogadorVencedor == 0) {
		// CHECA A DIAGONAL ESQUERDA -> DIREITA
		if (gridArray[0][0] == gridArray[1][1] && gridArray[0][0] == gridArray[2][2]) {
			jogadorVencedor = gridArray[0][0];
		}
		// CHECA A DIAGONAL DIREITA -> ESQUERDA
		else if (gridArray[0][2] == gridArray[1][1] && gridArray[0][2] == gridArray[2][0]) {
			jogadorVencedor = gridArray[0][2];
		}
		// CHECA SE EMPATOU
		else {
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					if (gridArray[y][x] != 0) {
						empate++;
					}
				}
			}
			if (empate == 9) {
				jogadorVencedor = 3;
			}
		}
	}

	// SE ALGUEM VENCEU FAZ ISSO
	if (jogadorVencedor != 0) {
		switch (jogadorVencedor) {
		case 1:
			cout << "O jogador venceu!\n\n";
			break;
		case 2:
			cout << "O computador venceu!\n\n";
			break;
		case 3:
			cout << "O jogo empatou!\n\n";
			break;
		}
		cout << "Jogar Novamente? [1.Sim | 2.Nao]: ";
		cin >> decisao;
		if (decisao == 1) {
			reset = true;
		}
		else {
			jogando = false;
		}
	}
}

int main() {

	while (jogando) {
		drawGame();

		playerTurn();
		drawGame();
		checkVitoria();

		// O BOT NAO JOGA LOGO DEPOIS DO JOGADOR VENCER
		if (!reset) {
			botTurn();
			drawGame();
			checkVitoria();
		}

		if (reset) {
			resetGrid();
		}
		
		
	}

	cout << "\nObrigado por jogar!\n";

	return 0;
}
