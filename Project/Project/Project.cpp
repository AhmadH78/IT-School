#include "Animal.h"
#include "Cereale.h"
#include "Ferma.h"
#include <iostream>


class Vaca :public Animal {
public:
	Vaca(int cantitate, int pret, double procentVanzare)
		: Animal("Vaca", cantitate, pret, procentVanzare){}
};

class Gaina :public Animal {
public:
	Gaina(int cantitate, int pret, double procentVanzare)
		:Animal("Gaina", cantitate, pret, procentVanzare) {
	}
};

class Oaie :public Animal {
public:
	Oaie(int cantitate, int pret, double procentVanzare)
		:Animal("Oaie", cantitate, pret, procentVanzare) {
	}
};

void introducereDate(int &cantitate, int &pret, double &procentVanzare) {
	std::cout << "  -cantitate: ";
	std::cin >> cantitate;
	std::cout << "  -pret: ";
	std::cin >> pret;
	std::cout << "  -procentul de vanzare: ";
	std::cin >> procentVanzare;
}


int main() {

	std::cout << "Introduce an curent: ";
	int anCurent;
	std::cin >> anCurent;

	int vaciRamase = 0, gainiRamase = 0, oiRamase = 0;
	double grauRamas = 0, porumbRamas = 0, orzRamas = 0;

	int an = 0;
	int ok = 1;

	while (ok == 1) {
		Ferma ferma(anCurent);


		std::cout << "\nIntroduceti datele fermei pentru anul " << anCurent << ": \n";
		std::cout << "\nIntroduceti animale:\n";
		int cantitate, pret;
		double procentVanzare;

		std::cout << "  Vaca:\n";
		introducereDate(cantitate, pret, procentVanzare);
		ferma.adaugaAnimale(new Vaca(cantitate + vaciRamase, pret, procentVanzare));

		std::cout << "\n  Gaina:\n";
		introducereDate(cantitate, pret, procentVanzare);
		ferma.adaugaAnimale(new Gaina(cantitate + gainiRamase, pret, procentVanzare));

		std::cout << "\n  Oaie:\n";
		introducereDate(cantitate, pret, procentVanzare);
		ferma.adaugaAnimale(new Oaie(cantitate + oiRamase, pret, procentVanzare));


		std::cout << "\nIntroduceti cereale:\n";

		std::cout << "  Grau:\n";
		introducereDate(cantitate, pret, procentVanzare);
		ferma.adaugaCereale(Cereale("Grau", cantitate + grauRamas, pret, procentVanzare));

		std::cout << "\n  Porumb:\n";
		introducereDate(cantitate, pret, procentVanzare);
		ferma.adaugaCereale(Cereale("Porumb", cantitate + porumbRamas, pret, procentVanzare));

		std::cout << "\n  orz:\n";
		introducereDate(cantitate, pret, procentVanzare);
		ferma.adaugaCereale(Cereale("orz", cantitate + orzRamas, pret, procentVanzare));

		if (an != 0)
			ferma.afisareIstoric(vaciRamase, gainiRamase, oiRamase, grauRamas, porumbRamas, orzRamas);

		ferma.afisareStocCurent();
		ferma.afisareBilant();


		vaciRamase = ferma.getAnimal(0)->estimarePastrare();
		gainiRamase = ferma.getAnimal(1)->estimarePastrare();
		oiRamase = ferma.getAnimal(2)->estimarePastrare();

		grauRamas = ferma.getCereala(0).estimarePastrare();
		porumbRamas = ferma.getCereala(1).estimarePastrare();
		orzRamas = ferma.getCereala(2).estimarePastrare();



		std::cout << "Doriti sa continuati? (y/n): ";

		char optiune;
		std::cin >> optiune;

		if (optiune == 'y' || optiune == 'Y') {
			std::cout << "Continuati...\n";
			anCurent++;
			an = 1;
		}
		else {
			std::cout << "Doriti sa incepeti alta ferma? (y/n): ";
			std::cin >> optiune;

			if (optiune == 'y' || optiune == 'Y') {
				std::cout << "Introduce an curent: ";
				std::cin >> anCurent;
				an = 0;
			}
			else {
				std::cout << "Iesire...\n";
				ok = 0;
			}
		}
	}
	

	return 0;
}