#include <iostream>
#include <vector>
#include <algorithm>
//один + один = много


std::vector<int> toDigit(int a) {
    std::vector<int> digits;
    if (a == 0) {
        digits.push_back(0);
        return digits;
    }
    while (a != 0) {
        digits.push_back(a % 10); 
        a /= 10;
    }
    std::reverse(digits.begin(), digits.end());  // переворо
    return digits;
}

bool isRepeat(std::vector<int> A){
    std::vector<int> B(10);
    for (int i = 0; i < A.size(); i++){
        B[A[i]]++;
        if (B[A[i]] > 1) return true;
    }
    return false;
}

int main(){

    for (int w = 5000; w <= 9999; w++){
        std::vector<int> W = toDigit(w);
        std::vector<int> R = toDigit(w*2);

        if (isRepeat({R[0], R[1], R[2], R[3], W[1], W[2]})) continue;

        if (W[0] != R[2]) continue; // Один мнОго
        if (W[3] != R[1]) continue; // одиН мНого
        if (R[2] != R[4]) continue; // мнОгО

        std::cout << w << " " << w*2 << std::endl;
        
    }

    return 0;
}
