def read(a):
 n=int(input("How many students\t"))
 print("Enter percentage of marks of these students now")
 for i in range(n):
     m=float(input())
     a.append(m)

def display(a):
 n=len(a)
 if n==0:
     print("No records...")
 else:
     for i in range(len(a)):
         print(a[i],end=' ')
 print("\n")

def selectionsort(a) :
 n = len(a)
 for pos in range(n-1):
     m = pos
     for i in range(pos + 1, n) :
         if a[i] < a[m] :
             m = i
 #swapping
     temp = a[pos]
     a[pos] = a[m]
     a[m] = temp

def bubblesort(a) :         #timecomplexity o(n square)for both soeteing methods
 n = len(a)
 
 for Pass in range(1,n) :
     for i in range(n-Pass) :
         if(a[i] < a[i+1]) :
             temp = a[i]
             a[i] = a[i+1]

             a[i+1] = temp


 
while True :
 print ("1-->Accept & Display the FE Marks")
 print ("2-->Selection Sort Ascending order")
 print ("3-->Bubble sort Descending order and display top five scores")
 print ("4-->Exit")
 choice = int(input("Enter your choice\t"))
 if (choice==1):
     a = []
     read(a)
     display(a)
 elif (choice==2):
     print("Marks before sorting")
     display(a)
     selectionsort(a)
     print("Marks after sorting")
     display(a)
     n=len(a)
     if n>=5:
         print("------------Top five scores----------")
         for i in range(n-1,n-6,-1):
             print(a[i])
     else:
         print("----------Top scores-----------\n")
         for j in range(n-1,-1,-1):
             print(a[j])
 elif (choice==3):
     print("Marks before sorting")
     display(a)
     bubblesort(a)
     print("Marks after sorting")
     display(a)
     if len(a) >= 5:
         print("Top Five Scores : ")
         for i in range(5) :
             print("\t%.2f"%a[i])
     else :
         print("Top Scorers : ")
         for i in range(len(a)) :
             print("\t%.2f"%a[i])
 elif (choice == 4):
     print ("Program ending...")
     break
 else :
     print ("Wrong choice entered !! Try again")

