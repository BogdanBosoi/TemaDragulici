#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef H_Tabel;
#define H_Tabel;
#endif
#include "Tabel.hpp"

#define VARSTA_MAXIMA 80


Individ::Individ(bool rescriptibil = 1) {
	this -> m_rescriptibil = rescriptibil;
}

Individ::Individ(int pozX, int pozY, char tip) {
	this->m_i = pozX;
	this->m_j = pozY;
	this->m_tip = tip;
	this->m_varsta = 0;
	this->m_energie = 100;
	this->m_rescriptibil = 0;
	this->m_viu = 1;

}

Individ Tabel::Alocare(int pozX, int pozY) {
	int chance = rand() % 100;
	char tip;
	if (chance >= 50)
		tip = '+';
	else
		tip = '0';
	Individ omulet(pozX, pozY, tip);
	Harta[pozX][pozY] = omulet;
}

void Tabel::Eliminare(int pozX, int pozY) {
	Individ inexistent;
	Harta[pozX][pozY] = inexistent;
}

void Tabel::Actualizare() {
	for (int contorL = 1; contorL <= 20; contorL++)
		for (int contorC = 1; contorC <= 70; contorC++)
			if (Harta[contorL][contorC].m_viu == 0)
				Eliminare(contorL, contorC);
	
}

void Tabel::Afisare() {
	for (int contorL = 1; contorL <= 20; contorL++, std::cout << '\n')
		for (int contorC = 1; contorC <= 70; contorC++)
			if (Harta[contorL][contorC].m_rescriptibil == 1)
				std::cout << '*';
			else
				std::cout << Harta[contorL][contorC].m_tip;

}

bool Tabel::Test() {
	for (int contorL = 1; contorL <= 20; contorL++)
		for (int contorC = 1; contorC <= 70; contorC++)
			if (Harta[contorL][contorC].m_viu == 1)
				return 1;
	return 0;
}

void Individ::Hraneste(Individ & omulet, Tabel & Lume) {
	

}

void Individ::Ataca(Individ & omulet, Tabel & Lume) {

}

void Tabel::Init() {
	Harta = new Individ*[20];
	for (int contor = 1; contor <= 20; contor++)
		Harta[contor] = new Individ[70];

	srand(time(NULL));
	int numarIndivizi = rand() % 10 + 5;
	int pozX, pozY;
	for (int contor = 1; contor <= numarIndivizi; contor++) {
		do {
			pozX = rand() % 20 + 1;
			pozY = rand() % 20 + 1;
		} while (Harta[pozX][pozY].m_rescriptibil == 0);
		Alocare(pozX, pozY);
	}
}

Tabel::Tabel() {
	Init();
}

int main(){
	system("PAUSE");
	return 0;
}