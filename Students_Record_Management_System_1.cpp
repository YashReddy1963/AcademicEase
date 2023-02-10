#include<iostream>
using namespace std;

class in_out{//in_out==(for input && output)
    public:
    int id, m1,m2,m3,m4,m5;
    char f_name[20] , l_name[20]; //f_name==first_name , l_name==last_name;
    void input()//For inserting the records
        {
            cout<<"        ID:";
            cin>>id;
            cout<<"First Name:";
            cin>>f_name;
            cout<<" Last Name:";
            cin>>l_name;
            cout<<"Enter Marks for below subjects:(out of 100)"<<endl;
            cout<<"Computer Network:";
            cin>>m1;
            cout<<"             C++:";
            cin>>m2;
            cout<<"             SQL:";
            cin>>m3;
            cout<<"  Data Structure:";
            cin>>m4;
            cout<<"   Web Designing:";
            cin>>m5;
        }

    void display()//For displaying records
        {
        cout<<"             ID :"<<id<<endl;
        cout<<"     Frist Name :"<<f_name<<endl;
        cout<<"      Last Name :"<<l_name<<endl;
        cout<<"Computer Network:"<<m1<<endl;
        cout<<"             C++:"<<m2<<endl;
        cout<<"             SQL:"<<m3<<endl;
        cout<<"  Data Structure:"<<m4<<endl;
        cout<<"   Web Designing:"<<m5<<endl;
        }
};

class up_rd: public in_out//up_rd==(Claculating percentage && updating records) 
{
    public:
    void up_id(){//up_id==(updating id)
        cout<<"Enter the new ID of student:"<<endl;
        cin>>id;
        display();
    }   
    void up_f_name(){//up_f_name==(first name)
        cout<<"Enter the new First name of the student:"<<endl;
        cin>>f_name;
    }
    void up_l_name(){//up_l_name==(last name)
        cout<<"Enter the new First name of the student:"<<endl;
        cin>>l_name;
    }
    void up_m1(){//up_m1==(for computer network)
        cout<<"Enter the marks for Computer Network:"<<endl;
        cin>>m1;
    }
    void up_m2(){//up_m2==(C++)
        cout<<"Enter the marks for C++:"<<endl;
        cin>>m2;
    }
    void up_m3(){//up_m3==(SQL)
        cout<<"Enter the marks for SQL:"<<endl;
        cin>>m3;
    }
    void up_m4(){//up_m4==(Data Structure)
        cout<<"Enter the marks for Data Structure:"<<endl;
        cin>>m4;
    }
    void up_m5(){//up_m5==(Web designing)
        cout<<"Enter the marks for Web Designing"<<endl;
        cin>>m5;
    }
};

class screen{
    public:
    void clearscreen(){
       cout<<"\033[2J\033[1;1H";
    }
};

int main()
{
    int j,n;//j==for deleting records && n==number of records
    int enter, del=0;// enter==exiting particular section && del==to check wheather the record is deleted or not
    up_rd obj[10];
    screen s;
    login_page: //login_page label
    s.clearscreen();
    cout<<"STUDENT RECORD MANAGEMENT SYSTEM"<<endl;
    cout<<endl<<"LOGIN PAGE"<<endl;
    cout<<"1.Admin"<<endl<<"2.Student"<<endl<<"3.Exit"<<endl;
    int choice1;
    cin>>choice1;
         switch(choice1)//Switch case for login page
        {
            case 1:
                password: //password label
                cout<<"Enter the password:"<<endl;
                int password;
                cin>>password;
                if(password==2023)
                {
                    admin_page: //Admin page label
                    s.clearscreen();
                    cout<<"You have entered into the Admin Page:"<<endl;
                    cout<<"What do you want to perform:"<<endl;
                    cout<<"1.Add Records(Ignore if already added)\n2.Edit Records\n3.View Records\n4.Delete Specific Record\n5.Exit"<<endl;   
                    int choice2;
                    cin>>choice2;
                        switch(choice2)
                        {
                        case 1:
                            s.clearscreen();
                            cout<<"How many records do you want to enter:[YOU CAN ADD UPTO 10 RECORDS]"<<endl;
                            cin>>n; 
                            for(int i=1 ; i<=n ;i++)
                            {
                                cout<<"Enter the record of "<<i<<" student:"<<endl;
                                obj[i].input();
                            }
                            cout<<"Enter 1 to exit:"<<endl;
                            cin>>enter;
                            if(enter==1)
                                goto admin_page;       
                            break;  
                        case 2:
                            s.clearscreen();
                            cout<<"Enter the Id of student whose record you want to change:"<<endl;
                            int stud_id;
                            cin>>stud_id; // For comparing the I'd of student
                            for(int i=0 ; i<n ; i++)
                            {
                                if(obj[i].id == stud_id)
                                {
                                    obj[i].display();
                                    update: //update label
                                    cout<<"What changes you want to make:"<<endl;
                                    cout<<"1.Id\n2.First name\n3.Last name\n4.Marks\n5.Exit"<<endl;    
                                    int choice3; //To choose the the part to edit
                                    cin>>choice3;
                                    switch(choice3)
                                        {
                                            case 1:
                                                s.clearscreen();
                                                obj[i].up_id();
                                                cout<<"Enter 1 to exit:"<<endl;
                                                cin>>enter;
                                                if(enter==1)
                                                    goto update;
                                                break;
                                            case 2:
                                                s.clearscreen();
                                                obj[i].up_f_name();
                                                obj[i].display();
                                                cout<<"Enter 1 to exit:"<<endl;
                                                cin>>enter;
                                                if(enter==1)
                                                    goto update;
                                                break;
                                            case 3:
                                                s.clearscreen();
                                                obj[i].up_l_name();
                                                obj[i].display();
                                                cout<<"Enter 1 to exit:"<<endl;
                                                cin>>enter;
                                                if(enter==1)
                                                    goto update;
                                                break;
                                            case 4:
                                                marks_update: //marks update label
                                                s.clearscreen();
                                                cout<<"Enter the subject number to change the marks:"<<endl;
                                                cout<<"1.Computer Network\n2.c++\n3.SQL\n4.Data Structures\n5.Web Designing\n6.Exit\n"<<endl;
                                                int choice4;
                                                cin>>choice4;
                                                    switch(choice4)
                                                    {
                                                        case 1:
                                                            s.clearscreen();
                                                            obj[i].up_m1();
                                                            obj[i].display();
                                                            cout<<"Enter 1 to exit:"<<endl;
                                                            cin>>enter;
                                                            if(enter==1)
                                                                goto marks_update;
                                                            break;
                                                        case 2:
                                                            s.clearscreen();
                                                            obj[i].up_m2();
                                                            obj[i].display();
                                                            cout<<"Enter 1 to exit:"<<endl;
                                                            cin>>enter;
                                                            if(enter==1)
                                                                goto marks_update;
                                                            break;
                                                        case 3:
                                                            s.clearscreen();
                                                            obj[i].up_m3();
                                                            obj[i].display();
                                                            cout<<"Enter 1 to exit:"<<endl;
                                                            cin>>enter;
                                                            if(enter==1)
                                                                goto marks_update;
                                                            break;
                                                        case 4:
                                                            s.clearscreen();
                                                            obj[i].up_m4();
                                                            obj[i].display();
                                                            cout<<"Enter 1 to exit:"<<endl;
                                                            cin>>enter;
                                                            if(enter==1)
                                                                goto marks_update;
                                                            break;
                                                        case 5:
                                                            s.clearscreen();
                                                            obj[i].up_m5();
                                                            obj[i].display();
                                                            cout<<"Enter 1 to exit:"<<endl;
                                                            cin>>enter;
                                                            if(enter==1)
                                                                goto marks_update;
                                                            break;
                                                        case 6:
                                                            goto update;
                                                    }
                                                break;
                                            case 5:
                                                goto admin_page;
                                                break;
                                        }
                                }
                            }
                        case 3:
                            s.clearscreen();
                            cout<<"View record Section"<<endl;
                            for(int i=1; i<=n ;i++)
                            {   
                                if(del==0)
                                {
                                    cout<<i<<" record:-"<<endl;
                                    {
                                        obj[i].display();
                                    } 
                                }
                                else
                                {
                                    if(obj[i].id != j)
                                    {
                                        obj[i].display();
                                    }
                                }
                            }
                            cout<<"Enter 1 to exit:"<<endl;
                            cin>>enter;
                            if(enter==1)
                                goto admin_page;
                            break;
                        case 4:
                            s.clearscreen();
                            cout<<"Enter the ID of the student whose record has to be deleted !!(YOU CAN DELETED THE RECORD ONLY ONCE)"<<endl;
                            del++;
                            int del_id;//del_id==ID of student to be deleted
                            cin>>del_id;
                            j = del_id;
                            cout<<"After deletion the remaining records are :"<<endl;
                            for(int i=1; i<=n;i++)
                            {
                                if(obj[i].id != del_id)
                                {
                                    obj[i].display();
                                }
                            }
                            cout<<"Enter 1 to exit:"<<endl;
                            cin>>enter;
                            if(enter==1)
                                goto admin_page;
                            break;
                        case 5:
                            goto login_page;
                            break;
                        }
                }
                else
                {
                    cout<<"YOU HAVE ENTERED A WRONG PASSWORD !!!"<<endl;
                    goto password;
                }
                    break; 
            case 2:
                cout<<"Enter your I'd"<<endl;
                int enter_id;
                cin>>enter_id; // I'd enterd by student
                if(enter_id == j)
                    cout<<"This record is deleted"<<endl;
                else
                {
                    for(int i=1; i<=n ;i++)
                    {
                        if(obj[i].id == enter_id)
                        {
                            obj[i].display();
                        }
                    }
                }
                cout<<"Enter 1 to exit:"<<endl;
                cin>>enter;
                if(enter==1)
                    goto login_page;
                break;
            case 3:
                s.clearscreen();
                return 0;
        }
    return 0;
}