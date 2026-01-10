Tačke u dvodimenzionalnom Dekartovom koordinatnom sistemu opisane su preko njihovih koordinata:
    • Vrednost na x-osi (realan broj dvostruke preciznosti)
    • Vrednost na y-osi (realan broj dvostruke preciznosti)

Učitati tačke iz ulazne datoteke, potom uraditi sledeće:
    a) Pronaći koordinate težišne tačke za niz učitanih tačaka.
       Za pronalaženje koordinata težišne tačke potrebno je naći posebno aritmetičku sredinu x i y koordinata tačaka čija se težišna tačka nalazi (formula je na drugoj stranici dokumenta).
    b) Pronaći sve tačke koje pripadaju krugu sa centrom u težišnoj tački (rezultat prethodnog koraka) i poluprečnika koji se unosi kao argument komandne linije (može biti realna vrednost).
       Rezultat ovog i prethodnog koraka upisati u izlaznu datoteku čiji se naziv sastoji od stringa ``pripada_krugu_poluprecnika_``, vrednost poluprečnika (argument komandne linije) i ekstenzijom ``.txt``.
    c) Pronaći ukupan broj jedinstvenih trouglova koji može da nastane od datog niza tačaka.
       Da bi neke tri tačke sačinjavale trougao, potrebno je da duži koje one međusobno grade zadovoljavaju nejednakost trougla (formula je na drugoj stranici dokumenta).
       Dobijeni broj trouglova upisati u izlaznu datoteku "trouglovi.txt".

.. image:: tacke2d_ilustracija.png
   :align: center

Primer poziva programa:

.. code-block:: bash

  ./a.out tacke.txt 5

Primer ulazne datoteke ``tacke.txt``:

.. literalinclude:: ./tacke.txt
   :language: none

Primer izlazne datoteke ``trouglovi.txt``:

.. literalinclude:: ./trouglovi.txt
   :language: none

Primer izlazne datoteke ``pripada_krugu_poluprecnika_2.txt``

.. literalinclude:: ./pripada_krugu_poluprecnika_2.txt
   :language: none

Primer poziva programa gde tačke *ne sačinjavaju* trougao:

.. code-block:: bash

   ./a.out ne_trougao.txt 5

Primer ulazne datoteke ``ne_trougao.txt``:

.. literalinclude:: ./ne_trougao.txt
   :language: none

Primer izlazne datoteke ``trouglovi.txt``:

.. literalinclude:: ./ne_trouglovi.txt
   :language: none

Primer izlazne datoteke ``pripada_krugu_poluprecnika_5.txt``

.. literalinclude:: ./ne_trougao_pripada_krugu_poluprecnika_5.txt
   :language: none


**Korisne matematičke formule**

*Računanje težišne tačke*

Koordinate težišne tačke :math:`(x_{T}, y_{T})` za :math:`n` tačaka računaju se na sledeći način:

.. math::

  x_{T} = \frac{(x_{1} + x_{2} + ... + x_{n})}{n}

  y_{T} = \frac{(y_{1} + y_{2} + ... + y_{n})}{n}

*Nejednakost trougla*

Za svaki trougao sa stranicama :math:`a`, :math:`b` i :math:`c` treba da važe sledeće nejednakosti:

.. math::

  a + b > c

  c + b > a

  c + a > b

*Rastojanje između dve tačke u dvodimenzionalnom koordinatnom sistemu*

Date su dve tačke sa koordinatama :math:`(x_{1}, y_{1})` i :math:`(x_{2}, y_{2})`. Njihovo rastojanje može se odrediti na sledeći način:

.. math::

  d = \sqrt{(x_{1} - x_{2})^2 + (y_{1} - y_{2})^2}

