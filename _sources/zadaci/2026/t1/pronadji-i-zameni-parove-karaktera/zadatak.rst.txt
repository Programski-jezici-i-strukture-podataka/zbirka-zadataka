Napisati program koji pronalazi u stringu parove zadatih karaktera i menja im mesta.
Program traži od korisnika da unese string maksimalne dužine 100 karaktera, koji se može sastojati od više reči, zatim dva karaktera.
Uneti karakteri moraju biti isključivo mala slova.

Potrebno je proći kroz string, pronaći prvi karakter, zatim u ostatku stringa pronaći prvu pojavu drugog karaktera.
Ukoliko ona postoji, potrebno je izvršiti zamenu njihovih mesta u stringu.
Zamena se vrši bez obzira na veličinu slova.
Zamenjena slova uzimaju veličinu originalnog slova na toj poziciji.
Ukoliko je originalno slovo bilo veliko, zamenjeno slovo postaće veliko, iako je na originalnoj poziciji bilo malo i obrnuto (pogledati primere).
Ako dođe do situacije da prvi karakter nema odgovarajući drugi karakter sa kojim bi se zamenio, ispisati sledeći tekst: ``Ne postoji odgovarajuci broj parova za znakove <znak1> i <znak2>!\n``.
U suprotnom slučaju, kada drugog znaka ima više od prvog i kada i jednog i drugog ima tačno koliko treba, ne ispisivati navedenu poruku.

Na standardnom izlazu (ekranu terminala) ispisati string nakon izmene.


Primer rada programa:

Primer rada programa u slučaju jednostavne zamene, oba slova mala:

.. literalinclude:: ispis-programa.txt
   :language: none


Primer rada programa u slučaju zamene uz različite veličine slova:

.. literalinclude:: ispis-programa-razlicite-velicine.txt
   :language: none

Primer rada programa u slučaju kada string ima jedan prvi karakter, a više pojava drugog karaktera:

.. literalinclude:: ispis-programa-jedan-prvi-vise-drugih.txt
   :language: none

Primer rada programa u slučaju da nema dovoljno parova unesenih karaktera:

.. literalinclude:: ispis-programa-nema-dovoljno-parova.txt
   :language: none

Primer rada programa u slučaju kada su u stringu prvi i drugi karakter u pogrešnom redosledu:

.. literalinclude:: ispis-programa-pogresan-redosled.txt
   :language: none

