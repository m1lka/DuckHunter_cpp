cmake_minimum_required(VERSION 2.6)

project(DuckHunter)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -g3 -std=c++0x")

include_directories(./)

set(SRC_CORE ./Core/Window.cpp
			 ./Core/Renderer.cpp
			 ./Core/Texture.cpp
			 ./Core/Sprite.cpp
)

set(HDR_CORE ./Core/Window.hpp
			 ./Core/Render/Renderer.hpp
			 ./Core/Render/RenderRegion.hpp
			 ./Core/Texture.hpp
	         ./Core/MessageBox.hpp
	         ./Core/Sprite.hpp
	         ./Core/Input/KeyboardState.hpp
		     ./Core/Input/MouseState.hpp
		     ./Core/Input/Input.hpp
)

set(HDR_GAME ./Game.hpp)

set(TARGET_SRC ${HDR_CORE} ${SRC_CORE} ${HDR_GAME} ./main.cpp)

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)

  add_definitions(-D_LINUX)

  set(LIB SDL2 SDL2_image)

  add_executable(${PROJECT_NAME} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})

elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

  add_definitions(-D_WIN32)

  set(LIB m SDL2 SDL2main SDL2.dll mingw32 -mwindows)

  add_executable(${PROJECT_NAME} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})

else()
  message(FATAL_ERROR "-- Unknown compiler " ${CMAKE_C_COMPILER})
endif()
