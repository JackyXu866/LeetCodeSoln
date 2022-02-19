class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int8_t, int8_t> pos(0, 0);
        int8_t dir = 0;    //0->N 1->W 2->S 3->E
        
        for(const char& c : instructions){
            switch (c){
                case 'G':
                    move(pos, dir);
                    break;
                case 'L':
                    dir = (dir + 1)%4;
                    break;
                case 'R':
                    dir = (dir + 3)%4;
                    break;
            }
            
        }
          
        if( (pos.first == 0 && pos.second == 0) || dir != 0) return true;
        return false;
                
    }
    
    void move(pair<int8_t, int8_t>& pos, int8_t dir){
        switch(dir){
            case 0:
                pos.second++;
                break;
            case 1:
                pos.first--;
                break;
            case 2:
                pos.second--;
                break;
            case 3:
                pos.first++;
                break;
        }
        // cout << dir << ": " << pos.first << ", " << pos.second << endl;
    }
};
