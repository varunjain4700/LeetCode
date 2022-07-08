class Solution
{
    public:
        int carFleet(int target, vector<int> &position, vector<int> &speed)
        {
            int n = position.size();
            vector<pair<int, double>> pos;
            for (int i = 0; i < n; i++)
            {
                double time_taken = (double)(target - position[i]) / speed[i];
                pos.push_back({ position[i],
                    time_taken });
            }
            sort(pos.begin(), pos.end());	//sorting cars by their initial position(cars closer to target will be processed first)
            int car_fleets = 1;
            double slowest_car_time = pos[n - 1].second;
            for (int i = n - 2; i >= 0; i--)
            {
                if (pos[i].second > slowest_car_time)	//if current car takes more time to reach target than the slowest car in front of it,then it can't meet it anyway
                {
                    slowest_car_time = pos[i].second;
                    car_fleets++;
                }
            }
            return car_fleets;
        }
};