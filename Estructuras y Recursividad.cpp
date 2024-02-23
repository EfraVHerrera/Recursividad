#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definición de las estructuras
struct LIBRO {
	string title;
	string author;
	string ISBN;
	int publicationYear;
	string idioma;
	int edicion;
	int numPaginas;
};

struct USUARIO {
	int userID;
	string name;
	string lastname;
	string email;
	string fechaRegistro;
};

struct BIBLIOTECARIO {
	int employeeID;
	string name;
	string lastname;
	string email;
	string cargo;
};

const int NUM_LIBROS = 3;
const int NUM_USUARIOS = 3;
const int NUM_BIBLIOTECARIOS = 3;

// Función para generar datos aleatorios
string getRandomElement(string arr[], int size) {
	return arr[rand() % size];
}

int getRandomYear() {
	return rand() % 50 + 1970; // Años aleatorios entre 1970 y 2019
}

string generateEmail(string name, string lastname) {
	return name + "." + lastname + "@upds.net.bo";
}

string generateFechaRegistro(string listaFechasRegistro[], int size) {
	return listaFechasRegistro[rand() % size]; // Se elige una fecha de registro aleatoria del array
}

// Función para generar las estructuras y sus datos
void generarLibros(LIBRO libros[], string listaLibros[], string listaNombres[], string listaApellidos[], string listaIdiomas[]) {
	for (int i = 0; i < NUM_LIBROS; ++i) {
		libros[i].title = getRandomElement(listaLibros, NUM_LIBROS);
		libros[i].author = getRandomElement(listaNombres, 5) + " " + getRandomElement(listaApellidos, 5);
		libros[i].ISBN = to_string(i + 1) + ",2,3,4,5"; // ISBN falso
		libros[i].publicationYear = getRandomYear();
		libros[i].idioma = getRandomElement(listaIdiomas, 8); // Se elige un idioma aleatorio
		libros[i].edicion = rand() % 10 + 1; // Número de edición aleatorio entre 1 y 10
		libros[i].numPaginas = rand() % 500 + 100; // Número de páginas aleatorio entre 100 y 599
	}
}

void generarUsuarios(USUARIO usuarios[], string listaNombres[], string listaApellidos[], string listaFechasRegistro[], int size) {
	for (int i = 0; i < NUM_USUARIOS; ++i) {
		usuarios[i].userID = i + 1;
		usuarios[i].name = getRandomElement(listaNombres, 5);
		usuarios[i].lastname = getRandomElement(listaApellidos, 5);
		usuarios[i].email = generateEmail(usuarios[i].name, usuarios[i].lastname);
		usuarios[i].fechaRegistro = generateFechaRegistro(listaFechasRegistro, size); //HOY
	}
}

void generarBibliotecarios(BIBLIOTECARIO bibliotecarios[], string listaNombres[], string listaApellidos[], string listaCargos[], int size) {
	for (int i = 0; i < NUM_BIBLIOTECARIOS; ++i) {
		bibliotecarios[i].employeeID = i + 1;
		bibliotecarios[i].name = getRandomElement(listaNombres, 5);
		bibliotecarios[i].lastname = getRandomElement(listaApellidos, 5);
		bibliotecarios[i].email = generateEmail(bibliotecarios[i].name, bibliotecarios[i].lastname);
		bibliotecarios[i].cargo = getRandomElement(listaCargos, size); //HOY
	}
}

// Función para imprimir las personas (usuarios y bibliotecarios)
void imprimirPersonas(void *personas, int cant, string type) {
	if (cant > 0) {
		if (type == "usuario") {
			USUARIO *usuarios = static_cast<USUARIO*>(personas);
			imprimirPersonas(usuarios, cant - 1, type);
			cout << "ID: " << usuarios[cant - 1].userID << ", Nombre: " << usuarios[cant - 1].name << ", Apellido: " << usuarios[cant - 1].lastname << ", Email: " << usuarios[cant - 1].email << ", Fecha de Registro: " << usuarios[cant - 1].fechaRegistro << endl;
		} else if (type == "bibliotecario") {
			BIBLIOTECARIO *bibliotecarios = static_cast<BIBLIOTECARIO*>(personas);
			imprimirPersonas(bibliotecarios, cant - 1, type);
			cout << "ID: " << bibliotecarios[cant - 1].employeeID << ", Nombre: " << bibliotecarios[cant - 1].name << ", Apellido: " << bibliotecarios[cant - 1].lastname << ", Email: " << bibliotecarios[cant - 1].email << ", Cargo: " << bibliotecarios[cant - 1].cargo << endl;
		}
	}
}

int main() {
	// Semilla para números aleatorios
	srand(time(0));
	
	// Arrays fijos de datos
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Aprende C++", "Aprende Ubunto", "Clean Code", "The Art of Computer Programming", "Programming Pearls", "Introduction to Algorithms"};
	string listaNombres[] = {"Juan", "María", "Pedro", "Ana", "Luis", "Efrain", "Jose", "Carlos", "Cristian"};
	string listaApellidos[] = {"García", "Martínez", "López", "González", "Rodríguez", "Edmundo", "Flores", "Ponce", "Herrera"};
	string listaIdiomas[] = {"Español", "Inglés", "Francés", "Alemán", "Italiano", "Portugués", "Japonés", "Chino"};
	string listaFechasRegistro[] = {"01/01/2020", "15/03/2021", "30/06/2022", "26/06/2019"};
	string listaCargos[] = {"Bibliotecario jefe", "Bibliotecario Asistente", "Bibliotecario Junior", "Bibliotecario de tecnología de la información", "Bibliotecario de archivos y preservación:"};
	
	// Generar estructuras
	LIBRO libros[NUM_LIBROS];
	USUARIO usuarios[NUM_USUARIOS];
	BIBLIOTECARIO bibliotecarios[NUM_BIBLIOTECARIOS];
	
	// Generar datos aleatorios utilizando punteros
	generarLibros(libros, listaLibros, listaNombres, listaApellidos, listaIdiomas);
	generarUsuarios(usuarios, listaNombres, listaApellidos, listaFechasRegistro, sizeof(listaFechasRegistro)/sizeof(listaFechasRegistro[0]));
	generarBibliotecarios(bibliotecarios, listaNombres, listaApellidos, listaCargos, sizeof(listaCargos)/sizeof(listaCargos[0]));
	
	// Imprimir datos de usuarios y bibliotecarios utilizando función recursiva
	cout << "Usuarios:" << endl;
	imprimirPersonas(usuarios, NUM_USUARIOS, "usuario");
	cout << "\nBibliotecarios:" << endl;
	imprimirPersonas(bibliotecarios, NUM_BIBLIOTECARIOS, "bibliotecario");
	
	return 0;
}
