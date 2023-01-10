Pijanista takmičar predstavljen je preko strukture, pomoću sledećih polja:

* ime (string, do 20 karaktera)
* prezime (string, do 30 karaktera)
* broj osvojenih poena (neoznačena, celobrojna vrednost)

Učitati takmičare iz ulazne datoteke u binarno stablo pretrage.
Koristiti broj osvojenih poena kao ključno obeležje.
U izlaznu datoteku ispisati ime i prezime takmičara, zajedno sa nagradom koju je osvojio sortirano, u opadajućem redosledu.
Pravila za nagrađivanje su sledeća:

* Ukoliko takmičar ima od 91-100 osvojenih poena, osvojio je prvu nagradu
* Ukoliko takmičar ima od 81-90 osvojenih poena, osvojio je drugu nagradu
* Ukoliko takmičar ima 80 i niže poena, osvojio je pohvalu

Kako više takmičara može osvojiti prvu i drugu nagradu, one se dodatno rangiraju u odnosu na osvojeni broj poena.
Na primer, u slučaju da postoje dva takmičara, gde je jedan osvojio 99, a drugi 94 poena, prvi je osvojio prvu prvu, a drugi je osvojio prvu drugu nagradu.
U slučaju da je takmičar osvojio prvu ili drugu nagradu, koristiti format ispisa ``"%-10s %-12s %d. %d."``, dok u slučaju osvojene pohvale, koristiti ``"%-10s %-12s pohvala"``.
Pogledati primer izlazne datoteke za detaljnije objašnjenje.



* U slučaju nedovoljnog ili suvišnog broja argumenata, izaći iz programa sa kodom greške ``1`` (``EXIT_FAILURE``)
* U slučaju da nije moguće dinamički zauzeti memoriju, izaći iz programa sa kodom greške ``2``
* U slučaju neuspešnog otvaranja ulazne datoteke, izaći iz programa sa kodom greške ``3``
* U slučaju neuspešnog otvaranja izlazne datoteke, izaći iz programa sa kodom greške ``4``


Primer ulaznog fajla ``takmicari.txt``

.. literalinclude:: takmicari.txt
   :language: none

Primer poziva programa:

.. code-block:: bash

   ./program takmicari.txt rezultati.txt

Primer izlazne datoteke ``rezultati.txt``:

.. literalinclude:: rezultati.txt
   :language: none
