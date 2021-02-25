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

set(SOURCES
  divisao/divisao.c
  produto/produto.c
  soma/soma.c
  subtracao/subtracao.c
)
      
add_library(${TARGET_NAME} SHARED ${SOURCES})
target_link_libraries(${TARGET_NAME}
divisao
produto
soma
subtracao
)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR}/../output-files/libs-so/)

add_executable(${TARGET_NAME}-bin main.c)
target_link_libraries(${TARGET_NAME}-bin
${TARGET_NAME}
)

add_custom_command(TARGET ${TARGET_NAME}-bin POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}-bin> ${PROJECT_SOURCE_DIR}/../output-files/bin/)
