def read(m,r,c):
 print("Enter the elements of the matrix")
 for i in range(r):
     row = []
     print("\tRow Number ", i+1)
     for j in range(c):
         x=int(input())
         row.append(x)
     m.append(row)
def display(m):
    r=len(m)
    c=len(m[0])
    for i in range(r):
        for j in range(c):
            print(m[i][j],end=" ")
        print()

def transpose(m):
 r=len(m)
 c=len(m[0])
 for i in range(r):
     for j in range(c):
         print(m[j][i],end=" ")
     print()

def operation(m1,m2,ch):
 m3=[]
 r1=len(m1)
 c1=len(m1[0])
 r1=len(m2)
 c2=len(m2[0])
 if r1!=r2 or c1!=c2:
     print("The no. of rows & columns must be equal of both the matrices.Please try again.")
     return
 for i in range(r1):
     row=[]
     for j in range(c1):
         if ch=="+":
             x=m1[i][j]+m2[i][j]
         else:
             x=m1[i][j]-m2[i][j]
         row.append(x)
     m3.append(row)
 return m3

def mult(m1,m2):
 m3=[]
 r1=len(m1)
 c1=len(m1[0])
 r1=len(m2)
 c2=len(m2[0])
 if c1!=r2:
     print("Sorry... multiplication can not be done...Please try again.")
     return
 for i in range(r1):
     row=[]
     for j in range(c2):
         sum=0
         for k in range(c1):
             sum=sum+m1[i][k]*m2[k][j]
         row.append(sum)
     m3.append(row)
 return m3


#Asking user the operation he wants to perform
m1=[]
m2=[]
print("First matrix: ")
r1=int(input("How many rows\t"))
c1=int(input("How many columns"))
read(m1,r1,c1)
print("Second matrix: ")
r2=int(input("How many rows\t"))
c2=int(input("How many columns"))
read(m2,r2,c2)
while True:
 print("1.-->Display both matrices")
 print("2.-->Addition of two matrices")
 print("3.-->Subtraction of two matrices")
 print("4.-->Multiplication of two matrices")
 print("5.-->Transpose of the matrix")
 print("6.-->Exit")
 choice=int(input("Enter your choice\t"))

 #Addition
 if choice==1:
     print("First matrix is ")
     display(m1)
     print("Second matrix is ")
     display(m2)
 elif choice==2:
     m3=operation(m1,m2,"+")
     print("Addition of two matrices is")
     display(m3)
 elif choice==3:
     m3=operation(m1,m2,"-")
     print("Subtraction of two matrices is")
     display(m3)
 elif choice==4:
     m3=mult(m1,m2)
     print("Multiplication of two matrices is")
     display(m3)
 elif choice==5:
     print("Transpose of first matrix is ")
     transpose(m1)
     print("Transpose of second matrix is ")
     transpose(m2)
 elif (choice == 6):
     print ("Program ending...")
     break
 else :
     print ("Wrong choice entered !! Try again")
