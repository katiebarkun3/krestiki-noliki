//Екатерина Баркун
#include <iostream>
using namespace std;

void init_field(char** field, int size);
void print_field(char** field, int size);
void player_turn(char** field, int size);
bool check_win(char** field, int size, char sign);
bool check_draw(char** field, int size);



//==========MAIN==========

int main() {

	//подключаем русский язык
	setlocale(LC_ALL, "rus");

	//выделение памяти под поле
	int size = 3;
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}

	//заполняем поле пробелами
	init_field(field, size);
	//print_field(field, size);

	while (true) {
		//ход крестиков
		player_turn(field, size);

		//печать поля
		print_field(field, size);

		//если выигрыш крестиков, то прервать цикл
		if (check_win(field, size, 'x')) {
		cout << "выиграли крестики!" << endl;
		break;
        }

		//если ничья, то прервать цикл
		if (check_draw(field, size)) {
			cout << "ничья!" << endl;
			break;
		}

		//ход ноликов
		player_turn(field, size);

		//печать поля
		print_field(field, size);

		//если выигрыш ноликов, то прервать цикл
		if (check_win(field, size, 'o')) {
			cout << "выиграли нолики!" << endl;
			break;
		}

		//если ничья, то прервать цикл
		if (check_draw(field, size)) {
			cout << "ничья!" << endl;
			break;
		}
	}
	return 0;
}



//==========ФУНКЦИИ==========

//выделение поля
void init_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = ' ';
		}
	}
}

//границы поля
void print_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < size; j++) {
			cout << "| " << field[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << "|---|---|---|" << endl;
}

//ход игрока
void player_turn(char** field, int size) {
	int row, col;
	char sign;

	do {
		do {
			cout << "введите номер строки ";
			cin >> row;
		} while (row < 0 || row > size - 1);

		do {
			cout << "введите номер столбца ";
			cin >> col;
		} while (col < 0 || col > size - 1);
	} while (field[row][col] != ' ');
	do {
		cout << "введите значок х или о (английскими символами)" << endl;
		cin >> sign;
	} while (sign != 'x' && sign != 'o');
	field[row][col] = sign;
}

//проверка на победу крестиков / ноликов
bool check_win(char** field, int size, char sign) {
	//проверка строки номер 0
	if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) { return true; }
	//проверка строки номер 1
	if (field[1][0] == sign && field[1][1] == sign && field[1][2] == sign) { return true; }
	//проверка строки номер 2
	if (field[2][0] == sign && field[2][1] == sign && field[2][2] == sign) { return true; }
	//проверка  столбца номер 0
	if (field[0][0] == sign && field[1][0] == sign && field[2][0] == sign) { return true; }
	//проверка  столбца номер 1
	if (field[0][1] == sign && field[1][1] == sign && field[2][1] == sign) { return true; }
	//проверка  столбца номер 2
	if (field[0][2] == sign && field[1][2] == sign && field[2][2] == sign) { return true; }
	//проверка главной диагонали
	if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) { return true; }
	//проверка побочной диагонали
	if (field[0][2] == sign && field[1][1] == sign && field[2][0] == sign) { return true; }
	//всё проверили и не разу не нашли выигрыш - выигыша нет, поэтому возвращаем false 
	return false;
}

//проверка ничьей
bool check_draw(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (field[i][j] == ' ') return false;
		}
	}
	return true;
}















