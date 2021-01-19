#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Cinema
{
	char* denumire;
	int nrProiectii;
	int* oreProiectii;

	const int idC;
	static int nrCinema;
public:
	Cinema() :idC(++nrCinema) {
		denumire = nullptr;
		nrProiectii = 0;
		oreProiectii = nullptr;
	}

	Cinema(const char* denumire, int nrProiectii, int* oreProiectii) :idC(++nrCinema) {
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}		
		if (nrProiectii > 0 && oreProiectii != nullptr) {
			this->nrProiectii = nrProiectii;
			this->oreProiectii = new int[nrProiectii];
			for (int i = 0; i < nrProiectii; i++)
			{
				this->oreProiectii[i] = oreProiectii[i];
			}
		}
		else {
			this->nrProiectii = 0;
			this->oreProiectii = nullptr;
		}
	}

	Cinema(const Cinema& c) :idC(c.nrCinema) {
		if (c.denumire != nullptr) {
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
		}
		else {
			this->denumire = nullptr;
		}	
		
		if (c.nrProiectii > 0 && c.oreProiectii != nullptr) {
			this->nrProiectii = c.nrProiectii;
			this->oreProiectii = new int[c.nrProiectii];
			for (int i = 0; i < c.nrProiectii; i++) {
				this->oreProiectii[i] = c.oreProiectii[i];
			}
		}
		else {
			this->nrProiectii = 0;
			this->oreProiectii = nullptr;
		}
	}

	~Cinema() {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
		if (this->oreProiectii != nullptr) {
			delete[]this->oreProiectii;
		}
	}

	Cinema operator=(const Cinema& c) {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
		if (this->oreProiectii != nullptr) {
			delete[]this->oreProiectii;
		}
		if (c.denumire != nullptr) {
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
		}
		else {
			this->denumire = nullptr;
		}		
		if (c.nrProiectii > 0 && c.oreProiectii != nullptr) {	
			this->nrProiectii = c.nrProiectii;
			this->oreProiectii = new int[c.nrProiectii];
			for (int i = 0; i < c.nrProiectii; i++) {
				this->oreProiectii[i] = c.oreProiectii[i];
			}
		}
		else {
			this->nrProiectii = 0;
			this->oreProiectii = nullptr;
		}

		return *this;
	}

	int& operator[](int index) {
		if (index < this->nrProiectii && index >= 0) {
			return oreProiectii[index];
		}
		throw exception("index invalid");
	}

	Cinema operator+(int valoare) {
		if (valoare > 0) {
			Cinema copie = *this;
			copie.nrProiectii += valoare;
			return copie;
		}
		else {
			throw 1;
		}
	}

	bool operator>(Cinema c) {
		return this->nrProiectii > c.nrProiectii;
	}

	bool operator!() {
		return nrProiectii > 1000;
	}

	explicit operator float() {
		return getMedie();
	}

	const char* getDenumire() {
		return denumire;
	}

	int getNrProiectii() {
		return nrProiectii;
	}

	int* getOreProiectii() {
		return oreProiectii;
	}
	float getMedie() {
		if (this->oreProiectii != nullptr) {
			int suma = 0;
			//int medie = 0;
			for (int i = 0; i < this->nrProiectii; i++) {
				suma += this->oreProiectii[i];
			}
			return (float)suma / this->nrProiectii;
		}
		else
			return 0;
	}
	Cinema operator++() {
		this->nrProiectii++;
		return *this;
	}

	Cinema operator++(int) {
		Cinema copie = *this;
		this->nrProiectii++;
		return copie;
	}
	

	friend ostream& operator<<(ostream& out, Cinema& c) {
		out << "Cinematograf: " << c.denumire << endl;
		out << "Nr oreProiectii: " << c.nrProiectii << endl;
		for (int i = 0; i < c.nrProiectii; i++) {
			out << "Ora proiectie:" << c.oreProiectii[i] << endl;
		}
		out << "---end output Cinema---" << endl;
		return out;
	}

	friend istream& operator>> (istream& in, Cinema& c) {
		cout << "Cinematograf = ";
		in >> ws;
		char buffer[100];
		in.getline(buffer, 99);
		if (c.denumire != nullptr) {
			delete[] c.denumire;
		}
		c.denumire = new char[strlen(buffer) + 1];
		strcpy_s(c.denumire, strlen(buffer) + 1, buffer);
		cout << "Nr oreProiectii = ";
		in >> c.nrProiectii;
		if (c.oreProiectii != nullptr) {
			delete[]c.oreProiectii;
		}
		if (c.nrProiectii > 0) {
			c.oreProiectii = new int[c.nrProiectii];
			for (int i = 0; i < c.nrProiectii; i++) {
				cout << "Ora proiectie " << i + 1 << " = ";
				in >> c.oreProiectii[i];
			}
		}
		else {
			c.nrProiectii = 0;
			c.oreProiectii = nullptr;
		}
		cout << "---end input Cinema---" << endl;

		return in;
	}

	friend ofstream& operator<<(ofstream& fout, Cinema c) {
		fout << c.denumire << endl;
		fout << c.nrProiectii << endl;
		for (int i = 0; i < c.nrProiectii; i++) {
			fout << c.oreProiectii[i] << endl;
		}
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Cinema& c) {
		if (c.denumire != nullptr) {
			delete[] c.denumire;
		}
		char buffer[100];
		fin >> buffer;
		c.denumire = new char[strlen(buffer) + 1];
		strcpy_s(c.denumire, strlen(buffer) + 1, buffer);
		fin >> c.nrProiectii;

		if (c.oreProiectii != nullptr) {
			delete[] c.oreProiectii;
		}
		c.oreProiectii = new int[c.nrProiectii];
		for (int i = 0; i < c.nrProiectii; i++) {
			fin >> c.oreProiectii[i];
		}

		return fin;
	}	

	void scrieCinemaBinar(ofstream& fisBin) {
		int lung = strlen(denumire);
		fisBin.write((char*)&lung, sizeof(lung));
		fisBin.write(denumire, lung + 1);
		fisBin.write((char*)&this->nrProiectii, sizeof(int));
		for (int i = 0; i < this->nrProiectii; i++) {
			fisBin.write((char*)&this->oreProiectii[i], sizeof(int));
		}
	}
	void citireCinemaBinar(ifstream& fisBin) {
		int lung = 0;
		fisBin.read((char*)&lung, sizeof(lung));
		delete[] denumire;
		denumire = new char[lung + 1];
		fisBin.read(denumire, lung + 1);
		fisBin.read((char*)&this->nrProiectii, sizeof(int));
		if (this->oreProiectii != nullptr)
			delete[] this->oreProiectii;
		this->oreProiectii = new int[this->nrProiectii];
		for (int i = 0; i < this->nrProiectii; i++) {
			fisBin.read((char*)&this->oreProiectii[i], sizeof(int));
		}
	}

	void scrieBin() {
		ofstream f;
		f.open("cinemas.bin", ios_base::out | ios::binary);
		f.write((char*)this, sizeof(Cinema));
	}

	void citesteBin() {
		ifstream f;
		f.open("cinemas.bin", ios_base::in | ios::binary);
		f.read((char*)this, sizeof(Cinema));
	}

};


