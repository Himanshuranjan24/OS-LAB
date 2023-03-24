/*c program for rr scheduling.*/
#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

void rr_scheduling(struct process p[], int n, int quantum) {
    int i, current_time = 0, completed_jobs = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    while(completed_jobs < n) {
        for(i=0; i<n; i++) {
            if(p[i].arrival_time <= current_time && p[i].remaining_time > 0) {
                if(p[i].remaining_time <= quantum) {
                    current_time += p[i].remaining_time;
                    p[i].turnaround_time = current_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    avg_waiting_time += p[i].waiting_time;
                    avg_turnaround_time += p[i].turnaround_time;
                    p[i].remaining_time = 0;
                    completed_jobs++;
                }
                else {
                    current_time += quantum;
                    p[i].remaining_time -= quantum;
                }
            }
        }
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Average waiting time: %f\n", avg_waiting_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);
}

int main() {
    struct process p[] = {{1, 0, 10}, {2, 5, 5}, {3, 6, 2}};
    int n = sizeof(p)/sizeof(p[0]);
    int quantum = 2;
    int i;
    for(i=0; i<n; i++) {
        p[i].remaining_time = p[i].burst_time;
    }
    rr_scheduling(p, n, quantum);
    return 0;
}
