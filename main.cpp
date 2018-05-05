
// File:        main.cpp
// Author:      cheeren
// Date:        2018-03-31
// Description: Partial test of PA4 functionality
//              Reads Point data from external files
//              Produces PNG images of the point sets


#include "path.h"
#include "cs221util/RGBAPixel.h"
#include "cs221util/PNG.h"

using namespace cs221util;
using namespace std;

PNG runtest(PNG& test, int x1, int x2, int x3, int x4){

	pair<int,int> start(x1,x2);
	pair<int,int> end(x3,x4);
	path testpath(test,start,end);
	PNG out = testpath.render();
	return out;

}

int main()
{

	PNG origIm1;
	origIm1.readFromFile("images/snake.png");
	pair<int,int> start1(2,2);
    pair<int,int> end1(637,477);
	path snake(origIm1,start1,end1);
	printf("finish constructor\n");
	PNG out1 = snake.render();
	out1.writeToFile("images/snakePath.png");

	PNG origIm2;
	origIm2.readFromFile("images/maze.png");
	pair<int,int> start2(3,10);
    pair<int,int> end2(637,477);
	path maze(origIm2,start2,end2);
	PNG out2 = maze.render();
	out2.writeToFile("images/mazePath.png");

	PNG origIm3;
	origIm3.readFromFile("images/sunshine.png");
	pair<int,int> start3(320,420);
    pair<int,int> end3(100,100);
	path sunshine(origIm3,start3,end3);
	PNG out3 = sunshine.render();
	out3.writeToFile("images/sunshinePath.png");


	PNG test1;
	test1.readFromFile("images/test1.png");
	pair<int,int> start4(1,2);
  pair<int,int> end4(18,12);
	path testpath1(test1,start4,end4);
	PNG out4 = testpath1.render();
	out4.writeToFile("images/testPath1.png");

	PNG test2;
	test2.readFromFile("images/test2.png");
	pair<int,int> start5(3,4);
	pair<int,int> end5(16,14);
	path testpath2(test2,start5,end5);
	PNG out5 = testpath2.render();
	out5.writeToFile("images/testPath2.png");

	PNG test3;
	test3.readFromFile("images/test3.png");
	path testpath3(test3,start5,end5);
	PNG out6 = testpath3.render();
	out6.writeToFile("images/testPath3.png");

	PNG test4;
	test4.readFromFile("images/test4.png");
	PNG out7 = runtest(test4, 2, 9, 20, 11);
	out7.writeToFile("images/testPath4.png");

	PNG test5;
	test5.readFromFile("images/test5.png");
	PNG out8 = runtest(test5, 2, 9, 20, 11);
	out8.writeToFile("images/testPath5.png");

	PNG test6;
	test6.readFromFile("images/test6.png");
	PNG out9 = runtest(test6, 38, 42, 988, 515);
	out9.writeToFile("images/testPath6.png");

	PNG out10 = runtest(test6, 4, 515, 960, 183);
	out10.writeToFile("images/testPath7.png");

	PNG test7;
	test7.readFromFile("images/test8.png");
	PNG out11 = runtest(test7, 4, 515, 960, 183);
	out11.writeToFile("images/testPath8.png");
  return 0;
}
