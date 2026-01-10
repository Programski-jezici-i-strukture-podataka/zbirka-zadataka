Napisati program koji konvertuje uneti string veličine od najviše 30 karaktera u jednu od notacija: ``snake_case`` ili ``kebab-case``.
Snake notacija sadrži donju crtu (``_``) umesto razmaka, dok Kebab notacija umesto razmaka ima crticu (``-``).
Korisnik bira u koju od navedenih notacija će biti konvertovan string.
Normalizovati string tako da sadrži isključivo mala slova.
U slučaju da string sadrži neki od znakova koji nisu slovo ili broj, izaći iz programa uz poruku greške.
Ukoliko je konverzija uspešno sprovedena, ispisati rezultujući string, kao i ukupan broj konvertovanih karaktera u stringu.

**Napomene**

* Obratiti pažnju na validaciju karaktera koji će biti korišćen za pretvaranje u određenu notaciju (može biti samo ``_`` ili ``-``)
* Testirati program i za slučaj kad korisnik unese više karaktera od veličine ulaznog stringa

Primer rada programa:

.. literalinclude:: ispis-programa.txt
   :language: none

Primer rada programa u slučaju nevalidnog unosa sa tastature:

.. literalinclude:: ispis-programa-nevalidan-unos.txt
   :language: none
