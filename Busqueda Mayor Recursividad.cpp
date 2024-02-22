#include <iostream>
using namespace std;

void imprimir(int *n, int cant)
{
	for (int i = 0; i < cant; i++)
		cout << i << " = " << n[i] << endl;
}

void imprec(int *n, int cant)
{
	if (cant > 0)
	{
		imprec(n, cant - 1);
		cout << cant << " = " << n[cant - 1] << endl;
	}
}

void buscarMayor(int *n, int cant, int &m)
{
	if (cant > 0)
	{
		if (n[cant - 1] > m)
			m = n[cant - 1];
		buscarMayor(n, cant - 1, m);
	}
}

int main(int argc, char *argv[])
{
	const int Tam = 7;
	int m = 0; // Variable para almacenar el mayor número
	int numeros[] = {3, 5, 2, 0, 1, 7, 4};
	cout << "IMPRESION BUCLE" << endl;
	imprimir(numeros, Tam);
	cout << "IMPRESION RECURSIVA" << endl;
	imprec(numeros, Tam);
	buscarMayor(numeros, Tam, m);
	cout << "El mayor es: " << m << endl; // Se imprime la variable m, no n
	return 0;
}
