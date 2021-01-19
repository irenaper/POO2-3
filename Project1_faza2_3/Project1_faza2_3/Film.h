#include <string>
#include <iostream>
#include <fstream>
#include "Cinema.h"

using namespace std;

class Film
{
	char* titlu;
	int nrReviews;
	int* reviews;

	int nrCinema;
	Cinema* listaCinema;

	const int idFilm = 0;
	static int nrFilme;
public:
	Film() :idFilm(nrFilme++) {
		titlu = nullptr;
		nrReviews = 1;
		reviews = nullptr;
		nrCinema = 1;
		listaCinema = nullptr;
	}

	Film(const char* titlu, int nrReviews, int* reviews, int nrCinema, Cinema* listaCinema) :idFilm(nrFilme++) {
		if (titlu != nullptr) {
			this->titlu = new char[strlen(titlu) + 1];
			strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		}
		else {
			this->titlu = nullptr;
		}
		if (nrReviews > 0 && reviews != nullptr) {
			this->nrReviews = nrReviews;
			this->reviews = new int[nrReviews];
			for (int i = 0; i < nrReviews; i++) {
				this->reviews[i] = reviews[i];
			}
		}
		else {
			this->nrReviews = 0;
			this->reviews = nullptr;
		}
		if (nrCinema > 0 && listaCinema != nullptr) {
			this->nrCinema = nrCinema;
			this->listaCinema = new Cinema[nrCinema];
			for (int i = 0; i < nrCinema; i++) {
				this->listaCinema[i] = listaCinema[i];
			}
		}
		else {
			this->nrCinema = 0;
			this->listaCinema = nullptr;
		}
	}

	Film(const Film& f) :idFilm(f.idFilm) {
		if (f.titlu != nullptr) {
			this->titlu = new char[strlen(f.titlu) + 1];
			strcpy_s(this->titlu, strlen(f.titlu) + 1, f.titlu);
		}
		else {
			this->titlu = nullptr;
		}
		if (f.nrReviews > 0 && f.reviews != nullptr) {
			this->nrReviews = f.nrReviews;
			this->reviews = new int[f.nrReviews];
			for (int i = 0; i < f.nrReviews; i++) {
				this->reviews[i] = f.reviews[i];
			}
		}
		else {
			this->nrReviews = 0;
			this->reviews = nullptr;
		}

		if (f.nrCinema > 0 && f.listaCinema != nullptr) {
			this->nrCinema = f.nrCinema;
			listaCinema = new Cinema[f.nrCinema];
			for (int i = 0; i < f.nrCinema; i++) {
				this->listaCinema[i] = f.listaCinema[i];
			}
		}

		else {
			this->nrCinema = 0;
			this->listaCinema = nullptr;
		}
	}

	~Film() {
		if (this->titlu != nullptr) {
			delete[]this->titlu;
		}
		if (this->reviews != nullptr) {
			delete[]this->reviews;
		}
		if (this->listaCinema != nullptr) {
			delete[]this->listaCinema;
		}
	}

	Film operator=(const Film& f) {
		if (this->titlu != nullptr) {
			delete[]this->titlu;
		}
		if (this->reviews != nullptr) {
			delete[]this->reviews;
		}
		if (this->listaCinema != nullptr) {
			delete[]this->listaCinema;
		}

		if (f.titlu != nullptr) {
			this->titlu = new char[strlen(f.titlu) + 1];
			strcpy_s(this->titlu, strlen(f.titlu) + 1, f.titlu);
		}
		else {
			this->titlu = nullptr;
		}
		if (f.nrReviews > 0 && f.reviews != nullptr) {
			this->nrReviews = f.nrReviews;
			this->reviews = new int[f.nrReviews];
			for (int i = 0; i < f.nrReviews; i++) {
				this->reviews[i] = f.reviews[i];
			}
		}
		else {
			this->nrReviews = 0;
			this->reviews = nullptr;
		}
		if (f.nrCinema > 0 && f.listaCinema != nullptr) {
			this->nrCinema = f.nrCinema;
			listaCinema = new Cinema[f.nrCinema];
			for (int i = 0; i < f.nrCinema; i++) {
				this->listaCinema[i] = f.listaCinema[i];
			}
		}
		else {
			this->nrCinema = 0;
			this->listaCinema = nullptr;
		}

		return *this;
	}

	Cinema* getListaCinema() {
		return listaCinema;
	}
	const char* getTitlu() {
		return titlu;
	}
	int getNrReviews() {
		return nrReviews;
	}

	int* getReviews() {
		return reviews;
	}
	int getIdFilm() {
		return idFilm;
	}

	int& operator[](int index) {
		if (index < this->nrReviews && index >= 0) {
			return reviews[index];
		}
		throw exception("index invalid");
	}

	Film operator+(int valoare) {
		if (valoare > 0) {
			Film copie = *this;
			copie.nrReviews += valoare;
			return copie;
		}
		else {
			throw 1;
		}
	}

	bool operator>(Film f) {
		return this->nrReviews > f.nrReviews;
	}

	bool operator!() {
		return nrReviews > 1000;
	}

	explicit operator float() {
		return getMedieRev();
	}

	float getMedieRev() {
		if (this->reviews != nullptr) {
			int suma = 0;
			//int medie = 0;
			for (int i = 0; i < this->nrReviews; i++) {
				suma += this->reviews[i];
			}
			return (float)suma / this->nrReviews;
		}
		else
			return 0;
	}

	Film operator+=(Film f) {

	}
	Film operator++() {
		this->nrReviews++;
		return *this;
	}

	Film operator++(int) {
		Film copie = *this;
		this->nrReviews++;
		return copie;
	}
	/*friend bool operator==(Film1& f1, Film1& f2) {
		return strcmp(f1.den, f2.den) == 0 &&
			f1.pret == f2.pret;
	}*/

	friend bool operator==(Film& f1, Film& f2) {
		return strcmp(f1.titlu, f2.titlu) == 0;
	}


	void adaugareCinema(Cinema* c)
	{
		Cinema* copie = new Cinema[nrCinema + 1];
		for (int i = 0; i < nrCinema; i++) {
			copie[i] = listaCinema[i];
		}
		delete[] listaCinema;
		copie[nrCinema++] = *c;
		listaCinema = copie;
		ofstream fisOut("ListaCinema.dat", ios::app | ios::binary);
		if (fisOut.is_open()) {
			(*c).scrieCinemaBinar(fisOut);
			fisOut.close();
		}
		else cout << "fisierul nu este deschis";
	}

	Film& operator-=(Cinema& c) {
		int j = -1;
		int k = 0;
		for (int i = 0; i < this->nrFilme; i++)
			if (strcmp(this->listaCinema[i].getDenumire(), c.getDenumire()) == 0 &&
				this->listaCinema[i].getNrProiectii() == c.getNrProiectii() &&
				this->listaCinema[i].getOreProiectii() == c.getOreProiectii())
			{
				j = i;
				break;
			}
		if (j != -1)
		{
			Cinema* CinemaNou = new Cinema[this->nrCinema - 1];
			for (int i = 0; i < this->nrCinema; i++)
			{
				if (i != j) {
					CinemaNou[k] = this->listaCinema[i];
					k++;
				}
			}
			delete[]this->listaCinema;
			this->listaCinema = CinemaNou;
			this->nrCinema = this->nrCinema - 1;
		}
		return *this;
	}


	void scrieFilmBinar(ofstream& fisBin) {
		int lung = strlen(titlu);
		fisBin.write((char*)&lung, sizeof(lung));
		fisBin.write(titlu, lung + 1);
		fisBin.write((char*)&this->nrReviews, sizeof(int));
		for (int i = 0; i < this->nrReviews; i++) {
			fisBin.write((char*)&this->reviews[i], sizeof(int));
		}
		fisBin.write((char*)&this->nrFilme, sizeof(int));
		for (int i = 0; i < this->nrFilme; i++) {
			fisBin.write((char*)&this->listaCinema[i], sizeof(Cinema));			
			//(&this->listaCinema[i])->scrieCinemaBinar(fisBin);
		}
	}

	void citireFilmBinar(ifstream& fisBin) {
		int lung = 0;
		fisBin.read((char*)&lung, sizeof(lung));
		delete[] titlu;
		titlu = new char[lung + 1];
		fisBin.read(titlu, lung + 1);
		fisBin.read((char*)&this->nrReviews, sizeof(int));
		if (this->reviews != nullptr) {
			delete[] this->reviews;
		}
		this->reviews = new int[this->nrReviews];
		for (int i = 0; i < this->nrReviews; i++) {
			fisBin.read((char*)&this->reviews[i], sizeof(int));
		}
		fisBin.read((char*)&this->nrFilme, sizeof(int));
		if (this->listaCinema != nullptr) {
			delete[] this->listaCinema;
		}
		this->listaCinema = new Cinema[this->nrFilme];
		for (int i = 0; i < this->nrFilme; i++) {
			fisBin.read((char*)&this->listaCinema[i], sizeof(Cinema));
			//(&this->listaCinema[i])->citireCinemaBinar(fisBin);
		}
	}




	friend istream& operator>> (istream& in, Film& f) {
		cout << "Titlu film = ";
		in >> ws;
		char buffer[100];
		in.getline(buffer, 99);
		if (f.titlu != nullptr) {
			delete[] f.titlu;
		}
		f.titlu = new char[strlen(buffer) + 1];
		strcpy_s(f.titlu, strlen(buffer) + 1, buffer);

		cout << "Nr. reviews = ";
		in >> f.nrReviews;
		if (f.reviews != nullptr) {
			delete[]f.reviews;
		}
		if (f.nrReviews > 0) {
			f.reviews = new int[f.nrReviews];
			for (int i = 0; i < f.nrReviews; i++) {
				cout << "Review " << i + 1 << " = ";
				in >> f.reviews[i];
			}
		}
		else {
			f.nrReviews = 0;
			f.reviews = nullptr;
		}
		cout << "Nr. listaCinema = ";
		in >> f.nrCinema;
		if (f.listaCinema != nullptr) {
			delete[]f.listaCinema;
		}
		if (f.nrCinema > 0) {
			f.listaCinema = new Cinema[f.nrCinema];
			for (int i = 0; i < f.nrCinema; i++) {
				cout << "Cinema " << i + 1 << endl;
				Cinema c;
				in >> c;
				//	in >> f.listaCinema[i];

			}
		}
		else {
			f.nrCinema = 0;
			f.listaCinema = nullptr;
		}
		cout << "---end input Film---" << endl;

		return in;
	}

	friend ostream& operator<<(ostream& out, Film f) {
		out << endl << "Titlu: " << f.titlu << endl;
		out << "Nr reviews: " << f.nrReviews << endl;
		for (int i = 0; i < f.nrReviews; i++) {
			out << "Review " << i + 1 << ": " << f.reviews[i] << endl;
		}
		out << "Nr cinema:" << f.nrCinema << endl;
		//	out << "Bilete: " << endl;
		for (int i = 0; i < f.nrCinema; i++) {
			out << "Lista Cinema " << i + 1 << " " << f.listaCinema[i] << endl;
		}
		out << "---end output Film---";
		return out;
	}

	friend ofstream& operator<<(ofstream& fout, Film f) {
		fout << f.titlu << endl;
		fout << f.nrReviews << endl;
		for (int i = 0; i < f.nrReviews; i++) {
			fout << f.reviews[i] << endl;
		}
		fout << f.nrCinema << endl;
		for (int i = 0; i < f.nrCinema; i++) {
			fout << f.listaCinema[i] << endl;
		}
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Film& f) {
		if (f.titlu != nullptr) {
			delete[] f.titlu;
		}
		char buffer[100];
		fin >> buffer;
		f.titlu = new char[strlen(buffer) + 1];
		strcpy_s(f.titlu, strlen(buffer) + 1, buffer);
		fin >> f.nrReviews;
		if (f.reviews != nullptr) {
			delete[] f.reviews;
		}
		f.reviews = new int[f.nrReviews];
		for (int i = 0; i < f.nrReviews; i++) {
			fin >> f.reviews[i];
		}
		fin >> f.nrCinema;
		if (f.listaCinema != nullptr) {
			delete[] f.listaCinema;
		}
		f.listaCinema = new Cinema[f.nrCinema];
		for (int i = 0; i < f.nrCinema; i++) {
			fin >> f.listaCinema[i];
		}
		return fin;
	}

	//pentru o lista de nr dat de filme
	void salvareFisierBinar(const char* fisBin, Cinema* listaCinema, int nrCinema) {
		if (fisBin == nullptr || listaCinema == nullptr || nrCinema == 0) {
			cout << "datele de intrare nu sunt valide" << endl;
		}
		else {
			ofstream fisier;
			fisier.open(fisBin, ofstream::out | ofstream::binary);
			if (fisier.is_open()) {
				fisier.write((char*)&nrCinema, sizeof(int));
				for (int i = 0; i < nrCinema; i++) {

					int lungime = strlen(listaCinema[i].getDenumire()) + 1;
					fisier.write((char*)&lungime, sizeof(int));
					fisier.write(listaCinema[i].getDenumire(), lungime * sizeof(char));

					int nrReviews = listaCinema[i].getNrProiectii();
					fisier.write((char*)&nrReviews, sizeof(int));
					for (int j = 0; j < listaCinema[i].getNrProiectii(); j++) {
						fisier.write((char*)&listaCinema[i].getOreProiectii()[j], sizeof(int));
					}
				}
				fisier.close();
			}
			else {
				cout << "Fisierul nu s-a putut deschide" << endl;
			}
		}
	}


};


