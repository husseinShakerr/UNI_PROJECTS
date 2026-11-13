#Python 3
#Filnamn: hual2302_3.3_v1.py
#Skrivet av: Hussein Shaker
#Skapat datum: 2023-09-26
#Kurs: Grundläggande datavetenskap
#Handledare: Karl Pettersson
#Beskrivning: Denna programkod räknar ut om ett år är ett skottår eller ej.

årtal = int(input('Ange ett årtal: '))
if årtal % 4 == 0:
    if årtal % 100 == 0:
        if årtal % 400 == 0:
            print(årtal, 'är ett skottår')
        else: print(årtal, 'är inte ett skottår')
    else: print(årtal, 'är ett skottår.')
else: print(årtal, 'är inte ett skottår.')