Dinamička alokacija memorije
============================

Podeli svoje utiske o poglavlju na anketi https://docs.google.com/forms/d/1xdwvmDBf-dHSrliFcBA9KL1egNNWD9tYxEjdQRzcqSg

Preduslovi za rad:

.. literalinclude:: objasnjenja/preduslovi-za-rad.txt
   :language: none

Dinamičku alokaciju koristimo kada ne znamo unapred, pre pokretanja programa, koliko nam je memorije potrebno za rad. Do sada smo
u radu sa nizovima uvek unapred određivali veličinu niza. Kada ovako jednom odredimo veličinu niza, ne možemo je kasnije menjati.
Ta memorija nam može postati mala u nekom trenutku. Problem nedovoljne memorije rešavamo tako što je zauzimamo u toku izvršavanja
programa, tj. alociramo je dinamički. Dinamički alociranu memoriju je potrebno uvek nakon korišćenja osloboditi.

Funkcije za dinamičku alokaciju memorije su ``malloc``, ``calloc``, ``realloc`` i ``free``. Sve funkcije se nalaze u biblioteci ``stdlib.h``,
pa je potrebno uključiti je kako bi ih koristili. Funkcije ``malloc`` i  ``calloc`` služe za zauzimanje memorije, a funkcija ``realloc``
za proširenje/smanjene prethodno dinamički zauzete memorije. Ove tri funkcije vraćaju pokazivač na zauzetu memoriju ukoliko su je uspešno
zauzele ili NULL vrednost ukoliko ne mogu da zauzmu memoriju. Imajući ovo u vidu, uvek je potrebno proveriti da li su ove funkcije uspešno
zauzele memoriju i izaći iz programa ako nisu. Funkcija ``free`` služi za oslobađanje dinamički zauzete memorije.

Free
----
Funkcija ``free`` služi za oslobađanje dinamički zauzete memorije. Očekuje pokazivač na dinamički zauzetu memoriju kako bi je oslobodila.
Osnovna forma funkcije je::

  void free(void *ptr);

Malloc
------

Funkcija ``malloc`` se koristi za dinamičku alokaciju memorijskog bloka određene veličine. Funkcija vraća generički pokazivač
tipa ``void *``, koji se može pretvoriti u bilo koji pokazivač. Ne inicijalizuje zauzetu memoriju na početnu vrednost.
Osnovna forma funkcije je::

  void *malloc(size_t size);

gde size_t size predstavlja veličinu memorije koju će ``malloc`` pokušati da zauzme.

.. literalinclude:: primeri/malloc.c
   :linenos:

U primeru iznad unosimo prvo dužinu niza, nakon čega zauzimamo memoriju za tačno toliko članova niza korišćenjem funkcije ``malloc``.
Za veličinu jednog memorijskog bloka koja nam je potrebna koristimo operator ``sizeof``. Ovaj operator očekuje da mu se prosledi tip podatka
i vraća količinu memorije koju taj tip podatka zauzima u bajtovima. Kako je nama potrebna memorija za niz ``int`` tipa, sa ``sizeof(int)``
dobićemo memoriju jednog integer-a, dok ćemo sa ``n * sizeof(int)`` dobiti memoriju za ceo niz. Kada smo pokušali da zauzememo memoriju, potrebno je da
proverimo da li je ona uspešno zauzeta. Ukoliko je ``malloc`` vratio NULL, izlazimo iz programa, ukoliko nije, unosimo članove niza, pa ih ispisujemo.
Na kraju programa, oslobađamo dinamički zauzetu memoriju sa funkcijom ``free``.

Ispis ovog programa je:

.. literalinclude:: primeri/malloc.txt
   :language: none

Calloc
------

Funkcija ``calloc`` se koristi za dinamičku alokaciju memorijskog bloka određene veličine. Funkcija vraća generički pokazivač
tipa ``void *``, koji se može pretvoriti u bilo koji pokazivač. Inicijalizuje svaki zauzet memorijski blok na početnu vrednost 0.
Osnovna forma funkcije je::

  void *calloc(int n, size_t size);

gde size_t size predstavlja veličinu jednog memorijskog bloka, a n broj blokova koje će ``calloc`` pokušati da zauzme.

.. literalinclude:: primeri/calloc.c
   :linenos:

U primeru iznad je sve isto kao u primeru sa ``malloc`` funkcijom, uz razliku da je memorija ovde zauzeta korišćenjem ``calloc`` funkcije. Opet
je potrebno proveriti da li je memorija uspešno zauzeta, kao i osloboditi je na kraju programa.

Ispis ovog programa je:

.. literalinclude:: primeri/calloc.txt
   :language: none

Realloc
-------

Funkcija ``realloc`` se koristi za promenu dinamički alokacirane memorije. Memorija se prethodno mora zauzeti korišćenjem funkcija
``malloc`` ili ``calloc``. Funkcija vraća generički pokazivač tipa ``void *``, koji se može pretvoriti u bilo koji pokazivač. Realokacijom
memorije se zadržavaju prethodne vrednosti i ne inicijalizuje se memorija na početnu vrednost. Osnovna forma funkcije je::

  void *realloc(void *ptr, size_t size);

gde size_t size predstavlja novu veličinu memorije koju je potrebno zauzeti, a ``void *ptr`` pokazivač na prethodno zauzetu memoriju koju je potrebno
smanjiti ili povećati.

.. literalinclude:: primeri/realloc.c
   :linenos:

U primeru iznad unosimo prvo dužinu niza, nakon čega zauzimamo memoriju za tačno toliko članova niza korišćenjem funkcije ``malloc``.
Kada smo pokušali da zauzememo memoriju, potrebno je da proverimo da li je ona uspešno zauzeta. Ukoliko je ``malloc`` vratio NULL,
izlazimo iz programa, ukoliko nije, unosimo članove niza. Nakon toga, unosimo novu dužinu niza i zauzimamo memoriju za promenjenu
dužinu korišćenjem funkcije ``realloc``. Funkciji ``realloc`` prosleđujemo pokazivač na niz i ``m * sizeof(int)`` gde je ``m`` nova
dužina niza. Potrebno je da ponovo proverimo da li je memorija uspešno zauzeta ili je funkcija ``realloc`` vratila NULL. Ukoliko je
memorija zauzeta, proveravamo da li je nova dužina niza veća od stare i u tom slučaju unosimo ostale elemente niza. Za dužinu niza
sada uzimamo ``m``, pa će ``for`` petlja za ispis svih elemenata niza ići do ove vrednosti. Na kraju programa, oslobađamo dinamički
zauzetu memoriju sa funkcijom ``free``.

Ispis ovog programa je:

.. literalinclude:: primeri/realloc.txt
   :language: none
