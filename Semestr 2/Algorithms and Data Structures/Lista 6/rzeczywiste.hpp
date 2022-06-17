#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "wspolne.hpp"

using namespace std;


void menu4_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10);

void menu3_D (vector <double> &t_usr_D);

void menu2_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10);

void menu1_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10);

void wszystkie_D (vector <double> &td1,vector <double> &td2,vector <double> &td3,vector <double> &td4,vector <double> &td5,vector <double> &td6,vector <double> &td7,vector <double> &td8,vector <double> &td9,vector <double> &td10);

void wszystkie_D_usr (vector <double> d_vec_usr);
void alg_usrD(vector <double> &td);

void quicksort_rzeczywiste(vector <double> td, int lewy, int prawy);
void quicki(vector <double> &td, int lewy, int prawy);

void bucket_rzeczywiste(vector <double> td);
void bucket(vector<double> & td, int roz);

void heap_rzeczywiste(vector <double> td);
void sterta(vector <double> &td, int n, int i);

void merge_rzeczywiste(vector <double> td);
void mergeSort(double arr[], int l, int r);
void merge(double arr[], int p, int q, int r);

void insertion_rzeczywiste(vector <double> td);
void insertionSort(vector <double> &td, int n);

void selection_rzeczywiste(vector <double> td);

void sortowanie_babelkowe_rzeczywiste(vector <double> td);

void quicksort_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10);

void bucket_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10);

void heap_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10);

void merge_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10);

void insertion_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10);

void selection_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10);
 
void babel_R(vector <double> &td1,  vector <double> &td2, vector <double> &td3, vector <double> &td4, vector <double> &td5, vector <double> &td6,    vector <double> &td7, vector <double> &td8,  vector <double> &td9, vector <double> &td10);
   
    
