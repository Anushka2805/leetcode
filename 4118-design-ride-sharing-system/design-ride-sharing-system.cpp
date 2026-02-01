class RideSharingSystem {
public:
    queue<int> r;
    queue<int> d;
    unordered_set<int> activeR;
    queue<int> newR;
    RideSharingSystem() {}

    void addRider(int riderId) {
        r.push(riderId);
        activeR.insert(riderId);
    }

    void addDriver(int driverId) { d.push(driverId); }

    vector<int> matchDriverWithRider() {
        // one of them or both not thre
        while (!r.empty() && activeR.count(r.front()) == 0) {
            r.pop();
        }
        if (r.empty() || d.empty()) {
            return {-1, -1};
        }
        int dId = d.front();
        int rId = r.front();
        activeR.erase(rId);
        d.pop();
        r.pop();
        return {dId, rId};
    }

    void cancelRider(int riderId) {
        // rider exist nd not matched
        activeR.erase(riderId);
        while (!r.empty()) {
            if (r.front() != riderId) {
                newR.push(r.front());
            }
            r.pop();
        }
        r = newR;
        newR = queue<int>();
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */