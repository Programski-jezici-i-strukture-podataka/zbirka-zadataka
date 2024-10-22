Nizovi
======

Podeli svoje utiske o poglavlju na anketi `OVDE <https://docs.google.com/forms/d/1yTy8JHcbqWZH6xarUcUH697pDgfkHCB9w6FER3kbIwM>`_.

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Do sad je bio uveden koncept promenljive, koja ima jedinstveno ime, sadrži jednu vrednost i određene je veličine.
Veličina i vrednost zavise od tipa promenljive.
Nizovi predstavljaju više uzastopnih lokacija u memoriji, gde svaka poput promenljive ima svoju vrednost i sve su iste veličine.
Ukoliko se upotrebi analogija gde promenljiva predstavlja jednu "kućicu" u memoriji, niz je čitava ulica tipskih kuća (sve liče jedna na drugu).
To je zato što nizovi, kao i promenljive, imaju svoj tip i svi članovi niza su tog tipa.
Članovi se nazivaju i elementima niza.

Primer deklaracije niza::

  int niz[10];

Ova deklaracija napraviće niz od 10 celobrojnih elemenata.

Njima nije moguće pristupiti odjednom, već pojedinačnim elementima::

  niz[0] = 5;
  int a = niz[2];

Napomena:

  Indeksiranje nizova u programskom jeziku C kreće od 0!
  Za niz od 10 elemenata, validni indeksi su od 0 do 9!

Osnovni primeri rada sa nizovima
--------------------------------

Tokom rada sa nizovima moguće je raditi isključivo sa njegovim pojedinačnim elementima, ne sa celim nizom odjednom.
Da bi se obradio svaki element niza, potrebno je koristiti ``for`` petlju.

Pretpostavimo da imamo deklaraciju promenljive ``i`` i niza celobojnih vrednosti ``niz`` na sledeći način:

.. literalinclude:: primeri/nizovi-osnovno.c
   :linenos:
   :lines: 5

Primer upisa vrednosti u niz sa standardnog ulaza:

.. literalinclude:: primeri/nizovi-osnovno.c
   :linenos:
   :lines: 7-11

Primer ispisa vrednosti iz niza na standardni izlaz:

.. literalinclude:: primeri/nizovi-osnovno.c
   :linenos:
   :lines: 13-16

Na primerima se može videti da se promenljiva ``i`` koristi u ``for`` petlji, njena početna vrednost je ``0``, a krajnja veličina niza minus 1.
Za primer iznad to će biti vrednost ``4``.
U jednoj iteraciji for petlje, određeni element niza biće učitan, odnosno ispisan.

Korišćenje određenog dela niza
------------------------------

Kod deklaracije niza je njegova veličina navedena unapred, pre kompajliranja.
Često se u praksi dešava situacija da postoje slučajevi korišćenja kad je potrebno popuniti samo deo niza.
Sa druge strane, dimenzija niza mora podržati slučaj koji traži najviše iskorišćenih elemenata.

Ovakva fleksibilnost postiže se uvođenjem nove promenljive ``n``, koja će označavati broj upotrebljenih elemenata:

.. literalinclude:: primeri/nizovi-sa-n.c
   :linenos:

Na početku programa unosi se vrednost ``n``.
Obavezno je da bude u granicama od ``1`` do ``MAX_SIZE``, kako bi broj korišćenih elemenata bio unutar granica niza.

Primer rada programa:

.. literalinclude:: primeri/nizovi-sa-n-ispis.txt
   :language: none

Prve dve vrednosti koje su unete su izvan dimenzija niza, tako da će one biti odbijene.
Od korisnika će se tražiti da unosi vrednosti sve dok ne zada neku koja se nalazi u granicama niza (ovo obezbeđuje ``do-while`` petlja u programu).

Napomena:

.. literalinclude:: objasnjenja/define-direktiva.txt
   :language: none

Primer koji traži srednju vrednost unetih elemenata niza:

.. literalinclude:: primeri/srednja-vrednost-niza.c
   :linenos:

Ispis programa:

.. literalinclude:: primeri/srednja-vrednost-niza-ispis.txt
   :language: none

Traženje minimalnog/maksimalnog elementa u nizu
-----------------------------------------------

Često je neophodno pronaći vrednost najmanjeg, odnosno, najvećeg člana u nizu.
Kako je prethodno navedeno, u programskom jeziku C nije moguće odjednom pristupiti svim članovima i pronaći među njima najveći/najmanji element.

Algoritam je sledeći:

1. Pretpostaviti da je neki od članova niza njegov najveći/najmanji element, tako što se njegova vrednost sačuva u posebnu promenljivu (uglavnom se bira vrednost prvog člana niza)
2. Izabrati naredni član niza (uglavnom se ide redom, drugi, treći, četvrti itd.)
3. Uporediti ga sa vrednošću promenljive koja trenutno glasi kao najveća/najmanja
4. Ukoliko je trenutni član niza veći/manji od vrednosti iz prethodnog koraka, postaviti vrednost člana niza kao novu najveću/najmanju vrednost
5. Vratiti se na korak 2. i ponoviti postupak dokle god ima neobrađenih članova niza

Izvršavanje navedenih koraka garantuje da će se nakon prolaska kroz čitav niz, odnosno, obradu svih njegovih članova u promenljivoj koja je namenjena za to naći vrednost najvećeg/najmanjeg elementa.
Ovaj algoritam primenljiv je na nizove čiji elementi nisu prethodno uređeni po vrednosti (u rastućem ili opadajućem redosledu).

Primer koji traži maksimalnu vrednost u nizu:

.. literalinclude:: primeri/maksimalna-vrednost-niza.c
   :linenos:

Ispis programa:

.. literalinclude:: primeri/maksimalna-vrednost-niza-ispis.txt
   :language: none

Za traženje minimalne vrednosti u nizu potrebno je obrnuti samo smer relacionog operatora u ``if`` naredbi.

Sortiranje nizova
-----------------

Sortiranje niza predstavlja uređenje njegovih elemenata tako da oni budu u rastućem ili opadajućem redosledu.
Postoji mnoštvo algoritama za sortiranje niza. Ovde će biti prikazana dva, Bubble Sort i Selection Sort.
Kod za učitavanje elemenata niza i njihov ispis je izostavljen radi akcenta na samim algoritmima.

Bubble Sort algoritam:

.. literalinclude:: primeri/bubble-sort.c
   :linenos:
   :lines: 7, 22-42

Kod ovog algoritma najveći/najmanji element "isplivava" na kraj niza nakon jednog prolaska kroz ceo niz (``for`` petlja po ``j``).
To se dešava tako što se susedni elementi porede i ako se ispostavi da je prvi veći/manji od drugog, izvršiće se njihova zamena.
Čitav postupak ponavlja se ``n - 1`` puta i svaki put je ``for`` petlja po ``j`` sve kraća, zbog toga što se sa rastom ``i`` desilo "isplivavanje" elemenata na njihove pozicije.
Bubble Sort je vrlo neefikasan algoritam za sortiranje niza i koristi se isključivo u svrhe učenja zbog svoje jednostavnosti.

Selection Sort algoritam:

.. literalinclude:: primeri/selection-sort.c
   :linenos:
   :lines: 7, 22-42

Za razliku od Bubble Sort algoritma, Selection Sort traži odgovarajući element desno od ``i``-tog člana.
Ukoliko nađe najveći/najmanji, pristupa se zameni ``i``-tog i najvećeg/najmanjeg.
Ako se, pak, ispostavi da ne postoji veći/manji od ``i``-tog, zamena elemenata se neće dogoditi.

Napomena:

.. literalinclude:: objasnjenja/ugnezdena-petlja.txt
   :language: none

Napomena:

.. literalinclude:: objasnjenja/zamena-mesta-elementima-niza.txt
   :language: none