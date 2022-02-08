|Publish to Github Pages Badge|

Zbirka zadataka
===============

Zbirka sačinjena od zadataka koji su davani na testovima u sklopu predispitnih obaveza na predmetu "Programski jezici i strukture podataka", na smerovima E1, E2 i PSI.

Dodavanje novih zadataka
------------------------

U toku je izrada mehanizma za dodavanje novih zadataka

Izmene konfiguracije zbirke
---------------------------

Potrebno je:

1. Instalirati Python, verziju 3.X
2. Klonirati repozitorijum: ``git clone https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka.git``
3. Unutar kloniranog repozitorijuma napraviti virtuelno okruženje: ``python -m venv-zbirka``
4. Aktivirati virtuelno okruženje: ``source ./venv-zbirka/bin/activate``
5. Instalirati neophodne zavisnosti: ``pip install -r requirements.txt``

Nakon odgovarajućih izmena, moguće je izgenerisati sajt u lokalu pomoću komande u Terminalu ili Command Prompt-u::

  make html (make.bat html za Windows)

Sajt će biti u _build direktorijumu i može se videti preko veb pretraživača tako što se otvori fajl na putanji::

  _build/html/index.html

.. |Publish to GitHub Pages Badge| image:: https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka/actions/workflows/publish.yml/badge.svg?branch=master&event=push
   https://github.com/Programski-jezici-i-strukture-podataka/zbirka-zadataka/actions/workflows/publish.yml
