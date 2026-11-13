/**
 * @Hussein Alshaikhshaker
 * Datum: 2024-04-25
 * Kurs: DT019G/DT026G
 * Fil: Denna fil innehåller struktorer, funktioner, överlagrade
 * operatorer samt main.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

struct Address{
    std::string Street;
    int Zip;
    std::string City;
    Address(std::string street, int zip, std::string city){
        Street = std::move(street);
        Zip = zip;
        City = std::move(city);
    }
    Address() = default;
};
struct Person{
    std::string Name;
    std::string Id;
    Address Location;
    Person(std::string name, std::string id, Address location){
        Name = std::move(name);
        Id = std::move(id);
        Location = std::move(location);
    }
    Person() = default;
};
std::istream& operator>>(std::istream& in, Person& p){
    std::getline(in, p.Name);
    std::getline(in,p.Id);
    std::string streetLine, street, zip, city;
    std::getline(in, streetLine);

    size_t comma = streetLine.find(",");
    if(comma == std::string::npos)
        return in;
    street = streetLine.substr(0, comma);
    zip = streetLine.substr(comma+2, comma+6);
    zip.erase(std::remove(zip.begin(), zip.end(), ' '), zip.end());
    city = streetLine.substr(comma+10);
    size_t last_char_in_city = city.find_last_not_of(' ');
    city.erase(last_char_in_city+1);
    int zipCode = stoi(zip);
    
    p.Location.Street = street;
    p.Location.City = city;
    p.Location.Zip = zipCode;

    return in;
}
std::ostream& operator<<(std::ostream& personWriter, const Person& p){
    personWriter << p.Name << ", " << p.Id << ", " << p.Location.Street << ", " << p.Location.Zip << " " << p.Location.City << '\n';
    return personWriter;
}
std::vector<Person> read_file (std::string filename){
    std::vector<Person> people;
    std::ifstream reader(filename);
    if(!reader.is_open()){
        throw std::runtime_error("filed to open: '" + filename + "'");
    }
    while(!reader.eof()){
        Person p;
        reader>>p;
        people.push_back(p);
    }
    reader.close();
    return people;
}

size_t find_in_names(const std::vector<Person>& haystack, std::string name_part){
    size_t counter = 0;
    std::transform(name_part.begin(), name_part.end(), name_part.begin(), ::tolower);
    for (Person person : haystack){
        std::transform(person.Name.begin(), person.Name.end(), person.Name.begin(), ::tolower);
        if (person.Name.find(name_part) != std::string::npos)
        {
            counter++;
        }
    }
    return counter;
}
std::vector<Person> find_person_from_city(const std::vector<Person>& haystack, std::string city){
    std::transform(city.begin(), city.end(), city.begin(), ::toupper);
    std::vector<Person> cities;
    for(const Person& p : haystack) {
        if (p.Location.City == city) {
            cities.push_back(p);
        }
    }
    return cities;
}

int main() {
    std::cout<<std::string(100, '\n');
    bool running = true;
    std::vector<Person> personList = read_file("names.txt");
    while(running)
    {
        char user_choice;
        std::cout<< "Enter '1' to search a name in the list\n"
                    "Enter '2' to search a person in a city\n"
                    "Enter '3' to exit program"<<std::endl;
        std::cin>>user_choice;
        std::cin.ignore();
        switch (user_choice)
        {
        case '1':
        {
            std::cout << std::string(100, '\n');
            std::string search_name;
            std::cout << "Enter name: " <<std::endl;
            std::getline(std::cin, search_name);
            std::cout<<std::string(100, '\n');
            size_t matches = find_in_names(personList, search_name);
            std::cout<<"Found " << matches <<  " matches. \n\n" <<std::endl;
        
            break;
        }
        case '2':
        {
            std::cout<<std::string(100, '\n');
            std::string search_city;
            std::cout<<"Enter the city you want to search through: " <<std::endl;
            std::getline(std::cin, search_city);
            std::cout<<std::string(100, '\n');
            std::vector<Person> found_persons = find_person_from_city(personList, search_city);
            if(found_persons.empty()){
                std::cout<<"Found no matches."<<std::endl;
            }
            else
            {
                std::cout << "Found following matches: \n" <<
                "------------------------" << std::endl;
                for (Person p : found_persons) {
                std::cout << p << std::endl;
                std::cout << "------------------------------------" << std::endl;
                }
            }
            break;
        }
        case '3':
        {
            std::cout<<"Exiting program..."<<std::endl;
            running = false;
            break;
        }
        default:
            std::cout<<std::string(100, '\n');
            std::cout<<"Invalid input, try again"<<std::endl;
            break;
        }
    }
    return 0;
}