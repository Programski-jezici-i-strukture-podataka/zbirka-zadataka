Operacioni pojačavači su elektronske komponente koje pojačavaju razliku 2 signala. Rezultat mora biti manji od napona napajanja ove komponente. Zbog nesavršenosti ove komponente u praksi se javlja napon ofseta, koji eliminišemo dodavanjem potenciometra. Pojačavači koji nemaju napon ofseta nazivaju se "Auto-Zero".

Napisati program koji pronalazi odgovarajuće pojačavače za unete naponske signale.
Podaci o pojačavačima su zadati u ulaznoj datoteci u sledećem formatu:

* ``naziv`` (jedna reč, do 10 karaktera)
* ``pojacanje`` (celobrojna vrednost, u V/V)
* ``napajanje`` (celobrojna vrednost, u V)
* ``ofset`` (celobrojna vrednost, u V)


Učitati pojačavače u statički niz, zatim na osnovu jačine 2 ulazna signala u izlaznu datoteku ispisati imena operacionih pojačavača koji mogu da pojačaju razliku ulaznih signala, osim onih čiji je napon ofseta 0 (Auto-Zero pojačavače). Operacioni pojačavač može da pojača ulaznu vrednost ako važi da je napon napajanja veći od izlaznog signala, to jest:


.. math::

  napajanje > pojacanje * | ulaz1 - ulaz2 |
 
Gde su ``ulaz1`` i ``ulaz2`` jačine signala učitanih kao argumenti komandne linije, realni brojevi uneti u `milivoltima`. Pored imena ispisati vrednost izlaznog signala (realan broj), kao i procenat okretanja potenciometra koji služi za eliminaciju napona ofseta, koji se računa iz izraza:


.. math::

  (1 - \frac{napajanje - ofset}{2 * napajanje}) * 100
 
Podvući crtu ispod poslednjeg pronađenog pojačavača (sastoji se od 25 srednjih crtica ``-``), i ispod ispisati imena odgovarajućih pojačavača čiji je napon ofseta 0, jačinu izlaznog potencijala, i karaktere ``AZ``.

Osim ispisivanja operacionih pojačavača, potrebno je pronaći i ispisati na standardni izlaz ime i pojačanje pojačavača sa najvećim pojačanjem.


U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako program ne može da otvori ulazni fajl, izaći sa status kodom ``2``
* Ako program ne može da otvori izlazni fajl, izaći sa status kodom ``3``


Primer poziva programa:

.. tabs::

  .. group-tab:: Datoteke
    .. code-block:: bash

      ./a.out opamps.txt 139.7 117.9
  .. group-tab:: Standardni ulaz/izlaz
    .. code-block:: bash

       ./a.out 139.7 117.9 < opamps-stdinout.txt

.. tabs::

  .. group-tab:: Datoteke

    Primer ulazne datoteke ``opamps.txt``:

    .. literalinclude:: opamps.txt
      :language: none

    Primer izlazne datoteke ``operacioni_pojacavaci.txt``:

    .. literalinclude:: operacioni_pojacavaci.txt
      :language: none

    Ispis programa na standardnom izlazu:

    .. literalinclude:: ispis-programa.txt
      :language: none

  .. group-tab:: Standardni ulaz/izlaz

    Primer ulazne datoteke ``opamps-stdinout.txt``:

    .. literalinclude:: opamps-stdinout.txt
       :language: none

    Ispis programa na standardnom izlazu:

    .. literalinclude:: ispis-programa-stdinout.txt
       :language: none

