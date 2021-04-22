/* The below pre-processor directive makes sure that
   the header files gets included only once */
#ifndef TM4C123GH6PM_H
#define TM4C123GH6PM_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>             /* For uint32_t, etc typedef */

/* SYSCTL Base Address */
#define SYSCTL_BASE             0x400FE000UL
#define SYSCTL                  ((SYSCTL_Type *) SYSCTL_BASE)

/* Port F Base Address */
#define PORTF_BASE              0x40025000UL
#define GPIOF                   ((GPIOF_Type *) PORTF_BASE)

/**
  * @brief Register map for GPIOF peripheral (GPIOF)
  */
typedef struct {
    volatile const uint32_t  RESERVED[255];  /*!< Reserved                       */
    volatile       uint32_t  DATA;           /*!< GPIO Data                      */
    volatile       uint32_t  DIR;            /*!< GPIO Direction                 */
    volatile       uint32_t  IS;             /*!< GPIO Interrupt Sense           */
    volatile       uint32_t  IBE;            /*!< GPIO Interrupt Both Edges      */
    volatile       uint32_t  IEV;            /*!< GPIO Interrupt Event           */
    volatile       uint32_t  IM;             /*!< GPIO Interrupt Mask            */
    volatile       uint32_t  RIS;            /*!< GPIO Raw Interrupt Status      */
    volatile       uint32_t  MIS;            /*!< GPIO Masked Interrupt Status   */
    volatile       uint32_t  ICR;            /*!< GPIO Interrupt Clear           */
    volatile       uint32_t  AFSEL;          /*!< GPIO Alternate Function Select */
    volatile const uint32_t  RESERVED1[55];  /*!< Reserved1                      */
    volatile       uint32_t  DR2R;           /*!< GPIO 2-mA Drive Select         */
    volatile       uint32_t  DR4R;           /*!< GPIO 4-mA Drive Select         */
    volatile       uint32_t  DR8R;           /*!< GPIO 8-mA Drive Select         */
    volatile       uint32_t  ODR;            /*!< GPIO Open Drain Select         */
    volatile       uint32_t  PUR;            /*!< GPIO Pull-Up Select            */
    volatile       uint32_t  PDR;            /*!< GPIO Pull-Down Select          */
    volatile       uint32_t  SLR;            /*!< GPIO Slew Rate Control Select  */
    volatile       uint32_t  DEN;            /*!< GPIO Digital Enable            */
    volatile       uint32_t  LOCK;           /*!< GPIO Lock                      */
    volatile       uint32_t  CR;             /*!< GPIO Commit                    */
    volatile       uint32_t  AMSEL;          /*!< GPIO Analog Mode Select        */
    volatile       uint32_t  PCTL;           /*!< GPIO Port Control              */
    volatile       uint32_t  ADCCTL;         /*!< GPIO ADC Control               */
    volatile       uint32_t  DMACTL;         /*!< GPIO DMA Control               */
}GPIOF_Type;

/**
  * @brief Register map for SYSCTL peripheral (SYSCTL)
  */

typedef struct {                             /*!< SYSCTL Structure                                  */
  volatile       uint32_t  DID0;             /*!< Device Identification 0                           */
  volatile       uint32_t  DID1;             /*!< Device Identification 1                           */
  volatile       uint32_t  DC0;              /*!< Device Capabilities 0                             */
  volatile const uint32_t  RESERVED;         /*!< RESERVED                                          */
  volatile       uint32_t  DC1;              /*!< Device Capabilities 1                             */
  volatile       uint32_t  DC2;              /*!< Device Capabilities 2                             */
  volatile       uint32_t  DC3;              /*!< Device Capabilities 3                             */
  volatile       uint32_t  DC4;              /*!< Device Capabilities 4                             */
  volatile       uint32_t  DC5;              /*!< Device Capabilities 5                             */
  volatile       uint32_t  DC6;              /*!< Device Capabilities 6                             */
  volatile       uint32_t  DC7;              /*!< Device Capabilities 7                             */
  volatile       uint32_t  DC8;              /*!< Device Capabilities 8                             */
  volatile       uint32_t  PBORCTL;          /*!< Brown-Out Reset Control                           */
  volatile const uint32_t  RESERVED1[3];     /*!< RESERVED1                                         */
  volatile       uint32_t  SRCR0;            /*!< Software Reset Control 0                          */
  volatile       uint32_t  SRCR1;            /*!< Software Reset Control 1                          */
  volatile       uint32_t  SRCR2;            /*!< Software Reset Control 2                          */
  volatile const uint32_t  RESERVED2;        /*!< RESERVED2                                         */
  volatile       uint32_t  RIS;              /*!< Raw Interrupt Status                              */
  volatile       uint32_t  IMC;              /*!< Interrupt Mask Control                            */
  volatile       uint32_t  MISC;             /*!< Masked Interrupt Status and Clear                 */
  volatile       uint32_t  RESC;             /*!< Reset Cause                                       */
  volatile       uint32_t  RCC;              /*!< Run-Mode Clock Configuration                      */
  volatile const uint32_t  RESERVED3[2];     /*!< RESERVED3                                         */
  volatile       uint32_t  GPIOHBCTL;        /*!< GPIO High-Performance Bus Control                 */
  volatile       uint32_t  RCC2;             /*!< Run-Mode Clock Configuration 2                    */
  volatile const uint32_t  RESERVED4[2];     /*!< RESERVED4                                         */
  volatile       uint32_t  MOSCCTL;          /*!< Main Oscillator Control                           */
  volatile const uint32_t  RESERVED5[32];    /*!< RESERVED5                                         */
  volatile       uint32_t  RCGC0;            /*!< Run Mode Clock Gating Control Register 0          */
  volatile       uint32_t  RCGC1;            /*!< Run Mode Clock Gating Control Register 1          */
  volatile       uint32_t  RCGC2;            /*!< Run Mode Clock Gating Control Register 2          */
  volatile const uint32_t  RESERVED6;        /*!< RESERVED6                                         */
  volatile       uint32_t  SCGC0;            /*!< Sleep Mode Clock Gating Control Register 0        */
  volatile       uint32_t  SCGC1;            /*!< Sleep Mode Clock Gating Control Register 1        */
  volatile       uint32_t  SCGC2;            /*!< Sleep Mode Clock Gating Control Register 2        */
  volatile const uint32_t  RESERVED7;        /*!< RESERVED7                                         */
  volatile       uint32_t  DCGC0;            /*!< Deep Sleep Mode Clock Gating Control Register 0   */
  volatile       uint32_t  DCGC1;            /*!< Deep-Sleep Mode Clock Gating Control Register 1   */
  volatile       uint32_t  DCGC2;            /*!< Deep Sleep Mode Clock Gating Control Register 2   */
  volatile const uint32_t  RESERVED8[6];     /*!< RESERVED8                                         */
  volatile       uint32_t  DSLPCLKCFG;       /*!< Deep Sleep Clock Configuration                    */
  volatile const uint32_t  RESERVED9;        /*!< RESERVED9                                         */
  volatile       uint32_t  SYSPROP;          /*!< System Properties                                 */
  volatile       uint32_t  PIOSCCAL;         /*!< Precision Internal Oscillator Calibration         */
  volatile       uint32_t  PIOSCSTAT;        /*!< Precision Internal Oscillator Statistics          */
  volatile const uint32_t  RESERVED10[2];    /*!< RESERVED10                                        */
  volatile       uint32_t  PLLFREQ0;         /*!< PLL Frequency 0                                   */
  volatile       uint32_t  PLLFREQ1;         /*!< PLL Frequency 1                                   */
  volatile       uint32_t  PLLSTAT;          /*!< PLL Status                                        */
  volatile const uint32_t  RESERVED11[7];    /*!< RESERVED11                                        */
  volatile       uint32_t  SLPPWRCFG;        /*!< Sleep Power Configuration                         */
  volatile       uint32_t  DSLPPWRCFG;       /*!< Deep-Sleep Power Configuration                    */
  volatile       uint32_t  DC9;              /*!< Device Capabilities 9                             */
  volatile const uint32_t  RESERVED12[3];    /*!< RESERVED12                                        */
  volatile       uint32_t  NVMSTAT;          /*!< Non-Volatile Memory Information                   */
  volatile const uint32_t  RESERVED13[4];    /*!< RESERVED13                                        */
  volatile       uint32_t  LDOSPCTL;         /*!< LDO Sleep Power Control                           */
  volatile const uint32_t  RESERVED14;       /*!< RESERVED14                                        */
  volatile       uint32_t  LDODPCTL;         /*!< LDO Deep-Sleep Power Control                      */
  volatile const uint32_t  RESERVED15[80];   /*!< RESERVED15                                        */
  volatile       uint32_t  PPWD;             /*!< Watchdog Timer Peripheral Present                 */
  volatile       uint32_t  PPTIMER;          /*!< 16/32-Bit General-Purpose Timer Peripheral Present*/
  volatile       uint32_t  PPGPIO;           /*!< General-Purpose Input/Output Peripheral Present   */
  volatile       uint32_t  PPDMA;            /*!< Micro Direct Memory Access Peripheral Present     */
  volatile const uint32_t  RESERVED16;       /*!< RESERVED16                                        */
  volatile       uint32_t  PPHIB;            /*!< Hibernation Peripheral Present                    */
  volatile       uint32_t  PPUART;           /*!< UART Peripheral Present                           */
  volatile       uint32_t  PPSSI;            /*!< Synchronous Serial Interface Peripheral Present   */
  volatile       uint32_t  PPI2C;            /*!< Inter-Integrated Circuit Peripheral Present       */
  volatile const uint32_t  RESERVED17;       /*!< RESERVED17                                        */
  volatile       uint32_t  PPUSB;            /*!< Universal Serial Bus Peripheral Present           */
  volatile const uint32_t  RESERVED18[2];    /*!< RESERVED18                                        */
  volatile       uint32_t  PPCAN;            /*!< Controller Area Network Peripheral Present        */
  volatile       uint32_t  PPADC;            /*!< Analog-to-Digital Converter Peripheral Present    */
  volatile       uint32_t  PPACMP;           /*!< Analog Comparator Peripheral Present              */
  volatile       uint32_t  PPPWM;            /*!< Pulse Width Modulator Peripheral Present          */
  volatile       uint32_t  PPQEI;            /*!< Quadrature Encoder Interface Peripheral Present   */
  volatile const uint32_t  RESERVED19[4];    /*!< RESERVED19                                        */
  volatile       uint32_t  PPEEPROM;         /*!< EEPROM Peripheral Present     */
  volatile       uint32_t  PPWTIMER;         /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Present  */
  volatile const uint32_t  RESERVED20[104];  /*!< RESERVED20                                        */
  volatile       uint32_t  SRWD;             /*!< Watchdog Timer Software Reset */
  volatile       uint32_t  SRTIMER;          /*!< 16/32-Bit General-Purpose Timer Software Reset    */
  volatile       uint32_t  SRGPIO;           /*!< General-Purpose Input/Output Software Reset       */
  volatile       uint32_t  SRDMA;            /*!< Micro Direct Memory Access Software Reset         */
  volatile const uint32_t  RESERVED21;       /*!< RESERVED21                                        */
  volatile       uint32_t  SRHIB;            /*!< Hibernation Software Reset    */
  volatile       uint32_t  SRUART;           /*!< Universal Asynchronous Receiver/Transmitter Software Reset            */
  volatile       uint32_t  SRSSI;            /*!< Synchronous Serial Interface Software Reset       */
  volatile       uint32_t  SRI2C;            /*!< Inter-Integrated Circuit Software Reset           */
  volatile const uint32_t  RESERVED22;       /*!< RESERVED22                                        */
  volatile       uint32_t  SRUSB;            /*!< Universal Serial Bus Software Reset               */
  volatile const uint32_t  RESERVED23[2];    /*!< RESERVED23                                        */
  volatile       uint32_t  SRCAN;            /*!< Controller Area Network Software Reset            */
  volatile       uint32_t  SRADC;            /*!< Analog-to-Digital Converter Software Reset        */
  volatile       uint32_t  SRACMP;           /*!< Analog Comparator Software Reset                  */
  volatile       uint32_t  SRPWM;            /*!< Pulse Width Modulator Software Reset              */
  volatile       uint32_t  SRQEI;            /*!< Quadrature Encoder Interface Software Reset       */
  volatile const uint32_t  RESERVED24[4];    /*!< RESERVED24                                        */
  volatile       uint32_t  SREEPROM;         /*!< EEPROM Software Reset                             */
  volatile       uint32_t  SRWTIMER;         /*!< 32/64-Bit Wide General-Purpose Timer Software Reset                   */
  volatile const uint32_t  RESERVED25[40];   /*!< RESERVED25                                        */
  volatile       uint32_t  RCGCWD;           /*!< Watchdog Timer Run Mode Clock Gating Control      */
  volatile       uint32_t  RCGCTIMER;        /*!< 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control         */
  volatile       uint32_t  RCGCGPIO;         /*!< General-Purpose Input/Output Run Mode Clock Gating Control            */
  volatile       uint32_t  RCGCDMA;          /*!< Micro Direct Memory Access Run Mode Clock Gating Control              */
  volatile const uint32_t  RESERVED26;       /*!< RESERVED26                                        */
  volatile       uint32_t  RCGCHIB;          /*!< Hibernation Run Mode Clock Gating Control         */
  volatile       uint32_t  RCGCUART;         /*!< Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating
                                                         Control                       */
  volatile       uint32_t  RCGCSSI;          /*!< Synchronous Serial Interface Run Mode Clock Gating Control            */
  volatile       uint32_t  RCGCI2C;          /*!< Inter-Integrated Circuit Run Mode Clock Gating Control                */
  volatile const uint32_t  RESERVED27;       /*!< RESERVED27                                        */
  volatile       uint32_t  RCGCUSB;          /*!< Universal Serial Bus Run Mode Clock Gating Control*/
  volatile const uint32_t  RESERVED28[2];    /*!< RESERVED28                                        */
  volatile       uint32_t  RCGCCAN;          /*!< Controller Area Network Run Mode Clock Gating Control                 */
  volatile       uint32_t  RCGCADC;          /*!< Analog-to-Digital Converter Run Mode Clock Gating Control             */
  volatile       uint32_t  RCGCACMP;         /*!< Analog Comparator Run Mode Clock Gating Control   */
  volatile       uint32_t  RCGCPWM;          /*!< Pulse Width Modulator Run Mode Clock Gating Control                   */
  volatile       uint32_t  RCGCQEI;          /*!< Quadrature Encoder Interface Run Mode Clock Gating Control            */
  volatile const uint32_t  RESERVED29[4];    /*!< RESERVED29                                        */
  volatile       uint32_t  RCGCEEPROM;       /*!< EEPROM Run Mode Clock Gating Control              */
  volatile       uint32_t  RCGCWTIMER;       /*!< 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control    */
  volatile const uint32_t  RESERVED30[40];   /*!< RESERVED30                                        */
  volatile       uint32_t  SCGCWD;           /*!< Watchdog Timer Sleep Mode Clock Gating Control    */
  volatile       uint32_t  SCGCTIMER;        /*!< 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control       */
  volatile       uint32_t  SCGCGPIO;         /*!< General-Purpose Input/Output Sleep Mode Clock Gating Control          */
  volatile       uint32_t  SCGCDMA;          /*!< Micro Direct Memory Access Sleep Mode Clock Gating Control            */
  volatile const uint32_t  RESERVED31;
  volatile       uint32_t  SCGCHIB;          /*!< Hibernation Sleep Mode Clock Gating Control       */
  volatile       uint32_t  SCGCUART;         /*!< Universal Asynchronous Receiver/Transmitter Sleep Mode Clock
                                                         Gating Control                */
  volatile       uint32_t  SCGCSSI;          /*!< Synchronous Serial Interface Sleep Mode Clock Gating Control          */
  volatile       uint32_t  SCGCI2C;          /*!< Inter-Integrated Circuit Sleep Mode Clock Gating Control              */
  volatile const uint32_t  RESERVED32;
  volatile       uint32_t  SCGCUSB;          /*!< Universal Serial Bus Sleep Mode Clock Gating Control                  */
  volatile const uint32_t  RESERVED33[2];
  volatile       uint32_t  SCGCCAN;          /*!< Controller Area Network Sleep Mode Clock Gating Control               */
  volatile       uint32_t  SCGCADC;          /*!< Analog-to-Digital Converter Sleep Mode Clock Gating Control           */
  volatile       uint32_t  SCGCACMP;         /*!< Analog Comparator Sleep Mode Clock Gating Control */
  volatile       uint32_t  SCGCPWM;          /*!< Pulse Width Modulator Sleep Mode Clock Gating Control                 */
  volatile       uint32_t  SCGCQEI;          /*!< Quadrature Encoder Interface Sleep Mode Clock Gating Control          */
  volatile const uint32_t  RESERVED34[4];
  volatile       uint32_t  SCGCEEPROM;       /*!< EEPROM Sleep Mode Clock Gating Control            */
  volatile       uint32_t  SCGCWTIMER;       /*!< 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating
                                                         Control                       */
  volatile const uint32_t  RESERVED35[40];
  volatile       uint32_t  DCGCWD;           /*!< Watchdog Timer Deep-Sleep Mode Clock Gating Control                   */
  volatile       uint32_t  DCGCTIMER;        /*!< 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                       */
  volatile       uint32_t  DCGCGPIO;         /*!< General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control     */
  volatile       uint32_t  DCGCDMA;          /*!< Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control       */
  volatile const uint32_t  RESERVED36;
  volatile       uint32_t  DCGCHIB;          /*!< Hibernation Deep-Sleep Mode Clock Gating Control  */
  volatile       uint32_t  DCGCUART;         /*!< Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode
                                                         Clock Gating Control          */
  volatile       uint32_t  DCGCSSI;          /*!< Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control     */
  volatile       uint32_t  DCGCI2C;          /*!< Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control         */
  volatile const uint32_t  RESERVED37;
  volatile       uint32_t  DCGCUSB;          /*!< Universal Serial Bus Deep-Sleep Mode Clock Gating Control             */
  volatile const uint32_t  RESERVED38[2];
  volatile       uint32_t  DCGCCAN;          /*!< Controller Area Network Deep-Sleep Mode Clock Gating Control          */
  volatile       uint32_t  DCGCADC;          /*!< Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control      */
  volatile       uint32_t  DCGCACMP;         /*!< Analog Comparator Deep-Sleep Mode Clock Gating Control                */
  volatile       uint32_t  DCGCPWM;          /*!< Pulse Width Modulator Deep-Sleep Mode Clock Gating Control            */
  volatile       uint32_t  DCGCQEI;          /*!< Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control     */
  volatile const uint32_t  RESERVED39[4];
  volatile       uint32_t  DCGCEEPROM;       /*!< EEPROM Deep-Sleep Mode Clock Gating Control       */
  volatile       uint32_t  DCGCWTIMER;       /*!< 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                       */
  volatile const uint32_t  RESERVED40[104];
  volatile       uint32_t  PRWD;             /*!< Watchdog Timer Peripheral Ready                   */
  volatile       uint32_t  PRTIMER;          /*!< 16/32-Bit General-Purpose Timer Peripheral Ready  */
  volatile       uint32_t  PRGPIO;           /*!< General-Purpose Input/Output Peripheral Ready     */
  volatile       uint32_t  PRDMA;            /*!< Micro Direct Memory Access Peripheral Ready       */
  volatile const uint32_t  RESERVED41;
  volatile       uint32_t  PRHIB;            /*!< Hibernation Peripheral Ready  */
  volatile       uint32_t  PRUART;           /*!< Universal Asynchronous Receiver/Transmitter Peripheral Ready          */
  volatile       uint32_t  PRSSI;            /*!< Synchronous Serial Interface Peripheral Ready     */
  volatile       uint32_t  PRI2C;            /*!< Inter-Integrated Circuit Peripheral Ready         */
  volatile const uint32_t  RESERVED42;
  volatile       uint32_t  PRUSB;            /*!< Universal Serial Bus Peripheral Ready             */
  volatile const uint32_t  RESERVED43[2];
  volatile       uint32_t  PRCAN;            /*!< Controller Area Network Peripheral Ready          */
  volatile       uint32_t  PRADC;            /*!< Analog-to-Digital Converter Peripheral Ready      */
  volatile       uint32_t  PRACMP;           /*!< Analog Comparator Peripheral Ready                */
  volatile       uint32_t  PRPWM;            /*!< Pulse Width Modulator Peripheral Ready            */
  volatile       uint32_t  PRQEI;            /*!< Quadrature Encoder Interface Peripheral Ready     */
  volatile const uint32_t  RESERVED44[4];
  volatile       uint32_t  PREEPROM;         /*!< EEPROM Peripheral Ready       */
  volatile       uint32_t  PRWTIMER;         /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Ready                 */
} SYSCTL_Type;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TM4C123GH6PM_H */