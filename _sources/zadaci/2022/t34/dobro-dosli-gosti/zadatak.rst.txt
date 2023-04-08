Napisati program koji pronalazi najpogodniji za proslavu među zadatim restoranima.
Podaci su zadati u ulaznoj datoteci u sledećem formatu:

* ``naziv`` (jedna reč, do 20 karaktera)
* ``cena_po_osobi`` (u dinarima, realan broj)
* ``kapacitet`` (celobrojna vrednost)
* ``broj_konobara`` (celobrojna vrednost)

Učitati restorane u statički niz, zatim na osnovu zadatog broja gostiju i kursa evra ispisati sve restorane sa cenom preračunatom u evre, osim onih čiji kapacitet premašuje zadati broj gostiju.
U tom slučaju, umesto cene, ispisati ``nedovoljno kapaciteta``.
Broj gostiju i kurs evra zadaju se kao argumenti komandne linije. Kod restorana sa dovoljnim kapacitetom ispisati i odnos na koliko gostiju dolazi jedan konobar.
U slučaju decimalnog rezultata, zaokružiti broj gostiju po konobaru na prvu sledeću celobrojnu vrednost nakon deljenja.

Osim ispisivanja svih restorana, potrebno je pronaći i ispisati na standardni izlaz restoran sa najmanjim koeficijentom za restorane koji ispunjavaju zahtev za kapacitetom.
Koeficijent se računa na sledeći način:


.. math::

  koeficijent = cena\_po\_osobi \div \lceil \frac{broj\_gostiju}{broj\_konobara} \rceil

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako program ne može da otvori ulazni fajl, izaći sa status kodom ``2``
* Ako program ne može da otvori izlazni fajl, izaći sa status kodom ``3``

Primer poziva programa:

.. code-block:: bash

  ./a.out restorani.txt 120 117.5

Primer ulazne datoteke ``restorani.txt``:

.. literalinclude:: restorani.txt
   :language: none

Primer izlazne datoteke ``cene_za_120_ljudi.txt``:

.. literalinclude:: cene_za_120_ljudi.txt
   :language: none

Ispis programa na standardnom izlazu:

.. literalinclude:: ispis-programa.txt
   :language: none

