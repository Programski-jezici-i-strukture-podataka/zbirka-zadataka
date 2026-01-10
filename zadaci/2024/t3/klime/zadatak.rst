Ime ulazne i izlazne datoteke učitati argumentom komandne linije. Ulazna datoteka sadrži podatke o klima uređajima:

* ``naziv`` (jedna reč, do 30 karaktera)
* ``proizvodjac`` (jedna reč, do 30 karaktera)
* ``cena`` (ceo broj)
* ``energetska_klasa`` (jedna reč, do 4 karaktera)

Učitati podatke u jednostruko spregnutu listu dodavanjem novih elemenata na kraj liste. Za ime proizvođača uneto argumentom komandne linije ispisati sva imena klimi i cene u izlaznu datoteku. Na standardni izlaz ispisati broj klima u ponudi svake energetske klase: ``A+++, A++, A+, A, B, C``.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa status kodom ``1`` (``EXIT_FAILURE``)
* Ako nije uspešno otvorena ulazna datoteka, izaći iz programa sa status kodom ``2``
* Ako nije uspešno otvorena izlazna datoteka, izaći iz programa sa status kodom ``3``
* Ako nije uspešno alocirana memorija za elemente, izaći iz programa sa status kodom ``4``
* Ako klimina energetska klasa ne pripada navedenim klasama, izaći iz programa sa status kodom ``5``

Primer poziva programa:

.. code-block:: bash

  ./a.out klime.txt out.txt BOSCH

Primer ulazne datoteke ``klime.txt``:

.. literalinclude:: klime.txt
   :language: none

Ispis programa na standardnom izlazu:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer izlazne datoteke ``out.txt``:

.. literalinclude:: out.txt
   :language: none
