#pragma once
#include <vector>
#include "Animal.h"
#include "Cereale.h"


class Ferma
{
private:
	std::vector<Animal*> animale;
	std::vector<Cereale> cereale;
	int anCurent;

public:
	Ferma(int an);
	~Ferma();

	Animal* getAnimal(int index) const;
	Cereale getCereala(int index) const;

	void adaugaAnimale(Animal* animal);
	void adaugaCereale(Cereale cereala);

	void afisareIstoric(int vaci, int gaini, int oi, double grau, double porumb, double orz);
	void afisareStocCurent();
	void afisareBilant();
};