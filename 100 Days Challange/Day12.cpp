//539. Minimum Time Difference
class Solution {
public:

    int HourCOnvertedToMinutes(string time){
        int hourToMinute = stoi(time.substr(0, 2)) * 60;
        int minute = stoi(time.substr(3, 2));
        return hourToMinute + minute;
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(begin(timePoints),end(timePoints));
        timePoints.push_back(timePoints[0]);

        int res=INT_MAX, n=timePoints.size(),
            time1, time2, secondside=1440;

        for(int i =0; i<n-1;i++){
            time1=HourCOnvertedToMinutes(timePoints[i]);
            time2=HourCOnvertedToMinutes(timePoints[i+1]);
          
            res=min(res,abs(time1-time2));
          
            res=min(res,abs(time1-(secondside+time2)));
        }
    return res;

    }
};