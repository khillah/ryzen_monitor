#pragma once

//Calculate memory address of element
#define pm_element(i) ((float*) (base_addr + (i)*4))

//Assign 2 given elements to a array of size 2
#define assign_pm_elements_2(arr,e0,e1) arr[0]=pm_element(e0); arr[1]=pm_element(e1);

//Assign 4 given elements to a array of size 4
#define assign_pm_elements_4(arr,e0,e1,e2,e3) \
arr[0]=pm_element(e0); arr[1]=pm_element(e1); arr[2]=pm_element(e2); arr[3]=pm_element(e3);

//Assign 4 consecutive elements to a array of size 4
#define assign_pm_elements_4_consec(arr,e) \
arr[0]=pm_element(e  ); arr[1]=pm_element(e+1); arr[2]=pm_element(e+2); arr[3]=pm_element(e+3);

//Assign 8 consecutive elements to a array of size 8
#define assign_pm_elements_8_consec(arr,e) \
arr[0]=pm_element(e  ); arr[1]=pm_element(e+1); arr[2]=pm_element(e+2); arr[3]=pm_element(e+3);\
    arr[4]=pm_element(e+4); arr[5]=pm_element(e+5); arr[6]=pm_element(e+6); arr[7]=pm_element(e+7);

//Assign 16 consecutive elements to a array of size 16
#define assign_pm_elements_16_consec(arr,e) \
arr[ 0]=pm_element(e   ); arr[ 1]=pm_element(e+ 1); arr[ 2]=pm_element(e+ 2); arr[ 3]=pm_element(e+ 3);\
    arr[ 4]=pm_element(e+ 4); arr[ 5]=pm_element(e+ 5); arr[ 6]=pm_element(e+ 6); arr[ 7]=pm_element(e+ 7);\
    arr[ 8]=pm_element(e+ 8); arr[ 9]=pm_element(e+ 9); arr[10]=pm_element(e+10); arr[11]=pm_element(e+11);\
    arr[12]=pm_element(e+12); arr[13]=pm_element(e+13); arr[14]=pm_element(e+14); arr[15]=pm_element(e+15);
