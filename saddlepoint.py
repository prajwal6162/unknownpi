def read(m):
 r=int(input("How many rows\t"))
 c=int(input("How many columns\t"))
 print("Enter the elements of now\n")
 for i in range(r):
     row = []
     print("\tRow Number ", i+1)
     for j in range(c):
         x=int(input())
         row.append(x)
     m.append(row)
 
def display(m,r,c):
 for i in range(r):
     for j in range(c):
         print(m[i][j],end=" ")
     print()
     
def saddle_point(m,r,c): 
 count=0;
 for i in range(r): #to find minimum element of the row
     min=m[i][0]
     posc=0
     for j in range(c):
         if m[i][j] < min:
             min=m[i][j];
             clm=j;


# So, we got minimum in row i and column=posc
# Now, find largest element in column=posc
     max=m[0][posc]
     for k in range(r):
         if (m[k][posc]>max):
             max=m[k][posc]
             posr=k
     if (posr==i):
         print(min,"is the saddle point in the given matrix")
         print("It is row number", i, " and column number ", posc)
         return
 print("saddle point found in the given matrix") 
m=[]
read(m)
r=len(m)
c=len(m[0])
display(m,r,c)
saddle_point(m,r,c)
