Dat je niz od maksimalno 20 pasti za zube. Učitati n pasti ako su opisane sledećim podacima:

* ``naziv`` (jedna reč, do 30 karaktera)
* ``cena`` (u dinarima, realna vrednost)
* ``velicina`` (u ml, celobrojna vrednost)
* ``decija`` (jedna reč, do 2 karaktera, "da" ili "ne")
* ``pun_naziv`` (više reči, određeno opisom u zadatku)

Ispisati prosečnu cenu paste za zube. Ispisati sve nazive pasta za zube veće od veličine zadate argumentom komandne linije, potom ispisati naziv najjeftinije od njih. Polje ``pun_naziv`` popuniti nazivima pasti takvim da su sva slova izmenjena u velika, znak ``_`` zamenjen razmakom, a u slučaju da je pasta dečija na kraju naziva dodato ``za decu``.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako nije pronađena pasta za zube veličine veće od unete argumentima komandne linije, izaći sa status kodom ``2``

Primer poziva programa:

.. code-block:: bash

  ./a.out 100 < paste-stdinout.txt

Primer ulazne datoteke ``paste-stdinout.txt``:

.. literalinclude:: paste-stdinout.txt
   :language: none

Ispis programa na standardnom izlazu:

.. literalinclude:: ispis-programa-stdinout.txt
   :language: none
