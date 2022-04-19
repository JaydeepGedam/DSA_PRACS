#include <iostream>
using namespace std;

int main(){
    int op;
    cout<<"\n1. Linear Search \n2. Binary Search \n3. Fibonacci Search"<<"\n\nWhich opearation you wanna perform  : ";
    cin>>op;

    switch(op){
        case 1: 
        {
            int size;
            cout << "\nEnter the size of array : ";
            cin >> size;

            int arr[size];

            cout << "Enter the elements inside the array : ";
            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            int search;
            cout << "Enter the number which you wanna search : ";
            cin >> search;

            int count = 0;
            int temp = 0;
            int i=0;
            for ( i = 0; i < size; i++)
            {

                if (arr[i] == search)
                {

                    temp = 1;

                    cout << "\nElement is found at location " << i+1<< endl;
                    break;
                }
                count++;
            }
            

            if (temp == 0)
            {
                cout << "\nElement not found."<<endl;
                cout<<"count is "<<i<<endl<<endl;

            }
            else{
                cout << "The count is " <<i+1<<endl<<endl;

            }
            break;
        }
        case 2:
        {
            int n;
            cout<<"\nEnter the size of array : ";
            cin>>n;

            int arr[n];
            cout<<"Enter the elements inside the array (in ascending order) : ";
            for(int i=0; i<n; i++){
                cin>>arr[i];
            }

            int key;
            cout<<"Enter the number which you wanna search : ";
            cin>>key;

            int start=0, end=n;
            int count=0;

            while(start<=end){
                int mid = (start+end)/2;
                count++;
                if(arr[mid] == key){
                    cout<<"\nElement is present at position "<<mid+1<<"."<<endl;
                    break;
                }
                else if(abs(arr[mid]) > abs(key)){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }

            if(start>end)
                cout<<"Element not found."<<endl;

            cout<<"Count is "<<count<<endl<<endl;
            break;
        }
        

        case 3:
        {
            int size, i;
            cout << "\nEnter the total number of elements : ";
            cin >> size;

            int arr[size];
            cout << "Enter elements in array (in ascending order) : ";
            for (i = 0; i < size; i++)
            {
                cin >> arr[i];
            }

            int search;
            cout << "Enter element to be searched : ";
            cin >> search;

            int fbK2 = 0;
            int fbK1 = 1;
            int fbK = fbK2 + fbK1;

            int offset = -1;

            int flag = 0;
            while (fbK < size)
            {
                fbK2 = fbK1;
                fbK1 = fbK;
                fbK = fbK2 + fbK1;
            }
            int count = 0;
            while (fbK > 1)
            {
                count++;
                int i = min(offset + fbK2, size - 1);

                if (arr[i] < search)
                {
                    fbK = fbK1;
                    fbK1 = fbK2;
                    fbK2 = fbK - fbK1;
                    offset = i;
                }
                
                else if (arr[i] > search)
                {
                    fbK = fbK2;
                    fbK1 = fbK1 - fbK2;
                    fbK2 = fbK - fbK1;
                }
                else
                {
                    cout << "\nElement found at position " << i + 1 << endl;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                cout <<"\nElement not found." << endl;
            }

            cout<<"Count is "<<count<<endl<<endl;
            break;
        }

        default:
            cout<<"\nInvalid Operation......"<<endl<<endl;
    
    }
    return 0;
}

