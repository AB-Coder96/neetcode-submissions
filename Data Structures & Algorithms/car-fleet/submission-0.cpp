class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size();
        if (n == 0) return 0;

        // Pair each car's position with its independent time-to-target
        // time = (target - position) / speed
        std::vector<std::pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            double time_to_target = static_cast<double>(target - position[i]) / speed[i];
            cars[i] = {position[i], time_to_target};
        }
        // Sort cars by position in ascending order (from furthest to closest to target)
        std::sort(cars.begin(), cars.end());

        // Monotonic stack to hold the arrival times of the fleet leaders
        std::stack<double> fleet_times;

        // Process from right to left (from the car closest to the target back to the furthest)
        // This naturally sets the front car's speed/time as the bottleneck barrier
        for (int i = n - 1; i >= 0; --i) {
            double current_car_time = cars[i].second;

            // If the stack is empty, this car is currently the leading bottleneck
            if (fleet_times.empty()) {
                fleet_times.push(current_car_time);
            } 
            // If the trailing car takes LONGER than the leader in front of it,
            // it can never catch up. It forms a brand new fleet behind.
            else if (current_car_time > fleet_times.top()) {
                fleet_times.push(current_car_time);
            }
            // If the trailing car takes LESS or EQUAL time, it collides, slows down, 
            // and collapses into the existing front fleet. We don't push it.
        }

        // The number of remaining elements in the stack represents the total distinct fleets
        return fleet_times.size();
    }
};
