class Robot {
public:
    bool moved;
    vector<vector<int>> pos; // (x, y, dir) 0 -> East, 1 -> North, 2 -> West, 3 -> South
    int idx = 0;

    Robot(int width, int height) {
        moved = false;

        // set for east
        for(int x = 0; x < width; x++) pos.push_back({x, 0, 0});

        // set for north
        for(int y = 1; y < height; y++) pos.push_back({width-1, y, 1});

        // set for west
        for(int x = width-2; x >= 0; x--) pos.push_back({x, height-1, 2});

        // set for south
        for(int y = height-2; y >= 1; y--) pos.push_back({0, y, 3});

        pos[0][2] = 3;
    }
    
    void step(int num) {
        if(!moved) moved = true;

        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }
    
    string getDir() {
        // edge case when robot is not moved it's direct is 'E'
        if(!moved) return "East";

        int dir = pos[idx][2];
        if(dir == 0) return "East";
        else if(dir == 1) return "North";
        else if(dir == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */