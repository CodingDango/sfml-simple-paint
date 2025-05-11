# Plan

## Small steps

    1. Setup directory 
       - create src folder, 
       - create includes folder, 
       - link the includes in the .launch.json
       - link includes with cmake with target_includes()

    2. Basic SFML Setup (Get a window on the screen very simple.)
       - Setup the RenderWindow object
       - Set RenderWindow object FPS and Title and screen width\
       - Create the game loop
         - initialize delta time with clock 
         - Create the basic while event loop
         - Update logic
         - display logic
    
    3. Setting up the Drawable Canvas
       - Temporarily, canvas size should cover he wholes screen.
       - When mouse is held draw red circles into the texture at the mouse position? not sure how to do this yet. (maybe use objects?)
       - Maybe find a way to clear the canvas with a shortcut or button. (FOR NOW SHORTCUT)
  