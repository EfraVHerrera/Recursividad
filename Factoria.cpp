#include <iostream>
using namespace std;

// FUNCION PARA CALCULAR EL FACTORIAL USANDO UN BUCLE FOR
int factorialNormal(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact = i * fact;
	return fact;
}

// FUNCION RECURSIVA PARA CALCULAR EL FACTORIAL
int factorial(int n){
	if (n == 0)
		return 1;
	else
		return factorial(n-1) * n;
}
	
	int main(int argc, char * argv[]) {
		const int NUM = 5;
		// IMPRIMIR EL FACTORIAL DE NUM UTILIZANDO LA FUNCION RECURSIVA
		cout << "Factorial: " << factorial(NUM) << endl;
		return 0;
	}
	
