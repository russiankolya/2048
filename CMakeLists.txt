cmake_minimum_required(VERSION 3.3.2)
set(CMAKE_OSX_ARCHITECTURES x86_64)

project(2048 C CXX)

include(cmake/App.cmake)

set(SOURCES "src/main.cpp"
            "src/AppGame.cpp"
            "src/Tile.cpp"
            "src/Board.cpp")

add_app("${SOURCES}")