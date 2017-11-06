
#include<stdio.h>
void printFrame();

int pages[100],i,j,k,indicator=0,pageSize,frameSize,solution[100]={0},index=0,pageFault=0;
int main(){

    printf("First In,First Out Algorithm\n----------------------------");

    printf("\nEnter Number of Pages : ");
    scanf("%d",&pageSize);
    printf("Enter Page Sequence : ");
    for(i=0;i<pageSize;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter Number of Frames : ");
    scanf("%d",&frameSize);
    printf("\nSolution :");

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
                //refVariable[index]=0;
                index++;
                pageFault++;
            }
            else
            {
                for(j=0;j<frameSize-1;j++){
                    solution[j]=solution[j+1];
                }
                solution[frameSize-1]=pages[i];
                pageFault++;
            }
            printFrame();
        }
    }///end of for loop
    printf("\n\nNumber of Page Faults : %d\n",pageFault);
}

void printFrame(){
  printf("\n\n" );

  printf("Upcoming Page %d : ",pages[i]);
  for(j=0;j<index;j++){

      printf("| %d ",solution[j]);

  }
  printf("|");
}
