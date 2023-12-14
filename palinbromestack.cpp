#include <iostream>
using namespace std;
#define MAX 100

class Stack
{ int top;
 int data[MAX];
 public:
 Stack()
 {
 top=-1;
 }
 void push(int ch)
 {
data[++top]=ch;
 }
 int isfull()
 {
return(top==MAX-1);
 } 
 int pop()
 {
 return data[top--];
 }
 int isempty()
 {
 return(top==-1);
 }
};//class Stack 

void reverse(char *str)
{
 Stack s;
 int i;
 char ch;
 for(i=0;str[i]!=NULL;i++)
 {
 if(!s.isfull())
 s.push(str[i]);
 else
{
 cout<<"Stack overflow...";
 return;
 }
 }//for
 cout<<"\n\tReverse string is\t";
 while(!s.isempty())
 {
 ch=s.pop();
 cout<<ch;
 }
}//reverse

void check(char *str)
{
 Stack s;
 char ch;
 int i,flag;
 // push all characters in the stack s
 for(i=0;str[i]!=NULL;i++)
 {
 if(!s.isfull())
 s.push(str[i]);
 else
{
 cout<<"Stack overflow...";
 return;
 }
 }//for
 for(i=0,flag=0;str[i]!=NULL;i++)
 {
 if(str[i]!=s.pop())
 {
 flag=1;
 break;
 }//if
 }//for
if(flag)
cout<<"\nNot a palindrome";
else
cout<<"\nIt is a palindrome";
}//main

int main()
{
 char str[MAX];
 cout<<"\n\tEnter a string\t";
 cin>>str;
 reverse(str);
 check(str);
return 0;
}//main
