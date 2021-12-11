//Баркун Екатерина
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int main() {
//char s;
//s = 'a'; //в переменную s записывается символ а
	const int n = 3;
	char field[n][n];
	//заполнить массив случайным образом буквами x и o. вывести массив на экран
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = rand() % 2;
			if (t == 0)field[i][j] = 'x';
			else field[i][j] = 'o';
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < n; j++) {
			cout << "| " << field[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	   cout << "|---|---|---|" << endl;
	   //проверка того, что выиграли крестики
	   //проверка строк
	   //проверка строки номер 0
	   if (field[0][0] == 'x' && field[0][1] == 'x' && field[0][2] == 'x') {
		   cout << "x wins" << endl;
	       }
	   //проверка строки номер 1
	   if (field[1][0] == 'x' && field[1][1] == 'x' && field[1][2] == 'x') {
			   cout << "x wins" << endl;
		   }
	   //проверка строки номер 2
	   if (field[2][0] == 'x' && field[2][1] == 'x' && field[2][2] == 'x') {
	  	       cout << "x wins" << endl;
		   }
				   //проверка  столбца номер 0
			   if (field[0][0] == 'x' && field[1][0] == 'x' && field[2][0] == 'x') {
				   cout << "x wins" << endl;
			   }
				   //проверка  столбца номер 1
			   if (field[0][1] == 'x' && field[1][1] == 'x' && field[2][1] == 'x') {
				   cout << "x wins" << endl;
			   }
				   //проверка  столбца номер 2
			   if (field[0][2] == 'x' && field[1][2] == 'x' && field[2][2] == 'x') {
					cout << "x wins" << endl;
	           }
			   //проверка главной диагонали
			   if (field[0][0] == 'x' && field[1][1] == 'x' && field[2][2] == 'x') {
				   cout << "x wins" << endl;
			   }
			   //проверка побочной диагонали
			   if (field[0][2] == 'x' && field[1][1] == 'x' && field[2][0] == 'x') {
				   cout << "x wins" << endl;
			   }







	return 0;
}
