#include <iostream>
using namespace std;

int front = -1;
int rear = -1;

int btQueue[100];
int wt[100];
int tat[100];

void enQueue(int samplebt)
{
    if (rear > 100)
    {
        cout << "\nQueue Overflow...";
    }
    else if (rear == -1)
    {
        front++;
        rear++;
        btQueue[rear] = samplebt;
    }
    else
    {
        rear++;
        btQueue[rear] = samplebt;
    }
}

void deQueue()
{
    if (front == -1 || front > rear)
    {
        cout << "\nQueue is empty...";
    }
    else
    {
        front++;
        cout << "\nElement deleted sucessfully...\n";
    }
}

void waitingTime()
{
    for (int i = front; i <= rear; i++)
    {
        wt[i] = 0;
    }
    wt[0] = 0;
    for (int i = front; i <= rear; i++)
    {
        wt[i + 1] = wt[i] + btQueue[i];
    }
}

void turaroundTime()
{
    for (int i = front; i <= rear; i++)
    {
        tat[i] = 0;
    }
    for (int i = front; i <= rear; i++)
    {
        tat[i] = wt[i] + btQueue[i];
    }
}

void display()
{
    cout << "\n\tSr.no.     \tBurst time \tWaiting time    Turnaround time \n";
    cout << "--------------------------------------------------------------------------\n";
    int srno = 1;
    for (int i = front; i <= rear; i++)
    {
        cout << "\t" << srno << "\t\t   " << btQueue[i] << "\t\t    " << wt[i] << "               " << tat[i] << "\n";
        srno++;
    }

    int totalwt = 0, totaltat = 0, size = 0;
    for (int i = front; i <= rear; i++)
    {
        totalwt += wt[i];
        totaltat += tat[i];
        size++;
    }
    int avgwt = totalwt / size;
    int avgtat = totaltat / size;

    cout << "--------------------------------------------------------------------------\n";
    cout << "\t"
         << "Average"
         << "\t\t   "
         << "\t\t    " << avgwt << "               " << avgtat << "\n";
}

void withoutPriority()
{

    int samplebt,n;

    while (1)
    {
        int ch;
        cout << "\nWhich operation you wanna perform \n1. enQueue \n2. deQueue \n3. Display \n4. Exit \nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout<<"\nHow many burst time you wanna enter : ";
            cin>>n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter burst time of process "<<i+1<<" : ";
                cin >> samplebt;
                enQueue(samplebt);
            }
            break;
        }

        case 2:
        {
            deQueue();
            break;
        }

        case 3:
        {
            waitingTime();
            turaroundTime();
            display();
            break;
        }

        case 4:
        {
            exit(0);
        }

        default:
            cout << "Invalid choice....";
            break;
        }
    }
}

void withPriority()
{

    int r;
    while (1)
    {
        int ch;
        cout << "\nWhich operation you wanna perform \n1. enQueue \n2. deQueue \n3. Display \n4. Exit \nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter the number of rows : ";
            cin >> r;
            int temprow = r;
            int tempcol = r + 1;

            int arr[temprow][tempcol];

            for (int i = 0; i < temprow; i++)
            {
                for (int j = 0; j < tempcol; j++)
                {
                    arr[i][j] = 0;
                }
            }

            int position = tempcol - 1;
            int check = temprow - 1;

            int tempbt = 0, pr = 0, my_index = 0, flag = 0;
            int ch;
            while (r > my_index)
            {
                if (flag == 1)
                {
                    cout << "\nDo you wanna continue (1. Yes 2. No) : ";
                    cin >> ch;
                }
                if (flag == 0)
                {
                    ch = 1;
                }
                if (ch == 1)
                {
                here:
                    cout << "\nEnter the burst time : ";
                    cin >> tempbt;
                    cout << "Enter the priority : ";
                    cin >> pr;

                    my_index = arr[pr][position];

                    int cont;
                    if (my_index == r)
                    {
                        cout << "You reached the limit in this priority...";
                        cout << "Do you wanna continue in other priority (1.Yes 2.No) : ";
                        cin >> cont;
                        if (cont == 1)
                        {
                            goto here;
                        }
                    }

                    arr[pr][my_index] = tempbt;
                    arr[pr][position]++;
                    flag = 1;
                }
                else
                {
                    break;
                }
            }

            int size = r * r;
            int tbt[size], kvalue = 0;
            int counter = 0;
            int btsize = 0;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    if (arr[i][j] == 0)
                    {
                        
                    }
                    else
                    {
                        btsize++;
                    }
                    tbt[counter] = arr[i][j];
                    counter++;
                }
            }

            int bt[btsize - 1];
            int ct = 0;
            for (int i = 0; i < size; i++)
            {
                if (tbt[i] == 0)
                {
                    continue;
                }
                enQueue(tbt[i]);
                if (ct < btsize)
                {
                    ct++;
                }
            }
            break;
        }

        case 2:
        {
            deQueue();
            break;
        }

        case 3:
        {
            waitingTime();
            turaroundTime();
            display();
            break;
        }

        case 4:
        {
            exit(0);
        }

        default:
            cout << "Invalid choice....";
            break;
        }
    }
}

int main()
{
    while (1)
    {

        int choice;

        cout << "\nChoose from the following : \n1.Queue without priority. \n2.Queue with priority. \n3.Exit \nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            withoutPriority();
            break;

        case 2:
            withPriority();
            break;

        case 3:
            exit(0);

        default:
            cout << "Invalid Choice.....";
        }
    }

    return 0;
}