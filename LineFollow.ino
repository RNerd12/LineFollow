#include<AFMotor.h>
AF_DCMotor m1(4);
AF_DCMotor m2(2);
int i=0,m=0,j=0,f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,f7=0,f8=0,nl=0,nr=0,dir1[100],dir2[100];

void setup() {            
  pinMode(A0,INPUT);      //left most sensor   8
  pinMode(A1,INPUT);      //left sensor        9
  pinMode(A2,INPUT);      //centre sensor      A2
  pinMode(A3,INPUT);      //right sensor       A3
  pinMode(A4,INPUT);      //right most sensor  A4
  pinMode(A5,OUTPUT);     //LED                13
  m1.setSpeed(255);
  m2.setSpeed(255);
  m1.run(FORWARD);
  m2.run(FORWARD);
}
void loop() 
{                                                             //end condition
  if(digitalRead(A0)==0&&digitalRead(A1)==0&&digitalRead(A2)==0&&digitalRead(A3)==0&&digitalRead(A4)==0)
  {
    delay(100);
    if(digitalRead(A0)==0&&digitalRead(A1)==0&&digitalRead(A2)==0&&digitalRead(A3)==0&&digitalRead(A4)==0)
    {
      f7=1;
      digitalWrite(13,HIGH);
      m1.setSpeed(0);
      m2.setSpeed(0);
      for(int k=0,l=0;j<=i;j++,k++,l++)                   //wet array
      {
        dir2[k]=dir1[j];                                      //copy
        if(dir1[j]==3||dir1[j]==4||dir1[j]==6)                //dead ends
          l=0;
        if(dir1[j]==1)
        {
          k=k-l;
          switch(dir2[k])
          {
            case 3:dir2[k]=5;
                   break;
            case 4:dir2[k]=7;
                   break;
            case 6:dir2[k]=5;
                   break;
          }
          j=j+l;
          l=0;
        }
        if(j>5)                                               //loops  
        {
          f8=0;                                   
          for(int x=1;x<=4;x++)
            if((dir1[j]==2||dir1[j]==4)&&(dir1[j-k]==2||dir1[j-k]==4))
              f8++;
          if(f8==4)
          {
            k-=4;
            switch(dir2[k])
            {
             case 3:dir2[k]=5;
                     break;
             case 4:dir2[k]=7;
                     break;
             case 6:dir2[k]=5;
                     break;
            }
            j++;
          }
        }
      }
      while(digitalRead(A0)==0&&digitalRead(A1)==0&&digitalRead(A2)==0&&digitalRead(A3)==0&&digitalRead(A4)==0)
      {}
      digitalWrite(13,LOW);
      delay(1500);
      m1.run(FORWARD);
      m2.run(FORWARD);
    }
  }
  if(digitalRead(A1)==0&&digitalRead(A0)!=0)                //alignment
  {
    m2.setSpeed(200);
    delay(75);
    m2.setSpeed(255);
  }
  if(digitalRead(A3)==0&&digitalRead(A4)!=0)
  {
    m1.setSpeed(200);
    delay(75);
    m1.setSpeed(255);
  }
  if(f7==0)
  {  
    if(digitalRead(A0)==0&&nl<5)                            //turns
    {
      m1.setSpeed(200);
      m2.setSpeed(200);
      if(digitalRead(A4)==0)
        f6=1;
      delay(1450);
      if(digitalRead(A2)==1)
        f2=1;
      else
        f4=1;
      m1.run(BACKWARD);
     // delay(50);
      if(digitalRead(A2)==0)
        m1.run(FORWARD);
    }
    else if(digitalRead(A4)==0&&nr<5)
    {
      m1.setSpeed(200);
      m2.setSpeed(200);
      delay(1450);
      if(digitalRead(A2)==0)
        f3=1;
      else
      {
        f5=1;
        m2.run(BACKWARD);
        delay(50);
        if(digitalRead(A2)==0)
          m2.run(FORWARD);  
      }
    }
    else if(digitalRead(A2)==0)                //dead end
    {
      m1.setSpeed(200);
      m2.setSpeed(200);
      m1.run(BACKWARD);
      delay(2900);
      m1.run(FORWARD);
      f1=1;
    }
    else if(digitalRead(A2)==10)
    {
      m1.run(BACKWARD);
      m2.run(BACKWARD); 
    }
    if(f2==1||f4==1)                     //loops
    {
      nl++;
      nr=0;
    }
    if(f5==1)
    {
      nr++;
      nl=0;
    }                          
    if(f1==1&&dir1[i-1])                 //dry array
    {
     dir1[i]=1;                          //reverse-1
      i++;
      f1=0;
    }
    if(f2==1)
    {
      dir1[i]=2;                         //left-2
      f2=0;
      i++;
    }
    if(f3==1)
    {
      dir1[i]=3;                         //forward(right)-3
      f3=0;
      i++;
    }
    if(f4==1)
    {
      dir1[i]=4;                         //left(forward)-4
      f4=0;
      i++;
    }
    if(f5==1)
    {
      dir1[i]=5;                         //right-5
      f5=0;
      i++;
    }
    if(f6==1)
    {
      dir1[i]=6;                         //left(right)-6
      f6=0;
      i++;
    }                                    //forward-7
  }
  else
  {
    if(digitalRead(A0)==0||digitalRead(A3)==0)
    {
      switch(dir2[j])
      {
        case 2:
              m1.setSpeed(200);
              m2.setSpeed(200);
              delay(1450);
              m1.run(BACKWARD);
              //delay(50);
              if(digitalRead(A2)==0)
                m1.run(FORWARD);
              break;
        case 5:
              m1.setSpeed(200);
              m2.setSpeed(200);
              delay(1450);
              m2.run(BACKWARD);
              //delay(50);
              if(digitalRead(A2)==0)
                m2.run(FORWARD);
              break;
        case 7:
              break;   
      }
    }
  }
  delay(1);
}
  if(ls == LOW && rs == LOW)
  {
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
  }
}
