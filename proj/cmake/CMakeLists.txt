cmake_minimum_required( VERSION 2.8 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( MaurerRose )

get_filename_component( CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../.." ABSOLUTE )
get_filename_component( APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE )

include( "${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake" )

ci_make_app(
  APP_NAME    "MaurerRoseOriginal"
	SOURCES     ${APP_PATH}/src/original/MaurerRose.cpp
	CINDER_PATH ${CINDER_PATH}
)

ci_make_app(
  APP_NAME    "MaurerRoseComplex"
	SOURCES     ${APP_PATH}/src/complex/MaurerRose.cpp
	CINDER_PATH ${CINDER_PATH}
)
