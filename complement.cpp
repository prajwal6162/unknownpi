#include <iostream>
using namespace std;
class node
{
int bit;
node *prev;
node *next;
node()
{
 this->bit=0;
 next=prev=NULL;
}
node(int bit)
{
 this->bit=bit;
 next=prev=NULL;
}
friend class dll;
};
class dll
{
 node *headnd;
public:
 dll()
 { headnd=NULL;
 }
 void readnumbers();
 void display();
 void complement1();
 void complement2();
 void add(dll l1,dll l2);
};//class dll
void dll::readnumbers() //DLL is created in this function

{
 node *tempnd,*newnd;
 int n,x;
 cout<<"\nEnter binary number";
 cout<<"\nHow many bits\t";
 cin>>n;
 cout<<"\nEnter those bits\t";
 for(int i=0;i<n;i++)
 {
 cin>>x;
 newnd=new node(x);
 if(headnd==NULL)
 {
 headnd=newnd;
 tempnd=newnd;
 }
 else
 {
 tempnd->next=newnd;
 newnd->prev=tempnd;
 tempnd=newnd;
 }
 }//for
}//readnumbers

void dll::display()
{ if(headnd==NULL)
 { cout<<"empty"; 
 return;
 }
node *current;
for(current=headnd;current!=NULL;current=current->next)
{
 cout<<current->bit<<" ";
}//for
}//display

void dll::add(dll l1,dll l2)
{ // we have to start addition from LSB, so reach at the end of each DLL

 node *current1,*current2,*newnd;
 int sum,carry, b1, b2;
 for(current1=l1.headnd;current1->next!=NULL;current1=current1->next)
 { ;
 }//for
 for(current2=l2.headnd;current2->next!=NULL;current2=current2->next)
 { ;
 }//for
 carry=0;
 while(current1!=NULL || current2!=NULL)
 { if(current1!=NULL)
 b1=current1->bit;
 else
 b1=0;
 if(current2!=NULL)
 b2=current2->bit;
 else
 b2=0;
 sum=b1+b2+carry; //integer addition
 carry=sum/2; //binary carry
 sum=sum%2;//binary addition
 // We need to create a new node for (this) DLL i.e. l4 now
 // to store this sum
 newnd=new node(sum);
 if(headnd==NULL) // headnd of *this i.e. l4 of main()
 { // its first node
 headnd=newnd;
 }//if
 else
 { // insert at the beginning
 newnd->next=headnd;
 headnd->prev=newnd;
 headnd=newnd;
 }
 // now go for next bits
 if(current1!=NULL)
 current1=current1->prev;
 if(current2!=NULL)
 current2=current2->prev;

 }//while
 //Its over
 // But if carry is 1, we have to insert a new node at the
 // beginning which contains that carry
 if(carry==1)
{
 newnd=new node(carry);
 newnd->next=headnd;
 headnd->prev=newnd;
 headnd=newnd;
 }//if
}//add

void dll::complement1()
{
 node *current;
 for(current=headnd;current!=NULL;current=current->next)
 { //simply change 1 to 0 and 0 to 1
 if(current->bit==1)
 current->bit=0;
 else
 current->bit=1;
 }
 display();
}//complement


void dll::complement2()
{
 // 2's complement is 1's complement +1
 node *current,*newnd;
 int sum,carry;
 // reach to last node
 // as it contains LSB
 for(current=headnd;current->next!=NULL;current=current->next)
 {
 ;
 }//for
 // we have to add 1
 carry=1;
 for( ;current!=NULL;current=current->prev)// going from LSB to MSB
 {
 sum=current->bit+carry;
 carry=sum/2;
 sum=sum%2;
 current->bit=sum;
 }//for
 //Its over
 // But if carry is 1, we have to insert a new node at the
 // beginning which contains that carry
 if(carry==1)
 {
 newnd=new node(carry);
 newnd->next=headnd;
 headnd->prev=newnd;
 headnd=newnd;
 }
 display();
}//complement2


int menu()
{ int choice;
 cout<<"\nMenu";
 cout<<"\n1.Enter a binary number";
 cout<<"\n2.Display the binary number";
 cout<<"\n3.Display 1's complement and 2's complement";
 cout<<"\n4.Addition of 2 binary numbers";
 cout<<"\n5.Exit";
 cout<<"\nEnter your choice\t";
 cin>>choice;
 return choice;
}//menu
int main()
{ dll l1,l2,l3,l4;
 int choice;
 while(1)
 {
 choice=menu();
 switch(choice)
 {
 case 1: // Read a binary number
 l1=dll(); // calling constructor explicitly
 l1.readnumbers();
 break;
 case 2: //Display the binary number
 cout<<"\nThe binary number is\t";
 l1.display();
 break;
 case 3: //Display 1's complement and 2's complement
 cout<<"\nGiven binary number\t";
 l1.display();
 cout<<"\n 1's complement is\t";
 l1.complement1();
 cout<<"\nAnd 2's complement is\t";
 l1.complement2();
 break;
 case 4: //Addition of 2 binary numbers
 cout<<"\nFirst binary number\n";

 l2.readnumbers();
 cout<<"\nSecond binary number\n";
 l3.readnumbers();
 l4.add(l2,l3);
 // Here l4 will be new DLL created
 // It will referred as *this in the add function
 cout<<"\nAddition of two binary numbers is";
 l4.display();
 break;
 case 5: cout<<"\n Program ending.....";
return 0;
 default: cout<<"\nWrong choice...";
}//switch
}//while
}//main


