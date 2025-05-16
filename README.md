# Plan

## Small steps

    1. Painting:
       - Cursor should be smooth.. use line interpolation? whatever that is..
    2. Stuff to Encapsulate (Lets try using composition instead):
       - Create an Entity Base Class (This is where everything will inherit)
       
       - Canvas Object              
       - Toolbar Object
       - Brush Object
       - Button Object
       
       
       
       
## Simplified Plan

1. Application will have
    - ToolBar (Handles logic of changing brush color)
        - reference to brush sprite
        - interface for changing brush sprite properties
    
    - ToolBarUI ( handles checking for user input, then calling back to the interface given by toolbar )
       - A Reference to a toolbar object. 
       - Display 3 Rectangles Going downwards on the right edge of the screen.
       - Check hover
         - If hover, scales up a tiny bit to show hover.
       - Check click
         - If click, call the ToolBar called changeBrushColor(button_color); 
  
