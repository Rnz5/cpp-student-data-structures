#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

// Estructura del estudiante
struct Student {
    string code;                // carrera + numero
    string last_name;           // csv
    string name;                // csv
    double ppa;                 // ppa
};

// Funcion para generar estudiantes, puntero para evitar la copia innecesaria de volumenes altos de datos
vector<Student*> generateStudents(string routeCsv);

#endif