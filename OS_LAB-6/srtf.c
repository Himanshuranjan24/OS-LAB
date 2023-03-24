/*c program for srtf scheduling.*/
#include <stdio.h>
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};
void srtf_scheduling(struct process p[], int n) {
    int i, current_time = 0, completed_jobs = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    while(completed_jobs < n) {
        int shortest_job = -1, shortest_time = __INT_MAX__;
        for(i=0; i<n; i++) {
            if(p[i].arrival_time <= current_time && p[i].remaining_time < shortest_time && p[i].remaining_time > 0) {
                shortest_job = i;
                shortest_time = p[i].remaining_time;
            }
        }
        if(shortest_job == -1) {
            current_time++;
            continue;
        }
        struct process *job = &p[shortest_job];
        job->waiting_time += current_time - job->arrival_time;
        current_time++;
        job->remaining_time--;
        if(job->remaining_time == 0) {
            job->turnaround_time = current_time - job->arrival_time;
            avg_waiting_time += job->waiting_time;
            avg_turnaround_time += job->turnaround_time;
            completed_jobs++;
            printf("Process %d: waiting time=%d, turnaround time=%d\n", job->pid, job->waiting_time, job->turnaround_time);
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
    int i;
    for(i=0; i<n; i++) {
        p[i].remaining_time = p[i].burst_time;
    }
    srtf_scheduling(p, n);
    return 0;
}
