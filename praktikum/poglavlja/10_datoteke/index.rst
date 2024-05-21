Datoteke
========

Podeli svoje utiske o poglavlju na anketi https://docs.google.com/forms/d/1xdwvmDBf-dHSrliFcBA9KL1egNNWD9tYxEjdQRzcqSg

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Moguće je čuvati podatke programa nakon što se program završi koristeći datoteke. Na ovom predmetu će se koristiti tekstualne datoteke, čije ime se završava ekstenzijom ``.txt``. Možemo napraviti novu datoteku i popuniti je kroz ``Visual Studio Code``::
	
  code primer.txt

Sadržaj datoteke ćemo učitati u program i obraditi ga. Kao primer uzmimo podatke o državama Južne Amerike:

.. literalinclude:: primeri/primer.txt
   :language: none

Prva reč u svakom redu predstavlja ime države, potom je naveden broj stanovnika (u milionima) i površina države. Podatke ćemo učitati u niz struktura.

Funkcije za rad sa datotekom
----------------------------

Da bismo radili sa datotekom, potrebno je otvoriti i zatvoriti je unutar programa. Koristićemo funkcije ``fopen`` i ``fclose``. Sve funkcije sem fopen će raditi sa pokazivačem na datoteku ``FILE *``, sem ``fopen`` koji vraća adresu otvorene datoteke.

Kao argument funkciji ``fopen`` prosleđujemo string sa imenom datoteke koju želimo da otvorimo, a kao povratnu vrednost dobijamo pokazivač na datoteku ``FILE *``, kojim ćemo raditi sa datotekom. Kada završimo rad, prosledićemo taj pokazivač funkciji ``fclose``.

Datoteke će zarad jednostavnosti biti smeštene u istom direktorijumu u kom se nalazi program. Pored imena datoteke, funkcija ``fopen`` zahteva string koji sadrži režim otvaranja datoteke - ``r`` u slučaju da želimo da čitamo iz datoteke, ``w`` u slučaju da želimo da pišemo. Iako su samo po jedan karakter, režimi se prosleđuju kao string.

Ako pišemo u datoteku (otvorimo sa režimom ``w``), automatski će se napraviti nova datoteka ako datoteka sa unetim imenom ne postoji. To se neće desiti pri čitanju (ne može čitanje iz nepostojeće datoteke), pa će funkcija ``fopen`` vratiti ``NULL``, što može izazvati grešku pri izvršavanju programa. Zato je potrebno proveriti da li je datoteka uspešno otvorena, što možemo preko funkcije za otvaranje datoteka sa proverom:

.. literalinclude:: primeri/datoteke.c
   :lines: 35-46

Ako datoteka nije pronađena, potrebno je završiti program i ispisati grešku. Funkcija ``exit`` služi za završavanje programa iz bilo koje funkcije, prosleđujemo joj kod greške. Završavanje programa u slučaju da se ne otvori datoteka je samo jedna od strategija za obradu ovog izuzetka, koju smo mi odlučili da koristimo.

Za čitanje i pisanje u datoteku koriste se ``fscanf`` i ``fprintf``, kao i ``fgets`` i ``fputs``. Pozivi ``fscanf`` i ``fprintf`` su slični pozivima ``scanf`` i ``printf``, s tim što se prvo navodi pokazivač na datu datoteku. Učitavanje se odvija red po red, sve dok nije učitan poslednji red, u kom slučaju će funkcija ``fscanf`` vratiti vrednost ``EOF``, koja označava kraj datoteke.

Primer programa
---------------

Primer programa koji učitava države, i ispisuje gustinu stanovništva za svaku državu u novu datoteku pod imenom ``gustina.txt``:

.. literalinclude:: primeri/datoteke.c
   :linenos:

Nakon izvršavanja, pojaviće se nova datoteka ``gustina.txt`` sa sledećim sadržajem:

.. literalinclude:: primeri/gustina.txt
   :language: none

