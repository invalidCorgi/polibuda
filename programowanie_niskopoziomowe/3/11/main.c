#include <stdio.h>
#include <stdlib.h>

//------------------stack-------------
int stack[100];
int top = -1;

void push(int data)
{
    top = top + 1;
    stack[top] = data;
}

int pop()
{
    int data;

    data = stack[top];
    top = top - 1;
    return data;
}

void stackSearch(int data)
{
    int i;
    for(i=top; i>=0; i--)
    {
        if(stack[i]==data)
        {
            printf("Znaleziono\n");
            return;
        }
    }
    printf("Nie znaleziono\n");
}
//--------------------/stack----------

//----------------lista dwukierunkowa----------------
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head=NULL;

struct Node* GetNewNode(int x)
{
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void Insert(int x)
{
    struct Node* newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Delete()
{
    if(head!=NULL)
    {
        if(head->next != NULL)
        {
            struct Node* temp = head->next;
            free(head);
            head=temp;
            head->prev=NULL;
        }
        else
        {
            free(head);
            head=NULL;
        }
    }
}

void PrintList()
{
    struct Node* temp = head;
    printf("Lista: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void listSearch(int x)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data==x)
        {
            printf("Znaleziono\n");
            return;
        }
        temp = temp->next;
    }
    printf("Nie znaleziono\n");
}
//-------------/lista dwukierunkowa-----------------

//--------------BST---------------------------------
typedef struct wezel
{
    int wartosc;           //wartosc przechowywana w wezle
    struct wezel *rodzic;  //wskaznik na rodzica
    struct wezel *l_syn;   //wskaznik na lewe dziecko
    struct wezel *p_syn;   //wskaznik na prawe dziecko
} wezel;
struct wezel *root=NULL;  //wskaŸnik na root'a

//funkcja zwraca wskaznik elementu o najmniejszej wartosci (najbardziej na lewo)
struct wezel* naj_lewo(struct wezel *start)
{
    if(start->l_syn != NULL)
        return naj_lewo(start->l_syn);
    else
        return start;
}

//funkcja zwraca wezel o podanej wartosci, badz NULL, gdy taki wezel nie istnieje
struct wezel* szukaj(struct wezel *start, int wartosc)
{
//jezeli wezel ma szukana wartosc to odnalezlismy go
    if (start->wartosc == wartosc)
    {
        printf("Znaleziono\n");
        return start;
    }
//jezeli szukana wartosc jest mniejsza to szukamy w lewym poddrzewie o ile istnieje
    else if (wartosc < start->wartosc && start->l_syn != NULL) return szukaj(start->l_syn, wartosc);
//jezeli szukana wartosc jest wieksza to szukamy w prawym poddrzewie o ile istnieje
    else if (wartosc > start->wartosc && start->p_syn != NULL) return szukaj(start->p_syn, wartosc);
    printf("Nie znaleziono\n");
    return NULL;
}

//dodaje wezel o podanej wartosci n, do drzewa o korzeniu start
int dodawanie(int n, struct wezel *start)
{
//jezeli drzewo jest puste to dodaj korzen
    if (root == NULL)
    {
        root = (wezel*)malloc(sizeof *root);
        root->wartosc = n;
        root->l_syn = NULL;
        root->p_syn = NULL;
        root->rodzic = NULL;
    }
//jezeli zadana wartosc jest mniejsza od korzenia idz do lewego poddrzewa
    else if(n < start->wartosc)
    {
//jezeli lewe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
        if(start->l_syn != NULL)
        {
            dodawanie(n,start->l_syn);
        }
//jezeli lewe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
        else
        {
            wezel *nowy = (wezel*)malloc(sizeof *root);
            nowy->wartosc = n;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->rodzic = start;
            start->l_syn=nowy;
        }
    }
//jezeli zadana wartosc jest wieksza lub rowna korzeniowi idz do prawego poddrzewa
    else
    {
//jezeli prawe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
        if(start->p_syn!=NULL)
        {
            dodawanie(n,start->p_syn);
        }
//jezeli prawe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
        else
        {
            wezel *nowy = (wezel*)malloc(sizeof *root);
            nowy->wartosc = n;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->rodzic = start;
            start->p_syn=nowy;
        }
    }
    return 0;
}

//usun wezel start
void kasowanie(struct wezel *start)
{
//jezeli wezel nie ma dzieci
    if(start->l_syn==NULL && start->p_syn==NULL)
    {
//jezeli wezel jest korzeniem
        if(start->rodzic==NULL)
        {
            root=NULL;
        }
//jezeli wezel jest po lewej stronie rodzica,
        else if(start->rodzic->l_syn==start)
        {
//usun wezel z lewej strony wezla rodzica
            start->rodzic->l_syn=NULL;
        }
        else
        {
//usun wezel z prawej strony wezla rodzica
            start->rodzic->p_syn=NULL;
        }
        free(start);
    }
//jezeli wezel ma tylko jedno dziecko
    else if(start->l_syn==NULL || start->p_syn==NULL)
    {
//jezeli po lewej stronie nie ma dziecka
        if(start->l_syn==NULL)
        {
//jezeli wezel jest korzeniem
            if(start->rodzic==NULL)
            {
                root=start->p_syn;
            }
//jezeli wezel jest po lewej stronie rodzica
            else if(start->rodzic->l_syn==start)
            {
//przyczep z lewej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
                start->rodzic->l_syn=start->p_syn;
            }
            else
            {
//przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
                start->rodzic->p_syn=start->p_syn;
            }
        }
        else
        {
//jezeli wezel jest korzeniem
            if(start->rodzic==NULL)
            {
                root=start->l_syn;
            }
//jezeli wezel jest po lewej stronie rodzica
            else if(start->rodzic->l_syn==start)
            {
//przyczep z lewej strony rodzica wezel bedacy po lewej stronie usuwanego wezla
                start->rodzic->l_syn=start->l_syn;
            }
            else
            {
//przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
                start->rodzic->p_syn=start->l_syn;
            }
        }
        free(start);
    }
    else
    {
//wstaw w miejsce usuwanego elementu - najmniejsza wartosc z prawego poddrzewa
        struct wezel *temp;
        temp=naj_lewo(start->p_syn);
        start->wartosc = temp->wartosc;
        kasowanie(temp);
    }
}

//przejdz drzewo w kolejnosci zaczynajac od wezla start
void in_order_tree_walk(struct wezel *start)
{
    if(start->l_syn != NULL) //jezeli ma dzieci po lewej stronie wywolaj funkcje rekurencyjnie
        in_order_tree_walk(start->l_syn);

    printf("%d\n", start->wartosc); //wypisz wartosc

    if(start->p_syn != NULL) //jezeli ma dzieci po prawej stronie wywolaj rekurencyjnie
        in_order_tree_walk(start->p_syn);
}
//--------------------------------------/BST--------------------------------------
int main()
{

    return 0;
}
