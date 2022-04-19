#include<stdio.h>
#include<stdlib.h>

struct node
{
	float coeff;
	int expox;
	int expoy;
	int expoz;
	struct node* link;
};

struct node *insert(struct node* head,float co,int x,int y,int z)
{
	struct node* temp;
	struct node* newP=malloc(sizeof(struct node));
	newP->coeff=co;
	newP->expox=x;
	newP->expoy=y;
	newP->expoz=z;
	newP->link=NULL;
	
	if(head == NULL || (x > head->expox && y > head->expoy && z > head->expoz))
	{
	newP->link = head;
	head=newP;
	}
	else
	{
		temp = head;
		while(temp->link != NULL && (temp->link->expox >= x || temp->link->expoy >= y || temp->link->expoz >= z))
		{
			temp = temp->link;
		}
		newP->link = temp->link;
		temp->link = newP;
	}
	return head;
}

void printRes(struct node* head)
{
	if(head == NULL)
    {
	    printf("\nAddition not possible");
        exit(0);
    }
    else{
        struct node* temp = head;
        while(temp != NULL)
        {
            printf("(%.1fx^%d y^%d z^%d)",temp->coeff,temp->expox,temp->expoy,temp->expoz);
            temp = temp->link;
            if(temp!=NULL)
            {
                printf(" + ");
            }
            else{
            printf("\n");
            }
        }
    }
}

void polyadd(struct node* head1,struct node* head2)
{
	struct node* ptr1=head1;
	struct node* ptr2=head2;
	struct node* head3=NULL;

	int flag;
	while(ptr1 != NULL){
		flag=0;
		ptr2=head2;
		while(ptr2 != NULL){
			if(ptr1->expox == ptr2->expox && ptr1->expoy == ptr2->expoy && ptr1->expoz == ptr2->expoz){
				head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expox,ptr1->expoy,ptr1->expoz);
				flag = 1;
			}
			ptr2=ptr2->link;
		}
		if(flag==0){
			head3=insert(head3,ptr1->coeff,ptr1->expox,ptr1->expoy,ptr1->expoz);
		}
		ptr1=ptr1->link;
	}

	while(ptr2 != NULL){
		flag=0;
		ptr1=head1;
		while(ptr1 != NULL){
			if(ptr1->expox == ptr2->expox && ptr1->expoy == ptr2->expoy && ptr1->expoz == ptr2->expoz){
				flag = 1;
			}
			ptr1=ptr1->link;
		}
		if(flag==0){
			head3=insert(head3,ptr2->coeff,ptr2->expox,ptr2->expoy,ptr2->expoz);
		}
		ptr2=ptr2->link;
	}


	printRes(head3);
	
}


struct node *create(struct node *head)
{
	int n,i,x,y,z;
	float co;
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the coefficient for the node %d : ",i+1);
		scanf("%f",&co);
		printf("Enter the exponent of x for the node %d : ",i+1);
		scanf("%d",&x);
        printf("Enter the exponent of y for the node %d : ",i+1);
		scanf("%d",&y);
        printf("Enter the exponent of z for the node %d : ",i+1);
		scanf("%d",&z);
		
		head=insert(head,co,x,y,z);
	}
	return head;	
}

int main()
{
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	
	printf("\nEnter the values of Polynomial 1 \n\n");
	head1=create(head1);
	printf("\nPolynomial 1 is \n");
	printRes(head1);
	printf("\n\nEnter the values of Polynomial 2\n\n");
	head2=create(head2);
	printf("\nPolynomial 2 is \n");
	printRes(head2);
	
	
    printf("\n\nAddition of polynomial is \n");
	polyadd(head1,head2);


	return 0;
}