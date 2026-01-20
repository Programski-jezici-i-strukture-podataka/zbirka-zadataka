GNU Make
========

.. Podeli svoje utiske o poglavlju na anketi `OVDE <>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Problem više datoteka sa izvornim kodom
---------------------------------------

Kako programsko rešenje napreduje, ono postaje sve obimnije u smislu broja linija koda od kog se sastoji.
Iako potpuno moguće, držanje svih funkcija u jednoj datoteci sa izvornim kodom postaje sve teže za održavanje.

Motivacija za podelu rešenja u više datoteka sa izvornim kodom je sledeća:

* Moguće je jasno odvojiti celine, čime se naglašava dodatno čime se bavi grupisani deo koda
* Zajedničke funkcije mogu biti izdvojene u posebnu biblioteku, čineći taj kod ponovno upotrebljivim za druge programe
* Zavisnosti se mogu uvoditi ciljano, samo tamo gde su neophodne

Ovako razdvojene celine kompajliraju se odvojeno svaka za sebe, potom se grupišu.
Rezultat grupisanja može biti izvršna datoteka (na primer, ``a.out``) ili biblioteka, koja potom može biti uključena u više različitih programa.
Razlika da li će biti jedno ili drugo je u tome da li kod koji se kompajlira sadrži ``main`` funkciju.
U slučaju da sadrži, radiće se o izvršnom programu, a ukoliko ne, onda će biti biblioteka.

Analiza koraka prilikom kompajliranja jedne datoteke sa izvornim kodom
----------------------------------------------------------------------

Koristiće se vrlo jednostavan "Hello world!" primer:

.. literalinclude:: primeri/test.c
   :linenos:

U dosadašnjem radu su prepoznata dva koraka koje ``gcc`` radi kada mu se prosledi ``.c`` datoteka: pretprocesiranje i kompajliranje.
Pretprocesiranje je zaduženo da sve pretprocesorske direktive (one koje počinju znakom ``#``, na primer ``#include`` ili ``#define``), razvije, odnosno, da izvrši tekstualnu zamenu gde će direktive biti zamenjene određenim sadržajem.
Da bi se videla pretprocesirana datoteka sa izvornim kodom, potrebno je pokrenuti sledeću komandu:

.. literalinclude:: primeri/komande.rst
   :lines: 2

Sadržaj pretprocesiranog izvornog koda dalje obrađuje kompajler, koji je zadužen da proveri da li je kod sintaksno tačan i od njega napravi set mašinskih instrukcija koje računar može da izvrši.
Rezultat kompajliranje je tzv. objektna datoteka, koja još uvek nije izvršni program (ili biblioteka).

.. literalinclude:: primeri/komande.rst
   :lines: 3

Nakon uspešno izvršenog kompajliranja, pojaviće se ``test.o`` datoteka.
Kao što je navedeno, još uvek se ne radi o izvršnom programu.
Potrebno je još povezati spoljne zavisnosti, odnosno, u ovom slučaju, povezati funkcije koje se koriste iz npr. ``stdio.h`` biblioteke.
Ovo radi poseban program, koji se zove *linker*, što je ujedno i poslednji korak prilikom kompajliranja.

Iz ``gcc``-a se može pozvati na sledeći način:

.. literalinclude:: primeri/komande.rst
   :lines: 4

Rezultat nakon uspešnog linkovanja je izvršna datoteka, npr. ``a.out``, koja se može pokrenuti na isti način kao što je to i do sad rađeno.

Sa linkerom, proces pravljenja izvršne datoteke je kompletiran i izgleda ovako:

.. literalinclude:: primeri/gcc-workflow.rst

Svi navedeni koraci su se izvršavali svaki put kad se na najjednostavniji način pravila izvršna datoteka:

.. literalinclude:: primeri/komande.rst
   :lines: 5

Napomena:

.. literalinclude:: objasnjenja/poredjenje-pre-i-posle-linkera.txt
   :language: none

Kompajliranje više datoteka sa izvornim kodom
---------------------------------------------

Na sličan način moguće je postupiti i u slučaju više datoteka sa izvornim kodom:

1. Za svaku ``.c`` datoteku, potrebno je pokrenuti ``gcc`` sa opcijom ``-c`` i od nje napraviti objektnu datoteku ``.o``
2. Pokrenuti linker preko ``gcc`` komande, tako što će se pored nje navesti sve prethodno dobijene objektne datoteke

Na konkretnom primeru to izgleda ovako:

.. tabs::

  .. tab:: Pravougaonik zaglavlje
    .. literalinclude:: primeri/pravougaonik.h
       :caption: pravougaonik.h
       :linenos:
  .. tab:: Pravougaonik implementacija
    .. literalinclude:: primeri/pravougaonik.c
       :caption: pravougaonik.c
       :linenos:

.. tabs::

  .. tab:: Kvadrat zaglavlje
    .. literalinclude:: primeri/kvadrat.h
       :caption: kvadrat.h
       :linenos:
  .. tab:: Kvadrat implementacija
    .. literalinclude:: primeri/kvadrat.c
       :caption: kvadrat.c
       :linenos:

.. literalinclude:: primeri/main.c
    :caption: main.c
    :linenos:

Treba primetiti da ono što je do sad pisano pre i posle main funkcije, sad je podeljeno u dve datoteke.
Kako je navedeno i u primeru, datoteke sa ekstenzijom ``.h`` se zovu zaglavlja, dok odgovarajuća ``.c`` datoteke se nazivaju implementacijama.
Sama ``main`` funkcija nema svoje zaglavlje, stoga joj nije neophodno da ima svoju ``.h`` biblioteku.

Zašto je sve ovako organizovano?

.. literalinclude:: objasnjenja/zaglavlja-i-implementacije.txt
   :language: none

Pošto se #include direktiva izvršava tokom pretprocesiranja i postavlja čitav sadržaj datoteke unutar druge datoteke,
jasno je da bi se dobile višestruke deklaracije jedne te iste funkcije, što bi rezultovalo greškama prilikom kompajliranja.
Da bi se taj problem izbegao, koriste se tzv. mehanizam "include guard".
On počiva na pretprocesorskim direktivama ``#ifndef`` (if not defined), ``#define`` i ``endif``.
Prve dve linije u zaglavlju tumače se na sledeći način: ako simbol nije definisan (npr. ``PRAVOUGAONIK_H``), definiši ga.
Svaki sledeći nailazak na ``#ifndef PRAVOUGAONIK_H`` rezultovaće da kod neće biti ponovo ispisan tokom pretprocesiranja.
``#endif`` služi da oiviči kod opseg trajanja ``#ifndef`` naredbe.
U većini modernih kompajlera dostupna je i direktiva ``#pragma once``, koja postiže isti efekat, sa manje pisanja, jer se navodi samo na vrhu datoteke.

Da bi se ovo rešenje kompajliralo i pokrenulo, potrebno je pokrenuti sledeće komande:

.. literalinclude:: primeri/komande.rst
   :language: bash
   :start-after: komande_13.3
   :end-before: kraj_komande_13.3

GNU Make
--------

Višestruko pokretanje gcc naredbe za svaki par zaglavlje/implementacija nije skalabilno.
Kako broj datoteka raste, sve bi bilo teže voditi računa šta je potrebno ponovo kompajlirati, pre linkovanja u izvršnu datoteku.
Kao rešenje, nude se alati za build-ovanje programa, a jedno od njih je program ``GNU Make``.
On se koristi tako što se deklarativno navedu pravila i zavisnosti unutar specijalne datoteke sa imenom ``Makefile``, koju program ``make`` prepoznaje i izvršava.

``Makefile`` se sastoji od sledećih činilaca:

* Pravila (*rules*): Objašnjavaju ``make`` programu kako da napravi ciljnu datoteku od izvorne, uz navođenje zavisnosti da bi se to postiglo
* Ciljevi (*targets*): Predstavljaju krajnji proizvod nastao od komandi definisanim u pravilima

Struktura jednog ``Makefile``-a:

.. literalinclude:: objasnjenja/Makefile-opis
    :linenos:

``Makefile`` za primer iz prethodnog potpoglavlja bi mogao izgledati na sledeći način:

.. literalinclude:: primeri/Makefile
    :caption: Makefile
    :linenos:

Pokretanjem ``make`` komande u istom direktorijumu gde se ``Makefile`` nalazi, izvršiće se pravilo ``all``.
Ukoliko je sve u redu, biće prikazan ispis komandi koji odgovara onome što se u prethodnom poglavlju pokretalo ručno.
Svako sledeće pokretanje ``make`` komande, vršiće kompajliranje samo onih datoteka čiji je sadržaj bio izmenjen, čime se smanjuje vreme kompajliranja celokupnog rešenja.
To je jedna od najznačanijih razlika između alata za build rešenja i njegovo kompajliranje.
Program ``make`` će koristiti ``gcc`` pametno, odnosno, vodiće računa da ga ne pokreće tamo gde za tim nema potrebe (nema promena u kodu).

.. TODO Dodati deo za wildcard-ove, promenljive itd.

Ideja ``make`` programa prenesena je i u druge jezike i platforme, te za programski jezik ``Java`` postoji ``ant``, u programskom jeziku ``Ruby`` ``rake`` itd.
Oni počivaju na sličnim idejama, mada se implementacija i korišćeni formati razlikuju.
Zbog svoje apstraktne definicije, on ne mora da se nužno koristi isključivo za build ``C/C++`` rešenja, tako da ga je moguće koristiti i za druge programske jezike/alate i sl.
Na primer, web stranica za zbirku i praktikum se build-uje pomoću ``make`` komande, slajdovi za vežbe na ovom predmetu se takođe build-uju na isti način. Isto važi i za zadatke za kolokvijum.

Postoje alternative što se tiče build alata za ``C/C++``:

* Automake - generiše ``Makefile`` za različite Unix/Linux platforme
* CMake - radi na Windows, Mac i na Linux platofmi
