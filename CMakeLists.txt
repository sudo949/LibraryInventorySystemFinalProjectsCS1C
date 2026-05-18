cmake_minimum_required(VERSION 3.16)

project(LibraryInventorySystemFinalProjectsCS1C LANGUAGES CXX)

file(GLOB PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

file(GLOB PROJECT_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

set(APP_MAIN "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
list(REMOVE_ITEM PROJECT_SOURCES "${APP_MAIN}")

add_library(${PROJECT_NAME} STATIC
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_executable(${PROJECT_NAME}_app
    ${APP_MAIN}
)

target_link_libraries(${PROJECT_NAME}_app
    PRIVATE
        ${PROJECT_NAME}
)

target_compile_features(${PROJECT_NAME}_app PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME}_app PROPERTIES OUTPUT_NAME "LibraryInventorySystemFinalProjectsCS1C")
