class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for(int i = 0; i < position.size(); i++) { //O(n)
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend()); //O(nlogn)

        int fleets = 0;
        double lastTime = 0;
        
        for(auto &car: cars) { //O(n)
            double time = (double)(target - car.first) / car.second;
            
            if(time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }
        return fleets; //T.C: O(nlogn), S.C: O(n)
    }
};
