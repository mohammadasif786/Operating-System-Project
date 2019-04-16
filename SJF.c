#include<stdio.h>
#include<conio.h>
 
void main()
{
    int brst_time[10],Process[10],wait_time[10],ta_time[10];
	int i,j,n,total=0,position,temp;
    float avg_wait_time,avg_ta_time;
    printf("Enter number of Processes:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
    	printf("Process %d:",i+1);
        //printf("p%d:",i+1);
        scanf("%d",&brst_time[i]);
        Process[i] = i+1;
        //p[i]=i+1;
		//printf("Student\n",p[i]);          //contains process number
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        position = i;
        for(j=i+1;j<n;j++)
        {
            if(brst_time[j]<brst_time[position])
                position = j;
        }
 
        temp = brst_time[i];
        brst_time[i] = brst_time[position];
        brst_time[position] = temp;
 
        temp = Process[i];
        Process[i] = Process[position];
        Process[position] = temp;
    }
 
    wait_time[0] = 0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wait_time[i] = 0;
        for(j=0;j<i;j++)
            wait_time[i]+=brst_time[j];
 
        total += wait_time[i];
    }
 
    avg_wait_time = (float)total/n;      //average waiting time
    total = 0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        ta_time[i] = brst_time[i]+wait_time[i];     //calculate turnaround time
        total += ta_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",Process[i],brst_time[i],wait_time[i],ta_time[i]);
    }
 
    avg_ta_time = (float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wait_time);
    printf("\nAverage Turnaround Time=%f\n",avg_ta_time);
    getch();
}
