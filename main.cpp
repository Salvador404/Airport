#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class FlightManager;
class Customer;
class Date {
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;

public:
    Date(int ,int ,int ,int ,int );
    //////////////////////////////
    void setDay(int d);
    int getDay() ;

    void setMonth(int m);
    int getMonth() ;

    void setYear(int y);
    int getYear() ;

    void setHour(int h);
    int getHour() ;

    void setMinute(int m);
    int getMinute() ;

    friend  ostream& operator<<( ostream& out,  const Date& date);
    friend  istream& operator>>( istream& in, Date& date);


};


////////////////////////////////////////////////////////////
Date::Date(int D=1, int M=1 , int Y=2025 , int H=0 , int MIN=0 ):day(D),month(M),year(Y),hour(H),minute(MIN)
{
    if (D<=0||D>31)
       {
        cout<<"Invalid day: Day must be between 1 and 31"<<endl ;
        day=1;
       }

    if (M<=0||M>12)
       {
        cout<<"Invalid day: month must be between 1 and 12"<<endl ;
        month=1;
       }

    if (Y<=2020||Y>2030)
       {
        cout<<"Invalid day: year must be between 2021 and 2030"<<endl ;
        year=2025;
       }

    if (H<0||H>23)
       {
        cout<<"Invalid day: hour must be between 0 and 23"<<endl ;
        hour=0;
       }
    if (MIN<0||MIN>59)
       {
        cout<<"Invalid day: minute must be between 0 and 59"<<endl ;
        minute=0;
       }
}
//////////////////////////////overloading operators//////////////////////////////////////

ostream& operator<<( ostream& out, const Date& date)
{
    out<<"("<<date.day<<"/"<<date.month<<"/"<<date.year<<" "<<date.hour<<":"<<date.minute<<")" <<endl;
    return out;
}

istream& operator>>( istream& in, Date& date)
{
    cout<<"day : ";     cin>>date.day;
    cout<<"month : ";   cin>>date.month;
    cout<<"year : ";    cin>>date.year;
    cout<<"hour : ";    cin>>date.hour;
    cout<<"minute : ";  cin>>date.minute;
    return in;

}


////////////////////////setter functions for Date class/////////////////////////
void Date::setDay(int d)
{
    if (d<=0||d>31)
       {
        cout<<"Invalid input"<<endl ;
        day=1;
       }
    else
        day=d;

}


void Date::setMonth(int m)
{
    if (m<=0||m>12)
       {
        cout<<"Invalid input"<<endl ;
        month=1;
       }
    else
        month=m;

}

void Date::setYear(int y)
{
    if (y<=2020||y>2030)
       {
        cout<<"Invalid input"<<endl ;
        year=2025;
       }
    else
        year=y;

}

void Date::setHour(int h)
{
    if (h<0||h>23)
       {
        cout<<"Invalid input"<<endl ;
        hour=0;
       }
    else
        hour=h;

}


void Date::setMinute(int m)
{
    if (m<0||m>59)
       {
        cout<<"Invalid input"<<endl ;
        minute=0;
       }
    else
        minute=m;

}

//////////////////////getter functions////////////////////

int Date::getDay() {return day;}
int Date::getMonth() {return month;}
int Date::getYear()  {return year;}
int Date::getHour() {return hour;}
int Date::getMinute() {return minute;}
//////////////////////////////////////////////////////////
class Food {
private:
     string type; // Economic or Business
     string meal; // food1 or food2

public:

    Food(string _type="Economic" ,string _meal="standard");
    void setType(  string& t);
    string getType() ;

    void setMeal(  string& m);
    string getMeal() ;

    friend  ostream& operator<<( ostream& out,  Food& food);
    friend  istream& operator>>( istream& in, Food& food);
};
////////////////////////////////////////////////////////
Food::Food(string _type ,string _meal){
    if ((_type=="Economic"||_type=="Business")&&(_meal=="food1"||_meal=="food2")){
        type=_type;
    }else{ cout<<"Wrong input, use(Business/Economic and food1/food2)"<<endl;}
}

void Food::setType( string& t){
    if (t=="Economic"||t=="Business"){
        type=t;
    }else{ cout<<"Wrong input, use(Business/Economic)"<<endl;}
}
void Food::setMeal( string& m){
    if (m=="food1"||m=="food2"){
        meal=m;
    }else{ cout<<"Wrong input, use(food1/food2)"<<endl;}
}

string Food::getType(){ return type;}
string Food::getMeal(){ return meal;}

ostream& operator<<( ostream& out,  Food& food){
    out<<"type : "<<food.type<<"  meal: "<<food.meal<<endl;
    return out;
}

istream& operator>>( istream& in, Food& food){
    cout<<" Enter type (Economic/Business) :"; cin>> food.type;
    cout << "Enter meal :"; cin>> food.meal;
    return in;
}
//////////////////////////////////////////////////////////

class Tax {
public:
    double calculateTax(double price, double percentage)const{
            if(price>0)
                return price*(percentage/100);
            else
                cout<<"invalid price"<<endl;
    } ;
};
///////////////////////////airport class////////////////////////////
class Airport {

protected:
     string domesticFlights;
     string foreignFlights;

public:

    virtual void addFlight(  string& flight)=0;
    virtual void removeFlight(  string& flight)=0;               //////******************
    virtual void displayFlights()=0 ;
    friend istream& operator>>( istream& in, Airport &a);
    friend ostream& operator<<( ostream& out,  Airport &a);
};
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
istream& operator>>( istream& in, Airport &a){
    cout<< "enter domesticFlight :"; cin>>a.domesticFlights;
    cout<< "enter foreignFlights :"; cin>>a.foreignFlights;
    return in;
}
ostream& operator<<( ostream& out,  Airport &a){
    cout<<"domesticFlight: "<<a.domesticFlights<<"  foreignFlights: "<<a.foreignFlights<<endl;
    return out;
}


//////////////////////end of Airport class///////////////////////


////////////////////////cities classes//////////////////////////
class DomesticCities {
private:
    static string cities[10];
    static int cityCount;

public:
    void addCity(const string& city);
    void removeCity(const string& city);
    bool findCity(const string& city) const;
    int getCityCount() const;
    string getCities() const;
};


string DomesticCities::cities[10];
int DomesticCities::cityCount = 0;

void DomesticCities::addCity(const string& city) {
    if (cityCount < 10) {

        for (int i = 0; i < cityCount; ++i) {
            if (cities[i] == city) {
                cout << "City already exists in the list: " << city << endl;
                return;
            }
        }

        cities[cityCount] = city;
        cityCount++;
        cout << "City added successfully: " << city << endl;
    } else {
        cout << "Error: Cannot add more cities! Maximum limit reached (10 cities)." << endl;
    }
}

void DomesticCities::removeCity(const string& city) {
    int foundIndex = -1;
    for (int i = 0; i < cityCount; ++i) {
        if (cities[i] == city) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {

        for (int i = foundIndex; i < cityCount - 1; ++i) {
            cities[i] = cities[i + 1];
        }
        cityCount--;
        cout << "City removed successfully: " << city << endl;
    } else {
        cout << "City not found in the list: " << city << endl;
    }
}

bool DomesticCities::findCity(const string& city) const {

    for (int i = 0; i < cityCount; ++i) {
        if (cities[i] == city) {
            return true;
        }
    }
    return false;
}

int DomesticCities::getCityCount() const {
    return cityCount;
}

string DomesticCities::getCities() const {
    string result;
    for (int i = 0; i < cityCount; ++i) {
        result += cities[i];
        if (i < cityCount - 1) {
            result += " , ";
        }
    }
    return result;
}
////////////////////////end of domestic Cities//////////////////

/////////////////////////ForeignCities class///////////////////////
class ForeignCities {
private:
    static string cities[10];
    static int cityCount;

public:
    void addCity(const string& city);
    void removeCity(const string& city);
    bool findCity(const string& city) const;
    int getCityCount() const;
    string getCities() const;
};


string ForeignCities::cities[10];
int ForeignCities::cityCount = 0;

void ForeignCities::addCity(const string& city) {
    if (cityCount < 10) {

        for (int i = 0; i < cityCount; ++i) {
            if (cities[i] == city) {
                cout << "City already exists in the list: " << city << endl;
                return;
            }
        }

        cities[cityCount] = city;
        cityCount++;
        cout << "City added successfully: " << city << endl;
    } else {
        cout << "Error: Cannot add more cities! Maximum limit reached (10 cities)." << endl;
    }
}

void ForeignCities::removeCity(const string& city) {
    int foundIndex = -1;

    for (int i = 0; i < cityCount; ++i) {
        if (cities[i] == city) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {

        for (int i = foundIndex; i < cityCount - 1; ++i) {
            cities[i] = cities[i + 1];
        }
        cityCount--;
        cout << "City removed successfully: " << city << endl;
    } else {
        cout << "City not found in the list: " << city << endl;
    }
}

bool ForeignCities::findCity(const string& city) const {

    for (int i = 0; i < cityCount; ++i) {
        if (cities[i] == city) {
            return true;
        }
    }
    return false;
}

int ForeignCities::getCityCount() const {
    return cityCount;
}

string ForeignCities::getCities() const {
    string result;
    for (int i = 0; i < cityCount; ++i) {
        result += cities[i];
        if (i < cityCount - 1) {
            result += " , ";
        }
    }
    return result;
}
///////////////////////end of Foreign Cities//////////////////////


///////////////////////foreign flights class//////////////////////
class ForeignFlights : public Airport {
private:
    string flightID;
    string originCity;
    string destinationCity;
    Date flightDate;
    string planeName;
    bool isCancelled;
    double price;

public:
    void setFlightID(  string& id);
    string getFlightID();

    void setOriginCity(string& city);
    string getOriginCity() ;

    void setDestinationCity(string& city);
    string getDestinationCity() ;

    void setFlightDate(Date& date);
    Date getFlightDate() ;

    void setPlaneName(string& name);
    string getPlaneName() ;

    void setIsCancelled(bool cancelled);
    bool getIsCancelled() ;

    void setPrice(  double& _price);
    double getPrice() ;
    void display() const;
    friend istream& operator>>( istream& in ,ForeignFlights &a );
    friend ostream& operator<<( ostream& out,ForeignFlights &a );
    friend bool operator==(const ForeignFlights& a, const ForeignFlights& b);

    void addFlight(  string& flight)override;
    void removeFlight(string& flight, FlightManager& flightManager);
    void displayFlights(const FlightManager& flightManager) const;



/////////////////////constructor///////////////////
ForeignFlights(string id = "", string origin = "", string dest = "", Date date =Date(), bool cancelled = false, double Price=10 , string plane = "")
        : flightID(id), originCity(origin), destinationCity(dest), flightDate(date), isCancelled(cancelled), price(Price) , planeName(plane) {}

};

////////////////////////display///////////////////////////
void ForeignFlights::display() const {
        cout << "Flight ID: " << flightID << endl;
        cout << "Origin: " << originCity << endl;
        cout << "Destination: " << destinationCity << endl;
        cout << "Date: " << flightDate << endl;
        cout << "Plane Name: " << planeName << endl;
        cout << "ForeignFlight-Price: " << price << endl;
        cout << "Status: " << (isCancelled ? "Cancelled" : "Active") << endl;
        cout << "-------------------------" << endl;
}
///////////////////////////////////////
void ForeignFlights::setFlightID(  string& id){
    flightID=id;
}
void ForeignFlights::setOriginCity(string& city){
    originCity=city;
}
void ForeignFlights::setDestinationCity(string& city){
    destinationCity=city;
}
void ForeignFlights::setFlightDate(Date& date){
    flightDate=date;
}
void ForeignFlights::setPlaneName(string& name){
    planeName=name;
}
void ForeignFlights::setIsCancelled(bool cancelled){
    isCancelled=cancelled;
}
void ForeignFlights::setPrice(  double& _price){
    price=_price;
}
////////////////////////////////////////
string ForeignFlights::getFlightID() { return flightID; }
string ForeignFlights::getOriginCity(){ return originCity; }
string ForeignFlights::getDestinationCity(){ return destinationCity; }
Date ForeignFlights::getFlightDate(){ return flightDate; }
string ForeignFlights::getPlaneName(){ return planeName; }
bool ForeignFlights::getIsCancelled(){ return isCancelled; }
double ForeignFlights::getPrice() {return price;}

/////////////////////////////////////////
istream& operator>>( istream& in,ForeignFlights &a ){
    cout << "flight ID : ";cin>>a.flightID;
    cout<< "OriginCity: "; cin>>a.originCity;
    cout<< "DestinationCity: "; cin>>a.destinationCity;
    cout<< "FlightDate: "; cin>>a.flightDate;
    cout<< "PlaneName: "; cin>>a.planeName;
    cout<< "Is Cancelled?(1 for Yes, 0 for No): "; cin>>a.isCancelled;
    return in;
}
ostream& operator<<( ostream& out, ForeignFlights &a  ){
    cout << "flight ID : "<<a.flightID<<endl;
    cout<< "OriginCity: "<<a.originCity<<endl;
    cout<< "DestinationCity: "<<a.destinationCity<<endl;
    cout<< "FlightDate: "<<a.flightDate<<endl;
    cout<< "PlaneName: "<<a.planeName<<endl;
    if (a.isCancelled == true){
        cout<< "CANCELLED!"<<endl;
    }else{ cout<< "NOT Cancelled"<<endl;}
    return out;
}
//در تابع فایند از این اپراتوریبراس جستوجو در لیست استفاده میشه
bool operator==(const ForeignFlights& a, const ForeignFlights& b) {
    return (a.getFlightID() == b.getFlightID());
}
/////////////////////////////////////////////
void ForeignFlights::addFlight(  string& flight){
     if (foreignFlightsList.size() < 10) {

        for (const auto & existingFlight : foreignFlightsList) {
            if (existingFlight.getFlightID() == flight) {
                cout << "Flight already exists: " << flight << endl;
                return;
            }
        }


        ForeignFlights newFlight;
        newFlight.setFlightID(flight);


        string origin, destination, planeName;
        Date flightDate;
        bool isCancelled;

        cout << "Enter origin city: ";
        cin >> origin;
        newFlight.setOriginCity(origin);

        cout << "Enter destination city: ";
        cin >> destination;
        newFlight.setDestinationCity(destination);

        cout << "Enter flight date (day month year hour minute): ";
        cin >> flightDate;
        newFlight.setFlightDate(flightDate);

        cout << "Enter plane name: ";
        cin >> planeName;
        newFlight.setPlaneName(planeName);

        cout << "Is the flight cancelled? (1 for Yes, 0 for No): ";
        cin >> isCancelled;
        newFlight.setIsCancelled(isCancelled);

        foreignFlightsList.push_back(newFlight);
        cout << "Foreign flight added successfully: " << flight << endl;
    } else {
        cout << "Cannot add more foreign flights! Maximum limit reached (10 flights)." << endl;
    }
}

void ForeignFlights::removeFlight(  string& flight){
    flightManager.removeForeignFlight(flight);
}

void ForeignFlights::displayFlights(const FlightManager& flightManager) {
    cout << "Foreign Flights List:" << endl;
    const vector<ForeignFlights>& flights = flightManager.getForeignFlights();
    for (size_t i = 0; i < flights.size(); ++i) {
        cout << i + 1 << ". " << flights[i] << endl;
    }
}
///////////////////////////END OF ForeignFlights//////////////////////////


//////////////////////////////DOMESTIC FLIGHTS/////////////////////////////
class DomesticFlights : public Airport {
private:
     string flightID;
     string originCity;
     string destinationCity;
     Date flightDate;
     string planeName;
     bool isCancelled;
     double price;

public:
    void setFlightID(  string& id);
    string getFlightID() ;

    void setOriginCity(  string& city);
    string getOriginCity() ;

    void setDestinationCity(  string& city);
    string getDestinationCity() ;

    void setFlightDate( Date& date);
    Date getFlightDate() ;

    void setPlaneName(  string& name);
    string getPlaneName() ;

    void setIsCancelled(bool cancelled);
    bool getIsCancelled() ;

    void setPrice(  double& _price);
    double getPrice() ;

    friend istream& operator>>( istream& in,DomesticFlights &a );
    friend ostream& operator<<( ostream& out, DomesticFlights &a);

    virtual void addFlight(  string& flight)override;
    virtual void removeFlight(string& flight, FlightManager& flightManager);
    virtual void displayFlights(const FlightManager& flightManager) const;


/////////////////////constructor////////////////////
DomesticFlights(string id = "", string origin = "", string dest = "", Date date = Date(), bool cancelled = false, double Price=10 , string plane = "")
        : flightID(id), originCity(origin), destinationCity(dest), flightDate(date), isCancelled(cancelled), price(Price) , planeName(plane) {}


//در تابع فایند از این اپراتور برای  جستوجو در لیست استفاده میشه
bool operator==(const DomesticFlights& a, const DomesticFlights& b) {
    return a.getFlightID() == b.getFlightID();
}

};
///////////////////////display////////////////////////////
void DomesticFlights::display() const {
        cout << "Flight ID: " << flightID << endl;
        cout << "Origin: " << originCity << endl;
        cout << "Destination: " << destinationCity << endl;
        cout << "Date: " << flightDate << endl;
        cout << "Plane Name: " << planeName << endl;
        cout << "DomesticFlight-Price: " << price << endl;
        cout << "Status: " << (isCancelled ? "Cancelled" : "Active") << endl;
        cout << "-------------------------" << endl;
}
///////////////////////////////////////////////////
void DomesticFlights::setFlightID(  string& id){
    flightID=id;
}

void DomesticFlights::setOriginCity(string& city){
    originCity=city;
}
void DomesticFlights::setDestinationCity(string& city){
    destinationCity=city;
}
void DomesticFlights::setFlightDate(Date& date){
    flightDate=date;
}
void DomesticFlights::setPlaneName(string& name){
    planeName=name;
}
void DomesticFlights::setIsCancelled(bool cancelled){
    isCancelled=cancelled;
}
void DomesticFlights::setPrice(  double& _price){
    price=_price;
}

///////////////////////////////////////////////
string DomesticFlights::getFlightID() { return flightID; }
string DomesticFlights::getOriginCity(){ return originCity; }
string DomesticFlights::getDestinationCity(){ return destinationCity; }
Date DomesticFlights::getFlightDate(){ return flightDate; }
string DomesticFlights::getPlaneName(){ return planeName; }
bool DomesticFlights::getIsCancelled(){ return isCancelled; }
double DomesticFlights::getPrice() {return price;}
////////////////////////////////////////////////
istream& operator>>( istream& in,DomesticFlights &a ){
    cout << "flight ID : ";cin>>a.flightID;
    cout<< "OriginCity: "; cin>>a.originCity;
    cout<< "DestinationCity: "; cin>>a.destinationCity;
    cout<< "FlightDate: "; cin>>a.flightDate;
    cout<< "PlaneName: "; cin>>a.planeName;
    cout<< "Is Cancelled?(1 for Yes, 0 for No): "; cin>>a.isCancelled;
    return in;
}
ostream& operator<<( ostream& out, DomesticFlights &a  ){
    cout<< "flight ID : "<<a.flightID<<endl;
    cout<< "OriginCity: "<<a.originCity<<endl;
    cout<< "DestinationCity: "<<a.destinationCity<<endl;
    cout<< "FlightDate: "<<a.flightDate<<endl;
    cout<< "PlaneName: "<<a.planeName<<endl;
    if (a.isCancelled == true){
        cout<< "CANCELLED!"<<endl;
    }else{ cout<< "NOT Cancelled"<<endl;}
    return out;
}
/////////////////////////////////////////////
void DomesticFlights::addFlight(  string& flight){
      if (domesticFlightsList.size() < 10) {
        for (const auto & existingFlight : domesticFlightsList) {
            if (existingFlight.getFlightID() == flight) {
                cout << "Flight already exists: " << flight << endl;
                return;
            }
        }

        DomesticFlights newFlight;
        newFlight.setFlightID(flight);


        string origin, destination, planeName;
        Date flightDate;
        bool isCancelled;

        cout << "Enter origin city: ";
        cin >> origin;
        newFlight.setOriginCity(origin);

        cout << "Enter destination city: ";
        cin >> destination;
        newFlight.setDestinationCity(destination);

        cout << "Enter flight date (day month year hour minute): ";
        cin >> flightDate;
        newFlight.setFlightDate(flightDate);

        cout << "Enter plane name: ";
        cin >> planeName;
        newFlight.setPlaneName(planeName);

        cout << "Is the flight cancelled? (1 for Yes, 0 for No): ";
        cin >> isCancelled;
        newFlight.setIsCancelled(isCancelled);


        domesticFlightsList.push_back(newFlight);
        cout << "Domestic flight added successfully: " << flight << endl;
    }else {
        cout << "Cannot add more domestic flights! Maximum limit reached (10 flights)." << endl;
    }
}

void DomesticFlights::removeFlight(  string& flight){

     flightManager.removeDomesticFlight(flight);
}

void DomesticFlights::displayFlights(){
    cout << "Domestic Flights List:" << endl;
    const vector<DomesticFlights>& flights = flightManager.getDomesticFlights();
    for (size_t i = 0; i < flights.size(); ++i) {
        cout << i + 1 << ". " << flights[i] << endl;
    }
}

//////////////////////END OF DOMESTIC FLIGHTS/////////////////////

////////////////////////////ADMIN////////////////////////////////
class Admin {
private:
     string adminName;
     string adminPassword;
     FlightManager& flightManager;//refrence to FlighrManager

public:
    Admin(FlightManager& fm, string name="admin",string passwd="1234");
    void setAdminName(string& name);
    string getAdminName() ;

    void setAdminPassword(string& password);
    string getAdminPassword() ;

    bool authenticate(string& name, string& password) ;
    void manageFlights();

    void addDomesticFlight(const DomesticFlights& flight);
    void addForeignFlight(const ForeignFlights& flight);
    void removeDomesticFlight(const string& flightID);
    void removeForeignFlight(const string& flightID);
};
///////////////////////////////////////
Admin::Admin(FlightManager& fm, string name, string passwd)
    : flightManager(fm), adminName(name), adminPassword(passwd) {}

void Admin::setAdminName(string& name){
    adminName=name;
}

string Admin::getAdminName(){ return adminName;}

void Admin::setAdminPassword(string& password){
    adminPassword=password;
}

string Admin::getAdminPassword(){return adminPassword;}

 bool Admin::authenticate(string& name, string& password){
    if (adminName==name&&adminPassword==password)
        return true;
    else
        return false;
 }

//////////////////////////////////////
void Admin::addDomesticFlight(const DomesticFlights& flight) {
        flightManager.addDomesticFlight(flight);
}

void Admin::addForeignFlight(const ForeignFlights& flight) {
        flightManager.addForeignFlight(flight);
}

void Admin::removeDomesticFlight(const string& flightID) {
        flightManager.removeDomesticFlight(flightID);
}

void Admin::removeForeignFlight(const string& flightID) {
        flightManager.removeForeignFlight(flightID);
}

void Admin::manageFlights() {                                            //show(print) Admin Panel
        cout << "\n--- Domestic Flights ----\n";

        for (const auto& flight : flightManager.getDomesticFlights()) {
            flight.display();
        }

        cout << "\n---Foreign Flights ---\n";
        for (const auto& flight : flightManager.getForeignFlights()) {
            flight.display();
        }
}
//////////////////////////end of Admin///////////////////////

//////////////////////////////    /////////////////////////
class Customer {
private:
    string name;
    double balance;
    FlightManager& flightManager;
    //string purchasedFlights; به صورت یک لیست نگه داری میکنیم
    vector<string> purchasedFlights;
    vector<string> flightHistory;

public:
    void setName(string& n);
    string getName() ;

    void setBalance(double b);
    double getBalance() ;
    void addBalance(double amount);

    void addpurchaseFlight(const string& flightID, FlightManager& flightManager, double price);
    string getPurchasedFlights() ;

    void refundTicket(const string& flightID);
    void displayAllFlights(const FlightManager& flightManager) const;
};
////////////////////////////////////////////////////////////////
void Customer::setName(string& n){
    name=n;
}
string Customer::getName(){ return name;}
void Customer::setBalance(double b){
    balance=b;
}
double Customer::getBalance(){ return balance;}

void Customer::addBalance(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Balance increased successfully. New balance: " << balance << endl;
    } else {
            cout << "The amount is invalid." << endl;
    }
}


void Customer::addpurchaseFlight(const string& flightID, FlightManager& flightManager, double price) {

    bool flightFound = false;
    for (const auto& flight : flightManager.getdomesticFlightsList()) {
        if (flight.getFlightID() == flightID) {
            flightFound = true;
            break;
        }
    }
    if (!flightFound) {
            for (const auto& flight : flightManager.getforeignFlightsList()) {
                if (flight.getFlightID() == flightID) {
                    flightFound = true;
                    break;
                }
            }
        }

    if (flightFound) {
            if (balance >= price) {
                balance -= price;
                purchasedFlights.push_back(flightID);
                flightHistory.push_back("Flight purchase: " + flightID + "- Price: " + to_string(price));
                cout << "Flight " << flightID << "Successfully purchased." << endl;
            } else {
                cout << "Your account balance is insufficient. Increase your balance." << endl;
            }
    } else {
            cout << "Flight " << flightID << " Not found in the flight list." << endl;
    }
}

void Customer::refundTicket(const string& flightID) {
        auto it = find(purchasedFlights.begin(), purchasedFlights.end(), flightID);
        if (it != purchasedFlights.end()) {
            // جریمه 10 درصدی برای استرداد بلیط
            double refundAmount = 0.9 * balance;
            balance -= refundAmount;
            flightHistory.push_back("Ticket refund: " + flightID + " - Refund amount: " + to_string(refundAmount));
            purchasedFlights.erase(it);
            cout << "Ticket" << flightID << "Refunded successfully. Refund amount: " << refundAmount << endl;
        } else {
            cout << "Flight" << flightID << " Not found in the purchased list." << endl;
        }
}

void Customer::displayFlightHistory() const {
        cout << "Purchase history:" << endl;
        for (const auto& history : flightHistory) {
            cout << history << endl;
        }
    }


void Customer::displayAllFlights(const FlightManager& flightManager) const {
        cout << "***All flights***" << endl;

        // نمایش پروازهای داخلی
        cout << "Domestic flights:" << endl;
        for (const auto& flight : flightManager.getdomesticFlightsList()) {
            flight.display();
        }
        cout << "Foreign flights:" << endl;
        for (const auto& flight : flightManager.getforeignFlightsList()) {
            flight.display();
        }
    }
};



/////////////////////////////////////////////////////////////////
class FlightManager {

private:
    vector<DomesticFlights> domesticFlightsList;
    vector<ForeignFlights> foreignFlightsList;


public:

    const vector<DomesticFlights>& getDomesticFlights() const {
        return domesticFlightsList;
    }

    const vector<ForeignFlights>& getForeignFlights() const {
        return foreignFlightsList;
    }

    void addDomesticFlight(const DomesticFlights& flight) {
        if (domesticFlightsList.size() < 10) {
            domesticFlightsList.push_back(flight);
            cout << "DomesticFlight Added : " << flight.getFlightID() << endl;
        } else {
            cout << "Cannot add more domestic flights! Maximum limit reached (10 flights)." << endl;
        }
    }

    void addForeignFlight(const ForeignFlights& flight) {
        if (foreignFlightsList.size() < 10) {
            foreignFlightsList.push_back(flight);
            cout << "ForeignFlight Added :" << flight.getFlightID() << endl;
        } else {
            cout << "Cannot add more foreign flights! Maximum limit reached (10 flights)." << endl;
        }
    }

     void removeDomesticFlight(const string& flightID) {
        auto it = find_if(domesticFlightsList.begin(), domesticFlightsList.end(), [&flightID](const DomesticFlights& flight) {
            return flight.getFlightID() == flightID;
        });

        if (it != domesticFlightsList.end()) {
            domesticFlightsList.erase(it);
            cout << "Domestic flight removed:" << flightID << endl;
        } else {
            cout << "Error: Domestic flight with ID " << flightID << " Not found." << endl;
        }
    }


    void removeForeignFlight(const string& flightID) {
        auto it = find_if(foreignFlightsList.begin(), foreignFlightsList.end(), [&flightID](const ForeignFlights& flight) {
            return flight.getFlightID() == flightID;
        });

        if (it != foreignFlightsList.end()) {
            foreignFlightsList.erase(it);
            cout << "Foreign flight removed:" << flightID << endl;
        } else {
            cout << "Error: Foreign flight with ID " << flightID << " Not found." << endl;
        }
    }


    const vector<DomesticFlights>& getDomesticFlights() const {
        return domesticFlightsList;
    }


    const vector<ForeignFlights>& getForeignFlights() const {
        return foreignFlightsList;
    }


    bool findFlight(const string& flightID) const {

        auto domesticIt = find_if(domesticFlightsList.begin(), domesticFlightsList.end(), [&flightID](const DomesticFlights& flight) {
            return flight.getFlightID() == flightID;
        });


        auto foreignIt = find_if(foreignFlightsList.begin(), foreignFlightsList.end(), [&flightID](const ForeignFlights& flight) {
            return flight.getFlightID() == flightID;
        });

        return (domesticIt != domesticFlightsList.end() || foreignIt != foreignFlightsList.end());
    }
};
/////////////////////////////////////////////////////////////////

///////////////menu Design////////////////////
void showMainMenu() {
    cout << "\n--- Main Menu ---\n";
    cout << "1. Login as Admin\n";
    cout << "2. Login as Customer\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}
void showAdminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. Add Domestic Flight\n";
    cout << "2. Add Foreign Flight\n";
    cout << "3. Remove Domestic Flight\n";
    cout << "4. Remove Foreign Flight\n";
    cout << "5. Display All Flights\n";
    cout << "6. Logout\n";
    cout << "Enter your choice: ";
}
void showCustomerMenu() {
    cout << "\n--- Customer Menu ---\n";
    cout << "1. View All Flights\n";
    cout << "2. Purchase Flight\n";
    cout << "3. Add Balance\n";
    cout << "4. Refund Ticket\n";
    cout << "5. View Purchase History\n";
    cout << "6. Logout\n";
    cout << "Enter your choice: ";
}
///////////////////////////////////////////////
int main(){

    FlightManager fm;
    Admin admin("admin", "1234"); // ادمین پیش‌فرض
    Customer customer;
    customer.setName("Yaser");
    customer.setBalance(1000.0);

    int mainChoice, adminChoice, customerChoice;
    string flightID, origin, destination, planeName;
    double price;
    Date date;
    bool isCancelled;

while (true) {
    showMainMenu();
    cin >> mainChoice;

    if (mainChoice == 1) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (admin.authenticate(username, password)) {
                    while (true) {
                    showAdminMenu();
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        cout << "Enter Flight ID: ";
                        cin >> flightID;
                        cout << "Enter Origin: ";
                        cin >> origin;
                        cout << "Enter Destination: ";
                        cin >> destination;
                        cout << "Enter Date (day month year hour minute): ";
                        cin >> date;
                        cout << "Enter Plane Name: ";
                        cin >> planeName;
                        cout << "Enter Price: ";
                        cin >> price;

                        DomesticFlights df(flightID, origin, destination, date, false, price, planeName);
                        fm.addDomesticFlight(df);

                    } else if (adminChoice == 2) {
                        cout << "Enter Flight ID: ";
                        cin >> flightID;
                        cout << "Enter Origin: ";
                        cin >> origin;
                        cout << "Enter Destination: ";
                        cin >> destination;
                        cout << "Enter Date (day month year hour minute): ";
                        cin >> date;
                        cout << "Enter Plane Name: ";
                        cin >> planeName;
                        cout << "Enter Price: ";
                        cin >> price;

                        ForeignFlights ff(flightID, origin, destination, date, false, price, planeName);
                        fm.addForeignFlight(ff);

                    } else if (adminChoice == 3) {
                        cout << "Enter Flight ID to remove: ";
                        cin >> flightID;
                        fm.removeDomesticFlight(flightID);

                    } else if (adminChoice == 4) {
                        cout << "Enter Flight ID to remove: ";
                        cin >> flightID;
                        fm.removeForeignFlight(flightID);
                    } else if (adminChoice == 5) {
                        customer.displayAllFlights(fm);

                    } else if (adminChoice == 6) {
                        break;

                    } else {
                        cout << "Invalid choice! Try again.\n";
                    }

    }
        } else if (mainChoice == 2) {
            while (true) {
                showCustomerMenu();
                cin >> customerChoice;

                if (customerChoice == 1) {
                    customer.displayAllFlights(fm);

                } else if (customerChoice == 2) {
                    cout << "Enter Flight ID to purchase: ";
                    cin >> flightID;
                    cout << "Enter Price: ";
                    cin >> price;
                    customer.addpurchaseFlight(flightID, fm, price);

                } else if (customerChoice == 3) {
                    double amount;
                    cout << "Enter amount to add: ";
                    cin >> amount;
                    customer.addBalance(amount);

                } else if (customerChoice == 4) {
                    cout << "Enter Flight ID to refund: ";
                    cin >> flightID;
                    customer.refundTicket(flightID);

                } else if (customerChoice == 5) {
                    customer.displayFlightHistory();

                } else if (customerChoice == 6) {
                    break;

                } else {
                    cout << "Invalid choice! Try again.\n";
                }

    }
        } else if (mainChoice == 3) {
             cout << "Exiting program...\n";
             break;

        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }


return 0;



}

