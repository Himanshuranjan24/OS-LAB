/*c program for fcfs scheduling.*/
#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
void fcfs_scheduling(struct process p[], int n) {
    int i;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int current_time = 0;
    for(i=0; i<n; i++) {
        if(p[i].arrival_time > current_time) {
            current_time = p[i].arrival_time;
        }
        p[i].waiting_time = current_time - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        current_time += p[i].burst_time;
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
        printf("Process %d: waiting time=%d, turnaround time=%d\n", p[i].pid, p[i].waiting_time, p[i].turnaround_time);
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Average waiting time: %f\n", avg_waiting_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);
}
int main() {
    struct process p[] = {{1, 0, 10}, {2, 5, 5}, {3, 6, 2}};
    int n = sizeof(p)/sizeof(p[0]);
    fcfs_scheduling(p, n);
    return 0;
}
