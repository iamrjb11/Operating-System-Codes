#include<stdio.h>
void printFrame();

int pages[100],refVariable[100]={0},refV[100]={0},i,j,k,c=0,pageFault=0,pageSize,frameSize,solution[100]={0},index=0;
int main(){

    printf("Second Chance Algorithm\n------------------------");

    printf("\nEnter The Number of Pages : ");
    scanf("%d",&pageSize);
    printf("Enter Page Sequence : ");
    for(i=0;i<pageSize;i++){
        scanf("%d",&pages[i]);
    }


    printf("Enter Number of Frames : ");
    scanf("%d",&frameSize);
    printf("Solution :\n");

    for(i=0;i<pageSize;i++){
        int have=0;
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
                int temp;
                printFrame();
                printf("\nEnter Referance Values : ");
                for(j=0;j<frameSize;j++){
                    scanf("%d",&refV[j]);
                }
                for(j=0;j<frameSize;j++){
                        //printf("j=%d\n",j);
                    if(refV[j]==1){
                        temp=solution[0];
                        for(j=0;j<frameSize-1;j++){
                            solution[j]=solution[j+1];
                            refV[j]=refV[j+1];
                        }
                        solution[frameSize-1]=temp;
                        refV[j]=0;

                        j=-1;
                    }
                    else
                    {

                        for(j=0;j<frameSize-1;j++){
                            solution[j]=solution[j+1];
                            refV[j]=refV[j+1];
                        }
                        solution[frameSize-1]=pages[i];
                         refV[j]=0;

                        pageFault++;
                        //printf("Break\n");
                        break;
                    }

                    //else check2=1;
                }

                //printf("\nIndex : %d\n",repIndex);
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
