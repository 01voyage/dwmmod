
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(void){
        for(;;){
        // Modules are defined here:
        char* dateMod(){
            time_t t = time(NULL);
            char* var = ctime(&t);
            var[strlen(var)-1] = '\0'; // Removes weird unicode symbol at the end
            return  var;
        }

        // Gives date_module the return value of dateMod()/
        char* date_module = dateMod();
        //printf("date_module = %s\n", date_module);
        ////////////////////////////////////////////////

        int batteryMod(){
            FILE* fptr;
            char a;
            int capacity;
            char file[] = "/sys/class/power_supply/BAT0/capacity"; // Edit battery id to fit your machine //


            fptr = fopen(file, "r");

            if(fptr == NULL){
                printf("Battery capacity inaccesible!");
                return 0;
                }

            fscanf (fptr, "%d", &capacity);
            while (!feof (fptr)){
                fscanf (fptr, "%d", &capacity);
            }

            fclose(fptr);
            return capacity;
        }

        // Converts interger to string and adds '%' sign /
        int batterycapacity = batteryMod();
        char battery_module[4];
        sprintf(battery_module, "%d", batterycapacity);
        strcat(battery_module, "%");
        //printf("battery_module = %s\n", battery_module);

        ////////////////////////////// Configuration //////////////////////////////

        // The seperator between modules
        char* spacer =  " | ";

        // The size of the modules array
        #define SIZE 5

        // The delay between updates (seconds)
        #define DELAY 1

        // Add enabled modules here:
        // Make sure to not go over or under SIZE!, edit it to your needs.
        // Remember that spacers also contribute to SIZE.
        char* modules[SIZE] = {spacer, date_module, spacer, battery_module, spacer};

        ////////////////////////////////////////////////////////////////////////////



        char xsetroot[120] = "xsetroot -name '";
        for(int j=0; j < SIZE; j++){
            strcat(xsetroot, modules[j]);
        }
        strcat(xsetroot, "'");
        //printf("full command = %s\n", xsetroot);
        system(xsetroot);
        sleep(DELAY);
        }
    }


