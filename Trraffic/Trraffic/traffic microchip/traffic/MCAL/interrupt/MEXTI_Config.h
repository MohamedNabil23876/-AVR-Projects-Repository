/*
 * MEXTI_Config.h
 *
 * Created: 10/09/2022 08:15:13 م
 *  Author: nabil
 */ 


#ifndef MEXTI_CONFIG_H_
#define MEXTI_CONFIG_H_

/*Options 
  1-Low_Level 
  2-On_CHANGE
  3-FALLING_ADGE
  4-Rising_Adge
  
*/
#define INT0_SENSE  FALLING_ADGE 
#define INT1_SENSE   On_CHANGE


/*Options

  -FALLING_ADGE
  -Rising_Adge

*/
#define INT2_SENSE FALLING_ADGE

/*Options
  1-ENABIL
  2-DISABLE


*/
#define INTI0_INTLSTATUE ENABIL
#define INTI1_INTLSTATUE ENABIL
#define INTI2_INTLSTATUE ENABIL










#endif /* MEXTI_CONFIG_H_ */