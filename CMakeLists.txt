project(REND)

#add_definitions(-DUSE_SDL2)
add_definitions(-DUSE_FLTK)

include_directories(
  import/iron/include
  src
)

add_library(rend
  src/rend/Window.cpp
  src/rend/Image.cpp
  src/rend/Context.cpp
  src/rend/mathutil.cpp
  src/rend/Shader.cpp
  src/rend/UiShader.cpp
)
target_link_libraries(rend SDL2 fltk fltk_gl GL GLEW)

add_executable(sample
  src/sample/main.cpp
)
target_link_libraries(sample rend)

