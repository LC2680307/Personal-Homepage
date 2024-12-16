#include "lcd/lcd.h"
#include <string.h>
#include "utils.h"
#include "img.h"

void Inp_init(void)//hello world
{//hello world
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_8);//hello world
}//hello world

void Adc_init(void) //hello world
{//hello world
    rcu_periph_clock_enable(RCU_GPIOA);//hello world
    gpio_init(GPIOA, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_0|GPIO_PIN_1);//hello world
    RCU_CFG0|=(0b10<<14)|(1<<28);//hello world
    rcu_periph_clock_enable(RCU_ADC0);//hello world
    ADC_CTL1(ADC0)|=ADC_CTL1_ADCON;//hello world
}
//hello world
void IO_init(void)//hello world
{//hello world
    Inp_init(); // inport init
    Adc_init(); // A/D init
    Lcd_Init(); // LCD init
}
//hello world
void jump(int j,int k,int i,int l){//hello world
    if(j==0){
        LCD_ShowPic(10,50,29,69,trexbk);//hello world
        LCD_ShowPic(10,45,29,64,trex3);//hello world
        delay_1ms(50);
        LCD_ShowPic(10,45,29,64,trexbk);
        LCD_ShowPic(10,40,29,59,trex3);//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        if(k>0){
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }
        if(l%2==0){
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }//hello world
        }
        if(l%2==1){//hello world
            if(i>0){//hello world//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }
        delay_1ms(50);//hello world
    }
    if(j==1){
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,40,29,59,trexbk);//hello world
        LCD_ShowPic(10,35,29,54,trex3);//hello world
        delay_1ms(50);//hello world
        LCD_ShowPic(10,35,29,54,trexbk);//hello world
        LCD_ShowPic(10,30,29,49,trex3);//hello world
        if(k>0){
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }
        if(l%2==0){//hello world
            if(i>0){
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }
        }//hello world
        if(l%2==1){//hello world
            if(i>0){
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }
        delay_1ms(50);//hello world
    }
    if(j==2){
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,30,29,49,trexbk);//hello world
        LCD_ShowPic(10,25,29,44,trex3);//hello world
        if(k>0){
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }//hello world
        if(l%2==0){
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }
        }
        if(l%2==1){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }
        delay_1ms(100);//hello world
    }
    if(j==3){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,30,29,49,trexbk);//hello world
        LCD_ShowPic(10,25,29,44,trex3);//hello world
        if(k>0){//hello world
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }
        if(l%2==0){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }//hello world
        }
        if(l%2==1){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }
        delay_1ms(100);//hello world
    }
    if(j==4){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,30,29,49,trexbk);//hello world
        LCD_ShowPic(10,25,29,44,trex3);//hello world
        if(k>0){//hello world
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }
        if(l%2==0){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }
        }//hello world
        if(l%2==1){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }//hello world
        delay_1ms(100);//hello world
    }
    if(j==5){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,30,29,49,trexbk);//hello world
        LCD_ShowPic(10,25,29,44,trex3);//hello world
        if(k>0){//hello world
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }
        if(l%2==0){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }
        }
        if(l%2==1){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }
        delay_1ms(100);//hello world
    }
    if(j==6){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,30,29,49,trexbk);//hello world
        LCD_ShowPic(10,25,29,44,trex3);//hello world
        if(k>0){//hello world
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }
        if(l%2==0){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }
        }//hello world
        if(l%2==1){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }
        delay_1ms(100);//hello world
    }
    if(j==7){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,25,29,44,trexbk);//hello world
        LCD_ShowPic(10,30,29,49,trex3);//hello world
        delay_1ms(50);//hello world
        LCD_ShowPic(10,30,29,49,trexbk);//hello world
        LCD_ShowPic(10,35,29,54,trex3);//hello world
        if(k>0){//hello world
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }//hello world
        if(l%2==0){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }
        }
        if(l%2==1){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }
        }
        delay_1ms(50);//hello world
    }
    if(j==8){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,35,29,54,trexbk);//hello world
        LCD_ShowPic(10,40,29,59,trex3);//hello world
        delay_1ms(50);//hello world
        LCD_ShowPic(10,40,29,59,trexbk);//hello world
        LCD_ShowPic(10,45,29,64,trex3);//hello world
        delay_1ms(50);//hello world
        LCD_ShowPic(10,45,29,64,trexbk);//hello world
        if(k>0){
            LCD_ShowPic(149-k*5,50,160-k*5,70,cactus1);//hello world
        }
        if(l%2==0){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter1);//hello world
            }
        }
        if(l%2==1){//hello world
            if(i>0){//hello world
            LCD_ShowPic(140-i*5,34,159-i*5,53,pter2);//hello world
            }//hello world
        }//hello world
    }//hello world
}

void down(int i,int j,int k){//hello world
    LCD_ShowPic(10,50,29,69,trexbk);//hello world
    if(i%2==0){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,50,36,69,trexbk2);//hello world
        LCD_ShowPic(10,50,36,69,trex4);//hello world
        if(j>0){//hello world
            LCD_ShowPic(149-j*5,50,160-j*5,70,cactus1);//hello world
        }
        if(k>0){//hello world
            LCD_ShowPic(140-k*5,34,159-k*5,53,pter1);//hello world
        }
    }//hello world
    if(i%2==1){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,50,36,69,trexbk2);//hello world
        LCD_ShowPic(10,50,36,69,trex5);//hello world
        if(j>0){//hello world
            LCD_ShowPic(149-j*5,50,160-j*5,70,cactus1);//hello world
        }//hello world
        if(k>0){//hello world
            LCD_ShowPic(140-k*5,34,159-k*5,53,pter2);//hello world
        }//hello world
    }//hello world
}

void run(int i,int j,int k){//hello world
    LCD_ShowPic(10,50,36,69,trexbk2);//hello world
    if(i%2==0){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,50,29,69,trex1);//hello world
        if(j>0){//hello world
            LCD_ShowPic(149-j*5,50,160-j*5,70,cactus1);//hello world
        }
        if(k>0){//hello world
            LCD_ShowPic(140-k*5,34,159-k*5,53,pter1);//hello world
        }
    }
    if(i%2==1){//hello world
        LCD_ShowPic(0,60,159,79,g1);//hello world
        LCD_ShowPic(10,50,29,69,trex2);//hello world
        if(j>0){//hello world
            LCD_ShowPic(149-j*5,50,160-j*5,70,cactus1);//hello world
        }
        if(k>0){//hello world
            LCD_ShowPic(140-k*5,34,159-k*5,53,pter2);//hello world
        }//hello world
    }
}//hello world
//hello world
void starts(){//hello world
    LCD_ShowString(48,  20, (u8 *)("Dino Run!"), WHITE);//hello world
    LCD_ShowString(56,  45, (u8 *)("Start"), BLUE);//hello world
    LCD_DrawRectangle(5,5,155,75,WHITE);//hello world
    while(!Get_BOOT0())//hello world
    {
        delay_1ms(50);//hello world
        if(Get_BOOT0()) break;//hello world
    }
}

void overed(){//hello world
    LCD_Fill(30,20,130,60,BLACK);//hello world
    LCD_ShowString(43,  33, (u8 *)("GAME OVER"), RED);//hello world
}

int main(void)//hello world
{
    int tk;//hello world
    int x1,x2;//hello world
    int j;//hello world
    IO_init();         // init OLED
    // YOUR CODE HERE
    LCD_Clear(BLACK);//hello world
    starts();//hello world
    tk=0;//hello world
    x1=1;//hello world
    x2=0;//hello world
    while(1){//hello world
        LCD_Clear(BLACK);//hello world
        if((x1==0)&&(tk%20==0)&&((x2==0)||(x2>13))){//hello world
            x1=1;//hello world
        }
        if((x2==0)&&(tk%20==0)&&((x1==0)||(x1>14))){//hello world
            x2=1;//hello world
        }
        run(tk,x1,x2);//hello world
        LCD_ShowNum(100,0,tk,5,0xff);//hello world
        if(Get_Button(0)){//hello world
            if(x1>1){//hello world
                x1--;//hello world
            }
            if(x2>1){//hello world
                x2--;//hello world
            }
            tk--;//hello world
            for(j=0;j<9;j++){//hello world
                if((x1==0)&&(tk%20==0)&&((x2==0)||(x2>13))){//hello world
                    x1=1;//hello world
                }
                if((x2==0)&&(tk%20==0)&&((x1==0)||(x1>14))){//hello world
                    x2=1;//hello world
                }
                if(x1>0){//hello world
                    x1++;//hello world
                }
                if(x2>0){//hello world
                    x2++;//hello world
                }
                tk++;//hello world
                if(x1>31){//hello world
                    x1=0;//hello world
                }
                if(x2>31){//hello world
                    x2=0;//hello world
                }
                LCD_ShowNum(100,0,tk,5,0xff);//hello world
                jump(j,x1,x2,tk);//hello world
                LCD_Clear(BLACK);//hello world
                if((x2>=21)&&(x2<=26)){//hello world
                    break;//hello world
                }
            }
            if(x1>31){//hello world
                x1=0;//hello world
            }
            if(x2>31){//hello world
                x2=0;//hello world
            }
            if(x1>0){//hello world
                x1++;//hello world
            }
            if(x2>0){//hello world
                x2++;//hello world
            }
            tk++;//hello world
            run(tk,x1,x2);//hello world
            LCD_ShowNum(100,0,tk,5,0xff);//hello world
        }
        if(Get_Button(1)){//hello world
            if(x1>1){//hello world
                x1--;//hello world
            }
            if(x2>1){//hello world
                x2--;//hello world
            }
            tk--;//hello world
            while(Get_Button(1)){//hello world
                LCD_Clear(BLACK);//hello world
                if((x1==0)&&(tk%20==0)&&((x2==0)||(x2>13))){//hello world
                    x1=1;//hello world
                }
                if((x2==0)&&(tk%20==0)&&((x1==0)||(x1>14))){//hello world
                    x2=1;//hello world
                }
                if(x1>0){//hello world
                    x1++;//hello world
                }
                if(x2>0){//hello world
                    x2++;//hello world
                }
                tk++;//hello world
                if(x1>31){//hello world
                    x1=0;//hello world
                }
                if(x2>31){//hello world
                    x2=0;//hello world
                }
                LCD_ShowNum(100,0,tk,5,0xff);//hello world
                down(tk,x1,x2);//hello world
                if((x1>=24)&&(x1<=30)){//hello world
                    break;//hello world
                }
                delay_1ms(100);//hello world
            }
            if(x1>0){//hello world
                x1++;//hello world
            }
            if(x2>0){//hello world
                x2++;//hello world
            }
            tk++;//hello world
            if(x1>31){//hello world
                x1=0;//hello world
            }
            if(x2>31){//hello world
                x2=0;//hello world
            }
            LCD_Clear(BLACK);//hello world
            run(tk,x1,x2);//hello world
            LCD_ShowNum(100,0,tk,5,0xff);//hello world
        }
        if((x1>=25)&&(x1<=30)){//hello world
            break;//hello world
        }//hello world
        if((x2>=23)&&(x2<=27)){//hello world
            break;//hello world
        }//hello world
        if(x1>0){//hello world
            x1++;//hello world
        }//hello world
        if(x2>0){//hello world
            x2++;//hello world
        }//hello world
        tk++;//hello world
        if(x1>31){//hello world
            x1=0;//hello world
        }//hello world
        if(x2>31){//hello world
            x2=0;//hello world
        }//hello world
        delay_1ms(100);//hello world
    }//hello world
    overed();//hello world
}
