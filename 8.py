from drawtree import draw_bst

class node:  
    def __init__(self,data): 
        self.data=data
        self.left = None
        self.right = None

def draw(l):
	draw_bst(l)

def display(root) : 
    if (root != None) : 
        l.append(root.data) 
        display(root.left)  
        display(root.right)  

def postorder(root):
	if(root!=None):
		postorder(root.left)
		postorder(root.right)
		print(root.data,end=" ")

def construct(start, end):  
    list = []  
    if (start > end) : 
        list.append(None)  
        return list
    for i in range(start, end + 1):  
        lefttree = construct(start, i - 1)  
        righttree = construct(i + 1, end)  
        for j in range(len(lefttree)) : 
            left = lefttree[j]  
            for k in range(len(righttree)):  
                right = righttree[k]  
                newnode = node(i)   
                newnode.left = left      
                newnode.right = right
                list.append(newnode)    
    return list



l = []
print("Enter limit n1 to n2 :")
n1 = int(input())
n2 = int(input())
alltrees = construct(n1,n2)  
print("all constructed BSTs are")  
for i in range(len(alltrees)):
	l = []  
	display(alltrees[i])
	draw(l)
	print()
	print("--"*5)
	print() 


print("postorder of all BST's are :")
for i in range(len(alltrees)):  
	postorder(alltrees[i])
	print() 