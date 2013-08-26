/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
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
#include "qumlsendsignalaction.h"

#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlSignal>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlSendSignalAction

    \inmodule QtUml

    \brief A send signal action is an action that creates a signal instance from its inputs, and transmits it to the target object, where it may cause the firing of a state machine transition or the execution of an activity. The argument values are available to the execution of associated behaviors. The requestor continues execution immediately. Any reply message is ignored and is not transmitted to the requestor. If the input is already a signal instance, use a send object action.
 */

QUmlSendSignalAction::QUmlSendSignalAction() :
    _signal(0),
    _target(0)
{
}

// OWNED ATTRIBUTES

/*!
    The type of signal transmitted to the target object.
 */
QUmlSignal *QUmlSendSignalAction::signal() const
{
    // This is a read-write association end

    return _signal;
}

void QUmlSendSignalAction::setSignal(QUmlSignal *signal)
{
    // This is a read-write association end

    if (_signal != signal) {
        _signal = signal;
    }
}

/*!
    The target object to which the signal is sent.
 */
QUmlInputPin *QUmlSendSignalAction::target() const
{
    // This is a read-write association end

    return _target;
}

void QUmlSendSignalAction::setTarget(QUmlInputPin *target)
{
    // This is a read-write association end

    if (_target != target) {
        // Adjust subsetted properties
        removeInput(_target);

        _target = target;

        // Adjust subsetted properties
        if (target) {
            addInput(target);
        }
    }
}

QT_END_NAMESPACE

