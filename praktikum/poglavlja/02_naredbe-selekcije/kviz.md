## Koji će biti ispis sledećeg programa?

```c
#include <stdio.h>

int main()
{
   int a = 3, b = 5, c = a / b;

   if(a > b)
   {
      printf("Kolo srece");
   }
   else
   {
      printf("Ipak");
   }

   if(c)
   {
      printf(" se okrece!\n");
   }

   return 0;
}
```

1. [x] Ipak
    > ``a > b`` je netačno za zadate vrednosti 3 i 5, tako da će se ići u else i ispisati "Ipak". a / b će izvršiti celobrojno deljenje brojeva 3 i 5, pritom dajući rezultat 0, što se smatra logički netačnom vrednošću u programskom jeziku C. Zato neće biti dodatnog ispisa.
1. [ ] Kolo sreće se okrece
    > 3 nije manje od 5, stoga izraz u ``if`` naredbi neće biti zadovoljen. U tom slučaju, izvršiće se ``else`` naredba. Drugi deo ispisa se neće dogoditi zbog rezultata celobrojnog deljenja broja 3 i 5, što će dati rezultat 0, što je logički netačno.
1. [ ] Ipak se okrece
    > Iako je prvi deo odgovora tačan, drugi deo se neće ispisati usled celobrojnog deljenja broja 3 i 5, što će dati rezultat 0, što je logički netačno.
1. [ ] Ništa neće biti ispisano
   > Ovo ne može biti ni za jedan par vrednosti a i b tačno, jer imamo barem jednu if-else naredbu, gde se mora ispisati barem nešto.

## Razlika između naredbi selekcije i naredbi ciklusa je?

1. [x] Kod naredbi selekcije će biti izabran deo koda koji će se izvršiti, dok naredbe ciklusa imaju mogućnost izvršavanja određenog koda više puta
1. [ ] Naredbe selekcije biraju kod koji se izvršava, dok naredbe ciklusa ne utiču na redosled naredbi tokom izvršavanja programa
1. [ ] Naredbe ciklusa biraju kod koji se izvršava, dok naredbe selekcije izvršavaju određeni kod više puta
1. [ ] Razlika je isključivo u korišćenim ključnim rečima, u ponašanju nema znatnih razlika

## Koju vrednost će ispisati sledeći program za unete vrednosti 6 i 9?

```c
#include <stdio.h>

int main()
{
   int vr, rez;

   printf("Unesite vrednost: ");
   scanf("%d", &vr);

   switch(vr)
   {
   case 10:
       rez = 95;
       break;
   case 9:
       rez = 85;
       break;
   case 8:
       rez = 75;
       break;
   case 7:
       rez = 65;
       break;
   case 6:
       rez = 55;
   default:
       rez = 45;
   }

   printf("Rezultat: %d\n", rez);

   return 0;
}

```

1. [x] 45 i 85
1. [ ] 55 i 85
    > Fali ``break`` naredba kod ``case 6`` naredbe, izvršiće se i ``default`` naredba zbog toga.
1. [ ] 45 i 95
    > 45 je tačno, ali 95 se neće ispisati, jer bi to bilo za slučaj da je uneta vrednost 10.
1. [ ] 45 i 45
    > Prvo 45 je tačno, ali u slučaju vrednosti 9, neće se dobiti rezultat 45, zbog postojanja break naredbi.

## Kako bi glasila naredba u programskom jeziku C "dok je vrednost a veća od 0 i vrednost suma je manja od 50"?

1. [x] ``while (a > 0 && suma < 50)``
    > while -> "dok", a > 0 -> "vrednost a veća od 0", && -> logičko "I", suma < 50 -> "suma je manja od 50"
1. [ ] ``if (a > 0 && suma < 50)``
    > Iako je sintaksno tačno, ne zadovoljava rečenicu jer ona ukazuje na potrebno ponavljanje u naredbi.
1. [ ] ``for (a = 0; a > 0 || suma < 50; a++)``
    > Ova naredba nije dobra iz više razloga. Prvi je zato što a počinje od 0, što znači da odmah ne bi bila tačna i ciklus se ne bi nijednom izvršio, da je ostatak napisan kako treba. Drugi problem je što je napisano logičko "ILI" umesto "I" u izrazu.
1. [ ] ``switch (a > 0 && suma < 50)``
    > Sintaksno nije tačno, izraz u switch naredbi mora biti konstantan. Switch takođe nije naredba ciklusa, nego selekcije.

## Koji izraz je potrebno da do-while naredba sadrži kako bi korisnik morao isključivo da unese neparan broj deljiv sa 7?

```c
#include <stdio.h>

int main()
{
   int broj;

   do
   {
      printf("Unesite broj: ");
      scanf("%d", &broj);
   } while(<izraz>);

    return 0;
}
```

1. [x] ``broj % 2 == 0 || broj % 7 != 0``
1. [ ] ``broj % 2 == 0 && broj % 7 != 0``
    > Ovaj izraz će pustiti korisnika za svaki neparan broj koji nije deljiv sa 7 (3, 5, 9 itd.), što ne bi smelo da se desi.
1. [ ] ``broj % 2 != 0 && broj % 7 == 0``
    > Ovaj izraz će vratiti korisnika za brojeve 14, 28 itd, odnosno parne deljive sa 7, ali će pustiti za 7 i 21 itd, odnosno neparne deljive sa 7, jer će u tom slučaju izraz biti logički netačan.
1. [ ] ``broj % 2 != 0 || broj % 7 != 0``
    > Ovaj izraz će pustiti korisnika ukoliko je broj paran i deljiv sa 7, što nije ono što je traženo.
