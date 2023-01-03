cmake_minimum_required (VERSION 3.8)

project (EngineProject)

add_subdirectory (Engine)
add_subdirectory (thirdParty/glfw/)

add_executable(${PROJECT_NAME} 
	main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC thirdParty/glfw/include)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
