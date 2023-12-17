#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

void static drawCalc() {
	for (int line = 0; line < 30; line++) cout << '#';
	cout << '\n' << "  Calculadora" << '\n';
	for (int line = 0; line < 30; line++) cout << '#';
}

static void calculadora() {
	vector<double> valores;
	double value, resultado = 0.0;
	bool running = true;
	bool inserindo = true;
	char op;
	int ins;

	while (running) {
		drawCalc();
		cout << '\n' << "Digite uma operacao [ + - / *]: ";
		cin >> op;

		cout << '\n' << "Digite o valor: ";
		cin >> value;
		valores.push_back(value);

		while (inserindo) {
			cout << "Digite outro valor: ";
			cin >> value;
			valores.push_back(value);
			cout << "Inserir novo valor [1] ou finalizar? [0]: ";
			cin >> ins;
			if (ins == 0) {
				inserindo = false;
				running = false;
			}
		}

		for (int i = 0; i < valores.size(); i++) {
			if (i == 0) {
				resultado = valores[i];
			}
			else {
				switch (op) {
				case '+':
					resultado += valores[i];
					break;
				case '-':
					resultado -= valores[i];
					break;
				case '/':
					resultado /= valores[i];
					break;
				case '*':
					resultado *= valores[i];
					break;
				}
			}
		}

		cout << '\n' << "O resultado da operacao foi: " << resultado << '\n';
	}

}

int main() {
	bool calculando = true;
	char continuar;

	while (calculando) {
		system("cls");
		calculadora();
		cout << '\n' << "Fazer outro calculo? [y/n]: ";
		cin >> continuar;

		if (continuar == 'n') {
			calculando = false;
		}
	}
	
	return 0;
}