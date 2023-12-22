// proyecto-main.cc
// main con el menu y todas las opciones que se le brinda al usuario
// en el caso de nuestro proyecto, el menu sera un programa sencillo hecho en c++ que se ejecuta en la terminal

#include "proyecto.h"

    int main(){

        int opcion ;
        int usuario = 5 ;
        int actividad ;
        int id ;
        string user ;
        string password ;
        string mensaje ;

            do {

                cout << "Menú:" << endl;
                cout << "1. Iniciar sesion" << endl;
                cout << "2. Visualizar actividades" << endl;
                cout << "0. Salir" << endl;

                cout << "\nIngrese su elección: ";
                cin >> opcion;

            switch (opcion) {
                    
                case 1: 

                    cout << "\nIntroduzca usuario: " ;
                    cin >> user ;
                    cout << "Introduzca contraseña: " ;
                    cin >> password ;

                        usuario = Login( user , password ) ;

                            switch (usuario) {
                                case 3:
                                cout << "Las credenciales se encontraron en el archivo 'Organizador.txt'." << endl;
                                break;
                                case 2:
                                cout << "Las credenciales se encontraron en el archivo 'Director Academico.txt'." << endl;
                                break;
                                case 1:
                                cout << "Las credenciales se encontraron en el archivo 'Usuarios.txt'." << endl;
                                break;
                                case 0:
                                cout << "Las credenciales no se encontraron en ninguno de los archivos." << endl;
                                break;
                                case -1:
                                cout << "No se pudo crear el archivo 'Organizador.txt'." << endl;
                                break;
                                default:
                                cout << "Error desconocido." << endl;
                                break;
                            } 

                    opcion = 0 ;

                break;
                case 2:

                    Visualizar_act() ;

                break;
                default:
                cout << "Opcion no valida" << endl;
                break;
                } 

            } while (opcion != 0);

            if( usuario == 1 ){

                do {

                cout << "Menú:" << endl;
                cout << "1. Inscribirse en una actividad" << endl;
                cout << "2. Cancelar inscripcion" << endl;
                cout << "3. Ver asistencia a las actividades" << endl;
                cout << "4. Visualizar actividades" << endl;
                cout << "0. Salir" << endl;

                cout << "\nIngrese su elección: ";
                cin >> opcion;

                switch (opcion) {
                    
                    case 1: 

                    cout << "Ingrese el número: ";
                    cin >> actividad;
                    cin.ignore(); // Limpiar el buffer del teclado

                    cout << "Ingrese el nombre de usuario: ";
                    getline(cin, user);

                    Inscripcion( actividad , user ) ;

                    break;
                    case 2: 

                    cout << "Ingrese el número a eliminar: ";
                    cin >> actividad;
                    cin.ignore(); // Limpiar el buffer del teclado

                    cout << "Ingrese el nombre de usuario: ";
                    getline(cin, user);

                    Cancelacion( actividad , user ) ;

                    break;
                    case 3: 

                    Ver_asistencia() ;

                    break;
                    case 4:

                    Visualizar_act() ;

                    break;
                    default:
                    cout << "Opcion no valida" << endl;
                    break;
                    } 

                } while (opcion != 0 );

            }

            if( usuario == 2 ){

                do {

                cout << "Menú:" << endl;
                cout << "1. Eliminar usuario registrado" << endl;
                cout << "2. Crear actividad academica" << endl;
                cout << "3. Eliminar actividad academica" << endl;
                cout << "4. Visualizar actividades" << endl;
                cout << "0. Salir" << endl;

                cout << "\nIngrese su elección: ";
                cin >> opcion;

                switch (opcion) {
                    
                    case 1: 

                        cout << "Ingrese el nombre de usuario a eliminar: ";
                        getline(cin, user);

                        Eliminar_usuario_registrado( user ) ;

                    break;
                    case 2: 

                        Crear_actividad() ;

                    break;
                    case 3: 

                        cout << "Ingrese el número de la actividad a eliminar: ";
                        cin >> actividad;

                        Eliminar_act( actividad ) ;

                    break;
                    case 4:

                        Visualizar_act() ;

                    break;
                    default:
                    cout << "Opcion no valida" << endl;
                    break;
                    } 

                } while (opcion != 0 );

            }    

            if( usuario == 3 ){

                do {

                cout << "Menú:" << endl;
                cout << "1. Eliminar usuario registrado" << endl;
                cout << "2. Crear usuario registrado" << endl;
                cout << "3. Crear actividad academica" << endl;
                cout << "4. Eliminar actividad academica" << endl;
                cout << "5. Visualizar actividades" << endl;
                cout << "6. Designar director academico" <<endl ;
                cout << "0. Salir" << endl;

                cout << "\nIngrese su elección: ";
                cin >> opcion;

                switch (opcion) {
                    
                    case 1: 

                        cout << "Ingrese el nombre de usuario a eliminar: ";
                        getline(cin, user);

                        Eliminar_usuario_registrado( user ) ;

                    break;
                    case 2: 

                        cout << "\nInserte el usuario que quiere crear: " ;
                        cin >> user ;
                        cout << "\nInserte su contraseña: " ;
                        cin >> password ;

                        Crear_usuario( user, password ) ;

                    break;
                    case 3: 

                        Crear_actividad() ;

                    break;
                    case 4: 

                        cout << "Ingrese el número de la actividad a eliminar: ";
                        cin >> actividad;

                        Eliminar_act( actividad ) ;

                    break;
                    case 5:

                        Visualizar_act() ;

                    break;
                    case 6: 

                        cout << "\nInserte el usuario de el director academico: " ;
                        cin >> user ;
                        cout << "\nInserte la contrasena de el director academico: " ;
                        cin >> password ;

                        Designar_director_academico( user , password ) ;

                    break;
                    
                    default:
                    cout << "Opcion no valida" << endl;
                    break;
                    } 

                } while (opcion != 0 );

            }

        cout << "\nFin de la ejecucion " <<endl ;            

    return 0 ;

}
