cmake_minimum_required(VERSION 2.6)

project(DuckHunter)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -g3 -std=c++0x")

include_directories(./include)

set(SRC ./src/SDLWrapper/Window.cpp
		./src/SDLWrapper/Renderer.cpp
		./src/SDLWrapper/Texture.cpp
)

set(HDR ./include/SDLWrapper/Window.hpp
		./include/SDLWrapper/Render/Renderer.hpp
		./include/SDLWrapper/Render/RenderRegion.hpp
		./include/SDLWrapper/Texture.hpp
                ./include/SDLWrapper/MessageBox.hpp
        ./include/Game.hpp
)

set(TARGET_SRC ./main.cpp)

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)

  add_definitions(-D_LINUX)

  set(LIB SDL2)

  add_executable(${PROJECT_NAME} ${HDR} ${SRC} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})

elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

  add_definitions(-D_WIN32)

  set(LIB m SDL2 SDL2main SDL2.dll mingw32 -mwindows)

  add_executable(${PROJECT_NAME} ${HDR} ${SRC} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})

else()
  message(FATAL_ERROR "-- Unknown compiler " ${CMAKE_C_COMPILER})
endif()
