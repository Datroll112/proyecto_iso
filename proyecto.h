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

using namespace std;

class Usuario{

    private:

        list<string> lista_usuarios_ ;
        map<string,int> lista_contrasenas_usuarios_ ;

    public:

        int Login( string usuario, string contraseña ) ; // Devuelve 0 si el usuario no existe,  1 si es un usuario registrado, 2 si es el director academico y 3 si es el organizador.
        void Designar_director_academico( string usuario, string contraseña ) ;

} ;

class Actividad_academica{

    private:

        int numero_act_ ;
        string tematica_ ;
        string ubicacion_ ;
        string fecha_ ;
        string aforo_ ;
        string asistentes_ ;
        int duracion_ ;
        float precio_ ;
        string material_necesario_ ;

    public:

        Actividad_academica( int numero_act = 0 , string tematica = "not found" , string ubicacion = "not found"  , string fecha = "not found"  , string aforo = "not found"  , string asistentes = "not found"  , int duracion = 0 , float precio = 0 , string material_necesario = "not found" ){
            numero_act_ = numero_act , tematica_ = tematica , ubicacion_ = ubicacion , fecha_ = fecha , aforo_ = aforo , asistentes_ = asistentes , duracion_ = duracion , precio_ = precio , material_necesario_ = material_necesario ;
        }
        void Crear_actividad() ; // almacena los datos de una actividad en los mapas y crea un fichero con unicamente la actividad creada.
        void Visualizar_act() ; // crea un fichero con todas las actividades. 
        bool Eliminar_act( int numero_ac ) ; // true exito, false fracaso

} ;

class Usuario_regristrado: public Usuario, public Actividad_academica{

    private:



    public:

        void Inscripcion( int actividad , string usuario ) ; // añade el usuario a la lista de asistentes de una actividad
        void Cancelacion( int actividad , string usuario ) ; // elimina al usuario de la lista de asistencia
        void Ver_asistencia() ; // imprime por pantalla los asistentes

} ;

class Director_academico: public Usuario, public Mailing, public Actividad_academica{

    private:



    public:

        bool Eliminar_usuario_registrado( string usuario ) ;

} ;

class Mailing{

    private:

        int id_mailing_ ;
        string mensaje_mailing_ ;

    public:

        Mailing( int id_mailing = 0 , string mensaje_mailing = "not found" ){ id_mailing_ = id_mailing , mensaje_mailing_ = mensaje_mailing ; }
        void Crear_mail( int id , string mensaje ) ; // crea un fichero con el id y el mensaje del mail

} ;

#endif