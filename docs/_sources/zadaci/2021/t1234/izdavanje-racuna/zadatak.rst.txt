Napisati program koji omogućuje izdavanje računa. Radnik unosi ime i prezime kupca (string od maksimalno 30 karaktera), kao i broj kupljenih artikala.
Nakon toga, za svaki artikal potrebno je upisati šifru artikla (string od maksimalno 8 karaktera), kao i njegovu cenu. Ukoliko šifra artikla počinje sa karakterom 'P', to označava da je proizvod trenutno na popustu i da njegovu cenu treba umanjiti za 10%.
Nakon unetih artikala ispisati ukupnu cenu koju kupac treba da plati sa obračunatim PDV-om, koji predstavlja dodatnih 20% na ukupnu cenu.
Uraditi validaciju unosa za broj artikala, kao i za cenu. Program treba da vrati na ponovni unos korisnika ukoliko je uneo vrednost manju ili jednaku od nule u oba slučaja.

Primer rada programa:

.. literalinclude:: izdavanje-racuna.txt

