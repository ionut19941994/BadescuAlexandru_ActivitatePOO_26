#include<iostream>
#include<string>

using namespace std;

class Companie {
private: 
	char* numeCompanie;
	const int idCompanie;
	double cifraAfaceri;

	static int nrCompanii;

public: 

	Companie() :idCompanie(++nrCompanii) {
		this->numeCompanie = nullptr;
		this->cifraAfaceri = 0;
	}

	Companie(const char* numeCompanie) : idCompanie(++nrCompanii) {
		if (numeCompanie != nullptr) {
			this->numeCompanie = new char[strlen(numeCompanie) + 1];
			strcpy_s(this->numeCompanie, strlen(numeCompanie) + 1, numeCompanie);
		}
		else {
			this->numeCompanie = nullptr;
		}
		this->cifraAfaceri = 0;
	}

	~Companie() {
		if (this->numeCompanie != nullptr) {
			delete[] this->numeCompanie;
		}
	}

	void afisare() {
		cout << endl << "ID companie" << this->idCompanie;
		cout << endl << "Nume Companie: ";
		if (this->numeCompanie != nullptr) {
			cout << this->numeCompanie;
		}
		else {
			cout << "nedefinit";
		}

		cout << endl << "cifra de afaceri: " << this->cifraAfaceri << endl;
		
	}
	int getIdCompanie() const {
		return this->idCompanie;
	}


	void setNumeCompanie(const char* numeNou) {
		char* copie = nullptr;

		if (numeNou != nullptr) {
			copie = new char[strlen(numeNou) + 1];
			strcpy_s(copie, strlen(numeNou) + 1, numeNou);
		}

		if (this->numeCompanie != nullptr) {
			delete[] this->numeCompanie;
		}

		this->numeCompanie = copie;
	}
};

int Companie::nrCompanii = 0;


int main() {
	Companie c1;
	c1.afisare();

	Companie c2("Microsoft");
	c2.afisare();

	cout << endl << "Id'ul companiei c2 este: " << c2.getIdCompanie() << endl;

	c2.setNumeCompanie("Microsoft Corporation");
	c2.afisare();

	return 0;
}

