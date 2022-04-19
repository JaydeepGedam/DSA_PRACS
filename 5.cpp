#include <iostream>
#include <string>
#include <cstring>
#include<math.h>
using namespace std;

int asize = 100;
string stack[100];
int top = -1;
bool flag = 0;

void push(string item)
{
	if(top >= asize-1)
	{
		cout<<"\nStack Overflow.";
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

bool check_number(string item) {
   for (int i = 0; i < item.length(); i++)
	if (isdigit(item[i]) == false)
		return false;
		return true;
}

bool check_alpha(string item) {
   for (int i = 0; i < item.length(); i++)
   if (isalpha(item[i]) == false)
      return false;
      return true;
}

bool is_operator(string symbol)
{
	if(symbol == "^" || symbol == "*" || symbol == "/" || symbol == "+" || symbol =="-")
	 return true;
	
	else
	 return false;
}

string pop()
{
	string item;

	if(top <0)
	{
		printf("stack under flow");
		exit(1);
	}
	else{
		item = stack[top];
		top = top-1;
		return(item);
	}

}

int precedence(string symbol)
{
	if(symbol == "^")
		return 3;
	
	else if(symbol == "*" || symbol == "/")
		return 2;
	
	else if(symbol == "+" || symbol == "-")   
		return 1;
	
	else
		return 0;
	
}

int evaluate(string postf[], int size)
{
  int i=0,op1,op2;
  string item=postf[i]; 
  while(i < size)
  {
  	if(check_number(item) || check_alpha(item) )
  	{
  	 push(item);
  	}
   else
  	{
  	 op2=stoi(pop());
  	 op1=stoi(pop());
  	 
    int resadd = op1+op2;
    int ressub = op1-op2;
    int resmul = op1*op2;
    int resdiv = op1/op2;
    int respow = pow(op1,op2);

    char char_array[2];
    strcpy(char_array, item.c_str());

  	 switch(char_array[0])   
    {
      case '+':          
         push(to_string(resadd));
         break;
      case '-':          
         push(to_string(ressub));
          break;
      case '*':            
         push(to_string(resmul));
          break;
      case '/':           
         push(to_string(resdiv));
          break;
      case '^':
         push(to_string(respow));
         break;
     }
     }
     i++;
	 item = postf[i]; 
    }

    return stoi(stack[top]);
}

int main(){
    string infix_exp[asize], postfix_exp[asize], item;

    cout<<"\nEnter Infix expression : ";
    int i=0;
    while(1){
        cin>>infix_exp[i];
        i++;
        if (cin.get() == '\n') {
            break;
        }
    }
    
    int size = i;

    cout<<"\nInfix expression : ";
    for (int i = 0; i < size; i++)
        cout<<infix_exp[i]<<" ";

        
	int j;
	string x;

	push("(");   
	infix_exp[size] = ")";

	i=0;
	j=0;
	item=infix_exp[i];  

	while(i <= size)
	{
		if(item == "(")
		{
			push(item);
		}
		else if(check_number(item) || check_alpha(item))
		{
			if(check_number(item))
				flag = 1;
			postfix_exp[j] = item;        
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
			 postfix_exp[j] = x; 
			 j++;
			 x=pop();
			}
			push(x);
			

			push(item);             
		}
		else if(item == ")") 
		{
			x = pop();   
			while(x != "(")       
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
		 printf("\nInvalid infix Expression.\n"); 
		 getchar();
		 exit(1);
		}
		i++;


		item = infix_exp[i]; 
	} 

	postfix_exp[j] = '\0';     

	cout<<"\nPostfix expression : ";
    for (int i = 0; i < size; i++)
        cout<<postfix_exp[i]<<" ";      

	if(flag){
	cout<<"\nEvaluated expression is: "<<evaluate(postfix_exp,size);
	}
	
    return 0;
}