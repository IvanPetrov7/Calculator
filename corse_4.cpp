#include <windows.h>
#include <string.h>
#include "graphics.h"
#include <math.h>
#include <stdlib.h>

struct button {
   int x, y, w, h, num;   
   char keyboard;
   //kol = 0 - �� ������� �� ���������� �������� ��������
   //kol = 1 - ����� ����������� � ����� ��������� ��������� 
   // kol = 2 - ����� ����������� � ����� ���������� ���������� 
   //kol = 3 - �������� =
};

double a=0, b=0, c=0; 
double prom=0;
int operation=-1, flag_input=0, flag15=0, flag18=0, flag_mr=0, flag_equal=0, flag_sqrt=0, flag_m=0; // flag_input �������� ���� �� ������� ����� �����
double memory=0, km=0;
int k1=0, k2=0, k3=0; //���������� ������ � ������� ����� ����� a, b � c
int wx=800, wy=600; 
button bt[28]={{268,448,84,28,0,'0'},{268,408,34,28,1,'1'},{319,408,33,28,2,'2'},
                     {370,408,33,28,3,'3'}, {268,370,34,28,4,'4'}, {319,370,33,28,5,'5'},
                     {370,370,33,28,6,'6'}, {268,331,34,28,7,'7'}, {319,331,33,28,8,'8'}, 
                     {370,331,33,28,9,'9'}, {420,370,34,28,0,'*'}, {420,311,34,28,0,'/'}, 
                     {420,448,34,28,0,'+'}, {420,408,34,28,0,'-'}, {370,448,33,28,0,'.'}, 
                     {471,370,34,28}, {471,331,34,28}, {471,293,34,29}, {420,293,34,29}, 
                     {370,293,33,28}, {319,293,33,29,0,KEY_DELETE}, {268,293,34,29,0,KEY_BACKSPACE},
                     {471,255,34,28}, {420,255,34,28}, {370,255,33,28}, {319,255,33,28},
                     {268,255,34,28}, {471,408,33,68,0,KEY_ENTER}};

void init(); // ������������� ����������
void function_application(); // ���������� ��������
void operation_zeroing(); // ��������� a, b, c � operation
void operation_zeroing_b_c(); // ��������� b, c 
void text_out(double an); // ����� �� ������� ������������
void text_out_m ();//����� �� ������� ������������ ���������� ������ "M"
int input(); //���� ��������
double analyse(); // ���� �� ����� ������ ��������, ����� ������������� ���� �����
void operation_1x(); // ���������� �������� 1/x
void operation_2x(); // ���������� �������� 1/x

int main(){
   int aa, i;
   init();
   while(1){
      flag_input=0;//���� �� ������� �����
      aa=analyse();
      switch(aa){
           case 10://*
               if (operation==0 || operation==-1){
               operation=aa;
               if (flag_input==1 || flag_mr==1  || flag_sqrt==1) {
                  a=c;
                  k1=k3;    
                  flag_mr=0;
               }
               else {
                  b=c;
                  k2=k3;
                  }
               }
              else {
                 if (flag_input==1 || flag_mr==1 || flag_sqrt==1) {
                    switch(operation){
                       case 10:
                          a=a*c;
                          text_out (a);
                          break;
                       case 11:
                          a=a/c;
                          text_out (a);
                          operation=10;
                          break;
                       case 12:
                          a+=c;
                          text_out(a);
                          operation=10;
                          break;
                       case 13:
                          a-=c;
                          text_out(a);
                          operation=10;
                          break;
                       }
                    }
               else break;
                 }
              operation_zeroing_b_c();
              break;              
           case 11:// delenie
              if (operation==0 || operation==-1){
               operation=aa;
               if (flag_input==1 || flag_mr==1 || flag_sqrt==1) {
                  a=c;
                  k1=k3;    
                  flag_mr=0;
               }
               else {
                  b=c;
                  k2=k3;
                  }
               }
              else {
                 if (flag_input==1 || flag_mr==1 || flag_sqrt==1) {
                    switch(operation){
                       case 10:
                          a=a*c;
                          text_out (a);
                          operation=11;
                          break;
                       case 11:
                          a=a/c;
                          text_out (a);
                          break;
                       case 12:
                          a+=c;
                          text_out(a);
                          operation=11;
                          break;
                       case 13:
                          a-=c;
                          text_out(a);
                          operation=11;
                          break;
                       }
                    }
               else break;
                 }
              operation_zeroing_b_c();
              break;              
           case 12://+
              if (operation==0 || operation==-1){
               operation=aa;
               if (flag_input==1 || flag_mr==1 || flag_sqrt==1) {
                  a=c;
                  k1=k3;
                  flag_mr=0;
               }
               else {
                  b=c;
                  k2=k3;
                 }
               }
              else {
                 if (flag_input==1 || flag_mr==1 || flag_sqrt==1) {
                    switch(operation){
                       case 10:
                          a=a*c;
                          text_out (a);
                          operation=12;
                          break;
                       case 11:
                          a=a/c;
                          text_out (a);
                          operation=12;
                          break;
                       case 12:
                          a+=c;
                          text_out(a);
                          break;
                       case 13:
                          a-=c;
                          text_out(a);
                          operation=12;
                          break;
                       }
                    }
               else break;
                 }
              operation_zeroing_b_c();
              break;
           case 13://-
              if (operation==0 || operation==-1){
               operation=aa;
               if (flag_input==1 || flag_mr==1 || flag_sqrt==1) {
                  a=c;
                  k1=k3;    
                  flag_mr=0;
               }
               else {
                  b=c;
                  k2=k3;
                  }
               }
              else {
                 if (flag_input==1 || flag_mr==1 || flag_sqrt==1) {
                    switch(operation){
                       case 10:
                          a=a*c;
                          text_out (a);
                          operation=13;
                          break;
                       case 11:
                          a=a/c;
                          text_out (a);
                          operation=13;
                          break;
                       case 12:
                          a+=c;
                          text_out(a);
                          operation=13;
                          break;
                       case 13:
                          a-=c;
                          text_out(a);
                          break;
                    }
                 }
               else break;
                 }
              operation_zeroing_b_c();
              break;
           case 15://1/x
              if (operation==0){
                 if (flag15==0){
                  if (flag_input==0){
                     if (flag_equal==1 && a!=0){
                        a=1/a;
                        text_out(a);
                        break;
                     }
                     else{
                     text_out(0);
                     break;
                  } 
               }
                 else{
                     operation_1x();
                    break;
                 }
               }
               else {
                  if (flag_input==0){
                     a=1/a;
                     text_out(a);
                     flag15=1;
                     break;
                  } 
                 else{
                     operation_1x();
                    break;
                   }
                 }
              }
              else {
                 if (flag15==0){
                    if (flag_input==0){
                       b=a;
                       k2=k1;
                       b=1/b;
                       text_out(b);
                       flag15=1;
                       break;
                    }
                    else {
                       operation_2x();
                       break;
                    }
              }
              else {
                 if (flag_input==0){
                       b=1/b;
                       text_out(b);
                       flag15=1;
                       break;
                    }
                    else {
                       operation_2x();
                       break;
                    }
              }
           }
           case 16://%
            switch(operation){
               case 0:
                  printf("0"); break;
               case 10:
               case 11:
                  b=0.01*c;
                  text_out(b); break;
               case 12:
               case 13:
                  b=a*0.01*c;
                  text_out(b); break;
               }
                  if (operation!=0){
                     k2=k3;
                     c=0;
                     k3=0;
                  }
               break;
           case 17://sqrt
            if (flag_input==1){
               if (operation==0){
                  c=sqrt(c);
                  text_out(c);
                  flag_sqrt=1;
                  }
               else {
                  c=sqrt(c);
                  text_out(c);
                  flag_sqrt=1;
                  }
               break;
            }
            else{
               a=sqrt(a);
               text_out(a);
               break;
            }
           case 18://+/-
              if (flag18==0){
                 if (operation==0){
                    a=-1*c;
                    k1=k3;
                    text_out(a);
                    }
                 else {
                    b=-1*c;
                    k2=k3;
                    text_out(b);
                    }
               c=0;
               k3=0;
               break;  
              }
              else {
                 a=-1*prom;
                 text_out(prom);
                 break;
              }
           case 19://c
              operation_zeroing();
              text_out(c);
              flag_equal=0;
              flag_sqrt=0;
              break;
           case 20://ce
              if (operation==0){
                 a=0;
                 k1=0;
                 flag_equal=0;
                 flag_sqrt=0;
                 }
              else {
                 b=0;
                 k2=0;
                 }
                 k3=0;
                 c=0;
                 text_out(c);
                 break;
           case 21://<-
              if (k3==0){
                 c=c/10;
                 c=trunc(c);
                 text_out(c);
                 break;
              }
              else {
                 int ten=10;
                 for (i=1; i<k3-1; i++) ten=ten*10;
                 c=c*ten;
                 c=trunc(c);
                 for (i=1; i<k3-1; i++) c=c*0.1;
                 text_out(c);
                 break;
              }
             case 22: //m-
              if (operation==0 || operation==-1) {
                 if (flag_input) {
                    memory-=c;
                    flag_mr=1;
                    flag_m=1;
                    text_out_m();
                 }
                    else {
                       memory-=a;
                      flag_m=1;
                      text_out_m();
                    }
                 break;
              }
               else {
                 if (flag_input){
                    memory-=c;
                    flag_mr=1;
                    flag_m=1;
                    text_out_m();
                 }
                    else {
                       memory-=b;
                       flag_m=1;
                       text_out_m();
                    }
                 break;
               }
           case 23://m+
              if (operation==0 || operation==-1) {
                 if (flag_input) {
                    memory+=c;
                    flag_mr=1;
                    flag_m=1;
                    text_out_m();
                 }
                    else {
                       memory+=a;
                       flag_m=1;
                       text_out_m();
                    }
                 break;
              }
               else {
                 if (flag_input){
                    memory+=c;
                    flag_mr=1;
                    flag_m=1;
                    text_out_m();
                 }
                    else {
                       memory+=b;
                       flag_m=1;
                       text_out_m();
                    }
                 break;
               }
           case 24://ms
               if (operation==0 || operation==-1) {
                 if (flag_input) {
                    memory=c;
                    flag_mr=1;
                    flag_m=1;
                    text_out_m();
                 }
                    else {
                       memory=a;
                       flag_m=1;
                       text_out_m();
                    }
                  break;
              }
               else {
                 if (flag_input){
                    memory=c;
                    flag_mr=1;
                    flag_m=1;
                    text_out_m();
                 }
                    else {
                       memory=b;
                       flag_m=1;
                       text_out_m();
                    }
                 break;
               }
           case 25://mr
              c=memory;
              flag_mr=1;
              text_out (c);
              break;
           case 26://mc
              memory=0;
              flag_m=0;
              text_out_m();
              break;
           case 27://=
              if (flag_input==1 || flag_mr==1 || flag_sqrt==1){
                 b=c;
                 k2=k3;
                 function_application();
              }
              else {
                 b=a;
                 k2=k1;
                 function_application();
              }
               operation=0;
               flag_input=0;
               flag_mr=0;
               flag_equal=1;
               a=prom;
               b=0;
               c=0;
               text_out (a);
               break;
        }
     }
}

void function_application(){//���������� �������� ����� ������� =
               flag15=0;
               flag18=1;
               switch(operation){
                 case 10:
                    prom=a*b;
                    break;
                 case 11:
                    prom=a/b;
                    break;
                 case 12:
                    prom=a+b;
                    break;
                 case 13:
                    prom=a-b;
                    break;
            }
}

double analyse(){//���� �� ����� ������ ��������, ����� ������������� ���� �����
   int a1, flag=0, i, kol=1;
   double ost;
   while(kol<15){
      a1=input();
      if (a1>9 && a1!=14) {
         flag=0;
         kol=1;
         break;
         }
      if (flag_mr) {
         c=0;
         k3=0;
         flag_mr=0;
      }
      if (flag_sqrt){
         c=0;
         k3=0;
         flag_sqrt=0;
      }
      if (a1==14) {
         flag=1;
         flag_input=1;
         kol++;
      }
         else if (flag==0){
            c=c*10+bt[a1].num;
            kol++;
            flag_input=1;
            text_out(c);
         }
         else if (flag==1){
            flag_input=1;
            kol++;
            k3++;
            ost=bt[a1].num;
            for (i=1; i<=k3; i++) ost=ost*0.1;
            c+=ost;
            text_out(c);
         }
      }
      return a1;
   }

int input(){//���� ��������
  while(1){ 
     delay(100);
     int xx,yy, ccc, i, o;
     xx=mousex();
     yy=mousey();
     if (mousebuttons()){
        for (i=0; i<28; i++)
           if (xx>=bt[i].x && xx<=(bt[i].w+bt[i].x) && yy>=bt[i].y && yy<=(bt[i].y+bt[i].h)) o=i;
           return o;
        }
     
     else if (kbhit()){
        ccc=getch();
        for (i=0; i<28; i++){
           if (ccc==bt[i].keyboard) {
              o=i;
              }
           }
            return o;
         }
   }
}

void drawimage(int x, int y, IMAGE *m, IMAGE *p){ // ��������� ����������
  putimage(x,y,m,AND_PUT);
  putimage(x,y,p,OR_PUT);
}

 IMAGE *createmask(IMAGE *p){//����� ����� ���� ���������� 
  int ww=imagewidth(p);
  int hh=imageheight(p);
  IMAGE *m=createimage(ww,hh);
  int cc=imagegetpixel(p,0,0);
  for(int x=0;x<ww;++x)
    for(int y=0;y<hh;++y)
    { int d=imagegetpixel(p,x,y);
      if(cc==d)
      { imageputpixel(m,x,y,WHITE);
        imageputpixel(p,x,y,BLACK);
      }
      else
        imageputpixel(m,x,y,BLACK);
    }
  return m;
}

void init(){//������������� ����������
   IMAGE *calc, *n;
   initwindow (wx,wy);
   setbkcolor (WHITE);
   clearviewport();
   calc=loadBMP("interface_2.bmp");   // �������� ��������
   if (calc== NULL) exit (1);          // ������ ��� ��������
   n=createmask(calc);                // �������� �����   
   drawimage (0, 0, n, calc);
}

void text_out (double an){ // ����� �� ������� ������������
   char mas_out[18];
   setfillstyle (SOLID_FILL, WHITE);
   bar (273, 185, 499, 235);
   sprintf (mas_out, "%11g", an);
   setcolor(BLACK);
   setbkcolor(WHITE);
   settextjustify (RIGHT_TEXT, TOP_TEXT);
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
   outtextxy(500, 204, mas_out);
}

void text_out_m (){ //����� �� ������� ������������ ���������� ������ "M"
   if (flag_m){
      setcolor(BLACK);
      setbkcolor(WHITE);
      settextjustify (RIGHT_TEXT, TOP_TEXT);
      settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
      outtextxy(500, 160, "M");
   }
   else {
   setfillstyle (SOLID_FILL, WHITE);
   bar (450, 165, 499, 185);
   }
}

void operation_zeroing(){ // ��������� a, b, c � operation
   a=0;
   b=0;
   c=0;
   k1=0;
   k2=0;
   k3=0;
   operation=-1;
}

void operation_zeroing_b_c(){// ��������� b � c
   b=0;
   k2=0;
   c=0;
   k3=0;
}

void operation_1x(){// ���������� �������� 1/x
   a=c;
   k1=k3;
   a=1/a;
   text_out(prom);
   c=0;
   k3=0;
   flag15=1;
}

void operation_2x(){// ���������� �������� 1/x
  b=c;
  k2=k3;
  b=1/b;
  text_out(b);
  c=0;
  k3=0;
  flag15=1;
}