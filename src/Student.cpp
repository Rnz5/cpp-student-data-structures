#include "../include/Student.h"
#include <fstream> // abrir y leer csv
#include <sstream> // separar por comas
#include <cstdlib> // aleatoriedad

using namespace std;
const int seed = 23;

// Se usa puntero tambien porque asi el avl, la tabla hash y los heaps apunten a la misma memoria sin duplicar datos
vector<Student*> generateStudents(string routeCsv){
    vector<Student*> studentList;
    vector<string> firstNames;
    vector<string> lastNames;

    // Verificar que la ruta del csv es correcta, sino, devuelve un vector vacio
    ifstream csv(routeCsv);
    if(!csv.is_open()){
        return studentList;
    }

    // ignorar primera linea del csv, cabecera
    string line;
    getline(csv, line); //leer lineas hasta un enter

    //leer el csb linea por linea
    while (getline(csv, line)) {
        
        stringstream ss(line);
        string name, last_name;
        
        // extrae el nombre hasta la coma y el resto de la linea lo asigna al apellido
        if (getline(ss, name, ',') && getline(ss, last_name)) {
            firstNames.push_back(name);
            lastNames.push_back(last_name);
        }
    }
    csv.close(); // cerrar csv

    // semilla declarada arriba para la aleatoriedad
    srand(seed); //se necesita para usar rand()
    string careers[] = {"CS", "SI", "CE", "TI"}; // las carreras del enunciado
    int sequentialId = 1000;                     // el numero que empieza en 1000

    // bucle para crear los 300 estudiantes usando punteros
    for (int i=0;i<300;i++) {
        Student* newStudent = new Student(); // reserva espacio en el heap

        // elegir una carrera al azar
        string randomCareer = careers[rand() % 4];
        newStudent->code = randomCareer + to_string(sequentialId); //lo vuelve string
        sequentialId++; // +1 para el siguiente estudiante

        // asigna nombres aleatorios del csv
        newStudent->name = firstNames[rand() % firstNames.size()];
        newStudent->last_name = lastNames[rand() % lastNames.size()];

        // genera el ppa entre 1 y 20 con decimales
        newStudent->ppa = 1.0 + (rand() % 1901) / 100.0;

        // guarda al estudiante ya "procesado"
        studentList.push_back(newStudent);
    }

    return studentList;
}