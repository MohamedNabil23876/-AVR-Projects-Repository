/*
 ============================================================================
 Name        : project.c
 Author      : programing
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void Ask_user();
void sensors_set();
int traffic_light_func(char *ptrafic ,int *room_temp ,int *eng_temp, char *ac_state ,char *eng_state);
void room_temp_data_func(int *ptr_temp_Data,char *ac_stat);
void room_engine_data_func(int *ptr_entemp_Data,char *ENG_temp_control1);


int main(void)
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	char AC_stat=1;
	char ENG_stat=1;
	char ENG_temp_control=1;
	char ask;
	char sensor;
	char traffic_light;
	int vehicle_speed=30;
	int room_temp_data=10;
	int engine_temp_data=20;

	Ask_user();

	scanf("%c",&ask);

	while(ask=='b')
	{
		Ask_user();
		scanf(" %c",&ask);
	}

	if ( ask=='c')
	{
		puts("Quit the System \n \n");
		return 0 ;
	}

	else if (ask=='a')
	{
		sensors_set();

		scanf(" %c",&sensor);
		while(sensor=='a')
		{
			Ask_user();
			scanf(" %c",&ask);
			while(ask=='b')
			{
				Ask_user();
				scanf(" %c",&ask);
			}

			if ( ask=='c')
			{
				puts("Quit the System \n \n");
				return 0 ;
			}

			else if (ask=='a')
			{
				sensors_set();

				scanf(" %c",&sensor);
			}

		}
		if(sensor=='b')
		{
			scanf(" %c",&traffic_light);
			int vehicle_speed=	traffic_light_func(&traffic_light, &room_temp_data, &engine_temp_data,&AC_stat,&ENG_stat);
			(AC_stat==1)? puts("AC is on \n"):puts("AC is off \n");
			(ENG_stat==1)? puts("engine is on \n"):puts("engine is off \n");
			printf("speed is =%d \n",vehicle_speed);
			printf("room temperature is :%d \n",room_temp_data);
			(ENG_temp_control==1)? puts("engine temperature on \n "):puts("engine temperature off \n ");
			printf("engine temperature is :%d \n",engine_temp_data);
		}
		else if(sensor=='c')
		{
			scanf("%d",&room_temp_data);
			room_temp_data_func(&room_temp_data,&AC_stat);
			(AC_stat==1)? puts("AC is on \n"):puts("AC is off \n");
			(ENG_stat==1)? puts("engine is on \n"):puts("engine is off \n");
			printf("speed is =%d \n",vehicle_speed);
			printf("room temperature is :%d \n",room_temp_data);
			(ENG_temp_control==1)? puts("engine temperature on \n "):puts("engine temperature off \n ");
			printf("engine temperature is :%d \n",engine_temp_data);

		}
		else if(sensor=='d')
		{
			scanf("%d",&engine_temp_data);
			room_engine_data_func(&engine_temp_data,&ENG_temp_control);
			(AC_stat==1)? puts("AC is on \n"):puts("AC is off \n");
			(ENG_stat==1)? puts("engine is on \n"):puts("engine is off \n");
			printf("speed is =%d \n",vehicle_speed);
			printf("room temperature is :%d \n",room_temp_data);
			(ENG_temp_control==1)? puts("engine temperature on "):puts("engine temperature off ");
			printf("engine temperature is :%d \n",engine_temp_data);

		}

	}
	else
	{
		puts("Wrong");
	}


}
void Ask_user()

{
	puts("a. Turn On the Vehicle Engine \n ");
	puts("b. Turn Off the Vehicle Engine \n ");
	puts("c. Close the System  \n ");
}

void sensors_set()
{
	puts("a. Turn Off the Vehicle Engine \n ");
	puts("b. Set The Traffic Light Engine \n ");
	puts("c. Set The Room Temperature \n");
	puts("d. Set The Engine Temperature \n");
}

int traffic_light_func(char *ptrafic ,int *room_temp ,int *eng_temp, char *ac_state ,char *eng_state)
{
	int speed=1;
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
	else
	{
		puts("Wrong");
	}
	return speed;
}

void room_temp_data_func(int *ptr_temp_Data,char *ac_stat)
{
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
void room_engine_data_func(int *ptr_entemp_Data,char *ENG_temp_control1)
{
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
