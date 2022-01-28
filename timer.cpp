#include<bits/stdc++.h>
#include<windows.h>
#include "espeak.h"
using namespace std;
void timer();
int main()
{
       timer();
       system("cls");
       voice_out voice;
       voice.initializer("timer completed");
       voice.print_voice_note("timer completed");
       voice.execute_voice_command();
}
void timer()
{
       int i,j,k,h,m,s;
             printf("enter hours : ");
              scanf("%2d",&h);
             printf("enter minutes : ");
              scanf("%2d",&m);
              printf("enter seconds : ");
              scanf("%2d",&s);
          for(int i=0;i<=23;i++)
            {
                    for(int j=0;j<=59;j++)
                {
                             for(int k=0;k<=59;k++)
                            {
                                        printf("\n%2d:%2d:%2d",i,j,k);
                                        Sleep(1000);
                                        system("cls");
                                        if(i>=h&&j>=m&&k>=s)
                                               break;
                             }
                     printf("\n%2d:%2d:%2d",i,j,k);
                     system("cls");
                     if(i>=h&&j>=m)
                              break;
                 }
              printf("\n%2d:%2d:%2d",i,j,k);
              system("cls");
              if(i>=h)
                            break;
           }
           printf("%2d:%2d:%2d\n\n",h,m,s);
}
