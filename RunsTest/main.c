//
//  main.c
//  RunsTest
//
//  Created by Akhil Verghese on 5/9/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int N,R;
    long long Np,Nn;
    int *numbers;
    double mean=0;
    
    scanf("%d",&N);
    
    numbers=(int*)malloc(N*sizeof(int));
    
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&numbers[i]);
        mean+=numbers[i];
    }
    
    mean/=(double)N;
    
    if((mean-(int)mean)==0)//just to make sure no integer is equal to the mean
        mean+=0.000001;
    
    for(int i=0;i<N;i++)
    {
        if(numbers[i]>mean)
            numbers[i]=1;
        else if(numbers[i]<mean)
            numbers[i]=0;
    }
    
    Np=Nn=R=0;
    
    for(int i = 0; i < N; i++)
    {
        if(numbers[i])
        {
            Np++;
            if(i==0||numbers[i-1]!=1)
                R++;
        }
        else
        {
            Nn++;
            if(i==0||numbers[i-1])
                R++;
        }
    }
    
    double expected_runs, run_variance, Z;
    
    expected_runs=((2*Np*Nn)/N) + 1;
    run_variance=(double)(2*Np*Nn*((2*Np*Nn)-Np-Nn))/(double)(((Np+Nn)*(Np+Nn))*(Np+Nn-1));
    
    Z=((long long)R-expected_runs)/sqrt(run_variance);
    
    printf("Mean = %lf",mean);
    printf("\nNp = %lld",Np);
    printf("\nNn = %lld\n",Nn);
    
    printf("Expected Runs = %lf",expected_runs);
    printf("\nRun Variance = %lf",run_variance);
    printf("\nActual Runs = %d",R);
    printf("\nZ value = %lf",Z);
    
    free(numbers);
    return 0;
}

