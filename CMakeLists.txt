cmake_minimum_required( VERSION 3.14 )

project( stl_implementation )
set( CMAKE_CXX_STANDARD 17 )

include_directories( "${PROJECT_BINARY_DIR}" )
include_directories( "${PROJECT_BINARY_DIR}/algorithms" )
include_directories( "${PROJECT_BINARY_DIR}/algorithms/modifying_sequence_operation" )
include_directories( "${PROJECT_BINARY_DIR}/array" )
include_directories( "${PROJECT_BINARY_DIR}/vector" )

add_subdirectory( algorithms )
add_subdirectory( algorithms/modifying_sequence_operation )
add_subdirectory( array )
add_subdirectory( vector )

add_executable( stl_implementation main.cpp )

install( TARGETS stl_implementation DESTINATION ${PROJECT_BINARY_DIR} )
