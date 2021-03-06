/* Labeless
 * by Aliaksandr Trafimchuk
 *
 * Source code released under
 * Creative Commons BY-NC 4.0
 * http://creativecommons.org/licenses/by-nc/4.0
 */

#pragma once

#include <QtGlobal>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#   include <QtWidgets/QDialog>
#else // QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#   include <QDialog>
#endif // QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)

#include "types.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ChooseMemoryDialog;
}
QT_END_NAMESPACE

class ChooseMemoryDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ChooseMemoryDialog(const MemoryRegionList& memMap, const QString& title = QString::null, QWidget* parent = nullptr);
	~ChooseMemoryDialog();

	bool getSelectedMemory(MemoryRegionList& selected) const;

protected:
	virtual void changeEvent(QEvent *e);
	virtual void accept();

private slots:
	void selectTypeChanged();
	void on_twMemoryMap_customContextMenuRequested(const QPoint&);
	void on_leManualVaFrom_textChanged(const QString&);
	void on_leManualVaTo_textChanged(const QString&);
	void on_leManualSize_textChanged(const QString&);
	void onManualMeasureTypeChanged(int);

private:
	void fillView();
	bool isRangeBelongsToExistingRegions(uint64_t base, uint64_t size) const;

private:
	Ui::ChooseMemoryDialog* m_UI;
	MemoryRegionList m_MemMap;
};

