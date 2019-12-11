#include "functions.h"
//tdfghfhgfghfhhggf

ofstream out1("L1.txt");
ofstream out2("L2.txt");
element* EnterList()
{
    element *first, *current;
    int n;
    cout<<"Number of elements"<<endl;
    cin>>n;
    cout<<"Enter element:\n"<<endl;
    first=current=new element;
    for(int i=0;i<n;i++)
    {
        cin>>current->dbl;
        current->next=new element;
        current=current->next;
    }
    if(n==0)
    {
        first=NULL;
    }
    current->next=NULL;
    return first;
}
element* razdelenie(element* first, int i)
{

    element *current,*first1,*first2;
    element *current1;
    element *current2;
    current=first;
    current1 = NULL;
    current2 = NULL;
    if(i == 1){
        first1=new element;
        current1=first1;
        while(current->next!=NULL)
        {
            if (current->dbl > 0)
            {
                current1->dbl = current->dbl;
                current1->next = new element;
                current1 = current1->next;
            }
            current = current->next;
        }
            current = current->next;
        return first1;

    }else if(i == 2){
        first2=new element;
        current2=first2;
        while (current->next!=NULL){
            if(current->dbl<=0){
                current2->dbl = current->dbl;
                current2->next = new element;
                current2 = current2->next;
            }
            current = current->next;
        }
        return first2;
    }

}
void Ldel(element* first)
{
    TE del;
    cout << "Enter element to delete " << endl;
    cin >> del;
    element *current, *prev;
    current=first->next;
    prev = first;
    while(1)
    {
        if(first->dbl == del){
            current = first;
            first = first->next;
            delete current;
            break;
        }else if(current->dbl == del){
            prev->next = current->next;
            delete current;
            break;
        }else{

            current = current->next;
            prev = prev->next;
            if(current == NULL){
                break;
            }
        }
    }

}
element* L2del(element* first)
{
    element *current, *prev;
    current=first->next;
    prev = first;
    if (first == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        while(1){
            if(first->dbl == 0||current->dbl == 0){
                current = current->next;
                prev = prev->next;
                if(current == NULL){
                    break;
                }
            }else if(first->dbl < 0){
                current = first;
                first = first->next;
                delete current;
                break;
            }else if(current->dbl < 0){
                prev->next = current->next;
                delete current;
                break;
            }
        }
    }
    return first;
}
void file(element* L,element* L1,element* L2)
{
element *current = L;
out1 <<"List L:"<<endl;
while (current->next != NULL)
{
out1 << current->dbl << endl;
current = current->next;
}
current =  L1;
out2 <<"List L1:"<< endl;
while (current->next != NULL)
{
out2 << current->dbl << endl;
current = current->next;
}
current = L2;
out2 <<"List L2:"<< endl;
while (current->next != NULL)
{
out2 << current->dbl << endl;
current = current->next;
}
}

element* SortList(element* first) {
    element *f = first;
    int size = SizeList(first);
    element **adress = new element*[size];   //массив адресов
    double *dbl = new double[size];      //массив значений элементов
    for(int i = 0;f != NULL;i++){    //запихиваем список в массивы
        dbl[i] = f->dbl;
        adress[i] = f;
        f = f->next;
    }
    double temp;    //"буфер обмена"
    element* tempA;      //"буфер обмена для Адрессов"
    for (int i = 0; i < size - 1; i++) {    //сортирование пузырьков
        for (int j = 0; j < size - i - 1; j++) {
            if (dbl[j] > dbl[j + 1]) {
                temp = dbl[j];
                tempA = adress[j];
                dbl[j] = dbl[j + 1];
                adress[j] = adress[j + 1];
                dbl[j + 1] = temp;
                adress[j + 1] = tempA;
            }
        }
    }
    first = adress[0];
    f = first;
    for(int i = 0;i < size - 1;i++){      //зписть элементов масиива в список
        f->next = adress[i + 1];
        f = f->next;
    }
    f->next = NULL;
    delete[] adress;      //удаление
    delete[] dbl;
    return first;

}
int SizeList(element* first)
{
  int size=0;
  while(first)
  {
    size++;
    first=first->next;
  }
  return size;
}