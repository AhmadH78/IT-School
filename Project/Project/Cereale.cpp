#include "Cereale.h"
#include <iostream>


Cereale::Cereale(const std::string tip, double cantitate, int pret, double procentVanzare)
	: tip(tip), cantitate(cantitate), pret(pret), procentVanzare(procentVanzare) {
}


std::string Cereale::getTip() const { return tip; }
double Cereale::getCantitate() const { return cantitate; }
int Cereale::getPret() const { return pret; }
double Cereale::getProcentVanzare() const { return procentVanzare; }


void Cereale::setCantitate(int newCantitate) { cantitate = newCantitate; }
void Cereale::setPret(int newPret) { pret = newPret; }
void Cereale::setProcentVanzare(double newProcentVanzare) { procentVanzare = newProcentVanzare; }


int Cereale::estimareVanzare() const {
	return static_cast<int>(cantitate * procentVanzare);
}

int Cereale::estimarePastrare() const {
	return cantitate - estimareVanzare();
}

void Cereale::afisare() const {
	std::cout << tip << "..." << cantitate << " tone\n" << estimareVanzare() << " pentru vanzare, " << estimarePastrare() << " pentru pastrare\n";
}

void Cereale::afisareIstoric() const {
	std::cout << "Stoc ramas pentru: " << tip << "..." << cantitate << " tone\n";
}