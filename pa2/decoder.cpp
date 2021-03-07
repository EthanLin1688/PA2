#include "decoder.h"
#include "queue.h"
#include "stack.h"
using namespace std;

decoder::decoder(const PNG & tm, pair<int,int> s)
   :start(s),mapImg(tm) {

/* YOUR CODE HERE */
    
}

PNG decoder::renderSolution(){

	for(int i = 0; i < pathPts.size(); i++){
		RGBAPixel *pixel = mapImg.getPixel(pathPts[i].first, pathPts[i].second);
		pixel->r = 255;
        pixel->g = 0;
        pixel->b = 0;
	}

}

PNG decoder::renderMaze(){

	PNG copy = mapImg;
    queue<pair<int, int>> locations;

    for(int i = start.first-3; i =< start.first+3; i++){
        if(i>=0 && i < copy.width()){
            for(int j = start.second-3; j =< start.second+3; j++){
                if(j>=0 && j < copy.height()){
                    RGBAPixel *pixel = im.getPixel(x,y);
                    pixel->r = 255;
                    pixel->g = 0;
                    pixel->b = 0;
                }
            }
        }
    }

    locations.enqueue(start);

    while(!location.isEmpty()) {
        pair<int, int> curr = locations.peek();
        vector<pair<int,int>> neighbor = neighbors(curr);
        locations.dequeue();
        for(int i = 0; i < 4; i++){
            if(good(visit, curr, neighbor[i])){
                setGrey(copy, neighbor[i]);
                locations.enqueue(neighbor[i]);
            }
        }
    }

    return copy;

}

void decoder::setGrey(PNG & im, pair<int,int> loc){

/* YOUR CODE HERE */

}

pair<int,int> decoder::findSpot(){

/* YOUR CODE HERE */

}

int decoder::pathLength(){

/* YOUR CODE HERE */

}

bool decoder::good(vector<vector<bool>> & v, vector<vector<int>> & d, pair<int,int> curr, pair<int,int> next){

/* YOUR CODE HERE */

}

vector<pair<int,int>> decoder::neighbors(pair<int,int> curr) {

/* YOUR CODE HERE */

}


bool decoder::compare(RGBAPixel p, int d){

/* YOUR CODE HERE */

}
