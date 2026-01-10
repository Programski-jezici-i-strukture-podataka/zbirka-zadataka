Sa terminala učitati potrošnju struje po domaćinstvima u niz od maksimalno 30 elemenata. 
Omogućiti korisniku da unese i manji broj elemenata od maksimalnog i napraviti zaštitu unosa. Korisnik mora da unese prirodan broj, ne veći od maksimalnog broja elemenata.

Preko terminala uneti naziv tarife (moguće vrednosti su osnovna, visa, niza). U zavisnosti od tarife i zone u kojoj se nalazi domaćinstvo, izračunati cenu struje i zaokružiti je na dve decimale. Prilikom unosa tarife od strane korisnika, jedine moguće vrednosti su osnovna, visa, niza, potrebno je napisati odgovarajuću zaštitu.

Osim računanja cene struje po domaćinstvu, potrebno je i izračunati koliko domaćinstava pripada zelenoj, koliko plavoj, a koliko crvenoj zoni.

============================ ============================= ========================== ==========================
ZONA                         CENA OSNOVNE TARIFE (din/kWh) CENA VIŠE TARIFE (din/kWh) CENA NIŽE TARIFE (din/kWh)
============================ ============================= ========================== ==========================
ZELENA ZONA (do 350 kWh)       5.108                         5.962                     1.491
PLAVA ZONA (351-1600 kWh)      7.658                         8.943                     2.236
CRVENA ZONA (preko 1600 kWh)  15.330                        18.588                     4.647
============================ ============================= ========================== ==========================

Primer učitavanja podataka preko terminala:

.. literalinclude:: rad-programa.txt
   :language: none

Ispis rezultata na terminal:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer unosa i ispisa za nizu tarifu i samo jedno domaćinstvo.

.. literalinclude:: rad-programa-jedno-domacinstvo.txt
   :language: none
