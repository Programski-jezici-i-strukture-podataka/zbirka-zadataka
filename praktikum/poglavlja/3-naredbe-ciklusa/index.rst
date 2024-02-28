3. Naredbe ciklusa
==================

Ako je potrebno ponavljati jednu ili više naredbi koriste se ciklusi, tj. petlje.
Broj ponavljanja može biti unapred poznat, ili određen nekim uslovom. 

While ciklus
------------

Osnovna forma ``while`` ciklusa je::

  while(izraz) {
    naredbe
  }

Naredbe koje se nalaze u bloku ponavljaju se dok je izraz logički tačan.
Ako se vrednosti promenljivih unutar izraza ne menjaju naredbama u bloku, može doći do "beskonačne petlje",
koja će dovesti do toga da se program nikada ne izvrši do kraja. Programi se mogu prekinuti prečicom Ctrl+C u terminalu.

Dat je primer programa gde korisnik pogađa broj, koji je unapred postavljen u programu:

.. literalinclude:: primeri/while.c
   :linenos:

Ciklus se, u slučaju da je korisnik odmah pogodio, preskače. Ako je uneti broj različit od traženog, ispisuje se poruka i poredi
uneti broj sa traženim. Korisnik ponovo unosi broj, sve dok ne pogodi traženi, čime će uslov::

   a != b

postati netačan, te će program izaći iz ciklusa. Primer ispisa programa za unete brojeve 1000, 3000 pa 2024 je:

.. literalinclude:: primeri/while-ispis.txt
   :language: none

U programu je korišćen ``while`` ciklus jer nije unapred poznato koliko puta će korisnik promašiti broj.

For ciklus
----------

Kada je unapred poznat broj iteracija (broj ponavljanja naredbi unutar bloka ciklusa), često je kraće koristiti ``for`` ciklus,
koji se zapisuje u obliku::

  for (inicijalizacija; uslov; korak) {
    naredbe
  }

Za ciklus se vezuje promenljiva, koja služi da broji ponavljanja naredbi. Inicijalizacija je naredba kojom se definiše početna vrednost
te promenljive pre ulaska u ciklus, korak definiše promenu te promenljive nakon svakog izvršenja naredbi, koje će se izvršavati dogod je
ispunjen uslov (odgovarajući izraz logički tačan). Ispod je dat primer petlje za ispisivanje svih cifara (brojeva od 0 do 9):

.. literalinclude:: primeri/for.c
   :linenos:

U datom primeru se deklariše nova promenljiva za kontrolu petlje i inicijalizuje na 0. Potom, kako je uslov ispunjen za vrednost promenljive 0,
izvršava se funkcija ``printf``. U sledećem ponavljanju, promenljiva se pomera za korak - kako je korak i++, uvećava se za jedan. Ispis se ponavlja
sve dok promenljiva ne dostigne vrednost 10, kada uslov nije više ispunjen, i izlazi se iz petlje. Ispis ovog programa je:

.. literalinclude:: primeri/for-ispis.txt
   :language: none

Moguće je definisati proizvoljan korak. U sledećem primeru ispisuju se prvih n parnih brojeva:

.. literalinclude:: primeri/for2.c
   :linenos:

Početna vrednost promenljive je 2, i uvećava se za 2 sve dok je ispunjen uslov. Ispis programa je:

.. literalinclude:: primeri/for2-ispis.txt
   :language: none

Do-while ciklus
---------------

Često je potrebno izvršiti bar jednom naredbe u ``while`` ciklusu. Za to se koristi ``do while``, čija forma je:

  do {
    naredbe
  } while(izraz);

Za razliku od ostalih ciklusa, do-while se završava sa ;
Primena ove petlje je najčešće provera unosa. Ako je potrebno npr. osigurati da je uneti broj prirodan, to se može uraditi na sledeći način:

.. literalinclude:: primeri/dowhile.c
   :linenos:

Kada se proverava unos, proverava se logički suprotan izraz željenom, u prethodnom primeru broj mora biti veći od 0 da bi bio prirodan, te se
proverava da li je manji ili jednak 0, ako jeste ponavlja se unos. Primer pokretanja programa je:

.. literalinclude:: primeri/dowhile-ispis.txt
   :language: none

Break i continue
----------------

Za kontrolu petlji postoje dve naredbe, break i continue.
Break uzrokuje da program odmah izađe iz ciklusa, dok
continue naredbom prelazi se na sledeću iteraciju.

Primer koji sadrži obe naredbe:

.. literalinclude:: primeri/break_continue.c
   :linenos:
   
U iteracijama gde je vrednost promenljive 2 ili 4, preskače se
ispis jer se continue izvrši pre ispisa, dok se u iteraciji gde
je vrednost promenljive 7 izlazi se iz petlje. Ispis programa je tada:

.. literalinclude:: primeri/break_continue-ispis.txt
   :language: none
