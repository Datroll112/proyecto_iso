add_library(UcoActividades UcoActividades-Funciones.cc UcoActividades.h)
target_include_directories(UcoActividades PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(UcoActividades-main UcoActividades-main.cc)

target_link_libraries(UcoActividades-main PUBLIC UcoActividades)