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

#include "qreadvariableaction.h"
#include "qreadvariableaction_p.h"

#include <QtUml/QOutputPin>

QT_BEGIN_NAMESPACE_QTUML

QReadVariableActionPrivate::QReadVariableActionPrivate() :
    result(0)
{
}

QReadVariableActionPrivate::~QReadVariableActionPrivate()
{
}

/*!
    \class QReadVariableAction

    \inmodule QtUml

    \brief A read variable action is a variable action that retrieves the values of a variable.
 */

QReadVariableAction::QReadVariableAction(QObject *parent) :
    QVariableAction(*new QReadVariableActionPrivate, parent)
{
    qRegisterMetaType<QReadVariableAction *>("QReadVariableAction *");
    qRegisterMetaType<const QSet<QReadVariableAction *> *>("const QSet<QReadVariableAction *> *");
    qRegisterMetaType<const QList<QReadVariableAction *> *>("const QList<QReadVariableAction *> *");
}

QReadVariableAction::QReadVariableAction(QReadVariableActionPrivate &dd, QObject *parent) :
    QVariableAction(dd, parent)
{
    qRegisterMetaType<QReadVariableAction *>("QReadVariableAction *");
    qRegisterMetaType<const QSet<QReadVariableAction *> *>("const QSet<QReadVariableAction *> *");
    qRegisterMetaType<const QList<QReadVariableAction *> *>("const QList<QReadVariableAction *> *");
}

QReadVariableAction::~QReadVariableAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QReadVariableAction
// ---------------------------------------------------------------

/*!
    Gives the output pin on which the result is put.
 */
QOutputPin *QReadVariableAction::result() const
{
    // This is a read-write association end

    Q_D(const QReadVariableAction);
    return d->result;
}

void QReadVariableAction::setResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QReadVariableAction);
    if (d->result != result) {
        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->removeOutput(qtuml_object_cast<QOutputPin *>(d->result));

        d->result = result;

        // Adjust subsetted property(ies)
        if (result) {
            (qtuml_object_cast<QActionPrivate *>(d))->addOutput(qtuml_object_cast<QOutputPin *>(result));
        }
    }
}

#include "moc_qreadvariableaction.cpp"

QT_END_NAMESPACE_QTUML

