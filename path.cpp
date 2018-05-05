#include "path.h"
#include <queue>
#include <stack>
using namespace std;
int MAX = 2147483000;

path::path(const PNG & im, pair<int,int> s, pair<int,int> e)
   :start(s),end(e),image(im){
    BFS();
}

void path::BFS(){
	// initialize working vectors
	vector<vector<bool>> V(image.height(), vector<bool> (image.width(),false));
	vector<vector<pair<int,int>>> P(image.height(), vector<pair<int,int>> (image.width(),end));
  vector<vector<int>> length(image.width(), vector<int>(image.height(),MAX));
  printf("height&width %d %d\n",image.height(), image.width());
  queue<pair<int,int>> q;
  q.push(start);
  length[start.first][start.second] = 0;
  V[start.second][start.first] = true;
  while(!q.empty()){
    pair<int,int> p1;
    p1 = q.front();
  // printf("pair p1: %d %d\n", p1.second, p1.first);
    q.pop();
    std::vector<pair<int,int>> v = neighbors(p1);
    while(!v.empty()){
      pair<int,int> p2= v.back();
      v.pop_back();
      if(good(V, p1, p2)){
        p1 = findMinLength(V,length,neighbors(p2),p2);
         // printf("finish findmin\n");
        P[p2.second][p2.first] = p1;
        // printf("pair p2: %d %d -> p1 %d %d\n",p2.second, p2.first, p1.second, p1.first);
        length[p2.first][p2.second] = length[p1.first][p1.second]+1;
        q.push(p2);
        V[p2.second][p2.first] = true;
      }
    }
  }

  printf("finish BFS\n");

	pathPts = assemble(P,start,end);
}

pair<int,int> path::findMinLength(vector<vector<bool>> & visited,vector<vector<int>>& length, vector<pair<int,int>> vec, pair<int,int>p){
  pair<int,int> min;
  int numMin = MAX;
  for(int i =0; i<4; i++){
  //  printf("int findmin %d %d\n",vec[i].first, vec[i].second );
    if(vec[i].second < 0 || vec[i].second >= image.height() || vec[i].first < 0 || vec[i].first >= image.width()) continue;
    if(visited[vec[i].second][vec[i].first]&&good(visited,vec[i],p)&&length[vec[i].first][vec[i].second]< numMin){
      min = vec[i];
      numMin = length[vec[i].first][vec[i].second];
    }
  }
  return min;
}

PNG path::render(){
  PNG rimage = PNG(image);
  for(auto it = pathPts.begin(); it != pathPts.end(); it++){
    *rimage.getPixel((*it).first, (*it).second) = RGBAPixel(255,0,0);
  }
  return rimage;

}

vector<pair<int,int>> path::getPath() { return pathPts;}

int path::length() { return pathPts.size();}

bool path::good(vector<vector<bool>> & v, pair<int,int> curr, pair<int,int> next){
  if(next.second < 0 || next.second >= image.height() || next.first < 0 || next.first >= image.width())
    return false;
  if(v[next.second][next.first]) return false;
  if(!closeEnough(*image.getPixel(curr.first, curr.second), *image.getPixel(next.first, next.second)))
    return false;
  return true;
}

vector<pair<int,int>> path::neighbors(pair<int,int> curr) {
//	vector<pair<int,int>>* n = new vector<pair<int, int>> (4);
  std::vector<pair<int,int>> n;
  n.push_back(pair<int,int> (curr.first, curr.second+1)); //2
  n.push_back(pair<int,int> (curr.first-1, curr.second)); //1
  n.push_back(pair<int,int> (curr.first, curr.second-1)); //4
  n.push_back(pair<int,int> (curr.first+1, curr.second)); //3
  return n;
}

vector<pair<int,int>> path::assemble(vector<vector<pair<int,int>>> & p,pair<int,int> s, pair<int,int> e) {
    /* hint, gold code contains the following line:*/
	stack<pair<int,int>> S;
  S.push(e);
  for(int i=0; i<image.height()*image.width(); i++) {
    pair<int,int> point = S.top();
    //printf("point: %d %d \n",point.second, point.first);
    if(point == s) break;
    if(p[point.second][point.first]!=point)
       S.push(p[point.second][point.first]);
  }
  std::vector<pair<int,int>> v;
  if(S.top()==s){
    while(!S.empty()){
      v.push_back(S.top());
      S.pop();
    }
    return v;
  }else{
    v.push_back(s);
    return v;
  }
}

bool path::closeEnough(RGBAPixel p1, RGBAPixel p2){
   int dist = (p1.r-p2.r)*(p1.r-p2.r) + (p1.g-p2.g)*(p1.g-p2.g) +
               (p1.b-p2.b)*(p1.b-p2.b);

   return (dist <= 80);
}
