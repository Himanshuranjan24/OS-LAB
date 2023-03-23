/*c program for sjf scheduling.*/
#include <stdio.h>

int main() {
   int n, bt[20], wt[20], tat[20], p[20], i, j, temp;

   printf("Enter the number of processes: ");
   scanf("%d", &n);

   printf("Enter the burst time for each process:\n");
   for(i = 0; i < n; i++) {
      printf("Process %d: ", i+1);
      scanf("%d", &bt[i]);
      p[i] = i+1; 
   }
   for(i = 0; i < n-1; i++) {
      for(j = i+1; j < n; j++) {
         if(bt[i] > bt[j]) {
            temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
         }
      }
   }
   wt[0] = 0; 
   for(i = 1; i < n; i++) {
      wt[i] = 0;
      for(j = 0; j < i; j++)
         wt[i] += bt[j];
   }
   for(i = 0; i < n; i++)
      tat[i] = bt[i] + wt[i];
   float avg_wt = 0, avg_tat = 0;
   for(i = 0; i < n; i++) {
      avg_wt += wt[i];
      avg_tat += tat[i];
   }
   avg_wt /= n;
   avg_tat /= n;

   printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
   for(i = 0; i < n; i++)
      printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
   printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f", avg_wt, avg_tat);

   return 0;
}
