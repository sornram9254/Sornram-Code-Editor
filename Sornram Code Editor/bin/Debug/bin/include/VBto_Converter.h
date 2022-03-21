//				file	VBto_Converter.h
// This is a part of the VBto Converter (www.vbto.net). Copyright (C) 2005-2014 StressSoft Company Ltd. All rights reserved.
//

#ifndef VBto_Converter_AddFunctions_H
#define VBto_Converter_AddFunctions_H

#include <winspool.h>
#include <assert.h>

 int QBColor(int iColor);
 
 CString GetWindowText(const CWnd *wnd);
 inline CString GetWindowText(const CWnd &wnd) { return GetWindowText(&wnd); }
 int GetLeft  (const CWnd *wnd);	inline int GetLeft  (const CWnd &wnd) { return GetLeft  (&wnd); }
 int GetTop   (const CWnd *wnd);	inline int GetTop   (const CWnd &wnd) { return GetTop   (&wnd); }
 int GetWidth (const CWnd *wnd);	inline int GetWidth (const CWnd &wnd) { return GetWidth (&wnd); }
 int GetHeight(const CWnd *wnd);	inline int GetHeight(const CWnd &wnd) { return GetHeight(&wnd); }
 void SetLeft  (CWnd *wnd, int value);	inline void SetLeft  (CWnd &wnd, int value) { SetLeft  (&wnd,value); }
 void SetTop   (CWnd *wnd, int value);	inline void SetTop   (CWnd &wnd, int value) { SetTop   (&wnd,value); }
 void SetWidth (CWnd *wnd, int value);	inline void SetWidth (CWnd &wnd, int value) { SetWidth (&wnd,value); }
 void SetHeight(CWnd *wnd, int value);	inline void SetHeight(CWnd &wnd, int value) { SetHeight(&wnd,value); }
 int InStrRev(const CString &StringCheck, const CString &StringMatch, int iStart=-1);
 CString StrReverse(const CString &csI);
 void RSet(CString &lS, const CString &rS);
 void LSet(CString &lS, const CString &rS);
 CString UCase(const CString &csI);
 CString LCase(const CString &csI);
 CString Trim(const CString &csI);
 CString LTrim(const CString &csI);
 CString RTrim(const CString &csI);
 
 CString Format(const char *fmt, ...);
 
 CString FormatVB(short  val, const char *vbfmt=NULL);
 CString FormatVB(int    val, const char *vbfmt=NULL);
 CString FormatVB(long   val, const char *vbfmt=NULL);
 CString FormatVB(float  val, const char *vbfmt=NULL);
 CString FormatVB(double val, const char *vbfmt=NULL);
 CString FormatVB(const char *str  , const char *vbfmt=NULL);
 CString FormatVB(const CString &cs, const char *vbfmt=NULL);
 
 CString Str(short h);
 CString Str(int i);
 CString Str(unsigned int u);
 CString Str(float f);
 CString Str(double d);
 CString Str(bool b);
 CString Str(CString s);
 inline CString Str(const char *ps) { return CString(ps); }
 CString Str(const CComVariant &v);

 inline CString DATEtoCString(DATE d) { return COleDateTime(d).Format(/*LOCALE_NOUSEROVERRIDE,LANG_USER_DEFAULT*/); }
 CString LocaleSDesimal();
 
 CString ToString(short h);
 CString ToString(int i);
 CString ToString(long l);
 CString ToString(float f);
 CString ToString(double d);
 CString ToStringLocale(double d);
 double StrToDouble(CString s);
 CString CStr(double d);
 CString CStr(CString s);
 
 CString Hex(short val);
 CString Hex(int val);
 
 CString Oct(short val);
 CString Oct(int val);
 int Asc(const CString &cs);
 
 double Val(CComVariant v);
 double Val(const char * pBuf);
 inline double Val(const CString &s) { return Val((const char *)s); }
 inline double Val(double d) { return d; }
 
 bool CBool(const char * ps);
 bool CBool(CComVariant v);
 inline bool CBool(bool b) { return b; }
 inline bool CBool(int d) { return d!=0; }
 inline bool CBool(double d) { return d!=0; }
 inline bool CBool(const CString &cs) { return CBool((const char *)cs); }
 
 double CDbl(CString s);
 inline double CDbl(double d) { return d; }
 
 float CSng(CString s);
 inline float CSng(double d) { return (float)d; }
 
 short CInt(CString s);
 inline short CInt(double d) { return (short)(d>=0 ? (d+0.5) : (d-0.5)); }
 
 int CLng(CString s);
 inline int CLng(double d) { return (int)(d>=0 ? (d+0.5) : (d-0.5)); }
 int Sign(double d);
 
 int Round(double d);
 int Round(const char *s);
 inline int Round(const CString &s) { return Round((const char *)s); }
 double Round(double d, int NumDigitsAfterDecimal);
 bool IsNumeric(const CString &s);
 CString GetText(const CListBox &lb);
 CString GetText(const CComboBox &cb, int ind);
 CString GetText(const CListBox &lb, int ind);
 
 inline void ResetString(CListBox *pLB, int ind, const CString &cs) {
	pLB->DeleteString(ind);
	pLB->InsertString(ind, cs);
 }
 inline void ResetString(CComboBox *pCB, int ind, const CString &cs) {
	pCB->DeleteString(ind);
	pCB->InsertString(ind, cs);
 }
 inline void ResetString(CListBox  &mLB, int ind, const CString &cs) { ResetString(&mLB, ind, cs); }
 inline void ResetString(CComboBox &mCB, int ind, const CString &cs) { ResetString(&mCB, ind, cs); }

 
 inline void SetViewStyle(CListCtrl *pListCtrl, DWORD FlagViewStyle) {
	pListCtrl->ModifyStyle(LVS_ICON|LVS_SMALLICON|LVS_LIST|LVS_REPORT, FlagViewStyle);
 }
 inline void SetViewStyle(CListCtrl &mListCtrl, DWORD FlagViewStyle) { SetViewStyle(&mListCtrl,FlagViewStyle); }
 
 inline int GetViewStyle(CListCtrl *pListCtrl) {
	return pListCtrl->GetStyle() & (LVS_ICON|LVS_SMALLICON|LVS_LIST|LVS_REPORT);
 }
 inline int GetViewStyle(CListCtrl &mListCtrl) { return GetViewStyle(&mListCtrl); }
 
 inline void SetSortOrder(CListCtrl *pListCtrl, DWORD FlagOrder) {
	if (FlagOrder & LVS_SORTDESCENDING)
			pListCtrl->ModifyStyle(LVS_SORTASCENDING, LVS_SORTDESCENDING);
	else	pListCtrl->ModifyStyle(LVS_SORTDESCENDING, LVS_SORTASCENDING);
 }
 inline void SetSortOrder(CListCtrl &mListCtrl, DWORD FlagOrder) { SetSortOrder(&mListCtrl, FlagOrder); }
 
 inline void mModifyStyle(CWnd *pWnd, DWORD dwFlags, bool bAddFlags) {
	bAddFlags ? pWnd->ModifyStyle(0,dwFlags) : pWnd->ModifyStyle(dwFlags,0);
 }
 inline void mModifyStyle(CWnd &mWnd, DWORD dwFlags, bool bAddFlags) { mModifyStyle(&mWnd, dwFlags, bAddFlags); }
 void Kill(const CString &PathName);
 CString Dir(const CString &PathName);
 CString Dir();

 CString GetCurrentDirectory();
 void DoEvents(HWND hWndEvents=NULL);	// - remove any messages that may be in the queue
 void PrintLine(HANDLE hf, const CString &cs="");
 void Print(HANDLE hf, const CString &cs="");
 void LineInput(HANDLE hf, CString &cs);
 bool IsEOF(HANDLE hf);
 void Randomize(int v=0);
 
 double Rnd();
 double Rnd(float v);
 
 #define kTP	15
 extern int CurrentX, CurrentY;
 
//===================================================================
 #define M_PI 3.14159265358979323846

class PictureProperties {
 public:
	PictureProperties()
	{
		DrawMode  = 0;
		DrawWidth = 1;
		DrawStyle = 0;
		FillColor = 0x0;
		FillStyle = 1;
	}
	int DrawMode;	// - unused!
	int DrawWidth;
	int DrawStyle;
	int FillColor;
	int FillStyle;
};
 extern PictureProperties LastPictureProps;

 void DrawLine(CWnd *wnd, int x1,int y1, int x2,int y2, int rgb=0);
 void DrawLineVB6xy(CWnd &mwnd, double x1,double y1, double x2,double y2, int rgb=0);
 inline void DrawLine(CWnd &wnd, int x1,int y1, int x2,int y2, int rgb=0) { DrawLine(&wnd, x1,y1, x2,y2, rgb); }

 void DrawLineTo(CWnd *wnd, int x,int y, int rgb=0);
 void DrawLineToVB6xy(CWnd &mwnd, double x,double y, int rgb=0);
 inline void DrawLineTo(CWnd &wnd, int x,int y, int rgb=0) { DrawLineTo(&wnd, x,y, rgb); }

 void DrawLineStep(CWnd *wnd, int x1, int y1, int x2, int y2, int rgb=0);
 void DrawLineStepVB6xy(CWnd *wnd, double x1, double y1, double x2, double y2, int rgb=0);
 inline void DrawLineStepVB6xy(CWnd &mwnd, double x1, double y1, double x2, double y2, int rgb=0) { DrawLineStepVB6xy(&mwnd, x1,y1, x2,y2, rgb); }

 void DrawLineToStep(CWnd *wnd, int x, int y, int rgb=0);
 void DrawLineToStepVB6xy(CWnd *wnd, double x, double y, int rgb=0);
 inline void DrawLineToStepVB6xy(CWnd &mwnd, double x, double y, int rgb=0) { DrawLineToStepVB6xy(&mwnd, x,y, rgb); }

 void DrawRectangle(CWnd *wnd, int x1,int y1, int x2,int y2, int rgb=0, CString bf="");
 void DrawRectangleVB6xy(CWnd &mwnd, double x1,double y1, double x2,double y2, int rgb=0, CString bf="");

 void DrawRectangleTo(CWnd *wnd, int x, int y, int rgb=0, CString bf="");
 void DrawRectangleToVB6xy(CWnd *wnd, double x, double y, int rgb=0, CString bf="");
 inline void DrawRectangleToVB6xy(CWnd &mwnd, double x, double y, int rgb=0, CString bf="") { DrawRectangleToVB6xy(&mwnd, x,y, rgb, bf); }

 void DrawRectangleStep(CWnd *wnd, int x1, int y1, int x2, int y2, int rgb=0, CString bf="");
 void DrawRectangleStepVB6xy(CWnd *wnd, double x1, double y1, double x2, double y2, int rgb=0, CString bf="");
 inline void DrawRectangleStepVB6xy(CWnd &mwnd, double x1, double y1, double x2, double y2, int rgb=0, CString bf="") { DrawRectangleStepVB6xy(&mwnd, x1,y1, x2,y2, rgb,bf); }

 void DrawRectangleToStep(CWnd *wnd, int x, int y, int rgb=0, CString bf="");
 void DrawRectangleToStepVB6xy(CWnd *wnd, double x, double y, int rgb=0, CString bf="");
 inline void DrawRectangleToStepVB6xy(CWnd &mwnd, double x, double y, int rgb=0, CString bf="") { DrawRectangleToStepVB6xy(&mwnd, x,y, rgb,bf); }

 void DrawCircle(CWnd *wnd, int xc,int yc, int rc, int rgb=0);
 void DrawArc(CWnd *wnd, int xc,int yc, int rc, double fiStart, double fiEnd, int rgb=0);
 void DrawPoint(CWnd *wnd, int x,int y, int rgb=0);
 inline void DrawCircle(CWnd &wnd, int xc,int yc, int rc, int rgb=0) { DrawCircle(&wnd, xc,yc, rc, rgb); }
 inline void DrawArc(CWnd &wnd, int xc,int yc, int rc, double fiStart, double fiEnd, int rgb=0) { DrawArc(&wnd, xc,yc, rc, fiStart,fiEnd, rgb); }
 inline void DrawPoint(CWnd &wnd, int x,int y, int rgb=0) { DrawPoint(&wnd, x,y, rgb); }

 void DrawCircleVB6xy(CWnd &mwnd, double xc,double yc, double rc, int rgb=0);
 void DrawArcVB6xy(CWnd &mwnd, double xc,double yc, double rc, double fiStart, double fiEnd, int rgb=0);
 void DrawPointVB6xy(CWnd &mwnd, double x,double y, int rgb=0);
 
 void DrawString(CWnd *wnd, const CString &Str, float x, float y);
 void DrawString(CWnd *wnd, const CString &Str);
 char *TranslateCFileDialogFilter(const CString &sFilter);
 int GetRangeMin(CScrollBar &sb);
 int GetRangeMax(CScrollBar &sb);
 void SetRangeMin(CScrollBar &sb, int nMinPos);
 void SetRangeMax(CScrollBar &sb, int nMaxPos);
 int GetRangeMin(CProgressCtrl &pb);
 int GetRangeMax(CProgressCtrl &pb);
 void SetRangeMin(CProgressCtrl &pb, int nMinPos);
 void SetRangeMax(CProgressCtrl &pb, int nMaxPos);
 
 int GetMin(const CSpinButtonCtrl *pCSpinButton);
 int GetMax(const CSpinButtonCtrl *pCSpinButton);
 void SetMin(CSpinButtonCtrl *pCSpinButton, int value);
 void SetMax(CSpinButtonCtrl *pCSpinButton, int value);
 inline int GetMin(const CSpinButtonCtrl &mCSpinButton) { return GetMin(&mCSpinButton); }
 inline int GetMax(const CSpinButtonCtrl &mCSpinButton) { return GetMax(&mCSpinButton); }
 inline void SetMin(CSpinButtonCtrl &mCSpinButton, int value) { SetMin(&mCSpinButton, value); }
 inline void SetMax(CSpinButtonCtrl &mCSpinButton, int value) { SetMax(&mCSpinButton, value); }
 int Int(double d);
 bool Like(const CString &sString, const CString &sPattern);
 
 extern char CommonDialogStrFile[];

 
//=======================================================================
// This is a part of the VBto Converter library (www.vbto.net)
// Copyright (C) 2005-2013 StressSoft Company Ltd. All rights reserved.
//=======================================================================
template <class Type> class CVBtoArrayLine {
public:
	CVBtoArrayLine();
	~CVBtoArrayLine();
	int GetLBound(int dimension) const;
	int GetUBound(int dimension) const;
	inline bool IsEmpty() const { return !pArray; }
protected:
	void ClearLine(int nIndexes, bool flArrayAsPtr);
	void Alloc(const int *pMaxIndexes, int nMaxIndexes, bool flArrayAsPtr);
	void ReAllocData(int nElementsNew, bool flArrayAsPtr, const void *pArraySrc);
	void CopyLineFrom(int nIndexes, const CVBtoArrayLine<Type> *pSrc, bool flArrayAsPtr);
	void ReDimPreserveByLastIndex(int nDim, bool flArrayAsPtr, int lastMaxIndexNew);
	void *&GetPtr1(int Index) const;
	Type *&GetLinePtr(const int *pIndexes, int nIndexes, bool flArrayAsPtr) const;
	Type & GetLineRef(const int *pIndexes, int nIndexes, bool flArrayAsPtr) const;
	const CVBtoArrayLine<Type> *ToLastLine(const int *pIndexes, int nIndexes, int &LastIndex) const;

	int minIndex, nElements;
	void *pArray;
}; //end class CVBtoArrayLine

//----------------------------------------------------------------------------------------
template <class Type> CVBtoArrayLine<Type>::CVBtoArrayLine() {
	minIndex = nElements = 0;
	pArray = NULL;
}
//----------------------------------------------------------------------------------------
template <class Type> CVBtoArrayLine<Type>::~CVBtoArrayLine() {
	assert(!nElements);
	assert(!pArray);
}
//----------------------------------------------------------------------------------------
template <class Type> int CVBtoArrayLine<Type>::GetLBound(int dimension) const {
	assert(dimension>=1);
	if (dimension==1) return minIndex;
	CVBtoArrayLine <Type> **ppVBtoArrayLine = (CVBtoArrayLine <Type> **) pArray;
	CVBtoArrayLine <Type> *pVBtoArrayLine = ppVBtoArrayLine[0];
	return pVBtoArrayLine->GetLBound(dimension-1);
}
//----------------------------------------------------------------------------------------
template <class Type> int CVBtoArrayLine<Type>::GetUBound(int dimension) const {
	assert(dimension>=1);
	if (dimension==1) return minIndex + nElements - 1;
	CVBtoArrayLine <Type> **ppVBtoArrayLine = (CVBtoArrayLine <Type> **) pArray;
	CVBtoArrayLine <Type> *pVBtoArrayLine = ppVBtoArrayLine[0];
	return pVBtoArrayLine->GetUBound(dimension-1);
}

//----------------------------------------------------------------------------------------
template <class Type> void CVBtoArrayLine<Type>::ClearLine(int nIndexes, bool flArrayAsPtr) {
	if (pArray) {
		assert(nIndexes>=1);
		if (nIndexes==1) {
			if (flArrayAsPtr) {
				Type **ppType = (Type **) pArray;
				for(int i=0; i<nElements; i++) {
					Type *pType = ppType[i];
					delete pType;
				}
			}
		} else {
			nIndexes--;
			CVBtoArrayLine <Type> **ppVBtoArrayLine = (CVBtoArrayLine <Type> **) pArray;
			for(int i=0; i<nElements; i++) {
				CVBtoArrayLine <Type> *pVBtoArrayLine = ppVBtoArrayLine[i];
				pVBtoArrayLine->ClearLine(nIndexes, flArrayAsPtr);
				delete pVBtoArrayLine;
			}
		}
		free(pArray);
		pArray = NULL;
	}
	minIndex = nElements = 0;
}
//----------------------------------------------------------------------------------------
template <class Type> void CVBtoArrayLine<Type>::Alloc(const int *pMaxIndexes, int nMaxIndexes, bool flArrayAsPtr) {
	assert(nMaxIndexes>=1);

	int nElementsNew = *pMaxIndexes - minIndex + 1;
	assert(nElementsNew>=1);

	if (nMaxIndexes==1) {
		ReAllocData(nElementsNew, flArrayAsPtr, NULL);
	} else {
		++pMaxIndexes;
		--nMaxIndexes;
		nElements = nElementsNew;
		pArray = realloc(pArray, nElements*sizeof(CVBtoArrayLine <Type> *));
		CVBtoArrayLine <Type> **ppVBtoArrayLine = (CVBtoArrayLine <Type> **) pArray;
		for(int i=0; i<nElements; i++) {
			(ppVBtoArrayLine[i]=new CVBtoArrayLine<Type>)->Alloc(pMaxIndexes, nMaxIndexes, flArrayAsPtr);
		}
	}
}
//----------------------------------------------------------------------------------------
template <class Type> void CVBtoArrayLine<Type>::ReAllocData(int nElementsNew, bool flArrayAsPtr, const void *pArraySrc) {
	if (nElementsNew==nElements) return;

	if (flArrayAsPtr) {
		if (nElementsNew>nElements) {
			pArray = realloc(pArray, nElementsNew*sizeof(Type*));
			Type **ppTypeDst = (Type **) pArray;
			Type **ppTypeSrc = (Type **) pArraySrc;
			for(int i=nElements; i<nElementsNew; i++) {
				Type *pTypeDst = new Type();
				if (ppTypeSrc) {
					Type * pTypeSrc = ppTypeSrc[i];
					if (pTypeSrc)
						*pTypeDst = *pTypeSrc;
				}
				ppTypeDst[i] = pTypeDst;
			}
		} else {
			Type **ppType = (Type **) pArray;
			for(int i=nElementsNew; i<nElements; i++) {
				Type *pType = ppType[i];
				delete pType;
			}
			pArray = realloc(pArray, nElementsNew*sizeof(Type*));
		}
	} else {
		pArray = realloc(pArray, nElementsNew*sizeof(Type));
		if (nElementsNew>nElements) {
			Type *pType = (Type *) pArray;
			int nBytes = (nElementsNew-nElements)*sizeof(Type);
			if (pArraySrc) {
				memcpy(pType+nElements, ((Type*)pArraySrc)+nElements, nBytes);
			} else {
				memset(pType+nElements, 0, nBytes);
			}
		}
	}

	nElements = nElementsNew;
}
//----------------------------------------------------------------------------------------
template <class Type> void CVBtoArrayLine<Type>::CopyLineFrom(int nIndexes, const CVBtoArrayLine<Type> *pSrc, bool flArrayAsPtr) {
	assert(nIndexes>=1);
	if (nIndexes==1) {
		ReAllocData(pSrc->nElements, flArrayAsPtr, pSrc->pArray);
	} else {
		nIndexes--;
		minIndex = pSrc->minIndex;
		nElements = pSrc->nElements;
		pArray = realloc(pArray, nElements*sizeof(CVBtoArrayLine <Type> *));
		CVBtoArrayLine <Type> **ppVBtoArrayLineDst = (CVBtoArrayLine <Type> **) pArray;
		CVBtoArrayLine <Type> **ppVBtoArrayLineSrc = (CVBtoArrayLine <Type> **) pSrc->pArray;
		for(int i=0; i<nElements; i++) {
			(ppVBtoArrayLineDst[i]=new CVBtoArrayLine<Type>)->CopyLineFrom(nIndexes, ppVBtoArrayLineSrc[i], flArrayAsPtr);
		}
	}
}
//----------------------------------------------------------------------------------------
template <class Type> void CVBtoArrayLine<Type>::ReDimPreserveByLastIndex(int nIndexes, bool flArrayAsPtr, int lastMaxIndexNew) {
	assert(nIndexes>=1);
	if (nIndexes==1) {
		int nElementsNew = lastMaxIndexNew - minIndex + 1;
		if (nElementsNew<0) nElementsNew = 0;
		ReAllocData(nElementsNew, flArrayAsPtr, NULL);
	} else {
		nIndexes--;
		CVBtoArrayLine <Type> **ppVBtoArrayLine = (CVBtoArrayLine <Type> **) pArray;
		for(int i=0; i<nElements; i++) {
			CVBtoArrayLine <Type> *pVBtoArrayLine = ppVBtoArrayLine[i];
			assert(pVBtoArrayLine);
			pVBtoArrayLine->ReDimPreserveByLastIndex(nIndexes, flArrayAsPtr, lastMaxIndexNew);
		}
	}
}
//----------------------------------------------------------------------------------------
template <class Type> void *&CVBtoArrayLine<Type>::GetPtr1(int Index) const {
	assert(pArray);
	int curIndex = Index - minIndex;
	assert(curIndex>=0 && curIndex<nElements);
	void **ppVoid = (void **) pArray;
	return ppVoid[curIndex];
}

//----------------------------------------------------------------------------------------
template <class Type> Type *&CVBtoArrayLine<Type>::GetLinePtr(const int *pIndexes, int nIndexes, bool flArrayAsPtr) const {
	assert(nIndexes>=1);
	assert(flArrayAsPtr);
	int LastIndex;
	const CVBtoArrayLine <Type> * pVBtoArrayLine = ToLastLine(pIndexes, nIndexes, LastIndex);
	return (Type *&) pVBtoArrayLine->GetPtr1(LastIndex);
}
//----------------------------------------------------------------------------------------
template <class Type> Type &CVBtoArrayLine<Type>::GetLineRef(const int *pIndexes, int nIndexes, bool flArrayAsPtr) const {
	int LastIndex;
	const CVBtoArrayLine <Type> * pVBtoArrayLine = ToLastLine(pIndexes, nIndexes, LastIndex);
	if (flArrayAsPtr) {
		void **ppVoid = (void **) pVBtoArrayLine->pArray;
		void *pVoid = ppVoid[LastIndex];
		return *((Type *)pVoid);
	} else {
		Type *pType = (Type *) pVBtoArrayLine->pArray;
		return pType[LastIndex];
	}
}

//----------------------------------------------------------------------------------------
template <class Type> const CVBtoArrayLine<Type> *CVBtoArrayLine<Type>::ToLastLine(const int *pIndexes, int nIndexes, int &LastIndex) const {
	assert(nIndexes>=1);
	const CVBtoArrayLine <Type> *pVBtoArrayLine = this;
	while(nIndexes-->1) {
		int Index = *pIndexes++;
		pVBtoArrayLine = (CVBtoArrayLine <Type> *) pVBtoArrayLine->GetPtr1(Index);
		assert(pVBtoArrayLine);
	}
	LastIndex = *pIndexes;
	return pVBtoArrayLine;
}


//=======================================================================
//=======================================================================
template <class Type> class CVBtoArray : public CVBtoArrayLine <Type> {
public:
	CVBtoArray() { Set0(); }
	~CVBtoArray() { Clear(); }

	//void SetDefaultBase(int DefaultBase_) {
	//	DefaultBase = DefaultBase_;
	//}

	CVBtoArray(const CVBtoArray<Type> &obj) {
		if (obj.IsEmpty()) Set0();
		else CopyFrom(obj);
	}

	CVBtoArray<Type>& operator = (const CVBtoArray<Type> &obj) {
		if (this != &obj) CopyFrom(obj);
		return *this;
	}

	void Clear() {
		ClearLine(nDim, flArrayAsPtr);
	}

	void ReDim(int maxIndex1);
	void ReDim(int maxIndex1, int maxIndex2);
	void ReDim(int maxIndex1, int maxIndex2, int maxIndex3);
	void ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4);
	void ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5);
	void ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5, int maxIndex6);
	void ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5, int maxIndex6, int maxIndex7);

	inline void ReDimPreserve(int maxIndex1) {
		assert(nDim==1);
		ReDimPreserveByLastIndex(nDim, flArrayAsPtr, maxIndex1);
	}
	inline void ReDimPreserve(int maxIndex1, int maxIndex2) {
		assert(nDim==2);
		ReDimPreserveByLastIndex(nDim, flArrayAsPtr, maxIndex2);
	}
	inline void ReDimPreserve(int maxIndex1, int maxIndex2, int maxIndex3) {
		assert(nDim==3);
		ReDimPreserveByLastIndex(nDim, flArrayAsPtr, maxIndex3);
	}
	inline void ReDimPreserve(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4) {
		assert(nDim==4);
		ReDimPreserveByLastIndex(nDim, flArrayAsPtr, maxIndex4);
	}
	inline void ReDimPreserve(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5) {
		assert(nDim==5);
		ReDimPreserveByLastIndex(nDim, flArrayAsPtr, maxIndex5);
	}
	inline void ReDimPreserve(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5, int maxIndex6) {
		assert(nDim==6);
		ReDimPreserveByLastIndex(nDim, flArrayAsPtr, maxIndex6);
	}
	inline void ReDimPreserve(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5, int maxIndex6, int maxIndex7) {
		assert(nDim==7);
		ReDimPreserveByLastIndex(nDim, flArrayAsPtr, maxIndex7);
	}

	Type *&GetPtr(int i1) const;
	Type *&GetPtr(int i1, int i2) const;
	Type *&GetPtr(int i1, int i2, int i3) const;
	Type *&GetPtr(int i1, int i2, int i3, int i4) const;
	Type *&GetPtr(int i1, int i2, int i3, int i4, int i5) const;
	Type *&GetPtr(int i1, int i2, int i3, int i4, int i5, int i6) const;
	Type *&GetPtr(int i1, int i2, int i3, int i4, int i5, int i6, int i7) const;

	Type &GetRef(int i1) const;
	Type &GetRef(int i1, int i2) const;
	Type &GetRef(int i1, int i2, int i3) const;
	Type &GetRef(int i1, int i2, int i3, int i4) const;
	Type &GetRef(int i1, int i2, int i3, int i4, int i5) const;
	Type &GetRef(int i1, int i2, int i3, int i4, int i5, int i6) const;
	Type &GetRef(int i1, int i2, int i3, int i4, int i5, int i6, int i7) const;

	inline Type &operator [] (int i1) { return GetRef(i1); }
	inline Type &operator () (int i1) { return GetRef(i1); }
	inline Type &operator () (int i1,int i2) { return GetRef(i1,i2); }
	inline Type &operator () (int i1,int i2,int i3) { return GetRef(i1,i2,i3); }
	inline Type &operator () (int i1,int i2,int i3,int i4) { return GetRef(i1,i2,i3,i4); }
	inline Type &operator () (int i1,int i2,int i3,int i4,int i5) { return GetRef(i1,i2,i3,i4,i5); }
	inline Type &operator () (int i1,int i2,int i3,int i4,int i5,int i6) { return GetRef(i1,i2,i3,i4,i5,i6); }
	inline Type &operator () (int i1,int i2,int i3,int i4,int i5,int i6,int i7) { return GetRef(i1,i2,i3,i4,i5,i6,i7); }

	int LBound(int Dimension=1) const;
	int UBound(int Dimension=1) const;

protected:
	int nDim;
	bool flArrayAsPtr;
	//int DefaultBase;	<-- Option Base 0	or	Option Base 1

	void Set0() {
		nDim = 0;
		flArrayAsPtr = false;
		//DefaultBase = 0;
	}

	void CopyFrom(const CVBtoArray<Type> &obj);

}; //end class CVBtoArray

//----------------------------------------------------------------------------------------
template <class Type> void CVBtoArray<Type>::ReDim(int maxIndex1) {
	Clear();
	Alloc(&maxIndex1, nDim=1, flArrayAsPtr);
}
template <class Type> void CVBtoArray<Type>::ReDim(int maxIndex1, int maxIndex2) {
	Clear();
	int MaxIndexes[] = {maxIndex1,maxIndex2};
	Alloc(MaxIndexes, nDim=2, flArrayAsPtr);
}
template <class Type> void CVBtoArray<Type>::ReDim(int maxIndex1, int maxIndex2, int maxIndex3) {
	Clear();
	int MaxIndexes[] = {maxIndex1,maxIndex2,maxIndex3};
	Alloc(MaxIndexes, nDim=3, flArrayAsPtr);
}
template <class Type> void CVBtoArray<Type>::ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4) {
	Clear();
	int MaxIndexes[] = {maxIndex1,maxIndex2,maxIndex3,maxIndex4};
	Alloc(MaxIndexes, nDim=4, flArrayAsPtr);
}
template <class Type> void CVBtoArray<Type>::ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5) {
	Clear();
	int MaxIndexes[] = {maxIndex1,maxIndex2,maxIndex3,maxIndex4,maxIndex5};
	Alloc(MaxIndexes, nDim=5, flArrayAsPtr);
}
template <class Type> void CVBtoArray<Type>::ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5, int maxIndex6) {
	Clear();
	int MaxIndexes[] = {maxIndex1,maxIndex2,maxIndex3,maxIndex4,maxIndex5,maxIndex6};
	Alloc(MaxIndexes, nDim=6, flArrayAsPtr);
}
template <class Type> void CVBtoArray<Type>::ReDim(int maxIndex1, int maxIndex2, int maxIndex3, int maxIndex4, int maxIndex5, int maxIndex6, int maxIndex7) {
	Clear();
	int MaxIndexes[] = {maxIndex1,maxIndex2,maxIndex3,maxIndex4,maxIndex5,maxIndex6,maxIndex7};
	Alloc(MaxIndexes, nDim=7, flArrayAsPtr);
}

//----------------------------------------------------------------------------------------
template <class Type> Type *&CVBtoArray<Type>::GetPtr(int i1) const {
	assert(nDim==1);
	//int Indexes[] = {i1};
	//return GetLinePtr(Indexes,1,flArrayAsPtr);
	return GetLinePtr(&i1,1,flArrayAsPtr);
}
template <class Type> Type *&CVBtoArray<Type>::GetPtr(int i1, int i2) const {
	assert(nDim==2);
	int Indexes[] = {i1,i2};
	return GetLinePtr(Indexes,2,flArrayAsPtr);
}
template <class Type> Type *&CVBtoArray<Type>::GetPtr(int i1, int i2, int i3) const {
	assert(nDim==3);
	int Indexes[] = {i1,i2,i3};
	return GetLinePtr(Indexes,3,flArrayAsPtr);
}
template <class Type> Type *&CVBtoArray<Type>::GetPtr(int i1, int i2, int i3, int i4) const {
	assert(nDim==4);
	int Indexes[] = {i1,i2,i3,i4};
	return GetLinePtr(Indexes,4,flArrayAsPtr);
}
template <class Type> Type *&CVBtoArray<Type>::GetPtr(int i1, int i2, int i3, int i4, int i5) const {
	assert(nDim==5);
	int Indexes[] = {i1,i2,i3,i4,i5};
	return GetLinePtr(Indexes,5,flArrayAsPtr);
}
template <class Type> Type *&CVBtoArray<Type>::GetPtr(int i1, int i2, int i3, int i4, int i5, int i6) const {
	assert(nDim==6);
	int Indexes[] = {i1,i2,i3,i4,i5,i6};
	return GetLinePtr(Indexes,6,flArrayAsPtr);
}
template <class Type> Type *&CVBtoArray<Type>::GetPtr(int i1, int i2, int i3, int i4, int i5, int i6, int i7) const {
	assert(nDim==7);
	int Indexes[] = {i1,i2,i3,i4,i5,i6,i7};
	return GetLinePtr(Indexes,7,flArrayAsPtr);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
template <class Type> Type &CVBtoArray<Type>::GetRef(int i1) const {
	assert(nDim==1);
	//int Indexes[] = {i1};
	//return GetLineRef(Indexes,1,flArrayAsPtr);
	return GetLineRef(&i1,1,flArrayAsPtr);
}
template <class Type> Type &CVBtoArray<Type>::GetRef(int i1, int i2) const {
	assert(nDim==2);
	int Indexes[] = {i1,i2};
	return GetLineRef(Indexes,2,flArrayAsPtr);
}
template <class Type> Type &CVBtoArray<Type>::GetRef(int i1, int i2, int i3) const {
	assert(nDim==3);
	int Indexes[] = {i1,i2,i3};
	return GetLineRef(Indexes,3,flArrayAsPtr);
}
template <class Type> Type &CVBtoArray<Type>::GetRef(int i1, int i2, int i3, int i4) const {
	assert(nDim==4);
	int Indexes[] = {i1,i2,i3,i4};
	return GetLineRef(Indexes,4,flArrayAsPtr);
}
template <class Type> Type &CVBtoArray<Type>::GetRef(int i1, int i2, int i3, int i4, int i5) const {
	assert(nDim==5);
	int Indexes[] = {i1,i2,i3,i4,i5};
	return GetLineRef(Indexes,5,flArrayAsPtr);
}
template <class Type> Type &CVBtoArray<Type>::GetRef(int i1, int i2, int i3, int i4, int i5, int i6) const {
	assert(nDim==6);
	int Indexes[] = {i1,i2,i3,i4,i5,i6};
	return GetLineRef(Indexes,6,flArrayAsPtr);
}
template <class Type> Type &CVBtoArray<Type>::GetRef(int i1, int i2, int i3, int i4, int i5, int i6, int i7) const {
	assert(nDim==7);
	int Indexes[] = {i1,i2,i3,i4,i5,i6,i7};
	return GetLineRef(Indexes,7,flArrayAsPtr);
}

//----------------------------------------------------------------------------------------
template <class Type> int CVBtoArray<Type>::LBound(int dimension) const {
	assert((dimension>0 && dimension<=nDim) || nDim==0);
	int lb = GetLBound(dimension);
	return lb;
}
//----------------------------------------------------------------------------------------
template <class Type> int CVBtoArray<Type>::UBound(int dimension) const {
	assert((dimension>0 && dimension<=nDim) || nDim==0);
	int ub = GetUBound(dimension);
	return ub;
}

//----------------------------------------------------------------------------------------
template <class Type> void CVBtoArray<Type>::CopyFrom(const CVBtoArray<Type> &obj) {
	Clear();
	nDim = obj.nDim;
	flArrayAsPtr = obj.flArrayAsPtr;
	CopyLineFrom(nDim, &obj, flArrayAsPtr);
}

//=======================================================================
//=======================================================================
template <class Type> class CVBtoArrayPtr : public CVBtoArray <Type> {
public:
	CVBtoArrayPtr() {
		flArrayAsPtr = true;
		//flAutoAlloc = true;
		//flAutoDelete =true;
	}

	//bool flAutoAlloc;
	//bool flAutoDelete;

	//inline Type *&operator [] (int i1) { return GetPtr(i1); }
	//inline Type *&operator () (int i1) { return GetPtr(i1); }
	//inline Type *&operator () (int i1,int i2) { return GetPtr(i1,i2); }
	//inline Type *&operator () (int i1,int i2,int i3) { return GetPtr(i1,i2,i3); }
	//inline Type *&operator () (int i1,int i2,int i3,int i4) { return GetPtr(i1,i2,i3,i4); }
	//inline Type *&operator () (int i1,int i2,int i3,int i4,int i5) { return GetPtr(i1,i2,i3,i4,i5); }
	//inline Type *&operator () (int i1,int i2,int i3,int i4,int i5,int i6) { return GetPtr(i1,i2,i3,i4,i5,i6); }
	//inline Type *&operator () (int i1,int i2,int i3,int i4,int i5,int i6,int i7) { return GetPtr(i1,i2,i3,i4,i5,i6,i7); }

}; //end class CVBtoArrayPtr

//----------------------------------------------------------------------------------------
//inline int LBound(const CVBtoArray <Type> &pVBtoArray, int dimension=1) { return pVBtoArray. LBound(dimension); }
//inline int UBound(const CVBtoArray <Type> &pVBtoArray, int dimension=1) { return pVBtoArray. UBound(dimension); }
//inline int LBound(const CVBtoArray <Type> *pVBtoArray, int dimension=1) { return pVBtoArray->LBound(dimension); }
//inline int UBound(const CVBtoArray <Type> *pVBtoArray, int dimension=1) { return pVBtoArray->UBound(dimension); }

 
//----------------------------------------------------------------------------------------
template <class T> void VBSetNew(T *&pDest, T *pNew) {
	delete pDest;
	pDest = pNew;
}
template <class T> void VBSet(T *&pDest, const T *pSrc) {
	delete pDest;
	// pDest = pSrc;	// <-- VB6 Correct !
	pDest = new T();	// <-- C++ Correct !!
	*pDest = *pSrc;
}
template <class T> void VBSet(T *&pDest, const T &mSrc) { VBSet(pDest, &mSrc); }

 

//===============================================================
class VBtoListViewItem {
public:
	VBtoListViewItem() {
		pListCtrl = NULL;
		ItemIndex = -1;
	}

	CString GetText() {
		return pListCtrl->GetItemText(ItemIndex,0);
	}
	void SetText(const CString &text) {
		pListCtrl->SetItemText(ItemIndex, 0, text);
	}

	CString GetSubItemText(int index) {
		return pListCtrl->GetItemText(ItemIndex,index);
	}
	void SetSubItemText(int index, const CString &text) {
		pListCtrl->SetItemText(ItemIndex, index, text);
	}

	BOOL GetCheck() {
		return pListCtrl->GetCheck(ItemIndex);
	}
	void SetCheck(BOOL fCheck=TRUE) {
		pListCtrl->SetCheck(ItemIndex, fCheck);
	}

	BOOL GetSelected() {
		return pListCtrl->GetItemState(ItemIndex, LVIS_SELECTED);
	}
	void SetSelected(BOOL flSelected) {
		pListCtrl->SetItemState(ItemIndex, flSelected ? LVIS_SELECTED|LVIS_FOCUSED : 0, LVIS_SELECTED|LVIS_FOCUSED);
	}

	void SetSelectedItem(CListCtrl *pListCtrl_) {
		pListCtrl = pListCtrl_;
		SetSelected(true);
	}
	void SetSelectedItem(CListCtrl &mListCtrl_) {
		SetSelectedItem(&mListCtrl_);
	}

	int GetIndex() { return ItemIndex+1; }

	void EnsureVisible() {
		pListCtrl->EnsureVisible(ItemIndex, false);
	}

	BOOL IsNothing() const {
		return !pListCtrl || ItemIndex<0;
	}
	BOOL operator == (int indItem) {
		if (!indItem) return IsNothing();
		return pListCtrl && ItemIndex == indItem;
	}

	CListCtrl *pListCtrl;
	int ItemIndex;	// The zero-based index of a list control item
};
 VBtoListViewItem GetVBtoListViewItem(CListCtrl &mListCtrl, int ItemIndex);
 VBtoListViewItem GetVBtoSelectedItem(CListCtrl &mListCtrl);
 
//===============================================================
 void SetItemData(CTreeCtrl &mTrV, HTREEITEM hItem, const CComVariant &ccv);
 void SetItemData(CTreeCtrl &mTrV, HTREEITEM hItem, const char *pBuf);
 CString GetItemDataAsString(const CTreeCtrl &mTrV, HTREEITEM hItem);
 CString GetFullPath(const CTreeCtrl &mTrV, HTREEITEM hItem);
 int GetChildren(const CTreeCtrl &mTrV, HTREEITEM hItem, BOOL flAll=false);
 HTREEITEM FindItemByKey(const CTreeCtrl &mTrV, HTREEITEM FirstNode, const CString &Key);
 HTREEITEM GetItem(CTreeCtrl &mTrV, int ind);

//===============================================================
 const int _tvwFirst	= 0;
 const int _tvwLast	= 1;
 const int _tvwNext	= 2;
 const int _tvwPrevious	= 3;
 const int _tvwChild	= 4;

class VBtoTreeItem {
public:

	VBtoTreeItem() {
		pTrV  = NULL;
		hItem = 0;
	}
	VBtoTreeItem(CTreeCtrl &mTrV, HTREEITEM hItem_) {
		pTrV  = &mTrV;
		hItem = hItem_;
	}
	VBtoTreeItem(CTreeCtrl &mTrV, int ind) {
		pTrV  = &mTrV;
		hItem = GetItem(mTrV,ind);
	}

	BOOL operator == (int iHandle) {
		return ((int)hItem)==iHandle;
	}
	BOOL IsNothing() const {
		return !pTrV || !hItem;
	}

	void operator = (int iNULL) {
		if (!iNULL) {
			pTrV  = NULL;
			hItem = 0;
		}
	}

	CString GetText() const {
		return pTrV->GetItemText(hItem);
	}
	void SetText(const CString &s) {
		pTrV->SetItemText(hItem, s);
	}

	CString GetKey() const {
		return GetItemDataAsString(*pTrV, hItem);
	}
	void SetKey(const CString &s) {
		SetItemData(*pTrV, hItem, s);
	}

	bool GetSelected() const {
		HTREEITEM hi = pTrV->GetSelectedItem();
		return hi && hi==hItem;
	}
	void SetSelected(bool b) {
		pTrV->SelectItem(b ? hItem : NULL);
	}

	bool GetChecked() const {
		return pTrV->GetCheck(hItem) ? true : false;
	}
	void SetChecked(bool b) {
		pTrV->SetCheck(hItem, b);
	}

	bool GetExpanded() const {
		return pTrV->GetItemState(hItem,TVIS_EXPANDED)==TVIS_EXPANDED;
	}
	void SetExpanded(bool b) {
		pTrV->SetItemState(hItem, b?TVIS_EXPANDED:0, TVIS_EXPANDED);
	}

	bool GetBold() const {
		return pTrV->GetItemState(hItem,TVIS_BOLD)==TVIS_BOLD;
	}
	void SetBold(bool b) {
		pTrV->SetItemState(hItem, b?TVIS_BOLD:0, TVIS_BOLD);
	}

	CString GetFullPath() const {
		return ::GetFullPath(*pTrV, hItem);
	}

	void EnsureVisible() {
		pTrV->EnsureVisible(hItem);
	}

	int GetChildren(BOOL flAll=false) const {
		return ::GetChildren(*pTrV, hItem, flAll);
	}

	int GetIndex() const;

//protected:
	CTreeCtrl *pTrV;
	HTREEITEM hItem;
};

 VBtoTreeItem InsertItem(CTreeCtrl &mTrV, VBtoTreeItem RelativeNode, int Relationship, CString Key="", CString Text="", int imageIndex=-1, int selImageIndex=-1);
 VBtoTreeItem InsertItem(CTreeCtrl &mTrV, CString RelativeKey, int Relationship, CString Key="", CString Text="", int imageIndex=-1, int selImageIndex=-1);
 VBtoTreeItem InsertItem(CTreeCtrl &mTrV, CString Key, CString Text, int imageIndex=-1, int selImageIndex=-1);
 
 inline void vModifyStyle(CWnd *pWnd, bool bAdd, DWORD Flags) { pWnd->ModifyStyle(bAdd?0:Flags, bAdd?Flags:0); }
 inline void vModifyStyle(CWnd &mWnd, bool bAdd, DWORD Flags) { vModifyStyle(&mWnd, bAdd, Flags); }
 inline long GetStyleFlags(CWnd *pWnd, DWORD Flags) { return GetWindowLong(pWnd->m_hWnd,GWL_STYLE) & Flags; }
 inline long GetStyleFlags(CWnd &mWnd, DWORD Flags) { return GetStyleFlags(&mWnd, Flags); }
 
 CString GetItemText(CTabCtrl *pTabCtrl, int ind);
 CString GetSelectedItemText(CTabCtrl *pTabCtrl);
 void SetItemText(CTabCtrl *pTabCtrl, int ind, CString text);
 void SetSelectedItemText(CTabCtrl *pTabCtrl, CString text);
 CComVariant GetItemParam(CTabCtrl *pTabCtrl, int ind);
 void SetItemParam(CTabCtrl *pTabCtrl, int ind, CComVariant *pccv);
 CComVariant GetSelectedItemParam(CTabCtrl *pTabCtrl);
 void SetSelectedItemParam(CTabCtrl *pTabCtrl, CComVariant *pccv);
 inline CString GetItemText(CTabCtrl &mTabCtrl, int ind) { return GetItemText(&mTabCtrl, ind); }
 inline CString GetSelectedItemText(CTabCtrl &mTabCtrl) { return GetSelectedItemText(&mTabCtrl); }
 inline void SetItemText(CTabCtrl &mTabCtrl, int ind, CString text) { SetItemText(&mTabCtrl, ind, text); }
 inline void SetSelectedItemText(CTabCtrl &mTabCtrl, CString text) { SetSelectedItemText(&mTabCtrl, text); }
 inline CComVariant GetItemParam(CTabCtrl &mTabCtrl, int ind) { return GetItemParam(&mTabCtrl, ind); }
 inline CComVariant GetSelectedItemParam(CTabCtrl &mTabCtrl) { return GetSelectedItemParam(&mTabCtrl); }
 inline void SetItemParam(CTabCtrl &mTabCtrl, int ind, CComVariant *pccv) { SetItemParam(&mTabCtrl, ind, pccv); }
 inline void SetSelectedItemParam(CTabCtrl &mTabCtrl, CComVariant *pccv) { SetSelectedItemParam(&mTabCtrl, pccv); }
 
//---------------------------------------------------------------
 #define VBtoConverter_Property(propType,propName)	\
	class Property_##propName {	\
		public:	\
		void operator = (propType value) { Set##propName(value); }	\
		propType operator () () { return Get##propName(); }	\
	};	\
	extern Property_##propName propName;

 #define VBtoConverter_PropertyReadOnly(propType,propName)	\
	class Property_##propName {	\
		public:	\
		propType operator () () { return Get##propName(); }	\
	};	\
	extern Property_##propName propName;

 #define VBtoConverter_PropertyWriteOnly(propType,propName)	\
	class Property_##propName {	\
		public:	\
		void operator = (propType value) { Set##propName(value); }	\
	};	\
	extern Property_##propName propName;
 
//---------------------------------------------------------------
#define VBtoConverter_ClassPropertyAsString(propType,propName,classParent)	\
	class Property_##propName {	\
		public:	\
		void SetParentClass(classParent *p) { mParent = p; }	\
		operator propType () { return mParent->Get##propName(); }	\
		propType operator () () { return mParent->Get##propName(); }	\
		void operator = (propType value) { mParent->Set##propName(value); }	\
		void operator += (propType value) {	\
			propType tmp = mParent->Get##propName();	\
			mParent->Set##propName(tmp+value);	\
		}	\
		classParent *mParent;	\
	} propName;	\
	friend Property_##propName;
 
//---------------------------------------------------------------
#define VBtoConverter_ClassProperty(propType,propName,classParent)	\
	class Property_##propName {	\
		public:	\
		void SetParentClass(classParent *p) { mParent = p; }	\
		operator propType () { return mParent->Get##propName(); }	\
		propType operator () () { return mParent->Get##propName(); }	\
		void operator = (propType value) { mParent->Set##propName(value); }	\
		classParent *mParent;	\
	} propName;	\
	friend Property_##propName;

//---------------------------------------------------------------
#define VBtoConverter_ClassPropertyReadOnly(propType,propName,classParent)	\
	class Property_##propName {	\
		public:	\
		propType operator () () { return mParent->Get##propName(); }	\
		classParent *mParent;	\
	} propName;	\
	friend Property_##propName;

//---------------------------------------------------------------
#define VBtoConverter_ClassPropertyWriteOnly(propType,propName,classParent)	\
	class Property_##propName {	\
		public:	\
		void operator = (propType value) { mParent->Set##propName(value); }	\
		classParent *mParent;	\
	} propName;	\
	friend Property_##propName;
 CString InputBox(const CString &Prompt, const CString &Title="", const CString &Default="", int XPos=-1, int YPos=-1);
 CString vbGetCommandLine();
 
//===============================================================================
// CPrinterInfo - This class wraps all of the PRINTER_INFO_* structures and provided by ::GetPrinter.
template <unsigned int t_nInfo>
class _printer_info
{
public:
    typedef void infotype;
};

template <> class _printer_info<1> { public: typedef PRINTER_INFO_1 infotype; };
template <> class _printer_info<2> { public: typedef PRINTER_INFO_2 infotype; };
template <> class _printer_info<3> { public: typedef PRINTER_INFO_3 infotype; };
template <> class _printer_info<4> { public: typedef PRINTER_INFO_4 infotype; };
template <> class _printer_info<5> { public: typedef PRINTER_INFO_5 infotype; };
template <> class _printer_info<6> { public: typedef PRINTER_INFO_6 infotype; };
template <> class _printer_info<7> { public: typedef PRINTER_INFO_7 infotype; };

//===============================================================================
template <unsigned int t_nInfo>
class CPrinterInfo
{
public:
// Data members
    typename _printer_info<t_nInfo>::infotype* m_pi;

    CPrinterInfo() : m_pi(NULL)
    { }

    CPrinterInfo(HANDLE hPrinter) : m_pi(NULL)
    {
        GetPrinterInfo(hPrinter);
    }

    ~CPrinterInfo()
    {
        Cleanup();
    }

// Operations
    bool GetPrinterInfo(HANDLE hPrinter)
    {
        Cleanup();
        return GetPrinterInfoHelper(hPrinter, (BYTE**)&m_pi, t_nInfo);
    }

// Implementation
    void Cleanup()
    {
        delete [] (BYTE*)m_pi;
        m_pi = NULL;
    }

    static bool GetPrinterInfoHelper(HANDLE hPrinter, BYTE** pi, int nIndex)
    {
        DWORD dw = 0;
        BYTE* pb = NULL;
        ::GetPrinter(hPrinter, nIndex, NULL, 0, &dw);
        if (dw > 0)
        {
            pb = new BYTE[dw];
            if (pb != NULL)
            {
                memset(pb, 0, dw);
                DWORD dwNew;
                if (!::GetPrinter(hPrinter, nIndex, pb, dw, &dwNew))
                {
                    delete [] pb;
                    pb = NULL;
                }
            }
        }
        *pi = pb;
        return (pb != NULL);
    }
};

//===============================================================================
// CPrinter - Wrapper class for a HANDLE to a printer
template <bool t_bManaged>
class CPrinterT
{
public:
    HANDLE m_hPrinter;

    CPrinterT(HANDLE hPrinter = NULL) : m_hPrinter(hPrinter)
    { }

    ~CPrinterT()
    {
        ClosePrinter();
    }

    CPrinterT& operator =(HANDLE hPrinter)
    {
        if (hPrinter != m_hPrinter)
        {
            ClosePrinter();
            m_hPrinter = hPrinter;
        }
        return *this;
    }

    bool IsNull() const { return (m_hPrinter == NULL); }

    bool OpenPrinter(HANDLE hDevNames, const DEVMODE* pDevMode = NULL)
    {
        bool b = false;
        DEVNAMES* pdn = (DEVNAMES*)::GlobalLock(hDevNames);
        if (pdn != NULL)
        {
            LPTSTR lpszPrinterName = (LPTSTR)pdn + pdn->wDeviceOffset;
            b = OpenPrinter(lpszPrinterName, pDevMode);
            ::GlobalUnlock(hDevNames);
        }
        return b;
    }

    bool OpenPrinter(LPCTSTR lpszPrinterName, const DEVMODE* pDevMode = NULL)
    {
        ClosePrinter();
        PRINTER_DEFAULTS pdefs = { NULL, (DEVMODE*)pDevMode, PRINTER_ACCESS_USE };
        ::OpenPrinter((LPTSTR) lpszPrinterName, &m_hPrinter, (pDevMode == NULL) ? NULL : &pdefs);

        return (m_hPrinter != NULL);
    }

    bool OpenPrinter(LPCTSTR lpszPrinterName, PRINTER_DEFAULTS* pprintdefs)
    {
        ClosePrinter();
        ::OpenPrinter((LPTSTR) lpszPrinterName, &m_hPrinter, pprintdefs);
        return (m_hPrinter != NULL);
    }

    bool OpenDefaultPrinter(const DEVMODE* pDevMode = NULL)
    {
        ClosePrinter();
        const int cchBuff = 512;
        TCHAR buffer[cchBuff];
        buffer[0] = 0;
        ::GetProfileString(_T("windows"), _T("device"), _T(",,,"), buffer, cchBuff);
        int nLen = lstrlen(buffer);
        if (nLen != 0)
        {
            LPTSTR lpsz = buffer;
            while (*lpsz)
            {
                if (*lpsz == _T(','))
                {
                    *lpsz = 0;
                    break;
                }
                lpsz = CharNext(lpsz);
            }
            PRINTER_DEFAULTS pdefs = { NULL, (DEVMODE*)pDevMode, PRINTER_ACCESS_USE };
            ::OpenPrinter(buffer, &m_hPrinter, (pDevMode == NULL) ? NULL : &pdefs);
        }
        return m_hPrinter != NULL;
    }

    void ClosePrinter()
    {
        if (m_hPrinter != NULL)
        {
            if (t_bManaged)
                ::ClosePrinter(m_hPrinter);
            m_hPrinter = NULL;
        }
    }

    bool PrinterProperties(HWND hWnd = NULL)
    {
        if (hWnd == NULL)
            hWnd = ::GetActiveWindow();
        return !!::PrinterProperties(hWnd, m_hPrinter);
    }

    HANDLE CopyToHDEVNAMES() const
    {
        HANDLE h = NULL;
        CPrinterInfo<5> pinfon5;
        CPrinterInfo<2> pinfon2;
        LPTSTR lpszPrinterName = NULL;
        // Some printers fail for PRINTER_INFO_5 in some situations
        if (pinfon5.GetPrinterInfo(m_hPrinter))
            lpszPrinterName = pinfon5.m_pi->pPrinterName;
        else if (pinfon2.GetPrinterInfo(m_hPrinter))
            lpszPrinterName = pinfon2.m_pi->pPrinterName;
        if (lpszPrinterName != NULL)
        {
            int nLen = sizeof(DEVNAMES) + (lstrlen(lpszPrinterName) + 1) * sizeof(TCHAR);
            h = ::GlobalAlloc(GMEM_MOVEABLE, nLen);	
            BYTE* pv = (BYTE*)::GlobalLock(h);
            DEVNAMES* pdev = (DEVNAMES*)pv;
            if (pv != NULL)
            {
                memset(pv, 0, nLen);
                pdev->wDeviceOffset = sizeof(DEVNAMES) / sizeof(TCHAR);
				pv = pv + sizeof(DEVNAMES); // now points to end
				//v strcpy_s((char*)pv, lstrlen(lpszPrinterName) + 1, (const char*)lpszPrinterName);
				strcpy((char*)pv, (const char*)lpszPrinterName);
                ::GlobalUnlock(h);
            }
        }
        return h;
    }

    HDC CreatePrinterDC(const DEVMODE* pdm = NULL) const
    {
        CPrinterInfo<5> pinfo5;
        CPrinterInfo<2> pinfo2;
        HDC hDC = NULL;
        LPTSTR lpszPrinterName = NULL;
        // Some printers fail for PRINTER_INFO_5 in some situations
        if (pinfo5.GetPrinterInfo(m_hPrinter))
            lpszPrinterName = pinfo5.m_pi->pPrinterName;
        else if (pinfo2.GetPrinterInfo(m_hPrinter))
            lpszPrinterName = pinfo2.m_pi->pPrinterName;
        if (lpszPrinterName != NULL)
            hDC = ::CreateDC(NULL, lpszPrinterName, NULL, pdm);
        return hDC;
    }

    HDC CreatePrinterIC(const DEVMODE* pdm = NULL) const
    {
        CPrinterInfo<5> pinfo5;
        CPrinterInfo<2> pinfo2;
        HDC hDC = NULL;
        LPTSTR lpszPrinterName = NULL;
        // Some printers fail for PRINTER_INFO_5 in some situations
        if (pinfo5.GetPrinterInfo(m_hPrinter))
            lpszPrinterName = pinfo5.m_pi->pPrinterName;
        else if (pinfo2.GetPrinterInfo(m_hPrinter))
            lpszPrinterName = pinfo2.m_pi->pPrinterName;
        if (lpszPrinterName != NULL)
            hDC = ::CreateIC(NULL, lpszPrinterName, NULL, pdm);
        return hDC;
    }

    void Attach(HANDLE hPrinter)
    {
        ClosePrinter();
        m_hPrinter = hPrinter;
    }

    HANDLE Detach()
    {
        HANDLE hPrinter = m_hPrinter;
        m_hPrinter = NULL;
        return hPrinter;
    }

    operator HANDLE() const { return m_hPrinter; }
};

typedef CPrinterT<false>   CPrinterHandle;
typedef CPrinterT<true>    CPrinter;


//===============================================================================
// CDevMode - Wrapper class for DEVMODE
template <bool t_bManaged>
class CDevModeT
{
public:
// Data members
    HANDLE m_hDevMode;
    DEVMODE* m_pDevMode;

// Constructor/destructor
    CDevModeT(HANDLE hDevMode = NULL) : m_hDevMode(hDevMode)
    {
        m_pDevMode = (m_hDevMode != NULL) ? (DEVMODE*)::GlobalLock(m_hDevMode) : NULL;
    }

    ~CDevModeT()
    {
        Cleanup();
    }

// Operations
    CDevModeT<t_bManaged>& operator =(HANDLE hDevMode)
    {
        Attach(hDevMode);
        return *this;
    }

    void Attach(HANDLE hDevModeNew)
    {
        Cleanup();
        m_hDevMode = hDevModeNew;
        m_pDevMode = (m_hDevMode != NULL) ? (DEVMODE*)::GlobalLock(m_hDevMode) : NULL;
    }

    HANDLE Detach()
    {
	if (m_hDevMode != NULL)
		::GlobalUnlock(m_hDevMode);
        HANDLE hDevMode = m_hDevMode;
        m_hDevMode = NULL;
        return hDevMode;
    }

    bool IsNull() const { return (m_hDevMode == NULL); }

    bool CopyFromPrinter(HANDLE hPrinter)
    {
        CPrinterInfo<2> pinfo;
        bool b = pinfo.GetPrinterInfo(hPrinter);
	if (b)
		b = CopyFromDEVMODE(pinfo.m_pi->pDevMode);
        return b;
    }

    bool CopyFromDEVMODE(const DEVMODE* pdm)
    {
        if (pdm == NULL)
            return false;
        int nSize = pdm->dmSize + pdm->dmDriverExtra;
        HANDLE h = ::GlobalAlloc(GMEM_MOVEABLE, nSize);
        if (h != NULL)
        {
            void* p = ::GlobalLock(h);
            memcpy(p, pdm, nSize);
            ::GlobalUnlock(h);
        }
        Attach(h);
        return (h != NULL);
    }

    bool CopyFromHDEVMODE(HANDLE hdm)
    {
        bool b = false;
        if (hdm != NULL)
        {
            DEVMODE* pdm = (DEVMODE*)::GlobalLock(hdm);
            b = CopyFromDEVMODE(pdm);
            ::GlobalUnlock(hdm);
        }
        return b;
    }

    HANDLE CopyToHDEVMODE()
    {
        if ((m_hDevMode == NULL) || (m_pDevMode == NULL))
            return NULL;
        int nSize = m_pDevMode->dmSize + m_pDevMode->dmDriverExtra;
        HANDLE h = ::GlobalAlloc(GMEM_MOVEABLE, nSize);
        if (h != NULL)
        {
            void* p = ::GlobalLock(h);
            memcpy(p, m_pDevMode, nSize);
            ::GlobalUnlock(h);
        }
        return h;
    }

    // If this devmode was for another printer, this will create a new devmode
    // based on the existing devmode, but retargeted at the new printer
    bool UpdateForNewPrinter(HANDLE hPrinter)
    {
        bool bRet = false;
        LONG nLen = ::DocumentProperties(NULL, hPrinter, NULL, NULL, NULL, 0);
        CTempBuffer<DEVMODE, _WTL_STACK_ALLOC_THRESHOLD> buff;
        DEVMODE* pdm = buff.AllocateBytes(nLen);
        if(pdm != NULL)
        {
            memset(pdm, 0, nLen);
            LONG l = ::DocumentProperties(NULL, hPrinter, NULL, pdm, m_pDevMode, DM_IN_BUFFER | DM_OUT_BUFFER);
            if (l == IDOK)
                bRet = CopyFromDEVMODE(pdm);
        }

        return bRet;
    }

    bool DocumentProperties(HANDLE hPrinter, HWND hWnd = NULL)
    {
        CPrinterInfo<1> pi;
        pi.GetPrinterInfo(hPrinter);
        if (hWnd == NULL)
            hWnd = ::GetActiveWindow();

        bool bRet = false;
        LONG nLen = ::DocumentProperties(hWnd, hPrinter, pi.m_pi->pName, NULL, NULL, 0);
        CTempBuffer<DEVMODE, _WTL_STACK_ALLOC_THRESHOLD> buff;
        DEVMODE* pdm = buff.AllocateBytes(nLen);
        if(pdm != NULL)
        {
            memset(pdm, 0, nLen);
            LONG l = ::DocumentProperties(hWnd, hPrinter, pi.m_pi->pName, pdm, m_pDevMode, DM_IN_BUFFER | DM_OUT_BUFFER | DM_PROMPT);
            if (l == IDOK)
                bRet = CopyFromDEVMODE(pdm);
        }

        return bRet;
    }

    operator HANDLE() const { return m_hDevMode; }
    operator DEVMODE*() const { return m_pDevMode; }

	void Cleanup() 
	{
		if (m_hDevMode != NULL)
		{
			::GlobalUnlock(m_hDevMode);
			if (t_bManaged)
				::GlobalFree(m_hDevMode);
			m_hDevMode = NULL;
		}
	}
};

//===============================================================================
typedef CDevModeT<false>   CDevModeHandle;
typedef CDevModeT<true>    CDevMode;

//===============================================================================
class CPrinterDC : public CDC
{
public:
    CPrinterDC() {
        CPrinter printer;
        printer.OpenDefaultPrinter();
        Attach(printer.CreatePrinterDC());
    }

    CPrinterDC(HANDLE hPrinter, const DEVMODE* pdm = NULL) {
        CPrinterHandle p;
        p.Attach(hPrinter);
        Attach(p.CreatePrinterDC(pdm));
    }

    ~CPrinterDC() {
        DeleteDC();
    }
};

//===============================================================================
class CVBtoPrinter
{
public:
	CVBtoPrinter();
	~CVBtoPrinter() {}

	void SetJobName(CString str) { m_sJobName = str; }
	CDC* GetCDC() { return &dcPrinter; }

	void OnPageSetup();
	bool StartDoc(bool bDisplayPrintDialog = true);
	void NewPage();
	void EndDoc(bool bCancel = false);

	int GetPageNumber() { return PageNumber; }

	CString GetFontName();
	void SetFontName(const CString &value);
	float GetFontSize();
	void SetFontSize(float value);
	bool GetFontBold();
	void SetFontBold(bool value);
	bool GetFontItalic();
	void SetFontItalic(bool value);

	float GetCurrentX();
	float GetCurrentY();
	void SetCurrentX(float value);
	void SetCurrentY(float value);

	void Print(const CString &S="");
	void PSet(double x, double y, int rgbCol=0);
	void Line(double x1, double y1, double x2, double y2, int rgbCol=0);
	void LineTo(double x2, double y2, int rgbCol=0);
	void Rectangle(double x1, double y1, double x2, double y2, int rgbCol=0);
	void Circle(double xC, double yC, double R, int rgbCol=0);
	void Arc(double xC, double yC, double R, double fiStart, double fiEnd, int rgbCol=0);

	int DrawWidth, DrawStyle, FillStyle;
	int FillColor;

protected:
	bool IsStartDoc;
	double kX, kY;
	int PageNumber;

	LOGFONT logFont;
	CFont *pDefaultFont;

	void UpdateFont();
	CPoint VB6toAPI(double vx, double vy);

protected:
	CPrinter m_printer;
	CDevMode m_devmode;
	CString m_sJobName;
	DOCINFO m_docinfo;
	CDC dcPrinter;
	bool m_bPrinting;

	int m_nPJState;
	int m_nJobID;

	CRect m_rcMargin;
};

extern CVBtoPrinter VBtoPrinter;

 
//====================================================
// This is a part of the VBto Converter (www.vbto.net)
// Copyright (C) 2005-2013 StressSoft Company Ltd. All rights reserved.
//====================================================
class VBtoFontAttribute {
public:

	VBtoFontAttribute();
	~VBtoFontAttribute();

	void Set(CWnd* pWnd_, 
		int rgbForeColor_ = RGB(0,0,0),
		int rgbBackColor_ = RGB(255,255,255),
		const char *pFaceName = NULL,
		float PointSize	= 0,
		bool flBold	= false,
		bool flItalic	= false,
		bool flStrikeOut= false,
		bool flUnderline= false,
		BYTE lfCharSet  = DEFAULT_CHARSET);

	inline int GetForeColor() const { return rgbForeColor; }
	inline int GetBackColor() const { return rgbBackColor; }
	void SetForeColor(int rgbForeColor_);
	void SetBackColor(int rgbBackColor_);

	CString GetFontName		() const;
	double GetFontSize		() const;
	short GetFontWeight		() const { return pLogFont ? (short)pLogFont->lfWeight : 0; }
	byte GetFontCharset		() const { return pLogFont ? pLogFont->lfCharSet : 0; }
	bool GetFontBold		() const { return pLogFont && pLogFont->lfWeight >= FW_SEMIBOLD; }
	bool GetFontItalic		() const { return pLogFont && pLogFont->lfItalic; }
	bool GetFontStrikeOut	() const { return pLogFont && pLogFont->lfStrikeOut; }
	bool GetFontUnderline	() const { return pLogFont && pLogFont->lfUnderline; }

	void SetFontName	 (const CString &FaceName);
	void SetFontSize	 (double PointSize);
	void SetFontWeight	 (long lfWeight);
	void SetFontCharset	 (short lfCharSet);
	void SetFontBold	 (bool flBold);
	void SetFontItalic	 (bool flItalic);
	void SetFontStrikeOut(bool flStrikeOut);
	void SetFontUnderline(bool flUnderline);

	HBRUSH OnCtlColor(CDC* pDC);

protected:
	CWnd* pWnd;
	CFont *pFont;
	LOGFONT *pLogFont;
	int rgbForeColor, rgbBackColor;
	CBrush mBrush;

	void CreateFont();
	void UpdateFont();
};

 FARPROC GetAddress(const char *pLibFileName, const char *pProcName, HINSTANCE *phLib=NULL);
 HDC GetHDC(CWnd *pWnd);	inline HDC GetHDC(CWnd &mWnd) { return GetHDC(&mWnd); }
 
//====================================================
class VBtoTimer {

public:
	VBtoTimer() {
		Set(0, 0, 0, false);
	}
	~VBtoTimer() {
		SetEnabled(false);
	}
	void Set(HWND hWnd_, UINT nIDEvent_, long Interval_=0, bool Enabled_=true) {
		hWnd = hWnd_;
		nIDEvent = nIDEvent_;
		Interval = Interval_;
		Enabled	= Enabled_;
		Reset();
	}
	void SetInterval(long Interval_) {
		Interval = Interval_;
		Reset();
	}
	void SetEnabled(bool Enabled_) {
		Enabled	= Enabled_;
		Reset();
	}
	void Reset() {
		if (hWnd && nIDEvent)
		if (Interval>0 && Enabled) {
			::SetTimer(hWnd, nIDEvent, Interval, NULL);
		} else {
			::KillTimer(hWnd, nIDEvent);
		}
	}

	long Interval;
	bool Enabled;

protected:
	HWND hWnd;
	UINT nIDEvent;
};
 
inline DATE vbNow() {
	return COleDateTime::GetCurrentTime();
}
inline DATE vbDate() {
	return (long)COleDateTime::GetCurrentTime();
}
inline DATE vbTime() {
	DATE dt = COleDateTime::GetCurrentTime();
	return dt - (long)dt;
}
inline CString vbDateStr() {
	return COleDateTime(vbDate()).Format();
}
inline CString vbTimeStr() {
	return COleDateTime(vbTime()).Format();
}
inline DATE StrToDATE(const char * sDate) {
	COleDateTime dt;
	dt.ParseDateTime(sDate);
	return dt.m_dt;
}
inline CString StrFromDate(DATE dt) {
	return COleDateTime(dt).Format();
}

 CString GetAppPath();
 void ShowModeless(CDialog *pDlg, UINT nIDTemplate);
 
 
#define	vbSunday	1
#define	vbMonday	2
#define	vbTuesday	3
#define	vbWednesday	4
#define	vbThursday	5
#define	vbFriday	6
#define	vbSaturday	7


  // === External Consts: ===
 #define vbTextCompare	1
 #define sbrSimple	1
 #define sbrNormal	0
 #define tvwAutomatic	0
 #define tvwManual	1
 #define tvwRootLines	1
 #define tvwTreeLines	0
 #define tvwChild	4
 #define tvwFirst	0
 #define tvwLast	1
 #define tvwNext	2
 #define tvwPrevious	3
 #define vbTuesday	3
 #define vbFixedDialog	3
 #define vbCtrlMask	2
 #define vbDiagonalCross	7
 #define cdlCancel	32755
 #define myConstToVCPP	182
 #define myConst1	11
 #define myConst2	12
 #define vbSunday	1
 #define vbMonday	2
 #define vbWednesday	4
 #define vbThursday	5
 #define vbFriday	6
 #define vbSaturday	7


#endif // VBto_Converter_AddFunctions_H
