Napisati program u kom korisnik unosi ``n`` površina koju pokriva jedan crep u kvadratnim centimetrima za različite modele crepova u celobrojni niz od maksimalno 20 elemenata.
Korisnik unosi i cenu crepa po komadu u poseban, realan niz, takođe od 20 elemenata. Crepu sa određenom površinom odgovara cena sa identičnim indeksom elementa u nizu cena.
Pored toga, potrebno je i uneti i realnu vrednost u kvadratnim metrima površine koju je potrebno pokriti crepom.

a. Napraviti novi, rezultujući niz čiji elementi predstavljaju koliko je ukupno novca potrebno uložiti da bi se pokrila zadata površina. Ispisati dobijeni niz.
b. Ispisati redni broj i ukupnu cenu crepa sa kojim je najisplativije uraditi posao i cenu materijala.
c. Ispisati redni broj i količinu crepa sa kojim je neophodno najmanje komada da bi se pokrila zadata površina.

Ispise realnih vrednosti zaokružiti na dve decimale.

Za unete površine crepova ``[150, 170, 134, 205, 230, 195]``, njihove cene ``[20, 23, 25, 27, 30, 22]`` i površinu 50m\ :sup:`2`, očekivani ispis na ekranu terminala je:

.. literalinclude:: ispis-programa.txt
   :language: none

**Korisne matematičke formule**

Konverzija iz cm\ :sup:`2` u m\ :sup:`2`:

.. class:: center

.. math::

   P_{m^2} = P_{cm^2}\cdot10^{-4}

