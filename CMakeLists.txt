cmake_minimum_required(VERSION 2.6)

project(DuckHunter)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -g3 -std=c++0x")

include_directories(./)

set(SRC_ENGINE ./mEngine/Core/Window.cpp
               ./mEngine/Core/Renderer.cpp
               ./mEngine/Core/Texture.cpp
               ./mEngine/Core/Sprite.cpp
               ./mEngine/Core/Object.cpp
)

set(HDR_ENGINE ./mEngine/Core/Window.hpp
               ./mEngine/Core/Render/Renderer.hpp
               ./mEngine/Core/Render/RenderRegion.hpp
               ./mEngine/Core/Texture.hpp
               ./mEngine/Core/MessageBox.hpp
               ./mEngine/Core/Sprite.hpp
               ./mEngine/Core/Input/KeyboardState.hpp
               ./mEngine/Core/Input/MouseState.hpp
               ./mEngine/Core/Input/Input.hpp
               ./mEngine/Core/Object.hpp
)


set(HDR_GAME ./Game.hpp)

set(TARGET_SRC ${HDR_ENGINE} ${SRC_ENGINE} ${HDR_GAME} ./main.cpp)

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)

  add_definitions(-D_LINUX)

  set(LIB SDL2 SDL2_image)

  add_executable(${PROJECT_NAME} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})

elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

  add_definitions(-D_WIN32)

  set(LIB m SDL2 SDL2main SDL2.dll SDL2_image.dll mingw32 -mwindows)

  add_executable(${PROJECT_NAME} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})

else()
  message(FATAL_ERROR "-- Unknown compiler " ${CMAKE_C_COMPILER})
endif()
