def initmat():
	row=int(input("Input no. of rows:"))
	col=int(input("Input no. of column:"))
	mat=[]
	for i in range(0,row):
		temp=[]
		for j in range(0,col):
			tempnum=int(input("Enter number:"))
			temp.append(tempnum)
		mat.append(temp)
	return mat
def add(mat1,mat2):
	if len(mat1)==len(mat2) and len(mat1[0])==len(mat2[0]):
		result=[]
		for i in range(0,len(mat1)):
			temp=[]
			for j in range(0,len(mat1[0])):
				tempvalue=mat1[i][j]+mat2[i][j]
				temp.append(tempvalue)
			result.append(temp)
	return result
def sub(mat1,mat2):
	if len(mat1)==len(mat2) and len(mat1[0])==len(mat2[0]):
		result=[]
		for i in range(0,len(mat1)):
			temp=[]
			for j in range(0,len(mat1[0])):
				tempvalue=mat1[i][j]-mat2[i][j]
				temp.append(tempvalue)
			result.append(temp)
	return result
def transpose(mat):
	result=[]
	for i in range(0,len(mat[0])):
		temp=[]
		for j in range(0,len(mat)):
			tempvalue=mat[j][i]
			temp.append(tempvalue)
		result.append(temp)
	return result
def multi(mat1,mat2):
	result=[]
	tempvalue=0
	for i in range(len(mat1)):
		temp=[]
		for j in range(len(mat2[0])):
			tempvalue=0
			for k in range(0,len(mat2)):
				tempvalue+=mat1[i][k]*mat2[k][j]
				temp.append(tempvalue)
			result.append(temp)
			print(temp)
	return result
def printMat(mat):
	print()
	for i in range(len(mat)):
		for j in range(len(mat[0])):
			print(mat[i][j],end=' ')
		print()
		print()

while True:
                print("1.add\n2.sub\n3.transpose\n4.multip\n5.End")
                choice=int(input("Enter choice no.:"))
                if (choice==1):
                        mat1=initmat()
                        mat2=initmat()
                        result=add(mat1,mat2)
                        printMat(result)
                        break
                if(choice==2):
                        mat1=initmat()
                        mat2=initmat()
                        result=sub(mat1,mat2)
                        printMat(result)
                        break
                if(choice==3):
                        mat1=initmat()
                        result=transpose(mat1)
                        printMat(result)
                        break
                if(choice==4):
                        mat1=initmat()
                        mat2=initmat()
                        result=multi(mat1,mat2)
                        printMat(result)
                if choice==5:
                        break