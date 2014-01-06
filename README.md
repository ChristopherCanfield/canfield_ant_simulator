<h2>Canfield Ant Simulator: Swarm Intelligence using Goal-based Agents & A*</h2>
<h4>Christopher D. Canfield</h4>



I. Overview
-----------

The Canfield Ant Simulator simulates a colony of ants, with a focus on the ants' search for food. Ants lay pheromone trails to notify other ants about food, as in the real world. Over time, this gives the ants the appearance of having a higher-level coordinating intelligence that is instructing all ants according to group goals, when in reality each ant is fully in control of itself, and does not have any direct communication with other ants.

The project involved the creation of the following components:
- World Creator: random map generator
- Navigation Graph, with nodes & edges
- Ants: goal-based agents
- 7 ant goals and subgoals
- A* algorithm implementation
- GUI processing framework using the Observer pattern
- 123 unit tests + 3 test applications, in addition to the final simulation

The project was created by Christopher Canfield as part of the BU MET CS 664 Artificial Intelligence course.


II. Implementation
------------------

The simulation was written in C++, and uses the following libraries:
- Simple & Fast Multimedia Library (SFML): Provides a cross-platform object-oriented abstraction layer over OpenGL and the platform's native windowing system
- Boost C++ Libraries: circular array, noncopyable
- POCO C++ Libraries: UUID


III. More Information
---------------------

- <a href="http://christopherdcanfield.com/projects/antsimulator/Canfield%20Ant%20Simulator.zip">Windows Binaries</a>
- <a href="http://christopherdcanfield.com/projects/antsimulator/CS664%20Canfield%20Ant%20Simulator%20Presentation.pdf">Presentation</a>
- <a href="http://christopherdcanfield.com/projects/antsimulator/CS664%20Canfield%20Ant%20Simulator%20Documentation.pdf">Documentation</a>


IV. Running the Simulator
-------------------------

The windows executable is available <a href="http://christopherdcanfield.com/projects/antsimulator/Canfield%20Ant%20Simulator.zip">here</a>. It was successfully tested on the following operating systems:
- Windows 8.1
- Windows 8
- Windows 7
- Windows Vista

Simulation controls:
    Space         Pause/Unpause
    +             Increase simulation speed
    -             Decrease simulation speed
    1             Show/hide navigation graph
    2             Show/hide pheromone strength
    3             Show/hide ant paths (A* paths)
    4             Show/hide dead ants
    5             Show/hide background
    Mouse wheel   Zoom in/out
    Arrow keys    Move screen up/down/left/right (only when zoomed)
    ?             Display these commands in the console
    Escape        Exit

The "Canfield: Ant Simulator" window must be active for these commands to work. You may need to click on the window's title bar to activate it.


V. Compiling the Code
---------------------

The code was successfully compiled using Visual Studio 2012. In theory, the code was written to be cross-platform, so any C++11 compiler should work, but this has not yet been tested. The project requires the 3 libraries listed above.


VI. Project References
----------------------

S. Russell & P. Norvig, Artificial Intelligence: A Modern Approach, 3rd edition. Upper Saddle River, NJ; 2010.

M. Bukland, Programming Game AI by Example. Sudbury, MA; 2005.

B.C. Bridger, Chris S. Groskopf, "Fundamentals of Artificial Intelligence in Game Development," Proceedings of the 38th annual on Southeast regional conference, April 7, 2000.

Christoph Salge , Christian Lipski , Tobias Mahlmann , Brigitte Mathiak, "Using genetically optimized artificial intelligence to improve gameplaying fun for strategical games," Proceedings of the 2008 ACM SIGGRAPH symposium on Video games, August 09-10, 2008, Los Angeles, California.

T. S. Ray, "An Approach to the Synthesis of Life," Artificial Life II, C. G. Langton, C. Taylor, J. D. Farmer, and S. Rasmussen (eds.), Addison-Wesley, Reading, MA, pp. 371-408.

Amit Patel, Amit's A* Pages [Online]. Available: http://theory.stanford.edu/~amitp/GameProgramming/

A. Dussutour, S. C. Nicolis, G. Shephard, M. Beekman and D. J. T. Sumpter, “The role of multiple pheromones in food recruitment by ants,” The Journal of Experimental Biology. Aug 2009.

M. Mizunami, N. Yamagata and H. Nishino, “Alarm Pheromone Processing in the Ant Brain: An Evolutionary Perspective,” Frontiers in Behavioral Neuroscience. vol. 4, article 28, June 2010.

Peter Miller, "The Genius of Swarms," National Geographic [Online]. Available: http://ngm.nationalgeographic.com/2007/07/swarms/miller-text

Simple & Fast Multimedia Library: http://www.sfml-dev.org/

Boost C++ Libraries: http://www.boost.org/

POCO C++ Libraries: http://pocoproject.org/

Paul Bourke, "Texture Library" [Online]. Available: http://paulbourke.net/texture_colour/


-----------------------
Christopher D. Canfield
