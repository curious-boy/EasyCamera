/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
#ifndef _CMS_SESSION_H_
#define _CMS_SESSION_H_

#include "Task.h"
#include "hi_type.h"
#include "hi_net_dev_sdk.h"
#include "hi_net_dev_errors.h"
#include "libClientCommondef.h"
#include "QTSS.h"


#define EASY_SNAP_BUFFER_SIZE 1024*1024

class EasyMediaSource : public Task
{
public:
	EasyMediaSource();
	~EasyMediaSource(void);

	bool CameraLogin();

	bool GetSnapData(unsigned char* pBuf, UInt32 uBufLen, int* uSnapLen);

	QTSS_Error NetDevStartStream();
	void NetDevStopStream();
	typedef void (onCloseFunc)(void* clientData);
	static void handleClosure(void* clientData);
	void handleClosure();

	void stopGettingFrames();
	void doStopGettingFrames();

	OSMutex*	GetMutex()      { return &fMutex; }
	//FILE* _f_264;
	
private:
	//������������
	HI_U32 m_u32Handle;
	onCloseFunc* fOnCloseFunc;
	void* fOnCloseClientData;
	//�ͻ�����Ϣ����������
	OSMutex fMutex;

	SInt64 Run();

public:
	bool fCameraLogin;
	bool m_bStreamFlag;
	bool m_bForceIFrame;
};

#endif //_CMS_SESSION_H_
