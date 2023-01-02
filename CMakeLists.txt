cmake_minimum_required (VERSION 3.8)

project (Engine)

add_subdirectory (Engine)

add_executable(${PROJECT_NAME} 
	main.cpp
)