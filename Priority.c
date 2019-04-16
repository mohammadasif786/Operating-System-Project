#include<stdio.h>
#include<conio.h>
 
int main()
{
    int brst_time[10],p[10],wait_time[10],ta_time[10],no_g[10];
	int i,j,n,total=0,position,temp,avg_wait_time,avg_ta_time;
    printf("Enter Total Number of Students : ");
    scanf("%d",&n);
 
    //printf("\nEnter Burst Time \n");
    //printf("Enter The Number of Gifts\n");
    for(i=0;i<n;i++)
    {
        printf("\nStudent %d\n",i+1);
        printf("Enter Burst Time :");
        scanf("%d",&brst_time[i]);
        printf("Enter No. of Gifts : ");
        scanf("%d",&no_g[i]);
        p[i] = i+1;                      //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        position = i;
        for(j=i+1;j<n;j++)
        {
            if(no_g[j]<no_g[position])
                position = j;
        }
 
        temp = no_g[i];
        no_g[i] = no_g[position];
        no_g[position] = temp;
 
        temp = brst_time[i];
        brst_time[i] = brst_time[position];
        brst_time[position] = temp;
 
        temp = p[i];
        p[i] = p[position];
        p[position] = temp;
    }
 
    wait_time[0] = 0;	                     //waiting time for first process is zero
 
    
    for(i=1;i<n;i++)                     //calculate waiting time
    {
        wait_time[i] = 0;
        for(j=0;j<i;j++)
            wait_time[i] += brst_time[j];
 
        total += wait_time[i];
    }
 
    avg_wait_time = total/n;              //average waiting time
    total = 0;
 
    printf("\nStudent\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        ta_time[i] = brst_time[i] + wait_time[i];      //calculate turnaround time
        total += ta_time[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],brst_time[i],wait_time[i],ta_time[i]);
    }
 
    avg_ta_time=total/n;                //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wait_time);
    printf("\nAverage Turnaround Time=%d\n",avg_ta_time);
 	getch();
	return 0;
}
