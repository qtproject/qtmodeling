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

#include "qtestidentityaction.h"
#include "qtestidentityaction_p.h"

#include <QtUml/QInputPin>
#include <QtUml/QOutputPin>

QT_BEGIN_NAMESPACE_QTUML

QTestIdentityActionPrivate::QTestIdentityActionPrivate() :
    second(0),
    result(0),
    first(0)
{
}

QTestIdentityActionPrivate::~QTestIdentityActionPrivate()
{
}

/*!
    \class QTestIdentityAction

    \inmodule QtUml

    \brief A test identity action is an action that tests if two values are identical objects.
 */

QTestIdentityAction::QTestIdentityAction(QObject *parent) :
    QAction(*new QTestIdentityActionPrivate, parent)
{
}

QTestIdentityAction::QTestIdentityAction(QTestIdentityActionPrivate &dd, QObject *parent) :
    QAction(dd, parent)
{
}

QTestIdentityAction::~QTestIdentityAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QTestIdentityAction
// ---------------------------------------------------------------

/*!
    Gives the pin on which an object is placed.
 */
QInputPin *QTestIdentityAction::second() const
{
    // This is a read-write association end

    Q_D(const QTestIdentityAction);
    return d->second;
}

void QTestIdentityAction::setSecond(QInputPin *second)
{
    // This is a read-write association end

    Q_D(QTestIdentityAction);
    if (d->second != second) {
        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->removeInput(qtuml_object_cast<QInputPin *>(d->second));

        d->second = second;

        // Adjust subsetted property(ies)
        if (second) {
            (qtuml_object_cast<QActionPrivate *>(d))->addInput(qtuml_object_cast<QInputPin *>(second));
        }
    }
}

/*!
    Tells whether the two input objects are identical.
 */
QOutputPin *QTestIdentityAction::result() const
{
    // This is a read-write association end

    Q_D(const QTestIdentityAction);
    return d->result;
}

void QTestIdentityAction::setResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QTestIdentityAction);
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

/*!
    Gives the pin on which an object is placed.
 */
QInputPin *QTestIdentityAction::first() const
{
    // This is a read-write association end

    Q_D(const QTestIdentityAction);
    return d->first;
}

void QTestIdentityAction::setFirst(QInputPin *first)
{
    // This is a read-write association end

    Q_D(QTestIdentityAction);
    if (d->first != first) {
        // Adjust subsetted property(ies)
        (qtuml_object_cast<QActionPrivate *>(d))->removeInput(qtuml_object_cast<QInputPin *>(d->first));

        d->first = first;

        // Adjust subsetted property(ies)
        if (first) {
            (qtuml_object_cast<QActionPrivate *>(d))->addInput(qtuml_object_cast<QInputPin *>(first));
        }
    }
}

#include "moc_qtestidentityaction.cpp"

QT_END_NAMESPACE_QTUML

