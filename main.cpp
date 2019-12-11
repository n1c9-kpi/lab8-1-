#include "functions.h"

int main()
{
    element *L, *L1, *L2;
     L = EnterList();
    int i;
    bool exit=false;
    while(!exit){
        cout<<"Enter command:\n\t1 - Delete the first occurrence of element\n\t2 - Separation on 2 lists\n\t3 - Deleting first negative element from second list\n\t4 - Enter lists to files\n\t0 - Exit\n\nYour command : ";
        cin>>i;
        switch(i)
        {
            case(1):
            {
                Ldel(L);
                break;
            }
            case(2):
            {
                L1 = razdelenie(L,1);
                L2 = razdelenie(L,2);
                break;
            }
            case(3):
            {
                 L2 = L2del(L2);
                break;
            }
            case(4):
            {
                file(L,L1,L2);
                break;
            }
            case(0):
            {
                exit=true;
                break;
            }
            default:
            {
                cout<<"wrong command"<<endl;
            }
        }
    }
    return 0;
}