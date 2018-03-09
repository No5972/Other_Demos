#pragma once


// CColorListBox

class CColorListBox : public CListBox
{
	DECLARE_DYNAMIC(CColorListBox)

public:
	CColorListBox();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	int AddString(LPCTSTR lpszItem, COLORREF itemColor = RGB(255, 0, 0));
	virtual ~CColorListBox();


protected:
	DECLARE_MESSAGE_MAP()
};


