|Publish to Github Pages Badge| |pages-build-deployment-badge|

Zbirka zadataka
===============

Zbirka sačinjena od zadataka koji su davani na testovima u sklopu predispitnih obaveza na predmetu "Programski jezici i strukture podataka", na smerovima E1, E2 i PSI.

Dodavanje novih zadataka
------------------------

U toku je izrada mehanizma za dodavanje novih zadataka

Izmene zbirke
-------------

Potrebno je:

1. Instalirati Python, verziju 3.10.12 (radi i na verzijama >=3.8.6)
2. Klonirati repozitorijum: ``git clone https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka.git``
3. Unutar kloniranog repozitorijuma napraviti virtuelno okruženje: ``python -m venv ./venv-zbirka``
4. Aktivirati virtuelno okruženje: ``source ./venv-zbirka/bin/activate`` (Windows: ``.\venv-zbirka\Scripts\activate``)
5. Instalirati neophodne zavisnosti: ``pip install -r requirements.txt``

Nakon prvobitnog podešavanja, svaki sledeći put pre rada treba aktivirati virtuelno okruženje (korak 4.).
Nakon odgovarajućih izmena, moguće je izgenerisati sajt u lokalu pomoću komande u Terminalu ili Command Prompt-u::

  make html (make.bat html za Windows)

Sajt će biti u _build direktorijumu i može se videti preko veb pretraživača tako što se otvori fajl na putanji::

  _build/html/index.html

Može se otvoriti preko browser-a iz komandne linije, na primer::

  firefox _build/html/index.html &

Prilikom dodavanja novih zadataka napraviti granu koja ima prefiks "zadaci"::

  git checkout -b zadaci-<dodatni-opis>

Dodati zadatke::

  git add --all (paziti koji sve fajlovi ulaze u staging)
  git commit -m <komit-poruka-o-zadacima-koji-se-dodaju>
  git push origin <ime-grane>

Nakon push-a bi trebalo da se pojavi link koji odmah nudi da napravi Pull Request.

Praktikum
---------

Procedura je slična kao i za zadatke, jedino što je neophodno da grana ima prefiks "praktikum"::

  git checkout -b praktikum-<ime-poglavlja>

Ostali koraci su slični kao i kod dodavanja zadataka u zbirku.

.. |Publish to GitHub Pages Badge| image:: https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka/actions/workflows/publish.yml/badge.svg?branch=master
   :target: https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka/actions/workflows/publish.yml

.. |pages-build-deployment-badge| image:: https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka/actions/workflows/pages/pages-build-deployment/badge.svg?branch=gh-pages
   :target: https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka/actions/workflows/pages/pages-build-deployment
