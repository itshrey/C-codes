#include<iostream>
#include<queue>
# define MAX 1000001
using namespace std;
int n;
void Enter_process(int *at,int *bt){
    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<":"<<endl;
        cout<<"Enter Arrival Time:";cin>>at[i];
        cout<<"Enter Burst Time:";cin>>bt[i];
    }
}

void avg_wt_tt(int *wt,int *tt){
    float w=0,t=0;
    for(int i=0;i<n;i++){
        w+=wt[i];
        t+=tt[i];
    }
    cout<<"Avg Waiting Time:"<<w/n<<endl;
    cout<<"Avg Turnaround Time:"<<t/n<<endl;
}

void FCFS(int *at,int *bt,bool *complete){
    int wt[n],ct[n],tt[n],time=0,p=0;
    while(p!=n){
        int min=-1,min_val=MAX;

        for(int i=0;i<n;i++){
            if(at[i]<=time && complete[i]!=1 && at[i]<min_val){
                min=i;
                min_val=at[min];
            }
        }

        if(min==-1)
            time++;
        else{
            wt[min]=time-at[min];
            time+=bt[min];
            ct[min]=time;
            tt[min]=ct[min]-at[min];
            complete[min]=true;
            p++;
        }
        
    }
    avg_wt_tt(wt,tt);
}

void SJF(int *at,int *bt,bool *complete){
    int wt[n],tt[n],ct[n],time=0,p=0,b[n];

    while(p!=n){

        int min=-1,min_val=MAX;
        for(int i=0;i<n;i++){
            if(at[i]<=time && complete[i]!=1 && bt[i]<min_val){
                min=i;
                min_val=bt[i];
            }
        }

        if(min==-1)
            time++;
        else{
            wt[min]=time-at[min];
            time+=bt[min];
            ct[min]=time;
            tt[min]=ct[min]-at[min];
            complete[min]=true;
            p++;
        }

    }
    avg_wt_tt(wt,tt);
}

void SRTF(int *at,int *bt,bool *complete){
    int time=0,p=0,wt[n],ct[n],tt[n],b[n];

    for(int i=0;i<n;i++){
            b[i]=bt[i];
        }
    while(p!=n){

        int min=-1,min_val=MAX;

        for(int i=0;i<n;i++){
            if(at[i]<=time && !complete[i] && bt[i]<min_val){
                min=i;
                min_val=bt[i];
            }
        }

        if(min==-1){
            time++;
        }
        else{
            time++;
            bt[min]--;
            if(bt[min]==0){
                ct[min]=time;
                tt[min]=ct[min]-at[min];
                wt[min]=tt[min]-b[min];
                complete[min]=true;
                p++;
            }
        }
    }

    avg_wt_tt(wt,tt);
}

void RoundRobin(int*at,int*bt,bool *complete,int qu){
    int time=0,p=0,wt[n]={0},tt[n]={0},ct[n]={0},b[n]={0};
    queue<int>q;

    for(int i=0;i<n;i++){
        b[i]=bt[i];
    }

    while(p!=n){
        for(int i=0;i<n;i++){
            if(at[i]<=time && !complete[i] && bt[i]>0){
                q.push(i);
            }
        }
        if(q.empty())
            time++;
        else{
            int x=q.front();
            q.pop();
            if(bt[x]>qu){
                time+=qu;
                bt[x]-=qu;
            }
            else {
                time+=bt[x];
                bt[x]=0;
            }
            if(bt[x]==0){
                    ct[x]=time;
                    tt[x]=ct[x]-at[x];
                    wt[x]=tt[x]-b[x];
                    complete[x]=true;
                    p++;
                }
            else
                q.push(x);
        }
    }
    avg_wt_tt(wt,tt);
}


int main(){
    cout<<"Enter No of processes:";cin>>n;
    int at[n],bt[n];
    bool complete[n]={0};
    Enter_process(at,bt);
    int a;
    cout<<"Select Algo:\n1.FCFS\n2.SJF\n3.SRTF\n4.RoundRobin\n";cin>>a;
    if(a==1)
        FCFS(at,bt,complete);
    else if(a==2)
        SJF(at,bt,complete);
    else if(a==3)
        SRTF(at,bt,complete);
    else if(a==4){
        int qu;
        cout<<"Enter Quantum:";cin>>qu;
        RoundRobin(at,bt,complete,qu);
    }
    else
        cout<<"Invalid Input";
}