#include <iostream>
using namespace std;
#define MAX 100
class Stack
{
private:
 int top;
 char data[MAX];
public:
 Stack() // default constructor
 {
 top=-1;
 }
 int isfull()
 {
 return (top==MAX-1);
 }
 int isempty()
 {
 return (top==-1);
 }
 void push(char x)
 {
 data[++top]=x;
 }
 char pop()
 {
 return data[top--];
 }
};//class Stack

class Paranthesis
{
 char expn[MAX];
 Stack s;
 public:
 void read();
 int checkexpn();
};
void Paranthesis::read()
{
 cout<<"\n enter the expression\t";
 cin>>expn;
 cout<<"\nentered expression is"<<expn;
}

int Paranthesis::checkexpn()
{
 int i,flag;
 char ch;
 for(i=0;expn[i]!='\0';i++)
 {
 if(expn[i]=='{'||expn[i]=='['||expn[i]=='(')
 {
 s.push(expn[i]);
 }//if
 }//for
 for(i=0;expn[i]!='\0';i++)
 {
 if(expn[i]=='}'||expn[i]==']'||expn[i]==')')
 {
 if(!s.isempty())
 {
 ch=s.pop();
 if(expn[i]=='}'&&ch!='{')
 return 0;
 if(expn[i]==']'&&ch!='[')
 return 0;
 if(expn[i]==')'&&ch!='(')
 return 0;
 }//if
 else
 return 0;
 }//for
 }
 if(s.isempty())
 return 1; //Expression is well paranthesized
return 0;
}//chechexpn

int main()
{
Paranthesis p1;
p1.read();
int i = p1.checkexpn();
if(i==1)
 cout<<"\nThe expression is well paranthesised";
else
 cout<<"\nThe expression is not well paranthesised";
return 0;
}//main

