Funkcije
========

Podeli svoje utiske o poglavlju na anketi `OVDE <https://docs.google.com/forms/d/1dahCI3494yRQzk0O5oWbRtqQHn3hNFX5uYUt0shtI40>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Definicija funkcija
-------------------

Kako rešenja postaju komplikovanija, povećava se šansa za ponavljanjem sličnog koda na više različitih mesta.
U slučaju da je neophodno promeniti postojeće rešenje, potrebno je promeniti na svim mestima gde se taj sličan kod nalazi.
Ovo je podložno greškama i zbog toga se uvodi pojam funkcije.

Funkcije pomažu oko tzv. dekompozicije problema na manje podprobleme.
Ovo pomaže u smanjenju mentalnog napora pri analizi rešenja, tako što će se kod koji je međusobno povezan biti grupisan na jednom mestu.
Svaku funkciju moguće je posmatrati kao "crnu kutiju" sa određenim ulaznim vrednostima i jednim rezultatom.
Kombinovanjem poziva funkcija, odnosno sklapanjem podproblema, dolazi se do rešavanja problema.

Funkcije su već uveliko korišćene u primerima do sad.
Počevši od funkcija za rad sa standardnim ulazom ``printf`` i ``scanf``, preko matematičkih funkcija poput ``pow`` i ``sqrt`` ili za rad sa stringovima, poput ``strlen``.
Te funkcije su dostupne preko zaglavlja ``stdio.h``, ``math.h`` i ``string.h``.
Svi prethodni primeri i programi samo pozivaju ove funkcije koje su definisane na nekom drugom mestu.

.. tabs::

  .. tab:: Deklaracija i definicija zajedno
    .. literalinclude:: primeri/funkcija-za-sabiranje.c
       :linenos:
  .. tab:: Deklaracija i definicija odvojeni
    .. literalinclude:: primeri/funkcija-za-sabiranje-alt.c
       :linenos:

Iznad je dat primer funkcije ``zbir`` koja sabira dva broja na dva načina.
Funkciju je moguće deklarisati i definisati na istom mestu, a moguće je napraviti deklaraciju, pa negde kasnije definiciju.
Oba načina rezultovaće kodom sa istim ponašanjem, stoga je na izboru programera kako će raditi.
Kada su funkcije deklarisane, pa potom definisane, to pomaže ``main`` funkciji da "ispliva" ka vrhu, jer je ona ta koja najbitnija.
U slučaju korišćenja više ``.h`` i ``.c.`` datoteka u rešenju, deklaracije funkcija će biti u ``.h`` datotekama.
Dobro napisane funkcije, sa dobrim imenovanjem, pomažu pri analizi šta program radi bez ulaska u detalje funkcionisanja koda.

Obe varijante primera daju isti ispis:

.. literalinclude:: primeri/funkcija-za-sabiranje-ispis.txt
   :language: none

Parametri funkcije
------------------

Prilikom poziva funkcije, potrebno je navesti vrednosti sa kojima se ona poziva. Ove vrednosti nazivaju se konkretni parametri ili argumenti.
Broj tih vrednosti, kao i njihovi tipovi, navode se prilikom deklaracije funkcije i nazivaju formalni parametri ili parametri.
Formalni parametri funkcije predstavljaju promenljive koje važe samo unutar te funkcije, a dobijaju početnu vrednost spolja, odnosno, prilikom poziva.
Ova apstrakcija predstavlja način kako funkcija može da radi za bilo koje vrednosti konkretnih parametara dokle god su one odgovarajućeg tipa.

Prenos parametara u funkciju
----------------------------

Parametre je moguće preneti po vrednosti i po referenci.

.. tabs::

  .. group-tab:: Po vrednosti
    .. literalinclude:: primeri/po-vrednosti.c
       :linenos:
  .. group-tab:: Po referenci
    .. literalinclude:: primeri/po-referenci.c
       :linenos:

Ispis u oba slučaja je različit:

.. tabs::

  .. group-tab:: Po vrednosti
    .. literalinclude:: primeri/po-vrednosti-ispis.txt
       :language: none
  .. group-tab:: Po referenci
    .. literalinclude:: primeri/po-referenci-ispis.txt
       :language: none

Kod prenosa po vrednosti, parametar funkcije samo dobija vrednost i promena te vrednosti unutar funkcije neće uticati na promenljivu van funkcije čija je vrednost prosleđena.
U slučaju prenosa po referenci, parametar funkcije dobija adresu promenljive izvan funkcije i posredstvom te adrese je moguće uticati na vrednost promenljive izvan funkcije.

Nizovi i funkcije
-----------------

U programskom jeziku C, nizovi se isključivo prenose po referenci, odnosno, preneće se adresa početka niza.
Ovo daje mogućnost čitanja vrednosti niza, ali i promenu vrednosti unutar niza.
Pretpostaviti da postoji niz unetih celobrojnih vrednosti i da je potrebno naći sumu tog niza:

.. literalinclude:: primeri/nizovi-preko-funkcija.c
   :linenos:
   :lines: 36-46

Napomena:

.. literalinclude:: objasnjenja/niz-kao-parametar.txt
   :language: none

Povratna vrednost funkcije
--------------------------

Prilikom deklaracije, odnosno definicije funkcije, pre njenog imena navodi se povratni tip, koji predstavlja tip vrednosti koju će funkcija vratiti onom ko je poziva.
Unutar funkcije, nakon što se dobije željeni rezultat, on će se "vratiti" pomoću ``return`` naredbe.

.. literalinclude:: primeri/faktorijel-funkcija.c
   :linenos:

Funkcija za traženje faktorijela prima celobrojnu vrednost kao parametar.
Pošto ništa ne garantuje da neko ko koristi funkciju neće pozvati sa negativnom vrednošću, potrebno je bilo proveriti vrednost pre računanja faktorijela.
Isto tako, postoji tzv. "granični slučaj" za vrednost ``0``, gde se po definiciji dobija vrednost ``1``.
Za obe ove varijante, funkcija ima posebne ``if`` grane u programu i naredbu ``return``.
Takođe, za preostale vrednosti, faktorijel se računa po standardnoj formuli, tako da postoji ``return`` naredba i za ovaj slučaj.
Kada se naiđe na bilo koju od navedenih ``return`` naredbi, funkcija će se završiti i biće vraćen rezultat.

Napomena:

.. literalinclude:: objasnjenja/return-vrednost.txt
   :language: none

U primeru je funkcija pozvana za sve tri različita skupa vrednosti, kako bi se demonstriralo njeno ponašanje u svim slučajevima:

.. literalinclude:: primeri/faktorijel-funkcija-ispis.txt
   :language: none

Sa druge strane, postoje i funkcije koje nemaju povratnu vrednost.
Kod njih će povratni tip biti ``void``.
Ovakve funkcije koriste se uglavnom kada treba nešto upisati/ispisati, bilo na standardni ulaz/izlaz ili u datoteku, što će biti obrađeno itd.

Programski jezik C ne podržava vraćanje više od jedne vrednosti pomoću ``return`` naredbe.
Funkcije povratnog tipa ``void`` i prenos parametara po referenci može da pomogne u tom slučaju.
Nizovi kao povratne vrednosti nisu mogući, jedina varijanta je prenos početne adrese putem prenosa po referenci.

.. literalinclude:: primeri/kategorizacija-ljudi.c
   :linenos:

Ovaj program daće ispis:

.. literalinclude:: primeri/kategorizacija-ljudi-ispis.txt
   :language: none

Funkcija ``ispisi_kategoriju`` je primer ``void`` funkcije koja se koristi za ispis prosleđenih vrednosti.
Funkcija ``unos_podataka`` prenosi više vrednosti po referenci pomoću kojih će postaviti vrednosti spoljnih promenljivih čije adrese prima.

Primer funkcija za rad sa nizovima
----------------------------------

.. literalinclude:: primeri/nizovi-preko-funkcija.c
   :linenos:

U ovom primeru navedene su definicije funkcija za unos i ispis, zajedno sa prethodnim primerom za računanje sume elemenata niza.
Sve definisane funkcije su pozvane u ``main`` funkciji, što omogućava njihovo izvršavanje.

Primer ispisa programa:

.. literalinclude:: primeri/nizovi-preko-funkcija-ispis.txt
   :language: none

Napomena:

.. literalinclude:: objasnjenja/nizovi-preko-funkcija.txt
   :language: none
