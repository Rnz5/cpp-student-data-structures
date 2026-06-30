#include <iostream>
#include <vector>
#include "include/Student.h"

using namespace std;

int main() {
    // genera los 300 punteros de estudiantes del csv
    vector<Student*> students = generateStudents("students.csv");

    //mostrar estudiantes
    if (!students.empty()) {
        cout << "Estudiantes:" << endl;
        
        for (int i = 0; i < students.size(); i++) {
            cout << i + 1 << ") "
                 << "Codigo: " << students[i]->code << " "
                 << "Nombre: " << students[i]->name << " " << students[i]->last_name << " "
                 << "PPA: " << students[i]->ppa << endl;
        }
    } else {
        cout << ":("<< endl;
    }

    // recorrer el vector para destruir uno a uno los objetos
    for (int i = 0; i < students.size(); i++) {
        delete students[i]; // espacio físico de memoria de alumno se borra
    }
    //vaciar contenedor por completo
    students.clear();

    return 0;
}