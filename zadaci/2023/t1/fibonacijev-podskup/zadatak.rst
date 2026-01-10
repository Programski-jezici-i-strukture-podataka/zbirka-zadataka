Dat je niz celobrojnih vrednosti od maksimalno 30 elemenata.
Uneti `n` vrednosti i ispitati da li uneti niz predstavlja podskup Fibonačijevog niza na sledeći način:

* Proveriti da li je prvi član niza pripada Fibonačijevom nizu
* Ako pripada, proveriti da li ostatak niza prati vrednosti u odnosu na formulu Fibonačijevog niza

Prva dva člana Fibonačijevog niza imaju vrednost 1, a svaki sledeći je zbir prethodna dva člana.

Ispisati poruku da li je niz podskup Fibonačijevog niza i same vrednosti niza ukoliko jeste.

Matematička formula Fibonačijevog niza je:

.. math::

  F(n) = 1, n = 1 \wedge n = 2

.. math::

  F(n) = F_{n-1} + F_{n-2}, n > 2

Napomene
--------

* Nije dozvoljeno koristiti globalne promenljive
* Računati da je uneti niz uvek u rastućem redosledu, tako da nije potrebno dodatno sortirati uneti niz!

Primer rada programa:

.. literalinclude:: ispis-je-podskup.txt
   :language: none

Primer rada programa u slučaju kada niz nije podskup Fibonačijevog niza:

.. literalinclude:: ispis-nije-podskup.txt
   :language: none

Primer rada programa u slučaju kada prvi element pripada Fibonačijevom nizu, a ostali ne:

.. literalinclude:: ispis-prvi-pripada-ostali-ne.txt
   :language: none

Primer rada programa u slučaju niza od 1 elementa, koji pripada Fibonačijevom nizu:

.. literalinclude:: ispis-je-podskup-1-clan.txt
   :language: none

Primer rada programa u slučaju niza od 2 elementa, koji pripadaju Fibonačijevom nizu:

.. literalinclude:: ispis-je-podskup-2-clana.txt
   :language: none
