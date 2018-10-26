#pragma once
#include "Tabel.hpp"

class Individ {
private:
	int m_i, m_j;
	char m_tip;
	int m_varsta;
	double m_energie;
	unsigned char m_viu;
	bool m_rescriptibil;
	Individ(bool); 
	Individ(int, int, char);
	void Hraneste(Individ &, Tabel &);
	void Inmulteste();
	void Ataca(Individ &, Tabel &);
	void Imbatraneste();
	void Moare();
	friend class Tabel;
public:
	void Actualizare();
	bool EsteViu();
	char GetTip();
};