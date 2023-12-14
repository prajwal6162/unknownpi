def read(a): 
 n = int(input("How many students\t"))
 print("Input roll numbers in sorted order")
 for i in range(n):
     r=int(input("Enter rollno of student %d\t" %(i+1)))
     a.append(r)
     
 print("Student Info accepted successfully")
 return n


def display(a,n): 
 if(n == 0) :
     print("\nNo records in the database")
 else :
     print("Students Array : ",end=' ')
     for i in range(n) :
         print(a[i],end=" ")
     print("\n")

def ternarysearch(a, lb, ub, target) :
 if (lb <=ub) :
     total=ub-lb+1
     mid1 = lb + total//3
     mid2 = lb + (2*total//3)
 if a[mid1] == target:
     return mid1
 if a[mid2] == target:
     return mid2
 if (target < a[mid1]) :
     return ternarysearch(a,lb, mid1 - 1, target) #search in 1st third
 elif (target > a[mid2]) :
     return ternarysearch(a,mid2 + 1, ub, target) #search in 3rd third
 else :
     return ternarysearch(a,mid1 + 1, mid2 - 1, target) #search in 2nd third
 return -1

while True :
 print ("1-->Accept & Display Students info")
 print ("2-->Ternary Search")
 print ("3-->Exit")
 choice = int(input("Enter your choice\t"))
 if choice==1:
     a = []
     n = read(a)
     display(a,n)
 elif choice==2:
     target=int(input("Enter the roll_no to be searched\t"))
     pos=ternarysearch(a,0,n-1,target)
     if pos==-1:
         print("\tNot found")
     else :
         print("\tFound at position " , pos+1)

 elif choice == 3:
     print ("Program ending...")
     break
 else :
     print ("Wrong choice...Try again")


#time complexity of ternary=0(2*log n to the base 3)=worst=avarage=(best=0(1)
