#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int acc_no;
    string name;
    float bal;
    node *next;
};
node *head=NULL;
node *searchh(int acc)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        if( (ptr->acc_no)==acc)
            return ptr;

            ptr=ptr->next;
    }

    return ptr;
}
void deletes(int acc)
{
    node *ptr=head;
    node *preptr=ptr;
    while(ptr->acc_no!=acc)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    node *temp=ptr;
    preptr->next=temp->next;
    delete(temp);
}
void open()
{
    node *n;
    n=new struct node;
    cout<<"\nEnter the account number and account holder's name: ";
    cin>>(n->acc_no)>>(n->name);
    n->bal=0;
    n->next=0;
    if(head==NULL)
        head=n;
    else
    {
        n->next=head;
        head=n;
    }
}
void withdraw()
{
    int acc;
    float am;
    node *ptr;
    cout<<"\nEnter the account number: ";
    cin>>acc;
    ptr=searchh(acc);
    cout<<"\nEnter the amount to be withdrawn: ";
    cin>>am;
    if(ptr!=0){
    if(am>ptr->bal)
        cout<<"\nNot enough balance!";
    else
    {
        ptr->bal-=am;
        cout<<"\nWithdrawal was successful!\n";
    }
    }
    else{
          cout<<"\nNo such account exists!";
    }
}
void deposit()
{
    int acc;
    float am;
    node *ptr;
    cout<<"\nEnter the account number: ";
    cin>>acc;
    ptr=searchh(acc);
    if(ptr!=0){
    cout<<"\nEnter the amount to be deposited: ";
    cin>>am;
    (ptr->bal)+=am;
     cout<<"\nDeposition was successful!\n";
    }
    else
        cout<<"\nNo such account exists!\nDeposition was unsuccessful!\n";
}
void balance()
{
    int acc;
    node *ptr;
    cout<<"\nEnter the account number: ";
    cin>>acc;
    ptr=searchh(acc);
    if(ptr==NULL)
    {
       cout<<"\nNo such account exists!";
        return;
    }
    else
    {
        cout<<"\nThe balance in this account is: "<<ptr->bal<<endl;
    }
}
void close()
{
    int acc;

    cout<<"\nEnter the account number: ";
    cin>>acc;
    node *ptr=searchh(acc);
    if(ptr!=0)
    {deletes(acc);cout<<"\nThe account has been closed!\n";
    }
    else
    {
        cout<<"\nNo such account exists!";

    }
}
int main()
{
    int x,y=1;
    cout<<"------------- WELCOME TO BANKING APPLICATION ----------------"<<endl;
    do
    {
        cout<<endl;
        cout<<endl;
        cout<<"1.Open an account\t2.Withdraw\t\t3.Deposit"<<endl;
        cout<<"4.Check balance\t\t5.Close an account\t6.Exit"<<endl;
        cout<<"\nSelect an option:";
        cin>>x;
        switch(x)
        {
        case 1:
            {
                open();
                cout<<"\nThe account has been made!\n";
                break;
            }
        case 2:
            {
                withdraw();
                break;
            }
        case 3:
            {
                deposit();

                break;
            }
        case 4:
            {
                balance();
                break;
            }
        case 5:
            {
                close();
                 break;
            }
        case 6:
            {
                y=0;
                break;
            }
        default:
            {
                cout<<"\nInvalid option!!";
                break;
            }
        }
    }while(y==1);
    return 0;
}

