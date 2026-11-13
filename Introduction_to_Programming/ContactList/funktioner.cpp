// Hussein Shaker
// 2023-11-26
// DT178G/DT028G
// Projektarbete. Funktioner.


#include "funktioner.h"

void create_contact()
{
    std::fstream lista;
    con insertion;
    std::string opt;
    bool creating_con = true;
    while(creating_con)
    {
    bool entered_firstname = false;
    //Loopen för varje element fortsätter om man inte matar in något.
    do
    {
    std::cout<<std::string(100, '\n');
    if(entered_firstname)
    {
        std::cout<<"This field can not be empty, please type something."<<std::endl;
    }
    std::cout<<"Enter firstname(press '-' to skip): "<<std::endl;
    std::getline(std::cin, insertion.first_name);
    entered_firstname = true;
    }while(insertion.first_name.empty());


    bool entered_surname = false;
    do
    {
    std::cout<<std::string(100, '\n');
    if(entered_surname)
    {
        std::cout<<"This field can not be empty, please type something."<<std::endl;
    }
    std::cout<<"Enter surname(press '-' to skip): "<<std::endl;
    std::getline(std::cin, insertion.surname);
    entered_surname = true;
    }while(insertion.surname.empty());
    

    bool entered_adress = false;
    do
    {
    std::cout<<std::string(100, '\n');
    if(entered_adress)
    {
        std::cout<<"This field can not be empty, please type something."<<std::endl;
    }
    std::cout<<"Enter adress(press '-' to skip): "<<std::endl;
    std::getline(std::cin, insertion.adress);
    entered_adress = true;
    }while(insertion.adress.empty());


    bool entered_epost = false;
    do
    {
    std::cout<<std::string(100, '\n');
    if(entered_epost)
    {
        std::cout<<"This field can not be empty, please type something."<<std::endl;
    }
    std::cout<<"Enter e-mailadress(press '-' to skip): "<<std::endl;
    std::getline(std::cin, insertion.epost);
    entered_epost = true;
    }while(insertion.epost.empty());


    /*Sätter in inmatat telefonnummer som parameter till den anropade funktionen.
    Första loopen är while-satsen alltid sann då första gången den körs är 'insertion.phoneNum' tom. 
    Om man skriver rätt format går programmet vidare, annars kommer 'entered_phone_number' vara sant
    och exevera if-sats blocket.
    */
    std::cout<<std::string(100, '\n');
    bool entered_phone_number=false;
    while(!phone_check(insertion.phoneNum))
    {
        if(entered_phone_number)
        {
            std::cout<<std::string(100, '\n');
            std::cout<<"Invalid phonenumber, you need to type exactly 10 digits."<<std::endl;
        }

        std::cout<<"Enter a phonenumber of 10 digits(Required): "<<std::endl;
        std::getline(std::cin, insertion.phoneNum);
        entered_phone_number=true;
    }

    //Samma algoritm som föregående element.
    std::cout<<std::string(100, '\n');
    bool entered_birthday = false;
    while(!birth_check(insertion.birthday))
    {
        if(entered_birthday)
        {
            std::cout<<std::string(100, '\n');
            std::cout<<"Invalid birthday, please try again."<<std::endl;
        }
        std::cout<<"Enter birthday[YYYYMMDD](Type '-' to skip): "<<std::endl;
        std::getline(std::cin, insertion.birthday);
        entered_birthday = true;
        if(insertion.birthday == "-")
        {
            break;
        }
    }

    std::cout<<std::string(100, '\n');
    std::cout<<"Press '1' to save contact."<<std::endl;
    std::cout<<"Press '2' to cancel"<<std::endl;
    std::getline(std::cin, opt);
    //Så länge inmatningen inte är '0' eller '1' eller är mer än en karaktär kommer while-loopen att fortsätta.
    while(opt[0] != '1' && opt[0] != '2' || opt.length() > 1)
    {
        std::cout<<std::string(100, '\n');
        std::cout<<"Invalid input, please try again!"<<std::endl;
        std::cout<<"Press '1' to save contact."<<std::endl;
        std::cout<<"Press '2' to cancel."<<std::endl;
        std::getline(std::cin, opt);
    }
    switch(opt[0])
    {

        case '1':
        std::cout<<std::string(100, '\n');
        lista.open("kontaktlista.txt",  std::ios::out | std::ios::app);
        if(!lista.is_open())
        {
            std::cerr<<"Failed to open your contactlist file...Exiting the program."<<std::endl;
        }
        //Skriver ut kontakten till textfilen.
        lista << insertion.first_name << " " << insertion.surname<< " " << insertion.adress << " "<< insertion.epost << " "<< insertion.phoneNum << " "<< insertion.birthday << "\n";
        lista.close();
        std::cout<<"Contact saved."<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        return;
        break;

        case '2':
        std::cout<<std::string(100, '\n');
        return;
        break;
    }
    }
}

bool phone_check(std::string PN)
{
    //Om parametern inte består av 10 siffror, funktionen returnerar falskt.
    if(PN.length() != 10)
    {
        return false;
    }
    /*Om ASCII värdet för karaktärerna inmatade är större eller mindre än ASCII värdet för '0' och '9' returnerar funktionen falskt.
    Alltså man måste skriva in karaktärer mellan 0 och 9.*/
    for(int i = 0; i < 10; i++)
    {
        if(PN[i] < '0' || PN[i] > '9')
        {
            return false;
        }
    }
    return true;
}

bool birth_check(std::string BD)
{
    //Om parametern inte består av 8 siffror, funktionen returnerar falskt.
    if(BD.length() != 8)
    {
        return false;
    }
    //Samma algoritm som "phone_check()"
    for(int i = 0; i < 8; i++)
    {
        if(BD[i] < '0' || BD[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void search_contact()
{
    std::fstream lista;
    std::cout<<std::string(100, '\n');
    std::vector<std::string> matches;
    std::string contact, searchstring;
    con contacts_found; 
    bool found;
    lista.open("kontaktlista.txt", std::ios::in);
    if(!lista.is_open())
    {
        std::cerr<<"Filed to open your contactlist file, please try again later."<<std::endl;
        return;
    }
    std::cout<<"Enter 'cancel_search' if you want to cancel."<<std::endl;
    std::cout<<"Enter the contact you want to find: "<<std::endl;
    std::getline(std::cin, searchstring);
    if(searchstring == "cancel_search")
    {
    lista.close();
    return;
    }
    //Omvandlar söksträngen och innehållet i textfilen till små bokstäver så jag kan jämföra.
    std::transform(searchstring.begin(), searchstring.end(), searchstring.begin(), ::tolower);
    while (std::getline(lista, contact))
    {
        std::transform(contact.begin(), contact.end(), contact.begin(), ::tolower);
        //Om söksträngen hittas i linjen, läggs hela linjen till i matches(vector).
        //Och så fort den hittar en matchning, found-variabeln blir sann.
        if(contact.find(searchstring) != std::string::npos)
        {
            found = true;
            matches.push_back(contact);
        }
    }
    lista.close();
    //Om found är sann skriver programmet ut hela matches(vector).
    if(found)
    {
    std::cout<<std::string(100, '\n');
    std::cout<<"Best matches to '"+searchstring+ "': \n"<<std::endl;
        for(auto itr = matches.begin(); itr != matches.end(); itr++)
        {
            std::cout<<(*itr)<<std::endl;
            std::cout<<"------------------------------------"<<std::endl;
        }
    }
    else
    {
        std::cout<<std::string(100, '\n');
        std::cout<<"Could not find '" +searchstring+ "' in your contact list."<<std::endl;
    }  
    lista.close();
    user_choice();
}

void delete_contact()
{   
    bool deleting = true;
    while(deleting)
    {
    int line_number = 0;
    std::string searchstring, line;
    std::fstream read, temp;
    std::vector<std::string> matches;
    std::vector<int> matches_line_numbers;
    std::cout<<"Search the contact you want to delete."<<std::endl;
    std::getline(std::cin, searchstring);
    //Omvandlar söksträngen till små bokstäver.
    std::transform(searchstring.begin(), searchstring.end(), searchstring.begin(), ::tolower);
    read.open("kontaktlista.txt", std::ios::in);
    while(std::getline(read, line))
    {
        //Omvandlar linjens karaktärer till små bokstäver.
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        /*
        Om söksträngen hittas i linjen, läggs linjen till i matches(vector<string>).
        Lägger till 'line_number' i matches_line_numbers(vector<integer>).
        'line_number' ökar med 1 vid varje matchning.
        */
        if(line.find(searchstring) != std::string::npos)
        {
            matches.push_back(line);
            matches_line_numbers.push_back(line_number);
        }
        line_number++;
    }
    read.close();
    //Om ingen matchning hittas, exekveras if-sats blocket.
    if(matches.empty())
    {
        std::cout<<std::string(100, '\n');
        std::cout<<"Could not find '" +searchstring+ "'."<<std::endl;
        std::string opt;
        std::cout<<"Press '0' if you want to go back to main."<<std::endl;
        std::cout<<"Press '1' if you want to try again."<<std::endl;
        std::getline(std::cin, opt);
        while(opt[0] != '1' && opt[0] != '0' || opt.length() > 1)
        {
            std::cout<<std::string(100, '\n');
            std::cout<<"Invalid input, please try again!"<<std::endl;
            std::cout<<"Press '0' if you want to go back to main."<<std::endl;
            std::cout<<"Press '1' if you want to try again."<<std::endl;
            std::getline(std::cin, opt);
        }

        
        if(opt[0] == '1')
        {
            continue;
        }
        deleting = false;
        continue;
    }
    std::cout<<std::string(100, '\n');
    std::cout<<"Following matches found:"<<std::endl;
    //Skriver ut alla matchningar som har lagrats i mathcningsvectorn.
    for(int index = 0; index < matches.size(); index++)
    {
        std::cout << index << ": " << matches[index]<< std::endl;
    }
    std::cout<<"Select the number of the contact you want to delete."<<std::endl;
    std::string ln;
    std::getline(std::cin,ln);
    //Omvandlar inmatningen från string till int och tilldelar värdet till variabeln line_choice.
    int line_choice = std::atoi(ln.c_str());
    /*
    Om inmatningen är större än antal matchningar...Tilldelas line_choice värdet av antalet matchningar - 1, vilket kommer automatiskt
    att radera linjen med det största värdet av indexet (Linjen som ligger längst ned för användare).
    */
    if(line_choice>matches_line_numbers.size()-1)
    {
        line_choice = matches_line_numbers.size()-1;
    }
    read.open("kontaktlista.txt", std::ios::in);
    //Öppnar en temporär textfil för utskrift.
    temp.open ("kontaktlista.tmp", std::ios::out);
    line_number = 0;
    while(std::getline(read, line))
    {
        //Skriver över alla linjer förutom linjen som matchar med inmatningen.
        if(line_number != matches_line_numbers[line_choice])
        {
            temp << line << '\n';
        }
        line_number++;
    }
    read.close();
    temp.close();
    //Raderar gamla filen och byter namn på den nya filen till samma namn som ursprungsfilen.
    remove("kontaktlista.txt");
    rename("kontaktlista.tmp","kontaktlista.txt");
    
    std::cout<<std::string(100, '\n');
    std::cout<<"------------------------------------"<<std::endl;
    std::cout << "Contact removed successfully!" << std::endl;
    deleting=false;
    }
}

void user_choice()
{
std::string opt; 
std::string usrchoicetxt = 
"Press '0' if you want to go back to main menu.\n"
"Press '1' if you want to search again.\n";
std::cout<<usrchoicetxt;
    while(std::getline(std::cin, opt))
    {
        if(opt == "0")
        {
            std::cout<<std::string(100, '\n');
            return;
        }
        if(opt == "1")
        {
            std::cout<<std::string(100, '\n');
            search_contact();
            return;
        }
        else if(opt.length() > 1)
        {
        std::cout<<std::string(100, '\n');
        std::cout<<"Invalid input, please try again!"<<std::endl;
        std::cout<<usrchoicetxt;
        continue;
        }
    }
}

void show_list()
{
    std::fstream liststream;
    std::string choice_text = "Press '0' if you want to go back to main menu.";
    std::string list_output, opt;
    liststream.open("kontaktlista.txt", std::ios::in);
    if(!liststream.is_open())
    {
        std::cerr<<"Failed to open your contactlist file...Exiting the program."<<std::endl;
    }
    while(std::getline(liststream, list_output))
    {
        std::cout<<list_output<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        liststream.clear();
    }
    std::cout<<choice_text<<std::endl;
    while(std::cin>>opt)
    {
    if(opt == "0")
    {
        std::cout<<std::string(100, '\n');
        return;
    }
    else if(opt.length() > 1)
    {
    std::cout<<std::string(100, '\n');
    std::cout<<"Invalid input, please try again."<<std::endl;
    std::cout<<choice_text<<std::endl;
    continue;
    }
    }
    liststream.close();
}
