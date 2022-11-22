// CONFIG1
#pragma config FOSC = INTOSC    // 内部オシレーター使用
#pragma config WDTE = OFF       // ウォッチドックタイマー無効
#pragma config PWRTE = OFF      // パワーアップタイマー無効
#pragma config MCLRE = OFF      // MCLR OFF
#pragma config CP = OFF         // コードプロテクション無効
#pragma config BOREN = ON       // ブラウンアウトリセット有効
#pragma config CLKOUTEN = OFF   // クロックアウト無効
#pragma config IESO = ON        // オシレータークロスオーバー切り替え有効
#pragma config FCMEN = ON       // フェイルセーフクロックモニター有効

// CONFIG2
#pragma config WRT = OFF        // フラッシュメモリ保護なし
#pragma config PPS1WAY = OFF    // 1度きりのPPS設定無効
#pragma config ZCDDIS = ON      // ゼロクロス検知回路無効
#pragma config PLLEN = ON       // PPL (x4PPS)有効
#pragma config STVREN = ON      // スタックオーバーフロー/アンダーフローでリセット有効
#pragma config BORV = LO        // ブラウンアウトリセット LOレベル
#pragma config LPBOR = OFF      // BOR無効
#pragma config LVP = OFF        // 低電圧プログラミング無効

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 32000000

void PIN_init(); //入出力設定やPPS設定
void UART_init(); //UART初期設定
void UART_print(char moji[]); //UART送信
void UART_println(char moji[]); //UART送信 + 改行

/*
 * 
 */
int main(int argc, char** argv) {
    
    OSCCON = 0xF0; //PPS有効 (32MHz)
    
    PIN_init();
    UART_init();
    __delay_ms(2000);
    __delay_ms(2000);
    while(1){
    if(RC3 == 0){
        UART_println("1");
        __delay_ms(1600);
    } else if(RC4 == 0){
        UART_println("2");
        __delay_ms(1600);
    } else if(RC5 == 0){
        UART_println("3");
        __delay_ms(1600);
    } else if(RC6 == 0){
        UART_println("4");
        __delay_ms(1600);
    } else if(RC7 == 0){
        UART_println("5");
        __delay_ms(1600);
    }
    }
    return (EXIT_SUCCESS);
}

//入出力設定やPPS設定
//引数 void 戻り値 void
void PIN_init(){
    
    TRISAbits.TRISA0 = 0; //RA0 出力
    TRISAbits.TRISA4 = 0; //RA4 UART TX
    TRISAbits.TRISA5 = 1; //RA5 UART RX
    ANSELA = 0; //RA デジタル入出力
    
    PPSLOCK = 0; //PPSアンロック
    
    RA4PPS = 0x14; //RA4をUART TXに設定
    RXPPS = 0x05; //RA5をUART RXに設定
    
    PPSLOCK = 1; //PPSロック
    ANSELC = 0b00000000;
    TRISC = 0b11111111;
    PORTC = 0b00000000; 
    OPTION_REG = 0b00000000;
}

//UARTの初期設定用
//引数 void 戻り値 void
void UART_init(){
    TX1STA |= 0x20; //UARTモード BRGH = 0;
    RC1STA |= 0x80; //シリアルモード有効 8bitモード
    BAUD1CON |= 0x00;
    
    SP1BRG = 51; //9600bps速度
}

//UART文字列送信 (改行なし)
//引数 文字列 戻り値 なし
void UART_print(char moji[]){
    int i = 0;
    while(moji[i] != '\0'){
        TX1REG = moji[i];
        while(!TX1STAbits.TRMT){} //送信待ち時間
        i++;
    }
}

//UART文字列送信 (改行あり) 
//引数 文字列 戻り値 なし
void UART_println(char moji[]){
    int i = 0;
    while(moji[i] != '\0'){
        TX1REG = moji[i];
        while(!TX1STAbits.TRMT){} //送信待ち時間
        i++;
    }
    TX1REG = '\r';
    while(!TX1STAbits.TRMT){} //送信待ち時間
    TX1REG = '\n';
    while(!TX1STAbits.TRMT){} //送信待ち時間
}
