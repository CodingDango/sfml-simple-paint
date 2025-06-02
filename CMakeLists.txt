cmake_minimum_required(VERSION 3.10)

project(SimpleSFMLPaintApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

add_executable(
    main 
    ./src/main.cpp 
    ./src/app.cpp

    # -- Entity Folder
    # ./src/Entity/Entity.cpp

    # -- Paint Folder 
    ./src/Paint/Brush.cpp
    ./src/Paint/BrushLogic.cpp
    ./src/Paint/Canvas.cpp
    
    # -- UI Components
    ./src/UIComponents/Buttons/ButtonBase.cpp
    ./src/UIComponents/Buttons/StandardButton.cpp
    ./src/UIComponents/Buttons/ColorPalleteButton.cpp

    ./src/UIComponents/TextLabel.cpp
    ./src/UIComponents/UIEntityContainerComponent.cpp

    # -- Paint UI Components
    ./src/PaintUIComponents/BrushLogicUI.cpp
    ./src/PaintUIComponents/BrushColorPallete.cpp
    ./src/PaintUIComponents/BrushShapes.cpp

    # -- Paint UX Folder
)
     
target_include_directories(
    main PRIVATE
    ./src/
    ./src/Paint
    ./src/UIComponents
    ./src/UIComponents/Buttons
    ./src/PaintUIComponents
    ./src/Entity
)
   
target_compile_options(
    main PRIVATE 
    "-O0"
    "-Wall"
    "-ggdb"
    "-pedantic"
)

find_package(SFML 2.6 COMPONENTS graphics audio system window REQUIRED)
target_link_libraries(main sfml-graphics sfml-audio sfml-system sfml-window)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})