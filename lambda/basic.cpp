#include <iostream>
#include <algorithm>
 
int main() {
    int arr[] = {1,2,3,4,5};

    int mul = 5;

    //format: [captured variables](params) { code here }
    //& allows for outer scope elements to be passed by reference
    //= allows for outer scope elemetns to be passed by value
    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [&](int x){
        std::cout << x << " ";
        mul = 3;
    });

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [=](int &x) {
        x = x*mul;
        //cannot modify mul here as it is passed by value
    });

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
        //no outer scope elements as no modifier is being passed
    });

    std::cout << std::endl;
    return 0;
}
