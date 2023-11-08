Napisati program koji vrši kompresiju unetog stringa od najviše 99 karaktera.
Kompresija se vrši na sledeći način:

* U unetom stringu se prate ponavljanja određenog karaktera jedan za drugim iste veličine
* Umesto ponovljenih karaktera, ispisati broj ponavljanja karaktera i sam karakter
* U slučaju da nema ponavljanja, ne piše se broj ispred karaktera

Na osnovu navedenih pravila kompresije, formirati novi, rezultujući string, koji je neophodno ispisati.
Osim kompresovanog stringa, ispisati i procenat kompresije algoritma koji se računa po sledećoj formuli:

.. math::

  Kompresija_\% = (1 - \frac{dužina_{kompresovano}}{dužina_{original}}) \cdot 100

Napomene
--------

* S obzirom na to da je ukupni broj karaktera dvocifren broj, broj ponavljanja takođe može biti najviše dvocifren
* Za ispisivanje procenat karaktera u naredbi `printf`, navesti `%%` u format stringu

Primer rada programa:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer rada programa u slučaju unetog istog slova:

.. literalinclude:: ispis-programa-isto-slovo.txt
   :language: none

Primer rada programa u slučaju stringa sa karakterima koji se ne ponavljaju:

.. literalinclude:: ispis-programa-bez-kompresije.txt
   :language: none
