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
 - Brush
    update method
    draw method
    unique_ptr to an sf::Shape object (initialized with an sf::CircleShape)
    
  
