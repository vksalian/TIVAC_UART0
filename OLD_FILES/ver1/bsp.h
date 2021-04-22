/*
 * bsp.h
 *
 *  Created on: 14-Apr-2021
 *      Author: vksalian
 */

#ifndef BSP_H_
#define BSP_H_

#ifdef __cplusplus
extern "C" {
#endif


#define BIT(n)       (1U<<(n))
#define L_RED        BIT(1)
#define L_BLUE       BIT(2)
#define L_GREEN      BIT(3)
#define PORTF_CLK    BIT(5)

#define USE_AHB               (1)
#define SYS_CLK_HZ            (16000000U)

#ifdef __cplusplus
}
#endif

#endif /* BSP_H_ */