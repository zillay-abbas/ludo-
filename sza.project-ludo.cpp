


#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<random>
#include<time.h>
#include<stdlib.h>

using namespace std;

void countPock(int,int,int,int[][4],int,int);
void ludologo();


int main()
{
	int pock[4][4]={0},num,sum,plyno,count[4]={0},won='\0';
	bool id=0,fl=false,game=false;
	char sel,anykey;
	int flag;
	srand(time(NULL));
	ludologo();
		cout<<"\n"<<"\t\t\t\t\t\t"<<"* It's Ludo Star *"<<"\n\n";
		ludologo();
		cout<<'\n'<<"\t\t\t\t\t\t"<<"\b\b"<<"Press Any Key To Start";
		anykey=_getch();
		if(anykey!='\0'){
			system("cls");
	cout<<"\t\t\t\t\t"<<"Select No. of Players: (1)(2)(3)(4) =";
	cin>>plyno;
	if(plyno==3){
		game=true;
	}
	if(plyno<=4){
	for(int j=0;j<plyno;j++){
		cout<<"Player No."<<j+1<<" : ";
		for(int i=0;i<4;i++){
			cout<<"("<<i+1<<")"<<":"<<pock[j][i]<<'\t';
		}cout<<"\n\n";
	}
	if(plyno==4){
		cout<<"If you want to play as Individual then enter: 0"<<endl;
		cout<<"If you want to play as friends then enter: 1 |";
		cin>>id;
	}
	if(id==true){
		cout<<"\nPlayer 1 and 3 are friends."<<endl;
		cout<<"Player 2 and 4 are friends."<<endl  ;
	}
	for(int i=0;i<plyno;i++){
		int sixcout=0,lstval=0;
		do{
		    cout<<"\nPlayer "<<i+1<<":"<<" [Stops: 10,15,20] "<<"\t\t\t Press any key to roll dice.";
	        _getch();
	        sum=rand()%6+1;
	        cout<<sum;
			if(sum!=6){
				lstval=sum;
			}
			if(sum==6){
				sixcout++;
			}
			if(sixcout==3){
				sixcout=-1;
			}
		}while(sum==6);
		for(int s=0;s<=sixcout;s++){
			cout<<endl<<"Select Pock: ";
		    cin>>sel;
			num=sel;
		    num=num-49;
			if(s<sixcout){
				sum=6;
			}
			if(s==sixcout){
				sum=lstval;
			}
			  for(int r=0;r<4;r++){
		  switch (sel){
			case '1':
				countPock(num,r,i,pock,sum,plyno);
	        cout<<"("<<r+1<<")"<<":"<<pock[i][r];	
			cout<<endl;
	    break;
	    	case '2':
				countPock(num,r,i,pock,sum,plyno);
	       cout<<"("<<r+1<<")"<<":"<<pock[i][r];
		   cout<<endl;
	    break;
		    case '3':
				countPock(num,r,i,pock,sum,plyno);
	       cout<<"("<<r+1<<")"<<":"<<pock[i][r];			
		   cout<<endl;
	   break;
		    case'4':
				countPock(num,r,i,pock,sum,plyno);
	       cout<<"("<<r+1<<")"<<":"<<pock[i][r];	
	       cout<<endl;
	   break;
		    default:
			cout<<"InValid Pock"<<endl;
			r=4;
		      }
		  }
		}
		  count[i]++;
		 for(int j=0;j<4;j++){
		  if(pock[i][j]<25){
			  flag=0;
			  j=4;
			  if(i==plyno-1){
			  fl=true;
			  }
		  }
		  else if(pock[i][j]==25){
			  flag=1;
			  if(game==true){
				  won=i;
			  }
		  }
		 }
		 if(flag==1){
			 if(plyno==1){
			 cout<<"Player "<<i+1<<" Reach Home in "<<count[i]<<" turns";
			 flag=' ';
			 }
			 else{
				 cout<<"Player "<<i+1<<" Wins. And Reach Home in "<<count[i]<<" turns";
				 flag=' ';
			 }
			 if(plyno<3){
			 i=plyno;
			 }
		 }
			 if(won!='\0')
			 {
				 if(i+1==won){
					 if(i+1==plyno-1){
					 i=-1;
		            fl=false;
			        flag=' ';
					 }
					 else{
					 i+=1;
					 }
				 }
				 else if(i+1!=won && fl==true)
				 {
					 if(won==0){
					 i=0;
					 fl=false;
					 flag=' ';
					 }
					 else {
					 i=-1;
		            fl=false;
			        flag=' ';
					 }
				 }
			 }
			 else if(fl==true){
			  i=-1;
		     fl=false;
			 flag=' ';
			 }
	}
	}
	else{
		cout<<"Invalid No. of Players. ;-}";
	}
		}
		  	_getch();
	return 0;
}  

void countPock(int a,int b,int c,int pck[][4],int s,int plyn){
	int modi,modk;
	bool id=0;
if(b==0 ){
	    	pck[c][a]+=s;
	    if(pck[c][a]>25){
		    pck[c][a]-=s;
	        }
				}
				for(int k=0;k<plyn;k++){
					for(int j=0;j<4;j++){
						if(k!=c && pck[c][a]!=0 && pck[c][a]!=10 && pck[c][a]!=15 && pck[c][a]!=20 &&pck[c][a]!=25 && pck[c][a]==pck[k][j]){
							if(id==true){
								modi=c%2;
								modk=k%2;
								if(modi!=modk){

							pck[k][j]=0;
								}
							}
							else{
							pck[k][j]=0;
							}
						}
					}
				}
}
void ludologo(){
	cout<<"\t\t\t\t\t\t";
	for(int i=0;i<18;i++){
		cout<<'*';
	}cout<<endl;
}