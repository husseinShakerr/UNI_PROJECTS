#Python 3
#Filnamn: hual2302_1.3_v1.py
#Skrivet av: Hussein Shaker
#Skapat datum: 2023-09-22
#Kurs: Grundläggande datavetenskap
#Handledare: Karl Pettersson
#Beskrivning: Denna programkod räknar ut moms samt pris med moms utav till exempel en produkt.

pris_utan_moms = input('Skriv in ett pris utan moms: ')
moms = int(pris_utan_moms) * 0.25
pris_med_moms = moms + int(pris_utan_moms)
print('Moms: ', moms)
print('Pris med moms: ', pris_med_moms)