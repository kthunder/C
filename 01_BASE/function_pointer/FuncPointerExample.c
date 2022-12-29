#include <stdio.h>
#include <stdint.h>

/*********  工作状态处理  *********/
typedef struct
{
	uint8_t mStatus;
	uint8_t (*Funtion)(void); // 函数指针的形式
} M26_WorkStatus_TypeDef;	  // M26的工作状态集合调用函数

/**********************************************
** >M26工作状态集合函数
***********************************************/
M26_WorkStatus_TypeDef M26_WorkStatus_Tab[] =
	{
		// {GPRS_NETWORK_CLOSE,  M26_PWRKEY_Off  },    //模块关机
		// {GPRS_NETWORK_OPEN,  M26_PWRKEY_On  },      //模块开机
		// {GPRS_NETWORK_Start,   M26_Work_Init  },    //管脚初始化
		// {GPRS_NETWORK_CONF,  M26_NET_Config  },     //AT指令配置
		// {GPRS_NETWORK_LINK_CTC,  M26_LINK_CTC  },   //连接调度中心
		// {GPRS_NETWORK_WAIT_CTC, M26_WAIT_CTC  },    //等待调度中心回复
		// {GPRS_NETWORK_LINK_FEM, M26_LINK_FEM  },    //连接前置机
		// {GPRS_NETWORK_WAIT_FEM, M26_WAIT_FEM  },    //等待前置机回复
		// {GPRS_NETWORK_COMM,  M26_COMM   },          //正常工作
		// {GPRS_NETWORK_WAIT_Sig,  M26_WAIT_Sig  },   //等待信号回复
		// {GPRS_NETWORK_GetSignal,  M26_GetSignal  }, //获取信号值
		// {GPRS_NETWORK_RESTART,  M26_RESET   },      //模块重启
};
/**********************************************
** >M26模块工作状态机，依次调用里面的12个函数
***********************************************/
uint8_t M26_WorkStatus_Call(uint8_t Start)
{
	uint8_t i = 0;
	for (i = 0; i < 12; i++)
	{
		if (Start == M26_WorkStatus_Tab[i].mStatus)
		{
			return M26_WorkStatus_Tab[i].Funtion();
		}
	}
	return 0;
}