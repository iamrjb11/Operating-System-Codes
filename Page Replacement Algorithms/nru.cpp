
#include<stdio.h>
void printFrame();
int pages[100],modiV[100]={0},refV[100]={0},i,j,k,pageFault=0,pageSize,frameSize,solution[100]={0},index=0,have=0;

int main(){

    printf("Not Recently Used Algorithm\n---------------------------");

    printf("\nEnter Number of Pages : ");
    scanf("%d",&pageSize);
    printf("Enter Page Sequence : ");
    for(i=0;i<pageSize;i++){
        scanf("%d",&pages[i]);
    }

    printf("Enter Number of Frames : ");
    scanf("%d",&frameSize);
    printf("Solution :\n");
    for(i=0;i<pageSize;i++){
        have=0;
        for(j=0;j<index;j++){
            if(solution[j]==pages[i]){
                have=1;
                break;
            }
        }
        if(have==1){
            continue;
        }
        else
        {
            if(index<frameSize){
                solution[index]=pages[i];
                index++;
                pageFault++;
            }
            else
            {
                printFrame();
                printf("\nEnter  Referance  Bits  Value  : ");
                for(j=0;j<frameSize;j++){
                    scanf("%d",&refV[j]);
                }
                printf("Enter Modification Bits Value  : ");

                for(j=0;j<frameSize;j++){
                    scanf("%d",&modiV[j]);
                }
                int checker=0;

                for(k=0;k<2;k++){
                    for(j=0;j<frameSize;j++){
                        if(refV[j]==0 && modiV[j]==k){
                          solution[j]=pages[i];
                          checker=1;
                          pageFault++;
                          break;
                        }

                    }
                    if(checker==1) break;
                }
                if(checker==0){
                     for(k=0;k<2;k++){
                        for(j=0;j<frameSize;j++){
                            if(refV[j]==1 && modiV[j]==k){
                              solution[j]=pages[i];

                              checker=1;
                              pageFault++;
                              break;
                            }

                        }
                        if(checker==1) break;
                    }
                }

            }
        }
    }
    printf("\n\n" );
    for(j=0;j<index;j++){

        printf("| %d ",solution[j]);

    }
    printf("|\nNumber of Page Faults : %d\n",pageFault);
}
void printFrame(){
  printf("\n\n" );
  for(j=0;j<index;j++){

      printf("| %d ",solution[j]);

  }
  printf("|\nUpcoming Page : | %d |",pages[i]);
}
