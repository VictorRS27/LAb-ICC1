#include <stdio.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int main()
{
    long long int Px = 0, Py = 0, Pl = 0, Pa = 0, Sx = 0, Sy = 0, Sl = 0, Sa = 0;
    long long int Ix = 0, Iy = 0, Il = 0, Ia = 0;

    scanf(" %lli %lli %lli %lli", &Px, &Py, &Pl, &Pa);
    scanf(" %lli %lli %lli %lli", &Sx, &Sy, &Sl, &Sa);


    //verificar miss
    if (Py+Pa < Sy || Sy+Sa < Py || Px+Pl < Sx || Sx+Sl < Px)
    {
        printf("MISS");
        exit(0);
    }

    //config y e altura
    if (Py+Pa>=Sy && Py<=Sy)
    {
        Ia=MIN(Py+Pa, Sy+Sa)-Sy;
        Iy=Sy;
    }
    if (Sy+Sa>Py && Sy<Py)
    {
        Ia=MIN(Py+Pa, Sy+Sa)-Py;
        Iy=Py;
    }

    //config do x e Largura
    if (Px+Pl>=Sx && Px<=Sx)
    {
        Il=MIN(Px+Pl, Sx+Sl)-Sx;
        Ix=Sx;
    }
    if (Sx+Sl>Px && Sx<Px)
    {
        Il=MIN(Px+Pl, Sx+Sl)-Px;
        Ix=Px;
    }

    printf("HIT: %lld %lld %lld %lld", Ix, Iy, Il, Ia);

    return 0;
}