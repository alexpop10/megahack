#ifndef _SIMPLE_API_H_
#define _SIMPLE_API_H_

#include "typedefs.h"

#define STX 0xF1
#define CTX 0xF2

#define MAX_API_BUFFER_SIZE 96

#define ISA100 0
#define WHART 1

#if (STANDARD == ISA100)
	
#define ANALOG_COUNT 4
#define DIGITAL_COUNT 4
	
#elif (STANDARD == WHART)
	
#define ANALOG_COUNT 6
#define DIGITAL_COUNT 2
	
#endif /* (STANDARD == ISA100) */

enum ACK_MESSAGES 
{
	DATA_OK = ((uint8_t) 0x01),
	MESSAGE_SENT_VIA_RF,
	API_CHANGE_ACCEPTED,
	ACK_FIRMWARE,
	
	NUM_ACK_MESSAGES
};

enum NACK_MESSAGES 
{
	NACK_CRC_FAIL = ((uint8_t) 0x01),
	NACK_DATA_OVERRUN,
	NACK_PACKET_INCOMPLETE,
	NACK_PARITY_ERROR,
	NACK_API_NOT_INITIALIZED,
	NACK_API_COMMAND_ERROR,
	NACK_API_BUSY,
	NACK_API_ERROR,
	NACK_STACK_ERROR, // Recommend getting Stack status from Stack Specific commands.
	NACK_UNSUPPORTED_FEATURE, // Feature not yet supported.
	NACK_FIRMWARE,
	
	NUM_NACK_MESSAGES
};

enum PASSTHROUGH_MESSAGES
{
	WRITE_DATA_REQ = ((uint8_t) 0x01),
	READ_DATA_REQ,
	READ_DATA_RESP,
	
	PASSTHROUGH_MESSAGES_NO
};

enum MSG_CLASS 
{
	DATA_PASSTHROUGH = ((uint8_t) 0x01), // Applies to stack specific objects (i.e. ISA100.11a UploadDownloadObject)
	API_COMMANDS = ((uint8_t) 0x04), // Messages to control/query API related data (i.e. FW/HW Version, platform)
	API_ACK,
	API_NACK,
	
	NUM_ITEMS_MSG_CLASS
};

enum MESSAGE_DIRECTION
{
	REQUEST = ((uint8_t) 0x00),
	RESPONSE
};

enum DATA_PASS_THROUGH_TYPES
{
	WRITE_DATA_REQUEST = ((uint8_t) 0x01),
	READ_DATA_REQUEST,
	READ_DATA_RESPONSE
};

enum API_COMMAND_TYPES
{
	API_HW_PLATFORM = ((uint8_t) 0x01),
	API_FW_PLATFORM,
	API_MAX_BUFFER,
	API_MAX_SPI_SPEED,
	API_UPDATE_SPI_SPEED,
	API_MAX_UART_SPEED,
	API_UPDATE_UART_SPEED,
	API_UPDATE_POLLING_FREQ,
	API_POLLING,
	API_FW_ACTIVATION_REQ,
	
	NUM_ITEMS_API_COMMAND_TYPES
};

typedef struct message
{
	struct message *m_pstPrev;	
	struct 
	{
		uint8_t ucReserved : 3;        
		uint8_t m_ucIsRsp : 1;
		uint8_t m_ucMessageClass : 4;
	} m_stMessageHeader;
	uint8_t m_ucMessageType;
	uint8_t m_ucMessageID;
	uint8_t m_ucMessageSize;
	uint8_t m_aucMessageData[MAX_API_BUFFER_SIZE];
	struct message *m_pstNext;
}MESSAGE;

extern uint8_t g_ucRadioReady;

void API_ParseMessage(uint8_t *p_ucMessage);
void API_HandleMessage(void);
uint16_t API_ComputeCRC(uint8_t *pucData, uint8_t ucSize, uint8_t unStartIdx);
void ComposeAck(void);
uint16_t API_ComputeCRC(uint8_t *pucData, uint8_t ucSize, uint8_t unStartIdx);
void SendMessage(uint8_t *pucData, uint8_t ucSize);
void API_OnRcvDataPassTrough(void);
void API_ComposeReadDataResponse(void);
void API_Task(void);

#endif /* _SIMPLE_API_H_ */