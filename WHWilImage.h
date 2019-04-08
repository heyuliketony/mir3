



#ifndef _WILIMAGEHANDLER_
#define	_WILIMAGEHANDLER_



/******************************************************************************************************************

	CWilImageData Class Declaration

   

*******************************************************************************************************************/


#pragma pack(1)
typedef struct tagNEWWILFILEHEADER
{
	SHORT	shComp;
	CHAR	szTitle[20];
	SHORT	shVer;
	INT		nImageCount;
}NEWWILFILEHEADER, *LPNEWWILFILEHEADER;

typedef struct tagNEWWILFILEIMAGEINFO
{
	SHORT	shWidth;  
	SHORT	shHeight; 
	SHORT	shPX;
	SHORT	shPY;
	CHAR	bShadow;					
	SHORT	shShadowPX;
	SHORT	shShadowPY;
	DWORD	dwImageLength;  
}NEWWILIMAGEINFO, *LPNEWWILIMAGEINFO;
typedef struct tagNEWWIXFILEIMAGEINFO
{
	CHAR	szTitle[20];
	INT		nIndexCount;
	INT*	pnPosition;
}NEWWIXIMAGEINFO, *LPNEWWIXIMAGEINFO;
#pragma pack()


class CWHWilImageData
{

protected:
	BOOL				m_bIsMemMapped;				
	BOOL				m_bIsCompressed;			
	LPBYTE			m_pbStartData;				
	INT					m_nCurrImageIdx;			


public:
	NEWWIXIMAGEINFO		m_stNewWixImgaeInfo;		
	LPNEWWILIMAGEINFO	m_lpstNewCurrWilImageInfo;	

	BYTE*				m_pbCurrImage;				
	TCHAR			m_szWilFileName[MAX_PATH];

	CWHWilImageData();
	~CWHWilImageData();

	BOOL NewLoad(CHAR* szWilFile, BOOL bComp = TRUE);
	BOOL NewSetIndex(DWORD dwIndex);				

	VOID Init();
	VOID Destroy();		
};


#endif 
