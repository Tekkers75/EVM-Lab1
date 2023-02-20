#include <iostream>
#include <string>
#include <cmath>
using namespace std;



void Vvod_D2(double* mas1, string size1)
{
	size_t k = size1.size();

	for (size_t i = 0; i < k; i++)
	{
		mas1[i] = size1[i] - 48;
		//cout << mas1[i];
	}
	//cout << endl;
}


/// Перевод целого числа из 2 в 10 +
int D2_in_D10(double* masD2, string size1)
{
	int k = size1.size();
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += masD2[i] * pow(2,k-i-1);
	}
	//cout << "10 = " << sum << endl;
	//cout << endl;
	return sum;
}

/// Перевод дробного числа из 2 в 10 
double D2_in_D10_Frac(double* masD2, string size1)
{
	int k = size1.size();
	double sum = 0;
	int chet = 0;
	for (int i = 0; i < k; i++)
	{
		sum += masD2[i] * pow(2, (chet - 1 - i));
	}
	//cout << "10 = " << sum;
	//cout << endl;
	//cout << sum;
	//cout << endl;
	return sum;
}





/// Перевод целого числа из 10 в 8
string D10_in_D8(double* masD2, int sum)
{
	int ch = 1;
	int copy = sum;
	string s;
	while (copy >= 7)
	{
		ch++;
		copy /= 8;
	}
	for (int i = (ch-1); i > 0; i--)
	{
		masD2[i] = sum % 8;
		sum /= 8;
	}
	masD2[0] = (int)(sum);
	for (int i = 0; i < ch; i++)
	{
		
		s.push_back((char)(((int)'0') + masD2[i]));
		//cout << masD2[i] << "proverka" << endl;
		//cout << s + "s" << endl;
		//cout << masD2[i];
	}

	return s;
	//cout << endl;
}

/// Перевод из 10 в 8 дробной части
string D10_in_D8_frac(double* masD2, double sum)
{
	int chet;
	string s;
	for (int i = 0; i < 3; i++)
	{
		sum = sum * 8;
		chet = sum / 1;
		if (chet >= 1)
		{
			sum -= chet;
		}
		s.push_back((char)(((int)'0') + chet));
	}
	//cout << s;
	return s;
}






int main()
{
	setlocale(LC_ALL, "russian");
	string D1;
	//string D2Frac;
	cout << "Введите двоичное число ";
	cin >> D1;
	auto pos = D1.find('.');
	string D2 = D1.substr(0, pos);
	string D2Frac = D1.substr(pos + 1);
	
	size_t k = D2.size();
	size_t s = D2Frac.size();

	double* masD2 = new double[k];
	double* masD2_frac = new double[s];


	Vvod_D2(masD2, D2);
	D2_in_D10(masD2, D2);
	//D10_in_D8(masD2, D2_in_D10(masD2, D2));

	Vvod_D2(masD2_frac, D2Frac);
	//D2_in_D10(masD2, D2);
	D2_in_D10_Frac(masD2_frac, D2Frac);
	//D10_in_D8_frac(masD2_frac, D2_in_D10_Frac(masD2_frac, D2Frac));

	string result = D10_in_D8(masD2, D2_in_D10(masD2, D2)) + "." + (D10_in_D8_frac(masD2_frac, D2_in_D10_Frac(masD2_frac, D2Frac)));
	cout << endl;
	cout << result;
	
	
	
	delete[] masD2;
	delete[] masD2_frac;


}



