#include "Ferma.h"
#include <iostream>

Ferma::Ferma(int an) : anCurent(an) {}
Ferma::~Ferma() {
	for (auto animal : animale) {
		delete animal;
	}
}

Animal* Ferma::getAnimal(int index) const{
	if (index >= 0 && index < animale.size()) {
		return animale[index];
	}
	return nullptr;
}

Cereale Ferma::getCereala(int index) const{
	if (index >= 0 && index < cereale.size()) {
		return cereale[index];
	}
	return Cereale("", 0, 0, 0);
}

void Ferma::adaugaAnimale(Animal* animal) {
	animale.push_back(animal);
}
void Ferma::adaugaCereale(Cereale cereala) {
	cereale.push_back(cereala);
}


void Ferma::afisareIstoric(int vaci, int gaini, int oi, double grau, double porumb, double orz) {
	std::cout << "\n\n--- Istoric " << anCurent-1 << " ---\n\n";
	std::cout << "Animale:\n";
	std::cout << "  Vaci: " << vaci << "\n  Gainii: " << gaini << "\n  Oi: " << oi << "\n\n";
	std::cout << "Cereale:\n";
	std::cout << "  Grau: " << grau << "\n  Porumb: " << porumb << "\n  Orz: " << orz << "\n\n";
}

void Ferma::afisareStocCurent() {
	std::cout << "\n\n--- Stoc curent " << anCurent << " ---\n\n";

	std::cout << "Animale:\n";
	for (auto& animal : animale) {
		animal->afisare();
		std::cout << "\n";
	}

	std::cout << "Cereale:\n";
	for (auto cereal : cereale) {
		cereal.afisare();
		std::cout << "\n";
	}
}

void Ferma::afisareBilant() {
	std::cout << "\n\n--- Bilant estimativ pentru " << anCurent << " ---\n\n";

	int totalAnimale = 0;
	int totalAnimaleVandute = 0;
	int totalPretAnimale = 0;

	for (auto& animal : animale) {
		totalAnimale += animal->getCantitate();
		totalAnimaleVandute += animal->estimareVanzare();
		totalPretAnimale += (animal->estimareVanzare()) * (animal->getPret());
	}

	std::cout << "Total animale: " << totalAnimale << "\nAnimale vandute: " << totalAnimaleVandute << " pentru un total de: " << totalPretAnimale << "\n\n";


	int totalCereale = 0;
	int totalCerealeVandute = 0;
	int totalPretCereale = 0;

	for (auto cereal : cereale) {
		totalCereale += cereal.getCantitate();
		totalCerealeVandute += cereal.estimareVanzare();
		totalPretCereale += (cereal.estimareVanzare()) * (cereal.getPret());
	}

	std::cout << "Total cereale: " << totalCereale << "\nCereale vandute: " << totalCerealeVandute << " pentru un total de: " << totalPretCereale << "\n\n";

	std::cout << "Bilant total: " << totalPretAnimale + totalPretCereale << "\n\n";
}