#include <stdio.h>
void tower(int, char, char, char);
 
main()
{
    int n;
 
    printf("Enter the number of disks");
    scanf("%d",&n);
    printf("The sequence of moves\n");
    tower(n,'A','C','B');
    
}
void tower(int n,char aa, char cc, char bb)
{
    if (n==1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", aa,cc);
        return ;
    }
    
    tower(n-1,aa,bb,cc);
    printf("\n Move disk %d from tower %c to tower %c", n, aa,cc);
    tower(n-1,bb,cc,aa);
  
}
