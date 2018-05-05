# Hot-Lava

•	Apply breath first traversal algorithm in a picture given start point and end point to find the shortest path.

•	If two pixels adjacent to each other are in the same color than assume there is a path between them.

•	Can be used to find solution for any given maze. 

•	Implemented using C++ and tested with JUnit tests.	

Goals and Overview

In this PA (Programming Assignment) you will:

learn about BFS graph traversal
learn about finding shortest paths in unweighted graphs
learn about implicitly defined graph data structures
The Assignment, Part 1: Inspiration and Background

Depth first and breadth first traversals are at the heart of solutions to many, many problems posed on graphs. For three examples, we can use traversals to detect cycles, to count components, and to find spanning trees. We can also use a breadth first traversal to find the shortest path between two vertices in an unweighted graph.

In this assignment we will use a breadth first traversal to find a shortest path between a start pixel and end pixel in an image, via a path where the colors of any two successive pixels cannot differ by very much.

The image below illustrates the result of this assignment. The start of the path is in the sea at the lower center of the image, and the end is in the clouds.

![alt text](https://www.ugrad.cs.ubc.ca/~cs221/2017W2/mps/p4/given-sunshinePath.png)

This problem is solved using a graph algorithm, and yet our solution contains no reference to an explicitly defined graph! Instead, the graph on which we execute the algorithm is implicitly defined so there is a vertex for every pixel in the image, and there is an edge between two vertices if they are adjacent to one another in the image, and similar in color.

This algorithm uses a stepping criterion that is similar to the one used in a popular optimization algorithm called “steepest descent.” Steepest descent is used to find a function’s local minimum value in multi-dimensional space. Machine learning algorithmns use such optimization algorithms as black-box solvers in classification problems.

The Assignment, Part 2: Coding

Problem Specification

Specifications for each function you write are contained in the given code. The list of functions here should serve as a checklist for completing the exercise.

In class path:

void BFS()
PNG render()
bool good(vector<vector<bool>> & v, pair<int,int> curr, pair<int,int> next)
vector<pair<int,int>> neighbors(pair<int,int> curr)
vector<pair<int,int>> assemble(vector<vector<pair<int,int>>> & p,pair<int,int> s, pair<int,int> e)
