cmake_minimum_required(VERSION 2.6)

project(DuckHunter)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(./)

set(SRC_ENGINE ./mEngine/Graphic/Core/Window.cpp
               ./mEngine/Graphic/Render/Renderer.cpp
               ./mEngine/Graphic/Core/Texture.cpp
               ./mEngine/Graphic/Core/Sprite.cpp
               ./mEngine/Core/Object.cpp
               ./mEngine/Core/Context.cpp
               ./mEngine/Core/Subsystem.cpp
               ./mEngine/Core/mCore.cpp
)

set(HDR_ENGINE ./mEngine/Graphic/Core/Window.hpp
               ./mEngine/Graphic/Render/Renderer.hpp
               ./mEngine/Graphic/Render/RenderRegion.hpp
               ./mEngine/Graphic/Core/Texture.hpp
               ./mEngine/UI/MessageBox.hpp
               ./mEngine/Graphic/Core/Sprite.hpp
               ./mEngine/Input/KeyboardState.hpp
               ./mEngine/Input/MouseState.hpp
               ./mEngine/Input/Input.hpp
               ./mEngine/Core/Object.hpp
               ./mEngine/Core/Context.hpp
               ./mEngine/Core/Subsystem.hpp
               ./mEngine/Core/mCore.hpp)

set(HDR_GAME ./Game.hpp)
set(TARGET_SRC ${HDR_ENGINE} ${SRC_ENGINE} ${HDR_GAME} ./main.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Textures/field.png ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Textures/X.bmp ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)

  add_definitions(-D_LINUX)

  set(LIB SDL2 SDL2_image)

  add_executable(${PROJECT_NAME} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})

elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)

  add_definitions(-D_WIN32)

  set(LIB m SDL2 SDL2main SDL2.dll SDL2_image.dll mingw32 -mwindows)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/libfreetype-6.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/libjpeg-9.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/libpng16-16.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/libtiff-5.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/libwebp-7.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/SDL2.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/SDL2_image.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Content/Libraries/SDL2_ttf.dll ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)

  add_executable(${PROJECT_NAME} ${TARGET_SRC})
  target_link_libraries(${PROJECT_NAME} ${LIB})
  
else()
  message(FATAL_ERROR "-- Unknown compiler " ${CMAKE_C_COMPILER})
endif()
