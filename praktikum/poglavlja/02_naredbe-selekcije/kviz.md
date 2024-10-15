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

## Koju vrednost će imati promenljiva rez na kraju programa?

```c
#include <stdio.h>

int main()
{
    int a = 2, b = 4, rez;

    rez = a != 0 ? b : a;

    return 0;
}
```

1. [x] 4
    > Pošto je ``a`` različito od 0 (ima vrednost 2), onda će se uzeti vrednost nakon ? i pre :, a to je vrednost promenljive b (4).
1. [ ] 2
1. [ ] 6
1. [ ] 8
