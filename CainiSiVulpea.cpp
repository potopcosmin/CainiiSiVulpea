#include<stdio.h>
#include<graphics.h>
#include<winbgim.h>
#include<iostream>
#include<conio.h>
#define cols 8
#define rows 8
using namespace std;
// Pot da edit  	
float l;//latura unuei celule
typedef struct tabla
{
    float x,y;//coordonate colt stanga sus pentru fiecare celula
    int valoare;//pentru a implementa cainii si vulpea
} grid[8][8];

void citesteMatriceTabla (grid tabla);

void deseneazaVulpe(grid tabla,int i,int j);

void deseneazaCaine(grid tabla,int i,int j);

void asociereGrafica(grid tabla);

void deseneazatabla(grid tabla);

void menu();

grid tabla;


int main()
{

    grid tabla;
    menu();


    getch();
    closegraph();
}
void citesteMatriceTabla (grid tabla)//pentru teste ,urmeaza sa fie initilaizata din fisier
{
    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
            tabla[i][j].valoare = 0;
    tabla[0][3].valoare=2;//vulpea
    tabla[7][0].valoare=1;//caine din stanga
    tabla[7][2].valoare=1;//cainele al2-lea
    tabla[7][4].valoare=1;//cainele al3-lea
    tabla[7][6].valoare=1;//cainele al4-lea
}
void deseneazaVulpe(grid tabla,int i,int j)
{
    setcolor(RED);
    circle(tabla[i][j].x+l/2,tabla[i][j].y+l/2,l/6);
    setfillstyle(SOLID_FILL,RED);
    floodfill(tabla[i][j].x+l/2,tabla[i][j].y+l/2,RED);
}
void deseneazaCaine(grid tabla,int i,int j)
{

    setcolor(GREEN);
    circle(tabla[i][j].x+l/2,tabla[i][j].y+l/2,l/6);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(tabla[i][j].x+l/2,tabla[i][j].y+l/2,GREEN);

}
void asociereGrafica(grid tabla) //pentru fiecare patrat din tabla ,indicam coordonatele coltului stanga sus
{
    l=(float)getmaxx()/cols;//latura unui patratel
    //coordonatele coltului stanga sus al tablei
    tabla[0][0].x=0;
    tabla[0][0].y=0;
    //coordonatele coltului stanga sus  pentru fiecare patrat
    int i,j;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
        {
            tabla[i][j].x=tabla[0][0].x+j*l;
            tabla[i][j].y=tabla[0][0].y+i*l;
        }
}
void deseneazatabla(grid tabla)
{
    int i,j;

    asociereGrafica(tabla);
    for (i = 0; i < cols; i++)
    {
        for ( j = 0; j < rows; j++)
        {
            if((i+j)%2==0)
            {
                setcolor(BLACK);
                rectangle(tabla[i][j].x,tabla[i][j].y,tabla[i][j].x+l,tabla[i][j].y+l);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(tabla[i][j].x+1,tabla[i][j].y+1,BLACK);
            }
            else
            {
                setcolor(WHITE);
                rectangle(tabla[i][j].x,tabla[i][j].y,tabla[i][j].x+l,tabla[i][j].y+l);
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(tabla[i][j].x+1,tabla[i][j].y+1,WHITE);
            }
            if(tabla[i][j].valoare==2)
                deseneazaVulpe(tabla,i,j);
            else if(tabla[i][j].valoare==1)
                deseneazaCaine(tabla,i,j);
        }

    }
}

void menu()
{
    int midx,x,y;

    initwindow(720, 720);
    setbkcolor(CYAN);
    midx = getmaxx() / 2;

    settextstyle(10, HORIZ_DIR, 7);      //fontul si marimea tipul orizontal
    settextjustify(1,1);            //centrat
    outtextxy(midx, 150, "CAINII SI VULPEA");        // x si y unde se va afisa stringul "..."

    settextstyle(9, HORIZ_DIR, 6);
    setbkcolor(RED);
    outtextxy(midx, 300, "START");

    settextstyle(9, HORIZ_DIR, 6);
    setbkcolor(RED);
    outtextxy(midx, 400, " EXIT ");

    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
       {
            x=mousex();
            y=mousey();
            clearmouseclick(WM_LBUTTONDOWN);
              //getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x >240 && x<467 && y>258 && y<312)
            {
                cleardevice();
                citesteMatriceTabla(tabla);
                deseneazatabla(  tabla);
            }
            if(x >240 && x<467 && y>358 && y<412)
                exit(1);
        }
    }
}
