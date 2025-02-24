#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

void activitySelection(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities (start, end):" << endl;
    int lastEnd = 0;
    for (auto &activity : activities) {
        if (activity.start >= lastEnd) {
            cout << "(" << activity.start << ", " << activity.end << ")" << endl;
            lastEnd = activity.end;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter start and end times of activities:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].end;
    }

    activitySelection(activities);

    return 0;
}
