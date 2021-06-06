project(REND)

include_directories(
  import/iron/include
  src
)

add_library(rend
  src/rend/Window.cpp
  src/rend/Image.cpp
  src/rend/Context.cpp
)
target_link_libraries(rend SDL2 GL GLEW)

add_executable(sample
  src/sample/main.cpp
)
target_link_libraries(sample rend)
