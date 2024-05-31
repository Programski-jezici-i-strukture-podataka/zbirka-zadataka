Ime ulazne datoteke učitati argumentom komandne linije. Ulazna datoteka sadrži podatke strukturama podataka:

* ``naziv`` (jedna reč, do 40 karaktera)
* ``memorija_elementa`` (ceo broj, u bajtima)
* ``prosecno_trajanje_pretrage`` (jedna reč, do 3 karaktera)

Učitati podatke u jednostruko spregnutu listu dodavanjem novih elemenata na kraj liste. U izlaznu datoteku pod nazivom ``memorija.txt`` ispisati imena i ukupno memorije potrebno za čuvanje broja elemenata učitanog preko argumenta komandne linije. Memoriju izraziti u kilobajtima (kB), ako važi da je 1kB = 1024bajta. Za uneti broj elemenata, ispisati na standardnom izlazu za svaku strukturu vreme prosečne pretrage, ako:

* ``1`` - je potrebna jedna operacija, otpr. 5 nanosekundi
* ``log`` - je potrebno 5 * log(n) nanosekundi
* ``n`` - je potrebno 5 * n nanosekundi

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa status kodom ``1`` (``EXIT_FAILURE``)
* Ako nije uspešno otvorena ulazna datoteka, izaći iz programa sa status kodom ``2``
* Ako nije uspešno otvorena izlazna datoteka, izaći iz programa sa status kodom ``3``
* Ako nije uspešno alocirana memorija za elemente, izaći iz programa sa status kodom ``4``

Primer poziva programa:

.. code-block:: bash

  ./a.out strukture.txt 1000

Primer ulazne datoteke ``strukture.txt``:

.. literalinclude:: strukture.txt
   :language: none

Ispis programa na standardnom izlazu:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer izlazne datoteke ``memorija.txt``:

.. literalinclude:: memorija.txt
   :language: none
