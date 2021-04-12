# SFML_SimCity_C
2D city bulding game (like first sim-city), currently WIP

## Technologies
C++ project written using SFML, using CMake, and Piskel (for drawing pixelarts)

## In Action
![gameplay-gif](https://github.com/arturJan4/SFML_SimCity_C/tree/master/docs/showcase.gif)
## Installation
required:
- sfml 2.5.1
- cmake (3.13 or higher)

Windows: 
    -Use CMake software (and relevant tutorials)
Linux: 
    -When in game folder, use commands `mkdir build`, `cd build`, `cmake ..`, `make` to build project
You can also run one commands (but it's harder to fix bugs if somethings doesn't work):
`mkdir build ; cd build ; cmake .. ; make`

Now you can play by launching SFML_SimCity_C executable ("./SFML_SIMCITY_C")

## Setup
Probably the easiest method is to just launch using and IDE supportin CMake, I personally used CLion for this project

## Features
* 2d tile map 
* user interaction using mouse and keyboard
* loading and saving to file
* animations that work (although not perfectly)

## TODO
* GUI library
* game goal
* statistics
* economy and progress (virtual opponents)
* natural disasters
* traffic
* optimizations for lower fps (duplicating frames etc.)
* fixing bugs and bag practices 
* and a lot of other things that I would like to have but never had the time to add them :(
## Author
Artur Jankowski
