#include <iostream>
#include <vector>


int main(){
    std::vector<int> A(1000, 0);

    for (int i = 0; i<A.size(); i++){
        A[i] = i;
    }

    for (int k = 2; k<A.size(); k++){
        for (int i = 0; i < A.size(); i++){
            if (A[i] % k != 0) A[i] = 0;
        }
    }

    for (int i = 0; i < A.size(); i++){
        if (A[i] != 0) std::cout << A[i] << std::endl;
    }

    return 0;
}