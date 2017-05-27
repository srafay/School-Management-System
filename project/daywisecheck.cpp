#include <conio.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
int daywise(char,int,int,int*);
int main()
{
	system("cls");
int rollno,day1,day2,count=0,totalclass,tempclass=0;char ch;

cout<<"Enter Roll number of student ";cin>>rollno;

cout<<"Enter the days on and between which you want to check attendance ,example : 1,5 ";cin>>day1>>ch>>day2;
for (int i=day1 ; i<=day2 ; i++)
{
count+=daywise('1',rollno,i,&totalclass);
tempclass+=totalclass;
}
count=(count*100)/tempclass;
cout<<"\nThe attendance of roll # "<<rollno<<" from "<<day1<<" to "<<day2<<" was "<<count<<"%"<<endl; system("pause");
main();
}						//main function ends

int attendance(int rollno,int classno,int subject)
{
	int i=1,count=0; string line;char r[4];
	itoa(rollno,r,10);
	ifstream datafile;
	if (subject==1)
	datafile.open("cp.txt",ios::in);
	if (subject==2)
	datafile.open("fce.txt",ios::in);
	if (subject==3)
	datafile.open("bee.txt",ios::in);
	if (subject==4)
	datafile.open("pst.txt",ios::in);
	if (subject==5)
	datafile.open("eng.txt",ios::in);
	if (subject==6)
	datafile.open("cal.txt",ios::in);
	if (subject==7)
	datafile.open("oop.txt",ios::in);
	if (subject==8)
	datafile.open("dst.txt",ios::in);
	if (subject==9)
	datafile.open("cth.txt",ios::in);
	if (subject==10)
	datafile.open("dld.txt",ios::in);
	if (subject==11)
	datafile.open("alg.txt",ios::in);
	if (subject==12)
	datafile.open("isl.txt",ios::in);
	while (i<classno)
	{
		getline(datafile,line);
		i++;
	}
	if (getline(datafile,line))
	{

		if ((strstr(line.c_str(),r))!=NULL)
			count=100;
	}
	datafile.close();
	return count;

} // attendance fn ends

int daywise(char ch,int roll,int day,int* b)
{
int weekno,classno,totalclass,count=0;
if (ch=='1')
{
	int dayfile[5][5]={{1109,1108},{1105,1114,1115,2114,1120},{2120,3114,2108,2109,3109},{3120,2105,3108,2115,3115},{4120,4109}};
weekno=day/5;
day=day%5;

switch(day)
	{
	case 1://Monday
		totalclass=2;
		classno=dayfile[0][0]/1000+weekno*4;
			if (attendance(roll,classno,1)==100)
				count++;
		
		classno=dayfile[0][1]/1000+weekno*3;
			if (attendance(roll,classno,2)==100)
				count++;

		break;
	case 2://Tuesday
		totalclass=5;
		classno=dayfile[1][0]/1000+weekno*2;
			if (attendance(roll,classno,4)==100)
				count++;
		classno=dayfile[1][1]/1000+weekno*3;
			if (attendance(roll,classno,6)==100)
				count++;			
		classno=dayfile[1][2]/1000+weekno*3;
			if (attendance(roll,classno,5)==100)
				count++;
		classno=dayfile[1][3]/1000+weekno*3;
			if (attendance(roll,classno,6)==100)
				count++;
		classno=dayfile[1][4]/1000+weekno*4;
			if (attendance(roll,classno,3)==100)
				count++;

		break;
	case 3://Wednesday
		totalclass=5;
		classno=dayfile[2][0]/1000+weekno*4;
		if (attendance(roll,classno,3)==100)
				count++;
		classno=dayfile[2][1]/1000+weekno*3;
		if (attendance(roll,classno,6)==100)
				count++;
		classno=dayfile[2][2]/1000+weekno*3;
		if (attendance(roll,classno,2)==100)
				count++;
		classno=dayfile[2][3]/1000+weekno*4;
		if (attendance(roll,classno,1)==100)
				count++;
		classno=dayfile[2][4]/1000+weekno*4;
		if (attendance(roll,classno,1)==100)
				count++;
		
		break;
	case 4://Thursday
		totalclass=5;
		classno=dayfile[3][0]/1000+weekno*4;
		if (attendance(roll,classno,3)==100)
				count++;
		classno=dayfile[3][1]/1000+weekno*2;
		if (attendance(roll,classno,4)==100)
				count++;
		classno=dayfile[3][2]/1000+weekno*3;
		if (attendance(roll,classno,2)==100)
				count++;
		classno=dayfile[3][3]/1000+weekno*3;
		if (attendance(roll,classno,5)==100)
				count++;
		classno=dayfile[3][4]/1000+weekno*3;
		if (attendance(roll,classno,5)==100)
				count++;
		
		break;
	case 0://Friday
		totalclass=2;
		classno=dayfile[4][0]/1000+weekno*4;
		if (attendance(roll,classno,3)==100)
				count++;
		classno=dayfile[4][1]/1000+weekno*2;
		if (attendance(roll,classno,1)==100)
				count++;

		break;
     Default:
		cout<<"Invalid day";
	}
*b=totalclass;
} // ch==1 ends
if (ch=='2')
{
int dayfile[5][5]={{1,1,1,1},{2,2,3,2,2},{4,3},{1,2,1,2},{3,4,3}};
weekno=day/5;
day=day%5;

switch(day)
	{
	case 1://Monday
		totalclass=4;
		classno=dayfile[0][0]+weekno*4;
			if (attendance(roll,classno,7)==100)
				count++;
		classno=dayfile[0][1]+weekno*3;
			if (attendance(roll,classno,8)==100)
				count++;
		classno=dayfile[0][2]+weekno*3;
			if (attendance(roll,classno,11)==100)
				count++;
		classno=dayfile[0][3]+weekno*4;
			if (attendance(roll,classno,10)==100)
				count++;

		break;
	case 2://Tuesday
		totalclass=5;
		classno=dayfile[1][0]+weekno*4;
			if (attendance(roll,classno,10)==100)
				count++;
		classno=dayfile[1][1]+weekno*4;
			if (attendance(roll,classno,7)==100)
				count++;			
		classno=dayfile[1][2]+weekno*4;
			if (attendance(roll,classno,7)==100)
				count++;
		classno=dayfile[1][3]+weekno*3;
			if (attendance(roll,classno,11)==100)
				count++;
		classno=dayfile[1][4]+weekno*3;
			if (attendance(roll,classno,8)==100)
				count++;
		
		break;
	case 3://Wednesday
		totalclass=2;
		classno=dayfile[2][0]+weekno*4;
		if (attendance(roll,classno,7)==100)
				count++;
		classno=dayfile[2][1]+weekno*4;
		if (attendance(roll,classno,10)==100)
				count++;		
		
		break;
	case 4://Thursday
		totalclass=4;
		classno=dayfile[3][0]+weekno*2;
		if (attendance(roll,classno,9)==100)
				count++;
		classno=dayfile[3][1]+weekno*2;
		if (attendance(roll,classno,9)==100)
				count++;
		classno=dayfile[3][2]+weekno*2;
		if (attendance(roll,classno,12)==100)
				count++;
		classno=dayfile[3][3]+weekno*2;
		if (attendance(roll,classno,12)==100)
				count++;
		
		break;
	case 0://Friday
		totalclass=3;
		classno=dayfile[4][0]+weekno*3;
		if (attendance(roll,classno,8)==100)
				count++;
		classno=dayfile[4][1]+weekno*4;
		if (attendance(roll,classno,10)==100)
				count++;
		classno=dayfile[4][2]+weekno*3;
		if (attendance(roll,classno,11)==100)
				count++;
		
		break;


	}
*b=totalclass;
} //ch==2 ends
return count;
}