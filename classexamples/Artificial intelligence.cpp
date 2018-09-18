//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Inflation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma hdrstop
#include <condefs.h>
//---------------------------------------------------------------------------
#pragma argsused
#pragma hdrstop
#include <condefs.h>
#include <math.h>
#include <conio.h>
#include <iostream.h>
#include <stdio.H>
#include <string.h>
#include<fstream.h>
/////////////////////////////////////////////////////////////////////////////////////////
#pragma argsused
#define LINEAR_RATE 0.05
#define INPUT_NEURONS 6
#define HIDDEN_NEURONS 6
#define OUTPUT_NEURONS 5
#define MAX_ITERATIONS 50000
/* Вага */
/* Вхід прихованих осередків (із зсувом) */
double wih[INPUT_NEURONS+1][HIDDEN_NEURONS];
/* Вхід вихідних осередків (із зсувом) */
double who[HIDDEN_NEURONS+1][OUTPUT_NEURONS];
/* Активатори */
double inputs[INPUT_NEURONS];
double hidden[HIDDEN_NEURONS];
double target[OUTPUT_NEURONS];
double actual[OUTPUT_NEURONS];
/* Помилки */
double erro[OUTPUT_NEURONS];
double errh[HIDDEN_NEURONS];
#define LEARN_RATE        0.19   /*  Коефіцієнт навчання */
#define RAND_WEIGHT      (   ((float) rand()   /   (float)RAND_MAX)   -  1)
#define getSRandO ((float)rand()   /   (float)RAND_MAX)
#define getRand(x) (int)((x) * getSRand())
#define sqr(x)        ((x) * (x))
typedef struct   {
double podie_1;
double podie_2;
double podie_3;
double podie_4;
double podie_5;
double podie_6;

double out[OUTPUT_NEURONS];
}  ELEMENT;
#define MAX_SAMPLES   42
/* база  знань */
ELEMENT samples[MAX_SAMPLES]   =   {
{0.0, 10.0, 0.0, 10.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{0.0, 9.0, 0.0, 9.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{0.0, 8.0, 0.0, 8.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{1.0, 10.0, 1.0, 10.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{1.0, 9.0, 1.0, 9.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{1.0, 8.0, 1.0, 8.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{2.0, 10.0, 2.0, 10.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{2.0, 9.0, 2.0, 9.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },
{2.0, 8.0, 2.0, 8.0, 1.0, 1.0,    {1.0, 0.0, 0.0, 0.0, 0.0}   },

{3.0, 8.0, 3.0, 8.0, 1.0, 0.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{4.0, 8.0, 4.0, 8.0, 1.0, 0.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{3.0, 7.0, 3.0, 7.0, 1.0, 0.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{3.0, 6.0, 3.0, 6.0, 0.0, 1.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{4.0, 7.0, 4.0, 7.0, 1.0, 0.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{4.0, 6.0, 4.0, 6.0, 0.0, 1.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{5.0, 7.0, 5.0, 7.0, 0.0, 1.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{5.0, 7.0, 5.0, 7.0, 1.0, 1.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },

{0.0, 10.0, 10.0, 10.0, 1.0, 1.0,    {0.0, 1.0, 0.0, 0.0, 0.0}   },
{7.0, 7.0, 7.0, 7.0, 1.0, 0.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{6.0, 6.0, 6.0, 6.0, 1.0, 0.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{5.0, 5.0, 5.0, 5.0, 1.0, 0.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{5.0, 4.0, 5.0, 4.0, 0.0, 1.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{6.0, 5.0, 6.0, 5.0, 1.0, 0.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{6.0, 4.0, 6.0, 4.0, 0.0, 1.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{7.0, 5.0, 7.0, 5.0, 1.0, 0.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{8.0, 6.0, 8.0, 6.0, 1.0, 0.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },

{10.0, 10.0, 10.0, 10.0, 1.0, 1.0,    {0.0, 0.0, 1.0, 0.0, 0.0}   },
{9.0, 9.0, 9.0, 9.0, 1.0, 1.0,    {0.0, 0.0, 0.0, 1.0, 0.0}   },
{8.0, 4.0, 8.0, 4.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 1.0, 0.0}   },
{7.0, 3.0, 7.0, 3.0, 0.0, 1.0,    {0.0, 0.0, 0.0, 1.0, 0.0}   },
{7.0, 2.0, 7.0, 2.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 1.0, 0.0}   },
{8.0, 3.0, 8.0, 3.0, 0.0, 1.0,    {0.0, 0.0, 0.0, 1.0, 0.0}   },
{8.0, 2.0, 8.0, 2.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 1.0, 0.0}   },
{9.0, 3.0, 9.0, 3.0, 0.0, 1.0,    {0.0, 0.0, 0.0, 1.0, 0.0}   },

{10.0, 3.0, 10.0, 3.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },
{10.0, 2.0, 10.0, 2.0, 0.0, 1.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },
{9.0, 1.0, 9.0, 1.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },
{9.0, 0.0, 9.0, 0.0, 0.0, 1.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },
{10.0, 1.0, 10.0, 1.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },
{10.0, 0.0, 10.0, 0.0, 0.0, 1.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },
{0.0, 0.0, 0.0, 0.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },
{1.0, 1.0, 1.0, 1.0, 1.0, 0.0,    {0.0, 0.0, 0.0, 0.0, 1.0}   },

};

char *strings[5]={"Закупати матеріальні цінності, ідеальний постачальник",
"Закупати матеріальні цінності, гарний постачальник",
"Можлива закупівля матеріальних цінностей, задовільний постачальник",
"Не рекомендована закупівля матеріальних цінностей, сумнівний постачальник",
"Не закупати матеріальні цінності, поганий постачальник"};
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
void assignRandomWeights(  void  );
double linear( double val );
double linearDerivative( double val );
void feedForward( );
void backPropagate( void );
int action( double *vector ) ;
double err, b;
int  i,   sample=0,   iterations=0;
int  sum =   0;
ofstream outfile("result.dat");
//* Ініціалізувати генератор випадкових чисел
srand( time(NULL) );
assignRandomWeights();
//* Навчити мережу
while (1) {
if (++sample == MAX_SAMPLES) sample = 0;
inputs[0]   =    samples[sample].podie_1;
inputs[1]   =    samples[sample].podie_2;
inputs[2]   =    samples[sample].podie_3;
inputs[3]   =    samples[sample].podie_4;
inputs[4]   =    samples[sample].podie_5;
inputs[5]   =    samples[sample].podie_6;

 target[0]   =    samples[sample].out[0];
 target[1]   =    samples[sample].out[1];
 target[2]   =    samples[sample].out[2];
 target[3]   =    samples[sample].out[3];
 target[4]   =    samples[sample].out[4];
feedForward();
err = 0.0;
for (i = 0 ; i < OUTPUT_NEURONS ; i++)
{
err += sqr( (samples[sample].out[i] - actual[i]) );
} err = 0.5 * err;
outfile<<err<<endl;  printf("ERROR  =  %g\n",   err);
if (iterations++ > MAX_ITERATIONS) {
            getch();
            break;
        }
backPropagate();
}
//* Перевірити мережу
for   (i   =   0   ;   i   <  MAX_SAMPLES   ; i++)
{inputs[0]   = samples[i].podie_1;
inputs[1]   = samples[i].podie_2;
inputs[2]   = samples[i].podie_3;
inputs[3]   = samples[i].podie_4;
inputs[4]   = samples[i].podie_5;
inputs[5]   = samples[i].podie_6;

target[0]   = samples[i].out[0] ;
target[1]   = samples[i].out[1];
target[2]   = samples[i].out[2];
target[3]   = samples[i].out[3];
target[4]   = samples[i].out[4];
feedForward();
if (action(actual) == action(target)) {
	sum++;
}
}
printf("Network is %g%% correct\n",
b = ((float)sum / (float)MAX_SAMPLES) * 100.0);
//Label15->Caption = b;
//* Виконання тестів *
//* Загальний капітал | Коеф. поточної ліквідності | Довгострокова заборгованість | Довгострокова заборгованість\акціонерний капітал | Покриття відсотків |Грошовий потік\ Довгострокова заборгованість

inputs[0] = TrackBar1->Position / 10;
inputs[1] = TrackBar2->Position / 10;
inputs[2] = TrackBar3->Position / 10;
inputs[3] = TrackBar4->Position / 10;
inputs[4] = TrackBar5->Position;
inputs[5] = TrackBar6->Position;

feedForward();
Edit5->Text = strings[action(actual)];
outfile.close();
getch();

    TStringList* List;
    int ListCount;
    List = new TStringList;
    List->LoadFromFile("result.dat");
    ListCount = List->Count;

    Chart1->Series[0]->Clear();
	for (int i = 0; i < ListCount; i = i + MAX_SAMPLES)
    {
        Chart1->Series[0]->Add(StrToFloat(StringReplace(List->Strings[i], ".", ",",
        TReplaceFlags() << rfReplaceAll)),i,clRed);
    }
}
//---------------------------------------------------------------------------
void assignRandomWeights(  void  )
{int  hid,   inp,   out;
for (inp =0 ; inp < INPUT_NEURONS+1 ; inp++)
{ for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++)
 { wih[inp][hid] = RAND_WEIGHT; }}
for (hid = 0 ; hid < HIDDEN_NEURONS+1 ; hid++)
{ for (out = 0 ; out < OUTPUT_NEURONS ; out++){
 who [hid] [out] = RAND_WEIGHT;}}
 }
 /////////////////////////////////////////////////////////////////////////////////
double linear( double val ) {
        return LINEAR_RATE * val;
}
///////////////////////////////////////////////////////////////////////////////////
double linearDerivative( double val ) {
        return LINEAR_RATE;
}
 /////////////////////////////////////////////////////////////////////////////////
void feedForward( )
{int inp, hid, out;
double sum;
/* Обчислити вхід в прихований шар */
for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++)
{sum = 0.0;
for (inp = 0 ; inp < INPUT_NEURONS ; inp++)
{ sum += inputs[inp] * wih[inp][hid];    }/* Додати зсув */
sum += wih[INPUT_NEURONS][hid];
hidden[hid] = linear( sum );
}
/* Обчислити вхід у вихідний шар */
for (out = 0 ; out < OUTPUT_NEURONS ; out++){
sum = 0.0;
for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++){
 sum += hidden[hid] * who[hid][out];
  }
/* Додати зсув */
sum += who[HIDDEN_NEURONS][out];
 actual[out] = linear( sum );
 }}
//////////////////////////////////////////////////////////////////////////////////
void backPropagate( void )
 {
 int inp, hid, out;
//* Обчислити помилку вихідного шару (крок 3 для вихідних осередків) *
for (out = 0 ; out < OUTPUT_NEURONS ; out++)
{ erro[out]= (target[out]-actual[out])*
linearDerivative( actual[out]);}
//* Обчислити помилку прихованого шару (крок 3 для прихованого шару) *
for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++)
{errh[hid] = 0.0;
for (out = 0 ; out < OUTPUT_NEURONS ; out++)
{ errh[hid] += erro[out] * who[hid][out];}
errh[hid] *= linearDerivative( hidden[hid] );
}
//* Відновити вагу для вихідного шару (крок 4 для вихідних осередків) *
for (out = 0 ; out < OUTPUT_NEURONS ; out++)
{
for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++)
{who[hid][out] += (LEARN_RATE * erro[out] * hidden[hid]);
 }
//* Відновити зсув *

who[HIDDEN_NEURONS][out] += (LEARN_RATE * erro[out]);}
//* Відновити вагу для прихованого шару (крок 4 для прихованого шару) *
for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++)
{ for (inp = 0 ; inp < INPUT_NEURONS ; inp++)
{
wih[inp][hid] += (LEARN_RATE * errh[hid] * inputs[inp]);}
//* Відновити зсув *
wih[INPUT_NEURONS][hid] += (LEARN_RATE * errh[hid]);}}
//////////////////////////////////////////////////////////////////
int action( double *vector )
{int index, sel;
double max;
sel = 0;
max = vector[sel];
for (index = 1 ; index < OUTPUT_NEURONS ; index++)
 {
  if (vector[index] > max)
 {   max = vector[index]; sel = index; }}
return (sel);}
//--------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender) {
        Label8 -> Caption = TrackBar1 -> Position;
}
//--------------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender) {
        Label9 -> Caption = TrackBar2 -> Position;
}
//--------------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender) {
        Label10 -> Caption = TrackBar3 -> Position;
}
//--------------------------------------------------------------------
void __fastcall TForm1::TrackBar4Change(TObject *Sender) {
        Label11 -> Caption = TrackBar4 -> Position;
}
//--------------------------------------------------------------------
void __fastcall TForm1::TrackBar5Change(TObject *Sender) {
    if (TrackBar5 -> Position == 0) {
		Label12 -> Caption = "Відсутня";
	}
	else if  (TrackBar5 -> Position == 1) {
		Label12 -> Caption = "Присутня";
	}
}
//--------------------------------------------------------------------
void __fastcall TForm1::TrackBar6Change(TObject *Sender) {
    if (TrackBar6 -> Position == 0) {
		Label13 -> Caption = "Відсутня";
	}
	else if  (TrackBar6 -> Position == 1) {
		Label13 -> Caption = "Присутня";
	}
}
