#include <stdio.h>
#include <stdlib.h>
//��� �������:
//������ ��� ����� ������� ��� ��� �������� ������ ����� ������, ��� ����������� �� �������.
//������� �������� ����� � ����� � �� � ������� ������, ��� ����� ������� �������������� �� � �������.
//���� ����� ������ ����� ���� ����� ������. ������ ��� ��� �������� �� ��� ������ ������ ���� ����� ��� ���������?

//��-�� ���� ��� ������ ������ ��������� ������ ������ ����������� �������� �������� �����, ���� ������ ��������� ��������� �������� �� ����
// �� ���� ������������ �������, ������ ������.
//������� ������
//������ ��������� ����
typedef struct ToDo todo;
//���������� ���������
struct ToDo {

//����� ���������� ������
char buffer[101];

//��� ��� �� ���� ��� ����, ������� - ��������� ����� �� ������ �������:
todo* next;

//������� ����, ����������� ������� �����:
int count;

};

// Declare start pointer as null in
// the beginning
todo* start = NULL;


//�������� ���:
int main()
{
 //� ��� ��� ��� �������� ��� ���������:
    int choice;
    interface();
     while(1){

        //������ ���� ������� � ������:
        system("Color 3F");

        //������� �������:
        system("cls");

        seetodo(); //� ������� ����� ������ ������ ������.
        //printf("1. To see your ToDo list\n");
        printf("1. To create new ToDo\n");
        printf("2. To delete your ToDo\n");
        printf("3. Exit\n");
        printf("\n\n\nEnter your choice\t:\t"); //� ��� ��� ����� ���������?

        //��������� ��� ��� ����:
        scanf("%d", &choice);
        switch (choice){
        //� ��� ��� ����� ������� � ����������� �� ������:

        case 1:
            createtodo();
            break;
        case 2:
            deletetodo();
            break;
        case 3:
            exit(1); //������ ��� � ���������� ����� 1?
            break;

        default:
            printf("\nInvalid Choise :-(\n");
            system("PAUSE");

        }
     }
     return 0;
}
void interface() //� ��� ��� � ����� ��� ������������ ������� � ����� Void ��� ���� ���������, ��� �� ���������� ������, ����� ��?
{

    system("color 4F");
    printf("\n\n\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n");
    printf("\t} : } : } : } : } : } "
           ": } : } : } :   "
           "WELCOME TO the TODO APP "
           "     : { : { : { : { : { "
           ": { : { : { : {\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\n\n\n\t\t\t\t\t\t\t"
           "\t\t\t\t       "
           "@en6ineer\n\n\n\n"
           "\n\n\n\t");

           //�� � �������� ������� �� ��� ��������� �������, ������ ��� �� ��� ����� UI

           //������ ��� ���� �������� ����� ������������ ���-�� ���� � ������������ ���������, ���������
           system("PAUSE");

}

//����� ���������� ������ �����:
void seetodo()
{
   // system("cls"); Lishnee

    // ��������� �� ���� ��� ������:
    todo* temp;

    //Temp ������ �� ������ ������
    temp = start;

    //������� �� ������ ������:
    if (start == NULL)
        printf("\n\nEmpty ToDo \n\n");
    //������ ���� ���� �� ����� �� ���������� ����:
    while (temp != NULL){
        //����� ����:
        printf("%d.)", temp->count); //��� �� ���������? �� ����� ���

        //������ ����:
        puts(temp -> buffer);

        //�������� ����� �������:
        fflush(stdin);

        //����� � ���������� ����:
        temp = temp->next;

    }
    printf("\n\n");
    //system("PAUSE");
}
//������� ��� ����� ����:
void createtodo()
{
    char c; //��� ���� ��� ���� ����� ������������ ��� ����� ��������

    //��������� �� ����:
    todo *add, *temp; //� ��� ��� ����� ����� ������?
    system("cls");

    seetodo();
   //��� ��� ���� � while ���� ���� ������������ �� ������� Y ��� N ������ �����.
    //����������� ����:
    //������������ ������ �����-�� ��������, ��� ������ �������������� ������,
    // ���������� ����� ������ Createtodo �� ����� ������� ������� �������� ��� ����
    //��� ��, ������ �� ������ ������� ���� 0 ��� �������� � ������� ����.
    //���������� ���� ����� != 0 ����� ������� ����� ����� � ������.


    //scanf("%c", &c);


    while(1) {
        printf("Please write name of ToDo: ");
        fflush(stdin);

    //���� �� �����:
    scanf("%c", &c);
    if (c == '0')
        break;
    else{
        //���� ��������� ���� ����:
        if (start == NULL){
        //����������� �������� ������ ������ ����:
        add = (todo*)calloc(1, sizeof(todo)); //��� ��� �� ���������

        //���������� ��������� ��� �������� ���������� �����:
        start = add;
        //printf("\nType it.....\n");

        fflush(stdin);
        gets(add->buffer);

        // As first node so start's next is NULL
        start->next = NULL;
        }
    else{
        temp = (todo*)calloc(1,sizeof(todo));
        //printf("\nType it.....\n");
        fflush(stdin);
        gets(temp->buffer);

        //Insertion is at last
        // so pointer part is NULL
        temp->next = NULL;

        // add is now pointing
        // newly created node
        add->next = temp;
        add = add->next;
        }



    // USing the concept of
    // insertion at the end,
    // adding todo
    //calling function to adjust
    // the count variable
    adjustcount();

        }
    }
}

//Function to delete the todo
void deletetodo()
{
//�� � ����� ��������� ��
//���� ���������� ��� �������� ��������. ���� �� �������.
    system("cls");

    seetodo();

    // To get the numbering of the
    // todo be deleted
    int x;

    todo *del, *temp;
    printf("\nEnter the ToDo's number that you want to remove.\n\t\t");

    // Checking empty condition
    if (start == NULL)
        printf("\n\nThere is no ToDo for today.\n\n");
    else{
        scanf("%d", &x);

        // del will point to start
        del = start;

        // temp will point to start's
        // next so that traversal and
        // deletion is achieved easily
        temp = start->next;
        // Running infinite loop so
        // that user can delete and
        // asked again for choice
        while(1){

            // When the values matches,
            // delete is first node
            if (del->count == x){
                // when the node to be
                // deleted is first node
                start = start->next;

                // Deallocating the memory
                // of the deleted node
                free(del);

                // Adjusting the count when
                // node is delted
                adjustcount();
                break;
            }
            if (temp->count == x){
                del->next = temp->next;
                free(temp);
                adjustcount();
                break;
            }
            else{
                del = temp;
                temp = temp->next;
            }
        }
    }
            system("PAUSE");
}

// Function to adjust numbering
// of the nodes
void adjustcount()
{
     //For a traversal, using
     // a node pointer
     todo* temp;
     int i = 1;
     temp = start;

     //running loop until last node
     // and numbering it one by one
     while(temp != NULL){
        temp->count = i;
        i++;
        temp = temp->next;
     }
}
