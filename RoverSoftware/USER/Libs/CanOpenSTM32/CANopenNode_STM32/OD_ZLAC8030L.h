/*******************************************************************************
    CANopen Object Dictionary definition for CANopenNode V4

    This file was automatically generated by CANopenEditor v4.2-0-g3735e28

    https://github.com/CANopenNode/CANopenNode
    https://github.com/CANopenNode/CANopenEditor

    DON'T EDIT THIS FILE MANUALLY !!!!
********************************************************************************

    File info:
        File Names:   OD_ZLAC8030L.h; OD_ZLAC8030L.c
        Project File: RoverMasterNode_30_V1.0.xdd
        File Version: 1

        Created:      9/25/2024 2:42:24 PM
        Created By:   
        Modified:     10/21/2024 2:23:26 PM
        Modified By:  

    Device Info:
        Vendor Name:  
        Vendor ID:    
        Product Name: RoverMasterNode
        Product ID:   

        Description:  STM32
*******************************************************************************/

#ifndef OD_ZLAC8030L_H
#define OD_ZLAC8030L_H
/*******************************************************************************
    Counters of OD objects
*******************************************************************************/
#define OD_ZLAC8030L_CNT_NMT 1
#define OD_ZLAC8030L_CNT_EM 1
#define OD_ZLAC8030L_CNT_SYNC 1
#define OD_ZLAC8030L_CNT_SYNC_PROD 1
#define OD_ZLAC8030L_CNT_STORAGE 1
#define OD_ZLAC8030L_CNT_TIME 1
#define OD_ZLAC8030L_CNT_EM_PROD 1
#define OD_ZLAC8030L_CNT_HB_CONS 1
#define OD_ZLAC8030L_CNT_HB_PROD 1
#define OD_ZLAC8030L_CNT_SDO_SRV 1
#define OD_ZLAC8030L_CNT_SDO_CLI 2
#define OD_ZLAC8030L_CNT_RPDO 4
#define OD_ZLAC8030L_CNT_TPDO 4


/*******************************************************************************
    Sizes of OD arrays
*******************************************************************************/
#define OD_ZLAC8030L_CNT_ARR_1003 16
#define OD_ZLAC8030L_CNT_ARR_1010 4
#define OD_ZLAC8030L_CNT_ARR_1011 4
#define OD_ZLAC8030L_CNT_ARR_1016 8
#define OD_ZLAC8030L_CNT_ARR_1029 2
#define OD_ZLAC8030L_CNT_ARR_2013 2
#define OD_ZLAC8030L_CNT_ARR_2026 2
#define OD_ZLAC8030L_CNT_ARR_6083 2
#define OD_ZLAC8030L_CNT_ARR_6084 2


/*******************************************************************************
    OD data declaration of all groups
*******************************************************************************/
typedef struct {
    uint32_t x1000_deviceType;
    uint32_t x1005_COB_ID_SYNCMessage;
    uint32_t x1006_communicationCyclePeriod;
    uint32_t x1007_synchronousWindowLength;
    uint16_t x100C_guardTime;
    uint8_t x100D_lifeTimeFactor;
    uint32_t x1012_COB_IDTimeStampObject;
    uint32_t x1014_COB_ID_EMCY;
    uint16_t x1015_inhibitTimeEMCY;
    uint8_t x1016_consumerHeartbeatTime_sub0;
    uint32_t x1016_consumerHeartbeatTime[OD_ZLAC8030L_CNT_ARR_1016];
    uint16_t x1017_producerHeartbeatTime;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t vendor_ID;
        uint32_t productCode;
        uint32_t revisionNumber;
        uint32_t serialNumber;
    } x1018_identity;
    uint8_t x1019_synchronousCounterOverflowValue;
    uint8_t x1029_errorBehaviorObject_sub0;
    uint8_t x1029_errorBehaviorObject[OD_ZLAC8030L_CNT_ARR_1029];
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDClientToServerTx;
        uint32_t COB_IDServerToClientRx;
        uint8_t node_IDOfTheSDOClient;
    } x1280_SDOClientParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDClientToServerTx;
        uint32_t COB_IDServerToClientRx;
        uint8_t node_IDOfTheSDOClient;
    } x1281_SDOClientParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByRPDO;
        uint8_t transmissionType;
        uint16_t eventTimer;
    } x1400_RPDOCommunicationParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByRPDO;
        uint8_t transmissionType;
        uint16_t eventTimer;
    } x1401_RPDOCommunicationParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByRPDO;
        uint8_t transmissionType;
        uint16_t eventTimer;
    } x1402_RPDOCommunicationParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByRPDO;
        uint8_t transmissionType;
        uint16_t eventTimer;
    } x1403_RPDOCommunicationParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1600_RPDOMappingParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1601_RPDOMappingParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1602_RPDOMappingParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1603_RPDOMappingParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByTPDO;
        uint8_t transmissionType;
        uint16_t inhibitTime;
        uint16_t eventTimer;
        uint8_t SYNCStartValue;
    } x1800_TPDOCommunicationParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByTPDO;
        uint8_t transmissionType;
        uint16_t inhibitTime;
        uint16_t eventTimer;
        uint8_t SYNCStartValue;
    } x1801_TPDOCommunicationParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByTPDO;
        uint8_t transmissionType;
        uint16_t inhibitTime;
        uint16_t eventTimer;
        uint8_t SYNCStartValue;
    } x1802_TPDOCommunicationParameter;
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDUsedByTPDO;
        uint8_t transmissionType;
        uint16_t inhibitTime;
        uint16_t eventTimer;
        uint8_t SYNCStartValue;
    } x1803_TPDOCommunicationParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1A00_TPDOMappingParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1A01_TPDOMappingParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1A02_TPDOMappingParameter;
    struct {
        uint8_t numberOfMappedApplicationObjectsInPDO;
        uint32_t applicationObject1;
        uint32_t applicationObject2;
        uint32_t applicationObject3;
        uint32_t applicationObject4;
        uint32_t applicationObject5;
        uint32_t applicationObject6;
        uint32_t applicationObject7;
        uint32_t applicationObject8;
    } x1A03_TPDOMappingParameter;
    uint16_t x2008_turnOnSpeed;
    uint16_t x2009_registerConfiguration;
    uint16_t x200D_CANID;
    int16_t x200F_syncFlag;
    uint32_t x2015_maxCurrent;
    uint8_t x2026_temperature_sub0;
    uint16_t x2026_temperature[OD_ZLAC8030L_CNT_ARR_2026];
    uint16_t x2027_motorStateRegister;
    uint16_t x2028_hallInputState;
    uint16_t x6040_controlWord;
    uint16_t x6041_stateWord;
    int8_t x6060_motionMode;
    uint32_t x6061_motionModeState;
    int32_t x606C_currentSpeedFeedBack;
    int16_t x6071_targetTorque;
    int16_t x6074_realTimeCommandTorque;
    int16_t x6077_realTimeTorqueFeedback;
    int32_t x607A_targetPosition;
    uint32_t x6081_maxSpeedPositionMode;
    uint32_t x6082_starStopSpeedPositionMode;
    uint8_t x6083_STypeAccelerationTime_sub0;
    uint32_t x6083_STypeAccelerationTime[OD_ZLAC8030L_CNT_ARR_6083];
    uint8_t x6084_STypeDecelerationTime_sub0;
    uint32_t x6084_STypeDecelerationTime[OD_ZLAC8030L_CNT_ARR_6084];
    uint32_t x6085_emergencyStopDecelerationTime;
    uint32_t x6087_torqueSlope;
    int32_t x60FF_targetSpeed;
    uint16_t x7040_controlWord;
    int32_t x706C_currentSpeedFeedBack;
    int32_t x70FF_targetSpeed;
} OD_ZLAC8030L_PERSIST_COMM_t;

typedef struct {
    uint8_t x1001_errorRegister;
    uint32_t x1002_manufacturerStatusRegister;
    uint8_t x1010_storeParameters_sub0;
    uint32_t x1010_storeParameters[OD_ZLAC8030L_CNT_ARR_1010];
    uint8_t x1011_restoreDefaultParameters_sub0;
    uint32_t x1011_restoreDefaultParameters[OD_ZLAC8030L_CNT_ARR_1011];
    struct {
        uint8_t highestSub_indexSupported;
        uint32_t COB_IDClientToServerRx;
        uint32_t COB_IDServerToClientTx;
    } x1200_SDOServerParameter;
    uint32_t x2005_clearFeedbackBit;
    uint32_t x2006_clearCurrentPositionBit;
    uint32_t x2007_limitedStopMethod;
    uint16_t x200A_maxSpeed;
    uint8_t x2013_temperatureThreshold_sub0;
    uint16_t x2013_temperatureThreshold[OD_ZLAC8030L_CNT_ARR_2013];
    uint16_t x2014_ratedCurrent;
} OD_ZLAC8030L_RAM_t;

#ifndef OD_ZLAC8030L_ATTR_PERSIST_COMM
#define OD_ZLAC8030L_ATTR_PERSIST_COMM
#endif
extern OD_ZLAC8030L_ATTR_PERSIST_COMM OD_ZLAC8030L_PERSIST_COMM_t OD_ZLAC8030L_PERSIST_COMM;

#ifndef OD_ZLAC8030L_ATTR_RAM
#define OD_ZLAC8030L_ATTR_RAM
#endif
extern OD_ZLAC8030L_ATTR_RAM OD_ZLAC8030L_RAM_t OD_ZLAC8030L_RAM;

#ifndef OD_ZLAC8030L_ATTR_OD
#define OD_ZLAC8030L_ATTR_OD
#endif
extern OD_ZLAC8030L_ATTR_OD OD_t *OD_ZLAC8030L;


/*******************************************************************************
    Object dictionary entries - shortcuts
*******************************************************************************/
#define OD_ZLAC8030L_ENTRY_H1000 &OD_ZLAC8030L->list[0]
#define OD_ZLAC8030L_ENTRY_H1001 &OD_ZLAC8030L->list[1]
#define OD_ZLAC8030L_ENTRY_H1002 &OD_ZLAC8030L->list[2]
#define OD_ZLAC8030L_ENTRY_H1003 &OD_ZLAC8030L->list[3]
#define OD_ZLAC8030L_ENTRY_H1005 &OD_ZLAC8030L->list[4]
#define OD_ZLAC8030L_ENTRY_H1006 &OD_ZLAC8030L->list[5]
#define OD_ZLAC8030L_ENTRY_H1007 &OD_ZLAC8030L->list[6]
#define OD_ZLAC8030L_ENTRY_H1008 &OD_ZLAC8030L->list[7]
#define OD_ZLAC8030L_ENTRY_H1009 &OD_ZLAC8030L->list[8]
#define OD_ZLAC8030L_ENTRY_H100A &OD_ZLAC8030L->list[9]
#define OD_ZLAC8030L_ENTRY_H100C &OD_ZLAC8030L->list[10]
#define OD_ZLAC8030L_ENTRY_H100D &OD_ZLAC8030L->list[11]
#define OD_ZLAC8030L_ENTRY_H1010 &OD_ZLAC8030L->list[12]
#define OD_ZLAC8030L_ENTRY_H1011 &OD_ZLAC8030L->list[13]
#define OD_ZLAC8030L_ENTRY_H1012 &OD_ZLAC8030L->list[14]
#define OD_ZLAC8030L_ENTRY_H1014 &OD_ZLAC8030L->list[15]
#define OD_ZLAC8030L_ENTRY_H1015 &OD_ZLAC8030L->list[16]
#define OD_ZLAC8030L_ENTRY_H1016 &OD_ZLAC8030L->list[17]
#define OD_ZLAC8030L_ENTRY_H1017 &OD_ZLAC8030L->list[18]
#define OD_ZLAC8030L_ENTRY_H1018 &OD_ZLAC8030L->list[19]
#define OD_ZLAC8030L_ENTRY_H1019 &OD_ZLAC8030L->list[20]
#define OD_ZLAC8030L_ENTRY_H1029 &OD_ZLAC8030L->list[21]
#define OD_ZLAC8030L_ENTRY_H1200 &OD_ZLAC8030L->list[22]
#define OD_ZLAC8030L_ENTRY_H1280 &OD_ZLAC8030L->list[23]
#define OD_ZLAC8030L_ENTRY_H1281 &OD_ZLAC8030L->list[24]
#define OD_ZLAC8030L_ENTRY_H1400 &OD_ZLAC8030L->list[25]
#define OD_ZLAC8030L_ENTRY_H1401 &OD_ZLAC8030L->list[26]
#define OD_ZLAC8030L_ENTRY_H1402 &OD_ZLAC8030L->list[27]
#define OD_ZLAC8030L_ENTRY_H1403 &OD_ZLAC8030L->list[28]
#define OD_ZLAC8030L_ENTRY_H1600 &OD_ZLAC8030L->list[29]
#define OD_ZLAC8030L_ENTRY_H1601 &OD_ZLAC8030L->list[30]
#define OD_ZLAC8030L_ENTRY_H1602 &OD_ZLAC8030L->list[31]
#define OD_ZLAC8030L_ENTRY_H1603 &OD_ZLAC8030L->list[32]
#define OD_ZLAC8030L_ENTRY_H1800 &OD_ZLAC8030L->list[33]
#define OD_ZLAC8030L_ENTRY_H1801 &OD_ZLAC8030L->list[34]
#define OD_ZLAC8030L_ENTRY_H1802 &OD_ZLAC8030L->list[35]
#define OD_ZLAC8030L_ENTRY_H1803 &OD_ZLAC8030L->list[36]
#define OD_ZLAC8030L_ENTRY_H1A00 &OD_ZLAC8030L->list[37]
#define OD_ZLAC8030L_ENTRY_H1A01 &OD_ZLAC8030L->list[38]
#define OD_ZLAC8030L_ENTRY_H1A02 &OD_ZLAC8030L->list[39]
#define OD_ZLAC8030L_ENTRY_H1A03 &OD_ZLAC8030L->list[40]
#define OD_ZLAC8030L_ENTRY_H2005 &OD_ZLAC8030L->list[41]
#define OD_ZLAC8030L_ENTRY_H2006 &OD_ZLAC8030L->list[42]
#define OD_ZLAC8030L_ENTRY_H2007 &OD_ZLAC8030L->list[43]
#define OD_ZLAC8030L_ENTRY_H2008 &OD_ZLAC8030L->list[44]
#define OD_ZLAC8030L_ENTRY_H2009 &OD_ZLAC8030L->list[45]
#define OD_ZLAC8030L_ENTRY_H200A &OD_ZLAC8030L->list[46]
#define OD_ZLAC8030L_ENTRY_H200D &OD_ZLAC8030L->list[47]
#define OD_ZLAC8030L_ENTRY_H200F &OD_ZLAC8030L->list[48]
#define OD_ZLAC8030L_ENTRY_H2013 &OD_ZLAC8030L->list[49]
#define OD_ZLAC8030L_ENTRY_H2014 &OD_ZLAC8030L->list[50]
#define OD_ZLAC8030L_ENTRY_H2015 &OD_ZLAC8030L->list[51]
#define OD_ZLAC8030L_ENTRY_H2026 &OD_ZLAC8030L->list[52]
#define OD_ZLAC8030L_ENTRY_H2027 &OD_ZLAC8030L->list[53]
#define OD_ZLAC8030L_ENTRY_H2028 &OD_ZLAC8030L->list[54]
#define OD_ZLAC8030L_ENTRY_H6040 &OD_ZLAC8030L->list[55]
#define OD_ZLAC8030L_ENTRY_H6041 &OD_ZLAC8030L->list[56]
#define OD_ZLAC8030L_ENTRY_H6060 &OD_ZLAC8030L->list[57]
#define OD_ZLAC8030L_ENTRY_H6061 &OD_ZLAC8030L->list[58]
#define OD_ZLAC8030L_ENTRY_H606C &OD_ZLAC8030L->list[59]
#define OD_ZLAC8030L_ENTRY_H6071 &OD_ZLAC8030L->list[60]
#define OD_ZLAC8030L_ENTRY_H6074 &OD_ZLAC8030L->list[61]
#define OD_ZLAC8030L_ENTRY_H6077 &OD_ZLAC8030L->list[62]
#define OD_ZLAC8030L_ENTRY_H607A &OD_ZLAC8030L->list[63]
#define OD_ZLAC8030L_ENTRY_H6081 &OD_ZLAC8030L->list[64]
#define OD_ZLAC8030L_ENTRY_H6082 &OD_ZLAC8030L->list[65]
#define OD_ZLAC8030L_ENTRY_H6083 &OD_ZLAC8030L->list[66]
#define OD_ZLAC8030L_ENTRY_H6084 &OD_ZLAC8030L->list[67]
#define OD_ZLAC8030L_ENTRY_H6085 &OD_ZLAC8030L->list[68]
#define OD_ZLAC8030L_ENTRY_H6087 &OD_ZLAC8030L->list[69]
#define OD_ZLAC8030L_ENTRY_H60FF &OD_ZLAC8030L->list[70]
#define OD_ZLAC8030L_ENTRY_H7040 &OD_ZLAC8030L->list[71]
#define OD_ZLAC8030L_ENTRY_H706C &OD_ZLAC8030L->list[72]
#define OD_ZLAC8030L_ENTRY_H70FF &OD_ZLAC8030L->list[73]


/*******************************************************************************
    Object dictionary entries - shortcuts with names
*******************************************************************************/
#define OD_ZLAC8030L_ENTRY_H1000_deviceType &OD_ZLAC8030L->list[0]
#define OD_ZLAC8030L_ENTRY_H1001_errorRegister &OD_ZLAC8030L->list[1]
#define OD_ZLAC8030L_ENTRY_H1002_manufacturerStatusRegister &OD_ZLAC8030L->list[2]
#define OD_ZLAC8030L_ENTRY_H1003_pre_definedErrorField &OD_ZLAC8030L->list[3]
#define OD_ZLAC8030L_ENTRY_H1005_COB_ID_SYNCMessage &OD_ZLAC8030L->list[4]
#define OD_ZLAC8030L_ENTRY_H1006_communicationCyclePeriod &OD_ZLAC8030L->list[5]
#define OD_ZLAC8030L_ENTRY_H1007_synchronousWindowLength &OD_ZLAC8030L->list[6]
#define OD_ZLAC8030L_ENTRY_H1008_manufacturerDeviceName &OD_ZLAC8030L->list[7]
#define OD_ZLAC8030L_ENTRY_H1009_manufacturerHardwareVersion &OD_ZLAC8030L->list[8]
#define OD_ZLAC8030L_ENTRY_H100A_manufacturerSoftwareVersion &OD_ZLAC8030L->list[9]
#define OD_ZLAC8030L_ENTRY_H100C_guardTime &OD_ZLAC8030L->list[10]
#define OD_ZLAC8030L_ENTRY_H100D_lifeTimeFactor &OD_ZLAC8030L->list[11]
#define OD_ZLAC8030L_ENTRY_H1010_storeParameters &OD_ZLAC8030L->list[12]
#define OD_ZLAC8030L_ENTRY_H1011_restoreDefaultParameters &OD_ZLAC8030L->list[13]
#define OD_ZLAC8030L_ENTRY_H1012_COB_IDTimeStampObject &OD_ZLAC8030L->list[14]
#define OD_ZLAC8030L_ENTRY_H1014_COB_ID_EMCY &OD_ZLAC8030L->list[15]
#define OD_ZLAC8030L_ENTRY_H1015_inhibitTimeEMCY &OD_ZLAC8030L->list[16]
#define OD_ZLAC8030L_ENTRY_H1016_consumerHeartbeatTime &OD_ZLAC8030L->list[17]
#define OD_ZLAC8030L_ENTRY_H1017_producerHeartbeatTime &OD_ZLAC8030L->list[18]
#define OD_ZLAC8030L_ENTRY_H1018_identity &OD_ZLAC8030L->list[19]
#define OD_ZLAC8030L_ENTRY_H1019_synchronousCounterOverflowValue &OD_ZLAC8030L->list[20]
#define OD_ZLAC8030L_ENTRY_H1029_errorBehaviorObject &OD_ZLAC8030L->list[21]
#define OD_ZLAC8030L_ENTRY_H1200_SDOServerParameter &OD_ZLAC8030L->list[22]
#define OD_ZLAC8030L_ENTRY_H1280_SDOClientParameter &OD_ZLAC8030L->list[23]
#define OD_ZLAC8030L_ENTRY_H1281_SDOClientParameter &OD_ZLAC8030L->list[24]
#define OD_ZLAC8030L_ENTRY_H1400_RPDOCommunicationParameter &OD_ZLAC8030L->list[25]
#define OD_ZLAC8030L_ENTRY_H1401_RPDOCommunicationParameter &OD_ZLAC8030L->list[26]
#define OD_ZLAC8030L_ENTRY_H1402_RPDOCommunicationParameter &OD_ZLAC8030L->list[27]
#define OD_ZLAC8030L_ENTRY_H1403_RPDOCommunicationParameter &OD_ZLAC8030L->list[28]
#define OD_ZLAC8030L_ENTRY_H1600_RPDOMappingParameter &OD_ZLAC8030L->list[29]
#define OD_ZLAC8030L_ENTRY_H1601_RPDOMappingParameter &OD_ZLAC8030L->list[30]
#define OD_ZLAC8030L_ENTRY_H1602_RPDOMappingParameter &OD_ZLAC8030L->list[31]
#define OD_ZLAC8030L_ENTRY_H1603_RPDOMappingParameter &OD_ZLAC8030L->list[32]
#define OD_ZLAC8030L_ENTRY_H1800_TPDOCommunicationParameter &OD_ZLAC8030L->list[33]
#define OD_ZLAC8030L_ENTRY_H1801_TPDOCommunicationParameter &OD_ZLAC8030L->list[34]
#define OD_ZLAC8030L_ENTRY_H1802_TPDOCommunicationParameter &OD_ZLAC8030L->list[35]
#define OD_ZLAC8030L_ENTRY_H1803_TPDOCommunicationParameter &OD_ZLAC8030L->list[36]
#define OD_ZLAC8030L_ENTRY_H1A00_TPDOMappingParameter &OD_ZLAC8030L->list[37]
#define OD_ZLAC8030L_ENTRY_H1A01_TPDOMappingParameter &OD_ZLAC8030L->list[38]
#define OD_ZLAC8030L_ENTRY_H1A02_TPDOMappingParameter &OD_ZLAC8030L->list[39]
#define OD_ZLAC8030L_ENTRY_H1A03_TPDOMappingParameter &OD_ZLAC8030L->list[40]
#define OD_ZLAC8030L_ENTRY_H2005_clearFeedbackBit &OD_ZLAC8030L->list[41]
#define OD_ZLAC8030L_ENTRY_H2006_clearCurrentPositionBit &OD_ZLAC8030L->list[42]
#define OD_ZLAC8030L_ENTRY_H2007_limitedStopMethod &OD_ZLAC8030L->list[43]
#define OD_ZLAC8030L_ENTRY_H2008_turnOnSpeed &OD_ZLAC8030L->list[44]
#define OD_ZLAC8030L_ENTRY_H2009_registerConfiguration &OD_ZLAC8030L->list[45]
#define OD_ZLAC8030L_ENTRY_H200A_maxSpeed &OD_ZLAC8030L->list[46]
#define OD_ZLAC8030L_ENTRY_H200D_CANID &OD_ZLAC8030L->list[47]
#define OD_ZLAC8030L_ENTRY_H200F_syncFlag &OD_ZLAC8030L->list[48]
#define OD_ZLAC8030L_ENTRY_H2013_temperatureThreshold &OD_ZLAC8030L->list[49]
#define OD_ZLAC8030L_ENTRY_H2014_ratedCurrent &OD_ZLAC8030L->list[50]
#define OD_ZLAC8030L_ENTRY_H2015_maxCurrent &OD_ZLAC8030L->list[51]
#define OD_ZLAC8030L_ENTRY_H2026_temperature &OD_ZLAC8030L->list[52]
#define OD_ZLAC8030L_ENTRY_H2027_motorStateRegister &OD_ZLAC8030L->list[53]
#define OD_ZLAC8030L_ENTRY_H2028_hallInputState &OD_ZLAC8030L->list[54]
#define OD_ZLAC8030L_ENTRY_H6040_controlWord &OD_ZLAC8030L->list[55]
#define OD_ZLAC8030L_ENTRY_H6041_stateWord &OD_ZLAC8030L->list[56]
#define OD_ZLAC8030L_ENTRY_H6060_motionMode &OD_ZLAC8030L->list[57]
#define OD_ZLAC8030L_ENTRY_H6061_motionModeState &OD_ZLAC8030L->list[58]
#define OD_ZLAC8030L_ENTRY_H606C_currentSpeedFeedBack &OD_ZLAC8030L->list[59]
#define OD_ZLAC8030L_ENTRY_H6071_targetTorque &OD_ZLAC8030L->list[60]
#define OD_ZLAC8030L_ENTRY_H6074_realTimeCommandTorque &OD_ZLAC8030L->list[61]
#define OD_ZLAC8030L_ENTRY_H6077_realTimeTorqueFeedback &OD_ZLAC8030L->list[62]
#define OD_ZLAC8030L_ENTRY_H607A_targetPosition &OD_ZLAC8030L->list[63]
#define OD_ZLAC8030L_ENTRY_H6081_maxSpeedPositionMode &OD_ZLAC8030L->list[64]
#define OD_ZLAC8030L_ENTRY_H6082_starStopSpeedPositionMode &OD_ZLAC8030L->list[65]
#define OD_ZLAC8030L_ENTRY_H6083_STypeAccelerationTime &OD_ZLAC8030L->list[66]
#define OD_ZLAC8030L_ENTRY_H6084_STypeDecelerationTime &OD_ZLAC8030L->list[67]
#define OD_ZLAC8030L_ENTRY_H6085_emergencyStopDecelerationTime &OD_ZLAC8030L->list[68]
#define OD_ZLAC8030L_ENTRY_H6087_torqueSlope &OD_ZLAC8030L->list[69]
#define OD_ZLAC8030L_ENTRY_H60FF_targetSpeed &OD_ZLAC8030L->list[70]
#define OD_ZLAC8030L_ENTRY_H7040_controlWord &OD_ZLAC8030L->list[71]
#define OD_ZLAC8030L_ENTRY_H706C_currentSpeedFeedBack &OD_ZLAC8030L->list[72]
#define OD_ZLAC8030L_ENTRY_H70FF_targetSpeed &OD_ZLAC8030L->list[73]


/*******************************************************************************
    OD config structure
*******************************************************************************/
#ifdef CO_MULTIPLE_OD
#define OD_ZLAC8030L_INIT_CONFIG(config) {\
    (config).CNT_NMT = OD_ZLAC8030L_CNT_NMT;\
    (config).ENTRY_H1017 = OD_ZLAC8030L_ENTRY_H1017;\
    (config).CNT_HB_CONS = OD_ZLAC8030L_CNT_HB_CONS;\
    (config).CNT_ARR_1016 = OD_ZLAC8030L_CNT_ARR_1016;\
    (config).ENTRY_H1016 = OD_ZLAC8030L_ENTRY_H1016;\
    (config).CNT_EM = OD_ZLAC8030L_CNT_EM;\
    (config).ENTRY_H1001 = OD_ZLAC8030L_ENTRY_H1001;\
    (config).ENTRY_H1014 = OD_ZLAC8030L_ENTRY_H1014;\
    (config).ENTRY_H1015 = OD_ZLAC8030L_ENTRY_H1015;\
    (config).CNT_ARR_1003 = OD_ZLAC8030L_CNT_ARR_1003;\
    (config).ENTRY_H1003 = OD_ZLAC8030L_ENTRY_H1003;\
    (config).CNT_SDO_SRV = OD_ZLAC8030L_CNT_SDO_SRV;\
    (config).ENTRY_H1200 = OD_ZLAC8030L_ENTRY_H1200;\
    (config).CNT_SDO_CLI = OD_ZLAC8030L_CNT_SDO_CLI;\
    (config).ENTRY_H1280 = OD_ZLAC8030L_ENTRY_H1280;\
    (config).CNT_TIME = OD_ZLAC8030L_CNT_TIME;\
    (config).ENTRY_H1012 = OD_ZLAC8030L_ENTRY_H1012;\
    (config).CNT_SYNC = OD_ZLAC8030L_CNT_SYNC;\
    (config).ENTRY_H1005 = OD_ZLAC8030L_ENTRY_H1005;\
    (config).ENTRY_H1006 = OD_ZLAC8030L_ENTRY_H1006;\
    (config).ENTRY_H1007 = OD_ZLAC8030L_ENTRY_H1007;\
    (config).ENTRY_H1019 = OD_ZLAC8030L_ENTRY_H1019;\
    (config).CNT_RPDO = OD_ZLAC8030L_CNT_RPDO;\
    (config).ENTRY_H1400 = OD_ZLAC8030L_ENTRY_H1400;\
    (config).ENTRY_H1600 = OD_ZLAC8030L_ENTRY_H1600;\
    (config).CNT_TPDO = OD_ZLAC8030L_CNT_TPDO;\
    (config).ENTRY_H1800 = OD_ZLAC8030L_ENTRY_H1800;\
    (config).ENTRY_H1A00 = OD_ZLAC8030L_ENTRY_H1A00;\
    (config).CNT_LEDS = 0;\
    (config).CNT_GFC = 0;\
    (config).ENTRY_H1300 = NULL;\
    (config).CNT_SRDO = 0;\
    (config).ENTRY_H1301 = NULL;\
    (config).ENTRY_H1381 = NULL;\
    (config).ENTRY_H13FE = NULL;\
    (config).ENTRY_H13FF = NULL;\
    (config).CNT_LSS_SLV = 0;\
    (config).CNT_LSS_MST = 0;\
    (config).CNT_GTWA = 0;\
    (config).CNT_TRACE = 0;\
}
#endif

#endif /* OD_ZLAC8030L_H */
