#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void write() {
    // Variable para el nombre del archivo
    string nombreFile = "prueba.txt";
    
    ofstream archivo(nombreFile.c_str(), ios::app); // "app" para agregar contenido
    
    if (!archivo.is_open()) {
        // El archivo no existe o no se puede abrir en modo de append, intentamos crearlo
        archivo.open(nombreFile.c_str()); // Convierte std::string a const char* para versiones anteriores a C++11

        if (!archivo.is_open()) {
            cerr << "No se pudo abrir ni crear el archivo " << nombreFile << " para escritura." << std::endl;
            return; // Salir de la funci�n sin retornar un valor
        }
    }
    
    archivo << "Hola mundo, como te llamas" << std::endl;
    archivo.close();
    
	cout << "" << std::endl;    
}



void read() {
	// variable para la lectura
    ifstream archivoLectura;
    string caracter;
    archivoLectura.open("prueba.txt", ios::in);
    
    // Falla el abrir el archivo
    if(!archivoLectura.is_open()) {
    	cout << "No se pudo abrir el archivo para lectura";
        exit(1);
	}
	
	//Obtenemos los datos de la variable t lo que tiene dentro
    while (getline(archivoLectura, caracter)) {
        cout << caracter << endl;
    }
	
	//Cerramos el archivo
    archivoLectura.close();
}


int main() {
	
	cout << "Vamos a escribir el archivo";
//	    write();
    read();
    return 0;
}

