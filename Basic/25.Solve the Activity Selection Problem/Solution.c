#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->end - activityB->end;
}

void activitySelection(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);

    printf("Selected activities (start, end):\n");
    int lastEnd = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            printf("(%d, %d)\n", activities[i].start, activities[i].end);
            lastEnd = activities[i].end;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity activities[n];
    printf("Enter start and end times of activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }

    activitySelection(activities, n);

    return 0;
}
