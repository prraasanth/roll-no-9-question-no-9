#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h> 
int main() 
{   

{
  
      int w, limit, total = 0, x, counter = 0, time_quantum,j; 
      
      int wait_time = 0, turnaround_time = 0,pos,z,p[10],prio[10], a_time[10], b_time[10], temp[10],b; 
      
      float average_wait_time, average_turnaround_time;
      
      printf("\n Enter Number of Processes:"); 
      
      scanf("%d", &limit); 
      
      x = limit; 
      for(w = 0; w < limit; w++) 
      {
        p[w]=w+1;
       
        prio[w]=0;
            printf("\n Enter the Details of Process[%d]\n", w + 1);
            printf("Arrival Time:\t");
            scanf("%d", &a_time[w]);
            printf("Burst Time:\t");
            scanf("%d", &b_time[w]); 
            temp[w] = b_time[w];
      }
       
      printf( "\n Enter the Time Quantum:" ) ; 
      scanf ("%d", &time_quantum ) ; 
      printf( "\n Process ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n" ) ;
      for( total = 0, w = 0; x != 0 ; ) 
      { 
 
            for(z=0;z<limit;z++)
            {
            int temp1;
            pos=z;
            for(j=z+1;j<limit;j++)
            {
                if(prio[j]<prio[pos])
                pos=j;
            }
         
        temp1=prio[z];
    
        prio[z]=prio[pos];
    
        prio[pos]=temp1;
         
            temp1=b_time[z];
            b_time[z]=b_time[pos];
            b_time[pos]=temp1;
                    temp1=a_time[z];
                a_time[z]=a_time[pos];
            a_time[pos]=temp1;
 
            temp1=p[z];
                p[z]=p[pos];
            p[pos]=temp1;
 
            temp1=temp[z];
                temp[z]=temp[pos];
            temp[pos]=temp1;
            }
            
            if(temp[w] <= time_quantum && temp[w] > 0) 
            { 
                  total = total + temp[w]; 
                  temp[w] = 0; 
                  counter = 1; 
            } 
            
            else if(temp[w] > 0) 
            { 
                  temp[w] = temp[w] - time_quantum; 
                  total = total + time_quantum; 
            } 
 
    for(b=0;b<limit;b++)
        {
            if(b==w)
            prio[b]+=1;
            else
            prio[b]+=2;
        }
 
            if(temp[w] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[w], b_time[w], total - a_time[w], total - a_time[w] - b_time[w],prio[w]);
                  wait_time = wait_time + total - a_time[w] - b_time[w]; 
                  turnaround_time = turnaround_time + total - a_time[w]; 
                  counter = 0; 
            } 
            if(w == limit - 1) 
            {
                  w = 0; 
            
            }
            else if(a_time[w + 1] <= total) 
            {
                  w++;
            
            }
            else 
            {
                  w = 0;
            
            }
			       
      } 
      return 0; 
      
}

}
