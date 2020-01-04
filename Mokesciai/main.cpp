// Komentaras
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

struct Mok {
	string vard;
	double sil, tel, vand;
};

void skaitymas(Mok A[], int & n);
void mokesciai(Mok A[], int n, double & suma, double & suma2, double & suma3);
void skaiciavimas(Mok A[], double BendraS[], int n);
void spausdinti(Mok A[], double BendraS[], int n, double suma, double suma2, double suma3);

int main()
{
	Mok A[50];
	double BendraS[50] = { 0 };
	int n;
	double suma, suma2, suma3;
	int kieklt, kiekct;
	skaitymas(A, n);
	mokesciai(A, n, suma, suma2, suma3);
	skaiciavimas(A, BendraS, n);
	spausdinti(A, BendraS, n, suma, suma2, suma3);

	return 0;
}

void skaitymas(Mok A[], int & n)
{
	ifstream fd("u2.txt");
	fd >> n;
	for (int i = 0; i < n; i++)
		fd >> A[i].vard >> A[i].sil >> A[i].tel >> A[i].vand;
	fd.close();
}

void mokesciai(Mok A[], int n, double & suma, double & suma2, double & suma3)
{
	suma = 0; suma2 = 0; suma3 = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i].sil > 0)
			suma = suma + A[i].sil;

		if (A[i].tel > 0)
			suma2 = suma2 + A[i].tel;

		if (A[i].vand > 0)
			suma3 = suma3 + A[i].vand;
	}
}

void skaiciavimas(Mok A[], double BendraS[], int n)
{
	for (int i = 0; i < n; i++) {
		if (A[i].sil > 0)
			BendraS[i] = BendraS[i] + A[i].sil;

		if (A[i].tel > 0)
			BendraS[i] = BendraS[i] + A[i].tel;

		if (A[i].vand > 0)
			BendraS[i] = BendraS[i] + A[i].vand;
	}

}

void spausdinti(Mok A[], double BendraS[], int n, double suma, double suma2, double suma3)
{
	ofstream fr("rez2.txt");
	fr << "Už šilumą turi būti sumokėta: " << suma << "\n";
	fr << "Už telefoną turi būti sumokėta: " << suma2 << "\n";
	fr << "Už vandenį turi būti sumokėta: " << suma3 << "\n";
	fr << "---------------------------------" << "\n";
	fr << "    Vardas        Turi sumokėti" << "\n";
	fr << "---------------------------------" << "\n";
	for (int i = 0; i < n; i++)
	{
	if ( A[i].sil > 0 || A[i].vand > 0 || A[i].tel > 0)
		fr << fixed << setprecision(2) << setw(15) << left << A[i].vard << setw(12) << right << BendraS[i] << "\n";
		}
	fr << "---------------------------------" << "\n";
	fr.close();
}
