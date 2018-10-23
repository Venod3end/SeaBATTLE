//
//  main.cpp
//  ocean battle
//
//  Created by apple on 20.10.2018.
//  Copyright © 2018 apple. All rights reserved.
//

#include "main.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    int n = 5;
    string null = "\t,";
    string z = "\t,";
    string ring[n][n];
    int rezRing[n][n];
    string ringWar[n][n];
    //заполняем резервный масик "0"
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rezRing[i][j] = 0;
        }
    }
    //заполняем масив ringWar
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ringWar[i][j] = z;
        }
    }
    //заполнаяем массив ринга ","
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ring[i][j] = null;
        }
    }
    // \/ Формирует ринг
    for(int i=0;i<n;i++){
        cout<<"\t"<<i;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<n;j++){
            cout<<ring[i][j];
        }
        cout<<endl;
    }
    //
    
    
    //рандомим для компьютера массив и кораблики
    srand( (unsigned int) time(NULL) );

    string comRing[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            comRing[i][j] = null;
            cout<<comRing[i][j];
        }
        cout<<endl;
    }
    
    int corShip1Com [n][n];
    int comKor = 2;
    for(int i=0;i<comKor;i++){
        int random1 = 0 + rand()% 5;
        int random2 = 0 + rand()% 5;//написать условие чтобы рандом1 != рандом2
        if((corShip1Com[0][0] != random1)&&(corShip1Com[0][1] != random2)){
        comRing[random1][random2]= "\tI";
        for(int j=0;j<1;j++){
            corShip1Com[i][j] = random1;
            corShip1Com[i][j+1] = random2;
            }
            
        }
        else{
            comKor = comKor + 1;
        }
    }
    
    comKor = 1;
    for(int i=0;i<comKor;i++){
        int random1 = 0 + rand()% 5;
        int random2 = 0 + rand()% 5;
        if((corShip1Com[0][0] != random1)&&(corShip1Com[0][1] != random2)&&
           (corShip1Com[0][0] != random2)&&(corShip1Com[0][1] != random1)&&
           (corShip1Com[1][0] != random1)&&(corShip1Com[1][1] != random2)&&
           (corShip1Com[1][0] != random2)&&(corShip1Com[1][1] != random1)){
            comRing[random1][random2] = "\tU";
            corShip1Com[0][2] = random1;
            corShip1Com[0][3] = random2;
            random1 = random1+1;
            if((random1 >= 0)&&(random1 < 5)){
                comRing[random1][random2] = "\tU";
                corShip1Com[2][2] = random1;
                corShip1Com[2][3] = random2;
            }
            else{
                random1 = random1 -2;
                comRing[random1][random2] = "\tU";
                corShip1Com[2][2] = random1;
                corShip1Com[2][3] = random2;
            }
        }
        else{
            comKor = comKor+1;
        }
    }
    comKor = 1;
    for(int i=0;i<comKor;i++){
        int random1 = 0 + rand()% 5;
        int random2 = 0 + rand()% 5;//контроль \/
        if((corShip1Com[0][0] != random1)&&(corShip1Com[0][1] != random2)&&
           (corShip1Com[1][0] != random1)&&(corShip1Com[1][1] != random2)&&
           (corShip1Com[0][2] != random1)&&(corShip1Com[0][3] != random2)&&
           (corShip1Com[2][2] != random1)&&(corShip1Com[2][3] != random2)){
            comRing[random1][random2] = "\tU";
            corShip1Com[4][0] = random1;
            corShip1Com[4][1] = random2;
            random2 = random2+1;
            if((random2 >= 0)&&(random2 < 5)){
                comRing[random1][random2] = "\tU";
                corShip1Com[4][2] = random1;
                corShip1Com[4][3] = random2;
            }
            else{
                random2 = random2 -2;
                comRing[random1][random2] = "\tU";
                corShip1Com[4][2] = random1;
                corShip1Com[4][3] = random2;
            }
        }
        else{
            comKor = comKor+1;
        }
    }
    
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<comRing[i][j];
        }
        cout<<endl;
    }

    
    //
    //расстановка корабликов 1х1
    int vertikal = n+1, gorizontal = n+1, oneKor = 2;
    
    cout<<"Введите координаты за которыми хотите расставить 2 кораблики 1х1"<<endl;
    string pervWtor[2] = {"\nПервый корабль :","\nВторой корабль :"};
    for(int i = 0; i < oneKor; i++){
        int rezVer = vertikal, rezGor = gorizontal;
        if(i < 1){
            cout<<pervWtor[0];
        }
        else{
            cout<<pervWtor[1];
        }
        cout<<"\nГоризонталь = ";
        cin>>gorizontal;
        cout<<"Вертикаль = ";
        cin>>vertikal;
        if((rezVer != vertikal)||(rezGor != gorizontal)){
            ring[vertikal][gorizontal] = "\tI";
            for(int j = 0 ; j < 1 ; j++){
                rezRing[i][j] = gorizontal;
                rezRing[i][j+1] = vertikal;
            }
        }
        else{
            cout<<"\nДва корабля не могут стоять на одной клетке :(\nПереставьте второй корабль..."<<endl;
            oneKor = oneKor +1;
        }
    }
    
    //кораблики 1х1 расставлены и выводится ринг
    for(int i=0;i<n;i++){
        cout<<"\t"<<i;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<n;j++){
            cout<<ring[i][j];
        }
        cout<<endl;
    }
    
    /*растановка корабликов 2х1
    1) Кораблики 2х1 не должны быть рядом с корабликами 1х1
    2) Нужно сделать чтобы при установке первой части кораблика вторая была ТОЛЬКО рядом со второй
    Написать уловие чтобы два корабля не были на одной клетке
    */
    cout<<endl;
    cout<<"Введите координаты за которыми хотите расставить 2 кораблики 2х1"<<endl;
    int twoKor = 2, revers;
    for(int i=0;i<twoKor;i++){
        //int rezVer = vertikal, rezGor = gorizontal;
        if( i < 1){
            cout<<pervWtor[0];
        }
        else{
            cout<<pervWtor[1];
        }
        cout<<"\nГоризонталь = ";
        cin>>gorizontal;
        cout<<"Вертикаль = ";
        cin>>vertikal;
        if(((rezRing[0][0] != gorizontal)||(rezRing[0][1] != vertikal))&&
           ((rezRing[1][0] != gorizontal)||(rezRing[1][1] != vertikal))){
            
            ring[vertikal][gorizontal] = "\tU";
            
            for(int i=0;i<n;i++){
                cout<<"\t"<<i;
            }
            cout<<endl;
            for(int i=0;i<n;i++){
                cout<<i;
                for(int j=0;j<n;j++){
                    cout<<ring[i][j];
                }
                cout<<endl;
            }
            int reversFor = 1;
            for( int q = 0 ; q < reversFor ; q++){
                cout<<"В какую сторону развернешь корабль?\nПо горизонтали или вертикали? (0-вертикали, 1-горизонтали) = ";
                cin>>revers;
                if(revers == 1){
                    cout<<"Влево или вправо?(0-вправо, 1-влево) = ";
                    cin>>revers;
                    if((revers == 1)&&(rezRing[0][0] != gorizontal - 1)){
                        ring[vertikal][gorizontal-1] = "\tU";
                    }
                    else if((revers == 0)&&(rezRing[1][0] != gorizontal + 1)){
                        ring[vertikal][gorizontal+1] = "\tU";
                    }
                    else{
                        cout<<"Нельзя ставить корабль поверх другого!"<<endl;
                        reversFor = reversFor + 1 ;
                    }
                }
                else if (revers == 0){
                    cout<<"Вверх или вниз?(0-вверх, 1-вниз) = ";
                    cin>>revers;
                    if((revers == 1)&&(rezRing[0][1] != vertikal + 1)){
                        ring[vertikal+1][gorizontal] = "\tU";
                    }
                    else if ((revers == 0)&&(rezRing[0][1] != vertikal - 1)){
                        ring[vertikal-1][gorizontal] = "\tU";
                    }
                    else{
                        cout<<"Нельзя ставить корабль поверх другого!"<<endl;
                        reversFor = reversFor + 1 ;
                    }
                }
            }
        
        for(int i=0;i<n;i++){
                cout<<"\t"<<i;
            }
            cout<<endl;
            for(int i=0;i<n;i++){
                cout<<i;
                for(int j=0;j<n;j++){
                    cout<<ring[i][j];
                }
                cout<<endl;
            }
        }
        else{
            cout<<"Кораблики 2х1 не должны стоять на клетках с кораблями 1х1!\nВведите еще раз координаты 2х1"<<endl;
            twoKor = twoKor + 1 ;
        }
    }
    
    
    //for(){
    
    cout<<"\nВы начинаете. Введите координаты куда стрелять : "<<endl;
    
    for(int i=0;i<n;i++){
        cout<<"\t"<<i;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<n;j++){
            cout<<ringWar[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    int shot = 1;
    for(int i=0;i<shot;i++){
        
        cout<<"\nГоризонталь = ";
        cin>>gorizontal;
        cout<<"Вертикаль = ";
        cin>>vertikal;
        if(ringWar[vertikal][gorizontal] == comRing[vertikal][gorizontal]){
            cout<<"Мимо.."<<endl;
            ringWar[vertikal][gorizontal] = "\t-";
            
            
            for(int i=0;i<n;i++){
                cout<<"\t"<<i;
            }
            cout<<endl;
            for(int i=0;i<n;i++){
                cout<<i;
                for(int j=0;j<n;j++){
                    cout<<ringWar[i][j];
                }
                cout<<endl;
            }
            shot = shot+1;
            cout<<endl;
        }
        else if (ringWar[vertikal][gorizontal] != comRing[vertikal][gorizontal]) {
            cout<<"Попадание.."<<endl;
            ringWar[vertikal][gorizontal] = "\t#";
            
            
            for(int i=0;i<n;i++){
                cout<<"\t"<<i;
            }
            cout<<endl;
            for(int i=0;i<n;i++){
                cout<<i;
                for(int j=0;j<n;j++){
                    cout<<ringWar[i][j];
                }
                cout<<endl;
            }
            cout<<endl;
            
            
            shot = shot +1;
            
        }
        
    }
        
//    }


}
