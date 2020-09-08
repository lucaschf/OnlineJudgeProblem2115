#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int startTime;
    int processingTime;
} Task;

int comparator(const void *a, const void *b) {
    Task *task = (Task *) a;
    Task *another = (Task *) b;

    if (task->startTime > another->startTime) {
        return 1;
    }

    if (task->startTime < another->startTime)
        return -1;

    return (task->startTime - another->startTime);
}

int main(int argc, char *argv[]) {
    int n;

    scanf("%d", &n);

    if (n <= 0) {
        return 1;
    }

    int time;
    int i;

    while (n != 0) {
        time = 0;
        Task tasks[n];

        for (i = 0; i < n; i++) {
            scanf("%d %d", &tasks[i].startTime, &tasks[i].processingTime);
        }

        qsort(tasks, n, sizeof(Task), comparator);

        for (i = 0; i < n; i++)
            if (time >= tasks[i].startTime) {
                time += tasks[i].processingTime;
            } else {
                time = tasks[i].startTime + tasks[i].processingTime;
            }

        printf("%d\n", time);
        n = 0;

        scanf("%d", &n);
    }

    return 0;
}
