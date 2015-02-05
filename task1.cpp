#include <iostream>

using namespace std;

int main()
{
  for (int i=000001;i<999999;i++)
  {
     int d1= i/100000;
     int d2= i%100000/10000;
     int d3= i%10000/1000;
     int d4= i%1000/100;
     int d5= i%100/10;
     int d6= i%10;
     if (d1+d2+d3 == d4+d5+d6)
       cout<<d1<<d2<<d3<<d4<<d5<<d6<<endl;
  }
  cout<<endl;
  return 0;
}

// 11 минут