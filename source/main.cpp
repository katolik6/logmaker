#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
    fstream plik;
    plik.open("log.txt", ios::out | ios::app);
    if(plik.good()){
        unsigned int year, month, day, hour, minute, second;
        second=time(0);
        minute=hour=day=month=1;
        year=1970;
        while((float(second)/31536000)>=1){
            year++;
            if((!(year%4))&&(year%1000)){
                if((float(second)/31622400)<1){
                    year--;
                    break;
                }else{second-=31622400;}
            }else{
                second-=31536000;
            }
        }
        while((second/float(2419200))>=1){
            if((!(year%4))&&(year%1000)&&(month==2)){
                if(second<2505600) break;
                second-=2505600;
            }else{
                if(month==2){
                    if(second<2419200) break;
                    second-=2419200;
                }else
                if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)){
                    if(second<2678400) break;
                    second-=2678400;
                }else{
                    if(second<2592000) break;
                    second-=2592000;
                }
            }
            month++;
        }
        while((float(second)/86400)>=1){
            second-=86400;
            day++;
        }
        while((float(second)/3600)>=1){
            second-=3600;
            hour++;
        }
        while((float(second)/60)>=1){
            second-=60;
            minute++;
        }
        plik<<"\n"<<year<<", "<<month<<", "<<day<<", "<<hour<<", "<<minute<<", "<<second;
        plik.close();
    }
    return 0;
}
