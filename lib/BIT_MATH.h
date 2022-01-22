#ifndef _BIT_MATH_H_
#define	_BIT_MATH_H_

#define SET_BIT(REG,BIT_ID) REG|=(1<<BIT_ID)
#define CLR_BIT(REG,BIT_ID) REG&=~(1<<BIT_ID)
#define GET_BIT(REG,BIT_ID) (REG>>BIT_ID)&1
#define TOG_BIT(REG,BIT_ID) REG^=(1<<BIT_ID)

#endif
