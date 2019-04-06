#include<stdio.h>
#include<conio.h>  
#include<stdlib.h>

int main() 
{
	system("color 90"); 
	printf("\n\n\n\n\n\t\t\t\t\t\tWelcome\n\n\n\n\n");
	printf("\n\t\t\t\t**Operating System Stimulation Based Project**\n\n\n");
	int wait_time = 0, turnaround_time = 0,pos,y,p[20],prio[20], a_time[20], b_time[20], temp[20],b; 
	  
	int i, requirement, total = 0, x, ani = 0, time_slice,j; 
      
	float average_wait_time, average_turnaround_time;
      
    printf("\nEnter total Number of Processes:\n"); 
      
    scanf("%d", &requirement); 
      
	x = requirement; 
    for(i = 0; i < requirement; i++) 
    {
	    p[i]=i+1;
	   
	    prio[i]=0;
            printf("\n\t\t\tEnter Details of Process[%d] ...\n", i + 1);
            printf("\nArrival Time of process:\n");
            scanf("%d", &a_time[i]);
            printf("Burst Time of process:\n");
            scanf("%d", &b_time[i]); 
            temp[i] = b_time[i];
    }
	   
      printf("\nEnter the Time Slice for Each Process (... Time Quantum ...):\n"); 
      scanf("%d", &time_slice); 
      printf("\n\tProcess ID\t|\tBurst Time\t|\tTurnaround Time\t|\tWaiting Time\t|\tPriority\n");
      for(total = 0, i = 0; x != 0;) 
      { 

		    for(y=0;y<requirement;y++)
		    {
			int temp1;
			pos=y;
			for(j=y+1;j<requirement;j++)
			{
			    if(prio[j]<prio[pos])
				pos=j;
			}
		 
		temp1=prio[y];
	
		prio[y]=prio[pos];
	
		prio[pos]=temp1;
		 
			temp1=b_time[y];
			b_time[y]=b_time[pos];
			b_time[pos]=temp1;
		 			temp1=a_time[y];
				a_time[y]=a_time[pos];
			a_time[pos]=temp1;

			temp1=p[y];
				p[y]=p[pos];
			p[pos]=temp1;

			temp1=temp[y];
				temp[y]=temp[pos];
			temp[pos]=temp1;
		    }
		{
		}
            
			if(temp[i] <= time_slice && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  ani = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_slice; 
                  total = total + time_slice; 
            } 

	for(y=0;y<requirement;y++)
		{
			if(y==i)
			prio[y]+=1;
			else
			prio[y]+=2;
		}

            if(temp[i] == 0 && ani == 1) 
            { 
                  x--; 
                  printf("\n\tProcess[%d]\t|\t%d\t\t|\t %d\t\t|\t %d\t\t|\t%d", p[i], b_time[i], total - a_time[i], total - a_time[i] - b_time[i],prio[i]);
                  wait_time = wait_time + total - a_time[i] - b_time[i]; 
                  turnaround_time = turnaround_time + total - a_time[i]; 
                  ani = 0; 
            } 
            if(i == requirement - 1) 
            {
                  i = 0; 
            
			}
            else if(a_time[i + 1] <= total) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      return 0; 
}
