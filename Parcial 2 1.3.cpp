#include<iostream>
using namespace std;

const char* Nombre_archivo = "estudiantes.dat";

struct Estudiante {
    int ID;
    char nombre[10];
    char apellido[10];
    int nota1, nota2, nota3, nota4;
    int promedio;
};

void Leer() {
    FILE* archivo = fopen(Nombre_archivo, "rb");
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Estudiante estudiante;
    int id = 0;
    cout << "______________________________________" << endl;
    cout << "ID" << "|" << "Nombre" << "|" << "Apellido" << "|" << "N1" << "|" << "N2" << "|" << "N3" << "|" << "N4" << "|" << "Prom" << endl;
    while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
        cout << id << "   |  " << estudiante.nombre << "   |   " << estudiante.apellido << "   |   " << estudiante.nota1 << "    |    " << estudiante.nota2 << "    |    " << estudiante.nota3 << "    |    " << estudiante.nota4 << "    |    " << estudiante.promedio << endl;
        id += 1;
    }
    fclose(archivo);
}

void Crear() {
    FILE* archivo = fopen(Nombre_archivo, "a+b");
    char res;
    Estudiante estudiante;
    do {
        fflush(stdin);

        cout << "Ingrese ID: ";
        cin >> estudiante.ID;
        cin.ignore();

        cout << "Ingrese los nombres: ";
        cin.getline(estudiante.nombre, 10);

        cout << "Ingrese los apellidos: ";
        cin.getline(estudiante.apellido, 10);

        cout << "Ingrese nota 1: ";
        cin >> estudiante.nota1;

        cout << "Ingrese nota 2: ";
        cin >> estudiante.nota2;

        cout << "Ingrese nota 3: ";
        cin >> estudiante.nota3;

        cout << "Ingrese nota 4: ";
        cin >> estudiante.nota4;

        estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3 + estudiante.nota4) / 4;

        fwrite(&estudiante, sizeof(Estudiante), 1, archivo);

        cout << "Desea ingresar otro estudiante (S/N): ";
        cin >> res;
        system("cls");
    } while (res == 's' || res == 'S');
    fclose(archivo);
    Leer();
}

void Actualizar() {
    FILE* archivo = fopen(Nombre_archivo, "r+b");
    Estudiante estudiante;
    int id;
    cout << "Ingrese el ID que desea actualizar: ";
    cin >> id;
    fseek(archivo, id * sizeof(Estudiante), SEEK_SET);

    fflush(stdin);

    cout << "Ingrese ID: ";
    cin >> estudiante.ID;
    cin.ignore();

    cout << "Ingrese los nombres: ";
    cin.getline(estudiante.nombre, 10);

    cout << "Ingrese los apellidos: ";
    cin.getline(estudiante.apellido, 10);

    cout << "Ingrese nota 1: ";
    cin >> estudiante.nota1;

    cout << "Ingrese nota 2: ";
    cin >> estudiante.nota2;

    cout << "Ingrese nota 3: ";
    cin >> estudiante.nota3;

    cout << "Ingrese nota 4: ";
    cin >> estudiante.nota4;

    estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3 + estudiante.nota4) / 4;

    fwrite(&estudiante, sizeof(Estudiante), 1, archivo);

    fclose(archivo);
    Leer();
}

void Borrar() {
    FILE* archivo_temp = fopen("archivo_temp.dat", "w+b");
    FILE* archivo = fopen(Nombre_archivo, "rb");
    Estudiante estudiante;
    int id, id_n = 0;
    cout << "Ingrese el ID a eliminar: ";
    cin >> id;
    while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
        if (id_n != id) {
            fwrite(&estudiante, sizeof(Estudiante), 1, archivo_temp);
        }
        id_n++;
    }
    fclose(archivo);
    fclose(archivo_temp);

    archivo_temp = fopen("archivo_temp.dat", "rb");
    archivo = fopen(Nombre_archivo, "w+b");

    while (fread(&estudiante, sizeof(Estudiante), 1, archivo_temp)) {
        fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
    }
    fclose(archivo);
    fclose(archivo_temp);
    Leer();
}

int main() {
    Crear();
    Borrar();
    Actualizar();
    system("pause");
    return 0;
}
