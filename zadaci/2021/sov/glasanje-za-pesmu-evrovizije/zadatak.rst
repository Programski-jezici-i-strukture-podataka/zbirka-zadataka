Napisati program koji izračunava ukupan broj glasova koji je određena država osvojila na Evroviziji.
Iz ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde se struktura sastoji iz sledećih polja:

* ``naziv_drzave`` (jedna reč, do 30 karaktera)
* ``glasovi_publike`` (neoznačena, celobrojna vrednost)
* ``glasovi_zirija`` (neoznačena, celobrojna vrednost)
* ``ukupno_glasova`` (neoznačena, celobrojna vrednost)

Struktura sadrži dodatna polja za pravilno formiranje jednostruko spregnute liste.

Program prima ime ulazne i izlazne datoteke kao argumente komandne linije.
Naziv države i glasovi se učitavaju u jednostruko spregnutu listu, dok se ukupan broj glasova izračunava kao suma glasova žirija i publike:

.. math::

   ukupno\_glasova = glasovi\_publike + glasovi\_zirija

Prilikom učitavanja u listu, podaci se sortiraju na osnovu ukupnog broja osvojenih glasova.
Ispisati podatke iz jednostruko spregnute liste u izlaznu datoteku u sledećem formatu: ``%2d. %-9s %3u %3u %3u``, gde ``%d`` predstavlja redni broj države,
dok su ostale vrednosti, redom, naziv države, ukupan broj glasova, glasovi publike i glasovi žirija.

Pronaći državu čija je razlika između glasova publike i glasova žirija najmanja:

.. math::

   razlika\_glasova = |glasovi\_publike - glasovi\_zirija|

Ispisati dobijeni rezultat nakon svih država u izlazni fajl u sledećem obliku:

.. code-block:: bash
  
   Drzava ucesnica sa najmanjom razlikom izmedju glasova publike(<glasovi_publike>) i zirija(<glasovi_zirija>) je <naziv_države>.
  
U slučaju uspešnog izvršavanja programa, izaći sa status kodom ``0`` (``EXIT_SUCCESS``).
Ukoliko program ne može da se izvrši do kraja usled sledećih nedostataka, izaći iz programa sa sledećim status kodovima:

* U slučaju nedovoljnog ili suvišnog broj argumenata komandne linije, kao i nemogućnosti dinamičkog zauzeća memorije, izaći iz programa sa status kodom ``1`` (``EXIT_FAILURE``)
* Ako program ne može da otvori ulazni fajl, izaći sa status kodom ``2``
* Ako program ne može da otvori izlazni fajl, izaći sa status kodom ``3``

Primer poziva programa:

.. code-block:: bash

  ./prebrojavanje glasanje.txt rezulati.txt


Primer ulazne datoteke ``glasanje.txt``:

.. literalinclude:: glasanje.txt
   :language: none

Primer izlazne datoteke ``rezultati.txt``:

.. literalinclude:: rezultati.txt
   :language: none

