#include <LiquidCrystal.h>
#include <Keypad.h>
const byte filas = 4; 
const byte colunas = 4; 
char tecla[filas][colunas] = {
  {'1','4','7','a'},
  {'2','5','8','0'},
  {'3','6','9','='},
  {'+','-','*','/'}
};
byte pinFilas[filas] = {9, 8, 7, 6}; 
byte pinColunas[colunas] = {13, 12, 11, 10}; 
Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColunas, filas, colunas );
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 
///////////////////////////////////////
String x,y;
byte z=0;
char tipo;
long dado1,dado2,rpt1,pontos=0;
double dado3,dado4,rpt2;
char key;
bool certo=true;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop(){
  millis();
  calculadora();
}

void calculadora(){
  char key = keypad.getKey();
  if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
    
      if(z==0){
        lcd.print(key);
        x+=key;
        dado1=x.toInt();
      }
      
      else if(z==1){
        lcd.print(key);
        y+=key;
        dado2=y.toInt();
      }
   
  }

  if(key=='a'){

      y="";
      x="";
      dado1=0;
      dado2=0;
      dado3=0;
      dado4=0;
      z=0;
      rpt1=0;
      rpt2=0;
      lcd.clear();
  }
  else if(key=='='&&tipo=='+'){
    z++;
    lcd.setCursor(0,2);
    rpt1=dado1+dado2;
    lcd.print("ANS=");
    lcd.print(rpt1);
  }

  else if(key=='='&&tipo=='-'){
    z++;
    lcd.setCursor(0,2);
    rpt1=dado1-dado2;
    lcd.print("ANS=");
    lcd.print(rpt1);
  }
  else if(key=='='&&tipo=='*'){
    z++;
    lcd.setCursor(0,2);
    rpt1=dado1*dado2;
    lcd.print("ANS=");
    lcd.print(rpt1);
  }
  else if(key=='='&&tipo=='/'){
    z++;
    lcd.setCursor(0,2);
    dado3=dado1;
    dado4=dado2;
    lcd.print("ANS=");
    rpt2=(dado3/dado4);
    lcd.print(rpt2);
  }

  
  else if((key=='+'||key=='-'||key=='*'||key=='/')&&(z==0)){
    z++;
    tipo=key;
    lcd.print(tipo);
  }
}
