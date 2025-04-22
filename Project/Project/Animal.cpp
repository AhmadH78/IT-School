#include "Animal.h"
#include <iostream>


Animal::Animal(const std::string specie, int cantitate, int pret, double procentVanzare)
: specie(specie), cantitate(cantitate), pret(pret), procentVanzare(procentVanzare) {
}


std::string Animal::getSpecie() const { return specie; }
int Animal::getCantitate() const { return cantitate; }
int Animal::getPret() const { return pret; }
double Animal::getProcentVanzare() const { return procentVanzare; }


void Animal::setCantitate(int newCantitate) { cantitate = newCantitate; }
void Animal::setPret(int newPret) { pret = newPret; }
void Animal::setProcentVanzare(double newProcentVanzare) { procentVanzare = newProcentVanzare; }


int Animal::estimareVanzare() const {
	return static_cast<int>(getCantitate() * getProcentVanzare());
}

int Animal::estimarePastrare() const {
	return cantitate - estimareVanzare();
}

void Animal::afisare() const {
	std::cout << specie << "..." << cantitate << "\n" << estimareVanzare() << " pentru vanzare, " << estimarePastrare() << " pentru pastrare\n";
}

void Animal::afisareIstoric() const {
	std::cout << "Stoc ramas pentru: " << specie << "..." << cantitate << "\n";
}