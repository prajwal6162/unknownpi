#Display word with the longest length
def findlongestword(str):
 #split str into a list
 l=str.split()
 longest=""
 max=0
 for e in l:
     if len(e)>max:
         max=len(e)
         longest=e
 return longest

#Determine the frequency of occurrence of particular character in the string
def countch(str,ch):
 cnt = 0
 for i in range(len(str)):
     if ch == str[i]:
         cnt = cnt + 1
 return cnt

#Check whether the given string is palindrome or not
def palindrome(str):
 length = len(str)
 i=0
 j=length-1
 flag=False
 while i<j:
     if str[i] != str[j]:
         return "Not Palindrome" #this result obtained inside-loop
     i=i+1
     j=j-1
 return "Palindrome" #this result obtained outside-loop

#Display index of first appearance of the substring
def substring(str, sub):
 l_str=len(str)
 l_sub=len(sub)
 for i in range(l_str-l_sub+1):
         #For current index i, check for pattern match
     flag=False
     for j in range (l_sub):
         if str[i + j] != sub[j]:
             flag=True #Mismatch
             break # So, stop
     if flag==False:
         return i # found
 return -1 #not found

def occwords(str):
 #split it into a list
 l=str.split()
 arr=[ 1 for i in range(len(l))] # arr is used as array of counters
 for i in range(len(l)):
     for j in range (i+1, len(l)):
         if l[i]==l[j] and arr[j]!=-1:
             arr[i]=arr[i]+1 # repeated, so add 1 to counter
             arr[j]=-1 # should not be considered again
 for i in range (len(arr)):
     if arr[i]!=-1:
         print(l[i], arr[i])





def menu():
 print("1-->To display word with the longest length")
 print("2-->To determine the frequency of occurrence of particular character in the string")
 print("3-->To check whether the given string is palindrome or not")
 print("4-->To display index of first appearance of the substring")
 print("5-->To count the occurance of each word in a given string")
 print("6-->Exit")
 choice = int(input("Enter your choice:"))
 return choice

while True:
 choice=menu()
 if choice== 1:
     print("To display word with the longest length")
     str=input("Enter a string\t")
     longestword=findlongestword(str)
     print("Longest string is", longestword)
     print("Its length is", len(longestword))
 elif choice == 2:
     print("To determine the frequency of occurrence of particular character in the string: ")
     str = input("Enter the string\t")
     ch = input("Enter the character\t")
     cnt=countch(str,ch)
     print("The occurance of ",ch," is ",cnt)
 elif choice == 3:
     print("To check whether the given string is palindrome or not: ")
     str = input("Enter a string\t")
     result=palindrome(str)
     print("The string is ", result)
 elif choice == 4:
     print("To display index of first appearance of the substring: ")
     str = input("Enter the string\t")
     sub = input("Enter the substring\t")
     pos=substring(str,sub)
     if pos==-1:
         print("Not found")
     else:
         print("Found at index = ",pos)
 elif choice == 5:
     print("To count the occurance of each word in a given string: ")
     str = input("Enter the string:")
     occwords(str)
 elif (choice == 6):
     print("Program ending...")
 break
