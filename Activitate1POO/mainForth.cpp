#include<iostream>
#include<string>

using namespace std;

class Sejur {
private:
	const int idSejur;
	int nrZile;
	float* costuriZilnice;
	static int nrSejururi;

public:
	Sejur() : idSejur(++nrSejururi) {
		this->nrZile = 0;
		this->costuriZilnice = nullptr;
	}

	Sejur(int nrZile, float* costuriZilnice) :idSejur(++nrSejururi) {
		this->nrZile = nrZile;

		if (nrZile > 0 && costuriZilnice != nullptr) {
			this->costuriZilnice = new float[nrZile];

			for (int i = 0; i < nrZile; i++) {
				this->costuriZilnice[i] = costuriZilnice[i];
			}
		}
		else {
			this->nrZile = 0;
			this->costuriZilnice = nullptr;
		}
	}

	~Sejur() {
		if (costuriZilnice != nullptr) {
			delete[] this->costuriZilnice;
		}
	}

	int getIdSejur() const {
		return this->idSejur;
	}

	void setCosturiZilnice(float* costuriNoi, int nrZileNoi) {
		float* copie = nullptr;

		if (nrZileNoi > 0 && costuriNoi != nullptr) {
			copie = new float[nrZileNoi];
			for (int i = 0; i < nrZileNoi; i++) {
				copie[i] = costuriNoi[i];
			}
		}
		else {
			nrZileNoi = 0;
		}
		if (this->costuriZilnice != nullptr) {
			delete[] this->costuriZilnice;
		}

		this->costuriZilnice = copie;
		this->nrZile = nrZileNoi;
	}

	void afisare() {
		cout << endl << "id Sejur: " << this->idSejur;
		cout << endl << "nr Zile: " << this->nrZile;

		if (this->costuriZilnice != nullptr) {
			cout << endl << "Costurile zilnice sunt: ";
			for (int i = 0; i < nrZile; i++)
				cout <<this->costuriZilnice[i] << " ";
		}
		else {
			cout << endl<< "0 costuri";
		}
		cout << endl;
	}
};

int Sejur::nrSejururi = 0;

int main() {
	Sejur s1;
	s1.afisare();

	float costuri[] = { 150, 200, 250 };

	Sejur s2(3, costuri);
	s2.afisare();

	cout << endl << "id-ul sejurului s2: " << s2.getIdSejur() << endl;

	float costuri2[] = { 300, 350 };

	s2.setCosturiZilnice(costuri2, 2);
	s2.afisare();
}