/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtWrappedObjectsWidgets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QWRAPPEDOBJECTVIEW_H
#define QWRAPPEDOBJECTVIEW_H

#include <QtCore/QModelIndex>

#include <QtWrappedObjectsWidgets/QtWrappedObjectsWidgetsGlobal>

#include <QtWidgets/QWidget>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtWrappedObjectsWidgets)

class QAbstractItemModel;
class QItemSelection;
class QWrappedObject;

class QWrappedObjectViewPrivate;

class Q_WRAPPEDOBJECTSWIDGETS_EXPORT QWrappedObjectView : public QWidget
{
    Q_OBJECT

    Q_DISABLE_COPY(QWrappedObjectView)
    Q_DECLARE_PRIVATE(QWrappedObjectView)

public:
    explicit QWrappedObjectView(QWidget *parent = 0, Qt::WindowFlags f = 0);

public Q_SLOTS:
    virtual void setModel(QAbstractItemModel *model);
    void updateSelected();

Q_SIGNALS:
    void wrappedObjectChanged(QWrappedObject *selectedWrappedObject, QModelIndex index = QModelIndex());
    void addToView(QWrappedObject *selectedWrappedObject);

protected:
     void contextMenuEvent(QContextMenuEvent *event);

private Q_SLOTS:
    void handleAddMethod();
    void addElementToView();
    void deleteObject();
    void modelReset();
    void rowsInserted(const QModelIndex &parent, int first);
    void selectionChanged(const QItemSelection &selected);

private:
    void removeObjectUse(QWrappedObject *container, QWrappedObject *usedObject);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QWRAPPEDOBJECTVIEW_H

