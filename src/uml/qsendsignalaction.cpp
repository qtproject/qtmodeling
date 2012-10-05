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

#include "qsendsignalaction.h"
//#include "qsendsignalaction_p.h"

QT_BEGIN_NAMESPACE_QTUML

/*!
    \class QSendSignalAction

    \inmodule QtUml

    \brief A send signal action is an action that creates a signal instance from its inputs, and transmits it to the target object, where it may cause the firing of a state machine transition or the execution of an activity. The argument values are available to the execution of associated behaviors. The requestor continues execution immediately. Any reply message is ignored and is not transmitted to the requestor. If the input is already a signal instance, use a send object action.
 */

QSendSignalAction::QSendSignalAction(QObject *parent)
    : QObject(parent)
{
}

QSendSignalAction::~QSendSignalAction()
{
}

/*!
    The type of signal transmitted to the target object.
 */
QSignal *QSendSignalAction::signal() const
{
}

void QSendSignalAction::setSignal(const QSignal *signal)
{
}

/*!
    The target object to which the signal is sent.
 */
QInputPin *QSendSignalAction::target() const
{
}

void QSendSignalAction::setTarget(const QInputPin *target)
{
}

#include "moc_qsendsignalaction.cpp"

QT_END_NAMESPACE_QTUML
