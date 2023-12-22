# CMake generated Testfile for 
# Source directory: /home/david/Escritorio/proyecto_iso/tests
# Build directory: /home/david/Escritorio/proyecto_iso/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(prueba-gtests "prueba-test")
set_tests_properties(prueba-gtests PROPERTIES  _BACKTRACE_TRIPLES "/home/david/Escritorio/proyecto_iso/tests/CMakeLists.txt;18;add_test;/home/david/Escritorio/proyecto_iso/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
