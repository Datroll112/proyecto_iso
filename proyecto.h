// proyecto.h
// file 

#ifndef PROYECTO_H
#define PROYECTO_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

        int Login( string usuario, string contrasena ) ; // Devuelve 0 si el usuario no existe,  1 si es un usuario registrado, 2 si es el director academico y 3 si es el organizador.
        void Designar_director_academico( string usuario, string contrasena ) ;
        void Crear_usuario( string usuario , string contrasena) ;



        void Crear_actividad() ; // almacena los datos de una actividad en los mapas y crea un fichero con unicamente la actividad creada.
        void Visualizar_act() ; // imprime por pantalla todas las actividades
        void Eliminar_act( int numero_ac ) ; 



        void Inscripcion( int numero , string usuario ) ; // añade el usuario a la lista de asistentes de una actividad
        void Cancelacion( int numero , string usuario ) ; // elimina al usuario de la lista de asistencia
        void Ver_asistencia() ; // imprime por pantalla los asistentes



       
        void Crear_mail( int id , string mensaje ) ; // crea un fichero con el id y el mensaje del mail

        void Eliminar_usuario_registrado( string usuario ) ;



#endif