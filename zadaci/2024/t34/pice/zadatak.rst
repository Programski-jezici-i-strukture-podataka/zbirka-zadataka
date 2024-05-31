Dat je niz od maksimalno 20 pica. Učitati n pica ako su opisane sledećim podacima:

* ``naziv`` (jedna reč, do 30 karaktera)
* ``cena`` (u dinarima, realna vrednost)
* ``precnik`` (u cm, celobrojna vrednost)
* ``vegetarijanska`` (jedna reč, do 2 karaktera, "da" ili "ne")
* ``pun_naziv`` (više reči, određeno opisom u zadatku)

Ispisati prosečnu cenu pice. Ispisati sve nazive pica veće od površine zadate argumentom komandne linije. Površina pice nalazi se formulom:


.. math::

  P = (\frac{R}{2})^2 \pi

Pi proceniti na 2 decimale.
Formirati string od naziva, veličine pice i reči ``vegetarijanska`` ako je pica vegetarijanska. Veličine pice mogu biti:

* ``mala`` - ako je prečnik manji od 25 
* ``srednja`` - ako je prečnik između 25 i 40
* ``velika`` - ako je prečnik veći od 40

Formirano ime upisati u polje ``pun_naziv`` i ispisati ga. Ispisati koliko ima vegetarijanskih pica.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako nije pronađena pice površine veće od unete argumentom komandne linije, izaći sa status kodom ``2``

Primer poziva programa:

.. code-block:: bash

  ./a.out 500.00 < pice.txt

Primer ulazne datoteke ``pice.txt``:

.. literalinclude:: pice.txt
   :language: none

Ispis programa na standardnom izlazu:

.. literalinclude:: ispis-programa.txt
   :language: none

