cmake_minimum_required (VERSION 2.6)

set(CMAKE_INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")

project (XModuleTest)

set(FOONAME cmake-default)

add_definitions(-DLIB_NAME="$(FOONAME)")


add_library(foo foo.c)

install (TARGETS foo DESTINATION lib)
install (FILES foo.h DESTINATION include)
