#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
void Modifyfile(char arr[5][8])
{
int i,j;
ofstream fp;
fp.open("2.txt");//open the file 2.txt and source file , text file are in same folder
for(i=0;i<5;i++)
{
for(j=0;j<8;j++)
fp<<arr[i][j]<<" ";//Modifying the file
fp<<"\n";
}
fp.close();//closing the file
}
void read(char arr[5][8])
{
int i,j;
char x;
FILE *file;
file = fopen( "2.txt", "r" );
i=0;j=0;
while ( ( x = fgetc( file ) ) != EOF )
 {
if(x==' ' )
continue;
else if(x=='\n')
{
i++;
j=0;
}
else
{
arr[i][j++]=x;//Assigning the file elements to a 2D char array
}
}
 fclose(file);
}
void display(char arr[5][8])
{
string line;
ifstream fp;
fp.open("2.txt");
cout<<"------------------"<<endl;
while(getline(fp,line))
{
cout<<line<<endl; //after reading the file dsipaying the grid
}
cout<<"------------------"<<endl;
fp.close();
}
void Transfer(char arr[5][8])
{
int i,j,ct=0;
for(i=0;i<5;i++)
{
for(j=0;j<8;j++)
{
if(arr[i][j]=='T')
{
ct++; //replacing 't' with 'v'
arr[i][j]='V';
}
}
}
for(i=0;i<5;i++)
{
for(j=0;j<8;j++)
{
if(arr[i][j]=='V' && ct>0)
{
ct--; //replacing 'v' with 'o'
arr[i][j]='O';
}
}
}
}
void Checkout(char arr[5][8])
{
int i,j;
for(i=0;i<5;i++)
{
for(j=0;j<8;j++)
{
if(arr[i][j]=='C')
{
arr[i][j]='O'; //checkouts are replaced with 'o'
}
}
}
Modifyfile(arr); //passing array to file
}
int nurseInput()
{
int m;
cout<<"please enter the number of new patients:"<<endl;
cin>>m; //read the new patients
return m; //returnig the new patients through m to no_of patients
}
int ischeck(char arr[5][8])
{
int vacancies=0,i,j;
for(i=0;i<5;i++)
{
for(j=0;j<8;j++)
if(*(*(arr+i)+j)=='V') //checcking the no of vacacies in grid
{
vacancies++;
}
}
return vacancies; //return the vacancies through vacancies to vacancancy
}
int insert_new_patients(char arr[5][8],int vacancy,int no_of_patients)
{
int i,j;
if(no_of_patients>vacancy)//if vacancy is not available
{
cout<<"vacancies are not there"<<endl;
return 0;
}
else
{
for(i=0;i<5;i++)
{
for(j=0;j<8;j++)
{
if(arr[i][j]=='V' && no_of_patients>0) //vacancy is available
{
arr[i][j]='O'; //vacancy is available occupied with 'o'
no_of_patients--;
}
}
}
Modifyfile(arr); //passing the array to file
return 1;
}
}
int main()
{
char arr[5][8];
read(arr); //reading the input file from file
display(arr); //display the inputs
cout<<"Grid loaded"<<endl;
Transfer(arr); //transfers are replaced with vacants
Checkout(arr); //chekcouts are replaced with ocuupied
display(arr); //display after transfers and checkouts are replaced with occupancies and vacancies
cout<<"checkouts and transfers completed"<<endl;
int no_of_patients=nurseInput(); //read the new patients
int vacancy=ischeck(arr); //check how many vacancies
if(insert_new_patients(arr,vacancy,no_of_patients)) //if vacancy is available call the insert_new_patients
{
display(arr);
cout<<"new patients update completed"<<endl;
}
return 0;
}
