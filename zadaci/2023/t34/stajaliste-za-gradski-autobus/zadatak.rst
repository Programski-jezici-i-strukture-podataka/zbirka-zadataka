Napisati program koji nalazi sve željene autobuske linije koje staju na stajalištu nakon zadatog vremena.
Podaci su zadati u ulaznoj datoteci u sledećem formatu:

* `naziv_linije` (jedna reč, do 50 karaktera)
* `broj_linije` (celobrojna vrednost)
* `vreme_dolaska` (jedna reč, do 4 karaktera)

Učitati linije u statički niz, zatim u izlaznu datoteku ispisati samo one linije koje pripadaju zadatim linijama nakon određenog vremena.
Ime ulazne i izlazne datoteke, kao i vreme se zadaju kao argument komandne linije, dok se željene linije zadaju putem standardnog ulaza.
Korisnik programa unosi tražene linije dokle god ne unese vrednost -1, što označava kraj korisničkog unosa (pogledati primer rada programa).
U izlaznu datoteku ispisati broj linije i vreme dolaska.

U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``2``
* Ako program ne može da otvori ulaznu datoteku, izaći sa status kodom ``3``
* Ako program ne može da otvori izlaznu datoteku, izaći sa status kodom ``4``

Napomene
--------

* Zarad jednostavnosti, prilikom unosa, pretpostaviti da se jedna linija ne moze izabrati vise puta
* Sprovesti odgovarajuću validaciju korisničkog unosa (dozvoljene vrednosti su od 1 do 15 i -1)

Primer poziva programa:

.. tabs::

  .. group-tab:: Datoteke
    .. code-block:: bash

      ./a.out linije.txt trazene-linije.txt 1800
  .. group-tab:: Standardni ulaz/izlaz
    .. code-block:: bash

      ./a.out 1800 < linije-stdinout.txt

.. tabs::

  .. group-tab:: Datoteke

    Primer ulazne datoteke ``linije.txt``:

    .. literalinclude:: linije.txt
       :language: none

    Primer rada programa:

    .. literalinclude:: ispis-programa.txt
       :language: none

    Primer izlazne datoteke ``trazene-linije.txt``:

    .. literalinclude:: trazene-linije.txt
       :language: none

  .. group-tab:: Standardni ulaz/izlaz
    
    Primer ulazne datoteke ``linije-stdinout.txt``
    
    .. literalinclude:: linije-stdinout.txt
      :language: none
   
    Primer rada programa:

    .. literalinclude:: ispis-programa-stdinout.txt
       :language: none
