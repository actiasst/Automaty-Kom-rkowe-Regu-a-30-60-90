#include <iostream>

#define WIELKOSC_REGULA 8
#define ROZMIAR 119

using namespace std;

bool regula[WIELKOSC_REGULA];
void wyznacz_regula();
void wyswietl_regula();
void zamien();
void inicjuj();
void wyswietl();
bool regula1(bool, bool, bool);
bool regula2(bool, bool, bool);
bool regula3(bool, bool, bool);
bool regula4(bool, bool, bool);
bool regula5(bool, bool, bool);
bool regula6(bool, bool, bool);
bool regula7(bool, bool, bool);
bool regula8(bool, bool, bool);
void licz();

bool tab[ROZMIAR];
bool tmp[ROZMIAR];

int main() {
	while (true) {
		inicjuj();
		wyznacz_regula();
		system("cls");
		wyswietl_regula();

		wyswietl();
		for (int i = 0; i < 58; i++) {
			licz();
			wyswietl();
		}
	}
	system("pause");
}

void wyznacz_regula() {
	for (int i = 0; i < WIELKOSC_REGULA; i++)
		regula[i] = false;

	int liczba;
	int licznik = WIELKOSC_REGULA-1;

	cout << "Podaj regule: ";

	while (true) {
		cin >> liczba;
		if (liczba < 256 && liczba > -1)
			break;
		cout << "Liczba musi byc z przedzialu <0,255>" << endl;
	}
	while (liczba > 0) {
		regula[licznik] = liczba % 2;
		liczba /= 2;
		licznik--;
	}
}

void wyswietl_regula() {
	cout<< "Regula to ";
	for (int i = 0; i < WIELKOSC_REGULA; i++)
		cout << regula[i];
	cout << endl;
}

void zamien() {
	for (int i = 0; i < ROZMIAR; i++) {
		tab[i] = tmp[i];
	}
}

void inicjuj() {
	for (int i = 0; i < ROZMIAR; i++) {
		tab[i] = 0;
	}
	tab[(ROZMIAR - 1) / 2] = true;
}

void wyswietl() {
	for (int i = 0; i < ROZMIAR; i++)
		if (tab[i])
			cout << (char)177;
		else
			cout << " ";
	cout << endl;
}

bool regula1(bool a, bool b, bool c) {
	if (a && b && c)
		return true;
	else
		return false;
}

bool regula2(bool a, bool b, bool c) {
	if (a && b && !c)
		return true;
	else
		return false;
}

bool regula3(bool a, bool b, bool c) {
	if (a && !b && c)
		return true;
	else
		return false;
}

bool regula4(bool a, bool b, bool c) {
	if (a && !b && !c)
		return true;
	else
		return false;
}

bool regula5(bool a, bool b, bool c) {
	if (!a && b && c)
		return true;
	else
		return false;
}

bool regula6(bool a, bool b, bool c) {
	if (!a && b && !c)
		return true;
	else
		return false;
}

bool regula7(bool a, bool b, bool c) {
	if (!a && !b && c)
		return true;
	else
		return false;
}

bool regula8(bool a, bool b, bool c) {
	if (!a && !b && !c)
		return true;
	else
		return false;
}

void licz() {
	if (regula1(false, tab[0], tab[1]))
		tmp[0] = regula[0];
	else if (regula2(false, tab[0], tab[1]))
		tmp[0] = regula[1];
	else if (regula3(false, tab[0], tab[1]))
		tmp[0] = regula[2];
	else if (regula4(false, tab[0], tab[1]))
		tmp[0] = regula[3];
	else if (regula5(false, tab[0], tab[1]))
		tmp[0] = regula[4];
	else if (regula6(false, tab[0], tab[1]))
		tmp[0] = regula[5];
	else if (regula7(false, tab[0], tab[1]))
		tmp[0] = regula[6];
	else if (regula8(false, tab[0], tab[1]))
		tmp[0] = regula[7];

	if (regula1(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[0];
	else if (regula2(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[1];
	else if (regula3(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[2];
	else if (regula4(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[3];
	else if (regula5(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[4];
	else if (regula6(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[5];
	else if (regula7(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[6];
	else if (regula8(tab[ROZMIAR - 2], tab[ROZMIAR - 1], false))
		tmp[ROZMIAR - 1] = regula[7];

	for (int i = 1; i < ROZMIAR - 1; i++) {
		if (regula1(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[0];
		else if (regula2(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[1];
		else if (regula3(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[2];
		else if (regula4(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[3];
		else if (regula5(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[4];
		else if (regula6(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[5];
		else if (regula7(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[6];
		else if (regula8(tab[i - 1], tab[i], tab[i + 1]))
			tmp[i] = regula[7];
	}
	zamien();
}