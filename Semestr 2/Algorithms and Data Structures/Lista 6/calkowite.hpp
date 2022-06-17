#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "wspolne.hpp"

using namespace std;


void menu4_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10);

void menu3_C (vector <int> &t_usr_C);

void menu2_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10);

void menu1_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10);

void wszystkie_C (vector <int> &tc1,vector <int> &tc2,vector <int> &tc3,vector <int> &tc4,vector <int> &tc5,vector <int> &tc6,vector <int> &tc7,vector <int> &tc8,vector <int> &tc9,vector <int> &tc10);

void mergeSorta(int tab[], int low, int high) ;
void mergeofarrays(int tab[], int low, int mid, int high);

void wszystkie_C_usr (vector <int> &c_vec_usr);

void sortowanie_babelkowe_calkowite(vector <int> tc);
void selection_calkowite(vector <int> tc);

void insertion_calkowite(vector <int> tc);
void insertionSort(vector <int> &tc, int n);


void alg_usr(vector <int> &tc);

void bucket_calkowite(vector <int> tc);
void bucketSort(vector <int> &arr, int n);
void bucket(vector<int> & v, int roz);

void counting_calkowite(vector <int> tc);
void countSort(int arr[], int n);

void heap_calkowite(vector <int> tc);
void sterta(vector <int> &tc, int n, int i);


void merge_calkowite(vector <int> tc);
void merge(int arr[], int p, int q, int r);
//void merge(vector <int> &arr, int p, int q, int r);
//void mergeSort(vector <int> &arr, int l, int r) ;
void mergeSort(int arr[], int l, int r);

void quicksort_calkowite(vector <int> tc, int lewy, int prawy);
void quicki(vector <int> &tc, int lewy, int prawy);


void quicksort_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);

void bucket_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);

void heap_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);

void merge_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);

void counting_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);

void insertion_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);

void selection_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);
 
void babel_C(vector <int> tc1,  vector <int> tc2, vector <int> tc3, vector <int> tc4, vector <int> tc5, vector <int> tc6,    vector <int> tc7, vector <int> tc8,  vector <int> tc9, vector <int> tc10);
   
    
