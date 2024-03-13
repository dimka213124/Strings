#include <iostream>

 bool isSumMultiple(int num) {
    if (num >= 10 && num <= 99) {
        int digit1 = num / 10;
        int digit2 = num % 10;
        int digitSum = digit1 + digit2;
        
        if (num % digitSum == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        std::cout << "Введите двухзначное число." << std::endl;
        return false;
    }
}

 int main() {
     int number;
     std::cout <<"Введите число";
     std::cin >> number;
     
     if (isSumMultiple(number)) {
         std::cout <<"Сумма цифр числа " << number <<" кратна трём." << std::endl; 
     } else {
         std::cout <<"Сумма цифр числа " << number << " не кратна трём." << std::endl;
     }
     
     return 0;
 }