#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int empid;
    char empname[20];
    struct node *next;
};
struct node *head;

void createList(int n);
void insertNode(int, char[]);
void deleteNode();
void displayData();

int main()
{
    int n;
    cout<<"\nHow many employee's data you wanna enter : ";
    cin>>n;
    createList(n);
    displayData();
    while (1)
    {
        int choose;
        cout<<"\n\n\n\t ***** Opreations Available ***** \n\nChoose Operation\n1. Insert Employee Data\n2. Delete Employee Data\n3. Display Employee Data \n4. Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choose;

        switch (choose)
        {
            case 1:
            {
                int ch, empid;
                char empname[20];
                cout<<"\nEnter the id of employee : ";
                cin>>empid;
                cout<<"Enter the name of employee : ";
                cin>>empname;

                insertNode(empid, empname);
                break;
            }
            case 2:
            {
                deleteNode();
                break;
            }
            case 3:
            {
                displayData();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid choice....";
                break;
            }
        }
    }
}
void createList(int n)
{
    struct node *newnode, *temp;
    int empid;
    char empname[20];

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        cout<<"Unable to allocate memory";
        exit(0);
    }
    cout<<"\nEnter the id of employee 1: ";
    cin>>empid;
    cout<<"Enter the name of employee 1: ";
    cin>>empname;

    head->empid = empid;
    strcpy(head->empname, empname);
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= n; i++)
    {
        
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            cout<<"Unable to allocate memory";
            exit(0);
        }

        cout<<"\nEnter the id of employee "<<i<<" : ";
        cin>>empid;
        cout<<"Enter the name of employee "<<i<<" : ";
        cin>>empname;

        int flag = 0;
        struct node *temp1 = head;
        while (temp1 != NULL) {
            if(temp1->empid == empid){
                flag = 1;
                break;
            }
            temp1 = temp1->next;
        }

        switch (flag)
        {
        case 0:
        {
            newnode->empid = empid;
            strcpy(newnode->empname, empname);
            newnode->next = NULL;

            temp->next = newnode;
            temp = temp->next;
            break;
        }
        case 1:
        {
            cout<<"\nYou can't insert duplicate data.\n";
            break;  
        }
        default:
            break;
        }
        
    }
}
void displayData()
{
    struct node *temp;
    if (head == NULL)
    {
        cout<<"EMPTY LIST";
        exit(0);
    }
    cout<<"\nEmployee ID\tEmployee Name\n------------------------------";
    temp = head;
    while (temp != NULL)
    {
        cout<<endl<<temp->empid<<"\t\t"<<temp->empname;
        temp = temp->next;
    }
}

void insertNode(int empid, char empname[])
{
    struct node *temp;
	struct node *newp=(struct node *)malloc(sizeof(struct node));
	newp->empid = empid;
	strcpy(newp->empname, empname);
	newp->next=NULL;
	
	
	int key = empid;
	if(head==NULL || empid < head->empid)
	{
        newp->next=head;
        head=newp;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL && temp->next->empid < key)
		{
			temp=temp->next;
		}
		newp->next=temp->next;
		temp->next=newp;
	
	}
    displayData();
}

void deleteNode()
{
    int roll;
    cout<<"\nEnter the employee id of employee to be deleted : ";
    cin>>roll;
    struct node *prev, *curr;
    while (head->empid == roll)
    {
        prev = head;
        head = head->next;
        free(prev);
        cout<<"Data deleted successfully\n";
        displayData();
        return;
    }

    prev = NULL;
    curr = head;
    while (curr != NULL)
    {
        if (curr->empid == roll)
        {
            if (prev != NULL)
            {
                prev->next = curr->next;
                free(curr);
                cout<<"Data deleted successfully\n";
                displayData();
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    cout<<"Employee id not found..\n";
}