// cpu sheduling sjf
 #include<stdio.h>
int main()
{
 int bt[10],wt[10],tat[10],pos,i,j,p[10],temp,total=0;
 int n;
 float totalWT=0,totalTAT=0;
 printf("enter the number of processes:");
 scanf("%d",&n);
 printf("enter prcess no\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&p[i]);
 }
 for(i=0;i<n;i++)
 {
 printf("enter the processe[%d]",i+1);
 scanf("%d",&bt[i]);
}
 for(i=0;i<n-1;i++)
 {
  pos=i; 
  for(j=i+1;j<n;j++)
  {
  if(bt[j]<bt[pos])
        {
  pos=j; 
        }
  }
  temp=bt[i];
  bt[i]=bt[pos];
  bt[pos]=temp;
  temp=p[i];
  p[i]=p[pos];
  p[pos]=temp;
 }
 printf("P\tbt\twt\ttat\n");
 for(i=0;i<n;i++)
 {
  wt[i]=0;tat[i]=0;
  for(j=0;j<i;j++)
        {
      wt[i]=wt[i]+bt[j];
         }
     totalWT=totalWT+wt[i];
 tat[i]=bt[i]+wt[i];
  totalTAT=totalTAT+tat[i];
  printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    
 }
   printf("\n avg waiting time=%f\n ",totalWT/n);
     printf("\n avg turnaround time=%f\n ",totalTAT/n);
     return 0;

}

