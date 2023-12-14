#include <iostream>
#include<string.h>
using namespace std;
class sll;
class node
{
 int prn;
 char name[40];
 node *next;
public:
 node(int prn,char name[])
 {
 this->prn=prn;
 strcpy(this->name,name);
 next=NULL;
 }
 friend class sll;
};

class sll
{ node *headnd;
 int n;
 public:
 sll()
 { headnd=NULL;
 n=0;
 }
 void create();
 node* getNewNode();
 void display();
 void insertAtBeginning();
 void insertAtEnd();
 void insertAfter();
 void deleteAtFirst();
 void deleteByValue();
 void deleteAtEnd();
 int getCount();
 void bubblesort();
 void concatList(sll &q1);
 void displayRev(node *t);
 bool reverseDisplay()//Only for passing headnd as argument to recursive function
 {
 if(headnd==NULL)
 return false;
 displayRev(headnd);
 return true;
 }
};
void sll::displayRev(node *headnd)
{ if(headnd==NULL)
 return;
 else
 {
 displayRev(headnd->next);
 cout<<"\nPRN NO:"<<headnd->prn<<" Name: "<<headnd->name;
 }
}

void sll::display()
{
 node *current;
 current=headnd;
 if(headnd==NULL)
 {
 cout<<"\nList is Empty";
 return;
 }
 for(current=headnd;current!=NULL; current=current->next)
 {
 cout<<"\n"<<current->prn<<" "<<current->name;
 }//for
}
node* sll::getNewNode()
{ int prn;
 char name[40];
 node *newnd;
 cout<<"\nEnter PRN number: ";
 cin>>prn;
 cout<<"Enter name: ";
 cin>>name;
 newnd=new node(prn,name);
 return newnd;
}
void sll::insertAtBeginning()
{ node *newnd=getNewNode();
 if(headnd==NULL)
 { //empty
 headnd=newnd;
 cout<<"Inserted as first node ";
 }
 else
 { newnd->next=headnd;
 headnd=newnd;
 cout<<"Inserted "<<newnd->name<<" at the beginning."; 
}
n++;
}

void sll::insertAtEnd()
{
 node *newnd=getNewNode();
 node *current;
 if(headnd==NULL)
headnd=newnd;
 else
 {
 //reach at last node
 for(current=headnd;current->next!=NULL; current=current->next)
 {
 continue;
 }//for
 current->next=newnd;
 }//else
 n++;
}

void sll::insertAfter()
{
 int target;
 node *current;
 cout<<"\nEnter PRN No. after which you want to insert\t";
 cin>>target;
 current=headnd;
 int flag=0;
 //Search target
 for(current=headnd,flag=0;current!=NULL; current=current->next)
 {
 if(current->prn==target)
 {
 flag=1;
 break;
 }
 }//for
 if(flag==0)
 {
 cout<<"\n"<<target<<" is not found in the list";
 return;
 }
 node *newnd=getNewNode();
 newnd->next=current->next;
 current->next=newnd;
 cout<<"Inserted...";
 n++;
}

void sll::deleteAtFirst()
{
 node *tempnd;
 if(headnd==NULL)
 {
 cout<<"\nClub is Empty..";
 return;
 }
 else
 {
 tempnd=headnd;
 headnd=headnd->next;
 delete tempnd;
 cout<<"\nPresident deleted..";
 n--;
 }
}

void sll::deleteByValue()
{
 int target,flag;
 node *tempnd,*prev,*current;
 if(headnd==NULL)
 { cout<<"\nClub is Empty..";
 return;
 }
 cout<<"\nEnter PRN no. of member to be deleted: ";
 cin>>target;
 if(headnd->prn==target)
 {//President is to be deleted
 tempnd=headnd;
 headnd=headnd->next;
 delete tempnd;
 cout<<"\nPresident deleted..";
 n--;
 return;
 }//if
 for(current=headnd,flag=0;current->next!=NULL; 
prev=current,current=current->next)
 {
 if(current->prn==target)
 {
 flag=1;
 break;
 }
 }//for
 if(flag==0)
 { cout<<"\n"<<target<<" is not found in the list";
 return;
 }
 if(flag==1)
 { prev->next=current->next;
 delete current;
 cout<<"\nMember with prn no: "<<target<<" is deleted.";
 }
}//deleteByValue

void sll::deleteAtEnd()
{
 node *current,*prev;
 current=headnd;
 if(headnd==NULL)
 {
 cout<<"\nClub is Empty..";
 return;
 }
 if(n==1)
 {
 cout<<"\nOnly one member..";
 return;
 }
 for(current=headnd;current->next->next!=NULL; current=current->next)
 {
 continue;
 }
 delete current->next;
 current->next=NULL;
 cout<<"\nSecretary Deleted.";
 n--;
}
int sll::getCount()
{
 return n;
}


void sll::bubblesort()
{
 int i;
 node *current;
 int tprn;
 char tname[40];
 if(headnd==NULL)
 {
 cout<<"\nList is empty.";
 return ;
 }
 for(i=0;i<n;i++)
 {
 for(current=headnd;current->next!=NULL;current=current->next)
 {
 if((current->prn)>(current->next->prn))
 { //swapping
 tprn=current->prn;
 current->prn=current->next->prn;
 current->next->prn=tprn; 
 strcpy(tname,current->name); 
 strcpy(current->name,current->next->name);
 strcpy(current->next->name,tname);
 }//if
 }//inner for
 }//outer for
 cout<<"\n List is sorted.";
 display();
}


void sll::concatList(sll &l2)
{
 node *current;
 if(l2.headnd==NULL)
 {
 cout<<"\nList 2 is empty";
 return;
 }
 // reach at the end of first LL
 for(current=headnd;current->next!=NULL; current=current->next)
 {
 continue;
 }
 current->next=l2.headnd;
 l2.headnd=NULL; //second list has no exitance now
 cout<<"\nAfter concatenation....";
 display(); 
}
int main() 
{
 sll *l;
 int choice,listno;
 sll l1,l2;
 l=&l1;
 while(1)
 {
 cout<<"\nSelect List\n1.List 1\n2.List 2\nEnter choice\t";
 cin>>listno;
 if(listno==1)
 {
 l=&l1;
 }
 else if(listno==2)
 {
 l=&l2;
 }
 else
 {
 cout<<"\nWrong choice";
 continue;
 }
 while(1)
 {
 cout<<"\n~~~~~~~List "<<listno<<"~~~~~~~";
 cout<<"\n1.Insert President";
 cout<<"\n2.Insert secretary";
 cout<<"\n3.insert after position(member)";
 cout<<"\n4.Display list";
 cout<<"\n5.Delete President";
 cout<<"\n6.Delete Secretary";
 cout<<"\n7.Delete Member";
 cout<<"\n8.Find total No. of members";
 cout<<"\n9.Sort list";
 cout<<"\n10.Combine lists";
 cout<<"\n11.Reverse Display"; 
 cout<<"\n12.Reselect List";

 cout<<"\n13.Exit";
 cout<<"\nENter your choice\t";
 cin>>choice;
 if (choice==12)
 break;
 switch(choice)
 {
 case 1: l->insertAtBeginning();
 break;
 case 2: l->insertAtEnd();
 break;
 case 3: l->insertAfter();
 break;
 case 4: l->display();
 break;
 case 5: l->deleteAtFirst();
 break;
 case 6: l->deleteAtEnd();
 break;
 case 7: l->deleteByValue();
 break;
 case 8: cout<<"\nTotal members"<<l->getCount();
 break;
 case 9:l->bubblesort();
 break;
 case 10:l1.concatList(l2);
 break;
 case 11:l->reverseDisplay();
 break;
 case 13:return 0;
 default:cout<<"Wrong choice";
 }
 }//inner while
}//outer while
}

