// proyecto.h
// file 

#ifndef PROYECTO_H
#define PROYECTO_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Usuario{

    private:

        list<string> lista_usuarios_ ;
        map<string,int> lista_contrasenas_usuarios_ ;
        string organizador_ = "Luis" ;
        string contrasena_organizador = "1234" ;
        string director_academico_ ;
        string contrasena_director_academico_ ;

    public:

        Usuario( string director_academico , string contrasena_director_academico ){ director_academico_ = director_academico , contrasena_director_academico_ = contrasena_director_academico ; }
        int Login( string usuario, string contraseña ) ; // Devuelve 0 si el usuario no existe,  1 si es un usuario registrado, 2 si es el director academico, 3 si es el organizador y 4 si es un visitante. 

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

        // el int de los mapas es el numero de la actividad

        map<int,string> lista_tematicas_ ;
        map<int,string> lista_ubicaciones_ ;
        map<int,string> lista_fechas_ ;
        map<int,string> lista_aforos_ ;
        map<int,string> lista_asistentes_ ;
        map<int,string> lista_duraciones_ ;
        map<int,string> lista_precios_ ;
        map<int,string> lista_materiales_necesarios_ ;

    public:

        Actividad_academica( int numero_act , string tematica , string ubicacion , string fecha , string aforo , string asistentes , int duracion , float precio , string material_necesario ){
            numero_act_ = numero_act , tematica_ = tematica , ubicacion_ = ubicacion , fecha_ = fecha , aforo_ = aforo , asistentes_ = asistentes , duracion_ = duracion , precio_ = precio , material_necesario_ = material_necesario ;
        }
        bool Crear_actividad() ; // almacena los datos de una actividad en los mapas y crea un fichero con unicamente la actividad creada.
        void Visualizar_act() ; // crea un fichero con todas las actividades. 

} ;

class Visitante: public Usuario{

    private:



    public:

        void Registro( string usuario, string contrasena ) ; // anade un nuevo usuario registrado.

} ;

class Usuario_regristrado: public Usuario, public Actividad_academica{

    private:

        map<int,string> lista_asistentes_ ;

    public:

        bool Inscripcion( int actividad ) ; // 1 exito, 0 fracaso.
        bool Cancelacion() ; // 1 exito, 0 fracaso.
        void Ver_asistencia() ; // imprime por pantalla los asistentes

} ;

class Director_academico: public Usuario, public Mailing{

    private:



    public:

        bool Eliminar_usuario_registrado( string usuario ) ;

} ;

class Mailing{

    private:

        int id_mailing_ ;
        string mensaje_mailing_ ;

    public:

        Mailing( int id_mailing , string mensaje_mailing ){ id_mailing_ = id_mailing , mensaje_mailing_ = mensaje_mailing ; }
        void Crear_mail( int id , string mensaje ) ; // crea un fichero con el id y el mensaje del mail

} ;

#endif