Napisati program koji izračunava iznose sirovina pekari koja je specijalizovana za pravljenje pita sa sirom.
Iz ulazne datoteke učitati sledeće podatke u statički niz struktura, gde se struktura sastoji iz sledećih polja:

* ``naziv_sirovine`` (jedna reč, do 30 karaktera)
* ``limit_za_velikoprodaju`` (neoznačena, celobrojna vrednost)
* ``maloprodajna_cena`` (realan broj)
* ``velikoprodajna_cena`` (realan broj)

Za pravljenje jednog kilograma pite sa sirom neophodno je:

* ``0,6kg`` brašna
* ``0,4kg`` sira
* ``0,1l`` ulja
* ``0,02kg`` soli

Program prima ime ulazne i izlazne datoteke, kao i broj kilograma pite koju je potrebno napraviti kao neoznačenu, celobrojnu vrednost.
U izlaznu datoteku za svaku sirovinu ispisati naziv, potrebnu količinu u kilogramima izračunatu na osnovu udela i cenu.
Prilikom upisa u izlaznu datoteku, koristiti format ispisa ``%6s %5.2lf %8.2lf``.
Ukoliko je potrebna količina sirovine za zadatu kilažu pite manja od limita za velikoprodaju, cena sirovine računa se po maloprodajnoj ceni.
U slučaju da je potrebna količina veća ili jednaka limitu za velikoprodaju, cena sirovine računa se po velikoprodajnoj ceni.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako program ne može da otvori ulazni fajl, izaći sa status kodom ``2``
* Ako program ne može da otvori izlazni fajl, izaći sa status kodom ``3``

.. tabs::

  .. group-tab:: Datoteke

      Primer poziva programa:

      .. code-block:: bash

         ./pekara sirovine.txt cene.txt 120

      Primer ulazne datoteke ``sirovine.txt``:

      .. literalinclude:: sirovine.txt
         :language: none

      Primer izlazne datoteke ``cene.txt``:

      .. literalinclude:: cene.txt
         :language: none

  .. group-tab:: Standardni ulaz/izlaz

      Primer poziva programa:

      .. code-block:: bash

         ./pekara 120 < sirovine-stdinout.txt

      Primer ulazne datoteke ``sirovine-stdinout.txt``:

      .. literalinclude:: sirovine-stdinout.txt
         :language: none

      Ispis programa na standardnom izlazu:

      .. literalinclude:: ispis-programa-stdinout.txt
         :language: none
