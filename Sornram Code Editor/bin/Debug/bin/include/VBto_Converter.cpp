//				file	VBto_Converter.cpp
// This is a part of the VBto Converter (www.vbto.net). Copyright (C) 2005-2014 StressSoft Company Ltd. All rights reserved.
//

#include "stdafx.h"

#pragma warning(disable : 4996)

#include "VBto_Converter.h"
#include "resource.h"

int QBColor(int iColor) {
	if (iColor<0 || iColor>15) return 0;
	static const int Col[16]={0, 8388608, 32768, 8421376, 128, 8388736, 32896, 12632256, 8421504, 16711680, 65280, 16776960, 255, 16711935, 65535, 16777215};
	return Col[iColor];
}

CString GetWindowText(const CWnd *wnd) {
	CString cs;
	wnd->GetWindowText(cs);
	return cs;
}

int GetLeft(const CWnd *wnd) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	CWnd *wndParent = wnd->GetParent();
	if (wndParent && wndParent->IsChild(wnd)) wndParent->ScreenToClient(&rect);
	return rect.left;
}

int GetTop(const CWnd *wnd) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	CWnd *wndParent = wnd->GetParent();
	if (wndParent && wndParent->IsChild(wnd)) wndParent->ScreenToClient(&rect);
	return rect.top;
}

int GetWidth(const CWnd *wnd) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	return rect.right-rect.left;
}

int GetHeight(const CWnd *wnd) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	return rect.bottom-rect.top;
}

void SetLeft(CWnd *wnd, int value) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	CWnd *wndParent = wnd->GetParent();
	if (wndParent && wndParent->IsChild(wnd)) wndParent->ScreenToClient(&rect);
	rect.right = value + (rect.right-rect.left);
	rect.left  = value;
	wnd->MoveWindow(&rect);
}

void SetTop(CWnd *wnd, int value) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	CWnd *wndParent = wnd->GetParent();
	if (wndParent && wndParent->IsChild(wnd)) wndParent->ScreenToClient(&rect);
	rect.bottom  = value + (rect.bottom-rect.top);
	rect.top = value;
	wnd->MoveWindow(&rect);
}

void SetWidth(CWnd *wnd, int value) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	rect.right = rect.left + value;
	wnd->MoveWindow(&rect);
}

void SetHeight(CWnd *wnd, int value) {
	RECT rect;
	wnd->GetWindowRect(&rect);
	rect.bottom = rect.top + value;
	wnd->MoveWindow(&rect);
}

int InStrRev(const CString &StringCheck, const CString &StringMatch, int iStart) { //? [Compare As VbCompareMethod = vbBinaryCompare]
	int nbStringCheck = StringCheck.GetLength();
	int nbStringMatch = StringMatch.GetLength();
	if (iStart>=0) nbStringCheck = iStart;
	if (nbStringCheck<nbStringMatch) return 0;
	const char *pStringCheck = (const char *) StringCheck;
	const char *pStringMatch = (const char *) StringMatch;
	const char *p = pStringCheck + nbStringCheck - nbStringMatch;
	for (; p>=pStringCheck; p--)
		if (!memcmp(p,pStringMatch,nbStringMatch)) return 1+(p-pStringCheck);
	return 0;
}

CString StrReverse(const CString &csI) {
	CString cs = csI;
	cs.MakeReverse();
	return cs;
}

void RSet(CString &lS, const CString &rS) {
	int nblS = lS.GetLength();
	int nbrS = rS.GetLength();
	lS = nblS<=nbrS ? rS.Left(nblS) : CString(' ',nblS-nbrS) + rS;
}

void LSet(CString &lS, const CString &rS) {
	int nblS = lS.GetLength();
	int nbrS = rS.GetLength();
	lS = nblS<=nbrS ? rS.Left(nblS) : rS + CString(' ',nblS-nbrS);
}

CString UCase(const CString &csI) {
	CString cs = csI;
	cs.MakeUpper();
	return cs;
}

CString LCase(const CString &csI) {
	CString cs = csI;
	cs.MakeLower();
	return cs;
}

CString Trim(const CString &csI) {
	CString cs = csI;
	cs.TrimRight();
	cs.TrimLeft();
	return cs;
}

CString LTrim(const CString &csI) {
	CString cs = csI;
	cs.TrimLeft();
	return cs;
}

CString RTrim(const CString &csI) {
	CString cs = csI;
	cs.TrimRight();
	return cs;
}

CString Format(const char *fmt, ...) {
	va_list params;
	va_start(params, fmt);
	CString cs;
	cs.FormatV(fmt,params);
	va_end(params);
	return cs;
}


CString GetFmt(const char * vbfmt, const char * cfmt0, bool cIsDot, const char * cfmt1, const char * cChar) {
	CString fmt = "%";
	if (!vbfmt) {
		if (cfmt0)	fmt += cfmt0;
		if (cIsDot)	fmt += ".";
		if (cfmt1)	fmt += cfmt1;
		fmt += cChar;
		return fmt;
	}

	int nPos=0;
	bool flIs0=false, flIsDot=false;
	CString vbfmt0, vbfmt1, sPos;
	for(const char *p=vbfmt; *p; p++) {
		switch(*p) {
			case '-':	case '+':	case '$':	case '(':	case ')':
			case ' ':	case '\t':	case '\r':	case '\n':
				if (flIsDot)	vbfmt1 += *p;
				else			vbfmt0 += *p;
				break;
			case '0':
				if (!nPos) flIs0 = true;
			case '#':
				nPos++;
				break;
			case '.':
				flIsDot = true;
				if (flIs0) fmt += "0";
				if (nPos) {
					sPos.Format("%d",nPos);
					fmt += sPos;
				}
				nPos = 0;
				flIs0 = false;
				break;
		}
	}

	if (nPos) {
		if (flIsDot) fmt += ".";
		if (flIs0)	 fmt += "0";
		sPos.Format("%d",nPos);
		fmt += sPos + CString(cChar);
	} else {
		fmt += CString(cChar);
		if (flIsDot) fmt += ".";
	}

	return vbfmt0 + fmt + vbfmt1;
}
CString FormatVB(short val, const char *vbfmt) {
	CString fmt = GetFmt(vbfmt,NULL,false,NULL,"hd");
	CString ret;
	ret.Format(fmt, val);
	return ret;
}
CString FormatVB(int val, const char *vbfmt) {
	CString fmt = GetFmt(vbfmt,NULL,false,NULL,"d");
	CString ret;
	ret.Format(fmt, val);
	return ret;
}
CString FormatVB(long val, const char *vbfmt) {
	CString fmt = GetFmt(vbfmt,NULL,false,NULL,"ld");
	CString ret;
	ret.Format(fmt, val);
	return ret;
}
CString FormatVB(float val, const char *vbfmt) {
	CString fmt = GetFmt(vbfmt,NULL,true,"12","g");
	CString ret;
	ret.Format(fmt, val);
	return ret;
}
CString FormatVB(double val, const char *vbfmt) {
	CString fmt = GetFmt(vbfmt,NULL,true,"12","lg");
	CString ret;
	ret.Format(fmt, val);
	return ret;
}
CString FormatVB(const char *str, const char *vbfmt) {
	return str;
}
CString FormatVB(const CString &cs, const char *vbfmt) {
	return cs;
}


CString Str(short h) {
	CString s = Format("%hd", h);
	return h>=0 ? (' '+s) : s;
}
CString Str(int i) {
	CString s = Format("%d", i);
	return i>=0 ? (' '+s) : s;
}
CString Str(unsigned int u) {
	CString s = Format("%u", u);
	return u>=0 ? (' '+s) : s;
}
CString Str(float f) {
	CString s = Format("%g", f);
	return f>=0 ? (' '+s) : s;
}
CString Str(double d) {
	CString s = Format("%.12lg", d);
	return d>=0 ? (' '+s) : s;
}
CString Str(bool b) {
	return b ? " True" : " False";
}
CString Str(CString s) {
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(syss,".");
	return ' '+s;
}
CString Str(const CComVariant &v) {
	switch(V_VT(&v)) {
		case VT_R8:		return Str(v.dblVal);
		case VT_R4:		return Str(v.fltVal);
		case VT_I4:		return Str(v.intVal);
		case VT_UI4:	return Str(v.uintVal);
		case VT_I2:		return Str(v.iVal);
		case VT_BOOL:	return v.boolVal ? "True" : "False";
		case VT_BSTR: {
			CComVariant ret = v;
			CComBSTR cc = ret.bstrVal;
			return Str((CString)cc.m_str); 
		}
		default: {
			CComVariant ret = v;
			ret.ChangeType(VT_BSTR);
			CComBSTR cc = ret.bstrVal;
			return Str((CString)cc.m_str);
		}
	}
}

CString LocaleSDesimal() {
	const int nBuffLen = ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDECIMAL, NULL, 0);
	_ASSERT(nBuffLen>0);
	CString LocaleSDesimal;
	const int nResult = ::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SDECIMAL, LocaleSDesimal.GetBuffer(nBuffLen), nBuffLen);
	_ASSERT(nResult!=0);
	LocaleSDesimal.ReleaseBuffer();
	return LocaleSDesimal;
}


CString ToString(short h) {
	CString ret;
	ret.Format("%hd", h);
	return ret;
}
CString ToString(int i) {
	CString ret;
	ret.Format("%d", i);
	return ret;
}
CString ToString(long l) {
	CString ret;
	ret.Format("%ld", l);
	return ret;
}
CString ToString(float f) {
	CString ret;
	ret.Format("%.12g", f);
	CString syss = LocaleSDesimal();
	if (syss!=".") ret.Replace(".",syss);
	return ret;
}
CString ToString(double d) {
	CString ret;
	ret.Format("%.12lg", d);
	CString syss = LocaleSDesimal();
	if (syss!=".") ret.Replace(".",syss);
	return ret;
}

double StrToDouble(CString s) {
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(syss,".");
	return atof(s);
}


CString CStr(double d) {
	CString s;
	s.Format("%.12g", d);
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(".", syss);
	return s;
}
CString CStr(CString s) {
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(".", syss);
	return s;
}

CString Hex(short val) {
	char Buf[40];
	sprintf(Buf,"%hX",val);
	return Buf;
}
CString Hex(int val) {
	char Buf[40];
	sprintf(Buf,"%X",val);
	return Buf;
}


CString Oct(short val) {
	char Buf[40];
	sprintf(Buf,"%ho",val);
	return Buf;
}
CString Oct(int val) {
	char Buf[40];
	sprintf(Buf,"%o",val);
	return Buf;
}

int Asc(const CString &cs) {
	unsigned char ch = cs[0];
	return ch;
}

double Val(CComVariant v) {
	v.ChangeType(VT_R8);
	return v.dblVal;
}
double Val(const char * pBuf) {
	double ret = 0;
	sscanf(pBuf,"%lg",&ret);
	return ret;
}

bool CBool(const char * ps) {
	if (!ps || !*ps) return false;
	register char ch = ps[0];
	if (ch=='T' || ch=='t') return true;
	if (ch=='F' || ch=='f') return false;
	double d = Val(ps);
	return d!=0;
}
bool CBool(CComVariant v) {
	v.ChangeType(VT_BOOL);
	return v.boolVal != VARIANT_FALSE;
}

double CDbl(CString s) {
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(syss,".");
	double ret = 0;
	sscanf((const char *)s,"%lg",&ret);
	return ret;
}

float CSng(CString s) {
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(syss,".");
	float ret = 0;
	sscanf((const char *)s,"%f",&ret);
	return ret;
}

short CInt(CString s) {
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(syss,".");
	double d = 0;
	sscanf((const char *)s,"%lg",&d);
	return (short)(d>=0 ? (d+0.5) : (d-0.5));
}

int CLng(CString s) {
	CString syss = LocaleSDesimal();
	if (syss!=".") s.Replace(syss,".");
	double d = 0;
	sscanf((const char *)s,"%lg",&d);
	return (int)(d>=0 ? (d+0.5) : (d-0.5));
}

int Sign(double d) {
	if (d>0) return 1;
	return !d ? 0 : -1;
}

int Round(double d) {
	return (int)(d>=0 ? (d+0.5) : (d-0.5));
}
int Round(const char *ps) {
	double d = 0;
	sscanf(ps,"%lg",&d);
	return Round(d);
}

double Round(double d, int NumDigitsAfterDecimal) {
	char buf[100];
	sprintf(buf,"%.*lf", NumDigitsAfterDecimal, d);
	sscanf (buf,"%lf", &d);
	return d;
}

bool IsNumeric(const CString &s) {
	const char *pBuf = (const char *) s;
	double d;
	return 1==sscanf(pBuf,"%lg",&d);
}

CString GetText(const CListBox &lb) {
	CString cs;
	int nIndex = lb.GetCurSel();
	if (nIndex>=0) lb.GetText(nIndex, cs);
	return cs;
}

CString GetText(const CComboBox &cb, int ind) {
	CString cs;
	cb.GetLBText(ind, cs);
	return cs;
}

CString GetText(const CListBox &lb, int ind) {
	CString cs;
	lb.GetText(ind, cs);
	return cs;
}

void Kill(const CString &PathName) {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFindFile = FindFirstFile(PathName, &FindFileData);
	if (hFindFile==INVALID_HANDLE_VALUE) return; /*Invalid File Handle*/
	do {
		DeleteFile(FindFileData.cFileName);
	} while (FindNextFile(hFindFile, &FindFileData));
	FindClose(hFindFile);
}

class VBtoConverter_Dir {
public:
	VBtoConverter_Dir(const CString &PathName) {
		hFindFile = ::FindFirstFile(PathName, &FindFileData);
	}
	CString CurFile() {
		return hFindFile==INVALID_HANDLE_VALUE ? "" : FindFileData.cFileName;
	}
	CString FindNextFile() {
		return ::FindNextFile(hFindFile,&FindFileData) ? FindFileData.cFileName : "";
	}
	WIN32_FIND_DATA FindFileData;
	HANDLE hFindFile;
};
VBtoConverter_Dir *pVBtoConverter_Dir = NULL;
CString Dir(const CString &PathName) {
	if (pVBtoConverter_Dir) delete pVBtoConverter_Dir;
	pVBtoConverter_Dir = new VBtoConverter_Dir(PathName);
	return pVBtoConverter_Dir->CurFile();
}
CString Dir() {
	return pVBtoConverter_Dir ? pVBtoConverter_Dir->FindNextFile() : "";
}

CString GetCurrentDirectory() {
	char Buffer[300]="";
	GetCurrentDirectory(sizeof(Buffer), Buffer);
	return Buffer;
}

void DoEvents(HWND hWndEvents) {
	MSG msg;
	while (PeekMessage(&msg, hWndEvents, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage (&msg);
	}
}

void PrintLine(HANDLE hf, const CString &cs) {
	DWORD dwSize;
	::WriteFile(hf, cs, cs.GetLength(), &dwSize, NULL);
	::WriteFile(hf, "\r\n", 2, &dwSize, NULL);
}
void Print(HANDLE hf, const CString &cs) {
	DWORD dwSize;
	::WriteFile(hf, cs, cs.GetLength(), &dwSize, NULL);
}

void LineInput(HANDLE hf, CString &cs) {
	cs = "";
	char ch; DWORD dwSize;
	while(::ReadFile(hf,&ch,1,&dwSize,NULL) && dwSize && ch!='\n')
		cs+=ch;
}

bool IsEOF(HANDLE hf) {
	char ch; DWORD dwSize;
	bool ret = ::ReadFile(hf,&ch,1,&dwSize,NULL) && dwSize;
	if (ret) SetFilePointer(hf, -1, NULL, FILE_CURRENT);
	return !ret;
}

void Randomize(int v) {
	srand(v ? v : (unsigned)time(NULL));
}

double Rnd() {
	return rand()/double(RAND_MAX);
}
double Rnd(float v) {
	return rand()/double(RAND_MAX);
}

 int CurrentX, CurrentY;


//===================================================================
 PictureProperties LastPictureProps;

void DrawLine(CWnd *wnd, int x1,int y1, int x2,int y2, int rgb) {
	CDC *cdc = wnd->GetDC();
	CPen *oldPen = cdc->SelectObject(new CPen(LastPictureProps.DrawStyle, LastPictureProps.DrawWidth, rgb));
	cdc->MoveTo(x1,y1);
	cdc->LineTo(CurrentX=x2, CurrentY=y2);
	delete (CPen *)cdc->SelectObject(oldPen);
	wnd->ReleaseDC(cdc);
}
void DrawLineVB6xy(CWnd &mwnd, double x1,double y1, double x2,double y2, int rgb) {
	DrawLine(&mwnd, int(x1/kTP), int(y1/kTP), int(x2/kTP), int(y2/kTP), rgb);
}

void DrawLineTo(CWnd *wnd, int x,int y, int rgb) {
	DrawLine(wnd, CurrentX, CurrentY, x, y, rgb);
}
void DrawLineToVB6xy(CWnd &mwnd, double x,double y, int rgb) {
	DrawLineTo(&mwnd, int(x/kTP), int(y/kTP), rgb);
}

void DrawLineStep(CWnd *wnd, int x1, int y1, int x2, int y2, int rgb) {
	DrawLine(wnd, x1, y1, x1 + x2, y1 + y2, rgb);
}
void DrawLineStepVB6xy(CWnd *wnd, double x1, double y1, double x2, double y2, int rgb) {
	DrawLineStep(wnd, int(x1/kTP), int(y1/kTP), int(x2/kTP), int(y2/kTP), rgb);
}

void DrawLineToStep(CWnd *wnd, int x, int y, int rgb) {
	DrawLineTo(wnd, CurrentX+x, CurrentY+y, rgb);
}
void DrawLineToStepVB6xy(CWnd *wnd, double x, double y, int rgb) {
	DrawLineToStep(wnd, int(x/kTP), int(y/kTP), rgb);
}

void DrawRectangle(CWnd *wnd, int x1,int y1, int x2,int y2, int rgb, CString bf) {
	CDC *cdc = wnd->GetDC();
	if (bf=="BF") {
		cdc->FillSolidRect(x1,y1, x2-x1,y2-y1, rgb);
	} else {
		CPen pen;
		pen.CreatePen(LastPictureProps.DrawStyle, LastPictureProps.DrawWidth, rgb);
		CPen *pOldPen = cdc->SelectObject(&pen);
		cdc->MoveTo(x2,y2);
		cdc->LineTo(x1,y2);
		cdc->LineTo(x1,y1);
		cdc->LineTo(x2,y1);
		cdc->LineTo(x2,y2);
		cdc->SelectObject(pOldPen);
	}
	CurrentX=x2;
	CurrentY=y2;
	wnd->ReleaseDC(cdc);
}

void DrawRectangleVB6xy(CWnd &mwnd, double x1,double y1, double x2,double y2, int rgb, CString bf) {
	DrawRectangle(&mwnd, int(x1/kTP), int(y1/kTP), int(x2/kTP), int(y2/kTP), rgb, bf);
}

void DrawRectangleTo(CWnd *wnd, int x, int y, int rgb, CString bf) {
	DrawRectangle(wnd, CurrentX, CurrentY, x, y, rgb, bf);
}
void DrawRectangleToVB6xy(CWnd *wnd, double x, double y, int rgb, CString bf) {
	DrawRectangleTo(wnd, int(x/kTP), int(y/kTP), rgb, bf);
}

void DrawRectangleStep(CWnd *wnd, int x1, int y1, int x2, int y2, int rgb, CString bf) {
	DrawRectangle(wnd, x1, y1, x1+x2, y1+y2, rgb, bf);
}
void DrawRectangleStepVB6xy(CWnd *wnd, double x1, double y1, double x2, double y2, int rgb, CString bf) {
	DrawRectangleStep(wnd, int(x1/kTP), int(y1/kTP), int(x2/kTP), int(y2/kTP), rgb, bf);
}

void DrawRectangleToStep(CWnd *wnd, int x, int y, int rgb, CString bf) {
	DrawRectangle(wnd, CurrentX, CurrentY, CurrentX+x, CurrentY+y, rgb, bf);
}
void DrawRectangleToStepVB6xy(CWnd *wnd, double x, double y, int rgb, CString bf) {
	DrawRectangleToStep(wnd, int(x/kTP), int(y/kTP), rgb, bf);
}

void DrawCircle(CWnd *wnd, int xc,int yc, int rc, int rgb) {
	CDC *cdc = wnd->GetDC();
	if (LastPictureProps.FillStyle==1) {
		CPen *oldPen = cdc->SelectObject(new CPen(LastPictureProps.DrawStyle, LastPictureProps.DrawWidth, COLORREF(rgb)));
		cdc->MoveTo(xc+rc,yc);
		cdc->AngleArc(xc,yc, rc, 0, 360);
		delete (CPen *)cdc->SelectObject(oldPen);
	} else {
		CBrush brush(LastPictureProps.FillStyle, rgb);
		CBrush *pOldBrush = cdc->SelectObject(&brush);
		cdc->Ellipse(xc-rc,yc-rc,xc+rc,yc+rc);
		cdc->SelectObject(pOldBrush);
	}
	wnd->ReleaseDC(cdc);
}
void DrawArc(CWnd *wnd, int xc,int yc, int rc, double fiStart, double fiEnd, int rgb) {
	CDC *cdc = wnd->GetDC();
	CPen *oldPen = cdc->SelectObject(new CPen(LastPictureProps.DrawStyle, LastPictureProps.DrawWidth, COLORREF(rgb)));
	int xStart = int(xc + rc*cos(fiStart));
	int yStart = int(yc - rc*sin(fiStart));
	cdc->MoveTo(xStart,yStart);
	float gfiStart = float(fiStart / M_PI * 180);
	float gfiEnd   = float(fiEnd   / M_PI * 180);
	cdc->AngleArc(xc,yc, rc, float(gfiStart), gfiEnd-gfiStart);
	delete (CPen *)cdc->SelectObject(oldPen);
	wnd->ReleaseDC(cdc);
}

void DrawPoint(CWnd *wnd, int x,int y, int rgb) {
	CDC *cdc = wnd->GetDC();
	cdc->SetPixelV(x,y,rgb);
	wnd->ReleaseDC(cdc);
}

void DrawCircleVB6xy(CWnd &mwnd, double xc,double yc, double rc, int rgb) {
	DrawCircle(&mwnd, int(xc/kTP), int(yc/kTP), int(rc/kTP), rgb);
}
void DrawArcVB6xy(CWnd &mwnd, double xc,double yc, double rc, double fiStart, double fiEnd, int rgb) {
	DrawArc(&mwnd, int(xc/kTP), int(yc/kTP), int(rc/kTP), fiStart, fiEnd, rgb);
}

void DrawPointVB6xy(CWnd &mwnd, double x,double y, int rgb) {
	DrawPoint(&mwnd, int(x/kTP), int(y/kTP), rgb);
}

void DrawString(CWnd *wnd, const CString &Str, float x, float y) {
	CDC *cdc = wnd->GetDC();
	cdc->TextOut((int)x,(int)y,Str);
	wnd->ReleaseDC(cdc);
}
void DrawString(CWnd *wnd, const CString &Str) {
	DrawString(wnd, Str, float(CurrentX), float(CurrentY));
	CurrentX = 0;
	LOGFONT lf;
	wnd->GetFont()->GetLogFont(&lf);
	int lfHeight = lf.lfHeight;
	if (lfHeight<0) lfHeight = -lfHeight;
	CurrentY += lfHeight + 3;
}

char *TranslateCFileDialogFilter(const CString &sFilter) {
	int nb = sFilter.GetLength();
	char *cFilter = new char[nb+2];
	char *pFilter = cFilter;
	for(int i=0; i<nb; i++)
		*pFilter++ = (sFilter[i]!='|') ? sFilter[i] : '\0';
	*pFilter++ = '\0';
	*pFilter = '\0';
	return cFilter;
}

int GetRangeMin(CScrollBar &sb) {
	int MinPos, MaxPos;
	sb.GetScrollRange(&MinPos, &MaxPos);
	return MinPos;
}

int GetRangeMax(CScrollBar &sb) {
	int MinPos, MaxPos;
	sb.GetScrollRange(&MinPos, &MaxPos);
	return MaxPos;
}

void SetRangeMin(CScrollBar &sb, int nMinPos) {
	int MinPos, MaxPos;
	sb.GetScrollRange(&MinPos, &MaxPos);
	sb.SetScrollRange(nMinPos,  MaxPos);
}

void SetRangeMax(CScrollBar &sb, int nMaxPos) {
	int MinPos, MaxPos;
	sb.GetScrollRange(&MinPos, &MaxPos);
	sb.SetScrollRange( MinPos, nMaxPos);
}

int GetRangeMin(CProgressCtrl &pb) {
	int MinPos, MaxPos;
	pb.GetRange(MinPos, MaxPos);
	return MinPos;
}

int GetRangeMax(CProgressCtrl &pb) {
	int MinPos, MaxPos;
	pb.GetRange(MinPos, MaxPos);
	return MaxPos;
}

void SetRangeMin(CProgressCtrl &pb, int nMinPos) {
	int MinPos, MaxPos;
	pb.GetRange  ( MinPos, MaxPos);
	pb.SetRange32(nMinPos, MaxPos);
}

void SetRangeMax(CProgressCtrl &pb, int nMaxPos) {
	int MinPos, MaxPos;
	pb.GetRange  (MinPos,  MaxPos);
	pb.SetRange32(MinPos, nMaxPos);
}



int GetMin(const CSpinButtonCtrl *pCSpinButton) {
	int lower, upper;
	pCSpinButton->GetRange32(lower, upper);
	return lower;
}
int GetMax(const CSpinButtonCtrl *pCSpinButton) {
	int lower, upper;
	pCSpinButton->GetRange32(lower, upper);
	return upper;
}
void SetMin(CSpinButtonCtrl *pCSpinButton, int value) {
	int lower, upper;
	pCSpinButton->GetRange32(lower, upper);
	pCSpinButton->SetRange32(value, upper);
}
void SetMax(CSpinButtonCtrl *pCSpinButton, int value) {
	int lower, upper;
	pCSpinButton->GetRange32(lower, upper);
	pCSpinButton->SetRange32(lower, value);
}

int Int(double d) {
	if (d>=0) return (int)d;
	int ret = -(int)(-d);
	return ret==d ? ret : ret-1;
}


//***************************************************************************
// This function provides essentially the same functionality as the LIKE operator in Visual Basic
// If string matches pattern, return is TRUE; if there is no match, return is FALSE. If either string or pattern is Null, return is FALSE;
// Parameters:
//	String    String to be compared with pattern.
//	Pattern   Any string conforming to the pattern-matching conventions described in Remarks.
//	bCaseSensitive  TRUE if comparison should be case sensitive.
// CAUTION: Function is recursive
//***************************************************************************
inline int ConvertCase(int c, BOOL bCaseSensitive) {
	return bCaseSensitive ? c : toupper(c);
}
BOOL pLike(LPCTSTR String, LPCTSTR Pattern, BOOL bCaseSensitive)
{
	TCHAR c, p, l;
	for(;;)
	{
		switch (p = ConvertCase( *Pattern++, bCaseSensitive ) )
		{
		case 0:	// end of pattern
			return *String ? FALSE : TRUE;  // if end of string TRUE

		case _T('*'):
			while (*String)
			{	// match zero or more char
				if (pLike(String++, Pattern, bCaseSensitive))
					return TRUE;
			}
			return pLike(String, Pattern, bCaseSensitive );

		case _T('?'):
			if (*String++ == 0)             // match any one char
				return FALSE;               // not end of string
			break;

		case _T('['):
			// match char set
			if ( (c = ConvertCase( *String++, bCaseSensitive) ) == 0)
				return FALSE;               // syntax
			l = 0;
			if ( *Pattern == _T('!') )		// match a char if NOT in set []
			{
				++Pattern;
				while( (p = ConvertCase( *Pattern++, bCaseSensitive) ) != _T('\0') )
				{
					if (p == _T(']'))     // if end of char set, then
						break;            // no match found

					if (p == _T('-'))
					{	// check a range of chars?
						p = ConvertCase( *Pattern, bCaseSensitive );
						// get high limit of range
						if (p == 0  ||  p == _T(']'))
							return FALSE;     // syntax

						if (c >= l  &&  c <= p)
							return FALSE;     // if in range, return FALSE
					}
					l = p;
					if (c == p)               // if char matches this element
						return FALSE;         // return false
				}
			}
			else    // match if char is in set []
			{
				while( (p = ConvertCase( *Pattern++, bCaseSensitive) ) != _T('\0') )
				{
					if (p == _T(']'))         // if end of char set, then
						return FALSE;         // no match found

					if (p == _T('-'))
					{	// check a range of chars?
						p = ConvertCase( *Pattern, bCaseSensitive );
						// get high limit of range
						if (p == 0  ||  p == _T(']'))
							return FALSE;       // syntax

						if (c >= l  &&  c <= p)
							break;              // if in range, move on
					}
					l = p;
					if (c == p)                 // if char matches this element
						break;                  // move on
				}

				while (p  &&  p != _T(']'))     // got a match in char set
					p = *Pattern++;             // skip to end of set
			}

			break;

		case _T('#'):
			c = *String++;
			if (!_istdigit(c))
				return FALSE;        // not a digit

			break;

		default:
			c = ConvertCase( *String++, bCaseSensitive );
			if (c != p)             // check for exact char
				return FALSE;       // not a match

			break;
		}
	}
}
bool Like(const CString &sString, const CString &sPattern) {
	return pLike(sString, sPattern, true) ? true : false;
}

char CommonDialogStrFile[_MAX_PATH];


VBtoListViewItem GetVBtoListViewItem(CListCtrl &mListCtrl, int ItemIndex)
{
	VBtoListViewItem Item;
	Item.pListCtrl = &mListCtrl;
	Item.ItemIndex = ItemIndex;
	return Item;
}

VBtoListViewItem GetVBtoSelectedItem(CListCtrl &mListCtrl)
{
	VBtoListViewItem Item;
	Item.pListCtrl = &mListCtrl;
	Item.ItemIndex = mListCtrl.GetNextItem(-1,LVNI_SELECTED);
	return Item;
}



//===============================================================

int VBtoTreeItem::GetIndex() const {
	int ind = 0;
	for(HTREEITEM node=hItem;;ind++) {
		HTREEITEM nodePrev = pTrV->GetPrevSiblingItem(node);
		if (nodePrev) {
			ind += ::GetChildren(*pTrV, nodePrev, true);
			node = nodePrev;
		} else {
			node = pTrV->GetParentItem(node);
			if (!node) return ind;
		}
	}
}

void SetItemData(CTreeCtrl &mTrV, HTREEITEM hItem, const CComVariant &ccv) {
	CComVariant *pccv = (CComVariant *) mTrV.GetItemData(hItem);
	if (pccv) delete pccv;
	pccv = new CComVariant(ccv);
	mTrV.SetItemData(hItem, (unsigned long)pccv);
}
void SetItemData(CTreeCtrl &mTrV, HTREEITEM hItem, const char *pBuf) {
	CComVariant ccv = pBuf;
	SetItemData(mTrV, hItem, ccv);
}
CString GetItemDataAsString(const CTreeCtrl &mTrV, HTREEITEM hItem) {
	CComVariant *pccv = (CComVariant *) mTrV.GetItemData(hItem);
	if (!pccv) return "";
	CComVariant ret = *pccv;
	ret.ChangeType(VT_BSTR);
	CComBSTR cc = ret.bstrVal;
	return CString(cc.m_str);
}

CString GetFullPath(const CTreeCtrl &mTrV, HTREEITEM hItem) {
	CString fp;
	while(hItem) {
		fp = mTrV.GetItemText(hItem) + fp;
		hItem = mTrV.GetParentItem(hItem);
		if (hItem) fp = "\\" + fp;
	}
	return fp;
}

int GetChildren(const CTreeCtrl &mTrV, HTREEITEM hItem, BOOL flAll) {
	int nChild = 0;
	for(hItem=mTrV.GetChildItem(hItem); hItem; hItem=mTrV.GetNextSiblingItem(hItem)) {
		if (flAll && mTrV.GetChildItem(hItem))
			nChild += GetChildren(mTrV, hItem, true);
		nChild++;
	}
	return nChild;
}

HTREEITEM FindItemByKey(const CTreeCtrl &mTrV, HTREEITEM FirstNode, const CString &Key) {
	for(HTREEITEM node=FirstNode; node; node=mTrV.GetNextSiblingItem(node)) {
		CString s = GetItemDataAsString(mTrV, node);
		if (s==Key) return node;
		HTREEITEM nodeChild = mTrV.GetChildItem(node);
		if (nodeChild) {
			nodeChild = FindItemByKey(mTrV, nodeChild, Key);
			if (nodeChild) return nodeChild;
		}
	}
	return 0;
}

HTREEITEM GetItem(CTreeCtrl &mTrV, HTREEITEM nodeFirst, int &ind) {
	for(HTREEITEM node=nodeFirst;;ind--) {
		if (ind<=0) return node;

		HTREEITEM nodeChild = mTrV.GetChildItem(node);
		if (nodeChild) {
			ind--;
			nodeChild = GetItem(mTrV, nodeChild, ind);
			if (ind<=0) return nodeChild;
		}

		node = mTrV.GetNextSiblingItem(node);
		if (!node) return 0;
	}
}
HTREEITEM GetItem(CTreeCtrl &mTrV, int ind) {
	return GetItem(mTrV, mTrV.GetRootItem(), ind);
}

VBtoTreeItem InsertItemAux(CTreeCtrl &mTrV, CString Key, CString Text, int imageIndex, int selImageIndex, HTREEITEM hParent, HTREEITEM hInsertAfter) {
/*
HTREEITEM InsertItem(
   UINT nMask,
   LPCTSTR lpszItem,
   int nImage,
   int nSelectedImage,
   UINT nState,
   UINT nStateMask,
   LPARAM lParam,
   HTREEITEM hParent,
   HTREEITEM hInsertAfter 
); 
mask	Array of flags that indicate which of the other structure members contain valid data. 
When this structure is used with the TVM_GETITEM message, the mask member indicates the item attributes to retrieve. 
This member can be one or more of the following values. 
TVIF_CHILDREN		The cChildren member is valid.
TVIF_DI_SETITEM		The tree-view control will retain the supplied information and will not request it again. This flag is valid only when processing the TVN_GETDISPINFO notification.
TVIF_HANDLE			The hItem member is valid.
*TVIF_IMAGE			The iImage member is valid.
*TVIF_PARAM			The lParam member is valid.
*TVIF_SELECTEDIMAGE	The iSelectedImage member is valid.
TVIF_STATE			The state and stateMask members are valid.
TVIF_TEXT			The pszText and cchTextMax members are valid.
*/
	UINT nMask = 0;
	if (!Text.IsEmpty())	nMask |= TVIF_TEXT;
	if (imageIndex>=0)		nMask |= TVIF_IMAGE;
	if (selImageIndex>=0)	nMask |= TVIF_SELECTEDIMAGE;
	LPARAM lParam = 0;
	if (!Key.IsEmpty())	{
		CComVariant *pccv = new CComVariant(Key);
		lParam = (long) pccv;
		nMask |= TVIF_PARAM;
	}

	VBtoTreeItem Node = VBtoTreeItem(mTrV, mTrV.InsertItem(nMask, Text.LockBuffer(), imageIndex, selImageIndex, 0, 0, lParam, hParent, hInsertAfter));
	Text.UnlockBuffer();

	return Node;
}
VBtoTreeItem InsertItem(CTreeCtrl &mTrV, VBtoTreeItem RelativeNode, int Relationship, CString Key, CString Text, int imageIndex, int selImageIndex) {
	HTREEITEM hParent, hInsertAfter;
	switch(Relationship) {
		default:
		case _tvwLast: {
			hParent = mTrV.GetParentItem(RelativeNode.hItem);
			hInsertAfter = TVI_LAST;
			break;
		}
		case _tvwFirst: {
			hParent = mTrV.GetParentItem(RelativeNode.hItem);
			hInsertAfter = TVI_FIRST;
			break;
		}
		case _tvwNext: {
			hParent = mTrV.GetParentItem(RelativeNode.hItem);
			hInsertAfter = RelativeNode.hItem;
			break;
		}
		case _tvwPrevious: {
			hParent = mTrV.GetParentItem(RelativeNode.hItem);
			hInsertAfter = mTrV.GetPrevSiblingItem(RelativeNode.hItem);
			if (!hInsertAfter) hInsertAfter = TVI_FIRST;
			break;
		}
		case _tvwChild: {
			hParent = RelativeNode.hItem;
			hInsertAfter = TVI_LAST;
			break;
		}
	}
	VBtoTreeItem Node = InsertItemAux(mTrV, Key, Text, imageIndex, selImageIndex, hParent, hInsertAfter);
	return Node;
}
VBtoTreeItem InsertItem(CTreeCtrl &mTrV, CString Key, CString Text, int imageIndex, int selImageIndex) {
	VBtoTreeItem Node = InsertItemAux(mTrV, Key, Text, imageIndex, selImageIndex, TVI_ROOT, TVI_LAST);
	return Node;
}
VBtoTreeItem InsertItem(CTreeCtrl &mTrV, CString RelativeKey, int Relationship, CString Key, CString Text, int imageIndex, int selImageIndex) {
	HTREEITEM RelativeNodehItem = FindItemByKey(mTrV, mTrV.GetRootItem(), RelativeKey);
	return RelativeNodehItem ? InsertItem(mTrV, VBtoTreeItem(mTrV,RelativeNodehItem), Relationship, Key, Text, imageIndex, selImageIndex) : VBtoTreeItem(mTrV,0);
}

CString GetItemText(CTabCtrl *pTabCtrl, int ind) {
	if (ind<0) return "";
	char buffer[256] = {0};
	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = buffer;
	tcItem.cchTextMax = sizeof(buffer);
	pTabCtrl->GetItem(ind, &tcItem);
	return tcItem.pszText;
}
CString GetSelectedItemText(CTabCtrl *pTabCtrl) {
	int ind = pTabCtrl->GetCurSel();
	return GetItemText(pTabCtrl, ind);
}
void SetItemText(CTabCtrl *pTabCtrl, int ind, CString text) {
	if (ind<0) return;
	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = text.LockBuffer();
	pTabCtrl->SetItem(ind, &tcItem);
	text.UnlockBuffer();
}
void SetSelectedItemText(CTabCtrl *pTabCtrl, CString text) {
	int ind = pTabCtrl->GetCurSel();
	SetItemText(pTabCtrl, ind, text);
}
CComVariant GetItemParam(CTabCtrl *pTabCtrl, int ind) {
	//if (ind<0) { CComVariant ccv; return ccv; }
	TCITEM tcItem;
	tcItem.mask = TCIF_PARAM;
	if (pTabCtrl->GetItem(ind, &tcItem)) {
		CComVariant *pccv = (CComVariant *) tcItem.lParam;
		if (pccv) return *pccv;
	}
	CComVariant ccv; 
	return ccv;
}
CComVariant GetSelectedItemParam(CTabCtrl *pTabCtrl) {
	int ind = pTabCtrl->GetCurSel();
	return GetItemParam(pTabCtrl, ind);
}
void SetItemParam(CTabCtrl *pTabCtrl, int ind, CComVariant *pccv) {
	if (ind<0) return;
	TCITEM tcItem;
	tcItem.mask = TCIF_PARAM;
	if (pTabCtrl->GetItem(ind, &tcItem)) {
		delete ((CComVariant *)tcItem.lParam);
	}
	tcItem.lParam = (long)pccv;
	pTabCtrl->SetItem(ind, &tcItem);
}
void SetSelectedItemParam(CTabCtrl *pTabCtrl, CComVariant *pccv) {
	int ind = pTabCtrl->GetCurSel();
	SetItemParam(pTabCtrl, ind, pccv);
}



/////////////////////////////////////////////////////////////////////////////
// CfrmVBtoInputBox dialog
/////////////////////////////////////////////////////////////////////////////
class CfrmVBtoInputBox : public CDialog 
{
public:
	CfrmVBtoInputBox(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDDfrmVBtoInputBox };
	CString Prompt, Title, Result;

protected:
	HICON m_hIcon;

	//{{AFX_MSG(CfrmVBtoInputBox)
	virtual BOOL OnInitDialog();
	afx_msg void OncmdCancel();
	afx_msg void OncmdOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CfrmVBtoInputBox, CDialog)
	//{{AFX_MSG_MAP(CfrmVBtoInputBox)
	ON_BN_CLICKED(cmdOk, OncmdOk)
	ON_BN_CLICKED(cmdCancel, OncmdCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CfrmVBtoInputBox::CfrmVBtoInputBox(CWnd* pParent /*=NULL*/)
	: CDialog(CfrmVBtoInputBox::IDD, pParent) 
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
BOOL CfrmVBtoInputBox::OnInitDialog() {
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);		// Set big icon
	SetIcon(m_hIcon, FALSE);	// Set small icon

	GetDlgItem(lblPrompt)->SetWindowText(Prompt);
	if (!Title .IsEmpty()) SetWindowText(Title);
	if (!Result.IsEmpty()) GetDlgItem(txtResult)->SetWindowText(Result);
	Result = "";

	return TRUE;
}
void CfrmVBtoInputBox::OncmdOk() {
	GetDlgItem(txtResult)->GetWindowText(Result);
	PostMessage(WM_CLOSE,0,0);
}
void CfrmVBtoInputBox::OncmdCancel() {
	PostMessage(WM_CLOSE,0,0);
}
CString InputBox(const CString &Prompt, const CString &Title, const CString &Default, int XPos, int YPos) {  // [HelpFile], [Context]
	CfrmVBtoInputBox dlgVBtoInputBox;
	dlgVBtoInputBox.Prompt	= Prompt;
	dlgVBtoInputBox.Title	= Title;
	dlgVBtoInputBox.Result	= Default;
	dlgVBtoInputBox.DoModal();
	return dlgVBtoInputBox.Result;
}

CString vbGetCommandLine() {
	CString CommandLine;
	for (int i=1; i<__argc; i++) {
		if (i!=1) CommandLine += " ";
		bool flSpace = strchr(__argv[i],' ') ? true : false;
		if (flSpace) CommandLine += '"';
		CommandLine += __argv[i];
		if (flSpace) CommandLine += '"';
	}
	return CommandLine;
}


//=========================================================
//=========================================================
CVBtoPrinter::CVBtoPrinter() {
	m_printer.OpenDefaultPrinter();
	m_devmode.CopyFromPrinter(m_printer);

	CDC dc;
	dc.Attach(m_printer.CreatePrinterDC(m_devmode.m_pDevMode));
	int x = dc.GetDeviceCaps(PHYSICALOFFSETX)*2540/dc.GetDeviceCaps(LOGPIXELSX);
	int y = dc.GetDeviceCaps(PHYSICALOFFSETY)*2540/dc.GetDeviceCaps(LOGPIXELSY);
	dc.Detach();

	m_rcMargin = CRect(x, y, x, y);

	m_sJobName = "VBto Document";
	m_bPrinting = false;

	IsStartDoc = false;
	DrawWidth = 1;
	DrawStyle = 0;
	FillStyle = 1;
	FillColor = 0;	// Black
	PageNumber = 0;
	pDefaultFont = NULL;
}

void CVBtoPrinter::UpdateFont() {
	CFont *pFont = new CFont();
	pFont->CreateFontIndirect(&logFont);
	CFont *pOldFont = dcPrinter.SelectObject(pFont);
	if (pDefaultFont) delete pOldFont; 
	else pDefaultFont = pOldFont;
}

CPoint CVBtoPrinter::VB6toAPI(double vx, double vy) {
	CPoint p;
	p.x = (int) (vx * kX);
	p.y = (int) (vy * kY);
	return p;
}

bool CVBtoPrinter::StartDoc(bool bDisplayPrintDialog) {
	if (IsStartDoc) return true;
	IsStartDoc = true;

	PageNumber = 1;

	memset(&m_docinfo, 0, sizeof(m_docinfo));
	m_docinfo.cbSize = sizeof(m_docinfo);
	m_docinfo.lpszDocName = m_sJobName;

	// вывод диалога печати
	if (bDisplayPrintDialog) {
		CPrintDialog dlg(FALSE);
		dlg.m_pd.hDevMode = m_devmode.CopyToHDEVMODE();
		dlg.m_pd.hDevNames = m_printer.CopyToHDEVNAMES();
		dlg.m_pd.Flags &= ~PD_NOPAGENUMS;

		if (dlg.DoModal() != IDOK) {
			::GlobalFree(dlg.m_pd.hDevMode);
			::GlobalFree(dlg.m_pd.hDevNames);
			return false;
		} else {
			m_devmode.CopyFromHDEVMODE(dlg.m_pd.hDevMode);
			m_printer.ClosePrinter();
			m_printer.OpenPrinter(dlg.m_pd.hDevNames, m_devmode.m_pDevMode);
				
			if ((dlg.m_pd.Flags & PD_PRINTTOFILE) != 0)
				m_docinfo.lpszOutput = _T("FILE:");
		}
		::GlobalFree(dlg.m_pd.hDevMode);
		::GlobalFree(dlg.m_pd.hDevNames);
	}

	dcPrinter.Attach(m_printer.CreatePrinterDC(m_devmode.m_pDevMode));
	if (dcPrinter.m_hDC == NULL) return false;

	memset(&logFont, 0, sizeof(LOGFONT));
	logFont.lfHeight = dcPrinter.GetDeviceCaps(LOGPIXELSY)*10/72;
	logFont.lfWeight = FW_REGULAR;	// FW_NORMAL
	strncpy(logFont.lfFaceName, "Arial", LF_FACESIZE);	// "MS Sans Serif"

	UpdateFont();

	dcPrinter.SetBkMode(TRANSPARENT);

	kX = dcPrinter.GetDeviceCaps(LOGPIXELSX)/1440.0;
	kY = dcPrinter.GetDeviceCaps(LOGPIXELSY)/1440.0;

	m_nJobID = ::StartDoc(dcPrinter, &m_docinfo);
	if (m_nJobID <= 0) return false;

	m_bPrinting = true;

	dcPrinter.StartPage();
	m_nPJState = dcPrinter.SaveDC();
		
	return true;
}

void CVBtoPrinter::OnPageSetup() {
	CPageSetupDialog dlg;
	dlg.m_psd.hDevMode = m_devmode.CopyToHDEVMODE();
	dlg.m_psd.hDevNames = m_printer.CopyToHDEVNAMES();
	dlg.m_psd.rtMargin = m_rcMargin;

	if (dlg.DoModal() == IDOK) {
		m_devmode.CopyFromHDEVMODE(dlg.m_psd.hDevMode);
		m_printer.ClosePrinter();
		m_printer.OpenPrinter(dlg.m_psd.hDevNames, m_devmode.m_pDevMode);
		m_rcMargin = dlg.m_psd.rtMargin;
	}

	::GlobalFree(dlg.m_psd.hDevMode);
	::GlobalFree(dlg.m_psd.hDevNames);
}

void CVBtoPrinter::NewPage() {
	if(!m_bPrinting) return;

	dcPrinter.RestoreDC(m_nPJState);
	dcPrinter.EndPage();
		
	dcPrinter.StartPage();
	m_nPJState = dcPrinter.SaveDC();

	PageNumber++;
}


// Вывод сформированного документа на печать
// bCancel - отменить печать
void CVBtoPrinter::EndDoc(bool bCancel) {
	if(!m_bPrinting) return;

	dcPrinter.RestoreDC(m_nPJState);
	dcPrinter.EndPage();
	
	if (bCancel)
		::AbortDoc(dcPrinter);
	else
		::EndDoc(dcPrinter);

	if (pDefaultFont) {
		dcPrinter.SelectObject(pDefaultFont);
		pDefaultFont = NULL;
	}

	dcPrinter.Detach();

	m_bPrinting = false;
	m_nJobID = 0;

	IsStartDoc = false;
	PageNumber = 0;
}


float CVBtoPrinter::GetCurrentX() { StartDoc(); return float(GetCDC()->GetCurrentPosition().x/kX); }
float CVBtoPrinter::GetCurrentY() { StartDoc(); return float(GetCDC()->GetCurrentPosition().y/kY); }

void CVBtoPrinter::SetCurrentX(float value) { StartDoc(); GetCDC()->MoveTo(VB6toAPI(value,0).x, GetCDC()->GetCurrentPosition().y); }
void CVBtoPrinter::SetCurrentY(float value) { StartDoc(); GetCDC()->MoveTo(GetCDC()->GetCurrentPosition().x, VB6toAPI(0,value).y); }


CString CVBtoPrinter::GetFontName() {
	return logFont.lfFaceName;
}
void CVBtoPrinter::SetFontName(const CString &value) {
	strncpy(logFont.lfFaceName, (const char *)value, LF_FACESIZE);
	logFont.lfFaceName[LF_FACESIZE-1]='\0';
	UpdateFont();
}

float CVBtoPrinter::GetFontSize() {
	float sz = float(logFont.lfHeight * 72. / dcPrinter.GetDeviceCaps(LOGPIXELSY));
	return sz;
}
void CVBtoPrinter::SetFontSize(float value) {
	StartDoc();
	logFont.lfHeight = long(dcPrinter.GetDeviceCaps(LOGPIXELSY)*value/72);
	UpdateFont();
}

bool CVBtoPrinter::GetFontBold() {
	return (logFont.lfWeight & FW_BOLD)!=0;
}
void CVBtoPrinter::SetFontBold(bool value) {
	StartDoc();
	if (value) {
		logFont.lfWeight |= FW_BOLD;
	} else {
		logFont.lfWeight &= ~FW_BOLD;
	}
	UpdateFont();
}

bool CVBtoPrinter::GetFontItalic() {
	return logFont.lfItalic!=0;
}
void CVBtoPrinter::SetFontItalic(bool value) {
	StartDoc();
	logFont.lfItalic = value;
	UpdateFont();
}

void CVBtoPrinter::Print(const CString &S) {
	StartDoc();
	CDC *cdc = GetCDC();
	CPoint cp = cdc->GetCurrentPosition();
	cdc->TextOut(cp.x,cp.y, S);
	int h = logFont.lfHeight;
	if (h<0) h = -h;
	cdc->MoveTo(0, cp.y + int(h*1.04));
}
void CVBtoPrinter::PSet(double x, double y, int rgbCol) {
	StartDoc();
	CPoint p = VB6toAPI(x,y);
	CDC *cdc = GetCDC();
	cdc->SetPixel(p,rgbCol);
	cdc->MoveTo(p);
}
void CVBtoPrinter::Line(double x1, double y1, double x2, double y2, int rgbCol) {
	StartDoc();
	CDC *cdc = GetCDC();
	CPen *pPenCur = new CPen(DrawStyle, DrawWidth, rgbCol);
	CPen *pPenOld = cdc->SelectObject(pPenCur);
	cdc->MoveTo(VB6toAPI(x1,y1));
	cdc->LineTo(VB6toAPI(x2,y2));
	cdc->SelectObject(pPenOld);
	delete pPenCur;
}
void CVBtoPrinter::LineTo(double x2, double y2, int rgbCol) {
	StartDoc();
	CDC *cdc = GetCDC();
	CPen *pPenCur = new CPen(DrawStyle, DrawWidth, rgbCol);
	CPen *pPenOld = cdc->SelectObject(pPenCur);
	cdc->LineTo(VB6toAPI(x2,y2));
	cdc->SelectObject(pPenOld);
	delete pPenCur;
}
void CVBtoPrinter::Rectangle(double x1, double y1, double x2, double y2, int rgbCol) {
	StartDoc();
	CPoint p1 = VB6toAPI(x1,y1);
	CPoint p2 = VB6toAPI(x2,y2);	
	CDC *cdc = GetCDC();
	CPen *pPenCur = new CPen(DrawStyle, DrawWidth, rgbCol);
	CPen *pPenOld = cdc->SelectObject(pPenCur);
	CBrush *pBrushOld = (CBrush*)cdc->SelectStockObject(NULL_BRUSH);
	cdc->Rectangle(p1.x,p1.y, p2.x,p2.y);
	cdc->MoveTo(p2);
	cdc->SelectObject(pBrushOld);
	cdc->SelectObject(pPenOld);
	delete pPenCur;
}
void CVBtoPrinter::Circle(double xC, double yC, double R, int rgbCol) {
	StartDoc();
	CPoint p1 = VB6toAPI(xC-R, yC-R);
	CPoint p2 = VB6toAPI(xC+R, yC+R);
	CDC *cdc = GetCDC();
	CPen *pPenCur = new CPen(DrawStyle, DrawWidth, rgbCol);
	CPen *pPenOld = cdc->SelectObject(pPenCur);
	if (FillStyle==1) {
		cdc->Ellipse(p1.x,p1.y, p2.x,p2.y);
	} else {
		CBrush *pBrushCur = new CBrush(FillColor);
		CBrush *pBrushOld = cdc->SelectObject(pBrushCur);
		cdc->Ellipse(p1.x,p1.y, p2.x,p2.y);
		cdc->SelectObject(pBrushOld);
		delete pBrushCur;
	}
	cdc->SelectObject(pPenOld);
	delete pPenCur;
}
void CVBtoPrinter::Arc(double xC, double yC, double R, double fiStart, double fiEnd, int rgbCol) {
	StartDoc();
	CPoint p1 = VB6toAPI(xC-R, yC-R);
	CPoint p2 = VB6toAPI(xC+R, yC+R);
	CPoint pC = VB6toAPI(xC, yC);
	int ix3 = int(pC.x+1000*cos(-fiStart));	int ix4 = int(pC.x+1000*cos(-fiEnd));
	int iy3 = int(pC.y+1000*sin(-fiStart));	int iy4 = int(pC.y+1000*sin(-fiEnd));
	CDC *cdc = GetCDC();
	CPen *pPenCur = new CPen(DrawStyle, DrawWidth, rgbCol);
	CPen *pPenOld = cdc->SelectObject(pPenCur);
	cdc->Arc(p1.x,p1.y, p2.x,p2.y, ix3,iy3, ix4,iy4);
	cdc->SelectObject(pPenOld);
	delete pPenCur;
}

CVBtoPrinter VBtoPrinter;



//====================================================
VBtoFontAttribute::VBtoFontAttribute() {
	pWnd = NULL;
	pFont = NULL;
	pLogFont = NULL;
	rgbForeColor = RGB(0,0,0);
	rgbBackColor = RGB(255,255,255);
	mBrush.CreateSolidBrush(rgbBackColor);
}
VBtoFontAttribute::~VBtoFontAttribute() {
	delete pFont;
	delete pLogFont;
}
void VBtoFontAttribute::Set(CWnd* pWnd_, int rgbForeColor_, int rgbBackColor_,
	const char *pFaceName, float PointSize,
	bool flBold, bool flItalic, bool flStrikeOut, bool flUnderline, BYTE lfCharSet) {

	pWnd = pWnd_;
	rgbForeColor = rgbForeColor_;
	rgbBackColor = rgbBackColor_;
	mBrush.DeleteObject();
	mBrush.CreateSolidBrush(rgbBackColor);

	if (!pWnd) return;
	if (!(pFaceName || PointSize || flBold || flItalic || flStrikeOut || flUnderline || lfCharSet!=DEFAULT_CHARSET)) return;

	CreateFont();

	if (pFaceName) strcpy(pLogFont->lfFaceName, pFaceName);

	if (PointSize) {
		CPaintDC dc(pWnd);
		pLogFont->lfHeight = - long(PointSize * dc.GetDeviceCaps(LOGPIXELSY) / 72);
	}

	if (flBold) pLogFont->lfWeight = FW_BOLD;
	pLogFont->lfItalic		= flItalic;
	pLogFont->lfStrikeOut	= flStrikeOut;
	pLogFont->lfUnderline	= flUnderline;
	if (lfCharSet!=DEFAULT_CHARSET)
		pLogFont->lfCharSet	= lfCharSet;

	UpdateFont();
}

void VBtoFontAttribute::SetForeColor(int rgbForeColor_) {
	rgbForeColor = rgbForeColor_;
	if (pWnd) pWnd->Invalidate();
}
void VBtoFontAttribute::SetBackColor(int rgbBackColor_) {
	rgbBackColor = rgbBackColor_;
	mBrush.DeleteObject();
	mBrush.CreateSolidBrush(rgbBackColor);
	if (pWnd) pWnd->Invalidate();
}

CString VBtoFontAttribute::GetFontName() const { 
	return pLogFont ? pLogFont->lfFaceName : "NULL"; 
}
double VBtoFontAttribute::GetFontSize() const {
	if (!pLogFont) return 0;
	CPaintDC dc(pWnd);
	return -pLogFont->lfHeight * 72. / dc.GetDeviceCaps(LOGPIXELSY);
}

void VBtoFontAttribute::SetFontName(const CString &FaceName) {
	if (!pWnd) return;
	CreateFont();
	strcpy(pLogFont->lfFaceName, (const char *)FaceName);
	UpdateFont();
}
void VBtoFontAttribute::SetFontSize(double PointSize) {
	if (!pWnd) return;
	CreateFont();
	CPaintDC dc(pWnd);
	pLogFont->lfHeight = - long(PointSize * dc.GetDeviceCaps(LOGPIXELSY) / 72);
	UpdateFont();
}
void VBtoFontAttribute::SetFontWeight(long lfWeight) {
	if (!pWnd) return;
	CreateFont();
	pLogFont->lfWeight = lfWeight;
	UpdateFont();
}
void VBtoFontAttribute::SetFontCharset(short lfCharSet) {
	if (!pWnd) return;
	CreateFont();
	pLogFont->lfCharSet = (byte) lfCharSet;
	UpdateFont();
}
void VBtoFontAttribute::SetFontBold(bool flBold) {
	if (!pWnd) return;
	CreateFont();
	pLogFont->lfWeight = flBold ? FW_BOLD : FW_NORMAL;
	UpdateFont();
}
void VBtoFontAttribute::SetFontItalic(bool flItalic) {
	if (!pWnd) return;
	CreateFont();
	pLogFont->lfItalic = flItalic;
	UpdateFont();
}
void VBtoFontAttribute::SetFontStrikeOut(bool flStrikeOut) {
	if (!pWnd) return;
	CreateFont();
	pLogFont->lfStrikeOut = flStrikeOut;
	UpdateFont();
}
void VBtoFontAttribute::SetFontUnderline(bool flUnderline) {
	if (!pWnd) return;
	CreateFont();
	pLogFont->lfUnderline = flUnderline;
	UpdateFont();
}

HBRUSH VBtoFontAttribute::OnCtlColor(CDC* pDC) {
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(rgbForeColor);
	//pDC->SetBkColor(rgbBackColor);
	return (HBRUSH)(mBrush.GetSafeHandle()); // mBrush
	//return GetSysColorBrush(COLOR_WINDOW);
}

void VBtoFontAttribute::CreateFont() {
	if (pFont) return;
	pFont = new CFont();
	pLogFont = new LOGFONT();
	pWnd->GetFont()->GetLogFont(pLogFont);
	pFont->CreateFontIndirect(pLogFont);
}
void VBtoFontAttribute::UpdateFont() {
	pFont->DeleteObject();
	pFont->CreateFontIndirect(pLogFont);
	pWnd->SetFont(pFont);
	pWnd->Invalidate();
}

FARPROC GetAddress(const char *pLibFileName, const char *pProcName, HINSTANCE *phLib) {
	if (phLib) *phLib = NULL;
	HINSTANCE hLib=LoadLibrary(pLibFileName);
	if (hLib < (HINSTANCE)32) {
		// Couldn't load DLL
		// ...
		return NULL;
	}
	//char Filename[300];
	//GetModuleFileName((HMODULE)hLib, Filename, sizeof(Filename));
	FARPROC pAddress = GetProcAddress((HMODULE)hLib, pProcName);
	if (!pAddress) {
		FreeLibrary((HMODULE)hLib);
		hLib = 0;
	}
	if (phLib) *phLib = hLib;
	return pAddress;
	//...FreeLibrary((HMODULE)hLib);
}

HDC GetHDC(CWnd *pWnd) {
	static CWnd *pWndPrev = NULL;
	static HDC hDCPrev = 0;

	if (pWnd==pWndPrev) return hDCPrev;
	if (pWndPrev) ReleaseDC(pWndPrev->m_hWnd, hDCPrev);

	pWndPrev = pWnd;
	hDCPrev = pWndPrev ? pWndPrev->GetDC()->m_hDC : 0;
	return hDCPrev;
}

CString GetAppPath() {
	char drive[_MAX_DRIVE], dir[_MAX_DIR];
	_splitpath(__argv[0], drive, dir, NULL, NULL);
	int len = strlen(dir);
	if (len>0 && dir[--len]=='\\') dir[len] = '\0';
	return CString(drive) + dir;
}

void ShowModeless(CDialog *pDlg, UINT nIDTemplate) {
	if (pDlg->m_hWnd) pDlg->ShowWindow(SW_SHOW);
	else pDlg->Create(nIDTemplate);
}


//=========================================================
class VBtoAutoCoInitialize {
public:
	VBtoAutoCoInitialize() {
		::CoInitialize(NULL);
	}
	~VBtoAutoCoInitialize() {
		//::CoUninitialize();
	}
} m_VBtoAutoCoInitialize;

