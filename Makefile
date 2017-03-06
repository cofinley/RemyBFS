main:   Position.o Maze.o mazeShortestPath.o RescueRemyQ.o
	g++ Position.o Maze.o RescueRemyQ.o mazeShortestPath.o -o main

RescueRemyQ.o:  RescueRemyQ.cpp mazeShortestPath.h Position.h Maze.h
	g++ -c RescueRemyQ.cpp

Position.o:  Position.cpp Position.h
	g++ -c Position.cpp 

Maze.o:   Maze.h Maze.cpp
	g++ -c Maze.cpp

mazeShortestPath.o: mazeShortestPath.cpp Maze.h mazeShortestPath.h
	g++ -c mazeShortestPath.cpp

