/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qaddvariablevalueaction.h"
#include "qaddvariablevalueaction_p.h"

#include <QtUml/QInputPin>

QT_BEGIN_NAMESPACE_QTUML

QAddVariableValueActionPrivate::QAddVariableValueActionPrivate() :
    isReplaceAll(false),
    insertAt(0)
{
}

QAddVariableValueActionPrivate::~QAddVariableValueActionPrivate()
{
}

/*!
    \class QAddVariableValueAction

    \inmodule QtUml

    \brief An add variable value action is a write variable action for adding values to a variable.
 */

QAddVariableValueAction::QAddVariableValueAction(QObject *parent) :
    QWriteVariableAction(*new QAddVariableValueActionPrivate, parent)
{
    qRegisterMetaType<QAddVariableValueAction *>("QAddVariableValueAction *");
    qRegisterMetaType<const QSet<QAddVariableValueAction *> *>("const QSet<QAddVariableValueAction *> *");
    qRegisterMetaType<const QList<QAddVariableValueAction *> *>("const QList<QAddVariableValueAction *> *");
}

QAddVariableValueAction::QAddVariableValueAction(QAddVariableValueActionPrivate &dd, QObject *parent) :
    QWriteVariableAction(dd, parent)
{
    qRegisterMetaType<QAddVariableValueAction *>("QAddVariableValueAction *");
    qRegisterMetaType<const QSet<QAddVariableValueAction *> *>("const QSet<QAddVariableValueAction *> *");
    qRegisterMetaType<const QList<QAddVariableValueAction *> *>("const QList<QAddVariableValueAction *> *");
}

QAddVariableValueAction::~QAddVariableValueAction()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QAddVariableValueAction
// ---------------------------------------------------------------

/*!
    Specifies whether existing values of the variable should be removed before adding the new value.
 */
bool QAddVariableValueAction::isReplaceAll() const
{
    // This is a read-write attribute

    Q_D(const QAddVariableValueAction);
    return d->isReplaceAll;
}

void QAddVariableValueAction::setReplaceAll(bool isReplaceAll)
{
    // This is a read-write attribute

    Q_D(QAddVariableValueAction);
    if (d->isReplaceAll != isReplaceAll) {
        d->isReplaceAll = isReplaceAll;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QAddVariableValueAction
// ---------------------------------------------------------------

/*!
    Gives the position at which to insert a new value or move an existing value in ordered variables. The types is UnlimitedINatural, but the value cannot be zero. This pin is omitted for unordered variables.
 */
QInputPin *QAddVariableValueAction::insertAt() const
{
    // This is a read-write association end

    Q_D(const QAddVariableValueAction);
    return d->insertAt;
}

void QAddVariableValueAction::setInsertAt(QInputPin *insertAt)
{
    // This is a read-write association end

    Q_D(QAddVariableValueAction);
    if (d->insertAt != insertAt) {
        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->removeInput(qtuml_object_cast<QInputPin *>(d->insertAt));

        d->insertAt = insertAt;

        // Adjust subsetted property(ies)
        if (insertAt) {
            (qtuml_object_cast<QActionPrivate *>(d))->addInput(qtuml_object_cast<QInputPin *>(insertAt));
        }
    }
}

#include "moc_qaddvariablevalueaction.cpp"

QT_END_NAMESPACE_QTUML

