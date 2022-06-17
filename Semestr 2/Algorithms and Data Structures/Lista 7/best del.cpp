#include <iostream>
#include <windows.h>

using namespace std;

struct Tree{
    int num;
    Tree* p;
    Tree* lc;
    Tree* rc;
};

Tree* FindTree(Tree*,int);
void Deletion(Tree*&,Tree*,int&);

Tree* Maxi(Tree* branch){
    if(branch->rc!=NULL)
        return Maxi(branch->rc);
    else
        return branch;
}
Tree* Mini(Tree* branch){
    if(branch->lc!=NULL)
        return Mini(branch->lc);
    else
        return branch;
}
Tree* FindTree(Tree* root, int key){
    if(root!=NULL){
        if(root->num<key)
            return FindTree(root->rc,key);
        else if(root->num>key)
            return FindTree(root->lc,key);
        else
            return root;
    }
    else
        return NULL;
}
void Deletion(Tree*(&Begin),Tree* root,int &n){
    if(root!=NULL){
        if(root->lc!=NULL){
            Tree* temp = Maxi(root->lc);
            root->num = temp->num;
            if(temp->p == root)
                root->lc = temp->lc;
            else
                temp->p->rc = temp->lc;
            if(temp->lc!=NULL)
                temp->lc->p = temp->p;
        }
        else if(root->rc!=NULL){
            Tree* temp = Mini(root->rc);
            root->num = temp->num;
            if(temp->p == root)
                root->rc = temp->rc;
            else
                temp->p->lc = temp->rc;
            if(temp->rc!=NULL)
                temp->rc->p = temp->p;
        }
        else{
            if(root->p!=NULL){
                if(root->p->lc==root)
                    root->p->lc = NULL;
                else
                    root->p->rc = NULL;
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
    system("pause");
}
