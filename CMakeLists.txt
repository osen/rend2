project(REND)

include_directories(
  src
)

add_library(rend
  src/rend/Window.cpp
  src/rend/Image.cpp
)
target_link_libraries(rend SDL2 GL)

add_executable(sample
  src/sample/main.cpp
)
target_link_libraries(sample rend)
