// -*- C++ -*-
/**
 * \file GuiLyXFiles.h
 * This file is part of LyX, the document processor.
 * Licence details can be found in the file COPYING.
 *
 * \author Jürgen Spitzmüller
 *
 * Full author contact details are available in file CREDITS.
 */

#ifndef GUILYXFILES_H
#define GUILYXFILES_H

#include "GuiDialog.h"
#include "FancyLineEdit.h"
#include "ui_LyXFilesUi.h"

class QListWidgetItem;

namespace lyx {

class Format;

namespace frontend {

class GuiLyXFiles : public GuiDialog, public Ui::LyXFilesUi
{
	Q_OBJECT

public:
	GuiLyXFiles(GuiView & lv);

private Q_SLOTS:
	void changed_adaptor();
	void on_fileTypeCO_activated(int);
	void on_filesLW_itemDoubleClicked(QTreeWidgetItem *, int);
	void on_browsePB_pressed();
	void slotButtonBox(QAbstractButton *);
	void filterLabels();
	void resetFilter();

private:
	///
	bool isValid();
	/// Apply from dialog
	void applyView();
	/// Update the dialog
	void updateContents();

	///
	bool initialiseParams(std::string const & data);
	///
	void paramsToDialog(QString const & command);
	///
	void clearParams() {}
	///
	void dispatchParams();
	///
	bool isBufferDependent() const { return false; }
	///
	FuncCode getLfun() const { return LFUN_BUFFER_NEW_TEMPLATE; }

private:
	/// contains the search box
	FancyLineEdit * filter_;
	///
	QString type_;
	///
	QString file_;
};

} // namespace frontend
} // namespace lyx

#endif // GUILYXFILES_H