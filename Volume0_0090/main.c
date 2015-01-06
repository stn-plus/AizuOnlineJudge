//
//  main.c
//  Volume0_0090
//
//  Created by slangsoft on 2015/01/01.
//  Copyright (c) 2015 Slang Software. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*----------------------------------*/
/* constant declaration             */
/*----------------------------------*/
#define NUM_EXIT    0
#define NUM_MAX_N   100
#define NUM_MIN_XY  0
#define NUM_MAX_XY  10
#define NUM_DIST    2
#define MSG_FST     "\nType the number of datasets (or '0' when done) >>>\n"
#define MSG_SCD     "\nType the dataset >>>\n"
#define MSG_ERR_N   "\nError!\nThe value of N must be 100 or less.\n"
#define MSG_ERR_XY  "\nError!\nThe value of X and Y must be 0 or more and 10 or less.\nPlease retype.\n"

/*----------------------------------*/
/* macro declaration                */
/*----------------------------------*/

/*----------------------------------*/
/* global variable declaration      */
/*----------------------------------*/

/*----------------------------------*/
/* functions prototype declaration  */
/*----------------------------------*/

/*----------------------------------*/
/* structural definition            */
/*----------------------------------*/
struct StdDataset
{
    double  x;
    double  y;
};

/*--------------------------------------*/
/* Function Name : mystrtod             */
/* Argument      : char   *str          */
/*                 double *x            */
/*                 double *y            */
/* Outputs       : -                    */
/* Author        : slangsoft            */
/* Creation Date : 2015/01/01           */
/*--------------------------------------*/
void mystrtod( char *str, double *x, double *y ) {
    char *ends;     /* 2nd arg of strtod() */
    char *str_x;
    char *str_y;
    
    str_x = strtok( str , "," );
    str_y = strtok( NULL, "," );
    
    *x = strtod( str_x, &ends );
    *y = strtod( str_y, &ends );
}

/*--------------------------------------*/
/* Function Name : dist                 */
/* Argument      : double a1            */
/*                 double a2            */
/*                 double b1            */
/*                 double b2            */
/* Output        : double dist          */
/* Author        : slangsoft            */
/* Creation Date : 2015/01/01           */
/*--------------------------------------*/
double dist( double a1, double a2, double b1, double b2 ) {
    double a    = 0;
    double b    = 0;
    double dist = 0;
    
    if( a1 > a2 ) {
        a = a1 - a2;
    }
    else {
        a = a2 - a1;
    }
    
    if( b1 > b2 ) {
        b = b1 - b2;
    }
    else {
        b = b2 - b1;
    }
    
    dist = sqrt( pow( a, 2 ) + pow( b, 2 ) );
    return dist;
}

/*--------------------------------------*/
/* Function Name : overlaps             */
/* Argument      : int n                */
/* Output        : -                    */
/* Author        : slangsoft            */
/* Creation Date : 2015/01/01           */
/*--------------------------------------*/
void overlaps( int n ) {
    int    i, j, k;
    int    ans;
    int    wk_ans;
    char   str[20];                 /* dataset(string) from stdio */
    double wk_x;
    double wk_y;
    double wk_dist;
    struct StdDataset dset[ n ];    /* dataset from stdio */
    
    /* read datasets from stdio */
    printf( MSG_SCD );
    for( i = 0; i < n; i++ ) {
        scanf( "%s", str );
        mystrtod( str, &wk_x, &wk_y );
        
        /* input value check */
        if ( NUM_MAX_XY < wk_x || NUM_MIN_XY > wk_x
         ||  NUM_MAX_XY < wk_y || NUM_MIN_XY > wk_y ) { /* error */
            printf( MSG_ERR_XY );
            i--;
        }
        else {                                          /* ok    */
            dset[ i ].x = wk_x;
            dset[ i ].y = wk_y;
        }
    }
    
    ans     = 1;
    wk_dist = 0;
    
    if( 1 >= n) {
        /* no process */
    }
    else {
        for (j = 0; j < n - 1; j++ ) {
            wk_ans = 1;
            for (k = j + 1; k < n; k++ ) {
                wk_dist = dist( dset[ j ].x, dset[ k ].x, dset[ j ].y, dset[ k ].y );
                if( NUM_DIST >= wk_dist ) {
                    wk_ans++;
                }
                else {
                    /* no process */
                }
            }
            if ( wk_ans > ans ) {
                ans = wk_ans;
            }
            else {
                /* no process */
            }
        }
    }
    printf("%d", ans);
    printf("\n");
}

/*--------------------------------------*/
/* Function Name : main                 */
/* Argument      : int argc             */
/*                 const char * argv[]  */
/* Output        : -                    */
/* Author        : slangsoft            */
/* Creation Date : 2015/01/01           */
/*--------------------------------------*/
int main( int argc, const char * argv[] ) {
    int    max_n;   /* number of datasets from stdio    */
    
    /* read number of datasets from stdio */
    printf( MSG_FST );
    scanf( "%d", &max_n );
    
    /* input value check */
    while( NUM_EXIT != max_n ) {
        if( NUM_MAX_N < max_n ) {   /* error */
            printf( MSG_ERR_N );
            return -1;
        }
        else {                      /* ok    */
            overlaps( max_n );
            printf( MSG_FST );
            scanf( "%d", &max_n );
        }
    }
    
    return 0;
}
