#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>

int main() {
    int seriellPort; //Variabel för check av seriella porten
    char mottagenKar;  //Variabel för att lagra mottagna tecken.

    seriellPort = serialOpen("/dev/serial0", 1200); //Öppnar seriell port, med baudrate på 1200.
    //Om porten inte kan öppnas.
    if (seriellPort < 0) {
        std::cerr << "Kunde ej öppna seriell port" << std::endl;
        return 1;
    }

    wiringPiSetup(); //Initierar WiringPI biblioteket.
    //Oändlig loop som läser inkommande seriell data.
    while (true) {
	//Om data finns tillänglig i seriella bufferten, skriv ut datat.
        if (serialDataAvail(seriellPort)) {
            //mottagenKar = serialGetchar(seriellPort);
            printf("%c," serialGetchar(seriellPort));
        }
    } 

    return 0;
}
