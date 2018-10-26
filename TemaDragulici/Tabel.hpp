#pragma once
#include "individ.hpp"

class Tabel {
public:
	Tabel();
	void Init();
	void Afisare();
	void Actualizare();
	bool Test();
	Individ Alocare(int, int);
	void Eliminare(int, int);
private:
	
	int m_lungime = 20, m_latime = 70;
	Individ **Harta;
};