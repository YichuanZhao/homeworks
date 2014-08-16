#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int num_month;
  double dol_month;
  double rate_return;
};

typedef struct _retire_info retire_info;

void retirement (int startAge,   //in months
                 double initial, //initial savings in dollars
                 retire_info working, //info about working
		 retire_info retired){ //info about being retired

 
  int  monthnumber = working.num_month;
  double balance = initial;
  int Ageyear = 0;
  int Agemonth = 0;
  for(int i = 0; i < monthnumber;i++)
    {
      Ageyear = (startAge + i)/12;
      Agemonth = (startAge + i) - Ageyear*12;
      printf("Age %3d month %2d you have $%.2lf\n",Ageyear, Agemonth, balance);
      balance = balance + balance * working.rate_return + working.dol_month;
    }
  
  int retire_age = startAge + working.num_month;
  int Rage_year = 0;
  int Rage_month = 0;
  for(int j = 0; j < retired.num_month;j++)
    {
      Rage_year = (retire_age + j)/12;
      Rage_month =(retire_age + j) - Rage_year*12;
      printf("Age %3d month %2d you have $%.2lf\n",Rage_year, Rage_month, balance);
      balance = balance + balance * retired.rate_return + retired.dol_month;
      
    }
  

}

int main()
{
  double initial = 21345;
  int startage = 327;
  retire_info working;
  retire_info retired;
  working.num_month = 489;
  working.rate_return = 0.045/12;
  working.dol_month = 1000;
  retired.num_month = 384;
  retired.rate_return = 0.01/12;
  retired.dol_month = -4000;
  
  retirement(startage, initial, working,retired);
  return 0;
}
