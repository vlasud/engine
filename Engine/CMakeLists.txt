
find_package(OpenGL REQUIRED)

add_subdirectory (thirdParty/glfw/)

add_library(engine 
	engine.cpp
	context.cpp
)

target_include_directories(engine PUBLIC thirdParty/glfw/include)
target_link_libraries(engine PUBLIC glfw OpenGL::GL)