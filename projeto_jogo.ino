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
  //calculadora();
  jogo();
}
void jogo(){
  lcd.clear();
  lcd.print("escolha um nivel:");
  lcd.setCursor(0,2);
  lcd.print("1 2 3 4 5");
  
  while(key!='1'&& key!='2'&& key!='3'&& key!='4'&& key!='5'){
    key = keypad.getKey();
  }
  if(key=='1'){
    level_1();
  }
  else if(key=='2'){
    level_2();
  }
  else if(key=='3'){
    level_3();
  }
  else if(key=='4'){
    level_4();
  }
  else if(key=='5'){
    level_5();
  }
}

void level_1(){
    lcd.clear();
    bool sair=false;
    randomSeed(millis());
  while(certo==true){
      long numero1,numero2;
      int c;
      int r_user=0;
      c=random(1,3);
    if(c==1){
          numero1=random(1,100);
          numero2=random(1,100);
          int r_sys=numero1+numero2;
          lcd.setCursor(0,0);
          lcd.print(numero1+String('+')+numero2+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(numero1+String('+')+numero2+String('='));
                x="";
                r_user=0;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("voce acertou"));
              lcd.setCursor(14,2);
              pontos+=5;
              lcd.print(String("p")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-1;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("p")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
    }
  if(c==2){
          numero1=random(1,100);
          int negativo=numero1;
          numero2=random(1,negativo);
            int r_sys=numero1-numero2;
          lcd.setCursor(0,0);
          lcd.print(numero1+String('-')+numero2+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(numero1+String('-')+numero2+String('='));
                x="";
                r_user=0;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("voce acertou"));
              lcd.setCursor(14,2);
              pontos+=5;
              lcd.print(String("p")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-1;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("p")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
      }
  }
}

void level_2(){
    lcd.clear();
    bool sair=false;
    randomSeed(millis());
  while(certo==true){
      long numero1,numero2,numero3;
      int c;
      int r_user=0;
      c=random(1,3);
    if(c==1){
          numero1=random(1,100);
          numero2=random(1,100);
          int negativo=numero1+numero2;
          if(negativo>99){
            negativo=100;
          }
          numero3=random(1,negativo);
          int r_sys=numero1+numero2-numero3;
          lcd.setCursor(0,0);
          lcd.print(numero1+String('+')+numero2+String("-")+numero3+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(numero1+String('+')+numero2+String("-")+numero3+String('='));
                x="";
                r_user=0;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=10;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
              lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-5;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
    }
  if(c==2){
          numero1=random(1,100);
          int negativo=numero1;
          numero2=random(1,negativo);
        numero3=random(1,100);
    
          int r_sys=numero1-numero2+numero3;
          lcd.setCursor(0,0);
          lcd.print(numero1+String('-')+numero2+String("+")+numero3+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(numero1+String('-')+numero2+String("+")+numero3+String('='));
                x="";
                r_user=0;
              }
                
              if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
                lcd.print(key);
                x+=key;
                r_user=x.toInt();
              }
             }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=10;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              pontos+=-5;
              if(pontos<0){
              pontos=0;
              }
              lcd.setCursor(12,2);
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
      }
  }
}
void level_3(){
    lcd.clear();
    bool sair=false;
    randomSeed(millis());
  while(certo==true){
      float numero1,numero2;
      int c;
      int r_user=0;
      c=random(1,3);
    if(c==1){
          numero1=random(1,99);
          numero2=random(1,99);
          int negativo=numero1+numero2;
          if(negativo>99){
            negativo=99;
          }
          int r_sys=numero1*numero2;
          lcd.setCursor(0,0);
          lcd.print(int(numero1)+String('*')+int(numero2)+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=15;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
              lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-15;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
    }
  if(c==2){
          numero1=random(1,100);
          int negativo=numero1;
          while(true){
            numero2=random(1,100);
            float numero_float=numero1/numero2;
            int numero_int=numero_float;
      if(numero_int==numero_float){
              break;
        }}
    
          int r_sys=numero1/numero2;
          lcd.setCursor(0,0);
          lcd.print(int(numero1)+String('/')+int(numero2)+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(int(numero1)+String('/')+int(numero2)+String('='));
                x="";
                r_user=0;
              }
                
              if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
                lcd.print(key);
                x+=key;
                r_user=x.toInt();
              }
             }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=15;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              pontos+=-15;
              if(pontos<0){
              pontos=0;
              }
              lcd.setCursor(12,2);
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
      }
  }
}
void level_4(){
  lcd.clear();
  bool sair=false;
  randomSeed(millis());
  while(certo==true){
      float numero1,numero2,numero3;
      int c;
      int r_user=0;
      x="";
      c=random(1,3);
    if(c==1){
          numero1=random(1,100);
          while(true){
            numero2=random(1,100);
            float numero_float=numero1/numero2;
            int numero_int=numero_float;
            if(numero_int==numero_float){
              break;
            }
          }
          numero3=random(1,100);
          int r_sys=numero1/numero2*numero3;
          lcd.setCursor(0,0);
          lcd.print(int(numero1)+String('/')+int(numero2)+String("*")+int(numero3)+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(int(numero1)+String('/')+int(numero2)+String("*")+int(numero3)+String('='));
                x="";
                r_user=0;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=15;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
              lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-10;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
    }
    
    if(c==2){
          numero1=random(1,100);
          numero2=random(1,100);
          while(true){
            numero3=random(1,100);
            float numero_float=(numero1*numero2)/numero3;
            int numero_int=numero_float;
            if(numero_int==numero_float){
              break;
            }
          }
          int r_sys=(numero1*numero2)/numero3;
          lcd.setCursor(0,0);
          lcd.print(int(numero1)+String('*')+int(numero2)+String("/")+int(numero3)+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(int(numero1)+String('*')+int(numero2)+String("/")+int(numero3)+String('='));
                x="";
                r_user=0;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=15;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
              lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-10;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
    }

  }
}
void level_5(){
  lcd.clear();
  bool sair=false;
  randomSeed(millis());
  while(certo==true){
      float numero1,numero2,numero3;
      int c;
      int r_user=0;
      x="";
      c=random(1,3);
      if(c==1){
          numero1=random(1,100);
          numero2=random(1,100);
          numero3=random(1,100);
          int r_sys=numero1*numero2*numero3;
          lcd.setCursor(0,0);
          lcd.print(int(numero1)+String('*')+int(numero2)+String("*")+int(numero3)+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(int(numero1)+String('*')+int(numero2)+String("*")+int(numero3)+String('='));
                x="";
                r_user=0;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=15;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
              lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-10;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
    }
    if(c==2){
          numero1=random(1,100);
          while(true){
            numero2=random(1,100);
            float numero_float=numero1/numero2;
            int numero_int=numero_float;
            if(numero_int==numero_float){
              break;
            }
          }
          while(true){
            numero3=random(1,100);
            float numero_float=(numero1/numero2)/numero3;
            int numero_int=numero_float;
            if(numero_int==numero_float){
              break;
            }
          }
          int r_sys=(numero1/numero2)/numero3;
          lcd.setCursor(0,0);
          lcd.print(int(numero1)+String('/')+int(numero2)+String("/")+int(numero3)+String('='));
            while(key!='='){
              key = keypad.getKey();
              if(key=='/'){
                sair=true;
                break;
              }
              if (key=='*'){
                lcd.clear();
                lcd.print(int(numero1)+String('/')+int(numero2)+String("/")+int(numero3)+String('='));
                x="";
                r_user=0;
              }
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
              lcd.print(key);
              x+=key;
              r_user=x.toInt();}
            }
          if(sair==true){
            return;}
          if(r_sys==r_user){
              lcd.setCursor(0,2);
              lcd.print(String("acertou"));
              lcd.setCursor(12,2);
              pontos+=15;
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
              lcd.clear();
              key = keypad.getKey();
              
              
          }
          else{
              lcd.setCursor(0,2);
              lcd.print(String("errou:")+r_sys);
              lcd.setCursor(12,2);
              pontos+=-10;
              if(pontos<0){
              pontos=0;
              }
              lcd.print(String("P")+pontos);
              delay(2000);
              x="";
          lcd.clear();
              key = keypad.getKey();
           }      
    }

  }
}
