cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME "subtracao")

project(${TARGET_NAME} VERSION 0.1
        DESCRIPTION "Uma simples calculadora"
        LANGUAGES C
        )

include_directories(${PROJECT_SOURCE_DIR}/header)

set(SOURCES
  subtracao.c
)
      
add_library(${TARGET_NAME} SHARED ${SOURCES})

install(
    TARGETS              "${TARGET_NAME}"
    LIBRARY DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
)
