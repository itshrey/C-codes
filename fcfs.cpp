#include <stdio.h>
void swap(int* a, int* b){
 int temp = *a;
 *a = *b;
 *b = temp;
}
void sort(int p[], int at[], int bt[], int size){
 for(int i=0; i<size; i++){
 for(int j=0; j<size-i-1; j++){
 if(at[j]>at[j+1]){
 swap(&at[j], &at[j+1]);
 swap(&bt[j], &bt[j+1]);
 swap(&p[j], &p[j+1]);
 }
 }
 }
}
double sum(int arr[], int size){
 double sum=0;
 for(int k=0; k<size; k++)
 sum+=arr[k];
 return sum;
}
int main(){
 int N;
 printf("Enter no of processes: ");
 scanf("%d", &N);
 //input
 int at[N], bt[N], p[N], wait[N], tat[N], ct[N], idle_time=0;
 for(int i=0; i<N; i++){
 printf("Enter arrival and burst time for process %d\n", i+1);
 scanf("%d\n%d", &at[i], &bt[i]);
 p[i] = i+1;
 }
 sort(p, at, bt, N);

 //fcfs
 wait[0] = 0;
 ct[0] = at[0] + bt[0];

 for(int i=0; i<N; i++){
 idle_time=0;
 wait[i] = ct[i] - bt[i] - at[i];
 if(at[i+1] > ct[i]) idle_time += at[i+1] - ct[i];
 ct[i+1] = ct[i] + bt[i+1] + idle_time;
 tat[i] = wait[i] + bt[i];
 }
 //display
 printf("\nProcess\tArrival\tBurst\tWait\tTAT\n");
 for(int i=0; i<N; i++)
 printf("%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wait[i], tat[i]);
 printf("\nAvg wait time: %f", sum(wait, N)/N);
 printf("\nAvg turn around time: %f\n", sum(tat, N)/N);} 
