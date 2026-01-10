Imena ulazne i izlazne datoteke učitati argumentom komandne linije. Ulazna datoteka sadrži podatke o pretraživačima:

* ``naziv`` (jedna reč, do 20 karaktera)
* ``procenat_pretraga_2010`` (realan broj, predstavlja % svih pretraga)
* ``procenat_pretraga_2015`` (realan broj, predstavlja % svih pretraga)
* ``procenat_pretraga_2020`` (realan broj, predstavlja % svih pretraga)

Učitati podatke u jednostruko spregnutu listu dodavanjem novih elemenata na kraj liste. U izlaznu datoteku ispisati imena i ukupni broj pretraga sa pretraživača (u bilionima) tokom te 3 godine, ako je:

* 2010 godine bilo 1.2 biliona pretraga
* 2015 godine bilo 2.3 biliona pretraga
* 2020 godine bilo 3.4 biliona pretraga

Ispis zaokružiti na dve decimale. Na standardni izlaz ispisati za svaku od navedenih godina pretraživač sa najviše pretraga.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa status kodom ``1`` (``EXIT_FAILURE``)
* Ako nije uspešno otvorena ulazna datoteka, izaći iz programa sa status kodom ``2``
* Ako nije uspešno otvorena izlazna datoteka, izaći iz programa sa status kodom ``3``
* Ako nije uspešno alocirana memorija za elemente, izaći iz programa sa status kodom ``4``

Primer poziva programa:

.. code-block:: bash

  ./a.out pretrazivaci.txt out.txt

Primer ulazne datoteke ``pretrazivaci.txt``:

.. literalinclude:: pretrazivaci.txt
   :language: none

Ispis programa na standardnom izlazu:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer izlazne datoteke ``out.txt``:

.. literalinclude:: out.txt
   :language: none
