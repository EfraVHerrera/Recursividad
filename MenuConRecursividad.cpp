#include <iostream>
#include <cstdlib> // Para la función rand()
#include <ctime>   // Para la función time()
using namespace std;

// FUNCION PARA IMPRIMIR EL CONTENIDO DEL ARREGLO UTILIZANDO UN BUCLE FOR
void imprimir(int *n, int cant)
{
	for (int i = 0; i < cant; i++)
		cout << i << " = " << n[i] << endl;
}

// FUNCION PARA IMPRIMIR EL CONTENIDO DEL ARREGLO DE MANERA RECURSIVA
void imprec(int *n, int cant)
{
	if (cant > 0)
	{
		imprec(n, cant - 1); // LLAMADA RECURSIVA ANTES DE IMPRIMIR EL ELEMENTO ACTUAL
		cout << cant << " = " << n[cant - 1] << endl;
	}
}

// FUNCION PARA BUSCAR UN NUMERO EN EL ARREGLO UTILIZANDO RECURSIVIDAD
bool buscarNumero(int *n, int cant, int num, int pos = 0)
{
	if (pos == cant) // SI LA POSICION ES IGUAL A LA CANTIDAD DE ELEMENTOS EN EL ARREGLO, RETORNAR FALSO
		return false;
	
	if (n[pos] == num) // SI SE ENCUENTRA EL NUMERO EN LA POSICION ACTUAL, RETORNAR VERDADERO
		return true;
	
	return buscarNumero(n, cant, num, pos + 1); // LLAMADA RECURSIVA PARA BUSCAR EN LA SIGUIENTE POSICION
}

// FUNCION PARA BUSCAR EL MAYOR NUMERO EN EL ARREGLO DE MANERA RECURSIVA
void buscarMayor(int *n, int cant, int &m)
{
	if (cant > 0)
	{
		if (n[cant - 1] > m) // SI EL ELEMENTO ACTUAL ES MAYOR QUE EL ALMACENADO EN 'm', ACTUALIZAR 'm'
			m = n[cant - 1];
		buscarMayor(n, cant - 1, m); // LLAMADA RECURSIVA PARA BUSCAR EL MAYOR EN LOS ELEMENTOS RESTANTES
	}
}

// FUNCION PARA LLENAR EL ARREGLO CON NUMEROS ALEATORIOS
void llenarAleatoriamente(int *n, int cant)
{
	// Inicializar la semilla de rand() con el tiempo actual para obtener números aleatorios diferentes cada vez
	srand(time(0));
	
	for (int i = 0; i < cant; ++i)
	{
		n[i] = rand() % 10; // Generar números aleatorios en el rango de 0 a 99
	}
}

int main(int argc, char *argv[])
{
	const int Tam = 7;
	int numeros[Tam];
	int opcion;
	int m = 0; // VARIABLE PARA ALMACENAR EL MAYOR NUMERO
	int numBuscar; // Numero a buscar
	bool encontrado; // Variable para almacenar si el numero fue encontrado o no
	
	do
	{
		cout << "MENU:" << endl;
		cout << "1. LLENAR DE NUMERO" << endl;
		cout << "2. IMPRESION" << endl;
		cout << "3. MAYOR NUMERO" << endl;
		cout << "4. BUSCAR" << endl;
		cout << "0. SALIR" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion)
		{
		case 1:
			llenarAleatoriamente(numeros, Tam);
			cout << "Arreglo llenado aleatoriamente." << endl;
			break;
		case 2:
			cout << "IMPRIMIENDO EL ARREGLO:" << endl;
			imprimir(numeros, Tam);
			break;
		case 3:
			buscarMayor(numeros, Tam, m);
			cout << "El mayor es: " << m << endl;
			break;
		case 4:
			cout << "Ingrese el numero que desea buscar: ";
			cin >> numBuscar;
			encontrado = buscarNumero(numeros, Tam, numBuscar);
			if (encontrado)
				cout << "El número " << numBuscar << " existe en el arreglo." << endl;
			else
				cout << "El número " << numBuscar << " no existe en el arreglo." << endl;
			break;
		case 0:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}
