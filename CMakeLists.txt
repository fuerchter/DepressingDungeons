cmake_minimum_required(VERSION 2.8)

project(DepressingDungeons)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(CURSES REQUIRED)

if(CURSES_FOUND)
	include_directories(${CURSES_INCLUDE_DIR})
	set(LIBRARIES ${LIBRARIES} ${CURSES_LIBRARIES})
endif()

#Folders to be searched
set(FOLDERS "src")

#Adding source files in each of the FOLDERS to EXECUTABLES
foreach(FOLDER ${FOLDERS})
	file(GLOB GLOBFILES "${FOLDER}/*.cpp")
	set(EXECUTABLES ${EXECUTABLES} ${GLOBFILES})
endforeach(FOLDER)

add_executable(DepressingDungeons ${EXECUTABLES})
target_link_libraries(DepressingDungeons ${LIBRARIES})

#install(TARGETS name DESTINATION ${CMAKE_INSTALL_PREFIX})
#install(DIRECTORY "assets" DESTINATION ${CMAKE_INSTALL_PREFIX})