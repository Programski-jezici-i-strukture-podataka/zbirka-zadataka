Dat je niz realnih brojeva od maksimalno ``30`` elemenata.
Učitati ``n`` pozitivnih elemenata, koji predstavljaju trenutnu visinu u metrima tela u odnosu na tlo.
Uneti putem standardnog ulaza masu tela ``m`` u kilogramima, koja predstavlja realnu vrednost veću od nule.
Za unete visine izračunati i ispisati:

a. Vrednost ukupne energije u sistemu.
b. Vrednost najmanje razlike između potencijalne i kinetičke energije za određenu visinu ``h``.
c. Formirati novi niz u kom će se nalaziti brzine tela koje odgovaraju unetim visinama.

Ispise realnih vrednosti zaokružiti na dve decimale.

Za uneti niz visina ``[1, 3.4, 5, 2, 0]`` i masu tela ``10kg``, očekivani ispis na standardnom izlazu je:

.. literalinclude:: ispis.txt
   :language: none

**Korisne matematičke formule**

Zakon održanja energije:

.. math::
   E_{uk} = E_1 + E_2 + ... + E_n

Gravitaciona potencijalna energija:

.. math::
   E_p = mgh

gde gravitaciono ubrzanje iznosi:

.. math::
   g = 9,81 \frac {m} {s^2}

Kinetička energija:

.. math::
   E_k = \frac {mv^2} {2}

