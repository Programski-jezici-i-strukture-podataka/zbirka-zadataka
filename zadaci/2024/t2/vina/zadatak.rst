Dat je niz od maksimalno 30 vina. Učitati n vina ako su vina opisana sledećim podacima:

* ``naziv`` (jedna reč, do 30 karaktera)
* ``osnovna_cena`` (u dinarima, celobrojna vrednost)
* ``kolicina`` (u litrima, realna vrednost)
* ``godiste`` (celobrojna vrednost)
* ``tip`` (jedna reč, do 10 karaktera)

Izmeniti naziv tako da se umesto ``_`` koristi prazan prostor, prvo slovo uveća, ostala umanje. Ispisati nazive svih vina tipa unetog pomoću argumenta komandne linije. Proceniti cenu vina formulom:


.. math::

  cena = \frac{( osnovna_cena + (2024 - godište) * 100 ) * količina}{tip}
  
Gde je ``tip`` koeficijent određen vrednošću polja ``tip`` i ima vrednosti:

* ``crveno`` - 0.66
* ``roze`` - 1
* ``belo`` - 1.33

Ispisati cene vina.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako nije pronađeno vino tipa unetog argumentom komandne linije, izaći sa status kodom ``2``
* Ako tip nekog od vina nije ``belo``, ``crveno`` ili ``roze``, izaći sa status kodom ``3``

Primer poziva programa:

.. code-block:: bash

  ./a.out belo < vina.txt

Primer ulazne datoteke ``vina.txt``:

.. literalinclude:: vina.txt
   :language: none

Ispis programa na standardnom izlazu:

.. literalinclude:: ispis-programa.txt
   :language: none

