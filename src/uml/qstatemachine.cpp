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

#include "qstatemachine.h"
#include "qstatemachine_p.h"
#include "qnamespace_p.h"
#include "qnamespace_p.h"

#include <QtUml/QNamespace>
#include <QtUml/QRedefinableElement>
#include <QtUml/QState>
#include <QtUml/QPseudostate>
#include <QtUml/QRegion>

QT_BEGIN_NAMESPACE_QTUML

QStateMachinePrivate::QStateMachinePrivate() :
    extendedStateMachines(new QSet<QStateMachine *>),
    connectionPoints(new QSet<QPseudostate *>),
    submachineStates(new QSet<QState *>),
    regions(new QSet<QRegion *>)
{
}

QStateMachinePrivate::~QStateMachinePrivate()
{
    delete extendedStateMachines;
    delete connectionPoints;
    delete submachineStates;
    delete regions;
}

/*!
    \class QStateMachine

    \inmodule QtUml

    \brief State machines can be used to express the behavior of part of a system. Behavior is modeled as a traversal of a graph of state nodes interconnected by one or more joined transition arcs that are triggered by the dispatching of series of (event) occurrences. During this traversal, the state machine executes a series of activities associated with various elements of the state machine.
 */

QStateMachine::QStateMachine(QObject *parent)
    : QBehavior(parent), d_ptr(new QStateMachinePrivate)
{
}

QStateMachine::~QStateMachine()
{
    delete d_ptr;
}

/*!
    The state machines of which this is an extension.
 */
const QSet<QStateMachine *> *QStateMachine::extendedStateMachines() const
{
    return d_ptr->extendedStateMachines;
}

void QStateMachine::addExtendedStateMachine(const QStateMachine *extendedStateMachine)
{
    d_ptr->extendedStateMachines->insert(const_cast<QStateMachine *>(extendedStateMachine));
}

void QStateMachine::removeExtendedStateMachine(const QStateMachine *extendedStateMachine)
{
    d_ptr->extendedStateMachines->remove(const_cast<QStateMachine *>(extendedStateMachine));
}

/*!
    The connection points defined for this state machine. They represent the interface of the state machine when used as part of submachine state.
 */
const QSet<QPseudostate *> *QStateMachine::connectionPoints() const
{
    return d_ptr->connectionPoints;
}

void QStateMachine::addConnectionPoint(const QPseudostate *connectionPoint)
{
    d_ptr->connectionPoints->insert(const_cast<QPseudostate *>(connectionPoint));
}

void QStateMachine::removeConnectionPoint(const QPseudostate *connectionPoint)
{
    d_ptr->connectionPoints->remove(const_cast<QPseudostate *>(connectionPoint));
}

/*!
    References the submachine(s) in case of a submachine state. Multiple machines are referenced in case of a concurrent state.
 */
const QSet<QState *> *QStateMachine::submachineStates() const
{
    return d_ptr->submachineStates;
}

void QStateMachine::addSubmachineState(const QState *submachineState)
{
    d_ptr->submachineStates->insert(const_cast<QState *>(submachineState));
}

void QStateMachine::removeSubmachineState(const QState *submachineState)
{
    d_ptr->submachineStates->remove(const_cast<QState *>(submachineState));
}

/*!
    The regions owned directly by the state machine.
 */
const QSet<QRegion *> *QStateMachine::regions() const
{
    return d_ptr->regions;
}

void QStateMachine::addRegion(const QRegion *region)
{
    d_ptr->regions->insert(const_cast<QRegion *>(region));
}

void QStateMachine::removeRegion(const QRegion *region)
{
    d_ptr->regions->remove(const_cast<QRegion *>(region));
}

/*!
    The operation LCA(s1,s2) returns an orthogonal state or region which is the least common ancestor of states s1 and s2, based on the statemachine containment hierarchy.
 */
QNamespace *QStateMachine::LCA(const QState *s1, const QState *s2) const
{
    qWarning("QStateMachine::LCA: operation to be implemented");
}

/*!
    The query ancestor(s1, s2) checks whether s1 is an ancestor state of state s2.
 */
bool QStateMachine::ancestor(const QState *s1, const QState *s2) const
{
    qWarning("QStateMachine::ancestor: operation to be implemented");
}

/*!
    The query isConsistentWith() specifies that a redefining state machine is consistent with a redefined state machine provided that the redefining state machine is an extension of the redefined state machine: Regions are inherited and regions can be added, inherited regions can be redefined. In case of multiple redefining state machines, extension implies that the redefining state machine gets orthogonal regions for each of the redefined state machines.
 */
bool QStateMachine::isConsistentWith(const QRedefinableElement *redefinee) const
{
    qWarning("QStateMachine::isConsistentWith: operation to be implemented");
}

/*!
    The query isRedefinitionContextValid() specifies whether the redefinition contexts of a statemachine are properly related to the redefinition contexts of the specified statemachine to allow this element to redefine the other. The containing classifier of a redefining statemachine must redefine the containing classifier of the redefined statemachine.
 */
bool QStateMachine::isRedefinitionContextValid(const QStateMachine *redefined) const
{
    qWarning("QStateMachine::isRedefinitionContextValid: operation to be implemented");
}

#include "moc_qstatemachine.cpp"

QT_END_NAMESPACE_QTUML

