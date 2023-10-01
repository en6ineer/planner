#include <stdio.h>
#include <stdlib.h>
//Мои заметки:
//Первое что можно сделать так это выводить список задач всегда, вне зависимости от статуса.
//Сделать хранение задач в файле а не в буффере обмена, для этого изучить взаимодействие Си с файлами.
//Надо чтобы список задач было видно всегда. Какого хуя при удалении он мне ошибку выдает если число вне диапазона?

//Из-за того что пендус создал буфферный список вместо нормального создания внешнего файла, этот ебанат прихуярил несколько проверок на ввод
// на ввод наименования тудушки, параша короче.
//Ебанные Индусы
//создал структуру ТуДу
typedef struct ToDo todo;
//Декларирую структуру
struct ToDo {

//Задаю символьный массив
char buffer[101];

//Вот тут не знаю для чего, поинтер - указатель чтоли на ячейку массива:
todo* next;

//счетчик типа, вариативный счетчик узлов:
int count;

};

// Declare start pointer as null in
// the beginning
todo* start = NULL;


//Основной код:
int main()
{
 //А вот тут уже началось без комментов:
    int choice;
    interface();
     while(1){

        //Меняем цвет консоли и текста:
        system("Color 3F");

        //Очищаем консоль:
        system("cls");

        seetodo(); //Я добавил чтобы видеть задачи всегда.
        //printf("1. To see your ToDo list\n");
        printf("1. To create new ToDo\n");
        printf("2. To delete your ToDo\n");
        printf("3. Exit\n");
        printf("\n\n\nEnter your choice\t:\t"); //А вот тут зачем табуляция?

        //Считываем что ввёл юзер:
        scanf("%d", &choice);
        switch (choice){
        //А вот тут вызов функции в зависимости от выбора:

        case 1:
            createtodo();
            break;
        case 2:
            deletetodo();
            break;
        case 3:
            exit(1); //Почему тут в параметрах стоит 1?
            break;

        default:
            printf("\nInvalid Choise :-(\n");
            system("PAUSE");

        }
     }
     return 0;
}
void interface() //А вот тут я понял что декларизация функции с типом Void это типа процедуры, она не возвращает ничего, верно же?
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

           //Ну в принципе понятно он тут интерфейс выводит, кстати как по мне говно UI

           //Дальше тут типа ожидание чтобы пользователь что-то ввел и продолжилась программа, прикольно
           system("PAUSE");

}

//ЧТобы посмотреть список задач:
void seetodo()
{
   // system("cls"); Lishnee

    // Указатель на узел для обхода:
    todo* temp;

    //Temp встает на начало списка
    temp = start;

    //Условие на пустой список:
    if (start == NULL)
        printf("\n\nEmpty ToDo \n\n");
    //Крутим цикл пока не дойдём до последнего узла:
    while (temp != NULL){
        //Номер узла:
        printf("%d.)", temp->count); //Что за стрелочка? Не помню уже

        //Данные узла:
        puts(temp -> buffer);

        //Очистить вывод консоли:
        fflush(stdin);

        //Пошли к следующему узлу:
        temp = temp->next;

    }
    printf("\n\n");
    //system("PAUSE");
}
//Функция для ввода узла:
void createtodo()
{
    char c; //Это типа для того чтобы пользователь сам вввел значение

    //Указатель на узел:
    todo *add, *temp; //А вот так разве можно делать?
    system("cls");

    seetodo();
   //Тут был цикл с while Пока типа пользователь не выберет Y или N короче жесть.
    //Бесконечный цикл:
    //ПОльзователь вводит какое-то значение, оно должно регулироваться кейсом,
    // получается после вызова Createtodo мы сразу выводим введите название для туду
    //Это ок, дальше мы следом выводим типа 0 для возврата в прошлое меню.
    //Получается если сканф != 0 тогда создать новую хуйню с именем.


    //scanf("%c", &c);


    while(1) {
        printf("Please write name of ToDo: ");
        fflush(stdin);

    //Ввод от юзера:
    scanf("%c", &c);
    if (c == '0')
        break;
    else{
        //Если стартовый узел ноль:
        if (start == NULL){
        //Динамически выделяем память новому узлу:
        add = (todo*)calloc(1, sizeof(todo)); //Вот тут бы подробнее

        //Используем указатель для создания ссылочного листа:
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
//Ну и говно процедура же
//нету исключений для вводимых значений. Надо бы создать.
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
