#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "UcoActividades.h"

using ::testing::StartsWith;

// Función para eliminar archivos temporales después de cada prueba
class ArchivoTemporal {
public:
    ArchivoTemporal(const std::string& nombreArchivo) : nombreArchivo_(nombreArchivo) {}

    ~ArchivoTemporal() {
        std::remove(nombreArchivo_.c_str());
    }

private:
    std::string nombreArchivo_;
};
// Clase de prueba para redirigir la entrada estándar durante las pruebas de la función Crear_Actividad
class EntradaEstandarRedirigida {
public:
    EntradaEstandarRedirigida(const std::string& input) : antiguaEntrada_(std::cin.rdbuf()) {
        std::cin.rdbuf(inputBuffer_.rdbuf());
        inputBuffer_.str(input);
        inputBuffer_.seekg(0);
    }

    ~EntradaEstandarRedirigida() {
        std::cin.rdbuf(antiguaEntrada_);
    }

private:
    std::istringstream inputBuffer_;
    std::streambuf* antiguaEntrada_;
};

TEST(LoginTest, UsuarioEnOrganizador) {
    // Configuración del entorno de prueba
    std::ofstream archivoOrganizador("Organizador.txt");
    archivoOrganizador << "usuario_existente" << std::endl;
    archivoOrganizador << "contrasena_existente" << std::endl;
    archivoOrganizador.close();

    // Ejecutar la función de prueba
    EXPECT_EQ(Login("usuario_existente", "contrasena_existente"), 3);
}

TEST(LoginTest, UsuarioEnDirectorAcademico) {
    // Configuración del entorno de prueba
    std::ofstream archivoDirector("Director Academico.txt");
    archivoDirector << "usuario_director" << " contrasena_director" << std::endl;
    archivoDirector.close();

    // Ejecutar la función de prueba
    EXPECT_EQ(Login("usuario_director", "contrasena_director"), 2);
}

TEST(LoginTest, UsuarioEnUsuarios) {
    // Configuración del entorno de prueba
    std::ofstream archivoUsuarios("Usuarios.txt");
    archivoUsuarios << "usuario_comun" << " contrasena_comun" << std::endl;
    archivoUsuarios.close();

    // Ejecutar la función de prueba
    EXPECT_EQ(Login("usuario_comun", "contrasena_comun"), 1);
}

TEST(LoginTest, UsuarioNoEncontrado) {
    // Configuración del entorno de prueba
    std::ofstream archivoOrganizador("Organizador.txt");
    archivoOrganizador.close();  // Archivo Organizador vacío

    std::ofstream archivoDirector("Director Academico.txt");
    archivoDirector.close();  // Archivo Director Academico vacío

    std::ofstream archivoUsuarios("Usuarios.txt");
    archivoUsuarios.close();  // Archivo Usuarios vacío

    // Ejecutar la función de prueba
    EXPECT_EQ(Login("usuario_inexistente", "contrasena_inexistente"), 0);
}


// Casos de prueba para la función Visualizar_act
TEST(VisualizarActTest, ArchivoExiste) {
    // Configuración del entorno de prueba
    std::ofstream archivo("Actividades Academicas.txt");
    archivo << "Actividad 1" << std::endl;
    archivo << "Actividad 2" << std::endl;
    archivo.close();

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Visualizar_act();

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();
    
    // Verificar el resultado esperado
    EXPECT_EQ(output, "Actividad 1\nActividad 2\n");
}


TEST(VisualizarActTest, ArchivoVacio) {
    // Configuración del entorno de prueba
    std::ofstream archivo("Actividades Academicas.txt");
    archivo.close();  // Archivo vacío

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Visualizar_act();

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar el resultado esperado
    EXPECT_EQ(output, "");
}

TEST(InscripcionTest, NumeroRepetido) {
    // Configuración del entorno de prueba
    std::ofstream archivoEntrada("Asistencia.txt");
    archivoEntrada << "usuario1 1 2 3 " << std::endl;
    archivoEntrada << "usuario2 2 3 4 " << std::endl;
    archivoEntrada.close();

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Inscripcion(2, "usuario1");

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar el resultado esperado
    EXPECT_EQ(output, "Asistencia agregada exitosamente.\n");

    // Verificar que el número repetido no se haya agregado
    std::ifstream archivoResultante("Asistencia.txt");
    std::string linea;
    std::getline(archivoResultante, linea); // Leer la primera línea
    EXPECT_EQ(linea, "usuario1 1 2 3 ");
}


// Casos de prueba para la función Cancelacion
TEST(CancelacionTest, EliminarNumeroExitoso) {
    // Configuración del entorno de prueba
    std::ofstream archivoEntrada("Asistencia.txt");
    archivoEntrada << "usuario1 1 2 3 " << std::endl;
    archivoEntrada << "usuario2 2 3 4 " << std::endl;
    archivoEntrada.close();

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Cancelacion(2, "usuario1");

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar el resultado esperado
    EXPECT_EQ(output, "Número eliminado exitosamente.\n");

    // Verificar el contenido del archivo resultante
    std::ifstream archivoResultante("Asistencia.txt");
    std::string linea;
    std::getline(archivoResultante, linea); // Leer la primera línea
    EXPECT_EQ(linea, "usuario1 1 3 ");
}


// Casos de prueba para la función Ver_asistencia
TEST(VerAsistenciaTest, ArchivoExiste) {
    // Configuración del entorno de prueba
    std::ofstream archivoEntrada("Asistencia.txt");
    archivoEntrada << "usuario1 1 2 3 " << std::endl;
    archivoEntrada << "usuario2 2 3 4 " << std::endl;
    archivoEntrada.close();

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Ver_asistencia();

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar el resultado esperado
    EXPECT_EQ(output, "usuario1 1 2 3 \nusuario2 2 3 4 \n");
}


// Ejemplo de caso de prueba utilizando un archivo temporal
TEST(VerAsistenciaTest, ErrorAlAbrirArchivo) {
    // Configuración del entorno de prueba
    ArchivoTemporal archivoTemp("Asistencia.txt");  // Archivo temporal que se eliminará automáticamente

    // Simular error al abrir el archivo
    std::remove("Asistencia.txt");

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Ver_asistencia();

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar el resultado esperado
    EXPECT_EQ(output, "El archivo 'Asistencia.txt' no existe.\n");
}

TEST(EliminarUsuarioTest, UsuarioInexistente) {
    // Configuración del entorno de prueba
    std::ofstream archivoEntrada("Usuarios.txt");
    archivoEntrada << "usuario1 contraseña1" << std::endl;
    archivoEntrada << "usuario2 contraseña2" << std::endl;
    archivoEntrada.close();

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Eliminar_usuario_registrado("usuario3");

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar el resultado esperado
    EXPECT_EQ(output, "El usuario no fue encontrado en el archivo.\n");

    // Verificar que el archivo no haya sido modificado
    std::ifstream archivoResultante("Usuarios.txt");
    std::string contenidoOriginal;
    std::getline(archivoResultante, contenidoOriginal); // Leer la primera línea
    EXPECT_EQ(contenidoOriginal, "usuario1 contraseña1");
}


// Caso de prueba para la función Eliminar_act cuando la actividad no se encuentra
TEST(EliminarActTest, ActividadNoEncontrada) {
    // Configuración del entorno de prueba
    ArchivoTemporal archivoTemp("Actividades Academicas.txt");  // Archivo temporal que se eliminará automáticamente

    // Crear un archivo de ejemplo sin la actividad a eliminar
    std::ofstream archivoEjemplo("Actividades Academicas.txt");
    archivoEjemplo << "Número de actividad: 2" << std::endl;
    archivoEjemplo.close();

    // Redirigir la salida estándar para capturarla
    testing::internal::CaptureStdout();

    // Ejecutar la función de prueba
    Eliminar_act(1);

    // Restaurar la salida estándar
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar el resultado esperado
    EXPECT_EQ(output, "La actividad no fue encontrada.\n");

    // Verificar que el archivo no ha sido modificado
    std::ifstream archivoResultante("Actividades Academicas.txt");
    std::vector<std::string> lineas;
    std::string linea;
    while (std::getline(archivoResultante, linea)) {
        lineas.push_back(linea);
    }
    EXPECT_EQ(lineas.size(), 1);  // Debería haber una sola línea
    EXPECT_EQ(lineas[0], "Número de actividad: 2");
}


int main(int argc, char** argv) { // Ejecutar todas los TEST
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
