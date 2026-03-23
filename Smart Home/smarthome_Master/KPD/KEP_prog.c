/*
 * KEP_prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


//LIB
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"

//MCAL
#include "../DIO/DIO_interface.h"
//HAL
#include "KPD_interface.h"
#include "KPD_cfg.h"
#include "KPD_private.h"



u8 KPD_u8GetPreessedKey(void)
{
  u8 Local_u8PreesedKey  = KPD_u8No_PREESEDkAY ;
  u8 Local_u8PinStatus;
  u8 Local_u8CounterColumn ;
  u8 Local_u8CounterRow ;

  u8 LOcal_u8ColumnArr[SIZE_COL] ={KPD_u8COLUMN0_PIN,KPD_u8COLUMN1_PIN,KPD_u8COLUMN2_PIN,KPD_u8COLUMN3_PIN,};
  u8 LOcal_u8RowArr[SIZE_ROW] = {KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};
  u8 Local_u8KPDArr[SIZE_ROW][SIZE_COL] = KPD_u8ARR ;

  for(Local_u8CounterColumn = 0 ;Local_u8CounterColumn < SIZE_COL ;Local_u8CounterColumn++)
  {
    /* Active current Column */
    DIO_u8SetPinValue(KPD_8uPORT,LOcal_u8ColumnArr[Local_u8CounterColumn],DIO_u8PIN_LOW);

    for(Local_u8CounterRow = 0 ;Local_u8CounterRow < SIZE_ROW ;Local_u8CounterRow++)
    {
      /* read Current Row */
      DIO_u8ReadPinValue(KPD_8uPORT,LOcal_u8RowArr[Local_u8CounterRow] ,&Local_u8PinStatus );

      if(Local_u8PinStatus == DIO_u8PIN_LOW)
      {

        Local_u8PreesedKey = Local_u8KPDArr[Local_u8CounterRow][Local_u8CounterColumn] ;

        while(Local_u8PinStatus == DIO_u8PIN_LOW)
        {
          DIO_u8ReadPinValue(KPD_8uPORT,LOcal_u8RowArr[Local_u8CounterRow] ,&Local_u8PinStatus );

        }




        return  Local_u8PreesedKey ;
      }

    }
    // Deactivate current column
    DIO_u8SetPinValue(KPD_8uPORT,LOcal_u8ColumnArr[Local_u8CounterColumn],DIO_u8PIN_HIGH);
  }


  return Local_u8PreesedKey;
}

u32 KPD_VoidScan( ){
  u32 value,temp;
  do
  {

    value= KPD_u8GetPreessedKey();
  }while(value == 0xff);
  switch (value){
  case'+':
    CLCD_voidSendData('+');
    break;
  case'-':
    CLCD_voidSendData('-');
    break;
  case'*':
    CLCD_voidSendData('*');
    break;
  case'=':
    CLCD_voidSendData('=');
    break;
  case'c':
    CLCD_VoidClear();
    temp=KPD_VoidScan( );
    return temp;
    break;
  case'/':
    CLCD_voidSendData('/');
    break;
  default :
    CLCD_VoidSendNumber(value);
    break;
  }
  return value ;
}
u32 KPD_VoidScan_PASS( ){
  u32 value,temp;
  do
  {

    value= KPD_u8GetPreessedKey();
  }while(value == 0xff);
  switch (value){
  case'+':
    CLCD_voidSendData('+');
    break;
  case'-':
    CLCD_voidSendData('-');
    break;
  case'*':
    CLCD_voidSendData('*');
    break;
  case'=':
    CLCD_voidSendData('=');
    break;
  case'c':
    CLCD_VoidClear();
    temp=KPD_VoidScan( );
    return temp;
    break;
  case'/':
    CLCD_voidSendData('/');
    break;
  default :
	  CLCD_voidSendData('*');
    break;
  }
  return value ;
}
u32 reverseNumber(u32 num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}
u32 EnterNum(void)
{
 u32 key,num = 0;
 u8 count = 0;
 // scan number
 do{
  key = KPD_VoidScan();
  count++;
   if (key != 0xFF )
   {
    if (key >= 0 && key <= 9)
    {
     num = num * 10 + (key);
    }
   }
 }while(count < 4);
 return num;
}
u32 EnterNum_pass(void)
{
 u32 key,num = 0;
 u8 count = 0;
 // scan number
 do{
  key = KPD_VoidScan_PASS();
  count++;
   if (key != 0xFF )
   {
    if (key >= 0 && key <= 9)
    {
     num = num * 10 + (key);
    }
   }
 }while(count < 4);
 return num;
}
