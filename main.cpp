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

Property properties[property_count] = {
    {101, "Melaka Family Apartment", "Melaka", 180.00, 6, 3, 2,
     "Wi-Fi, air conditioning, kitchen, parking", true},
    {102, "Mykey Imperio", "Melaka", 160.00, 4, 3, 2,
     "Wi-Fi, air conditioning, television, parking", true},
    {103, "Backpackers Cozy Apartment", "Kuala Lumpur", 200.00, 4, 2, 1,
     "Wi-Fi, air conditioning, swimming pool, parking", true},
    {104, "Lisa Homestay", "Kuala Lumpur", 230.00, 6, 3, 2,
     "Wi-Fi, air conditioning, kitchen, parking, barbeque area", true},
    {105, "Spacious Luxury Holiday Home", "Pulau Penang", 400.00, 8, 5, 3,
     "Wi-Fi, air conditioning, kitchen, parking, swimming pool, gym, television", true},
    {10, "The Homestay Helper", "Pulau Penang", 150.00, 3, 2, 1,
     "Wi-Fi, air conditioning, parking", true},
    {108, "King Serve Airbnb", "Johor", 250.00, 4, 2, 1,
     "Wi-Fi, air conditioning, television, parking", true},
    {109, "Sky Loft Homestay", "Johor", 230.00, 5, 3, 2,
     "Wi-Fi, air conditioning, telecision", true},
    {110, "Nightstay in Skyline", "Kuala Lumpur", 450.00, 4, 2, 2,
     "Wi-Fi, air conditioning, kitchen, parking, swimming pool, gym", true},

}