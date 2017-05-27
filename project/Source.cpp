#include <conio.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
void add_new(); void update_attendance();									 // Functions
void edit_data(); void display_data(); void check_attendance();				// to
void search(char,char [],int); int totalclass(int subject);				   // be
const int numberofstudents=50; const int numberofdays=80;				  // used
const int nooflines=4; int overall(int,int);		 					 // in
void dailyupdate(int);	int daywise(char,int,int,int*);					// the
int attendance(int, int, int);  void admin(); void user();			   // program

void main()
{
	system("cls");
	string username,pw; char temp;
cout <<"\n\n\n\n\n\n\n\n\n\t\t\tEnter username : ";
getline(cin,username);
cout <<"\n\t\t\tEnter password : ";
getline(cin,pw);
if ((username=="admin") && (pw=="admin"))
	admin();
if ((username=="user") && (pw=="user"))
	user();
if ( ((username=="user") && (pw=="user")) || ((username=="admin") && (pw=="admin")) )
	temp='g';
else
{ cout <<"\n\n\t\t\t ***Wrong Password***\n"; system("pause"); main(); }

}						//main function ends

void admin(void)
{
	char ch,rollno[4];
		cout <<"\n\n*Successfuly logged in to the Administrators account\n\n";
		system("pause");
		skip:
system("cls");
cout<<"\n\t\t\t=========================";
cout<<"\n\t\t\tSTUDENT ATTENDANCE SYSTEM";
cout<<"\n\t\t\t=========================";
cout<<"\n\n\n\tADMIN System" ;
cout<<"\n\t------------";
cout<<"\n\n\tSelect an Option =>";
cout<<"\n\n\n\t\t1. Update students data\n\t\t2. List students data\n\t\t3. Update attendance\n\t\t4. Check attendance\n\t\t5. Search for students\n\t\t6. Log out";
cout<<"\n\n\n\tWaiting for your response => ";
		ch=getche();

if (ch=='1')
{
	system("cls");
cout<<"\n\n 0. To create NEW record for new Batch\n\n 1. Update or remove data for the existing records\n";
cout<<"\n\n\tWaiting for your response => ";
ch=getche();
				if (ch=='0')
					{
				system("cls");
				cout<<"\n\t\t\t===================================";
				cout<<"\n\t\t\tCreate new record & delete previous";
				cout<<"\n\t\t\t===================================";
				cout <<"\n\n\t\t\t*** WARNING ***\n\nProceeding further results in the deletion of all the previous records\n";
				cout <<"\nEnter 'y' to continue or anykey to display Menu list => ";
				ch=getche();
				if (ch=='y' || ch=='Y')
				{ add_new(); goto skip; }
				else
				goto skip;
					}
				if (ch=='1')
				{
					system("cls");
					cout<<"\n\t\t\t===================================";
					cout<<"\n\t\t\tAdd, Remove or Edit data records";
					cout<<"\n\t\t\t===================================";
					cout <<"\n\n";
					edit_data();
				}
	goto skip;
}
if (ch=='2')
		{
			system("cls");
cout<<"\n\t\t\t===================================";
cout<<"\n\t\t\t       List Students data";
cout<<"\n\t\t\t===================================";
cout <<"\n\n Listing all of the students data";
cout<<"\n\n\n";
					cout <<"View the list of information of students  :"<<endl<<"	1 - First Year (FE)"<<endl<<"	2 - Second Year (SE)";
					cout <<endl<<endl<<"Waiting for instructions..... ";
					ch=getche();
					for (int roll_no=1; roll_no<=numberofstudents ; roll_no++)
					{
						char r_no[4]; itoa(roll_no,r_no,10);
						search(ch,r_no,3);
					}
		}
if (ch=='3')
update_attendance();
if (ch=='4')
			{
				system("cls");
cout<<"\n\t\t\t===================================";
cout<<"\n\t\t\t       Check Attendance";
cout<<"\n\t\t\t===================================";
cout <<"\n\n Check Attendance :\n\n\t\t1. Subject wise\n\t\t2. Daywise\n\n\tSelect an Option => ";
ch=getche();
				if (ch=='1')
				{
					system("cls");
					char rollno[4];
					cout <<"\nSubject wise Attendance\n\n\t\t1. First Year\n\t\t2. Second Year\n";
					ch=getche();
					cout <<"\n Enter Roll # : ";
					cin >>rollno;
					search(ch,rollno,1);
				}
				if (ch=='2')
				{
					system("cls");
					int rollno,day1,day2,count=0,totalclass,tempclass=0;char ch1,ch2;
					cout <<"Select Year :\n\t\t1. First Year\n\t\t2. Second Year\t=>";
					ch2=getche();
					cout<<"\n\nEnter Roll number of student "; cin>>rollno;
					cout<<"\nEnter the days on and between which you want\n to check attendance ,example : 1,5 => ";
					cin>>day1>>ch1>>day2;
					for (int i=day1 ; i<=day2 ; i++)
					{
					count+=daywise(ch2,rollno,i,&totalclass);
					tempclass+=totalclass;
					}
					count=(count*100)/tempclass;
					cout<<"\nThe attendance of roll # "<<rollno<<" from "<<day1<<" to "<<day2<<" was "<<count<<"%"<<endl;
					 system("pause");
					goto skip;
				}
			}
if (ch=='5')
		{
			system("cls");
cout<<"\n\t\t\t===================================";
cout<<"\n\t\t\t       List Students data";
cout<<"\n\t\t\t===================================";
cout <<"\n\nList students data according to : \n";
cout<<"\n\n\n\t\t1. Roll number\n\t\t2. Name\n\t\t3. Overall attendance";
cout<<"\n\n\n\tWaiting for your response => ";
	ch=getche();
	system("cls");
				if (ch=='1')
				{
					cout <<"View the list of information of students  :"<<endl<<"	1 - First Year (FE)"<<endl<<"	2 - Second Year (SE)";
					cout <<endl<<endl<<"Waiting for instructions..... ";
					ch=getche();
					cout <<"\n\nEnter roll number : "; cin>>rollno;
					search(ch,rollno,3);
				}
				if (ch=='2')
					display_data();
				if (ch=='3')
					check_attendance();
		}
if (ch=='6')
{ cout <<"\n\nLogged off succesfully...\n"; system("pause"); main(); }
goto skip;
} // admin fn ends

void user(void)
{
	char ch,rollno[4];
		cout <<"\n\n*Successfuly logged in to the Users account\n\n";
		system("pause");
		again:
system("cls");
cout<<"\n\t\t\t=========================";
cout<<"\n\t\t\tSTUDENT ATTENDANCE SYSTEM";
cout<<"\n\t\t\t=========================";
cout<<"\n\n\n\tEND-USER System" ;
cout<<"\n\t---------------";
cout<<"\n\n\tSelect an Option =>";
cout<<"\n\n\n\t\t1. View attendance\n\t\t2. Log out";
cout<<"\n\n\n\tWaiting for your response =>";
		ch=getche();
		if (ch=='1')
		{
			system("cls");
cout<<"\n\t\t\t===================================";
cout<<"\n\t\t\t        View Attendance";
cout<<"\n\t\t\t===================================";
cout <<"\n\n Select from the options";
cout<<"\n\n\n";
					cout <<"Select year  :"<<endl<<"	1 - First Year (FE)"<<endl<<"	2 - Second Year (SE)";
					cout <<endl<<endl<<"Waiting for instructions..... ";
					ch=getche();
					cout <<"\n\nEnter your roll number : "; cin>>rollno;
					search(ch,rollno,1);
					goto again;
		}
	if (ch=='2')
{ cout <<"\n\nLogged off succesfully...\n"; system("pause"); main(); }
	goto again;	
}

void add_new()
{
system("cls");
	char ch; string data;
	cout <<"Enter the new data of students for :"<<endl<<"	1 - First Year (FE)"<<endl<<"	2 - Second Year (SE)";
	cout <<endl<<endl<<"Waiting for instructions..... ";
	ch=getche();
	ofstream datafile;
	if (ch=='1')
		datafile.open("data-FE.txt", ios::out );
	if (ch=='2')
		datafile.open("data-SE.txt", ios::out);
	if (ch=='1' || ch=='2')
		goto start;
	else
	{
		cout <<endl<<"Please enter a valid option..........\n\n";
		system("pause");
		return;
	}

start:
if (!datafile)
{
cerr <<"File couldn't be opened\n";
system("pause");
exit (1);
}
system("cls");
for (int i=1 ; i<=numberofstudents ; i++)
{
cout <<"Enter Full name of student (roll#"<<i<<") : ";
getline (cin,data);
datafile <<'='<<endl<<i<<endl<<data<<endl;
cout <<endl<<"Enter Father's name of student (roll#"<<i<<") : ";
getline (cin,data);
datafile <<data<<endl;

system("cls");
} //for ends
datafile.close();
if (ch=='1')
{
ofstream cpfile("cp.txt",ios::out); cpfile.close();
ofstream fcefile("fce.txt",ios::out); fcefile.close();
ofstream beefile("bee.txt",ios::out); beefile.close();
ofstream engfile("eng.txt",ios::out); engfile.close();
ofstream pstfile("pst.txt",ios::out); pstfile.close();
ofstream calfile("cal.txt",ios::out); calfile.close();
}
if (ch=='2')
{
ofstream oopfile("oop.txt",ios::out); oopfile.close();
ofstream dstfile("dst.txt",ios::out); dstfile.close();
ofstream cthfile("cth.txt",ios::out); cthfile.close();
ofstream dldfile("dld.txt",ios::out); dldfile.close();
ofstream algfile("alg.txt",ios::out); algfile.close();
ofstream islfile("isl.txt",ios::out); islfile.close();
}

return;
}						//add_new function ends

void edit_data()
{
	repeat:
char ch,rollno[4], data[50]; string line;
	cout <<"Modify the data of students of :"<<endl<<"	1 - First Year (FE)"<<endl<<"	2 - Second Year (SE)";
	cout <<endl<<endl<<"Waiting for instructions..... ";
	ch=getche();
	ifstream datafile;
	ofstream tempfile("temp.txt" , ios::out);
	if (ch=='1')
		datafile.open("data-FE.txt", ios::in);
	if (ch=='2')
		datafile.open("data-SE.txt", ios::in);
	if (ch=='1' || ch=='2')
		goto start;
	else
	{
		cout <<endl<<"Please enter a valid option..........\n\n";
		system("pause");
		edit_data();
	}
start:
	system("cls");
	cout <<"Enter the roll number for which the data is to be modified : ";
	cin.getline(rollno,3);
	while ( getline(datafile,line) )
	{
		if (rollno==line)
		{
			cout <<"\n\t\t **Students Information**\n";
			getline(datafile,line);
			cout <<"Name : "<<line<<endl;
			getline(datafile,line);
			cout <<"Father's name : "<<line<<endl;
			cout <<"Roll # : "<<rollno<<endl;
			if (ch=='1')
				cout <<"Year : First Year "<<endl;
			if (ch=='2')
				cout <<"Year : Second Year "<<endl;
			goto nowopen;
		}
	}
	nowopen:
	datafile.seekg(0);
	int check=nooflines;
while ( getline(datafile,line) )
{
	if (rollno==line)
	{
		check=nooflines-(nooflines-3) ;
									tempfile << rollno <<endl;
cout <<"\n\t\t ***Leave blank to delete a record***\n\n";
		cout <<" \t\t*** Data is being updated ***"<<endl;
		cout <<"\nEnter the name of Student : ";
		cin.getline (data,50);		tempfile << data <<endl;
		cout <<"\nEnter father's name of student : ";
		cin.getline (data,50);		tempfile << data <<endl;
	}
	if (check<nooflines && check>0)
		{
			--check;
			goto skip;
	}
tempfile << line <<endl;
skip: ;
}			// while ends
datafile.close(); tempfile.close();				// closing files
if (ch=='1')
				{
		remove("data-FE.txt");  rename("temp.txt" , "data-FE.txt");
				}
	if (ch=='2')
				{
		remove("data-SE.txt");  rename("temp.txt" , "data-SE.txt");
				}

cout <<endl<<"Press r to repeat or any key to return to the main menu... ";
ch=getche();
if (ch=='r' || ch=='R')
{ system("cls");
goto repeat;
}
else
{ system("cls");
return;
}
}						//edit_data function ends

void display_data()
			{
				string name,line; char rollno[100]; unsigned int count=0,check=0;
system("cls");
	ifstream datafE("data-FE.txt", ios::in);
if (!datafE)
{
cerr <<"File couldn't be opened\n";
system("pause");
exit (1);
}
cout <<"\n\nEnter name to search : "; getline(cin,name);

while (getline(datafE,line))
{
	count++;
	if ((strstr(line.c_str(),name.c_str())!=NULL) && count%4!=0)
	{	
		++check;
		search('1',rollno,3);
	}
strncpy(rollno,line.c_str(),3);
} //while ends
datafE.close();
	ifstream dataSE("data-SE.txt", ios::in);
	count=0;
	while (getline(dataSE,line))
{
	count++;
	if ((strstr(line.c_str(),name.c_str())!=NULL) && count%4!=0)
	{	
		++check;
		search('2',rollno,3);
	}
strcpy(rollno,line.c_str());
} //while ends
dataSE.close();
if (check==0)
	cout <<"\n No record found...\n  ";
system ("pause");
return;
		}			 //display_data function ends

void search(char ch,char rollno[],int state) 
{                     // state : 0=no details, 1=details , 3=just for listing
	repeat:
char data[50]; string line; int presence;
system ("cls");
	ifstream datafile;
	if (ch=='1')
		datafile.open("data-FE.txt", ios::in);
	if (ch=='2')
		datafile.open("data-SE.txt", ios::in);
	if (ch=='1' || ch=='2')
		goto start;
	else
	{
		cout <<endl<<"Please enter a valid option..........\n\n";
		system("pause");
		return;
	}
start:
	system("cls");
while ( getline(datafile,line) )
{
	if (rollno==line)
	{

		cout <<"\t\t*** Data is being displayed ***"<<endl;
			getline(datafile,line);
		cout <<"\nName of Student : "<<line<<endl;
			getline(datafile,line);
		cout <<"Father's name : "<<line<<endl;
	}
}			// while ends
datafile.close();
if (ch=='1')
cout <<"Year of studying : First Year (FE)";
if (ch=='2')
cout <<"Year of studying : Second Year (SE)";
	cout <<"\nRoll number : "<<rollno<<endl<<endl;
	int temp=atoi(rollno);
	int totalsubjects=6,result=0,tempsubject;
	if (state==1)
	cout <<"\t\t*** Attendance Sheet ***";
		for (int subject=1 ; subject<=6 ; subject++)
		{
			tempsubject=subject;
			if (ch=='2')
				tempsubject+=6;
			temp=overall(temp,tempsubject);
			if (temp==786)
			{--totalsubjects; temp=0; }
			if (state==1)
			{
			if (tempsubject==1)
			cout <<"\n Computer Programming (CS-109) : "<<temp<<"%";
			if (tempsubject==2)
			cout <<"\n Fundamentals of Computer Engineering (CS-108) : "<<temp<<"%";
			if (tempsubject==3)
			cout <<"\n Basic Electrical Engineering (EE-120) : "<<temp<<"%";
			if (tempsubject==4)
			cout <<"\n Pakistan Studies (HS-105) : "<<temp<<"%";
			if (tempsubject==5)
			cout <<"\n Functional English (HS-114) : "<<temp<<"%";
			if (tempsubject==6)
			cout <<"\n Calculus (MT-114) : "<<temp<<"%";
			if (tempsubject==7)
			cout <<"\n Object Oriented Programming(CS-203) : "<<temp<<"%";
			if (tempsubject==8)
			cout <<"\n Discrete Structures(CS-211) : "<<temp<<"%";
			if (tempsubject==9)
			cout <<"\n Circuit Theory(EE-217) : "<<temp<<"%";
			if (tempsubject==10)
			cout <<"\n Digital Logic Design(CS-214) : "<<temp<<"%";
			if (tempsubject==11)
			cout <<"\n Linear Algebra and Ordinar Differential Equations (MS-222) : "<<temp<<"%";
			if (tempsubject==12)
			cout <<"\n Islamic Studies(HS-205) : "<<temp<<"%\n";
			}
			result+=temp;
		}
		if (totalsubjects==0)
		{ result=0; goto skip; }
		result=result/totalsubjects;
skip:
	cout <<"\nOverall Attendance : "<<result<<"%\n\n";
if (state==3)
{ system("pause"); goto end; }
cout <<endl<<"Press r to repeat or any key to return to the main menu... ";
ch=getche();
if (ch=='r' || ch=='R')
{ system("cls");
goto repeat;
}
else
{ system("cls");
return;
}
end:;
}						// search function ends

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

void update_attendance()
{
	system("cls");
char ch,subject,day; int i=1,check=1,tt; string data,ch1;
	cout <<"Update the attendace of students of :"<<endl<<"	1 - First Year (FE)"<<endl<<"	2 - Second Year (SE)";
	cout <<endl<<endl<<"Waiting for instructions..... ";
	ch=getche();
	if (ch=='1' || ch=='2')
		goto start;
	else
	{
		cout <<endl<<"Please enter a valid option..........\n\n";
		system("pause");
		update_attendance();
	}
start:
		again:
		system("cls");
cout <<endl<<endl<<endl<<endl<<"\n		Update the attendance for Day :";
cout <<endl<<"		1 - Monday";
cout <<endl<<"		2 - Tuesday";
cout <<endl<<"		3 - Wednesday";
cout <<endl<<"		4 - Thursday";
cout <<endl<<"		5 - Friday";
cout <<endl<<endl<<"Make your selection.... ";
day=getche();
if (ch=='1')
	{
switch(day) //for FE
{
	case '1':
		system("cls");
		cout<<"Select subject\n\t1. Fundamentals of Computer Engineering (CS-108)\n\t2. Computer Programming (CS-109)\n";
		subject=getche();
		if (subject=='1')
		{ dailyupdate(2); goto again; }
		if (subject=='2')
		{ dailyupdate(1); goto again; }
		break;
	case '2':
		system("cls");
		cout<<"Select subject\n\t1. Pakistan Studies (HS-105)\n\t2. Calculus (MT-114)\n\t3. Functional English (HS-114)\n\t4. Basic Electrical Engineering (EE-120)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(4); goto again; }
		if (subject=='2')
			{ dailyupdate(6); goto again; }
		if (subject=='3')
			{ dailyupdate(5); goto again; }
		if (subject=='4')
			{ dailyupdate(3); goto again; }
		break;
	case '3':
		system("cls");
		cout<<"Select subject\n\t1. Basic Electrical Engineering (EE-120)\n\t2. Calculus (MT-114)\n\t3. Fundamentals of Computer Engineering (CS-108)\n\t4. Computer Programming (CS-109)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(3); goto again; }
		if (subject=='2')
			{ dailyupdate(6); goto again; }
		if (subject=='3')
			{ dailyupdate(2); goto again; }
		if (subject=='4')
			{ dailyupdate(1); goto again; }
		break;
	case '4':
		system("cls");
		cout<<"Select subject\n\t1. Basic Electrical Engineering (EE-120)\n\t2. Pakistan Studies (HS-105)\n\t3. Fundamentals of Computer Engineering (CS-108)\n\t4. Functional English (HS-114)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(3); goto again; }
		if (subject=='2')
			{ dailyupdate(4); goto again; }
		if (subject=='3')
			{ dailyupdate(2); goto again; }
		if (subject=='4')
			{ dailyupdate(5); goto again; }
		break;
	case '5':
		system("cls");
		cout<<"Select subject\n\t1. Basic Electrical Engineering (EE-120)\n\t2. Computer Programming (CS-109)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(3); goto again; }
		if (subject=='2')
			{ dailyupdate(1); goto again; }
		break;
	default:
		return;
} // switch ends
	}

	if (ch=='2')
	{
switch(day) //For SE
{
	case '1':
		system("cls");
		cout<<"Select subject\n\t1. Discrete Structures(CS-211)\n\t2. Digital Logic Design(CS-214)\n\t3. Object Oriented Programming(CS-203)\n";
		subject=getche();
		if (subject=='1')
		{ dailyupdate(8); goto again; }
		if (subject=='2')
		{ dailyupdate(10); goto again; }
		if (subject=='3')
		{ dailyupdate(7); goto again; }
		break;
	case '2':
		system("cls");
		cout<<"Select subject\n\t1. Linear Algebra and Ordinar Differential Equations (MS-222)\n\t2. Digital Logic Design(CS-214)\n\t3. Islamic Studies(HS-205)\n\t4. Discrete Structures(CS-211)\n\t5. Object Oriented Programming(CS-203)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(11); goto again; }
		if (subject=='2')
			{ dailyupdate(10); goto again; }
		if (subject=='3')
			{ dailyupdate(12); goto again; }
		if (subject=='4')
			{ dailyupdate(8); goto again; }
		if (subject=='5')
			{ dailyupdate(7); goto again; }
		break;
	case '3':
		system("cls");
		cout<<"Select subject\n\t1. Linear Algebra and Ordinar Differential Equations (MS-222)\n\t2. Islamic Studies(HS-205)\n\t3. Circuit Theory(EE-217)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(11); goto again; }
		if (subject=='2')
			{ dailyupdate(12); goto again; }
		if (subject=='3')
			{ dailyupdate(9); goto again; }
		break;
	case '4':
		system("cls");
		cout<<"Select subject\n\t1. Object Oriented Programming(CS-203)\n\t2. Digital Logic Design(CS-214)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(7); goto again; }
		if (subject=='2')
			{ dailyupdate(10); goto again; }
		break;
	case '5':
		system("cls");
		cout<<"Select subject\n\t1. Digital Logic Design(CS-214)\n\t2. Discrete Structures(CS-211)\n\t3. Circuit Theory(EE-217)\n\t4. Linear Algebra and Ordinar Differential Equations (MS-222)\n";
		subject=getche();
		if (subject=='1')
			{ dailyupdate(10); goto again; }
		if (subject=='2')
			{ dailyupdate(8); goto again; }
		if (subject=='3')
			{ dailyupdate(9); goto again; }
		if (subject=='4')
			{ dailyupdate(11); goto again; }
		break;
	default:
return;
} // switch ends
	}

}						// Update attendance ends

void check_attendance()
{
	struct requiredstudents
	{
	string name , fname, rollno;
	int presence ;
	};
		int required, result,temp,tempsubject, count=0; char ch ;string data;
	system("cls");
	cout <<"View records for :"<<endl<<"	1 - First Year (FE)"<<endl<<"	2 - Second Year (SE)";
	cout <<endl<<endl<<"Waiting for instructions..... ";
	ch=getche();
	if (ch=='1' || ch=='2')
		goto start;
	else
	{
		cout <<endl<<"Returning to main menu..........\n\n";
		system("pause");
return;
	}

start:
	struct requiredstudents num[numberofstudents];
cout <<endl<<endl<<"Attendance in percent (ex : 60 or 75 or 80) : ";
	cin>>required;
	ifstream datafile;
	for (int roll_no=1 ; roll_no <=numberofstudents ; roll_no++)
	{
		int totalsubjects=6;
		result=0;
		for (int subject=1 ; subject<=6 ; subject++)
		{
			tempsubject=subject;
			if (ch=='2')
				tempsubject+=6;
			temp=overall(roll_no,tempsubject);
			if (temp==786)
			{--totalsubjects; temp=0; }
			result+=temp;
		}
		if (totalsubjects==0)
		{ result=0; goto skip; }
		result=result/totalsubjects;
		skip:
			if (result <= required)
				{
if (ch=='1')
datafile.open("data-FE.txt", ios ::in);
if (ch=='2')
datafile.open("data-SE.txt", ios ::in);
int k=1;
while(k<roll_no)
{
	getline(datafile,data);	getline(datafile,data);	getline(datafile,data);	getline(datafile,data);
	++k;
}

					num[count].presence = result; getline(datafile,data);

						getline(datafile,num[count].rollno);
						getline(datafile,num[count].name);
						getline(datafile,num[count].fname);
										++count;
										datafile.close();
				} // if ends
	}
	for (int j=0 ; j<count;j++)
	{
		system("cls");
				cout <<"Name of Student : "<<num[j].name<<endl<<endl;
				cout <<"Father's name : "<<num[j].fname<<endl<<endl;
				cout <<"Roll number : "<<num[j].rollno<<endl<<endl;
				cout <<"Overall Attendance : "<<num[j].presence<<"%"<<endl<<endl;
				system("pause");
	}
	datafile.close();
}						// Check_Attendance ends

int totalclass(int subject)
{
	string line; int count=0;
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
	
	while (getline(datafile,line))
	{
		++count;
	}
	datafile.close();
	return count;
}

int overall(int rollno,int subject)
{
	unsigned int classes,temp,result=0;
	again:
	classes=totalclass(subject);
if (classes==0)
return 786;
	for (int i=1 ; i<=classes ; i++)
	{
		temp=attendance(rollno,i,subject);
		if (temp==100)
			result++;
	}
	return (100*result/(classes));
}

void dailyupdate(int code)
{
	ofstream tempfile; tempfile.open("temp.txt" , ios ::out);
	string data; int tt; char ch1;
			ifstream datafile;
			if (code==1)
			datafile.open("cp.txt",ios::in);
			if (code==2)
			datafile.open("fce.txt",ios::in);
			if (code==3)
			datafile.open("bee.txt",ios::in);
			if (code==4)
			datafile.open("pst.txt",ios::in);
			if (code==5)
			datafile.open("eng.txt",ios::in);
			if (code==6)
			datafile.open("cal.txt",ios::in);
			if (code==7)
			datafile.open("oop.txt",ios::in);
			if (code==8)
			datafile.open("dst.txt",ios::in);
			if (code==9)
			datafile.open("cth.txt",ios::in);
			if (code==10)
			datafile.open("dld.txt",ios::in);
			if (code==11)
			datafile.open("alg.txt",ios::in);
			if (code==12)
			datafile.open("isl.txt",ios::in);

			cout<<endl<<"Enter class # of subject : ";
			cin >>tt;
			for (int i=1 ; i<tt ; i++)
			{
				getline(datafile,data);
				tempfile <<data<<endl;
			}
			getline(datafile,data);
			for (int i=1 ; i<=numberofstudents ; i++)
			{
system("cls");
		cout <<"\t\tPresent : p\n\t\tAbsent : a"<<endl;
		cout <<"\nRoll #"<<i<<" : ";
		cin >> ch1;
		if (ch1=='p')
			tempfile<<i<<' ';
		else
			tempfile<<'a'<<' ';
			}
			tempfile<<endl;
			while (!datafile.eof())
			{
				getline(datafile,data);
				tempfile<<data<<endl;
			}
			tempfile.close();datafile.close();
				if (code==1)
				remove("cp.txt");  rename("temp.txt" , "cp.txt");
				if (code==2)
				remove("fce.txt");  rename("temp.txt" , "fce.txt");
				if (code==3)
				remove("bee.txt");  rename("temp.txt" , "bee.txt");
				if (code==4)
				remove("pst.txt");  rename("temp.txt" , "pst.txt");
				if (code==5)
				remove("eng.txt");  rename("temp.txt" , "eng.txt");
				if (code==6)
				remove("cal.txt");  rename("temp.txt" , "cal.txt");
				if (code==7)
				remove("oop.txt");  rename("temp.txt" , "oop.txt");
				if (code==8)
				remove("dst.txt");  rename("temp.txt" , "dst.txt");
				if (code==9)
				remove("cth.txt");  rename("temp.txt" , "cth.txt");
				if (code==10)
				remove("dld.txt");  rename("temp.txt" , "dld.txt");
				if (code==11)
				remove("alg.txt");  rename("temp.txt" , "alg.txt");
				if (code==12)
				remove("isl.txt");  rename("temp.txt" , "isl.txt");

}

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
     Default:
		cout<<"Invalid day";
return count;
}