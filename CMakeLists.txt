cmake_minimum_required(VERSION 3.13)
project(SFML_SimCity_C)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(SFML_SimCity_C
        assets/Tile/commercial.png
        assets/Tile/forest.png
        assets/Tile/grass.png
        assets/Tile/industrial.png
        assets/Tile/residential.png
        assets/Tile/roads.png
        assets/Tile/waterAnim.png
        assets/UI/EmptyButton.png
        assets/UI/ExitButton.png
        assets/UI/Gellosia.ttf
        assets/UI/LargeEmptyButton.png
        assets/UI/MenuButton.png
        assets/UI/PlayButton.png
        assets/UI/SmallEmptyButton.png
        assets/background.png
        Animation.cpp
        Animation.hpp
        Button.cpp
        Button.hpp
        GameLoop.cpp
        GameLoop.hpp
        Gui.cpp
        Gui.hpp
        main.cpp
        MainGameState.cpp
        MainGameState.hpp
        MainMenuState.cpp
        MainMenuState.hpp
        MediaHandler.cpp
        MediaHandler.hpp
        State.hpp
        StateMachine.cpp
        StateMachine.hpp
        Tile.cpp
        Tile.hpp
        World.cpp
        World.hpp)

target_link_libraries (SFML_SimCity_C sfml-graphics sfml-window sfml-system)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY mapData.txt DESTINATION ${CMAKE_BINARY_DIR})