Bitwise
=======

Podeli svoje utiske o poglavlju na anketi https://docs.google.com/forms/d/1D8Xjy-0dB8AAETCUiHP8NX0W5qQxUCydenIeY9YGMnI

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

Dodatne nule u primerima služe da bi se videlo da grupe od 4 cifre odgovaraju jednoj heksadecimalnoj cifri, inače se mogu izostaviti.

Postoje operacije za rad sa bitovima ``int`` i ``char`` vrednosti. Te operacije su:

* ``&`` - logičko ``i`` bit po bit - poredi bitove na svakoj poziciji i ako su oba 1 daje 1, u ostalim slučajevima na toj poziciji daje 0
* ``|`` - logičko ``ili`` bit po bit - poredi bitove na svakoj poziciji i ako je bar jedan od njih 1 daje 1, u ostalim slučajevima na toj poziciji daje 0
* ``^`` - ekskluzivno ``ili`` bit po bit - poredi bitove na svakoj poziciji i ako je tačno jedan od njih 1 daje 1, u ostalim slučajevima na toj poziciji daje 0
* ``<<`` - levi pomak - bit po bit pomera sve bitove u levo onoliko puta koliko se navede nakon operatora, najdesnije bite postavlja na 0
* ``<<`` - desni pomak - bit po bit pomera sve bitove u desno onoliko puta koliko se navede nakon operatora, najlevlje bite postavlja na 0
* ``~`` - negacija - obrće vrednost svakog bita
	
Uz ove operacije moguće je staviti ``=`` da se rezultat dodeli promenljivoj sa leve strane. Slično kao ``+=``, može se koristiti ``&=`` itd.

Bitwise operatori se razlikuju od logičkih operatora:
* Bitwise ``i`` se piše ``&``, dok se logičko ``i`` piše ``&&``
* Bitwise ``ili`` se piše ``|``, dok se logičko ``ili`` piše ``||``
* Bitwise ``negacija`` se piše ``~``, dok se logička ``negacija`` piše ``!``

Primeri razlike bitwise i logičkih operatora:

* ``6 & 4`` će porediti bitove brojeva 0110 i 0100, kako je 1 na drugom mestu oba broja (sa leva) rezultat će biti 0100 što je 4.
* ``6 && 4`` će logički porediti 6 i 4, kako su oba tačna (sve vrednosti sem 0 su tačne) rezultat će biti 1
* ``5 | 3`` će porediti bitove brojeva 0101 i 0011, kako je 1 na drugom, trećem i četvrtom mestu (sa leva) bar jednog od brojeva, rezultat će biti 0111 što je 7
* ``5 || 3`` će logički porediti 5 i 3, kako su oba tačna (sve vrednosti sem 0 su tačne) rezultat će biti 1 
* ``~5`` će obrnuti bitove broja 5, rezultat zavisi od formata broja, ako je ``short int`` će 0000 0000 0000 0101 postati 1111 1111 1111 1010 što je 65530, za veće tipove će biti više bitova te će rezultat biti veći
* ``!5`` će logički obrnuti broj 5, pošto je 5 logički tačna vrednost, obrnuto je netačna, te je rezultat 0

Primer programa
---------------

Ispod je primer ispisa unetog broja u binarnom zapisu:

.. literalinclude:: primeri/bitwise.c
   :linenos:

Prvo se definiše maska - heksadecimalni broj ``0x8000``, koji je u binarnom zapisu: ``1000 0000 0000 0000``, jer svaka heksadecimalna cifra odgovara četiri binarne cifre, a binarni zapis broja ``8`` je ``1000``. Dužina ``short`` promenljive je 2 bajta, odnosno 16 bita. Bit-maska nam služi da zajedno sa operacijom izvučemo iz binarnog zapisa broja konkretne bite, u ovom slučaju prvi bit.

U funkciji za binarni ispis petlja će odraditi 16 iteracija - po jednu za svaku binarnu cifru. Broj se ispisuje sa leva na desno - prvo se ispisuje prva cifra tako što se broj logičkim ``i`` obradi maskom - sve cifre unetog broja će biti 0, sem prve, koja će ostati nepromenjena. 

Broj će nakon primene maske biti 0 ako je prva cifra 0, a ``0x8000`` ako je prva cifra 1. Nakon ispisa cifre (1 ili 0, rezultat poređenja sa 0) na binarni zapis broja se primenjuje ``levo pomeranje``, pa se svaka cifra pomera ulevo. 

Nakon svakih 4 ispisanih cifara ispisuje se prazan prostor, da bi se binarni broj razdvojio na po 4 cifre. Ispis će tada izgledati:

.. literalinclude:: primeri/primer.txt
   :language: none

