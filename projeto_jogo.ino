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
char tipo,key;
long dado1,dado2,rpt1,pontos=50;
double dado3,dado4,rpt2;
bool certo=true,sair=false,esgotado=false;
long r_sys,r_user,rand_min,rand_max;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop(){
  millis();
  jogo();
}
void jogo(){
  lcd.clear();
  lcd.print("escolha um nivel:");
  lcd.setCursor(0,2);
  lcd.print(String("1 2 3 4 5   p")+pontos);
  
  while(key!='1'&& key!='2'&& key!='3'&& key!='4'&& key!='5' && key!='*'){
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
  else if(key=='*'){
    key = keypad.getKey();
    lcd.clear();
    lcd.print("escolha um nivel:");
    lcd.setCursor(0,2);
    lcd.print(String("1 2 3 4 5 C ")+pontos);
    pontos=0;
  }
}

void level_1(){
  lcd.clear();
  sair=false;
  randomSeed(millis());
  while(true){
    algoritimos();
    long numero1,numero2;
    int c;
    r_user=0;
    r_sys=0;
    c=random(1,3);
    if(c==1){
      numero1=random(rand_min,rand_max);
      numero2=random(rand_min,rand_max);
      r_sys=numero1+numero2;
      lcd.setCursor(0,0);
      String conta_print=numero1+String('+')+numero2+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);     
    }
    if(c==2){
      numero1=random(rand_min,rand_max);
      int negativo=numero1;
      numero2=random(rand_min,negativo);
      r_sys=numero1-numero2;
      lcd.setCursor(0,0);
      String conta_print=numero1+String('-')+numero2+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);                 
    }
  }
}

void level_2(){
  lcd.clear();
  sair=false;
  randomSeed(millis());
  while(true){
    algoritimos();
    long numero1,numero2,numero3;
    int c;
    r_user=0;
    r_sys=0;
    c=random(1,3);
    if(c==1){
      numero1=random(rand_min,rand_max);
      numero2=random(rand_min,rand_max);
      int negativo=numero1+numero2;
      if(negativo>99){
        negativo=100;
      }
      numero3=random(rand_min,negativo);
      r_sys=numero1+numero2-numero3;
      lcd.setCursor(0,0);
      String conta_print=numero1+String('+')+numero2+String("-")+numero3+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user); 
          key = keypad.getKey();
    }      
  
    if(c==2){
      numero1=random(rand_min,rand_max);
      int negativo=numero1;
      numero2=random(rand_min,negativo);
      numero3=random(rand_min,rand_max);
      r_sys=numero1-numero2+numero3;
      lcd.setCursor(0,0);
      String conta_print=numero1+String('-')+numero2+String("+")+numero3+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);
          key = keypad.getKey();
    }      
  }
}
void level_3(){
  lcd.clear();
  sair=false;
  randomSeed(millis());
  while(true){
    algoritimos();
    float numero1,numero2;
    int c;
    r_user=0;
    r_sys=0;
    c=random(1,3);
    if(c==1){
      numero1=random(rand_min,rand_max);
      numero2=random(rand_min,rand_max);
      r_sys=numero1*numero2;
      lcd.setCursor(0,0);
      String conta_print=int(numero1)+String('*')+int(numero2)+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);
          key = keypad.getKey();
    }      

    if(c==2){
      numero1=random(rand_min,rand_max);
      while(true){
        numero2=random(1,100);
        float numero_float=numero1/numero2;
        int numero_int=numero_float;
        if(numero_int==numero_float){
          break;
        }   
      }
      r_sys=numero1/numero2;
      lcd.setCursor(0,0);
      String conta_print=int(numero1)+String('/')+int(numero2)+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);
          key = keypad.getKey();
    }      
  }
}

void level_4(){
  lcd.clear();
  sair=false;
  randomSeed(millis());
  while(true){
    algoritimos();
    float numero1,numero2,numero3;
    int c;
    r_user=0;
    r_sys=0;
    x="";
    c=random(1,3);
    if(c==1){
      numero1=random(rand_min,rand_max);
      while(true){
        numero2=random(1,100);
        float numero_float=numero1/numero2;
        int numero_int=numero_float;
        if(numero_int==numero_float){
          break;
        }
      }
      numero3=random(rand_min,rand_max);
      r_sys=numero1/numero2*numero3;
      lcd.setCursor(0,0);
      String conta_print=int(numero1)+String('/')+int(numero2)+String("*")+int(numero3)+String('=');
      lcd.print(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);
          key = keypad.getKey();
    }      
    
    if(c==2){
      numero1=random(rand_min,rand_max);
      numero2=random(rand_min,rand_max);
      while(true){
        numero3=random(1,100);
        float numero_float=(numero1*numero2)/numero3;
        int numero_int=numero_float;
        if(numero_int==numero_float){
          break;
        }
      }
      r_sys=(numero1*numero2)/numero3;
      lcd.setCursor(0,0);
      String conta_print=int(numero1)+String('*')+int(numero2)+String("/")+int(numero3)+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);
          key = keypad.getKey();
    }      
  }
}
void level_5(){
  lcd.clear();
  sair=false;
  randomSeed(millis());
  while(true){
    algoritimos();
      float numero1,numero2,numero3;
      int c;
      r_user=0;
      r_sys=0;
      x="";
      c=random(1,3);
      if(c==1){
        numero1=random(rand_min,rand_max);
        numero2=random(rand_min,rand_max);
        numero3=random(rand_min,rand_max);
        r_sys=numero1*numero2*numero3;
        lcd.setCursor(0,0);
        String conta_print=int(numero1)+String('*')+int(numero2)+String("*")+int(numero3)+String('=');
        lcd.print(conta_print);
        digitar(conta_print);
        if(sair==true){
          return;}
        val_r(r_sys,r_user);
            key = keypad.getKey();
      }      

    if(c==2){
      numero1=random(rand_min,rand_max);
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
      r_sys=(numero1/numero2)/numero3;
      lcd.setCursor(0,0);
      String conta_print=int(numero1)+String('/')+int(numero2)+String("/")+int(numero3)+String('=');
      lcd.print(conta_print);
      digitar(conta_print);
      if(sair==true){
        return;}
      val_r(r_sys,r_user);
          key = keypad.getKey();
    }      
  }
}
void algoritimos(){
  if(pontos<10){
    rand_min=1;
    rand_max=11;
  }
  if(pontos>=10){
    rand_min=1;
    rand_max=21;
  }
  if(pontos>=20){
    rand_min=10;
    rand_max=51;
  }
  if(pontos>=40){
    rand_min=10;
    rand_max=100;
  }
  if(pontos>=50){
    rand_min=50;
    rand_max=100;
  }

}
void digitar(String conta_print){
  unsigned long tempo_inicial=millis();
  while(key!='='){
    key = keypad.getKey();
    esgotado=false;
    unsigned long tempo_atual=millis();
    if(tempo_atual>(tempo_inicial+20000)){
      lcd.clear();
      lcd.print("tempo esgotado!!");
      delay(2000);
      lcd.clear();
      lcd.print(conta_print);
      esgotado=true;
      break;
    }
    if(key=='/'){
      sair=true;
      break;
    }
    if (key=='*'){
      lcd.clear();
      lcd.print(conta_print);
      x="";
      r_user=0;
    }
  if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
    lcd.print(key);
    x+=key;
    r_user=x.toInt();}
  }

}
void val_r(int r_sys,int r_user){
  if(r_sys==r_user){
    lcd.setCursor(0,2);
    lcd.print(String("acertou"));
    lcd.setCursor(12,2);
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
    pontos+=-5;
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
