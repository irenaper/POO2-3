#include <string>
#include <iostream>
#include <fstream>
#include "Film.h"

using namespace std;

class Bilet
{
private:
	char* nume;
	float pret;
	int nrCateg;
	int* categorii;
	int nrFilme;
	Film* listaFilme;

	const int idBilet;
	static int nrBilete;

public:
	Bilet() : idBilet(++nrBilete)
	{
		nume = nullptr;
		pret = 0;
		categorii = nullptr;
		nrCateg = 0;
		nrFilme = 1;
		listaFilme = nullptr;
	}

	Bilet(const char* nume, float pret, int* categorii, int nrCateg, int nrFilme, Film* listaFilme)
		:idBilet(++nrBilete)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->pret = pret;
		this->nrCateg = nrCateg;
		if (categorii != nullptr && nrCateg > 0)
		{
			this->categorii = new int[nrCateg];
			for (int i = 0; i < nrCateg; i++)
			{
				this->categorii[i] = categorii[i];
			}
		}
		else
		{
			this->categorii = nullptr;
			this->nrCateg = 0;
		}
		this->nrFilme = nrFilme;
		if (nrFilme > 0 && listaFilme != nullptr) {
			this->listaFilme = new Film[nrFilme];
			for (int i = 0; i < nrFilme; i++) {
				this->listaFilme[i] = listaFilme[i];
			}
		}
		else {
			this->nrFilme = 0;
			this->listaFilme = nullptr;
		}
	}

	Bilet(const Bilet& b) : idBilet(++nrBilete)
	{
		if (b.nume != nullptr)
		{
			this->nume = new char[strlen(b.nume) + 1];
			strcpy_s(this->nume, strlen(b.nume) + 1, b.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		this->pret = b.pret;
		this->nrCateg = b.nrCateg;
		if (b.categorii != nullptr && b.nrCateg > 0)
		{
			this->categorii = new int[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++)
			{
				this->categorii[i] = b.categorii[i];
			}
		}
		else
		{
			this->categorii = nullptr;
			this->nrCateg = 0;
		}
		this->nrFilme = b.nrFilme;
		if (b.nrFilme > 0 && b.listaFilme != nullptr) {
			listaFilme = new Film[b.nrFilme];
			for (int i = 0; i < b.nrFilme; i++) {
				this->listaFilme[i] = b.listaFilme[i];
			}
		}
		else {
			this->nrFilme = 0;
			this->listaFilme = nullptr;
		}
	}

	~Bilet()
	{
		if (nume != nullptr)
		{
			delete[] nume;
		}
		if (categorii != nullptr)
		{
			delete[] categorii;
		}
		if (listaFilme != nullptr) {
			delete[]listaFilme;
		}
	}

	Bilet& operator=(const Bilet& b)
	{
		if (nume != nullptr)
		{
			delete[] nume;
		}
		if (categorii != nullptr)
		{
			delete[] categorii;
		}
		if (listaFilme != nullptr) {
			delete[]listaFilme;
		}
		if (b.nume != nullptr)
		{
			this->nume = new char[strlen(b.nume) + 1];
			strcpy_s(this->nume, strlen(b.nume) + 1, b.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		this->pret = b.pret;
		this->nrCateg = b.nrCateg;
		if (b.categorii != nullptr && b.nrCateg != 0)
		{
			this->categorii = new int[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++)
			{
				this->categorii[i] = b.categorii[i];
			}
		}
		else
		{
			this->categorii = nullptr;
			this->nrCateg = 0;
		}
		this->nrFilme = b.nrFilme;
		if (b.nrFilme > 0 && b.listaFilme != nullptr) {
			listaFilme = new Film[b.nrFilme];
			for (int i = 0; i < b.nrFilme; i++) {
				this->listaFilme[i] = b.listaFilme[i];
			}
		}
		else {
			this->nrFilme = 0;
			this->listaFilme = nullptr;
		}

		return *this;
	}

	const char* getNume() {
		return nume;
	}

	Film* getFilme() {
		return listaFilme;
	}

	float getPret() {
		return pret;
	}

	int getNrCat()
	{
		return nrCateg;
	}

	float getMedie() {
		float s = 0;
		for (int i = 0; i < nrCateg; i++) {
			s += categorii[i];
		}
		if (nrCateg != 0)
			return s / nrCateg;
		else
			return 0;
	}

	int* getCategorii()
	{
		if (categorii != nullptr)
		{
			int* copie = new int[nrCateg];
			for (int i = 0; i < nrCateg; i++)
			{
				copie[i] = categorii[i];

			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getCategorie(int index)
	{
		if (index >= 0 && index < nrCateg && categorii != nullptr)
		{
			return categorii[index];
		}
	}

	void setNume(const char* nume) {
		if (strlen(nume) >= 3) {
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
			throw "Numele este prea scurt";
	}

	void setPret(float valoare) {
		this->pret = valoare;
	}

	void setNrCateg(int valoare) {
		if (valoare > 0) {
			this->nrCateg = nrCateg;
		}
	}

	void setCategorii(int* categorii, int nrCateg)
	{
		if (categorii != nullptr && nrCateg != 0)
		{
			this->nrCateg = nrCateg;
			if (this->categorii != nullptr)
			{
				delete[] this->categorii;

			}
			this->categorii = new int[nrCateg];
			for (int i = 0; i < nrCateg; i++)
			{
				this->categorii[i] = categorii[i];
			}
		}
	}

	Bilet operator+(float valoare)
	{
		Bilet copie = *this;
		copie.pret += valoare;
		return copie;
	}

	Bilet operator*(float valoare)
	{
		Bilet copie = *this;
		copie.pret *= valoare;
		return copie;
	}

	/*void operator*=(int repetitii) {
		*this = repetitii * (*this);
	}*/

	Bilet operator++()
	{
		this->pret++;
		return *this;
	}

	Bilet operator++(int i)
	{
		Bilet copie = *this;
		this->pret++;
		return copie;
	}

	Film& operator[](int i) {
		if (i >= 0 && i < this->nrFilme) {
			return this->listaFilme[i];
		}
		else throw new exception("Indexul nu e valid.");
	}	

	explicit operator int()
	{
		return pret;
	}

	bool operator!()
	{
		return pret > 20;
	}

	static int getNrBilete()
	{
		return Bilet::nrBilete;
	}
	static void setNrBilete(int nrBilete)
	{
		Bilet::nrBilete = nrBilete;
	}

	static float medieBilete(Bilet* bilete, int nrBilete)
	{
		float suma = 0;
		int nr = 0;
		if (bilete != nullptr && nrBilete > 0)
		{
			for (int i = 0; i < nrBilete; i++)
			{
				if (bilete[i].categorii != nullptr)
				{
					for (int j = 0; j < bilete[i].nrCateg; j++)
					{
						suma += bilete[i].categorii[j];
						nr++;
					}
				}
			}
			if (nr > 0)
			{
				return suma / nr;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	//Bilet& operator+=(Film& film) {
	//	bool contine = false;
	//	for (int i = 0; i < this->nrFilme; i++) {
	//		if (this->listaFilme != nullptr && this->listaFilme[i] = (&film)) {
	//			contine = true;
	//		}				
	//	}
	//	if (contine == false) {
	//		Film* filmNou = new Film[this->nrFilme + 1];
	//		for (int i = 0; i < this->nrFilme; i++) {
	//			filmNou[i] = listaFilme[i];
	//		}
	//		filmNou[this->nrFilme] = film;
	//		delete[] listaFilme;
	//		this->nrFilme++;
	//		this->listaFilme = filmNou;

	//		return *this;
	//	}
	//}

	Bilet& operator-=(Film& f) {
		int j = -1;
		int k = 0;
		for (int i = 0; i < this->nrFilme; i++)
			if (strcmp(this->listaFilme[i].getTitlu(), f.getTitlu()) == 0 &&
				this->listaFilme[i].getNrReviews() == f.getNrReviews() &&
				this->listaFilme[i].getReviews() == f.getReviews())
			{
				j = i;
				break;
			}
		if (j != -1)
		{
			Film* filmeNou = new Film[this->nrFilme - 1];
			for (int i = 0; i < this->nrFilme; i++)
			{
				if (i != j) {
					filmeNou[k] = this->listaFilme[i];
					k++;
				}
			}
			delete[]this->listaFilme;
			this->listaFilme = filmeNou;
			this->nrFilme = this->nrFilme - 1;
		}
		return *this;
	}
	Bilet& operator-=(const char* nume) {
		int a = -1;
		int b = 0;
		for (int i = 0; i < this->nrFilme; i++)
			if (strcmp(this->listaFilme[i].getTitlu(), nume) == 0) {
				a = i; break;
			}
		if (a != -1) {
			Film* op = new Film[this->nrFilme - 1];
			for (int i = 0; i < this->nrFilme; i++)
				if (i != a) {
					op[b] = this->listaFilme[i];
					b++;
				}
			delete[] this->listaFilme;
			this->listaFilme = op;
			this->nrFilme--;
		}
		return* this;
	}

	void operator-=(int nrCategSters) {
		if (nrCategSters <= this->nrCateg) {
			int* listaNoua = new int[this->nrCateg - nrCategSters];
			for (int i = 0; i < this->nrCateg - nrCategSters; i++)
				listaNoua[i] = this->categorii[i];
			if (this->categorii != nullptr)
				delete[] this->categorii;
			this->categorii = listaNoua;
			this->nrCateg -= nrCategSters;
		}
		else
			throw new exception();
	}

	friend ostream& operator<<(ostream& out, Bilet b)
	{
		out << "Nume persoana: " << b.nume << endl;
		out << "Pret bilet: " << b.pret << endl;
		out << "Nr. categorii pret: " << b.nrCateg << endl;
		out << "Preturi in categorie: ";
		for (int i = 0; i < b.nrCateg; i++)
		{
			out << b.categorii[i] << " " << endl;
		}
		out << "Nr filme:" << b.nrFilme << endl;
		for (int i = 0; i < b.nrFilme; i++) {
			out << b.listaFilme[i] << endl;
		}
		out << "Nr total de bilete: " << b.nrBilete << endl;
		out << "---end output Bilet---";
		return out;
	}

	friend ofstream& operator<<(ofstream& fout, Bilet b) {
		fout << b.nume << endl;
		fout << b.pret << endl;
		fout << b.nrCateg << endl;
		for (int i = 0; i < b.nrCateg; i++) {
			fout << b.categorii[i] << endl;
		}
		fout << b.nrFilme << endl;
		for (int i = 0; i < b.nrFilme; i++) {
			fout << b.listaFilme[i] << endl;
		}
		return fout;
	}

	friend istream& operator>>(istream& in, Bilet& b) {
		char buffer[100];
		cout << "Nume persoana = ";
		in >> ws;
		in.getline(buffer, 99);
		if (b.nume != nullptr)
		{
			delete[] b.nume;
		}
		b.nume = new char[strlen(buffer) + 1];
		strcpy_s(b.nume, strlen(buffer) + 1, buffer);
		cout << "Pret bilet = ";
		in >> b.pret;
		cout << "Nr. categorii = ";
		in >> b.nrCateg;
		if (b.categorii != nullptr)
		{
			delete[] b.categorii;
		}
		if (b.nrCateg > 0)
		{
			b.categorii = new int[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++) {
				cout << "Preturi in categorii[" << i << "] = ";
				in >> b.categorii[i];
			}
		}
		else
		{
			b.nrCateg = 0;
			b.categorii = nullptr;
		}

		cout << "Nr. filme = ";
		in >> b.nrFilme;

		if (b.listaFilme != nullptr) {
			delete[]b.listaFilme;
		}
		if (b.nrFilme > 0) {
			b.listaFilme = new Film[b.nrFilme];
			for (int i = 0; i < b.nrFilme; i++) {
				cout << "Film " << i + 1 << endl;
				in >> b.listaFilme[i];
			}
		}
		else {
			b.nrFilme = 0;
			b.listaFilme = nullptr;
		}
		cout << "---end intput Bilet---" << endl;

		return in;
	}


	friend ifstream& operator>>(ifstream& fin, Bilet& b)
	{
		char buffer[100];
		fin >> ws;
		fin.getline(buffer, 99);
		if (b.nume != nullptr)
		{
			delete[] b.nume;
		}
		b.nume = new char[strlen(buffer) + 1];
		strcpy_s(b.nume, strlen(buffer) + 1, buffer);
		fin >> b.pret;
		fin >> b.nrCateg;
		if (b.categorii != nullptr)
		{
			delete[] b.categorii;
		}
		if (b.nrCateg > 0)
		{
			b.categorii = new int[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++)
			{
				fin >> b.categorii[i];
			}
		}
		else
		{
			b.nrCateg = 0;
			b.categorii = nullptr;
		}
		fin >> b.nrFilme;
		if (b.listaFilme != nullptr) {
			delete[] b.listaFilme;
		}
		b.listaFilme = new Film[b.nrFilme];
		for (int i = 0; i < b.nrFilme; i++) {
			fin >> b.listaFilme[i];
			/*Film b;
			fin >> b;*/
		}
		cout << "---end intput Bilet---" << endl;

		return fin;
	}

	void scrieBiletBin() {
		ofstream f;
		f.open("bilete.bin", ios_base::out | ios::binary);
		f.write((char*)this, sizeof(Bilet));
	}

	void citesteBiletBin() {
		ifstream f;
		f.open("bilete.bin", ios_base::in | ios::binary);
		f.read((char*)this, sizeof(Bilet));
	}

	void afisare() {
		cout << "Nume persoana: " << this->nume << endl;
		cout << "Pret bilet: " << this->pret << endl;
		cout << "Nr. categorii pret: " << this->nrCateg << endl;
		cout << "Preturi in categorie: ";
		for (int i = 0; i < this->nrCateg; i++)
		{
			cout << this->categorii[i] << " " << endl;
		}
		//cout << "Nr total de bilete: " << this->nrMaxBilete - this->nrBilete << endl;
		//cout << "---end output Bilet---";
		//return b;
	}


};

