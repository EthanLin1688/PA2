#include "decoder.h"
#include "queue.h"
#include "stack.h"
#include "treasureMap.h"
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

    int x = loc.first;
    int y = loc.second;
    RGBAPixel *pixel = im.getPixel(x,y);
    pixel->r = 2*((pixel->r)/4);
    pixel->g = 2*((pixel->g)/4);
    pixel->b = 2*((pixel->b)/4);
}

pair<int,int> decoder::findSpot(){
    return pathPts[pathPts.size()-1];
}

int decoder::pathLength(){
    return pathPts.size()-1;
}

bool decoder::good(vector<vector<bool>> & v, vector<vector<int>> & d, pair<int,int> curr, pair<int,int> next){
    if(next.first >= base.width() || next.second >= base.height() || next.first < 0 || next.second < 0){
        return false;
    } else if (v[next.first][next.second] == true){
        return false;
    } else {
        RGBAPixel *p_next = maze.getPixel(next.first,next.second);
        dis = d[curr.second][curr.first];
        return compare(p_next, dis);
    }
}

vector<pair<int,int>> decoder::neighbors(pair<int,int> curr) {

    vector<pair<int,int>> n;
    int x = curr.first;
    int y = curr.second;
    n.push_back(pair<int,int>(x-1,y));
    n.push_back(pair<int,int>(x,y+1));
    n.push_back(pair<int,int>(x+1,y));
    n.push_back(pair<int,int>(x,y-1));

    return n;

}


bool decoder::compare(RGBAPixel p, int d){
    vector<int> bin_r = treasureMap.ten_2(p.r,6);
    vector<int> bin_g = treasureMap.ten_2(p.g,6);
    vector<int> bin_b = treasureMap.ten_2(p.b,6);

    vector<int> final;
    final.push_back(bin_r[4]);
    final.push_back(bin_r[5]);
    final.push_back(bin_g[4]);
    final.push_back(bin_g[5]);
    final.push_back(bin_b[4]);
    final.push_back(bin_b[5]);

    int final_i = treasureMap.two_10(final);
    if(final_i == 0 && d == 63){
        return true;
    }else{
        return(final_i == d+1);
    }
}
