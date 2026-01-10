Napisati program koji dekodira poruke napisane pomoću Morzeove abecede.
Podaci su zadati u ulaznoj datoteci u sledećem formatu:

* `slovo` (jedan karakter)
* `kod` (jedna reč, do 5 karaktera)

Učitati Morzeove kodove u statički niz, na osnovu kojih će se u izlaznu datoteku ispisati dekodirane reči.
Ime ulazne i izlazne datoteke se zadaju kao argument komandne linije, dok se reči napisane u Morzeovoj azbuci zadaju preko standardnog ulaza.
Korisnik programa unosi reči čija su pojedinačni kodovi slova razdvojeni jednim razmakom dokle god ne unese string ``kraj``, što označava kraj korisničkog unosa (pogledati primer rada programa).
Ukoliko je unet Morzeov kod koji nije definisan u ulaznoj datoteci, umesto slova napisati upitnik ``?``.
Pretpostaviti da će korisnik isključivo unositi karaktere ``-``, ``.`` i string ``kraj``, stoga nije potrebno raditi dodatnu validaciju unosa.
Izlazna datoteka sadrži originalnu reč napisanu pomoću Morzeove azbuke, strelicu ``->`` i prevedenu reč.
Format je ``%s -> %s``.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``2``
* Ako program ne može da otvori ulaznu datoteku, izaći sa status kodom ``3``
* Ako program ne može da otvori izlaznu datoteku, izaći sa status kodom ``4``

Napomene
--------

* Zbog učitavanja jednog karaktera, format string u ``fscanf`` naredbi mora sadržati znak za novi red ``"%c %s\n"``
* Beskonačna petlja u programskom jeziku C se može napisati kao ``while(1)``, dok se iz nje se može izaći sa ``break`` naredbom

Primer poziva programa:

.. code-block:: bash

  ./a.out kodovi.txt poruka.txt

Primer ulazne datoteke ``kodovi.txt``:

.. literalinclude:: kodovi.txt
   :language: none

Primer rada programa:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer izlazne datoteke ``poruka.txt``:

.. literalinclude:: poruka.txt
   :language: none
