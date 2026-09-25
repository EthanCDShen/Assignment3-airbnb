#include<stdio.h>
#include<iostream>
#include<string>

int main(){
    int service;

    do{
        std::cout<<"\n===Welcome to MMU AirB&B====\n"
             <<"1. View all properties.\n"
             <<"2. Filter options.\n"
             <<"3. View my booking.\n"
             <<"0. Exit.\n";

        switch (service){
            case 1:
                propertypage();
                break;
            case 2:
                filerpage();
                break;
            case 3:
                bookingpage();
                break;
            case 0:
                std::cout<<"Thank you for choosing us. See you again!";
                break;
        }
    }while(service !=0);

    return 0;
    
}

struct Property{
    int id;
    std::string name;
    std::string location;
    double pricePnight;
    int guest;
    int room;
    int toilet;
    std::string facility;
    bool availability;
};

