cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME "calculadora")

project(${TARGET_NAME} VERSION 0.1
        DESCRIPTION "Uma simples calculadora"
        LANGUAGES C
        )

set(modules divisao produto soma subtracao)

foreach(module ${modules})
  add_subdirectory(${module})
endforeach()

add_library(${TARGET_NAME} SHARED main.c)
target_link_libraries(${TARGET_NAME}
divisao
produto
soma
subtracao
)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR}/../output-files/libs-so/)

# Introduce variables:
#   - CMAKE_INSTALL_LIBDIR
#   - CMAKE_INSTALL_BINDIR
#   - CMAKE_INSTALL_INCLUDEDIR
include(GNUInstallDirs)

install(
    TARGETS              "${TARGET_NAME}"
    LIBRARY DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
)

install(
    FILES ${HEADERS_PUBLIC}
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_FOLDER}"
)
