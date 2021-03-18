cmake_minimum_required(VERSION 3.10)

set(TARGET_NAME "calculadora")

project(${TARGET_NAME} VERSION 0.1
        DESCRIPTION "Uma simples calculadora"
        LANGUAGES C
        )

include_directories(${PROJECT_SOURCE_DIR}/header)

# Set HEADERS_PUBLIC variable (public headers, included in the library)
set(HEADERS_PUBLIC
  ${PROJECT_SOURCE_DIR}/header/source.h
)

add_subdirectory(src)
