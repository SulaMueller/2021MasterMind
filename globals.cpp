/*
globals.cpp

@author:    Sula Mueller
@change:    26/06/2021

@summary:   define simple functions
*/

#include<globals.h>
#include<QDebug>


// works only for unsigned elements
void sort(int* arr, int numels){
    for(int i=0; i<numels; i++){
        if(arr[i]<0){
            qWarning() << "\narray not sorted. Only sort unsigned arrays.";
            return;
        }
    }
    int* output = new int[numels];
    int lastel = -1;
    int copiedels = 0;
    while(copiedels < numels){
        int currel = 10000;
        for(int i=0; i<numels; i++){
            if(arr[i]>lastel && arr[i] < currel)
                currel = arr[i];
        }
        int numcurrs = 0;
        for(int i=0; i<numels; i++){
            if(arr[i] == currel)
                numcurrs++;
        }
        for(int i=0; i<numcurrs; i++)
            output[copiedels++] = currel;
        lastel = currel;
    }
    memcpy(arr, output, numels*sizeof(int));

    //delete[] output;
}

void printArr(int* arr, int N){
    qDebug() << "\n [";
    for(int i=0; i<N; i++)
        qDebug() << arr[i] << ", ";
    qDebug()<< "]";
}

void cout(QString s){
    qDebug() << s;
}

void setInt(int* arr, int begin, int val, int N){
    int* ptr = arr + begin;
    int* pe = ptr + N;
    while(ptr < pe)
        *ptr++ = val;
}

