#include <stdio.h>
#include <stdlib.h>
typedef struct d{
        int p,y,g;
       } d;
int min(d* a,int size)
{
  int p_min = a[0].p;     
    int i;
    for(i=0;i<size;i++)
    {
      if(a[i].p < p_min)
      {
                 p_min = a[i].p;                   
                ;
      }       
    }
    return p_min;
    
}
int max(d* a,int size)
{
  int p_max = a[0].p + a[0].g ;     
    int i;
    for(i=0;i<size;i++)
    {
      if(a[i].p + a[i].g >= p_max)
      {
                 p_max = a[i].p + a[i].g;                   
                 
      }       
    }
    return p_max;
    
}
int mutlak(int a,int b)
{
  if(a>b)
  return a-b;
  else
  return b-a;      
}
int main(int argc, char *argv[])
{
    d* x; int a=0;
    x = (d*)malloc(sizeof(d));
    int *dizi;
     int i,j,cevre=0,bi=0;
    
    do{
        
        scanf("%d",&(x[a].p));
        if (x[a].p==-1)
        break;
        scanf("%d%d",&(x[a].y),&(x[a].g));
        x = (d*)realloc(x,sizeof(d)*(a+2));     
             a++;
    }while(x[a].p != -1);
    int boyut = max(x,a) - min(x,a)+x[0].p+1 ;
   dizi = (int*)calloc(  sizeof(int), boyut);
   
   for(i=1;i<boyut;i++)
   {
       for(j=0;j<a;j++){
          if(i>=x[j].p && i< (x[j].p + x[j].g) )
          {
                  if(x[j].y > dizi[i])
                  dizi[i] =   x[j].y;   
                       
          }                
                           
       }             
                       
   }
   dizi[boyut+1] = 0;
   for(i=1;i<boyut;i++)
   {
       if(dizi[i] != dizi[i-1])
            {
                    cevre +=  mutlak(dizi[i], dizi[i-1]);   
                    if(dizi[bi] != 0 )     
                    cevre += i-bi;
                    bi = i;
            }     
   }
    for(i=0;i<boyut;i++)
    {     printf(" %d ",dizi[i]);                                
    }
    printf("cevre = %d ",cevre);
  system("PAUSE");	return 0;}



















