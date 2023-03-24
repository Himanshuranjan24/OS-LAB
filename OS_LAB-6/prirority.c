/*c program for priority based scheduling.*/
#include<stdio.h>
struct process {
    int pid;
    int burst_time;
    int priority;
};
void swap(struct process *a, struct process *b) {
    struct process temp = *a;
    *a = *b;
    *b = temp;
}
void sort_by_priority(struct process p[], int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority < p[j].priority) {
                swap(&p[i], &p[j]);
            }
        }
    }
}
void priority_scheduling(struct process p[], int n) {
    sort_by_priority(p, n);
    int i, j;
    int waiting_time = 0;
    int turnaround_time = 0;
    for(i=0; i<n; i++) {
        waiting_time += turnaround_time;
        turnaround_time += p[i].burst_time;
        printf("Process %d: waiting time=%d, turnaround time=%d\n", p[i].pid, waiting_time, turnaround_time);
    }
}
int main() {
    struct process p[] = {{1, 10, 3}, {2, 5, 1}, {3, 8, 2}};
    int n = sizeof(p)/sizeof(p[0]);
    priority_scheduling(p, n);
    return 0;
}
