// Airplane ticket booking


#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Airline{
private:
string Flight, Des, Dep;
int Seats;
public:
Airline(string flight, string des,string dep, int seats){
    Flight= flight;
    Des= des;
    Dep=dep;
    Seats =seats;
}
string getFlight(){
    return Flight;
}
string getDes(){
    return Des;
}
string getDep(){
    return Dep;
}
int getSeat(){
    return Seats;
}
string update(string flight){
    ifstream in("C:/Users/manga/OneDrive/Desktop/c++/project/Flight.txt");
    ofstream out("C:/Users/manga/OneDrive/Desktop/c++/project/flighttemp.txt");
    string line;
    while(getline(in,line)){
        int pos=line.find(flight);
        if(pos != string::npos){
            int current = Seats-1;
            Seats=current;
            stringstream ss;
            ss<<current;
            string strCurrent = ss.str();
            int seatPos = line.find_last_of(':');
            line.replace(seatPos+1, string::npos,strCurrent);
        }
        out<<line<<endl;
    }
    out.close();
    in.close();
    remove("C:/Users/manga/OneDrive/Desktop/c++/project/Flight.txt");
    rename("C:/Users/manga/OneDrive/Desktop/c++/project/flighttemp.txt","C:/Users/manga/OneDrive/Desktop/c++/project/Flight.txt");
    cout<<"Seat Reserved Successfully!"<<endl;
}

};
string display(){
    ifstream in("C:/Users/manga/OneDrive/Desktop/c++/project/Flight.txt");
    if(!in){
        cout<<"Error: File cannot Open!"<<endl;
    }
    else{
        string line;
        while(getline(in,line)){
            cout<<line<<endl;
        }
    }
}

int main(){
    Airline flight1("F101","UAE","England",50);
    Airline flight2("F201","UAE","USA",40);
    Airline flight3("F301","UAE","Canada",2);

    ofstream out("C:/Users/manga/OneDrive/Desktop/c++/project/Flight.txt");
    if(!out){
        cout<<"Error : File cannot open !"<<endl;
    }
    else{
        out<<"\t"<<flight1.getFlight()<<":"<<flight1.getDes()<<":"<<flight1.getDep()<<":"<<flight1.getSeat()<<endl<<endl;
        out<<"\t"<<flight2.getFlight()<<":"<<flight2.getDes()<<":"<<flight2.getDep()<<":"<<flight2.getSeat()<<endl<<endl;
        out<<"\t"<<flight3.getFlight()<<":"<<flight3.getDes()<<":"<<flight3.getDep()<<":"<<flight3.getSeat()<<endl<<endl;
        cout<<"Data Saved Successfuly!"<<endl;
        out.close();
    }  
    bool exit =false;
    while(!exit){
        system("cls");
        cout<<"\t Welcome To Airline Management System"<<endl;
        cout<<"\t ************************************"<<endl;
        cout<<"\t 1.Reserve A Seat."<<endl;
        cout<<"\t 2.Exit."<<endl;
        cout<<"\t Enter the choice:" ;
        int val;
        cin>>val;
        if(val==1){
            system("cls");
            display();
            string flight;
            cout<<"Enter Flight No."<<endl;
            cin>>flight;
            if(flight==flight1.getFlight() && flight1.getSeat() >0 ){
                flight1.update(flight);
            }
            else if(flight1.getSeat()<=0){
                cout<<"Sorry, Seats Not Available!"<<endl;
            }
            if(flight==flight2.getFlight() && flight2.getSeat() >0 ){
                flight2.update(flight);
            }
            else if(flight2.getSeat()<=0){
                cout<<"Sorry, Seats Not Available!"<<endl;
            }
            if(flight==flight3.getFlight() && flight3.getSeat() >0 ){
                flight3.update(flight);
            }
            else if(flight3.getSeat()<=0){
                cout<<"Sorry, Seats Not Available!"<<endl;
            }
            Sleep(5000);
        }
        else if(val==2){
            system("cls");
            exit = true;
            cout<<"Good Luck!"<<endl;
            Sleep(3000);
        }
    }
    return 0;
}