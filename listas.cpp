#include <bits/stdc++.h>
using namespace std;
struct NODE{
    int data;
    NODE *next, *prev;
    NODE(int newData=0){
        data=newData;
        next=prev=NULL;
    }
    void PushBack(int newData){
        NODE *current=next;
        NODE *newNode=new NODE(newData);
        if(current==NULL) next=newNode;
        else{
            while(current->next!=NULL) current=current->next;
            current->next=newNode;
            newNode->prev=current;
        }
    }
    void Show(){
        NODE *current=next;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    void ReversePrint(){
        NODE *current=next;
        if(current==NULL) return;
        while(current->next!=NULL) current=current->next;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->prev;
        }
        cout<<endl;
    }
    void DeleteFirst(){
        if(next==NULL) return;
        NODE *current=next;
        next=current->next;
        current->next=NULL;
        current->prev=NULL;
        delete current;
        cout<<"Eliminado\n";
    }
};

void ShowMenu(){
    cout<<"1: Ingresar dato en orden"<<endl;
	cout<<"2: Mostrar lista en reversa"<<endl;
	cout<<"3: Mostrar lista"<<endl;
	cout<<"4: Eliminar primer elemento"<<endl;
	cout<<"5: Finalizar"<<endl;
	cout<<" "<<endl;
	cout<<"Seleccione una opcion --> ";
}
NODE l1;
int main(){
    int repetir=true;
    int option;
    while(repetir){
        ShowMenu();
        cin>>option;
        if(option==1){
            int newData;
            cout<<"Ingresa un dato --> ";
            cin>>newData;
            l1.PushBack(newData);
        }else if(option==2) l1.ReversePrint();
        else if(option==3) l1.Show();
        else if(option==4) l1.DeleteFirst();
        else if(option==5) break;
    }
    return 0;
}
