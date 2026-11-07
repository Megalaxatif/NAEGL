simplified pipeline:
  SETUP : init SDL + OpenGL -> init shaders -> create Gui_context -> add gui elements
  LOOP : get events -> handle event -> display -> delay -> repeat
         ---------- UPDATE -------------------

NOTE: shader programs will execute at display
