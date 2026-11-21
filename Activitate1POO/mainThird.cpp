#include<iostream>
#include<string>

using namespace std;

class Calatorie {
private: 
	char* numeDestinatie;
	const int idCalatorie;
	static int nrCalatorii;

public:
	Calatorie() :idCalatorie(++nrCalatorii) {
		this->numeDestinatie = nullptr;
	}

	Calatorie(const char* numeDestinatie) :idCalatorie(++nrCalatorii) {
		if (numeDestinatie != nullptr) {
			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
			strcpy_s(this->numeDestinatie, strlen(numeDestinatie) + 1, numeDestinatie);
		}
		else {
			this->numeDestinatie = nullptr;
		}
	}

	~Calatorie() {
		if (this->numeDestinatie != nullptr) {
			delete[] this->numeDestinatie;
		}
	}

	int getIdCalatorie() const {
		return this->idCalatorie;
	}

	void setNumeDestinatie(const char* numeNou) {
		char* copie = nullptr;
		if (numeNou != nullptr) {
			copie = new char[strlen(numeNou) + 1];
			strcpy_s(copie, strlen(numeNou) + 1, numeNou);
		}
		if(this->numeDestinatie != nullptr) {
			delete[] this->numeDestinatie;
		}

		this->numeDestinatie = copie;
	}

	void afisare() {
		cout << endl << "ID calatorie: " << this->idCalatorie;
		cout << endl << "nume Destinatie: ";

		if (this->numeDestinatie != nullptr) {
			cout << this->numeDestinatie;
		}
		else {
			cout << "nedefinit";
		}
		cout << endl;
	}
};

int Calatorie::nrCalatorii = 0;

int main() {

	Calatorie c1;
	c1.afisare();

	Calatorie c2("Tenerife");
	c2.afisare();

	cout << "Id-ul destinatiei c2 este " << c2.getIdCalatorie() << endl;

	c2.setNumeDestinatie("Bora Bora");
	c2.afisare();

}