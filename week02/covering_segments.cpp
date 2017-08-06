#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using std::vector;

// File  : covering_segments.cpp
// Implements an algorithm to solve the problem below
// Given a set of 𝑛 segments {[𝑎0, 𝑏0], [𝑎1, 𝑏1], . . . , [𝑎𝑛−1, 𝑏𝑛−1]} with integer coordinates on a line, 
// find the minimum number 𝑚 of points such that each segment contains at least one point. That is, find a
// set of integers 𝑋 of the minimum size such that for any segment [𝑎𝑖 , 𝑏𝑖 ] there is a point 𝑥 belongs to  𝑋 
// such that 𝑎i ≤ 𝑥 ≤ 𝑏i

// segment structure 
struct Segment {
  int start, end;
};

// custom comparator defined to arrange values in the vector 
// from min to max end valued segment 

typedef struct lesser_t
{
    template<class T>
    // true if a.end is less than b.end
    bool operator()(T const &a, T const &b) const { return a.end < b.end; }
}lesser_t;


// algorithm to find minimum number of points required to cover 
// given set of line segments

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  std::sort(segments.begin(), segments.end(), lesser_t());
  int x = segments[0].end;

  // add first point to set
  points.push_back(x);

  for (size_t i = 0; i < segments.size(); i++) {  
    if(((segments[i].start)>x)){
      //update the point incase x is not inbetwee ai and bi of segment
      x = segments[i].end;
      points.push_back(x);      
    }
  }
  return points;
}


void test(){
  
  vector<Segment> segments;
  Segment s1;
  s1.start = 4;
  s1.end = 7;
  segments.push_back(s1);

  s1.start = 1;
  s1.end = 3;
  segments.push_back(s1);

  s1.start = 2;
  s1.end = 5;
  segments.push_back(s1);

  s1.start = 5;
  s1.end = 6;
  segments.push_back(s1);

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }

}


int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
