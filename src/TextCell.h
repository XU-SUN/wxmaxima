// -*- mode: c++; c-file-style: "linux"; c-basic-offset: 2; indent-tabs-mode: nil -*-
//
//  Copyright (C) 2004-2015 Andrej Vodopivec <andrej.vodopivec@gmail.com>
//            (C) 2014-2016 Gunter Königsmann <wxMaxima@physikbuch.de>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef TEXTCELL_H
#define TEXTCELL_H

#include "MathCell.h"

/*! A Text cell

  Everything on the worksheet that is composed of characters with the eception
  of input cells: Input cells are handled by EditorCell instead.
 */
class TextCell : public MathCell
{
private:
  //! Is an ending "(" of a function name the opening parenthesis of the function?
  bool m_dontEscapeOpeningParenthesis;
public:
  TextCell();
  TextCell(wxString text);
  ~TextCell();
  MathCell* Copy();
  void Destroy();
  void SetValue(const wxString &text);
  void RecalculateWidths(CellParser& parser, int fontsize);
  void Draw(CellParser& parser, wxPoint point, int fontsize);
  void SetFont(CellParser& parser, int fontsize);
  /*! Calling this function signals that the "(" this cell ends in isn't part of the function name

    The "(" is the opening parenthesis of a function instead.
   */
  void DontEscapeOpeningParenthesis(){m_dontEscapeOpeningParenthesis = true;}
  wxString ToString();
  wxString ToTeX();
  wxString ToMathML();
  wxString ToOMML();
  wxString ToRTF();
  wxString ToXML();
  wxString GetDiffPart();
  bool IsOperator();
  wxString GetValue() { return m_text; }
  wxString GetGreekStringTeX();
  wxString GetSymbolTeX();
#if wxUSE_UNICODE
  wxString GetGreekStringUnicode();
  wxString GetSymbolUnicode(bool keepPercent);
#elif defined __WXMSW__
  wxString GetGreekStringSymbol();
  wxString GetSymbolSymbol(bool keepPercent);
#endif
  bool IsShortNum();
protected:
  void SetAltText(CellParser& parser);
  wxString m_text;
  wxString m_altText, m_altJsText;
  wxString m_fontname, m_texFontname;

  bool m_alt, m_altJs;
  int m_realCenter;
  //! The line height
  int m_fontSize;
  //! The actual font size for labels (that have a fixed width)
  int m_fontSizeLabel;
  int m_labelWidth, m_labelHeight;
private:
  //! Produces a text sample that determines the label width
  wxString LabelWidthText(CellParser &parser);

};

#endif // TEXTCELL_H
