#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>
#include <set>
using namespace std;



const int N = 1, S = 2, E = 4, W = 8;
const unordered_map<int,int> DX = {{N,0},{S,0},{E,1},{W,-1}};
const unordered_map<int,int> DY = {{N,-1},{S,1},{E,0},{W,0}};
const unordered_map<int,int> Opposites = {{N,S},{S,N},{E,W},{W,E}};

void drawGrid(int width, int height, vector<vector<int>>& grid) {
    int num = 0;
    cout << " " << string(width * 2 - 1, '_') << endl;
    for (int y = 0; y < height; ++y) {
        cout << "|";
        for (int x = 0; x < width; ++x) {
            
            cout << num;
            if (num < 10) {
                cout << " ";
            }
            if ((grid[y][x] & S) != 0) {
                cout << " ";
            } else {
                cout << "_";
            }
            if ((grid[y][x] & E) != 0) {
                if (x + 1 < width && ((grid[y][x] | grid[y][x+1]) & S) != 0) {
                    cout << " ";
                } else {
                    cout << "_";
                }
            } else {
                cout << "|";
            }
            num++; 
        }
        cout << endl;
    }
}




void carve(int cx, int cy, vector<vector<int>>& grid) {
    vector<int> directions = {N, S, E, W};
    random_device rd;
    shuffle(directions.begin(), directions.end(), default_random_engine(rd()));
    // cout << "Carving from (" << cx << ", " << cy << ")" << endl;

    for (auto dir : directions) {
        int nx = cx + DX.at(dir);
        int ny = cy + DY.at(dir);
        if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[ny].size() && grid[ny][nx] == 0) {
            // cout << "  Moving to (" << nx << ", " << ny << ") in direction " << dir << endl;
            grid[cy][cx] |= dir;
            grid[ny][nx] |= Opposites.at(dir);
            carve(nx, ny, grid);
        }
    }

    // cout << "Backtracking from (" << cx << ", " << cy << ")" << endl;
}


vector<vector<int>> maze_to_graph(vector<vector<int>> maze){
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> adj(m*n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int curr = maze[i][j];
            if((curr&N)==N){
                adj[n*i + j].push_back(n*(i-1)+j);
            }
            if((curr&S)==S){
                adj[n*i + j].push_back(n*(i+1)+j);
            }
            if((curr&E)==E){
                adj[n*i + j].push_back(n*i+j+1);
            }
            if((curr&W)==W){
                adj[n*i + j].push_back(n*i+j-1);
            }
        }
    }
    return adj;
}



vector<int> bfs(vector<vector<int>> adjmat,int start){
    vector<bool> visited(adjmat.size(),false);
    vector<int> ans;
    queue<int> q;
    q.push(start);
    int curr=start;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int i=0;i<adjmat[curr].size();i++){
            if(!visited[adjmat[curr][i]]){
                q.push(adjmat[curr][i]);
                visited[adjmat[curr][i]] = true;
            }
        }
    }
    return ans;

}


int main(){
    vector<vector<int>> myGrid(10,vector<int>(10,0));
    carve(0,0,myGrid);
    vector<vector<int>> adjans = maze_to_graph(myGrid);
    // for (int i = 0; i < adjans.size(); i++) {
    //     for (int j = 0; j < adjans[i].size(); j++) {
    //         cout << adjans[i][j] << " ";    
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < myGrid.size(); i++) {
    //     for (int j = 0; j < myGrid[i].size(); j++) {
    //         cout << myGrid[i][j] << " ";    
    //     }
    //     cout << endl;
    // }
    cout<<"\nMaze"<<endl;

    drawGrid(10,10,myGrid);

    vector<int> sol = bfs(adjans,0);
    cout<<"\nSolution"<<endl;
    for(int i=0;i<sol.size();i++){
        cout<<" -> "<<sol[i];
    }
    // set<int> mySet(sol.begin(),sol.end());
    // cout<<endl;
    // cout<<"set size "<<mySet.size();
    return 0;
}
