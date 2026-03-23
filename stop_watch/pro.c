/*
 ============================================================================
 Name        : project.c
 Author      : Mohamed_nabil_saad
 Version     : 2
 ============================================================================
 */

/*==================================================*/
/* function definition used in this project*/
void Ask_user()

{
	/* The options that are displayed */
	puts("a. Turn On the Vehicle Engine \n ");
	puts("b. Turn Off the Vehicle Engine \n ");
	puts("c. Close the System  \n ");
}


/*==================================================*/

void sensors_set()
{
	/* The options that are displayed */
	puts("a. Turn Off the Vehicle Engine \n ");
	puts("b. Set The Traffic Light Engine \n ");
	puts("c. Set The Room Temperature \n");
	puts("d. Set The Engine Temperature \n");
}

/*==================================================*/

int traffic_light_func(char *ptrafic ,int *room_temp ,int *eng_temp, char *ac_state ,char *eng_state)
{

	int speed=1;
	/*check traffic light */
	if((*ptrafic)=='o')
	{

		*ac_state=1;
		*eng_state=1;
		speed=30;
		*room_temp=((*room_temp)*5/4+1);

		*eng_temp=((*eng_temp)*5/4+1);
	}
	else if((*ptrafic)=='g')
	{

		*ac_state=1;
		*eng_state=1;
		speed=100;
	}
	else if((*ptrafic)=='r')
	{

		*ac_state=1;
		*eng_state=1;
		speed=0;
	}
	/*If  chooses something outside the options*/
	else
	{
		puts("Wrong choice \n");
	}
	return speed;
}

/*==================================================*/

void room_temp_data_func(int *ptr_temp_Data,char *ac_stat)
{
	/*check room Temperature data */
	if((*ptr_temp_Data)<10)
	{
		*ac_stat=1;
		*ptr_temp_Data=20;
	}
	else if((*ptr_temp_Data)>30)
	{
		*ac_stat=1;
		*ptr_temp_Data=20;
	}

	else
	{
		*ac_stat=0;
	}



}

/*==================================================*/

void room_engine_data_func(int *ptr_entemp_Data,char *ENG_temp_control1)
{
	/*check Engine Temperature  */
	if((*ptr_entemp_Data)<100)
	{
		*ptr_entemp_Data=125;
		*ENG_temp_control1=1;
	}
	else if((*ptr_entemp_Data)>150)
	{
		*ptr_entemp_Data=125;
		*ENG_temp_control1=1;
	}
	else
	{
		*ENG_temp_control1=0;
	}
}
