#include <iostream>
#include <string>
#include <vector>

class Animal {
private:
	std::string specie;
	int cantitate;
	int pret;
	double procentVanzare;

public:
	Animal(const std::string specie, int cantitate, int pret, double procentVanzare)
		: specie(specie), cantitate(cantitate), pret(pret), procentVanzare(procentVanzare) {}

	~Animal() {}


	std::string getSpecie() const { return specie; }
	int getCantitate() const { return cantitate; }
	int getPret() const { return pret; }
	double getProcentVanzare() const { return procentVanzare; }


	void setCantitate(int newCantitate) { cantitate = newCantitate; }
	void setPret(int newPret) { pret = newPret; }
	void setProcentVanzare(double newProcentVanzare) { procentVanzare = newProcentVanzare; }


	int estimareVanzare() const {
		return static_cast<int>(getCantitate() * getProcentVanzare());
	}

	int estimarePastrare() const {
		return cantitate - estimareVanzare();
	}

	void afisare() const {
		std::cout << specie << "..." << cantitate << "\n" << estimareVanzare() << " pentru vanzare, " << estimarePastrare() << " pentru pastrare\n";
	}
};



class Cereale {
private:
	std::string tip;
	double cantitate;
	int pret;
	double procentVanzare;

public:
	Cereale(const std::string tip, int cantitate, int pret, double procentVanzare)
		: tip(tip), cantitate(cantitate), pret(pret), procentVanzare(procentVanzare) {
	}

	~Cereale() {}


	std::string getTip() const { return tip; }
	double getCantitate() const { return cantitate; }
	int getPret() const { return pret; }
	double getProcentVanzare() const { return procentVanzare; }


	void setCantitate(int newCantitate) { cantitate = newCantitate; }
	void setPret(int newPret) { pret = newPret; }
	void setProcentVanzare(double newProcentVanzare) { procentVanzare = newProcentVanzare; }


	int estimareVanzare() const {
		return static_cast<int>(cantitate * procentVanzare);
	}

	int estimarePastrare() const {
		return cantitate - estimareVanzare();
	}

	void afisare() const {
		std::cout << tip << "..." << cantitate << " tone\n" << estimareVanzare() << " pentru vanzare, " << estimarePastrare() << " pentru pastrare\n";
	}
};


class Ferma {
private:
	std::vector<Animal*> animale;
	std::vector<Cereale> cereale;
	int anCurent;

public:
	Ferma(int an): anCurent(an){}

	~Ferma() {
		for (auto animal : animale) {
			delete animal;
		}
	}


	void adaugaAnimal(Animal* animal) {
		animale.push_back(animal);
	}

	void adaugaCereale(Cereale cereala) {
		cereale.push_back(cereala);
	}


	void afisareStocCurent() {
		std::cout << "--- Stoc curent " << anCurent << " ---\n";
		std::cout << "Animal:\n";
		for (auto& animal : animale) {
			animal->afisare();
			std::cout<<"\n";
		}

		std::cout << "Cereale:\n";
		for (auto cereal : cereale) {
			cereal.afisare();
			std::cout << "\n";
		}
	}

	void afisareBilant() {
		std::cout << "\n--- Bilant estimativ pentru" << anCurent << " ---\n";

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

		std::cout << "Total cereale: " << totalCereale << "\nCereale vandute: " << totalCereale << " pentru un total de: " << totalPretCereale << "\n\n";
		
		std::cout << "Bilant total: " << totalAnimale + totalCereale << "\n";
	}

};


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

int main() {

	Ferma ferma(2025);

	ferma.adaugaAnimal(new Vaca(100, 20, 0.2));
	ferma.adaugaAnimal(new Gaina(50, 10, 0.5));

	ferma.adaugaCereale(Cereale("Grau", 10, 5, 0.6));
	ferma.adaugaCereale(Cereale("Orez", 15, 2, 0.8));

	ferma.afisareStocCurent();
	ferma.afisareBilant();

	return 0;
}