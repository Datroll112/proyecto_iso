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
        Usuario aux ;
        string mensaje ;
        Actividad_academica aux2 ;
        Usuario_regristrado aux3 ;
        Director_academico aux4 ;
        Mailing aux5 ;
     
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

                    if( aux.Login( user , password ) == 0 ){

                        cout << "\nERROR al iniciar sesion" <<endl ;

                    }else{

                        usuario = aux.Login( user , password ) ;

                    }

                break;
                case 2:

                    aux2.Visualizar_act() ;

                    cout <<"\nSe ha creado un fichero con todas las actividades academicas " << endl ;

                break;
                default:
                cout << "Opcion no valida" << endl;
                break;
                } 

            } while (opcion != 0 || usuario != 5 );

            if( usuario = 1 ){

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

                    cout << "Introduzca el numero de la actividad en la que se quiere inscribir: " ;
                    cin >> actividad ;

                    aux3.Inscripcion( actividad , user ) ;

                    break;
                    case 2: 

                    cout << "Introduzca el numero de la actividad para cancelar su asistencia: " ;
                    cin >> actividad ;

                    aux3.Cancelacion( actividad , user ) ;

                    break;
                    case 3: 

                    aux3.Ver_asistencia() ;

                    break;
                    case 4:

                    aux2.Visualizar_act() ;

                    cout <<"\nSe ha creado un fichero con todas las actividades academicas " << endl ;

                    break;
                    default:
                    cout << "Opcion no valida" << endl;
                    break;
                    } 

                } while (opcion != 0 );

            }

            if( usuario = 2 ){

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

                        cout << "\nInserte el usuario que quiere eliminar: " ;
                        cin >> user ;

                        aux4.Eliminar_usuario_registrado( user ) ;

                    break;
                    case 2: 

                        aux4.Crear_actividad() ;

                    break;
                    case 3: 

                        cout << "\nInserte el numero de la actividad que quiere eliminar: " ;
                        cin >> actividad ;

                        if( aux4.Eliminar_act( actividad ) == true ){

                            cout << "\nActividad eliminada con exito" << endl ;

                        }else{

                            cout << "\nERROR al eliminar" <<endl ;

                        }

                    break;
                    case 4:

                    aux2.Visualizar_act() ;

                    cout <<"\nSe ha creado un fichero con todas las actividades academicas " << endl ;

                    break;
                    default:
                    cout << "Opcion no valida" << endl;
                    break;
                    } 

                } while (opcion != 0 );

            }    

            if( usuario = 2 ){

                do {

                cout << "Menú:" << endl;
                cout << "1. Eliminar usuario registrado" << endl;
                cout << "2. Crear actividad academica" << endl;
                cout << "3. Eliminar actividad academica" << endl;
                cout << "4. Visualizar actividades" << endl;
                cout << "5. Designar director academico" <<endl ;
                cout << "6. Crear mail" <<endl ;
                cout << "0. Salir" << endl;

                cout << "\nIngrese su elección: ";
                cin >> opcion;

                switch (opcion) {
                    
                    case 1: 

                        cout << "\nInserte el usuario que quiere eliminar: " ;
                        cin >> user ;

                        aux4.Eliminar_usuario_registrado( user ) ;

                    break;
                    case 2: 

                        aux4.Crear_actividad() ;

                    break;
                    case 3: 

                        cout << "\nInserte el numero de la actividad que quiere eliminar: " ;
                        cin >> actividad ;

                        if( aux4.Eliminar_act( actividad ) == true ){

                            cout << "\nActividad eliminada con exito" << endl ;

                        }else{

                            cout << "\nERROR al eliminar" <<endl ;

                        }

                    break;
                    case 4:

                    aux2.Visualizar_act() ;

                    cout <<"\nSe ha creado un fichero con todas las actividades academicas " << endl ;

                    break;
                    case 5: 

                        cout << "\nInserte el usuario de el director academico: " ;
                        cin >> user ;
                        cout << "\nInserte la contrasena de el director academico: " ;
                        cin >> password ;

                        aux4.Designar_director_academico( user , password ) ;

                    break;
                    case 6: 

                        cout << "\nInserte el id del mail: " ;
                        cin >> id ;
                        cout << "\nInserte el mensaje del mail a crear: " ;
                        cin >> mensaje ;

                        aux5.Crear_mail( id , mensaje ) ;

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