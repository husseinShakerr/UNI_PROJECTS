#Python 3
#Filnamn: hual2302_2.1_v1.py
#Skrivet av: Hussein Shaker
#Skapat datum: 2023-09-25
#Kurs: Grundläggande datavetenskap
#Handledare: Karl Pettersson
#Beskrivning: Denna programkod räknar ut om ett tal är udda eller jämnt. 

udda_jämnt = int(input('Skriv ett tal för att se om det är uddda eller jämnt: '))
if (udda_jämnt % 2) == 0:
    print("Talet", udda_jämnt, "är jämnt.")
else:
    print("Talet", udda_jämnt, "är udda.")
    