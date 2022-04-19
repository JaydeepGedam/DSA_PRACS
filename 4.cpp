#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node* prev;
    int vquantity,fquantity;
    char vegname[30], frname[30];
    struct node* next;
};

struct node* firstNode(struct node* head, char name[20], int quan, int ch){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    if(ch==1){
        temp->prev = NULL;
        strcpy(temp->vegname, name);
        temp->vquantity = quan;
        temp->next = NULL;
    }
    else{
        temp->prev = NULL;
        strcpy(temp->frname, name);
        temp->fquantity = quan;
        temp->next = NULL;
    }
    head = temp;
    return head;
}

struct node* exceptFirstNode(struct node* head, char name[20], int quan, int ch){
    struct node* temp, *tp;
    if(ch==1){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->prev = NULL;
        strcpy(temp->vegname, name);
        temp->vquantity = quan;
        temp->next = NULL;
        tp = head;

        while(tp->next != NULL)
            tp = tp->next;
        tp->next = temp;
        temp->prev = tp;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        temp->prev = NULL;
        strcpy(temp->frname, name);
        temp->fquantity = quan;
        temp->next = NULL;
        tp = head;

        while(tp->next != NULL)
            tp = tp->next;
        tp->next = temp;
        temp->prev = tp;
    }
    return head;
}

struct node* createList(struct node* head,int ch){
    
    int n, quan, i;
    char name[20];
    if(ch==1){
        printf("\nEnter the number of nodes for vegetable list : ");
        scanf("%d", &n);

        if(n==0)
        return head;

        printf("\nEnter the vegetable name for the node 1 : ");
        scanf("%s",name);
        printf("Enter the vegetable quantity for the node 1 : ");
        scanf("%d",&quan);
        head = firstNode(head, name,quan,1);

        for(i=1; i<n; i++){
            printf("\nEnter the vegetable name for the node %d : ", i+1);
            scanf("%s", name);
            printf("Enter the vegetable quantity for the node %d : ", i+1);
            scanf("%d",&quan);
            head = exceptFirstNode(head, name, quan, 1);
        }
    }
    
    else{
        printf("\nEnter the number of nodes for fruit list : ");
        scanf("%d", &n);

        if(n==0)
        return head;

        printf("\nEnter the fruit name for the node 1 : ");
        scanf("%s",name);
        printf("Enter the fruit quantity for the node 1 : ");
        scanf("%d",&quan);
        head = firstNode(head, name,quan,2);

        for(i=1; i<n; i++){
            printf("\nEnter the fruit name for the node %d : ", i+1);
            scanf("%s", name);
            printf("Enter the fruit quantity for the node %d : ", i+1);
            scanf("%d",&quan);
            head = exceptFirstNode(head, name, quan, 2);
        }
    }
    return head;
}

struct node* sortVegList(struct node* head, int ch){
    
    struct node *current = NULL, *index = NULL, *ptr;

    if(ch==1){
        char temp1[30];  
        int temp2;  

        if(head == NULL) {  
            return 0;  
        }  
        else {  
            for(current = head; current->next != NULL; current = current->next) {  

                for(index = current->next; index != NULL; index = index->next) {  

                    if(current->vquantity > index->vquantity) {  
                        temp2 = current->vquantity;  
                        strcpy(temp1, current->vegname);
                        current->vquantity = index->vquantity; 
                        strcpy(current->vegname, index->vegname); 
                        index->vquantity = temp2;  
                        strcpy(index->vegname, temp1);
                    }  
                }  
            }  
        }  
    }
    else if(ch==2){
        char temp1[30];  
        int temp2;   

        if(head == NULL) {  
            return 0;  
        }  
        else {  

            for(current = head; current->next != NULL; current = current->next) {  

                for(index = current->next; index != NULL; index = index->next) {  
                    
                    if(current->vquantity < index->vquantity) {  
                        temp2 = current->vquantity;  
                        strcpy(temp1, current->vegname);
                        current->vquantity = index->vquantity; 
                        strcpy(current->vegname, index->vegname); 
                        index->vquantity = temp2;  
                        strcpy(index->vegname, temp1);
                    }  
                }  
            }  
        }  
    }

    ptr = head;
    printf("\n Vegetable Name\t\t\tVegetable Quantity");
    printf("\n--------------------------------------------------------");
    while(ptr != NULL){
        printf("\n%s\t\t\t\t\t%d",ptr->vegname,ptr->vquantity);
        ptr = ptr->next;
    }
    printf("\n\n");

    return head;
}

struct node* sortFrList(struct node* head, int ch){
    
    struct node *current = NULL, *index = NULL, *ptr;

    if(ch==1){
        char temp1[30];  
        int temp2;   

        if(head == NULL) {  
            return 0;  
        }  
        else {  

            for(current = head; current->next != NULL; current = current->next) { 

                for(index = current->next; index != NULL; index = index->next) {  
                    
                    if(current->fquantity > index->fquantity) {  
                        temp2 = current->fquantity;  
                        strcpy(temp1, current->frname);
                        current->fquantity = index->fquantity; 
                        strcpy(current->frname, index->frname); 
                        index->fquantity = temp2;  
                        strcpy(index->frname, temp1);
                    }  
                }  
            }  
        }  
    }
    else if(ch==2){
        char temp1[30];  
        int temp2;   
        
        if(head == NULL) {  
            return 0;  
        }  
        else {  
            
            for(current = head; current->next != NULL; current = current->next) {  
                
                for(index = current->next; index != NULL; index = index->next) {  
                     
                    if(current->fquantity < index->fquantity) {  
                        temp2 = current->fquantity;  
                        strcpy(temp1, current->frname);
                        current->fquantity = index->fquantity; 
                        strcpy(current->frname, index->frname); 
                        index->fquantity = temp2;  
                        strcpy(index->frname, temp1);
                    }  
                }  
            }  
        }  
    }

    ptr = head;
    printf("\n Fruit Name\t\t\tFruit Quantity");
    printf("\n--------------------------------------------------------");
    while(ptr != NULL){
        printf("\n%s\t\t\t\t\t%d",ptr->frname,ptr->fquantity);
        ptr = ptr->next;
    }
    printf("\n\n");
    
    return head;
}

struct node* optionsOfList(struct node* head){
    while(1){
        int ch,cch,ich,vquan,fquan,dvch,dfch;
        char vname[30], fname[30];
        printf("\n\t\t---Welcome to JD Mall ---\n\n");
        printf("1. Create list. \n2. Insertion in the list. \n3. Display vegetables list. \n4. Display Fruit list. \n5. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                {
                   printf("\nFor which item you wanna create list (1. Vegetables 2. Fruits) :");
                   scanf("%d",&cch);
                   if(cch==1){
                    head = createList(head,1);
                   }
                   else if(cch==2){
                    head = createList(head,2);
                   }
                   else{
                        printf("Invalid Choice... ");
                   }
                   break;  
                }
            case 2:
                {
                    printf("\nIn which list you wanna enter (1. Vegetables 2. Fruits) : ");
                    scanf("%d",&ich);
                    if(ich == 1){
                        printf("Enter the name of vegetable : ");
                        scanf("%s",vname);
                        printf("Enter the quantity of vegetable : ");
                        scanf("%d",&vquan);
                        head = exceptFirstNode(head, vname, vquan, ich);
                    }
                    else if(ich == 2){
                        printf("Enter the name of fruit : ");
                        scanf("%s",fname);
                        printf("Enter the quantity of fruit : ");
                        scanf("%d",&fquan);
                        head = exceptFirstNode(head, fname, fquan, ich);
                    }
                    else{
                        printf("Invalid Choice... ");
                    }
                    break;
                }
            case 3:
            {
                printf("\nIn which order you wanna display vegetables (1. Ascending 2. Descending) : ");
                scanf("%d",&dvch);
                if(dvch == 1){
                    sortVegList(head,1);
                }
                else if(dvch == 2){
                    sortVegList(head,2);
                }
                else{
                    printf("Invalid Choice... ");
                }
                break;
            }

            case 4:
            {
                printf("In which order you wanna display fruits (1. Ascending 2. Descending) : ");
                scanf("%d",&dfch);
                if(dfch == 1){
                    sortFrList(head,1);
                }
                else if(dfch == 2){
                    sortFrList(head,2);
                }
                else{
                    printf("Invalid Choice... ");
                }
                break;
            }

            case 5:
            {
                exit(0);
            }

            default:
            {
                printf("Invalid Choice...");
                break;
            }
        }
    }

}
int main(){
  
    struct node* head = NULL;
    head = optionsOfList(head);

    return 0;
}