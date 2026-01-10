Napisati program koji pomaže selektoru reprezentacije da sastavi tim za predstojeću utakmicu.
Raspoloživi igrači su zadati u ulaznoj datoteci u sledećem formatu:

* ``ime`` (jedna reč, do 20 karaktera)
* ``prezime`` (jedna reč, do 30 karaktera)
* ``broj_dresa`` (celobrojna vrednost)
* ``pozicija`` (jedna reč, do 10 karaktera)

Učitati fudbalere u statički niz, zatim na osnovu zadate formacije odabrati igrače na osnovu zadatih brojeva unutar formacije.
Fudbalere je potrebno ispisati u izlaznu datoteku u sledećem formatu ``"%2d %s %c."``, gde celobrojna vrednost broj dresa koji igrač nosi, string predstavlja prezime igrača, a karakter početno slovo imena igrača.
Imena ulazne i izlazne datoteke zadaju se kao argumenti komandne linije.
Pored njih, kao argument komandne linije zadaje se i željena formacija.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako formacija nije napisana u traženom formatu (cifra, crta, cifra, crta, cifra), izaći sa status kodom ``2``
* Ako je broj igrača na određenoj poziciji veći od 5, izaći sa status kodom ``3`` 
* Ako program ne može da otvori ulaznu datoteku, izaći sa status kodom ``4``
* Ako program ne može da otvori izlaznu datoteku, izaći sa status kodom ``5``

Primer poziva programa:

.. tabs::

  .. group-tab:: Datoteke

      .. code-block:: bash

         ./a.out fudbaleri.txt postava.txt 4-3-3

      Primer ulazne datoteke ``fudbaleri.txt``:

      .. literalinclude:: fudbaleri.txt
         :language: none

      Primer izlazne datoteke ``postava.txt``:

      .. literalinclude:: postava.txt
         :language: none

  .. group-tab:: Standardni ulaz/izlaz
      .. code-block:: bash

         ./a.out 4-3-3 < fudbaleri-stdinout.txt

      Primer ulazne datoteke ``fudbaleri-stdinout.txt``:

      .. literalinclude:: fudbaleri-stdinout.txt
         :language: none

      Ispis programa na standardnom izlazu:

      .. literalinclude:: ispis-programa-stdinout.txt
         :language: none

