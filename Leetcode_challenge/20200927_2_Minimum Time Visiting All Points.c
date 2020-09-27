// Minimum Time Visiting All Points (easy)
// Runtime: 8 ms, faster than 84.35% of C online submissions for Minimum Time Visiting All Points.
// Memory Usage: 6.5 MB, less than 5.44% of C online submissions for Minimum Time Visiting All Points.



int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int second = 0;
    int x = points[0][0];
    int y = points[0][1];
    for (int i = 1; i < pointsSize; i++){
        second += abs(x - points[i][0]) + abs(y - points[i][1]) - fmin(abs(x - points[i][0]),abs(y - points[i][1]));
        x = points[i][0];
        y = points[i][1];
    }
    return second;
}