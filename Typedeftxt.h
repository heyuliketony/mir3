#ifndef _TYPEDEF_TEXT_H
#define _TYPEDEF_TEXT_H

typedef struct tag_CMTxtBtn
{
	COLORREF nColor;			
	COLORREF cColor;			
	CHAR	Txt[70];			// Main으로 보이는 Txt
	CHAR	sTxt[70];			// Sub로 보이는 Txt
	RECT	xRect;				// Top 은 항상 0으로 해야함
	INT		nLinePos;			// Top 을 결정한다.  Top은 휠과 윈도우 움직임에 의하서 항상 가변적임
	CHAR	Param[70];
	BOOL	bIsClicked;
	INT		nImgID;				//item暠튬乞多
	INT		nSubMenu;
} CMTxtBtn;

typedef struct tag_CMText
{
	COLORREF	fColor;				// Text Color
	BOOL		bDrawCenter;		// DrawCenter
	INT			nPosx;				// Draw Position x
	INT			nLine;				// Draw Line indicater	:Zerobase
	CHAR*		pText;				// Text
} CMText;

#endif _TYPEDEF_TEXT_H