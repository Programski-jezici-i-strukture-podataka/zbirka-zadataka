Brojevi telefona zajedno sa uslugama i imenima pružaoca usluga kojoj pripadaju predstavljeni su u strukturi na sledeći način:

* ime pružaoca usluge (jedna reč, maksimalno 20 karaktera)
* usluga (jedna reč, maksimalno 10 karaktera)
* broj telefona (jedna reč, maksimalno 20 karaktera)

Brojevi telefona zadati su korišćenjem slova zarad lakšeg pamćenja, što je tehnika koja se često koristi u SAD.
Evropljanin, kome ovaj princip nije poznat bi želeo da nazove brojeve sa spiska za određenu uslugu koja mu je u datom trenutku potrebna.
Učitati brojeve telefona iz ulazne datoteke u jednostruko spregnutu listu (novi elementi dodaju se na kraj liste), zatim uraditi sledeće:

Na osnovu imena usluge koja se zadaje kao argument komandne linije u izlaznu datoteku ispisati imena pružaoca zajedno sa dešifrovanim brojem telefona u formatu ``%-12s %s``.
Izlaznu datoteku nazvati ``telefoni-<usluga>.txt``, gde ``<usluga>`` predstavlja ime zadate usluge (pogledati primer izlazne datoteke).

Brojevi telefona dešifruju se na osnovu tabele:

===== =======
Slova Brojevi
===== =======
ABC      2
DEF      3
GHI      4 
JKL      5
MNO      6
PQRS     7
TUV      8
WXYZ     9
===== =======
   
Primer ulazne datoteke ``imenik.txt``:

.. literalinclude:: imenik.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

  ./desifruj_brojeve imenik.txt hrana

Primer izlazne datoteke ``telefoni-hrana.txt``:

.. literalinclude:: telefoni-hrana.txt
   :language: none

