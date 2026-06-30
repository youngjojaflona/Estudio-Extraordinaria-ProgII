cmake_minimum_required(VERSION 4.1)
project(TDAs_Extraod_26 C CXX)

set(CMAKE_C_STANDARD 11)

add_executable(TDAs_Extraod_26 main.c)
add_executable(Objetos_Clases Objetos-Clases_Extraordinaria-26.cpp
        PluginAudio.h
        PluginAudioAbstract.h
        PaquetePostal.h
        PaquetePostalAbstract.h
        RazaHumana.cpp
        RazaHumana.h
        ProveedorIA.h
        ProveedorIAAbstract.h
        Figura.h)