#include<stdio.h>
void printFrame();

int pages[100],refV[100]={0},i,j,k,c=0,pageFault=0,pageSize,frameSize,solution[100]={0},index=0,indi=0,have=0;
int main(){


    printf("Clock Algorithm\n----------------");

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
            //refV[j]=1;
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
                printf("\nEnter Referance Values : ");
                for(j=0;j<frameSize;j++){
                    scanf("%d",&refV[j]);
                }
                for( ; ; ){
                    if(refV[indi]==1){
                      refV[indi]=0;
                      indi++;
                      if(indi==frameSize) indi=0;
                    }
                    else
                    {
                        solution[indi]=pages[i];
                        indi++;
                        if(indi==frameSize) indi=0;
                        pageFault++;

                        break;
                    }  //else check2=1;
                }
            }
        }
    }  //. End of for loop
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
  printf("\nIndicator Position : %d",indi+1);
}
