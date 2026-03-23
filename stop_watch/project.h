

/*
 ============================================================================
 Name        : project.c
 Author      : Mohamed_nabil_saad
 Version     : 2
 ============================================================================
 */

/* function to display the options for the user*/
void Ask_user();
/* function to choose desired sensor to check it */
void sensors_set();
/* function to ask the user for the traffic light*/
int traffic_light_func(char *ptrafic ,int *room_temp ,int *eng_temp, char *ac_state ,char *eng_state);
/*function used to set room temperature data*/
void room_temp_data_func(int *ptr_temp_Data,char *ac_stat);
/*function used to set temperature of the engine*/
void room_engine_data_func(int *ptr_entemp_Data,char *ENG_temp_control1);
/* the previous are the function prototypes used in this project*/
