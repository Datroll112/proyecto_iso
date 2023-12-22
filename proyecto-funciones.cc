#include "proyecto.h"


int Login( string usuario , string contrasena ){

    ifstream archivoOrganizador("Organizador.txt");
    ifstream archivoDirector("Director Academico.txt");
    ifstream archivoUsuarios("Usuarios.txt");

    if (!archivoOrganizador.is_open()) {
        ofstream nuevoOrganizador("Organizador.txt");
        if (nuevoOrganizador.is_open()) {
            nuevoOrganizador << usuario << endl; // Escribir el usuario en la primera línea
            nuevoOrganizador << contrasena << endl; // Escribir la contraseña en la segunda línea
            nuevoOrganizador.close();
            return 3; // Usuario y contraseña creados en Organizador
        } else {
            return -1; // No se pudo crear el archivo Organizador
        }
    }

    string user, pass;
    bool encontrado = false;

    // Buscar en el archivo Organizador
    while (getline(archivoOrganizador, user) && getline(archivoOrganizador, pass)) {
        if (user == usuario && pass == contrasena) {
            encontrado = true;
            break;
        }
    }

    archivoOrganizador.close();

    if (encontrado) {
        return 3; // Usuario y contraseña encontrados en Organizador
    }

    // Buscar en el archivo Director Academico
    while (archivoDirector >> user >> pass) {
        if (user == usuario && pass == contrasena) {
            return 2; // Usuario y contraseña encontrados en Director Academico
        }
    }

    archivoDirector.close();

    // Buscar en el archivo Usuarios
    while (archivoUsuarios >> user >> pass) {
        if (user == usuario && pass == contrasena) {
            return 1; // Usuario y contraseña encontrados en Usuarios
        }
    }

    archivoUsuarios.close();

    return 0; // Usuario y contraseña no encontrados en ninguno de los archivos
}

void Visualizar_act(){

    ifstream archivo("Actividades Academicas.txt");

    if (!archivo.is_open()) {
        cout << "El archivo 'Actividades Academicas.txt' no existe." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();

}

void Inscripcion( int numero , string usuario ) {

    ifstream archivoEntrada("Asistencia.txt");
    ofstream archivoSalida("Asistencia_temp.txt");

    if (archivoEntrada.is_open()) {
        vector<string> datos;
        string linea;
        bool usuarioEncontrado = false;

        while (getline(archivoEntrada, linea)) {
            istringstream ss(linea);
            string palabra;
            ss >> palabra;
            
            if (palabra == usuario) {
                usuarioEncontrado = true;

                // Buscar si ya existe el número para ese usuario
                string asistencias = "";
                while (ss >> palabra) {
                    asistencias += palabra + " ";
                }

                istringstream iss(asistencias);
                int existente;
                bool numeroEncontrado = false;

                while (iss >> existente) {
                    if (existente == numero) {
                        numeroEncontrado = true;
                        break;
                    }
                }

                if (!numeroEncontrado) {
                    asistencias += to_string(numero) + " ";
                    linea = usuario + " " + asistencias;
                }
            }
            datos.push_back(linea);
        }

        archivoEntrada.close();

        if (!usuarioEncontrado) {
            datos.push_back(usuario + " " + to_string(numero) + " ");
        }

        for (const auto &dato : datos) {
            archivoSalida << dato << endl;
        }
    } else {
        archivoSalida << usuario + " " + to_string(numero) + " " << endl;
    }

    archivoSalida.close();

    if (remove("Asistencia.txt") != 0) {
        cout << "Error al eliminar el archivo existente." << endl;
    }
    if (rename("Asistencia_temp.txt", "Asistencia.txt") != 0) {
        cout << "Error al renombrar el archivo temporal." << endl;
    }

    cout << "Asistencia agregada exitosamente." << endl;

}

void Cancelacion( int numero , string usuario ){

    ifstream archivoEntrada("Asistencia.txt");
    ofstream archivoSalida("Asistencia_temp.txt");

    if (!archivoEntrada.is_open()) {
        cout << "El archivo 'Asistencia.txt' no existe." << endl;
        return;
    }

    vector<string> datos;
    string linea;
    bool usuarioEncontrado = false;

    while (getline(archivoEntrada, linea)) {
        istringstream ss(linea);
        string palabra;
        ss >> palabra;

        if (palabra == usuario) {
            usuarioEncontrado = true;

            // Buscar si existe el número para ese usuario
            string asistencias = "";
            while (ss >> palabra) {
                if (stoi(palabra) != numero) {
                    asistencias += palabra + " ";
                }
            }

            if (!asistencias.empty()) {
                datos.push_back(usuario + " " + asistencias);
            }
        } else {
            datos.push_back(linea);
        }
    }

    archivoEntrada.close();

    archivoSalida.close();

    if (!usuarioEncontrado) {
        cout << "El usuario no fue encontrado en el archivo." << endl;
        remove("Asistencia_temp.txt");
        return;
    }

    ofstream archivoNuevo("Asistencia.txt");

    for (const auto &dato : datos) {
        archivoNuevo << dato << endl;
    }

    archivoNuevo.close();
    cout << "Número eliminado exitosamente." << endl;

}

void Ver_asistencia(){

    ifstream archivo("Asistencia.txt");

    if (!archivo.is_open()) {
        cout << "El archivo 'Asistencia.txt' no existe." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();

}

void Eliminar_usuario_registrado( string usuario ){

    ifstream archivoEntrada("Usuarios.txt");
    ofstream archivoSalida("Usuarios_temp.txt");

    if (!archivoEntrada.is_open()) {
        cout << "El archivo 'Usuarios.txt' no existe." << endl;
        return;
    }

    vector<string> datos;
    string linea;
    bool usuarioEncontrado = false;

    while (getline(archivoEntrada, linea)) {
        istringstream ss(linea);
        string palabra;
        ss >> palabra;

        if (palabra == usuario) {
            usuarioEncontrado = true;
            getline(archivoEntrada, linea); // Saltar la línea de la contraseña
        } else {
            datos.push_back(linea);
        }
    }

    archivoEntrada.close();

    if (!usuarioEncontrado) {
        cout << "El usuario no fue encontrado en el archivo." << endl;
        remove("Usuarios_temp.txt");
        return;
    }

    ofstream archivoNuevo("Usuarios.txt");

    for (const auto &dato : datos) {
        archivoNuevo << dato << endl;
    }

    archivoNuevo.close();
    cout << "Usuario eliminado exitosamente." << endl;

}

void Crear_actividad(){

    int numero_act;
    string tematica, ubicacion, fecha, aforo, asistentes, material_necesario;
    int duracion;
    float precio;

    cout << "Ingrese el número de actividad: ";
    cin >> numero_act;
    cin.ignore(); // Limpiar el buffer del teclado

    cout << "Ingrese la temática: ";
    getline(cin, tematica);

    cout << "Ingrese la ubicación: ";
    getline(cin, ubicacion);

    cout << "Ingrese la fecha: ";
    getline(cin, fecha);

    cout << "Ingrese el aforo: ";
    getline(cin, aforo);

    cout << "Ingrese el número de asistentes: ";
    getline(cin, asistentes);

    cout << "Ingrese la duración en horas: ";
    cin >> duracion;
    cin.ignore(); // Limpiar el buffer del teclado

    cout << "Ingrese el precio: ";
    cin >> precio;
    cin.ignore(); // Limpiar el buffer del teclado

    cout << "Ingrese el material necesario: ";
    getline(cin, material_necesario);

    ofstream archivoActividades("Actividades Academicas.txt", ios::app); // Abrir en modo de adjuntar

    if (archivoActividades.is_open()) {
        archivoActividades << "Número de actividad: " << numero_act << endl;
        archivoActividades << "Temática: " << tematica << endl;
        archivoActividades << "Ubicación: " << ubicacion << endl;
        archivoActividades << "Fecha: " << fecha << endl;
        archivoActividades << "Aforo: " << aforo << endl;
        archivoActividades << "Asistentes: " << asistentes << endl;
        archivoActividades << "Duración: " << duracion << " horas" << endl;
        archivoActividades << "Precio: " << precio << " euros" << endl;
        archivoActividades << "Material necesario: " << material_necesario << endl;
        archivoActividades << "----------------------------------------" << endl;

        archivoActividades.close();

        cout << "La actividad se ha agregado al archivo 'Actividades Academicas.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo 'Actividades Academicas.txt'." << endl;
    }
}

void Eliminar_act( int actividad ){

    ifstream archivoEntrada("Actividades Academicas.txt");
    ofstream archivoTemporal("temp.txt");

    if (!archivoEntrada.is_open() || !archivoTemporal.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    vector<string> datos;
    bool encontrado = false;

    while (getline(archivoEntrada, linea)) {
        if (linea.find("Número de actividad: " + to_string(actividad)) != string::npos) {
            encontrado = true;
            for (int i = 0; i < 9; ++i) {
                getline(archivoEntrada, linea); // Saltar las siguientes 9 líneas
            }
        } else {
            datos.push_back(linea);
        }
    }

    archivoEntrada.close();

    if (!encontrado) {
        cout << "La actividad no fue encontrada." << endl;
        archivoTemporal.close();
        remove("temp.txt"); // Eliminar el archivo temporal
        return;
    }

    for (const auto &dato : datos) {
        archivoTemporal << dato << endl;
    }

    archivoTemporal.close();

    remove("Actividades Academicas.txt"); // Eliminar el archivo original
    rename("temp.txt", "Actividades Academicas.txt"); // Renombrar el archivo temporal
    cout << "La actividad ha sido eliminada correctamente." << endl;

}

void Crear_usuario( string usuario , string contrasena){

    ofstream archivoUsuarios("Usuarios.txt", ios::app); // Abrir en modo de adjuntar

    if (archivoUsuarios.is_open()) {
        archivoUsuarios << usuario << endl; // Escribir el usuario en la primera línea
        archivoUsuarios << contrasena << endl; // Escribir la contraseña en la segunda línea
        archivoUsuarios.close();

        cout << "Las credenciales han sido agregadas al archivo 'Usuarios.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo 'Usuarios.txt'." << endl;
    }
}

void Designar_director_academico( string usuario, string contrasena ){

    ofstream archivoDirector("Director Academico.txt");

    if (archivoDirector.is_open()) {
        archivoDirector << usuario << endl; // Escribir el usuario en la primera línea
        archivoDirector << contrasena << endl; // Escribir la contraseña en la segunda línea
        archivoDirector.close();

        cout << "El archivo 'Director Academico.txt' ha sido creado o sustituido con las nuevas credenciales." << endl;
    } else {
        cout << "No se pudo crear el archivo 'Director Academico.txt'." << endl;
    }
}

void Crear_mail( int id , string mensaje ){

    ofstream archivo("Mails.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "Error al abrir o crear el archivo 'Mails.txt'." << endl;
        return;
    }

    archivo << id << endl; // Escribir el ID en la primera línea
    archivo << mensaje << endl; // Escribir el mensaje en la segunda línea
    archivo << "----------------------------------------" << endl; // Separador entre mensajes

    archivo.close();

    ifstream leerArchivo("Mails.txt");

    if (!leerArchivo.is_open()) {
        cout << "Error al abrir el archivo 'Mails.txt'." << endl;
        return;
    }

    string linea;
    while (getline(leerArchivo, linea)) {
        cout << linea << endl;
    }

    leerArchivo.close();

}
    