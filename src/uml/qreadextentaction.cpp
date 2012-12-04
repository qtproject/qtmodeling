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

#include "qreadextentaction.h"
#include "qreadextentaction_p.h"

#include <QtUml/QClassifier>
#include <QtUml/QOutputPin>

QT_BEGIN_NAMESPACE_QTUML

QReadExtentActionPrivate::QReadExtentActionPrivate() :
    classifier(0),
    result(0)
{
}

QReadExtentActionPrivate::~QReadExtentActionPrivate()
{
}

/*!
    \class QReadExtentAction

    \inmodule QtUml

    \brief A read extent action is an action that retrieves the current instances of a classifier.
 */

QReadExtentAction::QReadExtentAction(QUmlObject *parent, QUmlObject *wrapper) :
    QAction(*new QReadExtentActionPrivate, parent, wrapper)
{
}

QReadExtentAction::QReadExtentAction(QReadExtentActionPrivate &dd, QUmlObject *parent, QUmlObject *wrapper) :
    QAction(dd, parent, wrapper)
{
}

QReadExtentAction::~QReadExtentAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QReadExtentAction
// ---------------------------------------------------------------

/*!
    The classifier whose instances are to be retrieved.
 */
QClassifier *QReadExtentAction::classifier() const
{
    // This is a read-write association end

    Q_D(const QReadExtentAction);
    return d->classifier;
}

void QReadExtentAction::setClassifier(QClassifier *classifier)
{
    // This is a read-write association end

    Q_D(QReadExtentAction);
    if (d->classifier != classifier) {
        d->classifier = classifier;
    }
}

/*!
    The runtime instances of the classifier.
 */
QOutputPin *QReadExtentAction::result() const
{
    // This is a read-write association end

    Q_D(const QReadExtentAction);
    return d->result;
}

void QReadExtentAction::setResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QReadExtentAction);
    if (d->result != result) {
        // Adjust subsetted property(ies)
        (qumlobject_cast<QActionPrivate *>(d))->removeOutput(qumlobject_cast<QOutputPin *>(d->result));

        d->result = result;

        // Adjust subsetted property(ies)
        if (result) {
            (qumlobject_cast<QActionPrivate *>(d))->addOutput(qumlobject_cast<QOutputPin *>(result));
        }
    }
}

#include "moc_qreadextentaction.cpp"

QT_END_NAMESPACE_QTUML

