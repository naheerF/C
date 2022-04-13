#include<stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], totalpro = 0;
   int i, j, sc;
   sc = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > sc)
         break;
      else {
         x[i] = 1.0;
         totalpro = totalpro + profit[i];
         sc = sc - weight[i];
      }
   }
 
   if (i < n)
      x[i] = sc / weight[i];
 
   totalpro = totalpro + (x[i] * profit[i]);
 
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nMaximum profit is:- %f", totalpro);
 
}
 main() {
   float weight[20], profit[20], capacity;
   int n, i, j;
   float ratio[20], temp;
 
   printf("\nEnter the number of elements");
   scanf("%d", &n);
 
   printf("\nEnter the wts and profits");
   for (i = 0; i < n; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }
 
   printf("\nEnter the capacity of knapsack");
   scanf("%f", &capacity);
 
   for (i = 0; i < n; i++) {
      ratio[i] = profit[i] / weight[i]; //P/W
   }
 
   for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[i];
            ratio[i] = ratio[j];
            ratio[j] = temp;
 
            temp = weight[i];
            weight[i] = weight[j];
            weight[j] = temp;
 
            temp = profit[i];
            profit[i] = profit[j];
            profit[j] = temp;
         }
      }
   }
 
   knapsack(n, weight, profit, capacity);
}

