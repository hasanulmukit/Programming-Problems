def activity_selection(activities):
    # Sort activities based on their end time
    activities.sort(key=lambda x: x[1])

    print("Selected activities (start, end):")
    last_end = 0
    for start, end in activities:
        if start >= last_end:
            print(f"({start}, {end})")
            last_end = end

if __name__ == "__main__":
    n = int(input("Enter the number of activities: "))
    activities = []

    print("Enter start and end times of activities:")
    for i in range(n):
        start, end = map(int, input(f"Activity {i + 1}: ").split())
        activities.append((start, end))

    activity_selection(activities)
