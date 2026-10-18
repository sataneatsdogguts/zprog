#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <chrono>

void printarr(std::vector<int> A){
    for (int i =0; i<A.size(); i++){
        std::cout << A[i] << " ";
    };
} 

std::vector<int> gen(int s){
  std::vector<int> A(s);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(1,100);      
  for (int i =0; i<s; i++){
    A[i] = distrib(gen);
    }
   return A;
}

void step(int speed, std::vector<int> &A){
std::this_thread::sleep_for(std::chrono::milliseconds(speed));
      printarr(A);
      std::cout << "\n";

}
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
            step(100, A);
        }

        A[winx] = A[i];
        A[i] = minEl;
    }
}

void ReligionSort(){
  std::cout << "Бог создал этот массив отсортированным.\nЛюбой несогласный идёт против самого мироздания и должен быть сожжён на костре, чтобы небеса были спокойны.\n";
}

void BubbleSort(std::vector<int> & A){
  for (int i=A.size(); i>0; i--){
    for (int j=1; j<i; j++){
      if (A[j-1]>A[j]){
        A[j] = A[j] ^ A[j-1];
        A[j-1] = A[j] ^ A[j-1];
        A[j] = A[j] ^ A[j-1];
            }
      step(100, A);
    }
  } 
}

void QuickSort(std::vector<int>&A, int i, int j){
  if (i>=j) return;
  int pivot = A[j];
  int st = i;
  int end = j;
while(i<=j){
  while (A[i]<pivot) i++;
  while (A[j]>pivot) j--;
  if (i<=j) {
    std::swap(A[i++], A[j--]);
    step(100, A);
  }
}
if (st < j) QuickSort(A, st, j);
if (end > i) QuickSort(A, i, end);
}

int main()
{
   std::vector<int> A = gen(10); 
   // std::vector<int> A = {8, 5, 9, 6}; 
   std::cout << "Изначальный массив: ";
   printarr(A);
   std::cout << "\n\n";
   
   std::cout<< "Как отсортировать массив?\n\n1) Bubble Sort\n2) Сортировка выбором\n3) QuickSort\n4) Сортировка верой\n\n";
   int num; 
   std::cin >> num;
   std::cout << "\n";
   if (num == 1) BubbleSort(A);
   else if (num == 2) sort(A);
   else if (num == 3) QuickSort(A, 0, A.size()-1);
   else if (num == 4) ReligionSort();
   else{
     std::cout << "INVALID NUMBER";
     return -1 ;
   }

   std::cout << "\n" << "Сортированный массив: ";
   printarr(A);
   std::cout << "\n";
   return 0;
}

