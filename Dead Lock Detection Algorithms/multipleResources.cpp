#include<stdio.h>


int main(){
    int E[100]={0},A[100]={0},C[100][100]={0},R[100][100]={0},saveR[100][100]={0},deadLockSTS[100][100]={0},i,j,k,resourceSize,procesSize;
    printf("Multiple Resources Dead Lock Detection\n--------------------------------------\n");
    printf("\nEnter Number of Resources : ");
    scanf("%d",&resourceSize );
    printf("Enter Number of Proces : ");
    scanf("%d",&procesSize );

    printf("Enter Existing Vector : ");
    for(i=0;i<resourceSize;i++){
        scanf("%d",&E[i] );
    }

    printf("Enter Current Matrix :\n");
    for(i=0;i<procesSize;i++){
        for(j=0;j<resourceSize;j++){
            scanf("%d",&C[i][j] );
        }
    }

    printf("Enter Request Matrix :\n");
    for(i=0;i<procesSize;i++){
        for(j=0;j<resourceSize;j++){
            scanf("%d",&R[i][j] );
            saveR[i][j]=R[i][j];
        }
    }

    ///Find Alocation Vector
    int sum=0;
    for(j=0;j<resourceSize;j++){
        sum=0;
        for(i=0;i<procesSize;i++){
            sum=sum+C[i][j];
        }
        A[j]=E[j]-sum;
    }
    printf("\nAvailable Vector : " );
    for ( i = 0; i < resourceSize; i++) {
        printf("%d ",A[i] );
    }
    int flag=1;
    for(k=0;k<procesSize;k++){

        flag=1;
        for(i=k;i<procesSize;i++){
            flag=1;
            for(j=0;j<resourceSize;j++){
                if( A[j] >= R[i][j] ){
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                //Store Available Vector
                for(j=0;j<resourceSize;j++){
                    A[j]=A[j]+C[i][j];
                }
                //Swap
                for(j=0;j<resourceSize;j++){

                    deadLockSTS[k][j]=R[i][j];
                    int temp=R[i][j]; //process free location
                    R[i][j]=R[k][j];
                    R[k][j]=temp;

                    temp=C[i][j]; //process free location
                    C[i][j]=C[k][j];
                    C[k][j]=temp;

                }
                printf("\nCurrent Matrix :\n");
                for(i=0;i<procesSize;i++){
                    for(j=0;j<resourceSize;j++){
                        printf("%d ",C[i][j] );
                    }
                    printf("\n" );
                }

                printf("Request Matrix :\n");
                for(i=0;i<procesSize;i++){
                    for(j=0;j<resourceSize;j++){
                        printf("%d ",R[i][j] );
                    }
                    printf("\n" );
                }
                //printf("\ni = %d\n",i );

                printf("\nAvailable Vector : " );
                for(j=0;j<resourceSize;j++){
                    printf("%d ",A[j] );
                }
                break;
            }
            printf("\n\n-------------------------\n\n" );
        }

    }

    printf("\nSatus ( deadLockSTS ) :\n");
    for(i=0;i<procesSize;i++){
        for(j=0;j<resourceSize;j++){
            printf("%d ",deadLockSTS[i][j] );
        }
        printf("\n" );
    }

    printf("\n");
    int saveProcesIndex[100]={0};
    for(k=0;k<procesSize;k++){

        for(i=0;i<procesSize;i++){
            flag=1;
            for(j=0;j<resourceSize;j++){
                if(deadLockSTS[k][j]==saveR[i][j]){
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                saveProcesIndex[i+1]=1;
                break;
            }

        }
    }
    printf("\nOutput :\n--------------------\n" );
    for(i=1;i<=procesSize;i++){
        if(saveProcesIndex[i]) printf("Process %d is not in Dead Lock\n", i);
        else printf("Process %d is in Dead Lock\n",  i);
    }

}
