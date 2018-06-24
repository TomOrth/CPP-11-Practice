#include <iostream>
#include <string>

int main() {
    std::string msg = "Hello";
    int counter = 10;

    //you can capture local variables
    //they are made constant so you have to add the mutable modifier
    auto func = [msg, counter] () mutable {
        std::cout << "Inside Lambda :: msg = " << msg << std::endl;
        std::cout << "Inside Lambda :: counter = " << counter << std::endl;

        //change the outer scope variables
        //changes will only be for inside the lambda, they do not persist outside the lambda
        msg = "Temp";
        counter = 20;

        std::cout << "Inside Lambda :: After changing :: msg = " << msg << std::endl;
        std::cout << "Inside Lambda :: After changing :: counter = " << counter << std::endl;
         
    };
    func();

    //local variables won't be changed
    std::cout << "msg = " << msg << std::endl;
    std::cout << "counter = " << counter << std::endl;

    //if you want the changes to persist then you need to pass by reference
	auto func2 = [&msg, &counter]  () {
		std::cout<<"Inside Lambda :: msg = "<<msg<<std::endl;
		std::cout<<"Inside Lambda :: counter = "<<counter<<std::endl;
 
		// Change the counter & msg
		// Change will affect the outer variable because counter variable is
		// captured by Reference in Lambda function
		msg = "Temp";
		counter = 20;
 
		std::cout<<"Inside Lambda :: After changing :: msg = "<<msg<<std::endl;
		std::cout<<"Inside Lambda :: After changing :: counter = "<<counter<<std::endl;
 
		};
 
	//Call the Lambda function
	func2();
 
	std::cout<<"msg = "<<msg<<std::endl;
	std::cout<<"counter = "<<counter<<std::endl;

    return 0;
}