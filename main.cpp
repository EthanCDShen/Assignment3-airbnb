#include<stdio.h>
#include<iostream>
#include<string>
#include<iomanip>

void propertypage();
void filterpage();
void bookingpage();

int main(){
    int service;

    do{
        std::cout<<"\n===Welcome to MMU AirB&B====\n"
             <<"1. View all properties.\n"
             <<"2. Filter options.\n"
             <<"3. View my booking.\n"
             <<"0. Exit.\n"
             <<"\n Enter you choice : ";

        std::cin>>service;

        switch (service){
            case 1:
                propertypage();
                break;
            case 2:
                filterpage();
                break;
            case 3:
                bookingpage();
                break;
            case 0:
                std::cout<<"Thank you for choosing us. See you again!";
                return 0;
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

const int property_count=9;

Property properties[property_count] = {
    {101, "Melaka Family Apartment", "Melaka", 180.00, 6, 3, 2,
     "Wi-Fi, air conditioning, kitchen, parking", false},
    {102, "Mykey Imperio", "Melaka", 160.00, 4, 3, 2,
     "Wi-Fi, air conditioning, television, parking", true},
    {103, "Backpackers Cozy Apartment", "Kuala Lumpur", 200.00, 4, 2, 1,
     "Wi-Fi, air conditioning, swimming pool, parking", true},
    {104, "Lisa Homestay", "Kuala Lumpur", 230.00, 6, 3, 2,
     "Wi-Fi, air conditioning, kitchen, parking, barbeque area", true},
    {105, "Spacious Luxury Holiday Home", "Pulau Penang", 400.00, 8, 5, 3,
     "Wi-Fi, air conditioning, kitchen, parking, swimming pool, gym, television", true},
    {106, "The Homestay Helper", "Pulau Penang", 150.00, 3, 2, 1,
     "Wi-Fi, air conditioning, parking", true},
    {108, "King Serve Airbnb", "Johor", 250.00, 4, 2, 1,
     "Wi-Fi, air conditioning, television, parking", true},
    {109, "Sky Loft Homestay", "Johor", 230.00, 5, 3, 2,
     "Wi-Fi, air conditioning, telecision", true},
    {110, "Nightstay in Skyline", "Kuala Lumpur", 450.00, 4, 2, 2,
     "Wi-Fi, air conditioning, kitchen, parking, swimming pool, gym", true},

};

void propertypage(){
    std::cout<<"\n===All Properties===\n"
             <<std::left<<std::setw(10)<<"ID"<<std::setw(30)<<"Property"<<std::setw(8)<<"Guests"<<std::setw(8)<<"Rooms"<<std::setw(10)<<"Toilets"<<std::setw(15)<<"Night (RM)"<<std::setw(15)<<"Availability"<<"\n";

    for (int i = 0; i < property_count; i++)
    {
        std::cout<<std::left<<std::setw(10)<<properties[i].id<<std::setw(30)<<properties[i].name<<std::setw(8)<<properties[i].guest<<std::setw(8)<<properties[i].room<<std::setw(10)<<properties[i].toilet<<std::setw(15)<<properties[i].pricePnight<<std::setw(15)<<(properties[i].availability ? "Available" : "Booked")<<"\n";
    }

    bool found = false;

    while (!found)
    {
        int propertyid;

        std::cout<<"\nEnter property ID to see details (0 to main menu): ";
        std::cin>>propertyid;

        if(propertyid == 0){
            return;
        }
            for (int i = 0; i < property_count; i++)
            {
                if (properties[i].id == propertyid)
                {
                    int propertychoice;

                    std::cout<<"\n===Property Details===\n"
                            <<"ID              : "<<properties[i].id<<"\n"
                            <<"Name            : "<<properties[i].name<<"\n"
                            <<"Location        : "<<properties[i].location<<"\n"
                            <<"Price/Night     : "<<properties[i].pricePnight<<"\n"
                            <<"Maximum guests  : "<<properties[i].guest<<"\n"
                            <<"Rooms           : "<<properties[i].room<<"\n"
                            <<"Toilets         : "<<properties[i].toilet<<"\n"
                            <<"Facilities      : "<<properties[i].facility<<"\n"
                            <<"Availability    : "<<(properties[i].availability ? "Available" : "Booked")<<"\n";

                    found = true;

                    if (properties[i].availability == false)
                    {
                        std::cout<<"This property had been booked. Press Enter to go back...";
                        std::cin.ignore();
                        std::cin.get();

                        return;
                    }else {
                        std::cout<<"\n1. Book this property."
                                 <<"\n0. Back to list."
                                 <<"\n\nEnter your choice : ";

                        std::cin>>propertychoice;

                        if (propertychoice == 1)
                        {
                            std::cout<<"\n===Booking Now==="
                                     <<"\nNumber of guests : ";
                            std::cin>>guestNum;

                            if(guestNum > properties[i].guest){
                                std::cout<<"Sorry, this property only allows "<<properties[i].guest<<" guests.\n";

                                return;
                            }

                            std::cout<<"\nHow many days : ";
                            std::cin>>nightNum;

                            double totalPrice;

                            totalPrice = properties[i].pricePnight * nightNum;
                            std::cout<<"\n\n===Booking Summary===\n"
                                     <<"Property : "<<properties[i].name<<"\n"
                                     <<"Guests : "<<guestNum<<"\n"
                                     <<"Nights : "<<nightNum<<"\n"
                                     <<"Total : RM"<<totalPrice<<"\n";
                            
                            std::cout<<"\n1. Confirm booking \n"
                                     <<"0. Go back.\n"
                                     <<"Enter your choice : "
                            std::cin>>confirmbooking;

                            if (confirmbooking == 1)
                            {
                                cout<<"Booking already confirmed. "
                            }else if (confirmbooking == 0)
                            {
                                
                            }
                            
                            

                        }else if(propertychoice == 0){
                            propertypage();
                        }else{
                            std::cout<<"\nInvalid input.";
                        }
                                          
                    }
            
                }

            if (!found){
                    std::cout<<"\nProperty not found. Please enter again try again.\n";
            }
    
        }
    
    }
      
}

void filterpage(){

    std::cout<<"\n===Filter Option===\n\n";

    std::cout<<"How many guest : ";
    std::cin>>guestfilter;

    std::cout<<"How many nights : ";
    std::cin>>nightfilter;

    std::cout<<"How many rooms : ";
    std::cin>>roomfilter;

    std::cout<<"How many toilets : ";
    std::cin>>toiletfilter;

    if (/*all condition true*/)
    {
        /*show filtered property*/ 
    }
    
}

void bookingpage(){
    
    std::cout<<"\n===Current Bookings===\n\n";

    if (/*have current booking*/)
    {
        /*show current booking*/
    }else{
        /*show no current booking*/
        /*ask to booking now, route to view all property page*/
    }
    

}