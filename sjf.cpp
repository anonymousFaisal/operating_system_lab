#include<iostream>
using namespace std;

class nahid
{
public:
    int n,index, p[100], bt[100], wt[100], tat[100], total_wt=0, total_tat=0;
    float avg_wt, avg_tat;
    void input();
    void waiting_time();
    void turn_around_time();
    void average_time();
};

void nd::input()
{
    cout<<"Enter the number of process :";
    cin>>n;
    cout<<"Enter the burst times:  ";
    for(int i=0; i<n; i++)
    {
        cin>>bt[i];
        p[i]=i+1;
    }
}
void nd::waiting_time()
{
    for(int i=0; i<n; i++)
    {
        index = i;
        for(int j=i+1;j<n;j++){
            if (bt[j]<bt[index]){
                index=j;
            }
        }
        swap(bt[i], bt[index]);
        swap(p[i], p[index]);
    }
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
        total_wt+=wt[i];
    }
    avg_wt = (float)total_wt/(float)n;
}
void nd::turn_around_time()
{
    for(int i=0;i<n;i++)
    {
        tat[i] = bt[i]+wt[i];
        total_tat+=tat[i];
    }
    avg_tat= (float)total_tat/(float)n;
}
void nd::average_time()
{
    waiting_time();
    turn_around_time();
    cout<<"P \t BT \t WT \t TAT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" \t "<<bt[i]<<" \t "<<wt[i]<<" \t "<<tat[i]<<endl;
    }
    cout<<"Average Waiting Time : "<<avg_wt<<endl;
    cout<<"Average TurnAround Time : "<<avg_tat<<endl;
}

int main()
{
    nahid data;
    data.input();
    data.average_time();
    return 0;
}
