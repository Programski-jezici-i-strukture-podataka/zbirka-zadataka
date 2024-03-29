Unosom sa tastature zadat je niz ``M`` od maksimalno ``25`` realnih elemenata.
Učitati n elemenata u niz ``M``, koji predstavlja poluprečnike kružnica (voditi računa da su poluprečnici pozitivni brojevi).

1. Formirati niz ``K`` čiji elementi predstavljaju površine krugova sa prečnicima iz niza ``M``
2. Ispisati površinu najvećeg kruga i indeks na kom se ta površina kruga nalazi u nizu ``K``. 
   U slučaju da se krug nalazi na parnom indeksu ispisati površinu zaokruženu na dve decimale, a u slučaju da
   se nalazi na neparnom indeksu ispisati površinu zaokruženu na tri decimale.
3. Preko konzole korisnik unosi realan pozitivan broj ``a``. Prebrojati sve poluprečnike iz niza ``M`` koji su
   veći od broja ``a``, a zatim ispisati broj takvih poluprečnika.

Na izlazu je neophodno ispisati nizove ``M`` i ``K``. Ispis članova niza zaokružiti na 2 decimale.

Formula za računanje površine kruga: :math:`P = r^{2}\cdot\pi` (:math:`\pi` posmatrati kao 3,14)

Primer rada programa:

.. literalinclude:: ispis-programa.txt
   :language: none
