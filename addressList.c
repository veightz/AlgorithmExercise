#include <stdio.h>
#include <string.h>
#define ADDRESS_PATH "/Users/veightz/Documents/address.list"
#define NUMBER 50

struct people
{
    char firstname[20];
    char lastname[20];
    char phonenumber[15];
    char address[50];
    int  mark;
};

//Import infomation from the address list.
void import(struct people person[]);

void export(struct people person[]);

//List the menu
void list();

//Init the structure
void init(struct people person[]);

//Call the function in themenu
int menu();

/*
 Return a index of structure array which is empty.
 If return number -1, it means the structure array is full.
 */
int getIndex(struct people person[]);

//Input infomation.
void add(struct people person[], int index);

//Delete infomation
void delete(struct people person[], int index);

//Show the infomation in the address list.
void show(struct people person[]);

//Search info.
void search(struct people person[]);



int main(int argc, const char * argv[])
{
    int index;
    struct people person[NUMBER];
    char cmd[20];
    
    init(person);
    list();
    scanf("%s", cmd);
    
    
    while(cmd[0] != '5')
    {
        switch (cmd[0]) {
            case '1':
                import(person);
                show(person);
                break;
                
            case '2':
                index = getIndex(person);
                if(index == -1)
                {
                    printf("本地容量已满\n");
                }else
                {
                    add(person, index);
                    export(person);
                }
                break;
                
            case '3':
                search(person);
                break;
                
            case '4':
                printf("请输入删除的序号\n");
                scanf("%d", &index);
                delete(person, index);
                export(person);
            default:
                break;
        }
        list();
        scanf("%s", cmd);
    }
    
    printf("谢谢使用!\n");
    
    return 0;
}

void list()
{
    printf("1.列出\n");
    printf("2.添加\n");
    printf("3.查询\n");
    printf("4.删除\n");
    printf("5.退出\n");
}

void init(struct people person[])
{
    int i;
    for (i = 0; i < NUMBER; ++i) {
        person[i].mark = 0;
    }
}

int getIndex(struct people person[])
{
    int i;
    import(person);
    for (i = 0; i < NUMBER; ++i) {
        if (person[i].mark == 0) {
            return i;
        }
    }
    return -1;
}

void add(struct people person[], int index)
{
    printf("请输入姓氏\n");
    scanf("%s", person[index].firstname);
    
    printf("请输入名字\n");
    scanf("%s", person[index].lastname);
    
    printf("请输入电话号码\n");
    scanf("%s", person[index].phonenumber);
    
    printf("请输入住宅地址\n");
    scanf("%s", person[index].address);
    
    person[index].mark = 1;
}

void delete(struct people person[], int index)
{
    person[index].mark = 0;
}

void search(struct people person[])
{
    int i;
    char keyword[20];
    import(person);
    printf("请输入姓氏\n");
    scanf("%s", keyword);
    for (i = 0; i < NUMBER; ++i) {
        if (person[i].mark == 1) {
            if(strcmp(person[i].firstname, keyword) == 0)
            {
                printf("电话: %s\n", person[i].phonenumber);
            }
        }
    }
}

void show(struct people person[])
{
    int i, sum = 0;
    import(person);
    for (i = 0; i < NUMBER; ++i) {
        sum += person[i].mark;
    }
    printf("目前本地储存了 %d 条联系人信息\n", sum);
    
    for (i = 0; i < NUMBER; ++i) {
        if (person[i].mark == 1) {
            printf("%s  %s  %s  %s\n", person[i].firstname, person[i].lastname, person[i].phonenumber, person[i].address);
        }
    }
}

void import(struct people person[])
{
    FILE *fp;
    int i = 0;
    fp = fopen(ADDRESS_PATH, "r");
    while (!feof(fp)) {
        fscanf(fp, " %s%s%s%s", person[i].firstname, person[i].lastname, person[i].phonenumber, person[i].address);
        person[i].mark = 1;
        i++;
    }
    fclose(fp);
}

void export(struct people person[])
{
    int i;
    FILE *fp;
    fp = fopen(ADDRESS_PATH, "w+");
    for (i = 0; i < NUMBER; ++i) {
        if (person[i].mark == 1) {
            fprintf(fp, "\n%s %s  %s  %s", person[i].firstname, person[i].lastname, person[i].phonenumber, person[i].address);
        }
    }
    fclose(fp);
}




