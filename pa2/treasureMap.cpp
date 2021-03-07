#include "treasureMap.h"
#include "queue.h"
using namespace std;

treasureMap::treasureMap(const PNG & baseim, const PNG & mazeim, pair<int,int> s)
{

/* YOUR CODE HERE */

}

void treasureMap::setGrey(PNG & im, pair<int,int> loc){

/* YOUR CODE HERE */

}

void treasureMap::setLOB(PNG & im, pair<int,int> loc, int d){

/* YOUR CODE HERE */

}

PNG treasureMap::renderMap(){

	PNG copy = base;
	vector<vector<boolean>> visit(copy.width(), vector<boolean> (copy.height(), false));
	vector<vector<int>> distance(copy.width(), vector<int> (copy.height()));
	queue<pair<int, int>> locations;

	visit[start.first][start.second] = true;
	distance[start.first][start.second] = 0;
	setLOB(copy, start, 0);
	locations.enqueue(start);

	while(!location.isEmpty()) {
		pair<int, int> curr = locations.peek();
		vector<pair<int,int>> neighbor = neighbors(curr);
		locations.dequeue();
		for(int i = 0; i < 4; i++){
			if(good(visit, curr, neighbor[i])){
				visit[neighbor[i].first][neighbor[i].second] = true;
				distance[neighbor[i].first][neighbor[i].second] = distance[curr.first][curr.second] + 1;
				setLOB(copy, neighbor[i], distance[neighbor[i].first][neighbor[i].second]);
				locations.enqueue(neighbor[i]);
			}
		}
	}

	return copy;
	
}


PNG treasureMap::renderMaze(){

	PNG copy = base;
	vector<vector<boolean>> visit(copy.width(), vector<boolean> (copy.height(), false));
	vector<vector<int>> distance(copy.width(), vector<int> (copy.height()));
	queue<pair<int, int>> locations;

	for(int i = start.first-3; i =< start.first+3; i++){
		if(i>=0 && i < copy.width()){
			for(int j = start.second-3; j =< start.second+3; j++){
				if(j>=0 && j < copy.height()){
					copy.getPixel(i, j) = new RGBAPixel(255, 0, 0);
				}
			}
		}
	}

	visit[start.first][start.second] = true;
	distance[start.first][start.second] = 0;
	locations.enqueue(start);

	while(!location.isEmpty()) {
		pair<int, int> curr = locations.peek();
		vector<pair<int,int>> neighbor = neighbors(curr);
		locations.dequeue();
		for(int i = 0; i < 4; i++){
			if(neighbor[i]){
				visit[neighbor[i].first][neighbor[i].second] = true;
				distance[neighbor[i].first][neighbor[i].second] = distance[curr.first][curr.second] + 1;
				setGrey(copy, neighbor[i]);
				locations.enqueue(neighbor[i]);
			}
		}
	}

	return copy;

}

bool treasureMap::good(vector<vector<bool>> & v, pair<int,int> curr, pair<int,int> next){

/* YOUR CODE HERE */

}

vector<pair<int,int>> treasureMap::neighbors(pair<int,int> curr) {

/* YOUR CODE HERE */

}

