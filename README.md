# JrsCheckers Project Overview

This windows console application and framework was written from scratch in less than 6 hours to support a checkers game. This application is in an unfinished state.

Some of the key features this application framework supports are:

* config-driven design		- much of the core application initialization is controlled via .ini configuration which facilitates adding new game types or modifying various tweakables for the checkers game mode. we also support dynamic factory instantiation by class name from config
* modular infrastructure	- makes swapping out rendering solution, input system, AI controllers, etc. easy
* shared core functionality	- which can be shared between many different types  of applications/games 
* logging system - makes it easy to dump logs to different output streams
* player turn system - makes it easy to support different combinations of human and 
					   AI players

TODO:
* finish implementation by finding and filling in TODOs
* replace rendering with a GUI-based rendering solution
* implement GameState control logic
* implement AI and human turn behaviors
* separate out engine, game, and checkers into separate vcprojs 
