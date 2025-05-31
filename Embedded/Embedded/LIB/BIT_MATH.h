#ifndef BIT_MATH
#define BIT_MATH

#define  SET_BIT(R,BIT)   R|=(1<<BIT)
#define  CLR_BIT(R,BIT)   R&=~(1<<BIT)
#define  TOG_BIT(R,BIT)   R^=(1<<BIT)
#define  GET_BIT(R,BIT)   ((R>>BIT)&0x01)

#endif