class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, const string& stationName, int t) {
        inTime[id] = {stationName, t};
    }
    
    void checkOut(int id, const string& stationName, int t) {
        auto& tmp = inTime[id];
        string sname = tmp.first+"->"+stationName;
        totalTime[sname].first += (t-tmp.second);
        totalTime[sname].second++;
    }
    
    double getAverageTime(const string& startStation, const string& endStation) {
        string tmp = startStation+"->"+endStation;
        return (double)totalTime[tmp].first/totalTime[tmp].second;
    }
    
private:
    unordered_map<int, pair<string, int>> inTime;       // id: {name, t}
    unordered_map<string, pair<int, int>> totalTime;    // "start->end": {total, count}
    
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
