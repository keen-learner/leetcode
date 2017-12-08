
Question: Given a list of N points in 2D space, determine the maximum number of co-linear points.

int gcd(int n1, int n2) {
    while() {
        
    }

}



////////   (1,1)  (2,1)  (5,1)
////////   m: [1, 0] -> 1
////////      [4, 0] -> 1

int getCoLinearPoints(vector<pair<int, int>> points) {
    int n = points.size();
    if(n <=1) return n;
    unordered_map<pair<int, int>, int> m; // point to slope map
    int countOverlapPoints = 0;
    int countVerticalPoints = 0;
    int res = 0;
    int ans = INT_MIN; // final return value
    
    for(int i = 0; i<n; i++) {
        countOverlapPoints = 0;
        countVerticalPoints = 0;
        res = 0;
        for(int j = i+1; j<n; j++) {
            // case 1: points same
            if(points[i] == points[j]) {
                countOverlapPoints++;        
            }
            
            // case 2: if x coordinate is same, vertical line , Dr 0
            else if(points[i].first == points[j].first) { // x same
                countVerticalPoints++;        
            }
            
            // case 3: 
            else {
                int my = points[j].second - points[i].second;
                int mx = points[j].first - points[i].first;
                if(my == 0) {
                  m[make_pair(0, 0)]++;
                  res = max(res, m[make_pair(0, 0)]);
                  continue;  
                }
                int g = gcd(my, mx);
                my = my/g;
                mx = mx/g;
                m[make_pair(my, mx)]++;
                res = max(res, m[make_pair(my, mx)]);     
            }
            res = max(res, countVerticalPoints);
        }
        ans = max(ans, res + countOverlapPoints + 1);
        m.clear();
    }
    return ans;
}

