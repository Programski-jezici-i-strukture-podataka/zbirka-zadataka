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
5. Instalirati neophodne zavisnosti: ``pip install requirements.txt``

Nakon odgovarajućih izmena u, na primer, ``conf.py`` ili u ``_static/alabaster.css`` fajlu, ili prilikom ručnog dodavanja novih zadataka (u direktorijum ``zadaci``), potrebno je:

1. ``make html``, ukoliko se samo proverava da li je promena uspešna (rezultujuće stranice biće u _build direktorijumu, lokalno se može otvoriti ``_build/html/index.html``), ili
2. ``make github``, koji će izbildovati zbirku, i prebaciti sadržaj iz ``_build`` u ``docs`` direktorijum, odakle se servira zbirka
