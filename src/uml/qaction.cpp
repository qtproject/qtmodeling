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

#include "qaction.h"
#include "qaction_p.h"
#include "qelement_p.h"
#include "qelement_p.h"
#include "qelement_p.h"
#include "qelement_p.h"

#include <QtUml/QOutputPin>
#include <QtUml/QConstraint>
#include <QtUml/QClassifier>
#include <QtUml/QInputPin>

QT_BEGIN_NAMESPACE_QTUML

QActionPrivate::QActionPrivate() :
    isLocallyReentrant(false),
    localPostconditions(new QSet<QConstraint *>),
    localPreconditions(new QSet<QConstraint *>),
    inputs(new QList<QInputPin *>),
    outputs(new QList<QOutputPin *>)
{
}

QActionPrivate::~QActionPrivate()
{
    delete localPostconditions;
    delete localPreconditions;
    delete inputs;
    delete outputs;
}

void QActionPrivate::setLocallyReentrant(bool isLocallyReentrant)
{
    this->isLocallyReentrant = isLocallyReentrant;
}

void QActionPrivate::addLocalPostcondition(QConstraint *localPostcondition)
{
    this->localPostconditions->insert(localPostcondition);

    // Adjust subsetted property(ies)
    addOwnedElement(localPostcondition);
}

void QActionPrivate::removeLocalPostcondition(QConstraint *localPostcondition)
{
    this->localPostconditions->remove(localPostcondition);

    // Adjust subsetted property(ies)
    removeOwnedElement(localPostcondition);
}

void QActionPrivate::addLocalPrecondition(QConstraint *localPrecondition)
{
    this->localPreconditions->insert(localPrecondition);

    // Adjust subsetted property(ies)
    addOwnedElement(localPrecondition);
}

void QActionPrivate::removeLocalPrecondition(QConstraint *localPrecondition)
{
    this->localPreconditions->remove(localPrecondition);

    // Adjust subsetted property(ies)
    removeOwnedElement(localPrecondition);
}

void QActionPrivate::addInput(QInputPin *input)
{
    this->inputs->append(input);

    // Adjust subsetted property(ies)
    addOwnedElement(input);
}

void QActionPrivate::removeInput(QInputPin *input)
{
    this->inputs->removeAll(input);

    // Adjust subsetted property(ies)
    removeOwnedElement(input);
}

void QActionPrivate::addOutput(QOutputPin *output)
{
    this->outputs->append(output);

    // Adjust subsetted property(ies)
    addOwnedElement(output);
}

void QActionPrivate::removeOutput(QOutputPin *output)
{
    this->outputs->removeAll(output);

    // Adjust subsetted property(ies)
    removeOwnedElement(output);
}

/*!
    \class QAction

    \inmodule QtUml

    \brief An action has pre- and post-conditions.An action represents a single step within an activity, that is, one that is not further decomposed within the activity.An action is a named element that is the fundamental unit of executable functionality. The execution of an action represents some transformation or processing in the modeled system, be it a computer system or otherwise.
 */

QAction::QAction()
{
}

QAction::~QAction()
{
}

/*!
    If true, the action can begin a new, concurrent execution, even if there is already another execution of the action ongoing. If false, the action cannot begin a new execution until any previous execution has completed.
 */
bool QAction::isLocallyReentrant() const
{
    QTUML_D(const QAction);
    return d->isLocallyReentrant;
}

void QAction::setLocallyReentrant(bool isLocallyReentrant)
{
    QTUML_D(QAction);
    if (d->isLocallyReentrant != isLocallyReentrant) {
        d->setLocallyReentrant(isLocallyReentrant);
    }
}

/*!
    The classifier that owns the behavior of which this action is a part.
 */
QClassifier *QAction::context() const
{
    qWarning("QAction::context: to be implemented (this is a derived associationend)");
}

/*!
    Constraint that must be satisfied when executed is completed.
 */
const QSet<QConstraint *> *QAction::localPostconditions() const
{
    QTUML_D(const QAction);
    return d->localPostconditions;
}

void QAction::addLocalPostcondition(QConstraint *localPostcondition)
{
    QTUML_D(QAction);
    if (!d->localPostconditions->contains(localPostcondition)) {
        d->addLocalPostcondition(localPostcondition);
    }
}

void QAction::removeLocalPostcondition(QConstraint *localPostcondition)
{
    QTUML_D(QAction);
    if (d->localPostconditions->contains(localPostcondition)) {
        d->removeLocalPostcondition(localPostcondition);
    }
}

/*!
    Constraint that must be satisfied when execution is started.
 */
const QSet<QConstraint *> *QAction::localPreconditions() const
{
    QTUML_D(const QAction);
    return d->localPreconditions;
}

void QAction::addLocalPrecondition(QConstraint *localPrecondition)
{
    QTUML_D(QAction);
    if (!d->localPreconditions->contains(localPrecondition)) {
        d->addLocalPrecondition(localPrecondition);
    }
}

void QAction::removeLocalPrecondition(QConstraint *localPrecondition)
{
    QTUML_D(QAction);
    if (d->localPreconditions->contains(localPrecondition)) {
        d->removeLocalPrecondition(localPrecondition);
    }
}

/*!
    The ordered set of input pins connected to the Action. These are among the total set of inputs.
 */
const QList<QInputPin *> *QAction::inputs() const
{
    QTUML_D(const QAction);
    return d->inputs;
}

/*!
    The ordered set of output pins connected to the Action. The action places its results onto pins in this set.
 */
const QList<QOutputPin *> *QAction::outputs() const
{
    QTUML_D(const QAction);
    return d->outputs;
}

QT_END_NAMESPACE_QTUML

