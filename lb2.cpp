#include <iostream>
#include <cmath>

double func(double x, int max_n){
  double z = (x-1)/(x+1);
  double zz = z*z;
  double sum = 0;
  double a = z;
  for (int n = 1; n<max_n; n+=2){
    sum += a/n;
    a *= zz;
  }
  sum += a;
  return 2*sum;
}
 int main(){
   int max_n;
   std::cout << "Введите максимальное n\n";
   std::cin >> max_n; 
   std::cout << "\n";
   for (double x = 0.1; x <= 0.9; x+=0.1){
      std::cout << x << "\t" << func(x, max_n) << "\t" << std::log(x) << "\n";
   }
   return 0;
 }
