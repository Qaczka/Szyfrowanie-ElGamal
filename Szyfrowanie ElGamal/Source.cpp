#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>


using namespace std;

bool czy_pierwsza(int n)
{
	double pierw=sqrt(n);
	int i;

	if (n < 2)
	{
		return false;
	}
	else
	{

		for (i = 2; i <= pierw; i++)
		{
			if (n%i == 0)
			{
				return false;
			}
			
		}
		return true;
	}
}

int potega(int a,int b,int c)
{
	int i, a_bitowe[60], potega[60], mnozenie;

	
	potega[0] = 1;

	a_bitowe[0] = a%c;
	i = 1;
	mnozenie = 1;


	while (potega[i - 1]<(b))
	{
		a_bitowe[i] = (a_bitowe[i - 1] * a_bitowe[i - 1]) % c;
		potega[i] = potega[i - 1] * 2;
		//printf("A to: %i\n", a_bitowe[i]);
		i++;

		//printf("Potega %i Liczba i %i\n", potega[i - 1], i);

	}
	i--;

	while (i >= 0)
	{
		if (b - potega[i] >= 0)
		{
			b = b - potega[i];
			mnozenie = (mnozenie*a_bitowe[i]) % c;
			// printf("Mnozenie to: %i\n",mnozenie);

		}
		i--;

	}


	//cout << "Mnozenie to:" << mnozenie << endl;
	return mnozenie;
}



int main()
{
	int n,z;
	cout << "Prosze podac liczbe pierwsza n: " << endl;
	cin >> n;
	cout << "Prosze podac pierwiastek pierwotny n z przedzialu 1<r<" << n - 1 << endl;

	if (czy_pierwsza(n) == true)
	{
		cout << "Jest to liczba pierwsza" << endl;
		z = 1;
	}
	else
	{
		cout << "Nie jest to liczba pierwsza" << endl;
		z = 0;
	}

	if (z == 1)
	{

		int i, m, k, S[100000];
		double pierwiastek;

		m = n - 1;

		pierwiastek = sqrt(m);

		for (i = 0; i < m; i++)
		{
			S[i] = i + 2;
		}

		for (i = 0; i < m; i++)
		{
			if (((double)S[i] <= pierwiastek) && (S[i] != 0))
			{
				for (k = i + 1; k < m; k++)
				{
					if (S[k] % S[i] == 0)
					{
						S[k] = 0;
					}
				}
			}
		}
		vector <int> cos;
		k = 0;

		for (i = 0; i < m; i++)
		{
			if (S[i] != 0 && (n - 1) % S[i] == 0)
			{
				//cout << S[i] << " ";
				cos.push_back(S[i]);
				k++;
			}
		}

		for (i = 0; i < k; i++)
		{
			//	cout << cos[i] << " ";
		}

		int r, a, j, c1, c2, t,r1;
		double g;
		bool czy_ok = true;

		cout << "Proszê podac r: ";
		cin >> r1;

	//	for (r = 1; r < n - 1; r++)
	//	{
			czy_ok = true;
			for (i = 0; i < k; i++)
			{

				g = potega(r1, (n - 1) / cos[i], n);
				if (g == 1)
				{
					czy_ok = false;
					break;
				}
			}
			if (czy_ok == true)
			{
				//cout << "R to liczba: " << r << endl;
			}
			else
			{
				cout << "R nie jest pierwiastkiem" << endl;
			}
	//	}

		///////
			r = r1;
		cout << endl << "Proszê podac k: ";
		cin >> k;
		cout << endl << "Proszê podac losowa tajna liczbe j: ";
		cin >> j;
		cout << endl << "Proszê podac t: ";
		cin >> t;
		cout << endl;

		//////

		a = potega(r, k, n);

		c1 = potega(r, j, n);
		c2 = (t*potega(a, j, n)) % n;

		cout << "Klucz publiczny to: (" << n << "," << r << "," << a << ")" << endl;
		cout << "Klucz prywatny to: (" << n << "," << r << "," << a << "," << k << ")" << endl;
		cout << "Szyfrogram to: (" << c1 << "," << c2 << ")" << endl;

		cout << "Odszyfrowanie to: " << (c2*potega(c1, n - 1 - k, n)) % n << endl;
	}

	system("PAUSE");
	return 0;
}