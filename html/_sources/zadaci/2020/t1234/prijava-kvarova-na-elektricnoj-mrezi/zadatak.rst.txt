Objekti koji dobijaju električnu energiju iz trafo stanice nalaze se u ulaznoj datoteci ``trafo-stanica.txt`` 
Objekat je predstavljen na sledeći način:

* ulica (jedna reč, maksimalno 20 karaktera)
* broj (neoznačeni, ceo broj)
* broj domaćinstava (neoznačeni, ceo broj)
* tip objekta (jedna reč, maksimalno 10 karaktera)
* prijavljen kvar (jedna reč, maksimalno 2 karaktera)

Učitati objekte iz ulazne datoteke, čije je ime zadato kao drugi argument komandne linije i uraditi sledeće:

a) Pronaći sve objekte koji imaju prijavljen kvar.
   Izračunati ukupan broj domaćinstava koja su trenutno bez električne energije.
   Informacije o objektima i ukupan broj domaćinstava ispisati u izlaznu datoteku sa imenom zadatim kao treći argument komandne linije.
   Prilikom ispisa, za stringove koristiti ``%s``, a za neoznačene vrednosti ``%2u`` format specifikator.
b) Uporediti broj objekata trenutno zahvaćenih nestankom električne energije sa vrednošću prvog argumenta komandne linije.
   Ukoliko broj objekata premašuje zadatu vrednost, u istu izlaznu datoteku iz prethodne tačke napisati: "Moguć kvar trafo stanice!".
   
Vrednost prvog argumenta komandne linije mora biti prirodan broj, veći od 1.
U slučaju sledećih grešaka izaći iz programa sa odgovarajućim kodom greške:

    * U slučaju nedovoljnog ili suvišnog broja argumenata, izaći iz programa sa kodom greške ``1`` (``EXIT_FAILURE``)
    * U slučaju da je vrednost prvog argumenta izvan navedenog opsega, izaći iz programa sa kodom greške ``2``
    * U slučaju neuspešnog otvaranja ulazne datoteke, izaći iz programa sa kodom greške ``3``
    * U slučaju neuspešnog otvaranja izlazne datoteke, izaći iz programa sa kodom greške ``4``

U slučaju uspešnog izvršavanja, izaći iz programa sa kodom ``0`` (``EXIT_SUCCESS``).

Primer ulazne datoteke ``trafo-stanica.txt``:

.. literalinclude:: trafo-stanica.txt
   :language: none

Primer poziva programa:

.. code:: bash

  ./prijava_kvarova 5 trafo-stanica.txt bez-energije.txt

Primer izlazne datoteke ``bez-energije.txt``:

.. literalinclude:: bez-energije-5.txt
   :language: none

Primer poziva programa:

.. code:: bash

  ./prijava_kvarova 7 trafo-stanica.txt bez-energije.txt

Primer izlazne datoteke ``bez_energije.txt``:

.. literalinclude:: bez-energije-7.txt
   :language: none

