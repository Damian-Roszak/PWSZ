#include <iostream>
#include <windows.h>

using namespace std;

struct wezel{
    int klucz;
    wezel* rodzic;
    wezel* lewy;
    wezel* prawy;
};

wezel* FindTree(wezel*,int);
void Deletion(wezel*&,wezel*,int&);

wezel* Maxi(wezel* branch){
    if(branch->prawy!=NULL)
        return Maxi(branch->prawy);
    else
        return branch;
}
wezel* Mini(wezel* branch){
    if(branch->lewy!=NULL)
        return Mini(branch->lewy);
    else
        return branch;
}
wezel* FindTree(wezel* root, int key){
    if(root!=NULL){
        if(root->klucz<key)
            return FindTree(root->prawy,key);
        else if(root->klucz>key)
            return FindTree(root->lewy,key);
        else
            return root;
    }
    else
        return NULL;
}
void Deletion(wezel*(&Begin),wezel* root,int &n){
    if(root!=NULL){
        if(root->lewy!=NULL){
            wezel* temp = Maxi(root->lewy);
            root->klucz = temp->klucz;
            if(temp->rodzic == root)
                root->lewy = temp->lewy;
            else
                temp->rodzic->prawy = temp->lewy;
            if(temp->lewy!=NULL)
                temp->lewy->rodzic = temp->rodzic;
        }
        else if(root->prawy!=NULL){
            wezel* temp = Mini(root->prawy);
            root->klucz = temp->klucz;
            if(temp->rodzic == root)
                root->prawy = temp->prawy;
            else
                temp->rodzic->lewy = temp->prawy;
            if(temp->prawy!=NULL)
                temp->prawy->rodzic = temp->rodzic;
        }
        else{
            if(root->rodzic!=NULL){
                if(root->rodzic->lewy==root)
                    root->rodzic->lewy = NULL;
                else
                    root->rodzic->prawy = NULL;
                delete root;
            }
            else{
                Begin = NULL;
                delete root;
            }
        }
        n--;
    }
    else
        cout<<"Brak danego elementu!!!"<<endl;
    
}
