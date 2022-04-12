#include <stdio.h>
  char id[4],x[100];
  int deadline[100],profit[100],y,i,j,k,temp,n;
  
  int minValue(int x, int y) {
  if(x < y) 
  return x;
  else
  return y;
}
main() {
	scanf("%d",&n);
	printf("enter states");
	for(i=0;i<n;i++)
	scanf(" %c",&x[i]);
    printf("enter profits");
    for(i=0;i<n;i++)
    scanf("%d",&profit[i]);
    printf("enter deadline");
    for(i=0;i<n;i++)
    scanf("%d",&deadline[i]);
  for(i = 1; i < n; i++) {
    for(j = i+1; j < n ; j++) {
      if(profit[i]<profit[j]) {
        temp = profit[i];
        profit[i] = profit[j];
        profit[j] = temp;
        
        temp = deadline[i];
        deadline[i] = deadline[j];
        deadline[j] = temp;
        
       temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        
        
      }
    }
  }

  printf("State\tDeadline\tProfit\n");
  for(i = 0; i < n; i++) {
    printf("%c\t%d\t\t%d\n", x[i], deadline[i], profit[i]);
  }
int k,maxprofit,timeSlot[100],fullTimeSlot = 0;
int dmax = 0;
  for(i = 0; i < n; i++) {
    if(deadline[i] > dmax) {
      dmax = deadline[i];
    }
  }

  
  for(i = 1; i <= dmax; i++) {
    timeSlot[i] = -1;//slot is empty
  }

  for(i = 1; i <= n; i++) {
    k = minValue(dmax, deadline[i-1]);
    while(k >= 1) {
      if(timeSlot[k] == -1) {
        timeSlot[k] = i-1;
        fullTimeSlot++;//to jump to next slot
        break;
      }
      k--;//suppose a=2,b=1 we hve to get 1,2
    }
	if(fullTimeSlot == dmax) {
      break;
    }
  }

  
  printf("\nRequired states: ");
  for(i = 1; i <= dmax; i++) {
    printf("%c", x[timeSlot[i]]);

    if(i < dmax) {
      printf(" --> ");
    }
  }

  
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += profit[timeSlot[i]];
  }
  printf("\nMax Profit: %d\n", maxprofit);
}
