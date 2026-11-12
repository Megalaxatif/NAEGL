simplified pipeline:
  SETUP : init SDL + OpenGL -> init shaders -> create Gui_context -> add gui elements
  LOOP : get events -> handle event -> display -> delay -> repeat
         -------------- UPDATE ---------------

NOTE: shader programs will execute at display

TODOs:
-create a new kind of layout that put the widgets in a grid
-move textures out of settings, because settings could be shared and not textures
-move rectangle and text to widgets (update enums and settings also)
-propagate flags during init of widgets
-display a button (first goal)
