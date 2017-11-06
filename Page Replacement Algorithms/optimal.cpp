#include<stdio.h>
int main(){
    int pages[100],i,j,k,check=1,pageFault=0,pageSize,frameSize,optimal[100]={0},opIndex=0,hasPosition[100],notPosition[100],notPositionSolve[100];
    printf("Enter Number of Pages : ");
    scanf("%d",&pageSize);
    printf("Enter Page Sequence : ");
    for(i=0;i<pageSize;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter Number of Frames : ");
    scanf("%d",&frameSize);
    printf("\n");

    for(i=0;i<pageSize;i++){
        printf("\n%d : ",i);
        check=1;
        int have=0,check2=1;
        if(opIndex<frameSize){
            if(i!=0){
                for(j=0;j<i;j++){
                    if(optimal[j]==pages[i]) have=1;
                }
            }
            if(have!=1){
                optimal[opIndex]=pages[i];
                opIndex++;
                pageFault++;
            }
            //printf("%d ",optimal[i]);

        }
        else
        {
            /*printf("\nElse \n");
            for(j=0;j<frameSize;j++){
                printf("%d ",optimal[j]);

            }*/
            have=0;
            int notPosIndex=0;
            for(j=0;j<frameSize;j++){
                if(optimal[j]==pages[i]) have=1; /// value ase
            }
            if(have!=1){
                int repIndex;
                for(j=0;j<frameSize;j++){
                    check=0;
                    for(k=i;k<pageSize;k++){
                        if(optimal[j]==pages[k])
                        {
                            hasPosition[j]=k; ///check=1 all position has
                            check=1;
                            break;
                        }
                    }

                    if(check==0){
                        notPosition[notPosIndex]=j;
                        //printf("pos : %d ",j);
                        notPosIndex++;
                        //repIndex=j;
                        check2=0;
                    }
                    //else check2=1;
                }
                if(check2){
                    //printf("  :if:  ");
                    repIndex=0;
                    for(j=1;j<frameSize;j++){
                        if(hasPosition[repIndex]<hasPosition[j]) repIndex=j;
                    }
                }
                else
                {
                    //printf("  :else:  ");
                    if(notPosIndex==1) repIndex=notPosition[0];
                    else
                    {

                        for(j=0;j<notPosIndex;j++){
                            for(k=i-1;k>=0;k--){
                                if(optimal[j]==pages[k])
                                {
                                    notPositionSolve[j]=k; ///check=1 all position has
                                    break;
                                }
                            }
                        }
                        repIndex=0;
                        for(j=1;j<notPosIndex;j++){
                            if(notPositionSolve[repIndex]>notPositionSolve[j]) repIndex=j;
                        }
                    }
                }
                ///Assign Value
                optimal[repIndex]=pages[i];
                pageFault++;
                //printf("\nIndex : %d\n",repIndex);
            }
            for(j=0;j<frameSize;j++){
                printf("%d ",optimal[j]);

            }



        }
    }

    printf("\nNumber of Page Faults : %d\n",pageFault);


    printf("\nOutput :\n");
    for(i=0;i<pageSize;i++){
        printf("%d ",pages[i]);
    }
}
