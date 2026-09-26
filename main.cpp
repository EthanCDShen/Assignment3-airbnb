#include<stdio.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<limits>

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

int readnumber(){
    int number;
    std::string remaining;

    while(true){
        if(std::cin>>number){
            std::getline(std::cin, remaining);

            if(remaining.find_first_not_of(" \t\r") == std::string::npos){
                return number;
            }
        }else{
            if(std::cin.eof()){
                return 0;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout<<"Invalid input. Enter a whole number : ";
    }
}


void propertypage(int guestfilter, int nightfilter, int roomfilter, int toiletfilter, int pricefilter){

    while(true){
        if(guestfilter >0){
            std::cout<<"\n===Filtered Properties===\n"
                     <<"Guests: "<<guestfilter<<" | Nights: "<<nightfilter
                     <<" | Minimum rooms: "<<roomfilter<<" | Minimum toilets: "<<toiletfilter
                     <<" | Maximum price/night: RM "<<pricefilter<<"\n";
        }else{
            std::cout<<"\n===All Properties===\n";
        }

        // The heading and property rows are displayed together in this page.
        std::cout<<std::left<<std::setw(10)<<"ID"<<std::setw(30)<<"Property"
                 <<std::setw(8)<<"Guests"<<std::setw(8)<<"Rooms"<<std::setw(10)<<"Toilets"
                 <<std::setw(15)<<"Night (RM)"<<std::setw(15)<<"Availability";
        if(nightfilter >0){
            std::cout<<"Total (RM)";
        }
        std::cout<<"\n";

        bool found=false;

        for(int i=0; i<property_count; i++){
            // Skip unavailable properties and properties that fail any filter.
            if(guestfilter >0 && (!properties[i].availability ||
               properties[i].guest <guestfilter || properties[i].room <roomfilter ||
               properties[i].toilet <toiletfilter || properties[i].pricePnight >pricefilter)){
                continue;
            }

            std::cout<<std::fixed<<std::setprecision(2)
                     <<std::left<<std::setw(10)<<properties[i].id<<std::setw(30)<<properties[i].name
                     <<std::setw(8)<<properties[i].guest<<std::setw(8)<<properties[i].room
                     <<std::setw(10)<<properties[i].toilet<<std::setw(15)<<properties[i].pricePnight
                     <<std::setw(15)<<(properties[i].availability ? "Available" : "Booked");
            if(nightfilter >0){
                std::cout<<properties[i].pricePnight * nightfilter;
            }
            std::cout<<"\n";
            found=true;
        }

        if(!found){
            std::cout<<"No available properties match your requirements. Try different filters.\n";
            return;
        }

        int propertyid;
        int index=-1;

        std::cout<<"\nEnter property ID to see details (0 to main menu): ";
        propertyid=readnumber();

        if(propertyid ==0){
            return;
        }

        for(int i=0; i<property_count; i++){
            if(properties[i].id ==propertyid){
                index=i;
                break;
            }
        }

        if(index ==-1){
            std::cout<<"Property not found. Please enter an ID from the list.\n";
            continue;
        }

        // A filtered booking must be selected from the displayed matches.
        if(guestfilter >0 && (!properties[index].availability ||
           properties[index].guest <guestfilter || properties[index].room <roomfilter ||
           properties[index].toilet <toiletfilter || properties[index].pricePnight >pricefilter)){
            std::cout<<"This property does not match your filters. Choose an ID from the list.\n";
            continue;
        }

        std::cout<<"\n===Property Details===\n"
                 <<"ID              : "<<properties[index].id<<"\n"
                 <<"Name            : "<<properties[index].name<<"\n"
                 <<"Location        : "<<properties[index].location<<"\n"
                 <<"Price/Night     : RM "<<properties[index].pricePnight<<"\n"
                 <<"Maximum guests  : "<<properties[index].guest<<"\n"
                 <<"Rooms           : "<<properties[index].room<<"\n"
                 <<"Toilets         : "<<properties[index].toilet<<"\n"
                 <<"Facilities      : "<<properties[index].facility<<"\n"
                 <<"Availability    : "<<(properties[index].availability ? "Available" : "Booked")<<"\n";

        if(!properties[index].availability){
            std::cout<<"This property has already been booked. Please choose another property.\n";
            continue;
        }

        int propertychoice;
        do{
            std::cout<<"\n1. Book this property.\n"
                     <<"0. Back to list.\n"
                     <<"\nEnter your choice : ";
            propertychoice=readnumber();

            if(propertychoice !=0 && propertychoice !=1){
                std::cout<<"Invalid choice. Enter 1 or 0.\n";
            }
        }while(propertychoice !=0 && propertychoice !=1);

        if(propertychoice ==0){
            continue;
        }

        if(booking_count >=max_booking){
            std::cout<<"The limit of 50 booking records for this run has been reached.\n";
            continue;
        }

        // Reuse the guests and nights entered on the filter page, if provided.
        int guestNum=guestfilter;
        int nightNum=nightfilter;
        int confirmbooking;

        std::cout<<"\n===Booking Now===\n";

        if(guestNum ==0){
            do{
                std::cout<<"Number of guests, 1-"<<properties[index].guest<<" (0 to go back): ";
                guestNum=readnumber();
                if(guestNum ==0){
                    break;
                }
                if(guestNum <1 || guestNum >properties[index].guest){
                    std::cout<<"Invalid input. This property allows 1 to "<<properties[index].guest<<" guests.\n";
                }
            }while(guestNum <1 || guestNum >properties[index].guest);

            if(guestNum ==0){
                continue;
            }
        }

        if(nightNum ==0){
            do{
                std::cout<<"How many nights, 1-30 (0 to go back): ";
                nightNum=readnumber();
                if(nightNum ==0){
                    break;
                }
                if(nightNum <1 || nightNum >30){
                    std::cout<<"Invalid input. Enter a number between 1 and 30.\n";
                }
            }while(nightNum <1 || nightNum >30);

            if(nightNum ==0){
                continue;
            }
        }

        double totalPrice=properties[index].pricePnight * nightNum;

        std::cout<<"\n===Booking Summary===\n"
                 <<"Property : "<<properties[index].name<<"\n"
                 <<"Guests   : "<<guestNum<<"\n"
                 <<"Nights   : "<<nightNum<<"\n"
                 <<"Total    : RM "<<std::fixed<<std::setprecision(2)<<totalPrice<<"\n";

        do{
            std::cout<<"\n1. Confirm booking.\n"
                     <<"0. Go back.\n"
                     <<"Enter your choice : ";
            confirmbooking=readnumber();

            if(confirmbooking !=0 && confirmbooking !=1){
                std::cout<<"Invalid choice. Enter 1 or 0.\n";
            }
        }while(confirmbooking !=0 && confirmbooking !=1);

        if(confirmbooking ==1){
            bookings[booking_count].id=1001 + booking_count;
            bookings[booking_count].propertyIndex=index;
            bookings[booking_count].guestNum=guestNum;
            bookings[booking_count].nightNum=nightNum;
            bookings[booking_count].totalPrice=totalPrice;
            bookings[booking_count].status="Current";
            properties[index].availability=false;

            std::cout<<"Booking confirmed. Your booking ID is "<<bookings[booking_count].id<<".\n";
            booking_count++;
        }else{
            std::cout<<"Booking not confirmed. No booking was saved.\n";
        }
    }
}
      

void filterpage(){

    int guestfilter, nightfilter, roomfilter, toiletfilter, pricefilter;

    std::cout<<"\n===Filter Option===\n";

    do
    {
        std::cout<<"\nHow many guest (1-15) : ";
        std::cin>>guestfilter;

        if (guestfilter < 1 || guestfilter > 15)
        {
            std::cout<<"Invalid input. Enter number between 1 to 15.\n";
        }
        
    } while (guestfilter < 1 || guestfilter > 15);
    

    do
    {
        std::cout<<"\nHow many nights (1-30) : ";
        std::cin>>nightfilter;

        if (nightfilter < 1 || nightfilter > 30)
        {
            std::cout<<"Invalid input. Enter number between 1 to 30.\n";
        }
        
    } while (nightfilter < 1 || nightfilter > 30);


    do
    {
        std::cout<<"\nHow many rooms (1-10) : ";
        std::cin>>roomfilter;

        if (roomfilter < 1 || roomfilter > 10)
        {
            std::cout<<"Invalid input. Enter number between 1 to 10.\n";
        }
        
    } while (roomfilter < 1 || roomfilter > 10);


    do
    {
        std::cout<<"\nHow many toilets (1-10) : ";
        std::cin>>toiletfilter;

        if (toiletfilter < 1 || toiletfilter > 10)
        {
            std::cout<<"Invalid input. Enter number between 1 to 10.\n";
        }
        
    } while (toiletfilter < 1 || toiletfilter > 10);


    do
    {
        std::cout<<"\nMaximum budget per night RM(1-1000) : ";
        std::cin>>pricefilter;

        if (pricefilter < 1 || pricefilter > 10)
        {
            std::cout<<"Invalid input. Enter number between 1 to 1000.\n";
        }
        
    } while (pricefilter < 1 || pricefilter > 1000);

    propertypage(guestfilter, nightfilter, roomfilter, toiletfilter, pricefilter);
    
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