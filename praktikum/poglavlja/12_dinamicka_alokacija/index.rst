Dinamička alokacija memorije
============================

Podeli svoje utiske o poglavlju na anketi https://docs.google.com/forms/d/1v87L2JkRzXnvglKgZtM-rPJjTuzB-93z9LHasXQMbA0

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Dinamičku alokaciju koristimo kada ne znamo unapred, pre pokretanja programa, koliko nam je memorije potrebno za rad. Do sada smo
u radu sa nizovima uvek unapred određivali veličinu niza. Kada ovako jednom odredimo veličinu niza, ne možemo je kasnije menjati.
Ta memorija nam može postati mala u nekom trenutku. Problem nedovoljne memorije rešavamo tako što je zauzimamo u toku izvršavanja
programa, tj. alociramo je dinamički. Dinamički alociranu memoriju je potrebno uvek nakon korišćenja osloboditi.

Funkcije za dinamičku alokaciju memorije su ``malloc``, ``calloc``, ``realloc`` i ``free``. Sve funkcije se nalaze u biblioteci ``stdlib.h``,
pa je potrebno uključiti je kako bi ih koristili. Funkcije ``malloc`` i  ``calloc`` služe za zauzimanje memorije, a funkcija ``realloc``
za proširenje/smanjenje prethodno dinamički zauzete memorije. Ove tri funkcije vraćaju adresu početka memorijskog bloka ukoliko je memorija uspešno
zauzeta ili NULL vrednost ukoliko se memorija ne može zauzeti. Imajući ovo u vidu, uvek je potrebno proveriti da li su ove funkcije uspešno
zauzele memoriju i izaći iz programa ako nisu. Funkcija ``free`` služi za oslobađanje dinamički zauzete memorije.

Malloc
------

Funkcija ``malloc`` se koristi za dinamičku alokaciju memorijskog bloka određene veličine. Funkcija vraća generički pokazivač
tipa ``void *``, koji se može pretvoriti u bilo koji pokazivač. Ne inicijalizuje zauzetu memoriju na početnu vrednost.
Osnovna forma funkcije je::

  void *malloc(``size_t`` size);

gde ``size_t size`` predstavlja veličinu memorije koju će ``malloc`` pokušati da zauzme.

.. literalinclude:: primeri/malloc.c
   :linenos:

U primeru iznad prvo unosimo dužinu niza, a zatim zauzimamo memoriju za tačno toliko članova niza korišćenjem funkcije ``malloc``.
Za određivanje veličine memorijskog bloka koji nam je potreban, koristimo operator ``sizeof``. Ovaj operator može se koristiti sa
tipovima podataka ili sa promenljivama, tako da je jedan od načina da mu prosledimo tip podatka. Na primer, ``sizeof(int)`` nam daje
veličinu jednog integer-a u bajtovima, dok sa izrazom ``n * sizeof(int)`` dobijamo ukupnu veličinu memorije potrebnu za ceo niz.

Nakon što pokušamo da zauzmemo memoriju, potrebno je da proverimo da li je to uspešno učinjeno. Ako ``malloc`` vrati NULL, to znači
da je zauzimanje memorije neuspešno i u tom slučaju treba da izađemo iz programa. Ako je memorija uspešno zauzeta, unosimo članove
niza, a zatim ih ispisujemo.

Kada nam više nije potrebna, ili kada smo završili sve što smo planirali u vezi sa dinamičkom memorijom, oslobađamo zauzetu
memoriju korišćenjem funkcije ``free``. Iako u primerima često oslobađamo memoriju na kraju programa, u stvarnim aplikacijama,
posebno onima koje rade u realnom vremenu ili u dugoročnim procesima (npr. serveri), važno je da oslobađamo memoriju čim nam više
nije potrebna, kako bismo izbegli curenje memorije.

Ispis ovog programa je:

.. literalinclude:: primeri/malloc.txt
   :language: none

Free
----

Funkcija ``free`` služi za oslobađanje dinamički zauzete memorije. Memorija se zauzima nekom od funkcija za dinamičku alokaciju,
koje vraćaju pokazivač na zauzetu memoriju. Ova funkcija očekuje pokazivač na tu memoriju kako bi je oslobodila.
Osnovna forma funkcije je::

  void free(void *ptr);

Calloc
------

Funkcija ``calloc`` se koristi za dinamičku alokaciju memorijskog bloka određene veličine. Blokovi memorije koje alocira funkcija
``calloc`` su sukcesivni, što znači da su raspoređeni uzastopno u memoriji. Ovo je bitna karakteristika, jer omogućava
efikasno korišćenje memorije i lakše upravljanje sa skupovima podataka koji se koriste u kontinuitetu. Funkcija vraća generički
pokazivač tipa ``void *``, koji se može pretvoriti u bilo koji pokazivač. Ukoliko dođe do greške u alokaciji, funkcija će vratiti
``NULL`` vrednost. Za razliku od funkcije ``malloc``, koja samo alocira memoriju bez inicijalizacije, ``calloc`` automatski postavlja
sve bajtove u dodeljenoj memoriji na nulu. To znači da će svaka pozicija u memoriji biti postavljena na 0 (ili ``NULL`` u slučaju pointera).
Osnovna forma funkcije je::

  void *calloc(int n, ``size_t`` size);

gde ``size_t size`` predstavlja veličinu jednog memorijskog bloka, a n broj blokova koje će ``calloc`` pokušati da zauzme.

.. literalinclude:: primeri/calloc.c
   :linenos:

U primeru iznad je sve isto kao u primeru sa ``malloc`` funkcijom, uz razliku da je memorija ovde zauzeta korišćenjem ``calloc``
funkcije. Opet je potrebno proveriti da li je memorija uspešno zauzeta, kao i osloboditi je na kraju programa.

Ispis ovog programa je:

.. literalinclude:: primeri/calloc.txt
   :language: none

Realloc
-------

Funkcija ``realloc`` koristi se za promenu veličine prethodno alociranog bloka memorije. Memorija se prethodno mora zauzeti
korišćenjem funkcija ``malloc`` ili ``calloc``. Realokacijom memorije se zadržavaju prethodne vrednosti i ne inicijalizuje se memorija na početnu vrednost.
Ukoliko je potrebno proširiti alocirani blok memorije (povećate njegovu veličinu), ``realloc`` će to i pokušati. Ako nije moguće
proširiti memoriju na postojećoj lokaciji (zbog fragmentacije ili drugih razloga), ``realloc`` može alocirati novi blok u nekoj
drugoj lokaciji i prekopirati sadržaj iz stare memorije u novu. Ukoliko je potrebno smanjiti veličinu memorijskog bloka, ``realloc``
jednostavno seče blok i oslobađa višak memorije, čuvajući samo prvih new_size bajtova.
Ako je alokacija uspešna, ``realloc`` vraća generički pokazivač na prošireni ili skraćeni memorijski blok tipa ``void *``.
Ovaj pokazivač može biti isti kao prethodni ili može biti nova adresa u slučaju premeštanja bloka. Ukoliko dođe do greške i nije
moguće alocirati memoriju, ``realloc`` vraća NULL, a originalni blok memorije ostaje nepromenjen.
Osnovna forma funkcije je::

  void *realloc(void *ptr, ``size_t`` new_size);

gde ``size_t new_size`` predstavlja novu veličinu memorije koju je potrebno zauzeti, a ``void *ptr`` pokazivač na prethodno zauzetu
memoriju koju je potrebno smanjiti ili povećati.

.. literalinclude:: primeri/realloc.c
   :linenos:

U primeru iznad unosimo prvo dužinu niza, nakon čega zauzimamo memoriju za tačno toliko članova niza korišćenjem funkcije ``malloc``.
Kada smo pokušali da zauzememo memoriju, potrebno je da proverimo da li je ona uspešno zauzeta. Ukoliko je ``malloc`` vratio ``NULL``,
izlazimo iz programa, ukoliko nije, unosimo članove niza. Nakon toga, unosimo novu dužinu niza i zauzimamo memoriju za promenjenu
dužinu korišćenjem funkcije ``realloc``. Funkciji ``realloc`` prosleđujemo pokazivač na niz i ``m * sizeof(int)`` gde je ``m`` nova
dužina niza. Potrebno je da ponovo proverimo da li je memorija uspešno zauzeta ili je funkcija ``realloc`` vratila ``NULL``. Ukoliko je
memorija zauzeta, proveravamo da li je nova dužina niza veća od stare i u tom slučaju unosimo ostale elemente niza. Za dužinu niza
sada uzimamo ``m``, pa će ``for`` petlja za ispis svih elemenata niza ići do ove vrednosti. Na kraju programa, oslobađamo dinamički
zauzetu memoriju sa funkcijom ``free``.

Ispis ovog programa je:

.. literalinclude:: primeri/realloc.txt
   :language: none
