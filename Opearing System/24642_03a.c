#include <stdio.h>
int main() {
    int n = 5;

    int pid[] = {0,1,2,3,4};
    int at[]  = {0,0,0,0,6};
    int bt1[] = {5,7,6,8,5};
    int io[]  = {2,2,3,1,2};

    int pct[5];     
    int bt2[5];      
    int ct[5];       

    int time = 0;

    for(int i=0;i<n;i++){
        if(time < at[i])
            time = at[i];

        time += bt1[i];
        pct[i] = time;
        bt2[i] = bt1[i] - 2;   
    }
    for(int i=0;i<n;i++){
        int ready_time = pct[i] + io[i];

        if(time < ready_time)
            time = ready_time;

        time += bt2[i];
        ct[i] = time;
    }
    printf("\nPID\tAT\tBT1\tIO\tBT2\tPCT\tCT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt1[i],io[i],bt2[i],pct[i],ct[i]);
    }
    return 0;
}