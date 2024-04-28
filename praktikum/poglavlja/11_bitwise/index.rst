Bitwise
=======

Podeli svoje utiske o poglavlju na anketi ...

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Postoje različite reprezentacije brojeva spram cifara koje se koriste. Najčešći je decimalni zapis brojeva, gde se svi brojevi zapisuju ciframa 0,1,2,3,4,5,6,7,8,9. Ako je broj veći od cifara kojim se može zapisati, dodaje se sa leve strane sledeća cifra, npr. broj 10 je za 1 veći od najveće cifre 9, te se zapisuje pomoću 2 cifre.

Osim decimalnog, za računarstvo su bitni binarni i heksadecimalni zapis. Binarni zapis broja koristi samo dve cifre: 0 i 1. Ove cifre predstavljaju individualne bitove - osnovne jedinice informacije u računarstvu. 

Heksadecimalni zapis koristi 16 cifara - osnovnih 10 cifara decimalnog zapisa, uz cifre A, B, C, D, E, F koje predstavljaju redom brojeve 10, 11, 12, 13, 14, 15. Kako 4 binarne cifre mogu predstaviti 16 vrednosti, cifre heksadecimalnih brojeva odgovaraju grupama od po 4 cifre u binarnom zapisu.

Primeri brojeva u decimalnom, binarnom i heksadecimalnom zapisu:

* 1,   1,   00000001
* 10,  A,   00001010
* 11,  B,   00001011
* 16,  10,  00010000

Postoje operacije za rad sa bitovima ``int`` i ``char`` vrednosti. Te operacije su:

* ``&`` - logičko ``i`` bit po bit - poredi bitove na svakoj poziciji i ako su oba 1 daje 1, u ostalim slučajevima na toj poziciji daje 0
* ``|`` - logičko ``ili`` bit po bit - poredi bitove na svakoj poziciji i ako je bar jedan od njih 1 daje 1, u ostalim slučajevima na toj poziciji daje 0
* ``^`` - ekskluzivno ``ili`` bit po bit - poredi bitove na svakoj poziciji i ako je tačno jedan od njih 1 daje 1, u ostalim slučajevima na toj poziciji daje 0
* ``<<`` - levi pomak - bit po bit pomera sve bitove u levo onoliko puta koliko se navede nakon operatora, najdesnije bite postavlja na 0
* ``<<`` - desni pomak - bit po bit pomera sve bitove u desno onoliko puta koliko se navede nakon operatora, najlevlje bite postavlja na 0
* ``~`` - negacija - obrće vrednost svakog bita
	
Uz ove operacije moguće je staviti ``=`` da se rezultat dodeli promenljivoj sa leve strane. 

Primer programa
---------------

Ispod je primer ispisa unetog broja u binarnom zapisu:

.. literalinclude:: primeri/bitwise.c
   :linenos:

Prvo se definiše maska - heksadecimalni broj ``0x8000``, koji je u binarnom zapisu: ``1000 0000 0000 0000``, jer svaka heksadecimalna cifra odgovara četiri binarne cifre, a binarni zapis broja ``8`` je ``1000``. Dužina ``short`` promenljive je 2 bajta, odnosno 16 bita. 

U funkciji za binarni ispis petlja će odraditi 16 iteracija - po jednu za svaku binarnu cifru. Broj se ispisuje sa leva na desno - prvo se ispisuje prva cifra tako što se broj logičkim ``i`` obradi maskom - sve cifre unetog broja će biti 0, sem prve, koja će ostati nepromenjena. 

Broj će nakon primene maske biti 0 ako je prva cifra 0, a ``0x8000`` ako je prva cifra 1. Nakon ispisa cifre (1 ili 0, rezultat poređenja sa 0) na binarni zapis broja se primenjuje ``levo pomeranje``, pa se svaka cifra pomera ulevo. 

Nakon svakih 4 ispisanih cifara ispisuje se prazan prostor, da bi se binarni broj razdvojio na po 4 cifre. Ispis će tada izgledati:

.. literalinclude:: primeri/primer.txt
   :language: none

