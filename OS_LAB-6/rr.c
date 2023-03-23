/*c program for round robin scheduling. */
#include <stdio.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completed;
};

int main() {
    int n, i, j, time, quantum, total_waiting_time = 0, total_turnaround_time = 0, completed_processes = 0;
    struct process processes[MAX_PROCESSES], temp;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
    }
    
    printf("\nGantt Chart:\n");
    
    for (time = 0; completed_processes != n; ) {
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].completed == 0) {
                if (processes[i].remaining_time <= quantum) {
                    time += processes[i].remaining_time;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    processes[i].remaining_time = 0;
                    processes[i].completed = 1;
                    completed_processes++;
                    
                    printf("| P%d ", processes[i].pid);
                } else {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                    
                    printf("| P%d ", processes[i].pid);
                }
            }
        }
    }
    
    printf("|\n\n");
    
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;
    
    printf("Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].pid > processes[j].pid) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    
    printf("\nAverage waiting time: %0.2f\n", avg_waiting_time);
    printf("Average turnaround time: %0.2f\n", avg_turnaround_time);
    
    return 0;
}
