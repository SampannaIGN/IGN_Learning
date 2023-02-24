/*

*Display title "Tour Ticket Prices from Miami" in the middle 
*Also display country name,city name, population and 
price in proper order one after the other
*structures have already been created & initialized just print 
the output in an organized way.

*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void solution(){

    Tours tours{ "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                    },
                },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                    } 
                },
            }
        };

    int maxLen = 100;
    int title_width = tours.title.length()+((maxLen-tours.title.length())/2);
    
    cout<<setw(title_width)<<right<<tours.title <<endl<<endl;
    
    cout<<setw(maxLen/4)<<left<<"Country"
        <<setw(maxLen/4)<<left<<"City"
        <<setw(maxLen/4)<<left<<"Population"
        <<setw(maxLen/4)<<left<<"Price"
        <<endl;
    for(int i = 0; i < 100; i++)cout<<'-';cout<<endl;
    
    
    for(auto country : tours.countries) {   // loop through the countries
        
        cout<<setw(maxLen/4)<<left<<country.name;
        bool firstflag = true;
        
        for(auto city : country.cities) {       // loop through the cities for each country
            if(!firstflag)cout <<setw(maxLen/4)<<left<<" ";

            cout<<setw(maxLen/4)<<left<< city.name 
                <<setw(maxLen/4)<<left<< city.population 
                <<setw(maxLen/4)<<left<< city.cost<<endl; 
            firstflag = false;
        }
    }

    std::cout << std::endl << std::endl;
}

int main()
{   
    solution();
    return 0;
}