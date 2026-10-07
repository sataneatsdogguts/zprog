#include <iostream>
#include <random>
#include <vector>


void sort(std::vector<int> & A){
    for (int i=0; i<A.size()-1; i++){
        int minEl = A[i];
        int winx = i;
        for (int j=i+1; j<A.size(); j++)
        {
            if (minEl > A[j])
            {
                minEl = A[j];
                winx = j;
            }
        }

        A[winx] = A[i];
        A[i] = minEl;
    }
}

void BubbleSort(std::vector<int> & A){
  for (int i=A.size(); i>0; i--){
    for (int j=1; j<i; j++){
      if (A[j-1]>A[j]){
        A[j] = A[j] ^ A[j-1];
        A[j-1] = A[j] ^ A[j-1];
        A[j] = A[j] ^ A[j-1];
      }
    }
  } 
}

void printarr(std::vector<int> A){
    for (int i =0; i<A.size(); i++){
        std::cout << A[i] << " ";
    };
} std::vector<int> gen(int s){
  std::vector<int> A(s);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1,100);      
     for (int i =0; i<s; i++){
        A[i] = distrib(gen);
    }
     return A;
}
int main()
{
   std::vector<int> A = gen(10); 
   std::cout << "Изначальный массив: ";
   printarr(A);
   std::cout << "\n";
   
   std::cout<< "Как отсортировать массив?\n1) Bubble Sort\n2) Сортировка выбором\n";
   int num; 
   std::cin >> num;
   if (num == 1) BubbleSort(A);
   else if (num == 2) sort(A);
   else{
     std::cout << "INVALID NUMBER";
     return -1 ;
   }

   std::cout << "\n" << "Сортированный массив: ";
   printarr(A);
   std::cout << "\n";
   return 0;
}

