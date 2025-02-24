import java.util.*;

class Activity {
    int start, end;

    Activity(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

public class ActivitySelection {

    public static void activitySelection(List<Activity> activities) {
        activities.sort(Comparator.comparingInt(a -> a.end));

        System.out.println("Selected activities (start, end):");
        int lastEnd = 0;
        for (Activity activity : activities) {
            if (activity.start >= lastEnd) {
                System.out.println("(" + activity.start + ", " + activity.end + ")");
                lastEnd = activity.end;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of activities: ");
        int n = sc.nextInt();

        List<Activity> activities = new ArrayList<>();
        System.out.println("Enter start and end times of activities:");
        for (int i = 0; i < n; i++) {
            System.out.print("Activity " + (i + 1) + ": ");
            int start = sc.nextInt();
            int end = sc.nextInt();
            activities.add(new Activity(start, end));
        }

        activitySelection(activities);
    }
}
