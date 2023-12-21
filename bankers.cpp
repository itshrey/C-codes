#include <stdio.h>
#include <stdbool.h>
int main(){
bool flag = true, end = false;
int P, R, k = 0;
printf("Enter no of processes, resources: ");
scanf("%d%d", &P, &R);
int ss[P], av[R], max[P][R], alloc[P][R], need[P][R];
bool finished[100] = { false };
printf("Enter no of resources available: ");
for (int k = 0; k < R; k++) {
scanf("%d", &av[k]);
}
for (int i = 0; i < P; i++) {
printf("Enter max no of resources reqd by proc %d: ", i+1);
for (int j = 0; j < R; j++) {
scanf("%d", &max[i][j]);
}
printf("Enter no of resources allocated to proc %d: ", i+1);
for (int j = 0; j < R; j++) {
scanf("%d", &alloc[i][j]);
need[i][j] = max[i][j] - alloc[i][j];
}
}
while (!end) {
for (int i = 0; i < P; i++) {
if (av[0] >= *need[i] && finished[i] == false) {
for (int j = 1; j < R; j++) {
if (need[i][j] > av[j]) {
flag = false;
}
}
if (flag) {
for (int j = 0; j < R; j++) {
av[j] += alloc[i][j];
}
ss[k] = i+1;
k++;
finished[i] = true;
}
end = true;
for (int i = 0; i < P; i++) {
if (finished[i] == false) {
end = false;
}
}
}
}
}
printf("\nSafety sequence: < ");
for (int i = 0; i < P; i++) {
printf("%d ", ss[i]);
}
printf(">\n");
}

