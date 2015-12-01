/******************************************************************************

                  ��Ȩ���� (C), 2010-2015, ��������ͨ�����õ缼���ֹ�˾

 ******************************************************************************
  �� �� ��   : con3761adp.h
  �� �� ��   : ����
  ��    ��   : liming
  ��������   : 2013��4��8�� ����һ
  ����޸�   :
  ��������   : ������376.1Э���������� ͷ�ļ� 
  �����б�   :
  �޸���ʷ   :
  ��д˵��   : CM ����������վ   MC ��վ��������
  1.��    ��   : 2013��4��8�� ����һ
    ��    ��   : liming
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef _CON_3761_ADP_H_
#define _CON_3761_ADP_H_
#include "qgdw_3761_api.h"

#pragma pack(push)  // ����һ�ֽڶ���
#pragma pack(1)

typedef eMtErr eCmErr;

/* (1)������վ�뼯����ͨ��Э����������, ÿ�������һ��3761Э�� 
 * (2)��Э���ʮ������,ÿ����,���֧��255��������
 * (3)��Щ����ֻ������������,��Щ����֧�ָô��������������������,
 *    ����ϵ��������ʶ��Ψһ
 * (4)������д����Ҫע��ʵ��,��������API����֮��ֱ���໥ת��
*/
typedef enum
{
    CM_CMD_UNKOWN,                  // δ֪����  

    /* ȷ�ϨM���ϣ�AFN=00H�� */
    CMD_ALL_OK,                     // ȫ��ȷ��
    CMD_ALL_DENY,                   // ȫ������
    CMD_ONE_BY_ONE,                 // �����ݵ�Ԫ��ʶȷ�Ϻͷ���


    /* ��λ���AFN=01H�� */ 
    CMD_HARD_INIT,                  // Ӳ����ʼ��
    CMD_DATA_INIT,                  // ��������ʼ��
    CMD_FACTORY_RESET,              // ������ȫ����������ʼ�������ָ����������ã�
    CMD_PARA_INIT,                  // ����������ϵͳ��վͨ���йصģ���ȫ����������ʼ��


    /* ��·�ӿڼ�⣨AFN=02H�� */
    CMD_LOG_IN,                     // ��¼       �����ݵ�Ԫ
    CMD_LOG_OUT,                    // �˳���¼   �����ݵ�Ԫ
    CMD_HEART_BEAT,                 // ����       �����ݵ�Ԫ

    /* ���ò�����AFN == 04H�� */ 
    //CMD_CFG_NOT_ELEC ,            // �ǵ������������ݲ�������
                                    // 1���¶ȣ�2��������3�����٣�4��ѹ����
                                    // 5��ʪ�ȣ�6���նȣ�7��ת�٣�����������

    CMD_CFG_TML_UP,                 // ���� �ն�����ͨ�ſ�ͨ�Ų�������
    CMD_CFG_TML_POWER,              // ���� �ն˵��ܱ�/��������װ�����ò���
    CMD_CFG_ASK_1,                  // 1��������������(���ն�֧�ֵ�1������������) CMD_AFN_4_F38_CFG_ASK_1
    CMD_CFG_ASK_2,                  // 2��������������(���ն�֧�ֵ�2������������) CMD_AFN_4_F39_CFG_ASK_2
    CMD_CFG_AUTO_1,                 // ��ʱ�ϱ�1��������������    CMD_AFN_4_F65_CFG_AUTO_1
    CMD_CFG_AUTO_2,                 // ��ʱ�ϱ�2��������������    CMD_AFN_4_F66_CFG_AUTO_2
    CMD_GO_AUTO_1,                  // ��ʱ�ϱ�1��������������/ֹͣ���� CMD_AFN_4_F67_GOP_AUTO_1
    CMD_GO_AUTO_2,                  // ��ʱ�ϱ�2��������������/ֹͣ���� CMD_AFN_4_F68_GOP_AUTO_2

    /* �������AFN == 05H��*/
    CMD_CTRL_CHECK_TIME,            // ��ʱ����

    CMD_PERMIT_TALK_GO,             // �����ն�����վͨ��  û��Ӧ�ò����� pn = p0
    CMD_PERMIT_TALK_STOP,           // ��ֹ�ն�����վͨ��  û��Ӧ�ò����� pn = p0

    CMD_PERMIT_LINK_ON,             // �����ն�������վ    û��Ӧ�ò����� pn = p0
    CMD_PERMIT_LINK_OFF,            // �����ն˶Ͽ�����    û��Ӧ�ò����� pn = p0

    CMD_AUTO_REPORT_GO,             // �����ն������ϱ�   û��Ӧ�ò����� pn = p0
    CMD_AUTO_REPORT_STOP,           // ��ֹ�ն������ϱ�   û��Ӧ�ò����� pn = p0


    /* �������� (AFN == 09H�� */ 
    CMD_AFN_TML_VERSION,            // �ն˰汾��Ϣ  pn = p0  ��Ӧ���ݽṹ sMtTmlVersion
    CMD_AFN_TML_INPUT_OUT,          // �ն�֧�ֵ����롢�����ͨ�Ŷ˿�����  pn = p0  ��Ӧ���ݽṹ sMtTmlInputOut
    CMD_TML_OTHER_CFG,              // �ն�֧�ֵ���������  ��Ӧ���ݽṹ sMtTmlOtherCfg
    CMD_SUPPORT_PARA_CFG,           // �ն�֧�ֵĲ�������      CMD_AFN_9_F4_SUPPORT_PARA_CFG
    CMD_SUPPORT_CTRL_CFG,           // �ն�֧�ֵĿ�������      CMD_AFN_9_F5_SUPPORT_CTRL_CFG
    CMD_SUPPORT_ASK1_CFG,           // �ն�֧�ֵ�1����������   CMD_AFN_9_F6_SUPPORT_ASK1_CFG
    CMD_SUPPORT_ASK2_CFG,           // �ն�֧�ֵ�2����������   CMD_AFN_9_F7_SUPPORT_ASK2_CFG
    CMD_SUPPORT_EVNT_CFG,           // �ն�֧�ֵ��¼���¼����  CMD_AFN_9_F8_SUPPORT_EVNT_CFG
    
    /* ��ѯ������AFN == 0AH�� */ 
    CMD_CFG_TML_UP_Q,               // ��ѯ �ն�����ͨ�ſ�ͨ�Ų�������           CMD_AFN_A_F1_TML_UP_CFG
    CMD_CFG_TML_POWER_Q,            // ��ѯ �ն˵��ܱ�/��������װ�����ò���   (�����в��� sMtTmlPowerCfg_Q)   CMD_AFN_A_F10_TML_POWER_CFG
    CMD_CFG_ASK_1_Q,                // 1��������������(���ն�֧�ֵ�1������������) (�����в��� sMtAsk1Cfg_Q) CMD_AFN_A_F38_CFG_ASK_1
    CMD_CFG_ASK_2_Q,                // 2��������������(���ն�֧�ֵ�2������������) (�����в��� sMtAsk2Cfg_Q) CMD_AFN_A_F39_CFG_ASK_2
    CMD_CFG_AUTO_1_Q,               // ��ѯ��ʱ�ϱ�1��������������      CMD_AFN_A_F65_CFG_AUTO_1
    CMD_CFG_AUTO_2_Q,               // ��ѯ��ʱ�ϱ�2��������������      CMD_AFN_A_F66_CFG_AUTO_2
    CMD_GOP_AUTO_1_Q,               // ��ʱ�ϱ�1��������������/ֹͣ���� CMD_AFN_A_F67_GOP_AUTO_1
    CMD_GOP_AUTO_2_Q,               // ��ʱ�ϱ�2��������������/ֹͣ���� CMD_AFN_A_F68_GOP_AUTO_2

    /* ����1�����ݣ�AFN=0CH�� */
    CMD_CURNT_PQUI,                 // ��ǰ���༰����/�޹����ʡ����������������ѹ��������������������ڹ���
    CMD_TML_CLOCK,                  // �ն�����ʱ��  ���ݽṹ sMtUserClock   CMD_AFN_C_F2_TML_CLOCK
    CMD_DC_RLTM_DATA,               // ֱ��ģ����ʵʱ���� CMD_AFN_C_F73_DC_RLTM_DATA
    CMD_POWER_CUR,                  // ��ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ ��Ӧ3761���� CMD_AFN_C_F31_POWER_CUR
    CMD_CURT_HARM_VALUE,            // ��ǰA��B��C�����ѹ������2��N��г����Чֵ CMD_AFN_C_F57_CURT_HARM_VALUE
    CMD_CURT_HARM_RATE,             // ��ǰA��B��C�����ѹ������2��N��г�������� CMD_AFN_C_F58_CURT_HARM_RATE
    CMD_FRTH_HAVE_POWR_C,           // ��ǰ�����й�����ʾֵ���ܡ�����1��M��              CMD_AFN_C_F129_FRTH_HAVE_POWR_C
    CMD_FRTH_NONE_POWR_C,           // ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M�� CMD_AFN_C_F130_FRTH_NONE_POWR_C
    
    /* ��ʾ2������ (AFN = 0DH) */
    CMD_UBLN_OVER_D,                // �ղ�ƽ���Խ���ۼ�ʱ�� �ն���  ���ݽṹ sMtUblnOverD ��Ӧ���� CMD_AFN_D_F28_UBLN_OVER_D
    CMD_UBLN_OVER_M,                // �²�ƽ���Խ���ۼ�ʱ�� �¶���  ���ݽṹ sMtUblnOverM ��Ӧ���� CMD_AFN_D_F36_UBLN_OVER_M


    // ��ȡ�¶���ʪ��������������Ϊ��ʱ���������������ܻ��
    CMD_NELC_TEMP,                  // ��ȡ�¶� CMD_AFN_C_F17_TOTAL_POWER_HAVE
    CMD_NELC_HUMi,                  // ��ȡʪ�� CMD_AFN_C_F18_TOTAL_POWER_NONE
    
   
    CM_CMD_MAX,                     // ������� 
}eCmCmd;            // contrator to master cmd ����������վ������




/****************************************************
 *
 * ����ȷ����������ݽṹ
 *
{*///
typedef struct
{
    eCmCmd eCmd;  // ����
    UINT16 usPN;  // �������
    BOOL   bOk; 
}sCmOne;

typedef struct
{
    UINT8  ucNum;     // ��Ҫȷ�ϻ���ϵ����������
    sCmOne sOne[1];   // ÿ��ȷ�����������
}sCmOneByOne;
///*}


/****************************************************
 * ���ݽṹ: �ն˻�����֧�ֵĲ�������
 * ��Ӧ����: sMtSuptParaCfg
 *
{*///
typedef struct
{
    UINT8   ucNum;       // ֧�ֵ����õĲ����ĸ���
    eCmCmd  eCfgCmd[1];  // ֧�ֵ����� ��Ӧ���ò����µ�����

}sCmSuptParaCfg;

///*}

/****************************************************
 * ���ݽṹ: �ն�֧�ֵĿ�������
 * ��Ӧ����: sMtSuptCtrlCfg
 *
{*///
typedef struct
{
    UINT8   ucNum;       // ֧�ֵĿ�������ĸ���
    eCmCmd  eCfgCmd[1];  // ֧�ֵĿ��������������  CMD_CTRL_CHECK_TIME �� CMD_AUTO_REPORT_STOP

}sCmSuptCtrlCfg;
///*}


/****************************************************
 * ���ݽṹ: �ն�֧�ֵ�1����������
 * ��Ӧ����: sMtSuptAsk1
 *
{*///
typedef struct
{
    UINT8   ucNum;       // �ն�֧�ֵ�1�����������
    eCmCmd  eCfgCmd[1];  // ucNum ������    CMD_CURNT_PQUI �� 

}sCmSuptAsk1;
///*}


/****************************************************
 * ���ݽṹ: �ն�֧�ֵ�2����������
 * ��Ӧ����: sMtSuptAsk2
 * ��Ӧ����: CMD_SUPPORT_ASK2_CFG
 *
{*///
typedef struct
{
    UINT8   ucNum;       // �ն�֧�ֵ�1�����������
    eCmCmd  eCfgCmd[1];  // ucNum ������    CMD_CURNT_PQUI �� 

}sCmSuptAsk2;

///*}

/****************************************************
 * ���ݽṹ: 1�������������� 
 * ��Ӧ����: CMD_CFG_ASK_1  CMD_CFG_ASK_1_Q
 *
{*///
typedef struct
{    
    UINT8   ucSmall;            //  �û�С���            
    UINT8   ucFN;               //  ֧�ֵ��������  0 ~ 248
    eCmCmd  eCmd[MT_FN_MAX];    //  ֧�ֵ�һ������������ CMD_AFN_C_F2_TML_CLOCK �� CMD_AFN_C_F170_READ_METER
}sCmAsk1CfgOne;

typedef struct
{    
    UINT8          ucBig;                //  �û�С���            
    UINT8          ucM;                  // �������õ�����m��m�ܸ��û��������֧�ֵ��û�С��Ÿ�����
    sCmAsk1CfgOne  sOne[1];   // M����Ϣ
    
}sCmAsk1Cfg;
///*}

/****************************************************
 * ���ݽṹ: 2�������������� 
 * ��Ӧ����: CMD_CFG_ASK_2  CMD_CFG_ASK_2_Q
 *
{*///
typedef struct
{    
    UINT8   ucSmall;            //  �û�С���            
    UINT8   ucFN;               //  ֧�ֵ��������  0 ~ 248
    eCmCmd  eCmd[MT_FN_MAX];    //  ֧�ֵ�һ������������ CMD_AFN_D_F1_FRTH_POWR_P1P4_D �� CMD_AFN_D_F218_COLOR_YAWP_CURVE
}sCmAsk2CfgOne;

typedef struct
{    
    UINT8          ucBig;                //  �û�С���            
    UINT8          ucM;                  // �������õ�����m��m�ܸ��û��������֧�ֵ��û�С��Ÿ�����
    sCmAsk2CfgOne  sOne[1];   // M����Ϣ
    
}sCmAsk2Cfg;
///*}

/****************************************************
 * ���ݽṹ: ��ʱ�ϱ�1 2���������� ���á���ѯӦ��
 * ��Ӧ����: sMtCfgAuto_1 sMtCfgAuto_2
 * ��Ӧ����: sCmCfgAuto_1 : CMD_CFG_AUTO_1 �� CMD_CFG_AUTO_1_Q
 * ��Ӧ����: sCmCfgAuto_2 : CMD_CFG_AUTO_2 �� CMD_CFG_AUTO_2_Q
 *
{*///
typedef struct
{
    eCmCmd eCmd;            
    UINT16 usPn;
    
}sCmCmdPn;

typedef struct
{
    eMtRptUnit    eUnit;               // ��ʱ�ϱ����ڵ�λ(�֡�ʱ���ա���)
    UINT8         ucPeriod;            // ��ʱ�ϱ�����
    sMtYWMDhms    sTime;               // �ϱ���׼ʱ�䣺���ʱ������
    UINT8         ucR;                 // �������ݳ�ȡ����R (1��96)
    UINT8         ucN;                 // ���ݵ�Ԫ��ʶ����n
    sCmCmdPn      sCmdPn[1];   // N�����ݵ�Ԫ��ʶ  

}sCmCfgAuto_1, sCmCfgAuto_2;
///*}

/****************************************************
 * ���ݽṹ: ��ʱ�������
 * ��Ӧ����: sMtTotalPowerHave
 * ��Ӧ����: CMD_NELC_TEMP  CMD_NELC_HUMi
 * ��Ӧ����: CMD_AFN_C_F17_TOTAL_POWER_HAVE  CMD_AFN_C_F18_TOTAL_POWER_NONE
 *
{*///
typedef sMtTotalPowerHave sMcNelcTmper;  // �¶�
typedef sMtTotalPowerNone sMcNelcHumit;  // ʪ��
///*}

typedef union
{
    // ������ͨ��
    sCmOneByOne      scmOneByOne;       // ����ȷ�������             CMD_ONE_BY_ONE
    sMtTmlUpCfg      sTmlUpCfg;         // �ն�����ͨ�ſ�ͨ�Ų������� CMD_CFG_TML_UP
    sMtTmlPowerCfg   sTmlPowerCfg;      // �ն˵��ܱ�/��������װ�����ò��� CMD_CFG_TML_POWER
    sCmAsk1Cfg       sAsk1Cfg;          // ���ò��� CMD_CFG_ASK_1 �� ��ѯ���� CMD_CFG_ASK_1_Q
    sCmAsk2Cfg       sAsk2Cfg;          // ���ò��� CMD_CFG_ASK_2 �� ��ѯ���� CMD_CFG_ASK_2_Q
    sCmCfgAuto_1     sCfgAuto_1;        // ��ʱ�ϱ�1���������� ���á���ѯӦ�� CMD_CFG_AUTO_1   CMD_CFG_AUTO_1_Q
    sCmCfgAuto_2     sCfgAuto_2;        // ��ʱ�ϱ�2���������� ���á���ѯӦ�� CMD_CFG_AUTO_2   CMD_CFG_AUTO_2_Q
    sMtGopAuto_1     sGoAuto_1;         // ��ʱ�ϱ�1��������������/ֹͣ����   CMD_GO_AUTO_1    CMD_GOP_AUTO_1_Q
    sMtGopAuto_2     sGoAuto_2;         // ��ʱ�ϱ�1��������������/ֹͣ����   CMD_GO_AUTO_2    CMD_GOP_AUTO_2_Q

    // �������� ����������վ
    sMtTmlVersion    sTmlVersion;       // �ն˰汾��Ϣ    CMD_AFN_TML_VERSION
    sMtTmlInputOut   sTmlInputOut;      // �ն�֧�ֵ����롢�����ͨ�Ŷ˿����� CMD_AFN_TML_INPUT_OUT
    sMtTmlOtherCfg   sTmlOtherCfg;      // �ն�֧�ֵ���������     CMD_TML_OTHER_CFG
    sCmSuptParaCfg   sTmlSuptParaCfg;   // �ն�֧�ֵĲ�������     CMD_SUPPORT_PARA_CFG
    sCmSuptCtrlCfg   sTmlSuptCtrlCfg;   // �ն�֧�ֵĿ�������     CMD_SUPPORT_CTRL_CFG
    sCmSuptAsk1      sTmlSuptAsk1;      // �ն�֧�ֵ�1����������  CMD_SUPPORT_ASK1_CFG
    sCmSuptAsk2      sTmlSuptAsk2;      // �ն�֧�ֵ�2����������  CMD_SUPPORT_ASK2_CFG
    sMtSuptEvent     sTmlSuptEvent;     // �ն�֧�ֵ��¼���¼���� CMD_SUPPORT_EVNT_CFG
    sMtUserClock     sTmlClock;         // �ն�����ʱ��           CMD_TML_CLOCK 
    sMtCurPQUI       sCurPQUI;          // ��ǰ���༰����/�޹����ʡ����������������ѹ��������������������ڹ��� CMD_CURNT_PQUI 

    sMtUblnOverD     sUblnOverD;        // �ն��� �ղ�ƽ���Խ���ۼ�ʱ��  CMD_UBLN_OVER_D 
    sMtUblnOverM     sUblnOverM;        // �¶��� �²�ƽ���Խ���ۼ�ʱ��  CMD_UBLN_OVER_M 
    float            fDcRltmData;       // ֱ��ģ����ʵʱ���� (��3λ��Ч����)  CMD_DC_RLTM_DATA CMD_AFN_C_F73_DC_RLTM_DATA
    sMtCurPower      sCurPower;         // ��ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ CMD_POWER_CUR
    sMtCurtHarmValue sTmlCurtHarmValue; // ��ǰA��B��C�����ѹ������2��N��г����Чֵ CMD_CURT_HARM_VALUE CMD_AFN_C_F57_CURT_HARM_VALUE
    sMtCurtHarmRate  sTmlCurtHarmRate;  // ��ǰA��B��C�����ѹ������2��N��г�������� CMD_CURT_HARM_RATE  CMD_AFN_C_F58_CURT_HARM_RATE
    sMtFrthHavePower sTmlFrthHavePowrC; // ��ǰ�����й�����ʾֵ���ܡ�����1��M��           CMD_FRTH_HAVE_POWR_C CMD_AFN_C_F129_FRTH_HAVE_POWR_C
    sMtFrthNonePower sTmlFrthNonePowrC; // ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��CMD_FRTH_NONE_POWR_C CMD_AFN_C_F130_FRTH_NONE_POWR_C
    sMcNelcTmper     sNelcTmper;        // �¶� CMD_NELC_TEMP
    sMcNelcHumit     sNelcHumit;        // �¶� CMD_NELC_HUMi
    

    // �������� ��վ��������
    sMtUserClock     sCheckTime;        // ��ʱ����      CMD_CTRL_CHECK_TIME
    sMtTmlPowerCfg_Q sTmlPowerCfg_Q;    // �ն˵��ܱ�/��������װ�����ò��� ������� CMD_CFG_TML_POWER_Q
    sMtAsk1Cfg_Q     sAsk1Cfg_Q;        // 1�������������� �����ն�֧�ֵ�1�����������ڣ�(��ѯ�������) CMD_CFG_ASK_1_Q
    sMtAsk2Cfg_Q     sAsk2Cfg_Q;        // 1�������������� �����ն�֧�ֵ�2�����������ڣ�(��ѯ�������) CMD_CFG_ASK_2_Q
    sMtTd_c          sTd_c;             // ����������ʱ��  �������   
    sMtTd_h          sTd_h;             // Сʱ���� �������
    sMtTd_d          sTd_d;             // �ն���   �������
    sMtTd_m          sTd_m;             // �¶���   �������  
    

}uCmApp;  // �û���Ӧ�ò�����    ��  uMtApp һһ��Ӧ


typedef struct
{
    eCmCmd   eCmd;        // ��������
    UINT16   usPN;        // ��������һ������
    BOOL     bApp;        // Ӧ�ò�����ʱ��ʱ��
    uCmApp   uAppData;    // Ӧ�ò����� ����
}sCmSub;                  // ���������ݽṹ


/*
 * ����������װ�������ݽṹ, ����������
 * ˵��:
 * (1)ÿһ����Ч֡�У�ֻ����һ����cmd���͵ı���
 * (2)ÿһ����Ч֡�У����԰��������Ӧ����cmd���͵���cmd���͵�������
 *    ��������һ�������Զ�����Ҷ��ʱ���������˳�����
 * (3)ÿ��subcmd�����¿��������ݣ�������Ӧ�ò�������
 */
typedef struct
{
    sMtAddress   sAddress;       // ��ַ��Ϣ
    BOOL         bReSend;        // �Ƿ�Ϊ�ط�  TRUE �ط���֡���������Զ�����1 FALSE ������1
    BOOL         bActive;        // �Ƿ�Ϊ�����ϱ� (����¼���������˳���¼��1��2�����������ϱ�ʱΪ��)
    UINT8        ucCmdNum;       // �ð��к���������ĸ��� ������һ�������� 
    sCmSub       sCmdData[1];    // ÿ�������������
    
}sCmPacket;

typedef struct
{
    eMtRole      eRole;                    // ���    
    UINT8        ucPermitDelayMinutes;     // ����ʱ��

}sCmInit; // 3761Э����ʼ�����ݽṹ

eMtAFN ecmGetCmdAfn(eCmCmd eCmd);

// �ϲ���ñ�ģ��ǰ,��ȷʵ���г�ʼ��
eCmErr ecm_3761_init(sCmInit * psCmInit); 
// �ϲ�ӿڷ�װ
INT32 ncm_3761_pack(sCmPacket* psCmPacket, UINT8 * pBuf);
INT32 ncm_3761_unpack(UINT8 * pBuf, UINT16 usBufLen, sCmPacket* psCmPacket);
INT32 ncm_3761_checkAndGetPacket(UINT8  *pinBuf, UINT16 usLen, UINT16 *pusFirstOff, UINT16 *pusFirstLen);


// ��װ����
eCmErr ecm_3761_pack(sCmPacket* psCmPacket, UINT8 * pBuf, UINT16 *pusBufLen);

// ���װ����
eCmErr ecm_3761_unpack(UINT8 * pBuf, UINT16 usBufLen, sCmPacket* psCmPacket);

// �ж��Ƿ�Ϊһ����Ч֡
BOOL bcm_valid_3761_packet(UINT8  *pinBuf, UINT16 usLen);


// �ҵ���һ����Ч֡��λ��
eCmErr ecm_find_frist_valid_pack(UINT8  *pinBuf, UINT16 usLen, UINT16 *pusFirstOff, UINT16 *pusFirstLen);

// ����¼�������
void vCmSetEC(UINT8 ucEC1, UINT8 ucEC2);

// ��������
BOOL bCmSetPw(char *pw); 

// �ڲ��ӿ�
eMtCmd emtTransAppData_cm_2_mt(eMtCmd emtCmd, uCmApp *pcmAppData, uMtApp *pmtAppData);
eMtCmd emtTransAppData_mt_2_cm(eMtCmd emtCmd, uMtApp *pmtAppData, uCmApp *pcmAppData);

eMtCmd eGetMtCmd(eCmCmd cmCMD);   
eCmCmd eGetCmCmd(eMtCmd mtCMD);
eMtPRM ecmGetPrm(eCmCmd cmCMD);  // ��ø������������

typedef struct
{
    eCmCmd ecmCMD;
    eMtCmd emtCMD;
    eMtPRM ePrm;   // ��������װ������ʱ��������
 
}sCmdMap; // ����ӳ��

#pragma pack(pop)  // һ�ֽڶ���
#endif /* _CON_3761_ADP_H_ */
