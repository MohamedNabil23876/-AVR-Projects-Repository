#ifndef  KPD_INTERFACE_H_
#define  KPD_INTERFACE_H_


u8 KPD_u8GetPreessedKey(void);
void KPD_voidShiftRight(u8 arr,u8 CopyPos);
void KPD_voidShiftLeft(u8 arr,u8 CopyPos);

u32 KPD_VoidScan(void);

u32 EnterNum(void);

#endif
